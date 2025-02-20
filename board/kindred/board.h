/* Copyright 2019 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* Hatch board configuration */

#ifndef __CROS_EC_BOARD_H
#define __CROS_EC_BOARD_H

/* Baseboard features */
#include "baseboard.h"

#define CONFIG_POWER_BUTTON
#undef  CONFIG_POWER_BUTTON_INIT_TIMEOUT
#define CONFIG_POWER_BUTTON_INIT_TIMEOUT 2
#define CONFIG_KEYBOARD_PROTOCOL_8042
#define CONFIG_LED_COMMON
#define CONFIG_LOW_POWER_IDLE

#define CONFIG_HOSTCMD_ESPI

#undef CONFIG_UART_TX_BUF_SIZE
#define CONFIG_UART_TX_BUF_SIZE 4096

/* Keyboard features */
#define CONFIG_PWM
#define CONFIG_PWM_KBLIGHT
/* support factory keyboard test */
#define CONFIG_KEYBOARD_FACTORY_TEST

/* Sensors */
/* BMI160 Base accel/gyro */
#define CONFIG_ACCEL_INTERRUPTS

#define CONFIG_ACCELGYRO_BMI160
#define CONFIG_ACCELGYRO_BMI160_INT_EVENT \
	TASK_EVENT_MOTION_SENSOR_INTERRUPT(BASE_ACCEL)

#define CONFIG_ACCELGYRO_ICM426XX
#define CONFIG_ACCELGYRO_ICM426XX_INT_EVENT \
	TASK_EVENT_MOTION_SENSOR_INTERRUPT(BASE_ACCEL)

#define CONFIG_ACCELGYRO_BMI160_INT2_OUTPUT
/* BMA253 Lid accel */
#define CONFIG_ACCEL_BMA255
#define CONFIG_ACCEL_KX022
#define CONFIG_LID_ANGLE
#define CONFIG_LID_ANGLE_SENSOR_BASE BASE_ACCEL
#define CONFIG_LID_ANGLE_SENSOR_LID LID_ACCEL
#define CONFIG_LID_ANGLE_UPDATE
#define CONFIG_DYNAMIC_MOTION_SENSOR_COUNT

/* USB Type C and USB PD defines */
#define CONFIG_USB_PD_COMM_LOCKED
#define CONFIG_USB_PD_TCPM_ANX7447
#define CONFIG_USB_PD_TCPM_ANX7447_AUX_PU_PD
#define CONFIG_USB_PD_TCPM_PS8751
#define BOARD_TCPC_C0_RESET_HOLD_DELAY ANX74XX_RESET_HOLD_MS
#define BOARD_TCPC_C0_RESET_POST_DELAY ANX74XX_RESET_HOLD_MS
#define BOARD_TCPC_C1_RESET_HOLD_DELAY PS8XXX_RESET_DELAY_MS
#define BOARD_TCPC_C1_RESET_POST_DELAY 0
#define GPIO_USB_C1_TCPC_RST GPIO_USB_C1_TCPC_RST_ODL

/* USB Type A Features */
#define CONFIG_USB_PORT_POWER_SMART
#undef CONFIG_USB_PORT_POWER_SMART_PORT_COUNT
#define CONFIG_USB_PORT_POWER_SMART_PORT_COUNT 1
#define CONFIG_USB_PORT_POWER_SMART_CDP_SDP_ONLY
#define GPIO_USB1_ILIM_SEL GPIO_EN_USB_A_LOW_PWR_OD

/* BC 1.2 */
#define CONFIG_BC12_DETECT_PI3USB9201

/* Charger features */
/*
 * The IDCHG current limit is set in 512 mA steps. The value set here is
 * somewhat specific to the battery pack being currently used. The limit here
 * was set based on the battery's discharge current limit and what was tested to
 * prevent the AP rebooting with low charge level batteries.
 *
 * TODO(b/133447140): Revisit this threshold once peak power consumption tuning
 * for the AP is completed.
 */
#define CONFIG_CHARGER_BQ25710_IDCHG_LIMIT_MA 8192

/* Volume Button feature */
#define CONFIG_VOLUME_BUTTONS
#define GPIO_VOLUME_UP_L GPIO_EC_VOLUP_BTN_ODL
#define GPIO_VOLUME_DOWN_L GPIO_EC_VOLDN_BTN_ODL

/* Fan features */
#define CONFIG_FANS 1
#undef CONFIG_FAN_INIT_SPEED
#define CONFIG_FAN_INIT_SPEED 50
#define CONFIG_TEMP_SENSOR_POWER_GPIO GPIO_EN_A_RAILS
#define CONFIG_THERMISTOR
#define CONFIG_THROTTLE_AP
#define CONFIG_STEINHART_HART_3V3_30K9_47K_4050B

/* MST */
/*
 * TDOD (b/124068003): This inherently assumes the MST chip is connected to only
 * one Type C port. This will need to be chagned to support 2 Type C ports
 * connected to the same MST chip.
 */
#define USB_PD_PORT_TCPC_MST USB_PD_PORT_TCPC_1

/*
 * Macros for GPIO signals used in common code that don't match the
 * schematic names. Signal names in gpio.inc match the schematic and are
 * then redefined here to so it's more clear which signal is being used for
 * which purpose.
 */
#define GPIO_PCH_RSMRST_L	GPIO_EC_PCH_RSMRST_L
#define GPIO_PCH_SLP_S0_L	GPIO_SLP_S0_L
#define GPIO_CPU_PROCHOT	GPIO_EC_PROCHOT_ODL
#define GPIO_AC_PRESENT		GPIO_ACOK_OD
#define GPIO_RSMRST_L_PGOOD	GPIO_PG_EC_RSMRST_L
#define GPIO_PCH_SYS_PWROK	GPIO_EC_PCH_SYS_PWROK
#define GPIO_PCH_SLP_S3_L	GPIO_SLP_S3_L
#define GPIO_PCH_SLP_S4_L	GPIO_SLP_S4_L
#define GPIO_EN_PP5000		GPIO_EN_PP5000_A

#ifndef __ASSEMBLER__
#include "gpio_signal.h"
#include "registers.h"

/* GPIO signals updated base on board version. */
#define GPIO_EN_PP5000_A gpio_en_pp5000_a
extern enum gpio_signal gpio_en_pp5000_a;

enum adc_channel {
	ADC_TEMP_SENSOR_1,	/* ADC0 */
	ADC_TEMP_SENSOR_2,	/* ADC1 */
	ADC_TEMP_SENSOR_3,	/* ADC3 */
	ADC_CH_COUNT
};

enum sensor_id {
	LID_ACCEL = 0,
	BASE_ACCEL,
	BASE_GYRO,
	SENSOR_COUNT,
};

enum pwm_channel {
	PWM_CH_KBLIGHT,
	PWM_CH_FAN,
	PWM_CH_COUNT
};

enum fan_channel {
	FAN_CH_0 = 0,
	/* Number of FAN channels */
	FAN_CH_COUNT,
};

enum mft_channel {
	MFT_CH_0 = 0,
	/* Number of MFT channels */
	MFT_CH_COUNT,
};

enum temp_sensor_id {
	TEMP_SENSOR_1,
	TEMP_SENSOR_2,
	TEMP_SENSOR_3,
	TEMP_SENSOR_COUNT
};

/* List of possible batteries */
enum battery_type {
	BATTERY_LGC_AP18C8K,
	BATTERY_MURATA_AP18C4K,
	BATTERY_TYPE_COUNT,
};

/* Sensors without hardware FIFO are in forced mode */
#define CONFIG_ACCEL_FORCE_MODE_MASK (1 << LID_ACCEL)

extern const int keyboard_factory_scan_pins[][2];
extern const int keyboard_factory_scan_pins_used;
void motion_interrupt(enum gpio_signal signal);
#endif /* !__ASSEMBLER__ */

#endif /* __CROS_EC_BOARD_H */
