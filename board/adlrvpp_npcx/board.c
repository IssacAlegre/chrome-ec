/* Copyright 2021 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* Intel ADLRVP-NPCX board-specific configuration */
#include "button.h"
#include "fusb302.h"
#include "lid_switch.h"
#include "power.h"
#include "power_button.h"
#include "switch.h"
#include "tablet_mode.h"
#include "uart.h"
#include "usb_pd_tcpm.h"

#include "gpio_list.h" /* Must come after other header files. */

/******************************************************************************/
/* I2C ports */
const struct i2c_port_t i2c_ports[] = {
	[I2C_CHAN_BATT_CHG] = {
		.name = "batt_chg",
		.port = I2C_PORT_CHARGER,
		.kbps = 100,
		.scl = GPIO_SMB_BS_CLK,
		.sda = GPIO_SMB_BS_DATA,
	},
	[I2C_CHAN_TYPEC_0] = {
		.name = "typec_0",
		.port = I2C_PORT_TYPEC_0,
		.kbps = 400,
		.scl = GPIO_USBC_TCPC_I2C_CLK_P0,
		.sda = GPIO_USBC_TCPC_I2C_DATA_P0,
	},
	[I2C_CHAN_TYPEC_1] = {
		.name = "typec_1",
		.port = I2C_PORT_TYPEC_1,
		.kbps = 400,
		.scl = GPIO_USBC_TCPC_I2C_CLK_P2,
		.sda = GPIO_USBC_TCPC_I2C_DATA_P2,
	},
#if defined(HAS_TASK_PD_C2)
	[I2C_CHAN_TYPEC_2] = {
		.name = "typec_2",
		.port = I2C_PORT_TYPEC_2,
		.kbps = 400,
		.scl = GPIO_USBC_TCPC_I2C_CLK_P1,
		.sda = GPIO_USBC_TCPC_I2C_DATA_P1,
	},
#endif
#if defined(HAS_TASK_PD_C3)
	[I2C_CHAN_TYPEC_3] = {
		.name = "typec_3",
		.port = I2C_PORT_TYPEC_3,
		.kbps = 400,
		.scl = GPIO_USBC_TCPC_I2C_CLK_P3,
		.sda = GPIO_USBC_TCPC_I2C_DATA_P3,
	},
#endif
};
BUILD_ASSERT(ARRAY_SIZE(i2c_ports) == I2C_CHAN_COUNT);
const unsigned int i2c_ports_used = ARRAY_SIZE(i2c_ports);

/* USB-C TCPC Configuration */
const struct tcpc_config_t tcpc_config[] = {
	[TYPE_C_PORT_0] = {
		.bus_type = EC_BUS_TYPE_I2C,
		.i2c_info = {
			.port = I2C_PORT_TYPEC_0,
			.addr_flags = I2C_ADDR_FUSB302_TCPC_AIC,
		},
		.drv = &fusb302_tcpm_drv,
	},
	[TYPE_C_PORT_1] = {
		.bus_type = EC_BUS_TYPE_I2C,
		.i2c_info = {
			.port = I2C_PORT_TYPEC_1,
			.addr_flags = I2C_ADDR_FUSB302_TCPC_AIC,
		},
		.drv = &fusb302_tcpm_drv,
	},
#if defined(HAS_TASK_PD_C2)
	[TYPE_C_PORT_2] = {
		.bus_type = EC_BUS_TYPE_I2C,
		.i2c_info = {
			.port = I2C_PORT_TYPEC_2,
			.addr_flags = I2C_ADDR_FUSB302_TCPC_AIC,
		},
		.drv = &fusb302_tcpm_drv,
	},
#endif
#if defined(HAS_TASK_PD_C3)
	[TYPE_C_PORT_3] = {
		.bus_type = EC_BUS_TYPE_I2C,
		.i2c_info = {
			.port = I2C_PORT_TYPEC_3,
			.addr_flags = I2C_ADDR_FUSB302_TCPC_AIC,
		},
		.drv = &fusb302_tcpm_drv,
	},
#endif
};
BUILD_ASSERT(ARRAY_SIZE(tcpc_config) == CONFIG_USB_PD_PORT_MAX_COUNT);
