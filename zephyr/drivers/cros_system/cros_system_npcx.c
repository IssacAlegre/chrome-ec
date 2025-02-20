/* Copyright 2021 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include <arch/arm/aarch32/cortex_m/cmsis.h>
#include <drivers/cros_system.h>
#include <drivers/gpio.h>
#include <drivers/watchdog.h>
#include <logging/log.h>
#include <soc.h>
#include <soc/nuvoton_npcx/reg_def_cros.h>
#include <sys/util.h>

#include "gpio.h"
#include "rom_chip.h"
#include "soc_gpio.h"
#include "soc_miwu.h"
#include "system.h"

LOG_MODULE_REGISTER(cros_system, LOG_LEVEL_ERR);

/**
 * @brief Get a node from path '/hibernate_wakeup_pins' which has a property
 *        'wakeup-pins' contains GPIO list for hibernate wake-up
 *
 * @return node identifier with that path.
 */
#define SYSTEM_DT_NODE_HIBERNATE_CONFIG DT_INST(0, cros_ec_hibernate_wake_pins)

/**
 * @brief Get the length of 'wakeup-pins' property
 *
 * @return length of 'wakeup-pins' prop which type is 'phandles'
 */
#define SYSTEM_DT_NODE_WAKEUP_PIN_LEN \
	DT_PROP_LEN(SYSTEM_DT_NODE_HIBERNATE_CONFIG, wakeup_pins)

/**
 * @brief Get a node identifier from a phandle in property 'wakeup-pins' at
 *        index i.
 *
 * @param i index of 'wakeup-pins' prop which type is 'phandles'
 * @return node identifier with that path.
 */
#define SYSTEM_DT_NODE_WAKEUP_PIN_BY_IDX(i) \
	DT_PHANDLE_BY_IDX(SYSTEM_DT_NODE_HIBERNATE_CONFIG, wakeup_pins, i)

/**
 * @brief Get the enum using in chromium system by index i in 'wakeup-pins'
 *        list.
 *
 * @param i index of 'wakeup-pins' prop which type is 'phandles'
 * @return GPIO enumeration
 */
#define SYSTEM_DT_WAKEUP_GPIO_ENUM_BY_IDX(i, _)                           \
	COND_CODE_1(DT_NODE_HAS_PROP(SYSTEM_DT_NODE_WAKEUP_PIN_BY_IDX(i), \
				     enum_name),                          \
		    (GPIO_SIGNAL(SYSTEM_DT_NODE_WAKEUP_PIN_BY_IDX(i)), ), ())

/* Driver config */
struct cros_system_npcx_config {
	/* hardware module base address */
	uintptr_t base_scfg;
	uintptr_t base_twd;
	uintptr_t base_mswc;
};

/* Driver data */
struct cros_system_npcx_data {
	int reset; /* reset cause */
};

/* Driver convenience defines */
#define DRV_CONFIG(dev) ((const struct cros_system_npcx_config *)(dev)->config)

#define HAL_SCFG_INST(dev) (struct scfg_reg *)(DRV_CONFIG(dev)->base_scfg)
#define HAL_TWD_INST(dev) (struct twd_reg *)(DRV_CONFIG(dev)->base_twd)
#define HAL_MSWC_INST(dev) (struct mswc_reg *)(DRV_CONFIG(dev)->base_mswc)

#define DRV_DATA(dev) ((struct cros_system_npcx_data *)(dev)->data)

#define FAMILY_ID_NPCX 0x20
#define CHIP_ID_NPCX79NXB_C 0x07

/* device ID for all variants in npcx family */
enum npcx_chip_id {
	DEVICE_ID_NPCX796F_B = 0x21,
	DEVICE_ID_NPCX796F_C = 0x29,
	DEVICE_ID_NPCX797F_C = 0x20,
	DEVICE_ID_NPCX797W_B = 0x24,
	DEVICE_ID_NPCX797W_C = 0x2C,
};

/* RAM block size in npcx family (Unit: bytes) */
#define NPCX_RAM_BLOCK_SIZE (32 * 1024)
/* RAM block number in npcx7 series */
#define NPCX7_RAM_BLOCK_NUM 12
/* RAM block mask for power down in npcx7 series */
#define NPCX7_RAM_BLOCK_PD_MASK (BIT(12) - 1)
/* Get saved reset flag address in battery-backed ram */
#define BBRAM_SAVED_RESET_FLAG_ADDR                         \
	(DT_REG_ADDR(DT_INST(0, nuvoton_npcx_cros_bbram)) + \
	 DT_PROP(DT_PATH(named_bbram_regions, saved_reset_flags), offset))

/* Soc specific system local functions */
static int system_npcx_watchdog_stop(void)
{
	if (IS_ENABLED(CONFIG_WATCHDOG)) {
		const struct device *wdt_dev = device_get_binding(
			DT_LABEL(DT_INST(0, nuvoton_npcx_watchdog)));

		if (!wdt_dev) {
			LOG_ERR("wdt_dev get binding failed");
			return -ENODEV;
		}

		wdt_disable(wdt_dev);
	}

	return 0;
}

static void system_npcx_set_flash_pins_tri_state(const struct device *dev)
{
	struct scfg_reg *const inst_scfg = HAL_SCFG_INST(dev);

	inst_scfg->DEVCNT |= BIT(NPCX_DEVCNT_F_SPI_TRIS);
}

static void system_npcx_init_watchdog_reset(const struct device *dev)
{
	struct twd_reg *const inst_twd = HAL_TWD_INST(dev);

	/* Enable early touch */
	inst_twd->T0CSR &= ~BIT(NPCX_T0CSR_TESDIS);
	/* watchdog touched by writing 5Ch to WDSDM */
	inst_twd->TWCFG |= BIT(NPCX_TWCFG_WDSDME);
}

static void system_npcx_turn_off_adc(void)
{
	struct adc_reg *const inst_adc =
		(struct adc_reg *)(DT_REG_ADDR(DT_INST(0, nuvoton_npcx_adc)));

	inst_adc->ADCCNF = 0;
	/* Wait for 1000 us to make sure conversion is completed. */
	k_busy_wait(1000);
}

static void system_npcx_turn_off_kernel_timer(void)
{
	static struct itim32_reg *const evt_tmr =
		(struct itim32_reg *)DT_REG_ADDR_BY_NAME(
			DT_INST(0, nuvoton_npcx_itim_timer), evt_itim);

	evt_tmr->ITCTS32 &= ~BIT(NPCX_ITCTSXX_ITEN);
}

static void system_npcx_disable_instant_wakeup(void)
{
	struct pmc_reg *const inst_pmc = (struct pmc_reg *)(DT_REG_ADDR_BY_NAME(
		DT_INST(0, nuvoton_npcx_pcc), pmc));

	inst_pmc->ENIDL_CTL &= ~BIT(NPCX_ENIDL_CTL_LP_WK_CTL);
}

static void system_npcx_set_wakeup_gpios_before_hibernate(void)
{
	const uintptr_t miwu_base[] = {
		DT_REG_ADDR(DT_INST(0, nuvoton_npcx_miwu)),
		DT_REG_ADDR(DT_INST(1, nuvoton_npcx_miwu)),
		DT_REG_ADDR(DT_INST(2, nuvoton_npcx_miwu)),
	};

	/* Disable all MIWU inputs before entering hibernate */
	for (int table = 0; table < ARRAY_SIZE(miwu_base); table++) {
		for (int group = 0; group < NPCX_MIWU_GROUP_COUNT; group++) {
			/* Disable all wake-ups */
			NPCX_WKEN(miwu_base[table], group) = 0x00;
			/* Clear all pending bits of wake-ups */
			NPCX_WKPCL(miwu_base[table], group) = 0xFF;
			/*
			 * Disable all inputs of wake-ups to prevent leakage
			 * caused by input floating.
			 */
			NPCX_WKINEN(miwu_base[table], group) = 0x00;
		}
	}

	static const int wakeup_pin_list[] = {
#if DT_NODE_EXISTS(SYSTEM_DT_NODE_HIBERNATE_CONFIG)
		UTIL_LISTIFY(SYSTEM_DT_NODE_WAKEUP_PIN_LEN,
			     SYSTEM_DT_WAKEUP_GPIO_ENUM_BY_IDX, _)
#endif
	};

	/* Reconfigure wake-up GPIOs */
	for (int i = 0; i < ARRAY_SIZE(wakeup_pin_list); i++) {
		gpio_reset(wakeup_pin_list[i]);
		/* Re-enable interrupt for wake-up inputs */
		gpio_enable_interrupt(wakeup_pin_list[i]);
	}
}

/*
 * Hibernate function locates in the last 32K ram block in npcx7 series.
 * Do not use global variables or call functions since we have turned off
 * the other ram blocks.
 */
noreturn void __keep __attribute__((section(".lfw.hiber")))
system_npcx_hibernate_by_lfw_in_last_ram(const struct device *dev,
					 uint32_t pd_ram_mask)
{
	/* Modules used for hibernating */
	struct twd_reg *const inst_twd = HAL_TWD_INST(dev);
	struct mtc_reg *const inst_mtc = (struct mtc_reg *)(DT_REG_ADDR(
		DT_INST(0, nuvoton_npcx_cros_mtc)));
	struct pmc_reg *const inst_pmc = (struct pmc_reg *)(DT_REG_ADDR_BY_NAME(
		DT_INST(0, nuvoton_npcx_pcc), pmc));
	uint32_t reset_flags;
	volatile uint8_t *saved_reset_flags =
		(volatile uint8_t *)BBRAM_SAVED_RESET_FLAG_ADDR;

	/* Turn off all blocks except last one for better power consumption */
	inst_pmc->RAM_PD[0] = (uint8_t)pd_ram_mask;
	inst_pmc->RAM_PD[1] = (uint8_t)(pd_ram_mask >> 8);

	/* Set deep idle mode */
	inst_pmc->PMCSR = BIT(NPCX_PMCSR_IDLE) | BIT(NPCX_PMCSR_DHF);

	/* Enter system sleep mode */
	__asm__ volatile("wfi");

	/*
	 * Mark wake-up reason for hibernate. Do not call bbram utilities
	 * directly since the other ram blocks are power down.
	 */
	if (IS_BIT_SET(inst_mtc->WTC, NPCX_WTC_PTO)) {
		/* Save wake-up reason as RTC alarm. */
		reset_flags = EC_RESET_FLAG_RTC_ALARM;
	} else {
		/* Otherwise, we treat it as GPIOs wake-up */
		reset_flags = EC_RESET_FLAG_WAKE_PIN;
	}

	saved_reset_flags[0] |= reset_flags;
	saved_reset_flags[1] |= reset_flags >> 8;
	saved_reset_flags[2] |= reset_flags >> 16;
	saved_reset_flags[3] |= reset_flags >> 24;

	/*
	 * The trigger of a watchdog event by a "too early service" condition.
	 * When the watchdog is written more than once during three watchdog
	 * clock cycle.
	 */
	inst_twd->WDSDM = 0x5C;
	inst_twd->WDSDM = 0x5C;

	/* Spin and wait for reboot; should never return */
	while (1)
		continue;
}

static inline int system_npcx_get_ram_blk_by_lfw_addr(char *address)
{
	return NPCX7_RAM_BLOCK_NUM -
	       ceiling_fraction((uint32_t)address -
					CONFIG_CROS_EC_PROGRAM_MEMORY_BASE,
				NPCX_RAM_BLOCK_SIZE);
}

static void system_npcx_hibernate_by_disable_ram(const struct device *dev,
						 uint32_t seconds,
						 uint32_t microseconds)
{
	/* Get 32kb ram block order of lfw function */
	extern char __lfw_text_start[], __lfw_text_end[];
	int lfw_block = system_npcx_get_ram_blk_by_lfw_addr(__lfw_text_start);
	uint32_t pd_ram_mask = ~BIT(lfw_block) & NPCX7_RAM_BLOCK_PD_MASK;

	if (lfw_block != system_npcx_get_ram_blk_by_lfw_addr(__lfw_text_end)) {
		LOG_ERR("LFW cannot cross ram blocks!");
		return;
	}

	/*
	 * Set status of pins which connect to flash to tri-state in case
	 * the leakage current.
	 */
	system_npcx_set_flash_pins_tri_state(dev);

	/* Initialize watchdog for reset after wake-up from hibernating */
	system_npcx_init_watchdog_reset(dev);

	/* Disable ADC and wait for 1000 us to make sure conversion is done */
	if (IS_ENABLED(CONFIG_ADC))
		system_npcx_turn_off_adc();

	/* Disable kernel timer */
	system_npcx_turn_off_kernel_timer();

	/* Disable instant wake up mode for better power consumption */
	system_npcx_disable_instant_wakeup();

	/*
	 * Set wake-up input GPIOs and turn off the other sources for better
	 * power consumption before entering hibernate mode.
	 */
	system_npcx_set_wakeup_gpios_before_hibernate();

	/*
	 * Give the board a chance to do any late stage hibernation work.  This
	 * is likely going to configure GPIOs for hibernation.  On some boards,
	 * it's possible that this may not return at all.  On those boards,
	 * power to the EC is likely being turn off entirely.
	 */
	if (board_hibernate_late) {
		board_hibernate_late();
	}

	/* Setup a RTC alarm if needed */
	if (IS_ENABLED(CONFIG_RTC) && (seconds || microseconds)) {
		system_set_rtc_alarm(seconds, microseconds);
	}

	/* Clear all pending IRQs in case wake-up immediately after sleeping */
	for (int i = 0; i < CONFIG_NUM_IRQS; i++) {
		NVIC_ClearPendingIRQ(i);
	}

	/* Execute hibernate by lfw which locates in last 32K block ram */
	system_npcx_hibernate_by_lfw_in_last_ram(dev, pd_ram_mask);
}

static const char *cros_system_npcx_get_chip_vendor(const struct device *dev)
{
	struct mswc_reg *const inst_mswc = HAL_MSWC_INST(dev);
	static char str[11] = "Unknown-XX";
	char *p = str + 8;
	uint8_t fam_id = inst_mswc->SID_CR;

	if (fam_id == FAMILY_ID_NPCX) {
		return "Nuvoton";
	}

	hex2char(fam_id >> 4, p++);
	hex2char(fam_id & 0xf, p);
	return str;
}

static const char *cros_system_npcx_get_chip_name(const struct device *dev)
{
	struct mswc_reg *const inst_mswc = HAL_MSWC_INST(dev);
	static char str[13] = "Unknown-XXXX";
	char *p = str + 8;
	uint8_t chip_id = inst_mswc->SRID_CR;
	uint8_t device_id = inst_mswc->DEVICE_ID_CR;

	if (chip_id == CHIP_ID_NPCX79NXB_C) {
		switch (device_id) {
		case DEVICE_ID_NPCX796F_B:
			return "NPCX796FB";
		case DEVICE_ID_NPCX796F_C:
			return "NPCX796FC";
		case DEVICE_ID_NPCX797F_C:
			return "NPCX797FC";
		case DEVICE_ID_NPCX797W_B:
			return "NPCX797WB";
		case DEVICE_ID_NPCX797W_C:
			return "NPCX797WC";
		}
	}

	hex2char(chip_id >> 4, p++);
	hex2char(chip_id & 0xf, p++);
	hex2char(device_id >> 4, p++);
	hex2char(device_id & 0xf, p);
	return str;
}

static const char *cros_system_npcx_get_chip_revision(const struct device *dev)
{
	ARG_UNUSED(dev);
	static char rev[NPCX_CHIP_REV_STR_SIZE];
	char *p = rev;
	uint8_t rev_num = *((volatile uint8_t *)NPCX_CHIP_REV_ADDR);

	/*
	 * For NPCX7, the revision number is 1 byte.
	 * For NPCX9 and later chips, the revision number is 4 bytes.
	 */
	for (int s = sizeof(rev_num) - 1; s >= 0; s--) {
		uint8_t r = rev_num >> (s * 8);
		hex2char(r >> 4, p++);
		hex2char(r & 0xf, p++);
	}
	*p = '\0';

	return rev;
}

static void system_npcx_hibernate_by_psl(const struct device *dev,
					 uint32_t seconds,
					 uint32_t microseconds)
{
	ARG_UNUSED(dev);
	/*
	 * TODO(b/178230662): RTC wake-up in PSL mode only support in npcx9
	 * series. Nuvoton will introduce CLs for it later.
	 */
	ARG_UNUSED(seconds);
	ARG_UNUSED(microseconds);

	/*
	 * Configure PSL input pads from "psl-in-pads" property in device tree
	 * file.
	 */
	npcx_pinctrl_psl_input_configure();

	/*
	 * Give the board a chance to do any late stage hibernation work.  This
	 * is likely going to configure GPIOs for hibernation.  On some boards,
	 * it's possible that this may not return at all.  On those boards,
	 * power to the EC is likely being turn off entirely.
	 */
	if (board_hibernate_late)
		board_hibernate_late();

	/* Turn off VCC1 to enter ultra-low-power mode for hibernating */
	npcx_pinctrl_psl_output_set_inactive();
}

static int cros_system_npcx_get_reset_cause(const struct device *dev)
{
	struct cros_system_npcx_data *data = DRV_DATA(dev);

	return data->reset;
}

static int cros_system_npcx_init(const struct device *dev)
{
	struct scfg_reg *const inst_scfg = HAL_SCFG_INST(dev);
	struct twd_reg *const inst_twd = HAL_TWD_INST(dev);
	struct cros_system_npcx_data *data = DRV_DATA(dev);

	/* check reset cause */
	if (IS_BIT_SET(inst_twd->T0CSR, NPCX_T0CSR_WDRST_STS)) {
		data->reset = WATCHDOG_RST;
		inst_twd->T0CSR |= BIT(NPCX_T0CSR_WDRST_STS);
	} else if (IS_BIT_SET(inst_scfg->RSTCTL, NPCX_RSTCTL_DBGRST_STS)) {
		data->reset = DEBUG_RST;
		inst_scfg->RSTCTL |= BIT(NPCX_RSTCTL_DBGRST_STS);
	} else if (IS_BIT_SET(inst_scfg->RSTCTL, NPCX_RSTCTL_VCC1_RST_STS)) {
		data->reset = VCC1_RST_PIN;
	} else {
		data->reset = POWERUP;
	}

	return 0;
}

static int cros_system_npcx_soc_reset(const struct device *dev)
{
	struct twd_reg *const inst_twd = HAL_TWD_INST(dev);

	/* Disable interrupts to avoid task swaps during reboot */
	interrupt_disable_all();

	/*
	 * NPCX chip doesn't have the specific system reset functionality. Use
	 * watchdog reset as a system reset.
	 */

	/* Stop the watchdog */
	system_npcx_watchdog_stop();

	/* Initialize watchdog for reset */
	system_npcx_init_watchdog_reset(dev);

	/*
	 * The trigger of a watchdog event by a "too early service" condition.
	 * When the watchdog is written more than once during three watchdog
	 * clock cycle.
	 */
	inst_twd->WDSDM = 0x5C;
	inst_twd->WDSDM = 0x5C;

	/* Wait for the soc reset. */
	while (1) {
		;
	}

	/* should never return */
	return 0;
}

static int cros_system_npcx_hibernate(const struct device *dev,
				      uint32_t seconds, uint32_t microseconds)
{
	/* Disable interrupt first */
	interrupt_disable_all();

	/* Stop the watchdog */
	system_npcx_watchdog_stop();

	/* Enter hibernate mode */
	if (IS_ENABLED(CONFIG_PLATFORM_EC_SYSTEM_HIBERNATE_PSL)) {
		system_npcx_hibernate_by_psl(dev, seconds, microseconds);
	} else {
		system_npcx_hibernate_by_disable_ram(dev, seconds,
						     microseconds);
	}

	return 0;
}

static struct cros_system_npcx_data cros_system_npcx_dev_data;

static const struct cros_system_npcx_config cros_system_dev_cfg = {
	.base_scfg = DT_REG_ADDR(DT_INST(0, nuvoton_npcx_scfg)),
	.base_twd = DT_REG_ADDR(DT_INST(0, nuvoton_npcx_watchdog)),
	.base_mswc =
		DT_REG_ADDR_BY_NAME(DT_INST(0, nuvoton_npcx_host_sub), mswc),
};

static const struct cros_system_driver_api cros_system_driver_npcx_api = {
	.get_reset_cause = cros_system_npcx_get_reset_cause,
	.soc_reset = cros_system_npcx_soc_reset,
	.hibernate = cros_system_npcx_hibernate,
	.chip_vendor = cros_system_npcx_get_chip_vendor,
	.chip_name = cros_system_npcx_get_chip_name,
	.chip_revision = cros_system_npcx_get_chip_revision,
};

/*
 * The priority of cros_system_npcx_init() should be higher than watchdog init
 * for reset cause check.
 */
DEVICE_DEFINE(cros_system_npcx_0, "CROS_SYSTEM", cros_system_npcx_init, NULL,
	      &cros_system_npcx_dev_data, &cros_system_dev_cfg, PRE_KERNEL_1,
	      CONFIG_CROS_SYSTEM_NPCX_INIT_PRIORITY,
	      &cros_system_driver_npcx_api);

#define HAL_DBG_REG_BASE_ADDR \
	((struct dbg_reg *)DT_REG_ADDR(DT_INST(0, nuvoton_npcx_cros_dbg)))

#define DBG_NODE           DT_NODELABEL(dbg)
#define DBG_PINCTRL_PH     DT_PHANDLE_BY_IDX(DBG_NODE, pinctrl_0, 0)
#define DBG_ALT_FILED(f)   DT_PHA_BY_IDX(DBG_PINCTRL_PH, alts, 0, f)

static int jtag_init(const struct device *dev)
{
	ARG_UNUSED(dev);
	struct dbg_reg *const dbg_reg_base = HAL_DBG_REG_BASE_ADDR;
	const struct npcx_alt jtag_alts[] = {
		{
			.group = DBG_ALT_FILED(group),
			.bit = DBG_ALT_FILED(bit),
			.inverted = DBG_ALT_FILED(inv)
		}
	};

	dbg_reg_base->DBGCTRL = 0x04;
	dbg_reg_base->DBGFRZEN3 &= ~BIT(NPCX_DBGFRZEN3_GLBL_FRZ_DIS);
	if (DT_NODE_HAS_STATUS(DT_NODELABEL(dbg), okay))
		npcx_pinctrl_mux_configure(jtag_alts, 1, 1);

	return 0;
}
#if CONFIG_KERNEL_INIT_PRIORITY_DEFAULT >= 41
#error "jtag_init must be called after default kernel init"
#endif
SYS_INIT(jtag_init, PRE_KERNEL_1, 41);
