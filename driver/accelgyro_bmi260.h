/* Copyright 2020 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/* BMI260 accelerometer and gyro for Chrome EC */

#ifndef __CROS_EC_ACCELGYRO_BMI260_H
#define __CROS_EC_ACCELGYRO_BMI260_H

#include "accelgyro.h"
#include "common.h"
#include "mag_bmm150.h"
#include "driver/accelgyro_bmi260_public.h"

#define BMI260_CHIP_ID      0x00
#define BMI260_CHIP_ID_MAJOR    0x27

#define BMI260_ERR_REG          0x02

#define BMI260_STATUS           0x03
#define BMI260_AUX_BUSY             BIT(2)
#define BMI260_CMD_RDY              BIT(4)
#define BMI260_DRDY_AUX             BIT(5)
#define BMI260_DRDY_GYR             BIT(6)
#define BMI260_DRDY_ACC             BIT(7)
#define BMI260_DRDY_OFF(_sensor)    (7 - (_sensor))
#define BMI260_DRDY_MASK(_sensor)   (1 << BMI260_DRDY_OFF(_sensor))

#define BMI260_AUX_X_L_G           0x04
#define BMI260_AUX_X_H_G           0x05
#define BMI260_AUX_Y_L_G           0x06
#define BMI260_AUX_Y_H_G           0x07
#define BMI260_AUX_Z_L_G           0x08
#define BMI260_AUX_Z_H_G           0x09
#define BMI260_AUX_R_L_G           0x0a
#define BMI260_AUX_R_H_G           0x0b
#define BMI260_ACC_X_L_G           0x0c
#define BMI260_ACC_X_H_G           0x0d
#define BMI260_ACC_Y_L_G           0x0e
#define BMI260_ACC_Y_H_G           0x0f
#define BMI260_ACC_Z_L_G           0x10
#define BMI260_ACC_Z_H_G           0x11
#define BMI260_GYR_X_L_G           0x12
#define BMI260_GYR_X_H_G           0x13
#define BMI260_GYR_Y_L_G           0x14
#define BMI260_GYR_Y_H_G           0x15
#define BMI260_GYR_Z_L_G           0x16
#define BMI260_GYR_Z_H_G           0x17

#define BMI260_SENSORTIME_0     0x18
#define BMI260_SENSORTIME_1     0x19
#define BMI260_SENSORTIME_2     0x1a

#define BMI260_EVENT            0x1b

/* 2 bytes interrupt reasons*/
#define BMI260_INT_STATUS_0     0x1c
#define BMI260_SIG_MOTION_OUT       BIT(0)
#define BMI260_STEP_COUNTER_OUT     BIT(1)
#define BMI260_HIGH_LOW_G_OUT       BIT(2)
#define BMI260_TAP_OUT              BIT(3)
#define BMI260_FLAT_OUT             BIT(4)
#define BMI260_NO_MOTION_OUT        BIT(5)
#define BMI260_ANY_MOTION_OUT       BIT(6)
#define BMI260_ORIENTATION_OUT      BIT(7)

#define BMI260_INT_STATUS_1     0x1d
#define BMI260_FFULL_INT            BIT(0 + 8)
#define BMI260_FWM_INT              BIT(1 + 8)
#define BMI260_ERR_INT              BIT(2 + 8)
#define BMI260_AUX_DRDY_INT         BIT(5 + 8)
#define BMI260_GYR_DRDY_INT         BIT(6 + 8)
#define BMI260_ACC_DRDY_INT         BIT(7 + 8)

#define BMI260_INT_MASK             0xFFFF

#define BMI260_SC_OUT_0         0x1e
#define BMI260_SC_OUT_1         0x1f

#define BMI260_ORIENT_ACT       0x20

#define BMI260_INTERNAL_STATUS  0X21
#define BMI260_MESSAGE_MASK         0xf
#define BMI260_NOT_INIT             0x00
#define BMI260_INIT_OK              0x01
#define BMI260_INIT_ERR             0x02
#define BMI260_DRV_ERR              0x03
#define BMI260_SNS_STOP             0x04
#define BMI260_NVM_ERROR            0x05
#define BMI260_START_UP_ERROR       0x06
#define BMI260_COMPAT_ERROR         0x07

#define BMI260_TEMPERATURE_0    0x22
#define BMI260_TEMPERATURE_1    0x23

#define BMI260_FIFO_LENGTH_0    0x24
#define BMI260_FIFO_LENGTH_1    0x25
#define BMI260_FIFO_LENGTH_MASK     (BIT(14) - 1)
#define BMI260_FIFO_DATA        0x26

#define BMI260_FEAT_PAGE        0x2f
/*
 * The register of feature page should be read/write as 16-bit register
 * Otherwise, there can be invalid data
 */
/* Features page 0 */
#define BMI260_ORIENT_OUT       0x36
#define BMI260_ORIENT_OUT_PORTRAIT_LANDSCAPE_MASK   3
#define BMI260_ORIENT_PORTRAIT                      0x0
#define BMI260_ORIENT_LANDSCAPE                     0x1
#define BMI260_ORIENT_PORTRAIT_INVERT               0x2
#define BMI260_ORIENT_LANDSCAPE_INVERT              0x3

/* Features page 1 */
#define BMI260_GEN_SET_1        0x34
#define BMI260_GYR_SELF_OFF         BIT(9)

#define BMI260_TAP_1            0x3e
#define BMI260_TAP_1_EN                     BIT(0)
#define BMI260_TAP_1_SENSITIVITY_OFFSET     1
#define BMI260_TAP_1_SENSITIVITY_MASK       \
	(0x7 << BMI260_TAP_1_SENSITIVITY_OFFSET)

/* Features page 2 */
#define BMI260_ORIENT_1         0x30
#define BMI260_ORIENT_1_EN          BIT(0)
#define BMI260_ORIENT_1_UD_EN       BIT(1)
#define BMI260_ORIENT_1_MODE_OFFSET 2
#define BMI260_ORIENT_1_MODE_MASK   (0x3 << BMI260_ORIENT_1_MODE_OFFSET)
#define BMI260_ORIENT_1_BLOCK_OFFSET    4
#define BMI260_ORIENT_1_BLOCK_MASK      (0x3 << BMI260_ORIENT_1_BLOCK_OFFSET)
#define BMI260_ORIENT_1_THETA_OFFSET     6
#define BMI260_ORIENT_1_THETA_MASK      \
	((BIT(6) - 1) << BMI260_ORIENT_1_THETA_OFFSET)

#define BMI260_ORIENT_2         0x32
/* hysteresis(10...0) range is 0~1g, default is 128 (0.0625g) */
#define BMI260_ORIENT_2_HYSTERESIS_MASK     (BIT(11) - 1)

#define BMI260_ACC_CONF         0x40
#define BMI260_ACC_BW_OFFSET        4
#define BMI260_ACC_BW_MASK          (0x7 << BMI260_ACC_BW_OFFSET)
#define BMI260_FILTER_PERF          BIT(7)
#define BMI260_ULP                  0x0
#define BMI260_HP                   0x1

#define BMI260_ACC_RANGE        0x41
#define BMI260_GSEL_2G              0x00
#define BMI260_GSEL_4G              0x01
#define BMI260_GSEL_8G              0x02
#define BMI260_GSEL_16G             0x03

/* The max positvie value of accel data is 0x7FFF, equal to range(g) */
/* So, in order to get +1g, divide the 0x7FFF by range */
#define BMI260_ACC_DATA_PLUS_1G(range) (0x7FFF / (range))
#define BMI260_ACC_DATA_MINUS_1G(range) (-BMI260_ACC_DATA_PLUS_1G(range))

#define BMI260_GYR_CONF         0x42
#define BMI260_GYR_BW_OFFSET        4
#define BMI260_GYR_BW_MASK          (0x3 << BMI260_GYR_BW_OFFSET)
#define BMI260_GYR_NOISE_PERF       BIT(6)

#define BMI260_GYR_RANGE        0x43
#define BMI260_DPS_SEL_2000         0x00
#define BMI260_DPS_SEL_1000         0x01
#define BMI260_DPS_SEL_500          0x02
#define BMI260_DPS_SEL_250          0x03
#define BMI260_DPS_SEL_125          0x04

#define BMI260_AUX_CONF         0x44

#define BMI260_FIFO_DOWNS       0x45

#define BMI260_FIFO_WTM_0       0x46
#define BMI260_FIFO_WTM_1       0x47

#define BMI260_FIFO_CONFIG_0    0x48
#define BMI260_FIFO_STOP_ON_FULL    BIT(0)
#define BMI260_FIFO_TIME_EN     BIT(1)

#define BMI260_FIFO_CONFIG_1    0x49
#define BMI260_FIFO_TAG_INT1_EN_OFFSET  0
#define BMI260_FIFO_TAG_INT1_EN_MASK    (0x3 << BMI260_FIFO_TAG_INT1_EN_OFFSET)
#define BMI260_FIFO_TAG_INT2_EN_OFFSET  2
#define BMI260_FIFO_TAG_INT2_EN_MASK    (0x3 << BMI260_FIFO_TAG_INT2_EN_OFFSET)
#define BMI260_FIFO_TAG_INT_EDGE        0x0
#define BMI260_FIFO_TAG_INT_LEVEL       0x1
#define BMI260_FIFO_TAG_ACC_SAT         0x2
#define BMI260_FIFO_TAG_GYR_SAT         0x3
#define BMI260_FIFO_HEADER_EN           BIT(4)
#define BMI260_FIFO_AUX_EN              BIT(5)
#define BMI260_FIFO_ACC_EN              BIT(6)
#define BMI260_FIFO_GYR_EN              BIT(7)
#define BMI260_FIFO_SENSOR_EN(_sensor) \
	((_sensor) == MOTIONSENSE_TYPE_ACCEL ? BMI260_FIFO_ACC_EN : \
	  ((_sensor) == MOTIONSENSE_TYPE_GYRO ? BMI260_FIFO_GYR_EN : \
	   BMI260_FIFO_AUX_EN))

#define BMI260_AUX_DEV_ID       0x4b
#define BMI260_AUX_I2C_ADDRESS          BMI260_AUX_DEV_ID

#define BMI260_AUX_IF_CONF      0x4c
#define BMI260_AUX_I2C_CONTROL          BMI260_AUX_IF_CONF
#define BMI260_AUX_READ_BURST_MASK      3
#define BMI260_AUX_MAN_READ_BURST_OFF   2
#define BMI260_AUX_MAN_READ_BURST_MASK  (0x3 << BMI280_AUX_MAN_READ_BURST_OFF)
#define BMI260_AUX_READ_BURST_1         0
#define BMI260_AUX_READ_BURST_2         1
#define BMI260_AUX_READ_BURST_6         2
#define BMI260_AUX_READ_BURST_8         3
#define BMI260_AUX_FCU_WRITE_EN         BIT(6)
#define BMI260_AUX_MANUAL_EN            BIT(7)

#define BMI260_AUX_RD_ADDR      0x4d
#define BMI260_AUX_I2C_READ_ADDR    BMI260_AUX_RD_ADDR
#define BMI260_AUX_WR_ADDR      0x4e
#define BMI260_AUX_I2C_WRITE_ADDR   BMI260_AUX_WR_ADDR
#define BMI260_AUX_WR_DATA      0x4f
#define BMI260_AUX_I2C_WRITE_DATA   BMI260_AUX_WR_DATA
#define BMI260_AUX_I2C_READ_DATA    BMI260_AUX_X_L_G

#define BMI260_ERR_REG_MSK      0x52
#define BMI260_FATAL_ERR            BIT(0)
#define BMI260_INTERNAL_ERR_OFF     1
#define BMI260_INTERNAL_ERR_MASK    (0xf << BMI260_INTERNAL_ERR_OFF)
#define BMI260_FIFO_ERR             BIT(6)
#define BMI260_AUX_ERR              BIT(7)

#define BMI260_INT1_IO_CTRL     0x53
#define BMI260_INT1_LVL             BIT(1)
#define BMI260_INT1_OD              BIT(2)
#define BMI260_INT1_OUTPUT_EN       BIT(3)
#define BMI260_INT1_INPUT_EN        BIT(4)

#define BMI260_INT2_IO_CTRL     0x54
#define BMI260_INT2_LVL             BIT(1)
#define BMI260_INT2_OD              BIT(2)
#define BMI260_INT2_OUTPUT_EN       BIT(3)
#define BMI260_INT2_INPUT_EN        BIT(4)

#define BMI260_INT_LATCH        0x55
#define BMI260_INT_LATCH_EN         BIT(0)

#define BMI260_INT1_MAP_FEAT    0x56
#define BMI260_INT2_MAP_FEAT    0x57
#define BMI260_MAP_SIG_MOTION_OUT   BIT(0)
#define BMI260_MAP_STEP_COUNTER_OUT BIT(1)
#define BMI260_MAP_HIGH_LOW_G_OUT   BIT(2)
#define BMI260_MAP_TAP_OUT          BIT(3)
#define BMI260_MAP_FLAT_OUT         BIT(4)
#define BMI260_MAP_NO_MOTION_OUT    BIT(5)
#define BMI260_MAP_ANY_MOTION_OUT   BIT(6)
#define BMI260_MAP_ORIENTAION_OUT   BIT(7)

#define BMI260_INT_MAP_DATA     0x58
#define BMI260_MAP_FFULL_INT        BIT(0)
#define BMI260_MAP_FWM_INT          BIT(1)
#define BMI260_MAP_DRDY_INT         BIT(2)
#define BMI260_MAP_ERR_INT          BIT(3)
#define BMI260_INT_MAP_DATA_INT1_OFFSET     0
#define BMI260_INT_MAP_DATA_INT2_OFFSET     4
#define BMI260_INT_MAP_DATA_REG(_i, _bit) \
	(CONCAT3(BMI260_MAP_, _bit, _INT) << \
	CONCAT3(BMI260_INT_MAP_DATA_INT, _i, _OFFSET))

#define BMI260_INIT_CTRL        0x59
#define BMI260_INIT_ADDR_0      0x5b
#define BMI260_INIT_ADDR_1      0x5c
#define BMI260_INIT_DATA        0x5e
#define BMI260_INTERNAL_ERROR   0x5f
#define BMI260_INT_ERR_1            BIT(1)
#define BMI260_INT_ERR_2            BIT(2)
#define BMI260_FEAT_ENG_DISABLED    BIT(4)

#define BMI260_AUX_IF_TRIM      0x68
#define BMI260_GYR_CRT_CONF     0x69

#define BMI260_NVM_CONF         0x6a
#define BMI260_NVM_PROG_EN          BIT(1)

#define BMI260_IF_CONF          0x6b
#define BMI260_IF_SPI3              BIT(0)
#define BMI260_IF_SPI3_OIS          BIT(1)
#define BMI260_IF_OIS_EN            BIT(4)
#define BMI260_IF_AUX_EN            BIT(5)

#define BMI260_DRV              0x6c
#define BMI260_ACC_SELF_TEST    0x6d

#define BMI260_NV_CONF          0x70
#define BMI260_ACC_OFFSET_EN        BIT(3)

#define BMI260_OFFSET_ACC70     0x71
#define BMI260_OFFSET_GYR70     0x74
#define BMI260_OFFSET_EN_GYR98  0x77
#define BMI260_OFFSET_GYRO_EN       BIT(6)
#define BMI260_GYR_GAIN_EN          BIT(7)

#define BMI260_PWR_CONF         0x7c
#define BMI260_ADV_POWER_SAVE       BIT(0)
#define BMI260_FIFO_SELF_WAKE_UP    BIT(1)
#define BMI260_FUP_EN               BIT(2)

#define BMI260_PWR_CTRL         0x7d
#define BMI260_AUX_EN               BIT(0)
#define BMI260_GYR_EN               BIT(1)
#define BMI260_ACC_EN               BIT(2)
#define BMI260_PWR_EN(_sensor_type) BIT(2 - _sensor_type)
#define BMI260_TEMP_EN              BIT(3)

#define BMI260_CMD_REG          0x7e
#define BMI260_CMD_FIFO_FLUSH       0xb0
#define BMI260_CMD_SOFT_RESET       0xb6

#define BMI260_FF_FRAME_LEN_TS          4
#define BMI260_FF_DATA_LEN_ACC          6
#define BMI260_FF_DATA_LEN_GYR          6
#define BMI260_FF_DATA_LEN_MAG          8

/* Root mean square noise of 100Hz accelerometer, units: ug */
#define BMI260_ACCEL_RMS_NOISE_100HZ    1060

#endif /* __CROS_EC_ACCELGYRO_BMI260_H */
