/* Copyright 2021 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* Baklava board configuration */

#ifndef __CROS_EC_BOARD_H
#define __CROS_EC_BOARD_H

/* Baseboard features */
#include "baseboard.h"

/* Optional features */
#define CONFIG_SYSTEM_UNLOCKED /* Allow dangerous commands while in dev. */

/* USB Type C and USB PD defines */
#define USB_PD_PORT_HOST   0
#define USB_PD_PORT_USB3   1

/*
 * Only the host and display usbc ports are usb-pd capable. There is a 2nd usbc
 * port, but this is type-c capable only. Only the PPC for this port needs to be
 * controlled by FW.
 */
#define CONFIG_USB_PD_PORT_MAX_COUNT 2
#define CONFIG_USB_MUX_PS8822

#define CONFIG_USB_PID 0x1195
#define CONFIG_USB_BCD_DEV 0x0001 /* v 0.01 */
#define CONFIG_USB_PD_IDENTITY_HW_VERS 1
#define CONFIG_USB_PD_IDENTITY_SW_VERS 1

/* I2C port names */
#define I2C_PORT_I2C1	0
#define I2C_PORT_I2C2	1
#define I2C_PORT_I2C3	2

/* Required symbolic I2C port names */
#define I2C_PORT_MP4245 I2C_PORT_I2C3
#define I2C_PORT_EEPROM I2C_PORT_I2C3
#define MP4245_I2C_ADDR_FLAGS MP4245_I2C_ADDR_0_FLAGS

#ifndef __ASSEMBLER__

#include "registers.h"

#define GPIO_DP_HPD GPIO_DDI_MST_IN_HPD

#define GPIO_TRIGGER_1 GPIO_TP41
#define GPIO_TRIGGER_2 GPIO_TP73

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
