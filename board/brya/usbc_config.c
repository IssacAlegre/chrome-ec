/* Copyright 2021 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "common.h"

#include "cbi_ec_fw_config.h"
#include "driver/bc12/pi3usb9201_public.h"
#include "driver/ppc/nx20p348x.h"
#include "driver/ppc/syv682x_public.h"
#include "driver/retimer/bb_retimer_public.h"
#include "driver/tcpm/nct38xx.h"
#include "driver/tcpm/ps8xxx_public.h"
#include "driver/tcpm/tcpci.h"
#include "hooks.h"
#include "ioexpander.h"
#include "system.h"
#include "timer.h"
#include "usbc_config.h"
#include "usbc_ppc.h"
#include "usb_mux.h"
#include "usb_pd_tcpm.h"

#define CPRINTF(format, args...) cprintf(CC_USBPD, format, ## args)
#define CPRINTS(format, args...) cprints(CC_USBPD, format, ## args)

/* USBC TCPC configuration */
const struct tcpc_config_t tcpc_config[] = {
	[USBC_PORT_C0] = {
		.bus_type = EC_BUS_TYPE_I2C,
		.i2c_info = {
			.port = I2C_PORT_USB_C0_C2_TCPC,
			.addr_flags = NCT38XX_I2C_ADDR1_1_FLAGS,
		},
		.drv = &nct38xx_tcpm_drv,
		.flags = TCPC_FLAGS_TCPCI_REV2_0,
	},
	[USBC_PORT_C1] = {
		.bus_type = EC_BUS_TYPE_I2C,
		.i2c_info = {
			.port = I2C_PORT_USB_C1_TCPC,
			.addr_flags = PS8751_I2C_ADDR1_FLAGS,
		},
		.drv = &ps8xxx_tcpm_drv,
		.flags = TCPC_FLAGS_TCPCI_REV2_0 |
			 TCPC_FLAGS_TCPCI_REV2_0_NO_VSAFE0V,
	},
	[USBC_PORT_C2] = {
		.bus_type = EC_BUS_TYPE_I2C,
		.i2c_info = {
			.port = I2C_PORT_USB_C0_C2_TCPC,
			.addr_flags = NCT38XX_I2C_ADDR2_1_FLAGS,
		},
		.drv = &nct38xx_tcpm_drv,
		.flags = TCPC_FLAGS_TCPCI_REV2_0,
	},
};
BUILD_ASSERT(ARRAY_SIZE(tcpc_config) == USBC_PORT_COUNT);
BUILD_ASSERT(CONFIG_USB_PD_PORT_MAX_COUNT == USBC_PORT_COUNT);

/* USBC PPC configuration */
struct ppc_config_t ppc_chips[] = {
	[USBC_PORT_C0] = {
		.i2c_port = I2C_PORT_USB_C0_C2_PPC,
		.i2c_addr_flags = SYV682X_ADDR0_FLAGS,
		.drv = &syv682x_drv,
	},
	[USBC_PORT_C1] = {
		/* Compatible with Silicon Mitus SM536A0 */
		.i2c_port = I2C_PORT_USB_C1_PPC,
		.i2c_addr_flags = NX20P3483_ADDR2_FLAGS,
		.drv = &nx20p348x_drv,
	},
	[USBC_PORT_C2] = {
		.i2c_port = I2C_PORT_USB_C0_C2_PPC,
		/*
		 * b/179987870
		 * schematics I2C map says ADDR3
		 */
		.i2c_addr_flags = SYV682X_ADDR2_FLAGS,
		.drv = &syv682x_drv,
	},
};
BUILD_ASSERT(ARRAY_SIZE(ppc_chips) == USBC_PORT_COUNT);

unsigned int ppc_cnt = ARRAY_SIZE(ppc_chips);

/* USBC mux configuration - Alder Lake includes internal mux */
static const struct usb_mux usbc0_tcss_usb_mux = {
	.usb_port = USBC_PORT_C0,
	.driver = &virtual_usb_mux_driver,
	.hpd_update = &virtual_hpd_update,
};
static const struct usb_mux usbc2_tcss_usb_mux = {
	.usb_port = USBC_PORT_C2,
	.driver = &virtual_usb_mux_driver,
	.hpd_update = &virtual_hpd_update,
};

/*
 * USB3 DB mux configuration - the top level mux still needs to be set
 * to the virtual_usb_mux_driver so the AP gets notified of mux changes
 * and updates the TCSS configuration on state changes.
 */
static const struct usb_mux usbc1_usb3_db_retimer = {
	.usb_port = USBC_PORT_C1,
	.driver = &tcpci_tcpm_usb_mux_driver,
	.hpd_update = &ps8xxx_tcpc_update_hpd_status,
};

const struct usb_mux usb_muxes[] = {
	[USBC_PORT_C0] = {
		.usb_port = USBC_PORT_C0,
		.driver = &bb_usb_retimer,
		.i2c_port = I2C_PORT_USB_C0_C2_MUX,
		.i2c_addr_flags = USBC_PORT_C0_BB_RETIMER_I2C_ADDR,
		.next_mux = &usbc0_tcss_usb_mux,
	},
	[USBC_PORT_C1] = {
		/* PS8815 DB */
		.usb_port = USBC_PORT_C1,
		.driver = &virtual_usb_mux_driver,
		.hpd_update = &virtual_hpd_update,
		.next_mux = &usbc1_usb3_db_retimer,
	},
	[USBC_PORT_C2] = {
		.usb_port = USBC_PORT_C2,
		.driver = &bb_usb_retimer,
		.i2c_port = I2C_PORT_USB_C0_C2_MUX,
		.i2c_addr_flags = USBC_PORT_C2_BB_RETIMER_I2C_ADDR,
		.next_mux = &usbc2_tcss_usb_mux,
	},
};
BUILD_ASSERT(ARRAY_SIZE(usb_muxes) == USBC_PORT_COUNT);

/* BC1.2 charger detect configuration */
const struct pi3usb9201_config_t pi3usb9201_bc12_chips[] = {
	[USBC_PORT_C0] = {
		.i2c_port = I2C_PORT_USB_C0_C2_BC12,
		.i2c_addr_flags = PI3USB9201_I2C_ADDR_3_FLAGS,
	},
	[USBC_PORT_C1] = {
		.i2c_port = I2C_PORT_USB_C1_BC12,
		.i2c_addr_flags = PI3USB9201_I2C_ADDR_3_FLAGS,
	},
	[USBC_PORT_C2] = {
		.i2c_port = I2C_PORT_USB_C0_C2_BC12,
		.i2c_addr_flags = PI3USB9201_I2C_ADDR_1_FLAGS,
	},
};
BUILD_ASSERT(ARRAY_SIZE(pi3usb9201_bc12_chips) == USBC_PORT_COUNT);

/*
 * USB C0 and C2 uses burnside bridge chips and have their reset
 * controlled by their respective TCPC chips acting as GPIO expanders.
 *
 * ioex_init() is normally called before we take the TCPCs out of
 * reset, so we need to start in disabled mode, then explicitly
 * call ioex_init().
 */

struct ioexpander_config_t ioex_config[] = {
	[IOEX_C0_NCT38XX] = {
		.i2c_host_port = I2C_PORT_USB_C0_C2_TCPC,
		.i2c_addr_flags = NCT38XX_I2C_ADDR1_1_FLAGS,
		.drv = &nct38xx_ioexpander_drv,
		.flags = IOEX_FLAGS_DISABLED,
	},
	[IOEX_C2_NCT38XX] = {
		.i2c_host_port = I2C_PORT_USB_C0_C2_TCPC,
		.i2c_addr_flags = NCT38XX_I2C_ADDR2_1_FLAGS,
		.drv = &nct38xx_ioexpander_drv,
		.flags = IOEX_FLAGS_DISABLED,
	},
};
BUILD_ASSERT(ARRAY_SIZE(ioex_config) == CONFIG_IO_EXPANDER_PORT_COUNT);

void config_usb_db_type(void)
{
	enum ec_cfg_usb_db_type db_type = ec_cfg_usb_db_type();

	/*
	 * TODO(b/180434685): implement multiple DB types
	 */

	CPRINTS("Configured USB DB type number is %d", db_type);
}

__override void bb_retimer_power_handle(const struct usb_mux *me, int on_off)
{
	enum ioex_signal rst_signal;

	if (me->usb_port == USBC_PORT_C0)
		rst_signal = IOEX_USB_C0_RT_RST_ODL;
	else if (me->usb_port == USBC_PORT_C2)
		rst_signal = IOEX_USB_C2_RT_RST_ODL;
	else
		return;

	/*
	 * We do not have a load switch for the burnside bridge chips,
	 * so we only need to sequence reset.
	 */

	if (on_off) {
		/*
		 * Tpw, minimum time from VCC to RESET_N de-assertion is 100us.
		 * For boards that don't provide a load switch control, the
		 * retimer_init() function ensures power is up before calling
		 * this function.
		 */
		ioex_set_level(rst_signal, 1);
		/*
		 * Allow 1ms time for the retimer to power up lc_domain
		 * which powers I2C controller within retimer
		 */
		msleep(1);
	} else {
		ioex_set_level(rst_signal, 0);
		msleep(1);
	}
}

void board_reset_pd_mcu(void)
{
	/*
	 * TODO(b/179648104): figure out correct timing
	 */

	gpio_set_level(GPIO_USB_C0_C2_TCPC_RST_ODL, 0);
	if (ec_cfg_usb_db_type() != DB_USB_ABSENT) {
		gpio_set_level(GPIO_USB_C1_RST_ODL, 0);
		gpio_set_level(GPIO_USB_C1_RT_RST_R_ODL, 0);
	}

	/*
	 * delay for power-on to reset-off and min. assertion time
	 */

	msleep(20);

	gpio_set_level(GPIO_USB_C0_C2_TCPC_RST_ODL, 1);
	if (ec_cfg_usb_db_type() != DB_USB_ABSENT) {
		gpio_set_level(GPIO_USB_C1_RST_ODL, 1);
		gpio_set_level(GPIO_USB_C1_RT_RST_R_ODL, 1);
	}

	/* wait for chips to come up */

	msleep(50);
}

static void board_tcpc_init(void)
{
	int i;

	/* Don't reset TCPCs after initial reset */
	if (!system_jumped_late()) {
		board_reset_pd_mcu();

		for (i = 0; i < CONFIG_IO_EXPANDER_PORT_COUNT; ++i) {
			ioex_config[i].flags &= ~IOEX_FLAGS_DISABLED;
			ioex_init(i);
		}
	}

	/* Enable PPC interrupts. */
	gpio_enable_interrupt(GPIO_USB_C0_PPC_INT_ODL);
	gpio_enable_interrupt(GPIO_USB_C2_PPC_INT_ODL);

	/* Enable TCPC interrupts. */
	gpio_enable_interrupt(GPIO_USB_C0_C2_TCPC_INT_ODL);

	/* Enable BC1.2 interrupts. */
	gpio_enable_interrupt(GPIO_USB_C0_BC12_INT_ODL);
	gpio_enable_interrupt(GPIO_USB_C2_BC12_INT_ODL);

	if (ec_cfg_usb_db_type() != DB_USB_ABSENT) {
		gpio_enable_interrupt(GPIO_USB_C1_PPC_INT_ODL);
		gpio_enable_interrupt(GPIO_USB_C1_TCPC_INT_ODL);
		gpio_enable_interrupt(GPIO_USB_C1_BC12_INT_ODL);
	}
}
DECLARE_HOOK(HOOK_INIT, board_tcpc_init, HOOK_PRIO_INIT_CHIPSET);

uint16_t tcpc_get_alert_status(void)
{
	uint16_t status = 0;

	if (gpio_get_level(GPIO_USB_C0_C2_TCPC_INT_ODL) == 0)
		status |= PD_STATUS_TCPC_ALERT_0 | PD_STATUS_TCPC_ALERT_2;

	if ((ec_cfg_usb_db_type() != DB_USB_ABSENT) &&
	    gpio_get_level(GPIO_USB_C1_TCPC_INT_ODL) == 0)
		status |= PD_STATUS_TCPC_ALERT_1;

	return status;
}

int ppc_get_alert_status(int port)
{
	if (port == USBC_PORT_C0)
		return gpio_get_level(GPIO_USB_C0_PPC_INT_ODL) == 0;
	else if ((port == USBC_PORT_C1) &&
		 (ec_cfg_usb_db_type() != DB_USB_ABSENT))
		return gpio_get_level(GPIO_USB_C1_PPC_INT_ODL) == 0;
	else if (port == USBC_PORT_C2)
		return gpio_get_level(GPIO_USB_C2_PPC_INT_ODL) == 0;
	return 0;
}

void tcpc_alert_event(enum gpio_signal signal)
{
	switch (signal) {
	case GPIO_USB_C0_C2_TCPC_INT_ODL:
		schedule_deferred_pd_interrupt(USBC_PORT_C0);
		break;
	case GPIO_USB_C1_TCPC_INT_ODL:
		if (ec_cfg_usb_db_type() == DB_USB_ABSENT)
			break;
		schedule_deferred_pd_interrupt(USBC_PORT_C1);
		break;
	default:
		break;
	}
}

void bc12_interrupt(enum gpio_signal signal)
{
	switch (signal) {
	case GPIO_USB_C0_BC12_INT_ODL:
		task_set_event(TASK_ID_USB_CHG_P0, USB_CHG_EVENT_BC12);
		break;
	case GPIO_USB_C1_BC12_INT_ODL:
		if (ec_cfg_usb_db_type() == DB_USB_ABSENT)
			break;
		task_set_event(TASK_ID_USB_CHG_P1, USB_CHG_EVENT_BC12);
		break;
	case GPIO_USB_C2_BC12_INT_ODL:
		task_set_event(TASK_ID_USB_CHG_P2, USB_CHG_EVENT_BC12);
		break;
	default:
		break;
	}
}

void ppc_interrupt(enum gpio_signal signal)
{
	switch (signal) {
	case GPIO_USB_C0_PPC_INT_ODL:
		syv682x_interrupt(USBC_PORT_C0);
		break;
	case GPIO_USB_C1_PPC_INT_ODL:
		switch (ec_cfg_usb_db_type()) {
		case DB_USB_ABSENT:
		case DB_USB_ABSENT2:
			break;
		case DB_USB3_PS8815:
			nx20p348x_interrupt(USBC_PORT_C1);
			break;
		}
		break;
	case GPIO_USB_C2_PPC_INT_ODL:
		syv682x_interrupt(USBC_PORT_C2);
		break;
	default:
		break;
	}
}

void retimer_interrupt(enum gpio_signal signal)
{
	/*
	 * TODO(b/179513527): add USB-C support
	 */
}
