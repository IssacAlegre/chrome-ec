/* Copyright 2020 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* Gingerbread board configuration */

#ifndef __CROS_EC_BOARD_H
#define __CROS_EC_BOARD_H

/* Baseboard features */
#include "baseboard.h"

/* Optional features */
#define CONFIG_SYSTEM_UNLOCKED /* Allow dangerous commands while in dev. */

#define CONFIG_WP_ACTIVE_HIGH

/* Console */
#define CONFIG_UART_CONSOLE 3
#define CONFIG_UART_TX_DMA_CH STM32_DMAC_USART3_TX
#define CONFIG_UART_TX_DMA_PH DMAMUX_REQ_USART3_TX

/* USB Type C and USB PD defines */
#define USB_PD_PORT_HOST   0
#define USB_PD_PORT_DP   1

#define CONFIG_USB_PD_PORT_MAX_COUNT 2
#define CONFIG_USB_MUX_TUSB1064
#define CONFIG_USBC_PPC_STUB
#define CONFIG_USB_PD_VBUS_ALERT_TCPC

#define CONFIG_USB_PID 0x5049
#define CONFIG_USB_BCD_DEV 0x0001 /* v 0.01 */
#define CONFIG_USB_PD_IDENTITY_HW_VERS 1
#define CONFIG_USB_PD_IDENTITY_SW_VERS 1

/* I2C port names */
#define I2C_PORT_I2C1	0
#define I2C_PORT_I2C2	1
#define I2C_PORT_I2C3	2
/* Required symbolic I2C port names */
#define I2C_PORT_MP4245 I2C_PORT_I2C3
#define I2C_PORT_EEPROM I2C_PORT_I2C1
#define MP4245_I2C_ADDR_FLAGS  MP4245_I2C_ADDR_0_FLAGS

/*
 * Macros for GPIO signals used in common code that don't match the
 * schematic names. Signal names in gpio.inc match the schematic and are
 * then redefined here to so it's more clear which signal is being used for
 * which purpose.
 */
#define GPIO_ENTERING_RW	GPIO_EC_ENTERING_RW
#define GPIO_WP_L		GPIO_EC_WP_L
#define GPIO_WP		GPIO_EC_WP_L

#ifndef __ASSEMBLER__

#include "registers.h"

#define GPIO_DP_HPD GPIO_DDI_MST_IN_HPD

#define GPIO_TRIGGER_1 GPIO_EC_HUB1_RESET_L
#define GPIO_TRIGGER_2 GPIO_EC_HUB2_RESET_L

enum  debug_gpio {
	TRIGGER_1 = 0,
	TRIGGER_2,
};

/*
 * Function used to control GPIO signals as a timing marker. This is intended to
 * be used for development/debugging purposes.
 *
 * @param trigger GPIO debug signal selection
 * @param level desired level of the debug gpio signal
 * @param pulse_usec pulse width if non-zero
 */
void board_debug_gpio(enum debug_gpio trigger, int level, int pulse_usec);

/*
 * Function called in power on case to enable usbc related interrupts
 */
void board_enable_usbc_interrupts(void);

/*
 * Function called in power off case to disable usbc related interrupts
 */
void board_disable_usbc_interrupts(void);

#endif /* !__ASSEMBLER__ */

#endif /* __CROS_EC_BOARD_H */
