/* Copyright 2020 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* Volteer board configuration */

#ifndef __CROS_EC_BOARD_H
#define __CROS_EC_BOARD_H

/* Baseboard features */
#include "baseboard.h"

/* Optional features */
#define CONFIG_SYSTEM_UNLOCKED /* Allow dangerous commands while in dev. */

#define CONFIG_POWER_BUTTON

#undef CONFIG_UART_TX_BUF_SIZE
#define CONFIG_UART_TX_BUF_SIZE 4096

/* LED defines */
#define CONFIG_LED_POWER_LED
#define CONFIG_LED_ONOFF_STATES
#define CONFIG_LED_ONOFF_STATES_BAT_LOW 10

/* Keyboard features */

/* Sensors */
/* BMA253 accelerometer in base */
#define CONFIG_ACCEL_BMA255

/* TCS3400 ALS */
#define CONFIG_ALS
#define ALS_COUNT		1
#define CONFIG_ALS_TCS3400
#define CONFIG_ALS_TCS3400_INT_EVENT \
	TASK_EVENT_MOTION_SENSOR_INTERRUPT(CLEAR_ALS)

/* Sensors without hardware FIFO are in forced mode */
#define CONFIG_ACCEL_FORCE_MODE_MASK \
	(BIT(LID_ACCEL) | BIT(CLEAR_ALS))

/* USB Type C and USB PD defines */
#define CONFIG_USB_PD_PORT_MAX_COUNT			3

#define PD_POWER_SUPPLY_TURN_ON_DELAY	30000 /* us */
#define PD_POWER_SUPPLY_TURN_OFF_DELAY	250000 /* us */

/*
 * SN5S30 PPC supports up to 24V VBUS source and sink, however passive USB-C
 * cables only support up to 60W.
 */
#define PD_OPERATING_POWER_MW	15000
#define PD_MAX_POWER_MW		65000
#define PD_MAX_CURRENT_MA	3250
#define PD_MAX_VOLTAGE_MV	20000

/* Enabling Thunderbolt-compatible mode */
#define CONFIG_USB_PD_TBT_COMPAT_MODE

/* Enabling USB4 mode */
#define CONFIG_USB_PD_USB4
#define USBC_PORT_C0_BB_RETIMER_I2C_ADDR	0x40
#define USBC_PORT_C1_BB_RETIMER_I2C_ADDR	0x41
#define USBC_PORT_C2_BB_RETIMER_I2C_ADDR	0x42

/* USB Type A Features */

/* USBC PPC*/
#define CONFIG_USBC_PPC_SYV682X		/* USBC port C0 C1 C2 */

/* BC 1.2 */

/* Volume Button feature */

/* Fan features */

/* charger defines */
#define CONFIG_CHARGER_SENSE_RESISTOR		5
#define CONFIG_CHARGER_SENSE_RESISTOR_AC	10

/*
 * Macros for GPIO signals used in common code that don't match the
 * schematic names. Signal names in gpio.inc match the schematic and are
 * then redefined here to so it's more clear which signal is being used for
 * which purpose.
 */
#define GPIO_AC_PRESENT			GPIO_ACOK_OD
#define GPIO_EC_INT_L			GPIO_EC_PCH_INT_ODL
#define GPIO_EN_PP5000			GPIO_EN_PP5000_A
#define GPIO_ENTERING_RW		GPIO_EC_ENTERING_RW
#define GPIO_LID_OPEN			GPIO_EC_LID_OPEN
#define GPIO_KBD_KSO2			GPIO_EC_KSO_02_INV
#define GPIO_PCH_WAKE_L			GPIO_EC_PCH_WAKE_ODL
#define GPIO_PCH_PWRBTN_L		GPIO_EC_PCH_PWR_BTN_ODL
#define GPIO_PCH_RSMRST_L		GPIO_EC_PCH_RSMRST_ODL
#define GPIO_PCH_RTCRST			GPIO_EC_PCH_RTCRST
#define GPIO_PCH_SYS_PWROK		GPIO_EC_PCH_SYS_PWROK
#define GPIO_PCH_SLP_S0_L		GPIO_SLP_S0_L
#define GPIO_PCH_SLP_S3_L		GPIO_SLP_S3_L
#define GPIO_PG_EC_DSW_PWROK		GPIO_DSW_PWROK
#define GPIO_POWER_BUTTON_L		GPIO_H1_EC_PWR_BTN_ODL
#define GPIO_RSMRST_L_PGOOD		GPIO_PG_EC_RSMRST_ODL
#define GPIO_CPU_PROCHOT		GPIO_EC_PROCHOT_ODL
#define GPIO_SYS_RESET_L		GPIO_SYS_RST_ODL
#define GPIO_USB_C0_BC12_INT_ODL	GPIO_USB_C0_MIX_INT_ODL
#define GPIO_USB_C1_BC12_INT_ODL	GPIO_USB_C1_MIX_INT_ODL
#define GPIO_USB_C2_BC12_INT_ODL	GPIO_USB_C2_MIX_INT_ODL
#define GPIO_WP_L			GPIO_EC_WP_L
#define GMR_TABLET_MODE_GPIO_L		GPIO_TABLET_MODE_L

#undef CONFIG_FANS
#undef CONFIG_VOLUME_BUTTONS

/* I2C Bus Configuration */
#define CONFIG_I2C
#define I2C_PORT_SENSOR		NPCX_I2C_PORT0_0
#define I2C_PORT_USB_C0		NPCX_I2C_PORT1_0
#define I2C_PORT_USB_C1		NPCX_I2C_PORT2_0
#define I2C_PORT_USB_BB_RETIMER	NPCX_I2C_PORT3_0
#define I2C_PORT_USB_C2		NPCX_I2C_PORT4_1
#define I2C_PORT_POWER		NPCX_I2C_PORT5_0
#define I2C_PORT_EEPROM		NPCX_I2C_PORT7_0

#define I2C_PORT_BATTERY	I2C_PORT_POWER
#define I2C_PORT_CHARGER	I2C_PORT_EEPROM
#define I2C_PORT_USB_1_MIX	I2C_PORT_USB_BB_RETIMER

#define I2C_ADDR_EEPROM_FLAGS	0x50
#define CONFIG_I2C_CONTROLLER


#ifndef __ASSEMBLER__

#include "gpio_signal.h"
#include "registers.h"

enum battery_type {
	BATTERY_AEC,
	BATTERY_TYPE_COUNT,
};

enum pwm_channel {
	PWM_CH_LED1_BLUE = 0,
	PWM_CH_LED2_GREEN,
	PWM_CH_LED3_RED,
	PWM_CH_LED4_SIDESEL,
	PWM_CH_FAN,
	PWM_CH_KBLIGHT,
	PWM_CH_COUNT
};

enum sensor_id {
	LID_ACCEL = 0,
	CLEAR_ALS,
	RGB_ALS,
	SENSOR_COUNT,
};

enum usbc_port {
	USBC_PORT_C0 = 0,
	USBC_PORT_C1,
	USBC_PORT_C2,
	USBC_PORT_COUNT
};

/* Definition for Halvor USB PD interrupt handlers. */
void halvor_tcpc_alert_event(enum gpio_signal signal);
void halvor_ppc_interrupt(enum gpio_signal signal);
void halvor_bc12_interrupt(enum gpio_signal signal);

void board_reset_pd_mcu(void);

#endif /* !__ASSEMBLER__ */

#endif /* __CROS_EC_BOARD_H */
