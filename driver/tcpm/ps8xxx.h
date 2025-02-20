/* Copyright 2017 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "usb_mux.h"

#include "driver/tcpm/ps8xxx_public.h"

/* Parade Tech Type-C port controller */

#ifndef __CROS_EC_USB_PD_TCPM_PS8XXX_H
#define __CROS_EC_USB_PD_TCPM_PS8XXX_H

#define PS8751_P3_TO_P1_FLAGS(p3_flags)	((p3_flags) - 2)

#define PS8751_BIST_TIMER_FREQ  15000000
#define PS8751_BIST_DELAY_MS    50

#define PS8751_BIST_COUNTER (PS8751_BIST_TIMER_FREQ / MSEC \
				* PS8751_BIST_DELAY_MS)

#define PS8751_BIST_COUNTER_BYTE0 (PS8751_BIST_COUNTER & 0xff)
#define PS8751_BIST_COUNTER_BYTE1 ((PS8751_BIST_COUNTER >> 8) & 0xff)
#define PS8751_BIST_COUNTER_BYTE2 ((PS8751_BIST_COUNTER >> 16) & 0xff)

#define PS8XXX_REG_RP_DETECT_CONTROL            0x9B
#define RP_DETECT_DISABLE			0x30

#define PS8XXX_REG_I2C_DEBUGGING_ENABLE         0xA0
#define PS8XXX_REG_I2C_DEBUGGING_ENABLE_ON      0x30
#define PS8XXX_REG_I2C_DEBUGGING_ENABLE_OFF     0x31    /* default */
#define PS8XXX_REG_BIST_CONT_MODE_BYTE0         0xBC
#define PS8XXX_REG_BIST_CONT_MODE_BYTE1         0xBD
#define PS8XXX_REG_BIST_CONT_MODE_BYTE2         0xBE
#define PS8XXX_REG_BIST_CONT_MODE_CTR           0xBF
#define PS8XXX_REG_DET_CTRL0                    0x08

#define PS8XXX_REG_MUX_USB_DCI_CFG_MODE_MASK    0xC0
#define PS8XXX_REG_MUX_USB_DCI_CFG_MODE_OFF     0x80

#define MUX_IN_HPD_ASSERTION_REG                0xD0
#define IN_HPD  BIT(0)
#define HPD_IRQ BIT(1)

#define PS8XXX_P1_REG_MUX_USB_DCI_CFG           0x4B

#if defined(CONFIG_USB_PD_TCPM_PS8751)
/* Vendor defined registers */
#define PS8XXX_REG_VENDOR_ID_L                  0x00
#define PS8XXX_REG_VENDOR_ID_H                  0x01
#define PS8XXX_REG_MUX_DP_EQ_CONFIGURATION      0xD3
#define PS8XXX_REG_MUX_DP_OUTPUT_CONFIGURATION  0xD4
#define PS8XXX_REG_MUX_USB_C2SS_EQ              0xE7
#define PS8XXX_REG_MUX_USB_C2SS_HS_THRESHOLD    0xE8
#define PS8751_REG_MUX_USB_DCI_CFG              0xED
#endif

/* Vendor defined registers */
#define PS8815_P1_REG_HW_REVISION		0xF0

#endif /* defined(__CROS_EC_USB_PD_TCPM_PS8XXX_H) */
