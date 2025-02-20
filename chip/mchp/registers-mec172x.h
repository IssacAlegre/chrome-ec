/* Copyright 2021 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 * Register map for Microchip MEC172x family controllers
 */

#ifndef __CROS_EC_REGISTERS_H
#error "This header file should not be included directly."
#endif

/*
 * IRQ Numbers
 * NOTE: GIRQ22 aggregated output and its sources are not connected to
 * the NVIC.
 */
#define MCHP_IRQ_GIRQ8		0
#define MCHP_IRQ_GIRQ9		1
#define MCHP_IRQ_GIRQ10		2
#define MCHP_IRQ_GIRQ11		3
#define MCHP_IRQ_GIRQ12		4
#define MCHP_IRQ_GIRQ13		5
#define MCHP_IRQ_GIRQ14		6
#define MCHP_IRQ_GIRQ15		7
#define MCHP_IRQ_GIRQ16		8
#define MCHP_IRQ_GIRQ17		9
#define MCHP_IRQ_GIRQ18		10
#define MCHP_IRQ_GIRQ19		11
#define MCHP_IRQ_GIRQ20		12
#define MCHP_IRQ_GIRQ21		13
#define MCHP_IRQ_GIRQ23		14
#define MCHP_IRQ_GIRQ24		15
#define MCHP_IRQ_GIRQ25		16
#define MCHP_IRQ_GIRQ26		17
/* GIRQ13 direct sources */
#define MCHP_IRQ_I2C_0		20
#define MCHP_IRQ_I2C_1		21
#define MCHP_IRQ_I2C_2		22
#define MCHP_IRQ_I2C_3		23
#define MCHP_IRQ_I2C_4		158
/* GIRQ14 direct sources */
#define MCHP_IRQ_DMA_0		24
#define MCHP_IRQ_DMA_1		25
#define MCHP_IRQ_DMA_2		26
#define MCHP_IRQ_DMA_3		27
#define MCHP_IRQ_DMA_4		28
#define MCHP_IRQ_DMA_5		29
#define MCHP_IRQ_DMA_6		30
#define MCHP_IRQ_DMA_7		31
#define MCHP_IRQ_DMA_8		32
#define MCHP_IRQ_DMA_9		33
#define MCHP_IRQ_DMA_10		34
#define MCHP_IRQ_DMA_11		35
#define MCHP_IRQ_DMA_12		36
#define MCHP_IRQ_DMA_13		37
#define MCHP_IRQ_DMA_14		38
#define MCHP_IRQ_DMA_15		39
/* GIRQ15 direct sources */
#define MCHP_IRQ_UART0		40
#define MCHP_IRQ_UART1		41
#define MCHP_IRQ_EMI0		42
#define MCHP_IRQ_EMI1		43
#define MCHP_IRQ_EMI2		44
#define MCHP_IRQ_ACPIEC0_IBF	45
#define MCHP_IRQ_ACPIEC0_OBE	46
#define MCHP_IRQ_ACPIEC1_IBF	47
#define MCHP_IRQ_ACPIEC1_OBE	48
#define MCHP_IRQ_ACPIEC2_IBF	49
#define MCHP_IRQ_ACPIEC2_OBE	50
#define MCHP_IRQ_ACPIEC3_IBF	51
#define MCHP_IRQ_ACPIEC3_OBE	52
#define MCHP_IRQ_ACPIEC4_IBF	53
#define MCHP_IRQ_ACPIEC4_OBE	54
#define MCHP_IRQ_ACPIPM1_CTL	55
#define MCHP_IRQ_ACPIPM1_EN	56
#define MCHP_IRQ_ACPIPM1_STS	57
#define MCHP_IRQ_8042EM_OBE	58
#define MCHP_IRQ_8042EM_IBF	59
#define MCHP_IRQ_MAILBOX_DATA	60
#define MCHP_IRQ_BDP0		62
/* GIRQ16 direct sources */
#define MCHP_IRQ_PKE		65
#define MCHP_IRQ_NDRNG		67
#define MCHP_IRQ_AESH		68
/* GIRQ17 direct sources */
#define MCHP_IRQ_PECI_HOST	70
#define MCHP_IRQ_TACH_0		71
#define MCHP_IRQ_TACH_1		72
#define MCHP_IRQ_TACH_2		73
#define MCHP_IRQ_TACH_3		159
#define MCHP_IRQ_FAN0_FAIL	74
#define MCHP_IRQ_FAN0_STALL	75
#define MCHP_IRQ_FAN1_FAIL	76
#define MCHP_IRQ_FAN1_STALL	77
#define MCHP_IRQ_ADC_SNGL	78
#define MCHP_IRQ_ADC_RPT	79
#define MCHP_IRQ_RCID0		80
#define MCHP_IRQ_RCID1		81
#define MCHP_IRQ_RCID2		82
#define MCHP_IRQ_LED0_WDT	83
#define MCHP_IRQ_LED1_WDT	84
#define MCHP_IRQ_LED2_WDT	85
#define MCHP_IRQ_LED3_WDT	86
#define MCHP_IRQ_PHOT		87
/* GIRQ18 direct sources */
#define MCHP_IRQ_SLAVE_SPI	90
#define MCHP_IRQ_QMSPI0		91
#define MCHP_IRQ_SPI0_TX	92
#define MCHP_IRQ_SPI0_RX	93
#define MCHP_IRQ_SPI1_TX	94
#define MCHP_IRQ_SPI1_RX	95
#define MCHP_IRQ_BCM0_ERR	96
#define MCHP_IRQ_BCM0_BUSY	97
#define MCHP_IRQ_PS2_0		100
#define MCHP_IRQ_EEPROM		155
#define MCHP_IRQ_CCT_TMR	146
#define MCHP_IRQ_CCT_CAP0	147
#define MCHP_IRQ_CCT_CAP1	148
#define MCHP_IRQ_CCT_CAP2	149
#define MCHP_IRQ_CCT_CAP3	150
#define MCHP_IRQ_CCT_CAP4	151
#define MCHP_IRQ_CCT_CAP5	152
#define MCHP_IRQ_CCT_CMP0	153
#define MCHP_IRQ_CCT_CMP1	154
/* GIRQ19 direct sources */
#define MCHP_IRQ_ESPI_PC	103
#define MCHP_IRQ_ESPI_BM1	104
#define MCHP_IRQ_ESPI_BM2	105
#define MCHP_IRQ_ESPI_LTR	106
#define MCHP_IRQ_ESPI_OOB_UP	107
#define MCHP_IRQ_ESPI_OOB_DN	108
#define MCHP_IRQ_ESPI_FC	109
#define MCHP_IRQ_ESPI_RESET	110
#define MCHP_IRQ_ESPI_VW_EN	156
#define MCHP_IRQ_ESPI_SAF_DONE	166
#define MCHP_IRQ_ESPI_SAF_ERR	166
#define MCHP_IRQ_ESPI_SAF_CACHE	169
/* GIRQ20 direct sources */
#define MCHP_IRQ_OTP		173
#define MCHP_IRQ_CLK32K_MON	174
/* GIRQ21 direct sources */
#define MCHP_IRQ_WDG		171
#define MCHP_IRQ_WEEK_ALARM	114
#define MCHP_IRQ_SUBWEEK	115
#define MCHP_IRQ_WEEK_SEC	116
#define MCHP_IRQ_WEEK_SUBSEC	117
#define MCHP_IRQ_WEEK_SYSPWR	118
#define MCHP_IRQ_RTC		119
#define MCHP_IRQ_RTC_ALARM	120
#define MCHP_IRQ_VCI_OVRD_IN	121
#define MCHP_IRQ_VCI_IN0	122
#define MCHP_IRQ_VCI_IN1	123
#define MCHP_IRQ_VCI_IN2	124
#define MCHP_IRQ_VCI_IN3	125
#define MCHP_IRQ_VCI_IN4	126
#define MCHP_IRQ_PS20A_WAKE	129
#define MCHP_IRQ_PS20B_WAKE	130
#define MCHP_IRQ_KSC_INT	135
#define MCHP_IRQ_GLUE		172
/* GIRQ23 direct sources */
#define MCHP_IRQ_TIMER16_0	136
#define MCHP_IRQ_TIMER16_1	137
#define MCHP_IRQ_TIMER16_2	138
#define MCHP_IRQ_TIMER16_3	139
#define MCHP_IRQ_TIMER32_0	140
#define MCHP_IRQ_TIMER32_1	141
#define MCHP_IRQ_CNTR_TM0	142
#define MCHP_IRQ_CNTR_TM1	143
#define MCHP_IRQ_CNTR_TM2	144
#define MCHP_IRQ_CNTR_TM3	145
#define MCHP_IRQ_RTOS_TIMER	111
#define MCHP_IRQ_HTIMER0	112
#define MCHP_IRQ_HTIMER1	113
/* Must match CONFIG_IRQ_COUNT in config_chip.h */
#define MCHP_IRQ_MAX 180

/* Block base addresses */
#define MCHP_WDG_BASE		0x40000400
#define MCHP_TMR16_0_BASE	0x40000c00
#define MCHP_TMR32_0_BASE	0x40000c80
#define MCHP_CNT16_0_BASE	0x40000d00
#define MCHP_DMA_BASE		0x40002400
#define MCHP_PROCHOT_BASE	0x40003400
#define MCHP_I2C0_BASE		0x40004000
#define MCHP_I2C1_BASE		0x40004400
#define MCHP_I2C2_BASE		0x40004800
#define MCHP_I2C3_BASE		0x40004C00
#define MCHP_I2C4_BASE		0x40005000
#define MCHP_CACHE_CTRL_BASE	0x40005400
#define MCHP_PWM_0_BASE		0x40005800
#define MCHP_TACH_0_BASE	0x40006000
#define MCHP_PECI_BASE		0x40006400
#define MCHP_SPIEP_BASE		0x40007000
#define MCHP_RTMR_BASE		0x40007400
#define MCHP_ADC_BASE		0x40007c00
#define MCHP_ESPI_SAF_BASE	0x40008000
#define MCHP_TFDP_BASE		0x40008c00
#define MCHP_GPSPI0_BASE	0x40009400
#define MCHP_GPSPI1_BASE	0x40009480
#define MCHP_HTIMER_BASE	0x40009800
#define MCHP_KEYSCAN_BASE	0x40009c00
#define MCHP_RPM2PWM0_BASE	0x4000a000
#define MCHP_RPM2PWM1_BASE	0x4000a080
#define MCHP_VBAT_BASE		0x4000a400
#define MCHP_VBAT_RAM_BASE	0x4000a800
#define MCHP_WKTIMER_BASE	0x4000ac80
#define MCHP_VCI_BASE		0x4000ae00
#define MCHP_BBLED_0_BASE	0x4000B800
#define MCHP_BCL_0_BASE		0x4000cd00
#define MCHP_INT_BASE		0x4000e000
#define MCHP_EC_BASE		0x4000fc00

#define MCHP_QMSPI0_BASE	0x40070000
#define MCHP_ESPI_SAF_COMM_BASE 0x40071000

#define MCHP_PCR_BASE		0x40080100
#define MCHP_GPIO_BASE		0x40081000
#define MCHP_OTP_BASE		0x40082000

#define MCHP_MBOX_BASE		0x400f0000
#define MCHP_8042_BASE		0x400f0400
#define MCHP_ACPI_EC_0_BASE	0x400f0800
#define MCHP_ACPI_PM1_BASE	0x400f1c00
#define MCHP_PORT92_BASE	0x400f2000
#define MCHP_UART0_BASE		0x400f2400
#define MCHP_UART1_BASE		0x400f2800
#define MCHP_LPC_BASE		0x400f3000
#define MCHP_ESPI_IO_BASE	0x400f3400
#define MCHP_ESPI_MEM_BASE	0x400f3800
#define MCHP_GLUE_BASE		0x400f3c00
#define MCHP_EMI_0_BASE		0x400f4000
#define MCHP_EMI_1_BASE		0x400f4400
#define MCHP_EMI_2_BASE		0x400f4800
#define MCHP_RTC_BASE		0x400f5000
#define MCHP_BDP0_BASE		0x400f8000
#define MCHP_ESPI_VW_BASE	0x400f9c00
#define MCHP_CHIP_BASE		0x400fff00

#ifndef __ASSEMBLER__

/*
 * Helper function for RAM address aliasing
 * NOTE: MEC17xx and MEC15xx AHB controllers do NOT require aliasing.
 * Cortex-M4 bit-banding does require aliasing of the
 * DATA SRAM region.
 */
#define MCHP_RAM_ALIAS(x) \
	((x) >= 0x118000 ? (x) - 0x118000 + 0x20000000 : (x))

/* EC Chip Configuration */
/* 16-bit Device ID */
#define MCHP_CHIP_DEV_ID		REG16(MCHP_CHIP_BASE + 0x1E)
/* 8-bit Device Sub ID */
#define MCHP_CHIP_DEV_SUB_ID		REG8(MCHP_CHIP_BASE + 0x1D)
/* 8-bit Device Revision */
#define MCHP_CHIP_DEV_REV		REG8(MCHP_CHIP_BASE + 0x1C)
/* All in one */
#define MCHP_CHIP_DEVRID32		REG32(MCHP_CHIP_BASE + 0x1C)
#define MCHP_CHIP_DEVID_POS		16
#define MCHP_CHIP_DEVID_MASK		(0xfffful << MCHP_CHIP_DEVID_POS)
#define MCHP_CHIP_SUBID_POS		8
#define MCHP_CHIP_SUBID_MASK		(0xfful << MCHP_CHIP_SUBID_POS)
#define MCHP_CHIP_REV_POS		0
#define MCHP_CHIP_REV_MASK		(0xfful << MCHP_CHIP_REV_POS)
#define MCHP_CHIP_EXTRACT_DEVID(d) \
	(((uint32_t)(d) & MCHP_CHIP_DEVID_MASK) >> MCHP_CHIP_DEVID_POS)
#define MCHP_CHIP_EXTRACT_SUBID(d) \
	(((uint32_t)(d) & MCHP_CHIP_SUBID_MASK) >> MCHP_CHIP_SUBID_POS)
#define MCHP_CHIP_EXTRACT_REV(d) \
	(((uint32_t)(d) & MCHP_CHIP_REV_MASK) >> MCHP_CHIP_REV_POS)

/* PCR clock control dividers */
#define MCHP_PCR_CLK_CTL_FASTEST	1U
#define MCHP_PCR_CLK_CTL_96MHZ		1U
#define MCHP_PCR_CLK_CTL_48MHZ		2U
#define MCHP_PCR_CLK_CTL_24MHZ		4U
#define MCHP_PCR_CLK_CTL_12MHZ		8U

/* Number of PCR Sleep Enable, Clock Required, and Reset registers */
#define MCHP_PCR_SLP_RST_REG_MAX 5

/* Sleep 0: Sleep Enable, Clock Required, and Reset bits */
#define MCHP_PCR_JTAG		BIT(0) /* CLKREQ only */
#define MCHP_PCR_OTP		BIT(1)
#define MCHP_PCR_ISPI		BIT(2)

/* Command all blocks to sleep */
#define MCHP_PCR_SLP_EN0_JTAG	BIT(0)
#define MCHP_PCR_SLP_EN0_OTP	BIT(1)
#define MCHP_PCR_SLP_EN0_ISPI	BIT(2)
#define MCHP_PCR_SLP_EN0_SLEEP	0xffffffff

/*
 * Encode register number and bit position
 * b[4:0] = bit number
 * b[10:8] = zero based register number
 */
#define MCHP_PCR_ERB(rnum, bnum) \
	((((rnum) & 0x0f) << 8) | ((bnum) & 0x1f))

/* PCR Sleep 1: Sleep Enable, Clock Required, and Reset bits */
#define MCHP_PCR_BTMR16_1	MCHP_PCR_ERB(1, 31)
#define MCHP_PCR_BTMR16_0	MCHP_PCR_ERB(1, 30)
#define MCHP_PCR_ECS		MCHP_PCR_ERB(1, 29)
#define MCHP_PCR_PWM8		MCHP_PCR_ERB(1, 27)
#define MCHP_PCR_PWM7		MCHP_PCR_ERB(1, 26)
#define MCHP_PCR_PWM6		MCHP_PCR_ERB(1, 25)
#define MCHP_PCR_PWM5		MCHP_PCR_ERB(1, 24)
#define MCHP_PCR_PWM4		MCHP_PCR_ERB(1, 23)
#define MCHP_PCR_PWM3		MCHP_PCR_ERB(1, 22)
#define MCHP_PCR_PWM2		MCHP_PCR_ERB(1, 21)
#define MCHP_PCR_PWM1		MCHP_PCR_ERB(1, 20)
#define MCHP_PCR_TACH3		MCHP_PCR_ERB(1, 13)
#define MCHP_PCR_TACH2		MCHP_PCR_ERB(1, 12)
#define MCHP_PCR_TACH1		MCHP_PCR_ERB(1, 11)
#define MCHP_PCR_I2C0		MCHP_PCR_ERB(1, 10)
#define MCHP_PCR_WDT		MCHP_PCR_ERB(1, 9)
#define MCHP_PCR_CPU		MCHP_PCR_ERB(1, 8)
#define MCHP_PCR_TFDP		MCHP_PCR_ERB(1, 7)
#define MCHP_PCR_DMA		MCHP_PCR_ERB(1, 6)
#define MCHP_PCR_PMC		MCHP_PCR_ERB(1, 5)
#define MCHP_PCR_PWM0		MCHP_PCR_ERB(1, 4)
#define MCHP_PCR_TACH0		MCHP_PCR_ERB(1, 2)
#define MCHP_PCR_PECI		MCHP_PCR_ERB(1, 1)
#define MCHP_PCR_ECIA		MCHP_PCR_ERB(1, 0)

/* Command all blocks to sleep */
#define MCHP_PCR_SLP_EN1_BTMR16_1	BIT(31)
#define MCHP_PCR_SLP_EN1_BTMR16_0	BIT(30)
#define MCHP_PCR_SLP_EN1_ECS		BIT(29)
#define MCHP_PCR_SLP_EN1_PWM_ALL	(BIT(4) | BIT(20) | BIT(21) |\
	BIT(22) | BIT(23) | BIT(24) | BIT(25) | BIT(26) | BIT(27))
#define MCHP_PCR_SLP_EN1_PWM8		BIT(27)
#define MCHP_PCR_SLP_EN1_PWM7		BIT(26)
#define MCHP_PCR_SLP_EN1_PWM6		BIT(25)
#define MCHP_PCR_SLP_EN1_PWM5		BIT(24)
#define MCHP_PCR_SLP_EN1_PWM4		BIT(23)
#define MCHP_PCR_SLP_EN1_PWM3		BIT(22)
#define MCHP_PCR_SLP_EN1_PWM2		BIT(21)
#define MCHP_PCR_SLP_EN1_PWM1		BIT(20)
#define MCHP_PCR_SLP_EN1_TACH3		BIT(13)
#define MCHP_PCR_SLP_EN1_TACH2		BIT(12)
#define MCHP_PCR_SLP_EN1_TACH1		BIT(11)
#define MCHP_PCR_SLP_EN1_I2C0		BIT(10)
#define MCHP_PCR_SLP_EN1_WDT		BIT(9)
#define MCHP_PCR_SLP_EN1_CPU		BIT(8)
#define MCHP_PCR_SLP_EN1_TFDP		BIT(7)
#define MCHP_PCR_SLP_EN1_DMA		BIT(6)
#define MCHP_PCR_SLP_EN1_PMC		BIT(5)
#define MCHP_PCR_SLP_EN1_PWM0		BIT(4)
#define MCHP_PCR_SLP_EN1_TACH0		BIT(2)
#define MCHP_PCR_SLP_EN1_PECI		BIT(1)
#define MCHP_PCR_SLP_EN1_ECIA		BIT(0)
/* all sleep enable 1 bits */
#define MCHP_PCR_SLP_EN1_SLEEP		0xffffffff
/*
 * block not used by default
 * Do not sleep ECIA, PMC, CPU and ECS
 */
#define MCHP_PCR_SLP_EN1_UNUSED_BLOCKS	0xdffffede

/* PCR Sleep 2: Sleep Enable, Clock Required 2, Reset bits */
#define MCHP_PCR_GLUE		MCHP_PCR_ERB(2, 29)
#define MCHP_PCR_SAF		MCHP_PCR_ERB(2, 27)
#define MCHP_PCR_BDP0		MCHP_PCR_ERB(2, 25)
#define MCHP_PCR_ACPI_EC4	MCHP_PCR_ERB(2, 23)
#define MCHP_PCR_ACPI_EC3	MCHP_PCR_ERB(2, 22)
#define MCHP_PCR_ACPI_EC2	MCHP_PCR_ERB(2, 21)
#define MCHP_PCR_ESPI_SCR	MCHP_PCR_ERB(2, 20)
#define MCHP_PCR_ESPI		MCHP_PCR_ERB(2, 19)
#define MCHP_PCR_RTC		MCHP_PCR_ERB(2, 18)
#define MCHP_PCR_MBOX		MCHP_PCR_ERB(2, 17)
#define MCHP_PCR_8042		MCHP_PCR_ERB(2, 16)
#define MCHP_PCR_ACPI_PM1	MCHP_PCR_ERB(2, 15)
#define MCHP_PCR_ACPI_EC1	MCHP_PCR_ERB(2, 14)
#define MCHP_PCR_ACPI_EC0	MCHP_PCR_ERB(2, 13)
#define MCHP_PCR_GCFG		MCHP_PCR_ERB(2, 12)
#define MCHP_PCR_UART1		MCHP_PCR_ERB(2, 2)
#define MCHP_PCR_UART0		MCHP_PCR_ERB(2, 1)
#define MCHP_PCR_EMI0		MCHP_PCR_ERB(2, 0)

/* Command all blocks to sleep */
#define MCHP_PCR_SLP_EN2_GLUE		BIT(29)
#define MCHP_PCR_SLP_EN2_SAF		BIT(27)
#define MCHP_PCR_SLP_EN2_BDP0		BIT(25)
#define MCHP_PCR_SLP_EN2_ACPI_EC4	BIT(23)
#define MCHP_PCR_SLP_EN2_ACPI_EC3	BIT(22)
#define MCHP_PCR_SLP_EN2_ACPI_EC2	BIT(21)
#define MCHP_PCR_SLP_EN2_ESPI_SCR	BIT(20)
#define MCHP_PCR_SLP_EN2_ESPI		BIT(19)
#define MCHP_PCR_SLP_EN2_RTC		BIT(18)
#define MCHP_PCR_SLP_EN2_MAILBOX	BIT(17)
#define MCHP_PCR_SLP_EN2_MIF8042	BIT(16)
#define MCHP_PCR_SLP_EN2_ACPI_PM1	BIT(15)
#define MCHP_PCR_SLP_EN2_ACPI_EC1	BIT(14)
#define MCHP_PCR_SLP_EN2_ACPI_EC0	BIT(13)
#define MCHP_PCR_SLP_EN2_GCFG		BIT(12)
#define MCHP_PCR_SLP_EN2_UART1		BIT(2)
#define MCHP_PCR_SLP_EN2_UART0		BIT(1)
#define MCHP_PCR_SLP_EN2_EMI0		BIT(0)
/* all sleep enable 2 bits */
#define MCHP_PCR_SLP_EN2_SLEEP		0xffffffff

/* PCR Sleep 3: Sleep Enable, Clock Required, and Reset */
#define MCHP_PCR_PWM9		MCHP_PCR_ERB(3, 31)
#define MCHP_PCR_CCT0		MCHP_PCR_ERB(3, 30)
#define MCHP_PCR_HTMR1		MCHP_PCR_ERB(3, 29)
#define MCHP_PCR_CRYPTO		MCHP_PCR_ERB(3, 26)
#define MCHP_PCR_LED3		MCHP_PCR_ERB(3, 25)
#define MCHP_PCR_BTMR32_1	MCHP_PCR_ERB(3, 24)
#define MCHP_PCR_BTMR32_0	MCHP_PCR_ERB(3, 23)
#define MCHP_PCR_BTMR16_3	MCHP_PCR_ERB(3, 22)
#define MCHP_PCR_BTMR16_2	MCHP_PCR_ERB(3, 21)
#define MCHP_PCR_I2C4		MCHP_PCR_ERB(3, 20)
#define MCHP_PCR_BCM0		MCHP_PCR_ERB(3, 19)
#define MCHP_PCR_LED2		MCHP_PCR_ERB(3, 18)
#define MCHP_PCR_LED1		MCHP_PCR_ERB(3, 17)
#define MCHP_PCR_LED0		MCHP_PCR_ERB(3, 16)
#define MCHP_PCR_I2C3		MCHP_PCR_ERB(3, 15)
#define MCHP_PCR_I2C2		MCHP_PCR_ERB(3, 14)
#define MCHP_PCR_I2C1		MCHP_PCR_ERB(3, 13)
#define MCHP_PCR_RPMPWM0	MCHP_PCR_ERB(3, 12)
#define MCHP_PCR_KEYSCAN	MCHP_PCR_ERB(3, 11)
#define MCHP_PCR_HTMR0		MCHP_PCR_ERB(3, 10)
#define MCHP_PCR_GPSPI0		MCHP_PCR_ERB(3, 9)
#define MCHP_PCR_PS2_0		MCHP_PCR_ERB(3, 5)
#define MCHP_PCR_ADC		MCHP_PCR_ERB(3, 3)

/* Command blocks to sleep */
#define MCHP_PCR_SLP_EN3_PWM9		BIT(31)
#define MCHP_PCR_SLP_EN3_CCT0		BIT(30)
#define MCHP_PCR_SLP_EN3_HTMR1		BIT(29)
#define MCHP_PCR_SLP_EN3_CRYPTO		BIT(26)
#define MCHP_PCR_SLP_EN3_LED3		BIT(25)
#define MCHP_PCR_SLP_EN3_BTMR32_1	BIT(24)
#define MCHP_PCR_SLP_EN3_BTMR32_0	BIT(23)
#define MCHP_PCR_SLP_EN3_BTMR16_3	BIT(22)
#define MCHP_PCR_SLP_EN3_BTMR16_2	BIT(21)
#define MCHP_PCR_SLP_EN3_I2C4		BIT(20)
#define MCHP_PCR_SLP_EN3_BCM0		BIT(19)
#define MCHP_PCR_SLP_EN3_LED2		BIT(18)
#define MCHP_PCR_SLP_EN3_LED1		BIT(17)
#define MCHP_PCR_SLP_EN3_LED0		BIT(16)
#define MCHP_PCR_SLP_EN3_I2C3		BIT(15)
#define MCHP_PCR_SLP_EN3_I2C2		BIT(14)
#define MCHP_PCR_SLP_EN3_I2C1		BIT(13)
#define MCHP_PCR_SLP_EN3_RPM2PWM0	BIT(12)
#define MCHP_PCR_SLP_EN3_KEYSCAN	BIT(11)
#define MCHP_PCR_SLP_EN3_HTMR0		BIT(10)
#define MCHP_PCR_SLP_EN3_GPSPI0		BIT(9)
#define MCHP_PCR_SLP_EN3_PS2_0		BIT(5)
#define MCHP_PCR_SLP_EN3_ADC		BIT(3)
#define MCHP_PCR_SLP_EN3_ALL_CRYPTO	BIT(26)
/* all sleep enable 3 bits */
#define MCHP_PCR_SLP_EN3_SLEEP		0xffffffff
#define MCHP_PCR_SLP_EN3_PWM_ALL	(MCHP_PCR_SLP_EN3_PWM9)

/* PCR Sleep 4: Sleep Enable, Clock Required, Reset */
#define MCHP_PCR_GPSPI1		MCHP_PCR_ERB(4, 22)
#define MCHP_PCR_PSPI		MCHP_PCR_ERB(4, 14)
#define MCHP_PCR_PROCHOT	MCHP_PCR_ERB(4, 13)
#define MCHP_PCR_RCID2		MCHP_PCR_ERB(4, 12)
#define MCHP_PCR_RCID1		MCHP_PCR_ERB(4, 11)
#define MCHP_PCR_RCID0		MCHP_PCR_ERB(4, 10)
#define MCHP_PCR_QMSPI		MCHP_PCR_ERB(4, 8)
#define MCHP_PCR_RPMPWM1	MCHP_PCR_ERB(4, 7)
#define MCHP_PCR_RTMR		MCHP_PCR_ERB(4, 6)
#define MCHP_PCR_CNT16_3	MCHP_PCR_ERB(4, 5)
#define MCHP_PCR_CNT16_2	MCHP_PCR_ERB(4, 4)
#define MCHP_PCR_CNT16_1	MCHP_PCR_ERB(4, 3)
#define MCHP_PCR_CNT16_0	MCHP_PCR_ERB(4, 2)
#define MCHP_PCR_PWM11		MCHP_PCR_ERB(4, 1)
#define MCHP_PCR_PWM10		MCHP_PCR_ERB(4, 0)

/* Command blocks to sleep */
#define MCHP_PCR_SLP_EN4_GPSPI1		BIT(22)
#define MCHP_PCR_SLP_EN4_PSPI		BIT(14)
#define MCHP_PCR_SLP_EN4_PROCHOT	BIT(13)
#define MCHP_PCR_SLP_EN4_RCID2		BIT(12)
#define MCHP_PCR_SLP_EN4_RCID1		BIT(11)
#define MCHP_PCR_SLP_EN4_RCID0		BIT(10)
#define MCHP_PCR_SLP_EN4_QMSPI		BIT(8)
#define MCHP_PCR_SLP_EN4_RPMPWM1	BIT(7)
#define MCHP_PCR_SLP_EN4_RTMR		BIT(6)
#define MCHP_PCR_SLP_EN4_CNT16_3	BIT(5)
#define MCHP_PCR_SLP_EN4_CNT16_2	BIT(4)
#define MCHP_PCR_SLP_EN4_CNT16_1	BIT(3)
#define MCHP_PCR_SLP_EN4_CNT16_0	BIT(2)
#define MCHP_PCR_SLP_EN4_PWM11		BIT(1)
#define MCHP_PCR_SLP_EN4_PWM10		BIT(0)

/* all sleep enable 4 bits */
#define MCHP_PCR_SLP_EN4_SLEEP		0xffffffff
#define MCHP_PCR_SLP_EN4_PWM_ALL \
	(MCHP_PCR_SLP_EN4_PWM10 | MCHP_PCR_SLP_EN4_PWM11)

/* Allow all blocks to request clocks */
#define MCHP_PCR_SLP_EN0_WAKE (~(MCHP_PCR_SLP_EN0_SLEEP))
#define MCHP_PCR_SLP_EN1_WAKE (~(MCHP_PCR_SLP_EN1_SLEEP))
#define MCHP_PCR_SLP_EN2_WAKE (~(MCHP_PCR_SLP_EN2_SLEEP))
#define MCHP_PCR_SLP_EN3_WAKE (~(MCHP_PCR_SLP_EN3_SLEEP))
#define MCHP_PCR_SLP_EN4_WAKE (~(MCHP_PCR_SLP_EN4_SLEEP))

/* Bit defines for MCHP_PCR_PWR_RST_STS */
#define MCHP_PWR_RST_STS_MASK_RO	0xc8c
#define MCHP_PWR_RST_STS_MASK_RWC	0x170
#define MCHP_PWR_RST_STS_MASK \
	((MCHP_PWR_RST_STS_MASK_RO) | (MCHP_PWR_RST_STS_MASK_RWC))

#define MCHP_PWR_RST_STS_ESPI_CLK_ACT	BIT(11) /* RO */
#define MCHP_PWR_RST_STS_32K_ACT	BIT(10) /* RO */
#define MCHP_PWR_RST_STS_WDT		BIT(8) /* R/WC */
#define MCHP_PWR_RST_STS_JTAG_RSTN	BIT(7) /* RO */
#define MCHP_PWR_RST_STS_SYS		BIT(6) /* R/WC */
#define MCHP_PWR_RST_STS_VBAT		BIT(5) /* R/WC */
#define MCHP_PWR_RST_STS_VTR		BIT(4) /* R/WC */
#define MCHP_PWR_RST_STS_HOST		BIT(3) /* RO */
#define MCHP_PWR_RST_STS_VCC_PWRGD	BIT(2) /* RO */

/* Bit defines for MCHP_PCR_PWR_RST_CTL */
#define MCHP_PCR_PWR_HOST_RST_SEL_BITPOS	8
#define MCHP_PCR_PWR_HOST_RST_PCI_RESET		BIT(8)
#define MCHP_PCR_PWR_HOST_RST_ESPI_PLTRST	0
#define MCHP_PCR_PWR_OK_INV_BITPOS		0

/* Bit defines for MCHP_PCR_SYS_RST */
#define MCHP_PCR_SYS_SOFT_RESET			BIT(8)

/*
 * PCR Peripheral Reset Lock register
 * MEC152x PCR Peripheral reset registers do not reset on
 * peripheral sleep. The peripheral is reset immediately.
 * Firmware must write an unlock value to this new lock
 * register, write to PCR reset enable register(s), and
 * write a lock value.
 */
#define MCHP_PCR_RST_LOCK	REG32(MCHP_PCR_BASE + 0x84)
#define MCHP_PCR_RST_LOCK_VAL	0xa6382d4d
#define MCHP_PCR_RST_UNLOCK_VAL	0xa6382d4c

/* PCR VBAT soft reset. Trigger a VBAT reset */
#define MCHP_PCR_VBAT_SRST	REG32(MCHP_PCR_BASE + 0x88)
#define MCHP_PCR_VBAT_SRST_EN	BIT(0)

/* PCR 32KHz clock source select */
#define MCHP_PCR_CK32_SS	REG32(MCHP_PCR_BASE + 0x8c)
#define MCHP_PCR_CK32_SEL_MASK	GENMASK(1, 0)
#define MCHP_PCR_CK32_SEL_SIL	0
#define MCHP_PCR_CK32_SEL_XTAL	1
#define MCHP_PCR_CK32_SEL_PIN	2
#define MCHP_PCR_CK32_SEL_OFF	3

/* PCR 32KHz period count (RO) */
#define MCHP_PCR_CK32_PER_CNT		REG32(MCHP_PCR_BASE + 0xc0)
#define MCHP_PCR_CD32_PER_CNT_MSK	GENMASK(15, 0)

/* PCR 32KHz high pulse count (RO) */
#define MCHP_PCR_CK32_HP_CNT		REG32(MCHP_PCR_BASE + 0xc4)
#define MCHP_PCR_CK32_HP_CNT_MSK	GENMASK(15, 0)

/* PCR 32KHz minimum acceptable period count */
#define MCHP_PCR_CK32_MIN_PER_CNT	REG32(MCHP_PCR_BASE + 0xc8)
#define MCHP_PCR_CK32_MIN_PER_CNT_MSK	GENMASK(15, 0)

/* PCR 32KHz maximum acceptable period count */
#define MCHP_PCR_CK32_MAX_PER_CNT	REG32(MCHP_PCR_BASE + 0xcc)
#define MCHP_PCR_CK32_MAX_PER_CNT_MSK	GENMASK(15, 0)

/* PCR 32KHz duty cycle variation count (RO) */
#define MCHP_PCR_CK32_DC_VAR_CNT	REG32(MCHP_PCR_BASE + 0xd0)
#define MCHP_PCR_CK32_DC_VAR_CNT_MSK	GENMASK(15, 0)

/* PCR 32KHz duty cycle variation acceptable maximum */
#define MCHP_PCR_CK32_DC_VAR_MAX	REG32(MCHP_PCR_BASE + 0xd4)
#define MCHP_PCR_CK32_DC_VAR_MAX_MSK	GENMASK(15, 0)

/* PCR 32KHz valid count */
#define MCHP_PCR_CK32_VAL_CNT		REG32(MCHP_PCR_BASE + 0xd8)
#define MCHP_PCR_CK32_VAL_CNT_MSK	GENMASK(7, 0)

/* PCR 32KHz valid count minimum */
#define MCHP_PCR_CK32_MIN_VAL_CNT	REG32(MCHP_PCR_BASE + 0xdc)
#define MCHP_PCR_CK32_MIN_VAL_CNT_MSK	GENMASK(7, 0)

/* PCR 32KHz control */
#define MCHP_PCR_CK32_CTRL		REG32(MCHP_PCR_BASE + 0xe0)
#define MCHP_PCR_CK32_CTRL_MSK		(GENMASK(2, 0) | BIT(4) | BIT(24))
#define MCHP_PCR_CK32_CTRL_PER_EN	BIT(0)
#define MCHP_PCR_CK32_CTRL_DC_EN	BIT(1)
#define MCHP_PCR_CK32_CTRL_VAL_EN	BIT(2)
#define MCHP_PCR_CK32_CTRL_SRC_SIL	BIT(3)
#define MCHP_PCR_CK32_CTRL_CLR_CNT	BIT(24)

/* PCR 32KHz interrupt status */
#define MCHP_PCR_CK32_INTR_STS		REG8(MCHP_PCR_BASE + 0xe4)
/* PCR 32KHz interrupt enable */
#define MCHP_PCR_CK32_INTR_EN		REG8(MCHP_PCR_BASE + 0xe8)
#define MCHP_PCR_CK32_INTR_PULSE_RDY	BIT(0)
#define MCHP_PCR_CK32_INTR_PASS_PER	BIT(1)
#define MCHP_PCR_CK32_INTR_PASS_DUTY	BIT(2)
#define MCHP_PCR_CK32_INTR_FAIL		BIT(3)
#define MCHP_PCR_CK32_INTR_STALL	BIT(4)
#define MCHP_PCR_CK32_INTR_VALID	BIT(5)
#define MCHP_PCR_CK32_INTR_UNWELL	BIT(6)

/* EC Subsystem */
#define MCHP_EC_AHB_ERR		REG32(MCHP_EC_BASE + 0x04)
#define MCHP_EC_ID_RO		REG32(MCHP_EC_BASE + 0x10)
#define MCHP_EC_AHB_ERR_EN	REG32(MCHP_EC_BASE + 0x14)
#define MCHP_EC_INT_CTRL	REG32(MCHP_EC_BASE + 0x18)
#define MCHP_EC_TRACE_EN	REG32(MCHP_EC_BASE + 0x1c)
#define MCHP_EC_JTAG_EN		REG32(MCHP_EC_BASE + 0x20)
#define MCHP_EC_WDT_CNT		REG32(MCHP_EC_BASE + 0x28)
#define MCHP_EC_PECI_DISABLE	REG8(MCHP_EC_BASE + 0x40)
#define MCHP_EC_VCI_FW_OVRD	REG32(MCHP_EC_BASE + 0x50)
#define MCHP_EC_BROM_STS	REG32(MCHP_EC_BASE + 0x54)
#define MCHP_EC_VW_SRC_CFG	REG32(MCHP_EC_BASE + 0x90)
#define MCHP_EC_CMP_CTRL	REG32(MCHP_EC_BASE + 0x94)
#define MCHP_EC_CMP_SLP_CTRL	REG32(MCHP_EC_BASE + 0x98)

/* AHB ERR Disable bit[0]=0(enable), 1(disable) */
#define MCHP_EC_AHB_ERROR_ENABLE	0
#define MCHP_EC_AHB_ERROR_DISABLE	1

/* MCHP_EC_JTAG_EN bit definitions */
#define MCHP_JTAG_ENABLE		0x01
/* bits [2:1] */
#define MCHP_JTAG_MODE_4PIN		0x00
/* ARM 2-pin SWD plus 1-pin Serial Wire Viewer (ITM) */
#define MCHP_JTAG_MODE_SWD_SWV		0x02
/* ARM 2-pin SWD with no SWV */
#define MCHP_JTAG_MODE_SWD		0x04

/* EC Interrupt aggregator (ECIA) */
#define MCHP_INT_GIRQ_LEN	20 /* 5 32-bit registers */
#define MCHP_INT_GIRQ_FIRST	8
#define MCHP_INT_GIRQ_LAST	26
#define MCHP_INT_GIRQ_NUM	(26-8+1)
/* MCHP_INT_GIRQ_FIRST <= x <= MCHP_INT_GIRQ_LAST */
#define MCHP_INTx_BASE(x) (MCHP_INT_BASE + (((x) - 8) * MCHP_INT_GIRQ_LEN))

/*
 * GPIO GIRQ's are not direct capable
 * GIRQ08 GPIO 0140 - 0176
 * GIRQ09 GPIO 0100 - 0136
 * GIRQ10 GPIO 040 - 076
 * GIRQ11 GPIO 000 - 036
 * GIRQ12 GPIO 0200 - 0236
 * GIRQ26 GPIO 0240 - 0276
 * Other GIRQ's not direct capable:
 * GIRQ22 wake peripheral clock only
 * GIRQ24, GIRQ25 eSPI host to endpoint virtual wires
 */
#define MCHP_INT_AGGR_ONLY_BITMAP (BIT(8) | BIT(9) | BIT(10) | BIT(11) |\
		BIT(12) | BIT(22) | BIT(24) | BIT(25) | BIT(26))

#define MCHP_INT_DIRECT_CAPABLE_BITMAP (BIT(13) | BIT(14) | BIT(15) |\
	BIT(16) | BIT(17) | BIT(18) | BIT(19) | BIT(20) | BIT(21) | BIT(23))

/* GIRQ13 I2C controllers 0 - 4. Direct capable */
#define MCHP_INT13_I2C(x) BIT(x)

/* GIRQ14 DMA channels 0 - 15. Direct capable */
#define MCHP_INT14_DMA(x) BIT(x)

/* GIQ15 interrupt sources. Direct capable */
#define MCHP_INT15_UART_0		BIT(0)
#define MCHP_INT15_UART_1		BIT(1)
#define MCHP_INT15_EMI_0		BIT(2)
#define MCHP_INT15_EMI_1		BIT(3)
#define MCHP_INT15_EMI_2		BIT(4)
#define MCHP_INT15_ACPI_EC0_IBF		BIT(5)
#define MCHP_INT15_ACPI_EC0_OBE		BIT(6)
#define MCHP_INT15_ACPI_EC1_IBF		BIT(7)
#define MCHP_INT15_ACPI_EC1_OBE		BIT(8)
#define MCHP_INT15_ACPI_EC2_IBF		BIT(9)
#define MCHP_INT15_ACPI_EC2_OBE		BIT(10)
#define MCHP_INT15_ACPI_EC3_IBF		BIT(11)
#define MCHP_INT15_ACPI_EC3_OBE		BIT(12)
#define MCHP_INT15_ACPI_EC4_IBF		BIT(13)
#define MCHP_INT15_ACPI_EC4_OBE		BIT(14)
#define MCHP_INT15_ACPI_PM1_CTL		BIT(15)
#define MCHP_INT15_ACPI_PM1_EN		BIT(16)
#define MCHP_INT15_ACPI_PM1_STS		BIT(17)
#define MCHP_INT15_8042_OBE		BIT(18)
#define MCHP_INT15_8042_IBF		BIT(19)
#define MCHP_INT15_MAILBOX		BIT(20)
#define MCHP_INT15_BDP0			BIT(22)

/* GIRQ16 interrupt sources. Direct capable */
#define MCHP_INT16_PKE_DONE		BIT(0)
#define MCHP_INT16_RNG_DONE		BIT(2)
#define MCHP_INT16_AESH_DONE		BIT(3)

/* GIR17 interrupt sources. Direct capable */
#define MCHP_INT17_PECI			BIT(0)
#define MCHP_INT17_TACH_0		BIT(1)
#define MCHP_INT17_TACH_1		BIT(2)
#define MCHP_INT17_TACH_2		BIT(3)
#define MCHP_INT17_TACH_3		BIT(4)
#define MCHP_INT17_ADC_SINGLE		BIT(8)
#define MCHP_INT17_ADC_REPEAT		BIT(9)
#define MCHP_INT17_RCID_0		BIT(10)
#define MCHP_INT17_RCID_1		BIT(11)
#define MCHP_INT17_RCID_2		BIT(12)
#define MCHP_INT17_LED_WDT_0		BIT(13)
#define MCHP_INT17_LED_WDT_1		BIT(14)
#define MCHP_INT17_LED_WDT_2		BIT(15)
#define MCHP_INT17_LED_WDT_3		BIT(16)
#define MCHP_INT17_PROCHOT		BIT(17)
#define MCHP_INT17_RPM2PWM0_FAIL	BIT(20)
#define MCHP_INT17_RPM2PWM0_STALL	BIT(21)
#define MCHP_INT17_RPM2PWM1_FAIL	BIT(22)
#define MCHP_INT17_RPM2PWM1_STALL	BIT(23)

/* GIRQ18 interrupt sources. Direct capable */
#define MCHP_INT18_SPIEP		BIT(0)
#define MCHP_INT18_QMSPI		BIT(1)
#define MCHP_INT18_GPSPI0_TXBE		BIT(2)
#define MCHP_INT18_GPSPI0_RXBF		BIT(3)
#define MCHP_INT18_GPSPI1_TXBE		BIT(4)
#define MCHP_INT18_GPSPI1_RXBF		BIT(5)
#define MCHP_INT18_BCM0_BUSY		BIT(6)
#define MCHP_INT18_BCM0_ERR		BIT(7)
#define MCHP_INT18_PS2_0		BIT(10)
#define MCHP_INT18_PSPI			BIT(13)
#define MCHP_INT18_CCT			BIT(20)
#define MCHP_INT18_CCT_CAP0		BIT(21)
#define MCHP_INT18_CCT_CAP1		BIT(22)
#define MCHP_INT18_CCT_CAP2		BIT(23)
#define MCHP_INT18_CCT_CAP3		BIT(24)
#define MCHP_INT18_CCT_CAP4		BIT(25)
#define MCHP_INT18_CCT_CAP6		BIT(26)
#define MCHP_INT18_CCT_CMP0		BIT(27)
#define MCHP_INT18_CCT_CMP1		BIT(28)

/* GIRQ19 interrupt sources. Direct capable */
#define MCHP_INT19_ESPI_PC		BIT(0)
#define MCHP_INT19_ESPI_BM1		BIT(1)
#define MCHP_INT19_ESPI_BM2		BIT(2)
#define MCHP_INT19_ESPI_LTR		BIT(3)
#define MCHP_INT19_ESPI_OOB_TX		BIT(4)
#define MCHP_INT19_ESPI_OOB_RX		BIT(5)
#define MCHP_INT19_ESPI_FC		BIT(6)
#define MCHP_INT19_ESPI_RESET		BIT(7)
#define MCHP_INT19_ESPI_VW_EN		BIT(8)
#define MCHP_INT19_ESPI_SAF		BIT(9)
#define MCHP_INT19_ESPI_SAF_ERR		BIT(10)
#define MCHP_INT19_ESPI_SAF_CACHE	BIT(11)

/* GIRQ20 interrupt sources. Direct capable */
#define MCHP_INT20_STAP_OBF		BIT(0)
#define MCHP_INT20_STAP_IBF		BIT(1)
#define MCHP_INT20_STAP_WAKE		BIT(2)
#define MCHP_INT20_OTP			BIT(3)
#define MCHP_INT20_ISPI			BIT(8)
#define MCHP_INT20_CLK32K_MON		BIT(9)

/* GIRQ21 interrupt sources. Direct capable */
#define MCHP_INT21_WDG			BIT(2)
#define MCHP_INT21_WEEK_ALARM		BIT(3)
#define MCHP_INT21_WEEK_SUB		BIT(4)
#define MCHP_INT21_WEEK_1SEC		BIT(5)
#define MCHP_INT21_WEEK_1SEC_SUB	BIT(6)
#define MCHP_INT21_WEEK_PWR_PRES	BIT(7)
#define MCHP_INT21_RTC			BIT(8)
#define MCHP_INT21_RTC_ALARM		BIT(9)
#define MCHP_INT21_VCI_OVRD		BIT(10)
#define MCHP_INT21_VCI_IN0		BIT(11)
#define MCHP_INT21_VCI_IN1		BIT(12)
#define MCHP_INT21_VCI_IN2		BIT(13)
#define MCHP_INT21_VCI_IN3		BIT(14)
#define MCHP_INT21_VCI_IN4		BIT(15)
#define MCHP_INT21_PS2_0A_WAKE		BIT(18)
#define MCHP_INT21_PS2_0B_WAKE		BIT(19)
#define MCHP_INT21_KEYSCAN		BIT(25)
#define MCHP_INT21_GLUE			BIT(26)

/* GIRQ22 peripheral wake only. GIRQ22 not connected to NVIC */
#define MCHP_INT22_WAKE_ONLY_SPIEP	BIT(0)
#define MCHP_INT22_WAKE_ONLY_I2C0	BIT(1)
#define MCHP_INT22_WAKE_ONLY_I2C1	BIT(2)
#define MCHP_INT22_WAKE_ONLY_I2C2	BIT(3)
#define MCHP_INT22_WAKE_ONLY_I2C3	BIT(4)
#define MCHP_INT22_WAKE_ONLY_I2C4	BIT(5)
#define MCHP_INT22_WAKE_ONLY_ESPI	BIT(9)
#define MCHP_INT22_WAKE_ONLY_STAP	BIT(15)

/* GIRQ23 sources. Direct capable */
#define MCHP_INT23_BTMR16_0		BIT(0)
#define MCHP_INT23_BTMR16_1		BIT(1)
#define MCHP_INT23_BTMR16_2		BIT(2)
#define MCHP_INT23_BTMR16_3		BIT(3)
#define MCHP_INT23_BTMR32_0		BIT(4)
#define MCHP_INT23_BTMR32_1		BIT(5)
#define MCHP_INT23_CNT16_0		BIT(6)
#define MCHP_INT23_CNT16_1		BIT(7)
#define MCHP_INT23_CNT16_2		BIT(8)
#define MCHP_INT23_CNT16_3		BIT(9)
#define MCHP_INT21_RTMR			BIT(10)
#define MCHP_INT21_HTMR_0		BIT(16)
#define MCHP_INT21_HTMR_1		BIT(17)

/* GIRQ24 sources. Master-to-Slave v=[0:6], Source=[0:3] */
#define MCHP_INT24_MSVW_SRC(v, s) (1ul << ((4 * (v)) + (s)))

/* GIRQ25 sources Master-to-Slave v=[7:10], Source=[0:3] */
#define MCHP_INT25_MSVW_SRC(v, s) (1ul << ((4 * ((v)-7)) + (s)))

/* UART Peripheral 0 <= x <= 1 */
#define MCHP_UART_INSTANCES	2
#define MCHP_UART_SPACING	0x400
#define MCHP_UART_CFG_OFS	0x300
#define MCHP_UART_CONFIG_BASE(x) \
	(MCHP_UART0_BASE + MCHP_UART_CFG_OFS + ((x) * MCHP_UART_SPACING))
#define MCHP_UART_RUNTIME_BASE(x) \
	(MCHP_UART0_BASE + ((x) * MCHP_UART_SPACING))
#define MCHP_UART_GIRQ		15
#define MCHP_UART0_GIRQ_BIT	(MCHP_INT15_UART_0)
#define MCHP_UART1_GIRQ_BIT	(MCHP_INT15_UART_1)
#define MCHP_UART_GIRQ_BIT(x)	BIT(x)
/* Bit defines for MCHP_UARTx_LSR */
#define MCHP_LSR_TX_EMPTY	BIT(5)

/*
 * GPIO
 * MCHP each Port contains 32 GPIO's.
 * GPIO Control 1 registers are 32-bit registers starting at
 * MCHP_GPIO_BASE.
 * index = octal GPIO number from MCHP specification.
 * port/bank = index >> 5
 * id = index & 0x1F
 *
 * The port/bank, id pair may also be used to access GPIO's via
 * parallel I/O registers if GPIO control is configured for
 * parallel I/O.
 *
 * From ec/chip/mec1701/config_chip.h
 * #define GPIO_PIN(index) ((index) >> 5), ((index) & 0x1F)
 *
 * GPIO Control 1 Address = 0x40081000 + (((bank << 5) + id) << 2)
 *
 * Example: GPIO043, Control 1 register address = 0x4008108c
 * port/bank = 0x23 >> 5 = 1
 * id        = 0x23 & 0x1F = 0x03
 * Control 1 Address = 0x40081000 + ((BIT(5) + 0x03) << 2) = 0x4008108c
 *
 * Example: GPIO235, Control 1 register address = 0x40081274
 * port/bank = 0x9d >> 5   = 4
 * id        = 0x9d & 0x1f = 0x1d
 * Control 1 Address = 0x40081000 + (((4 << 5) + 0x1d) << 2) = 0x40081274
 *
 */
#define MCHP_GPIO_CTL(port, id) REG32(MCHP_GPIO_BASE + \
	(((port << 5) + id) << 2))

/* MCHP implements 6 GPIO ports */
#define MCHP_GPIO_MAX_PORT	6
#define UNIMPLEMENTED_GPIO_BANK	MCHP_GPIO_MAX_PORT
/*
 * In MECxxxx documentation GPIO numbers are octal, each control
 * register is located on a 32-bit boundary.
 */
#define MCHP_GPIO_CTRL(gpio_num) REG32(MCHP_GPIO_BASE + \
	((gpio_num) << 2))

/*
 * GPIO control register bit fields
 */
#define MCHP_GPIO_CTRL_PUD_BITPOS	0
#define MCHP_GPIO_CTRL_PUD_MASK0	0x03
#define MCHP_GPIO_CTRL_PUD_MASK		0x03
#define MCHP_GPIO_CTRL_PUD_NONE		0x00
#define MCHP_GPIO_CTRL_PUD_PU		0x01
#define MCHP_GPIO_CTRL_PUD_PD		0x02
#define MCHP_GPIO_CTRL_PUD_KEEPER	0x03
#define MCHP_GPIO_CTRL_PWR_BITPOS	2
#define MCHP_GPIO_CTRL_PWR_MASK0	0x03
#define MCHP_GPIO_CTRL_PWR_MASK		GENMASK(2, 1)
#define MCHP_GPIO_CTRL_PWR_VTR		0
#define MCHP_GPIO_CTRL_PWR_OFF		(0x02U << 2)
#define MCHP_GPIO_INTDET_MASK		0xF0U
#define MCHP_GPIO_INTDET_LVL_LO		0x00
#define MCHP_GPIO_INTDET_LVL_HI		0x10U
#define MCHP_GPIO_INTDET_DISABLED	0x40U
#define MCHP_GPIO_INTDET_EDGE_RIS	0xD0U
#define MCHP_GPIO_INTDET_EDGE_FALL	0xE0U
#define MCHP_GPIO_INTDET_EDGE_BOTH	0xF0U
#define MCHP_GPIO_INTDET_EDGE_EN	BIT(7)
#define MCHP_GPIO_PUSH_PULL		0U
#define MCHP_GPIO_OPEN_DRAIN		BIT(8)
#define MCHP_GPIO_INPUT			0U
#define MCHP_GPIO_OUTPUT		BIT(9)
#define MCHP_GPIO_OUTSET_CTRL		0U
#define MCHP_GPIO_OUTSEL_PAR		BIT(10)
#define MCHP_GPIO_POLARITY_NINV		0U
#define MCHP_GPIO_POLARITY_INV		BIT(11)
#define MCHP_GPIO_CTRL_ALT_FUNC_BITPOS	12
#define MCHP_GPIO_CTRL_ALT_FUNC_MASK0	0x07U
#define MCHP_GPIO_CTRL_ALT_FUNC_MASK	(0x07U << 12)
#define MCHP_GPIO_CTRL_FUNC_GPIO	0
#define MCHP_GPIO_CTRL_FUNC_1		(1U << 12)
#define MCHP_GPIO_CTRL_FUNC_2		(2U << 12)
#define MCHP_GPIO_CTRL_FUNC_3		(3U << 12)
#define MCHP_GPIO_CTRL_FUNC_4		(4U << 12)
#define MCHP_GPIO_CTRL_FUNC_5		(5U << 12)
#define MCHP_GPIO_CTRL_OUT_LVL		BIT(16)
/* MEC172x implements input pad disable */
#define MCHP_GPIO_CTRL_DIS_INPUT_BITPOS	15
#define MCHP_GPIO_CTRL_DIS_INPUT_BIT	BIT(15)

/*
 * GPIO Parallel Input and Output registers.
 * gpio_bank in [0, 5]
 */
#define MCHP_GPIO_PARIN(bank)	\
	REG32(MCHP_GPIO_BASE + 0x0300 + ((bank) << 2))
#define MCHP_GPIO_PAROUT(bank)	\
	REG32(MCHP_GPIO_BASE + 0x0380 + ((bank) << 2))

/* Basic timers */
#define MCHP_TMR_SPACING	0x20
#define MCHP_TMR16_INSTANCES	4
#define MCHP_TMR32_INSTANCES	2
#define MCHP_TMR16_MAX		(MCHP_TMR16_INSTANCES)
#define MCHP_TMR32_MAX		(MCHP_TMR32_INSTANCES)
#define MCHP_TMR16_BASE(n)	(MCHP_TMR16_0_BASE + (n) * MCHP_TMR_SPACING)
#define MCHP_TMR32_BASE(n)	(MCHP_TMR32_0_BASE + (n) * MCHP_TMR_SPACING)
#define MCHP_TMR16_GIRQ		23
#define MCHP_TMR16_GIRQ_BIT(n)	BIT(0 + (n))
#define MCHP_TMR32_GIRQ		23
#define MCHP_TMR32_GIRQ_BIT(n)	BIT(4 + (n))

/* 16-bit Counter/timer */
#define MCHP_CNT16_SPACING	0x20
#define MCHP_CNT16_INSTANCES	4
#define MCHP_CNT16_BASE(n)	\
	(MCHP_CNT16_0_BASE + (n) * MCHP_CNT16_SPACING)
#define MCHP_CNT16_GIRQ		23
#define MCHP_CNT16_GIRQ_BIT(x)	BIT(6 + (x))

/* RTimer */
#define MCHP_RTMR_GIRQ		21
#define MCHP_RTMR_GIRQ_BIT(x)	MCHP_INT21_RTMR

/* Watchdog */
/* MEC152x specific registers */
#define MCHP_WDG_STATUS			REG32(MCHP_WDG_BASE + 0x10)
#define MCHP_WDG_IEN			REG32(MCHP_WDG_BASE + 0x14)
/* Status */
#define MCHP_WDG_STS_IRQ		BIT(0)
/* Interrupt enable */
#define MCHP_WDG_IEN_IRQ_EN		BIT(0)
#define MCHP_WDG_GIRQ			21
#define MCHP_WDG_GIRQ_BIT		BIT(2)
/* Control register has a bit to enable IRQ generation */
#define MCHP_WDG_RESET_IRQ_EN		BIT(9)

/* VBAT */
#define MCHP_VBAT_STS			REG32(MCHP_VBAT_BASE + 0x0)
#define MCHP_VBAT_CSS			REG32(MCHP_VBAT_BASE + 0x8)
#define MCHP_VBAT_MONOTONIC_CTR_LO	REG32(MCHP_VBAT_BASE + 0x20)
#define MCHP_VBAT_MONOTONIC_CTR_HI	REG32(MCHP_VBAT_BASE + 0x24)
#define MCHP_VBAT_ROM_FEAT		REG32(MCHP_VBAT_BASE + 0x28)
#define MCHP_VBAT_EMB_DEBOUNCE_EN	REG32(MCHP_VBAT_BASE + 0x34)
/* read 32-bit word at 32-bit offset x where 0 <= x <= 32 */
#define MCHP_VBAT_RAM_SIZE		128
#define MCHP_VBAT_RAM(wnum)		\
	REG32(MCHP_VBAT_RAM_BASE + ((wnum) * 4))
#define MCHP_VBAT_RAM8(bnum)		\
	REG8(MCHP_VBAT_RAM_BASE + (bnum))
#define MCHP_VBAT_VWIRE_BACKUP		30
/*
 * Miscellaneous firmware control fields
 * scratch pad index cannot be more than 32 as
 * MEC152x has 64 bytes = 16 words of scratch RAM
 */
#define MCHP_IMAGETYPE_IDX	31

/* Bit definition for MCHP_VBAT_STS */
#define MCHP_VBAT_STS_SOFTRESET		BIT(2)
#define MCHP_VBAT_STS_RESETI		BIT(4)
#define MCHP_VBAT_STS_WDT		BIT(5)
#define MCHP_VBAT_STS_SYSRESETREQ	BIT(6)
#define MCHP_VBAT_STS_VBAT_RST		BIT(7)
#define MCHP_VBAT_STS_ANY_RST		0xF4u

/* Bit definitions for MCHP_VBAT_CSS */
#define MCHP_VBAT_CSS_SIL32K_EN		BIT(0)
#define MCHP_VBAT_CSS_XTAL_EN		BIT(8)
#define MCHP_VBAT_CSS_XTAL_SINGLE	BIT(9)
#define MCHP_VBAT_CSS_XTAL_HSC_DIS	BIT(10)
#define MCHP_VBAT_CSS_XTAL_CNT_POS	11
#define MCHP_VBAT_CSS_XTAL_CNT_MASK	(0x03U << 11)
#define MCHP_VBAT_CSS_SRC_POS		16
#define MCHP_VBAT_CSS_SRC_MASK		(0x03U << 16)
#define MCHP_VBAT_CSS_SRC_SIL_OSC	0
#define MCHP_VBAT_CSS_SRC_XTAL		(1U << 16)
/* Switch from 32KHZ_IN input to silicon OSC when VTR goes down */
#define MCHP_VBAT_CSS_SRC_SWPS		(2U << 16)
/* Switch from 32KHZ_IN input to XTAL on VBAT when VTR goes down */
#define MCHP_VBAT_CSS_SRC_SWPX		(3U << 16)
/* Disable 32Khz silicon oscillator when VBAT goes off */
#define MCHP_VBAT_CSS_NVB_SUPS		BIT(18)

/* Blinking-Breathing LED 0 <= n <= 2 */
#define MCHP_BBLEB_INSTANCES	4
#define MCHP_BBLED_BASE(n)	(MCHP_BBLED_0_BASE + (((n) & 0x03) * 256))

/* EMI */
#define MCHP_EMI_INSTANCES	3
#define MCHP_EMI_SPACING	0x400
#define MCHP_EMI_ECREG_OFS	0x100
/* base of EMI registers only accessible by EC */
#define MCHP_EMI_BASE(n) \
	(MCHP_EMI_0_BASE + MCHP_EMI_ECREG_OFS + ((n) * MCHP_EMI_SPACING))
/* base of EMI registers accessible by EC and Host */
#define MCHP_EMI_RT_BASE(n) (MCHP_EMI_0_BASE + ((n) * MCHP_EMI_SPACING))
#define MCHP_EMI_GIRQ		15
#define MCHP_EMI_GIRQ_BIT(n)	BIT(2 + (n))

/* Mailbox */
#define MCHP_MBX_ECREGS_OFS	0x100
#define MCHP_MBX_RT_BASE	MCHP_MBOX_BASE
#define MCHP_MBX_BASE		(MCHP_MBOX_BASE + MCHP_MBX_ECREGS_OFS)
#define MCHP_MBX_GIRQ		15
#define MCHP_MBX_GIRQ_BIT	BIT(20)

/* MEC172x includes one instance of the BIOS Debug Port
 * capable of capturing Host I/O port 0x80 and 0x90 writes.
 * EC Data Value register:
 * bits[7:0] oldest FIFO data from Host
 * bits[15:16] data attributes/status
 * Read with 16 or 32 access guarantees attributes/status bits
 * correspond to data in bits[7:0].
 */
#define MCHP_BDP0_HDATA		REG32(MCHP_BDP0_BASE)
#define MCHP_BDP0_DATTR		REG16(MCHP_BDP0_BASE + 0x100)
#define MCHP_BDP0_CONFIG	REG32(MCHP_BDP0_BASE + 0x104)
#define MCHP_BDP0_STATUS	REG8(MCHP_BDP0_BASE + 0x108)
#define MCHP_BDP0_INTR_EN	REG8(MCHP_BDP0_BASE + 0x109)
#define MCHP_BDP0_STS_IEN	REG16(MCHP_BDP0_BASE + 0x108)
#define MCHP_BDP0_SNAPSHOT	REG32(MCHP_BDP0_BASE + 0x10C)
#define MCHP_BDP0_CAPTURE	REG32(MCHP_BDP0_BASE + 0x110)
#define MCHP_BDP0_ACTV		REG8(MCHP_BDP0_BASE + 0x330)
#define MCHP_BDP0_ALIAS_HDATA	REG8(MCHP_BDP0_BASE + 0x400)
#define MCHP_BDP0_ALIAS_ACTV	REG8(MCHP_BDP0_BASE + 0x730)
#define MCHP_BDP0_ALIAS_BLN	REG8(MCHP_BDP0_BASE + 0x7F0)

#define MCHP_BDP0_GIRQ		15
#define MCHP_BDP0_GIRQ_BIT	BIT(22)

/* BDP DATATR as 16-bit value bit definitions */
#define MCHP_BDP_DATTR_POS		0
#define MCHP_BDP_DATTR_DATA_MASK	0xff
#define MCHP_BDP_DATTR_LANE_POS		8
#define MCHP_BDP_DATTR_LANE_MASK	GENMASK(9, 8)
#define MCHP_BDP_DATTR_LANE_0		0
#define MCHP_BDP_DATTR_LANE_1		(1U << 8)
#define MCHP_BDP_DATTR_LANE_2		(2U << 8)
#define MCHP_BDP_DATTR_LANE_3		(3U << 8)
#define MCHP_BDP_DATTR_LEN_POS		10
#define MCHP_BDP_DATTR_LEN_MASK		GENMASK(11, 10)
#define MCHP_BDP_DATTR_LEN_1		0
#define MCHP_BDP_DATTR_LEN_2		(1U << 10)
#define MCHP_BDP_DATTR_LEN_4		(2U << 10)
#define MCHP_BDP_DATTR_LEN_INVAL	(3U << 10)
#define MCHP_BDP_DATTR_NE		BIT(12)
#define MCHP_BDP_DATTR_OVR		BIT(13)
#define MCHP_BDP_DATTR_THRH		BIT(14)

/* BDP Configuration */
#define MCHP_BDP_CFG_FLUSH_FIFO		BIT(0)
#define MCHP_BDP_CFG_SNAPSHOT_CLR	BIT(1)
#define MCHP_BDP_CFG_FIFO_THRH_POS	8
#define MCHP_BDP_CFG_FIFO_THRH_1	0
#define MCHP_BDP_CFG_FIFO_THRH_4	(1U << 8)
#define MCHP_BDP_CFG_FIFO_THRH_8	(2U << 8)
#define MCHP_BDP_CFG_FIFO_THRH_16	(3U << 8)
#define MCHP_BDP_CFG_FIFO_THRH_20	(4U << 8)
#define MCHP_BDP_CFG_FIFO_THRH_24	(5U << 8)
#define MCHP_BDP_CFG_FIFO_THRH_28	(6U << 8)
#define MCHP_BDP_CFG_FIFO_THRH_30	(7U << 8)
#define MCHP_BDP_CFG_SRST		BIT(31)

/* BDP Status */
#define MCHP_BDP_STATUS_MASK		GENMASK(2, 0)
#define MCHP_BDP_STATUS_NOT_EMPTY	BIT(0)
#define MCHP_BDP_STATUS_OVERRUN		BIT(1)
#define MCHP_BDP_STATUS_THRH		BIT(2)

/* BDP Interrupt enable */
#define MCHP_BDP_IEN_THRH		BIT(0)

/* PWM SZ 144 pin package has 9 PWM's */
#define MCHP_PWM_INSTANCES		9
#define MCHP_PWM_ID_MAX			(MCHP_PWM_INSTANCES)
#define MCHP_PWM_SPACING		16
#define MCHP_PWM_BASE(x) (MCHP_PWM_0_BASE + ((x) * MCHP_PWM_SPACING))

/* TACH */
#define MCHP_TACH_INSTANCES	4
#define MCHP_TACH_SPACING	16
#define MCHP_TACH_BASE(x) (MCHP_TACH_0_BASE + ((x) * MCHP_TACH_SPACING))
#define MCHP_TACH_GIRQ		17
#define MCHP_TACH_GIRQ_BIT(x)	BIT(1 + (x))

/* FAN */
#define MCHP_FAN_INSTANCES	2
#define MCHP_FAN_SPACING	0x80U
#define MCHP_FAN_BASE(x)	\
	(MCHP_RPM2PWM0_BASE + ((x) * MCHP_FAN_SPACING))
#define MCHP_FAN_SETTING(x)	REG8(MCHP_FAN_BASE(x) + 0x0)
#define MCHP_FAN_PWM_DIVIDE(x)	REG8(MCHP_FAN_BASE(x) + 0x1)
#define MCHP_FAN_CFG1(x)	REG8(MCHP_FAN_BASE(x) + 0x2)
#define MCHP_FAN_CFG2(x)	REG8(MCHP_FAN_BASE(x) + 0x3)
#define MCHP_FAN_GAIN(x)	REG8(MCHP_FAN_BASE(x) + 0x5)
#define MCHP_FAN_SPIN_UP(x)	REG8(MCHP_FAN_BASE(x) + 0x6)
#define MCHP_FAN_STEP(x)	REG8(MCHP_FAN_BASE(x) + 0x7)
#define MCHP_FAN_MIN_DRV(x)	REG8(MCHP_FAN_BASE(x) + 0x8)
#define MCHP_FAN_VALID_CNT(x)	REG8(MCHP_FAN_BASE(x) + 0x9)
#define MCHP_FAN_DRV_FAIL(x)	REG16(MCHP_FAN_BASE(x) + 0xa)
#define MCHP_FAN_TARGET(x)	REG16(MCHP_FAN_BASE(x) + 0xc)
#define MCHP_FAN_READING(x)	REG16(MCHP_FAN_BASE(x) + 0xe)
#define MCHP_FAN_BASE_FREQ(x)	REG8(MCHP_FAN_BASE(x) + 0x10)
#define MCHP_FAN_STATUS(x)	REG8(MCHP_FAN_BASE(x) + 0x11)

/* ACPI EC */
#define MCHP_ACPI_EC_INSTANCES		5
#define MCHP_ACPI_EC_MAX		(MCHP_ACPI_EC_INSTANCES)
#define MCHP_ACPI_EC_SPACING		0x400
#define MCHP_ACPI_EC_BASE(x) \
	(MCHP_ACPI_EC_0_BASE + ((x) * MCHP_ACPI_EC_SPACING))
#define MCHP_ACPI_EC_GIRQ		15
#define MCHP_ACPI_EC_IBF_GIRQ_BIT(x)	BIT(5 + ((x) * 2))
#define MCHP_ACPI_EC_OBE_GIRQ_BIT(x)	BIT(6 + ((x) * 2))

/* ACPI PM1 */
#define MCHP_ACPI_PM1_ECREGS_OFS	0x100
#define MCHP_ACPI_PM_RT_BASE		MCHP_ACPI_PM1_BASE
#define MCHP_ACPI_PM_EC_BASE	(MCHP_ACPI_PM1_BASE + MCHP_ACPI_PM1_ECREGS_OFS)
#define MCHP_ACPI_PM1_CTL_GIRQ_BIT	BIT(15)
#define MCHP_ACPI_PM1_EN_GIRQ_BIT	BIT(16)
#define MCHP_ACPI_PM1_STS_GIRQ_BIT	BIT(17)

/* 8042 */
#define MCHP_8042_ECREGS_OFS		0x100
#define MCHP_8042_GIRQ			15
#define MCHP_8042_OBE_GIRQ_BIT		BIT(18)
#define MCHP_8042_IBF_GIRQ_BIT		BIT(19)

/* I2C controllers 0 - 4 include SMBus network layer functionality. */
#define MCHP_I2C_CTRL0		0
#define MCHP_I2C_CTRL1		1
#define MCHP_I2C_CTRL2		2
#define MCHP_I2C_CTRL3		3
#define MCHP_I2C_CTRL4		4
#define MCHP_I2C_CTRL_MAX	5

#define MCHP_I2C_SEP0		0x400

/*
 * MEC172x SZ(144-pin) package implements 15 ports. No Port 11.
 * LJ(176-pin) package implements 16 ports.
 * Any port can be mapped to any I2C controller.
 * I2C port values must be zero based consecutive whole numbers due to
 * port number used as an index for I2C the mutex list, etc.
 * Refer to chip i2c_port_to_controller function for mapping
 * of port to controller.
 * Locking must occur by-controller (not by-port).
 */
#if (defined(CHIP_VARIANT_MEC1721LJ) || defined(CHIP_VARIANT_MEC1723LJ)\
		|| defined(CHIP_VARIANT_MEC1727LJ))
#define MCHP_I2C_PORT_MASK GENMASK(15, 0)
#else
#define MCHP_I2C_PORT_MASK (GENMASK(15, 0) & ~BIT(11))
#endif
enum MCHP_i2c_port {
	MCHP_I2C_PORT0 = 0,
	MCHP_I2C_PORT1,
	MCHP_I2C_PORT2,
	MCHP_I2C_PORT3,
	MCHP_I2C_PORT4,
	MCHP_I2C_PORT5,
	MCHP_I2C_PORT6,
	MCHP_I2C_PORT7,
	MCHP_I2C_PORT8,
	MCHP_I2C_PORT9,
	MCHP_I2C_PORT10,
	MCHP_I2C_PORT11,
	MCHP_I2C_PORT12,
	MCHP_I2C_PORT13,
	MCHP_I2C_PORT14,
	MCHP_I2C_PORT15,
	MCHP_I2C_PORT_COUNT,
};

/* All I2C controllers connected to GIRQ13 */
#define MCHP_I2C_GIRQ		13
/* I2C[0:7] -> GIRQ13 bits[0:7] */
#define MCHP_I2C_GIRQ_BIT(n)	BIT((n))

/* Keyboard scan matrix */
#define MCHP_KS_GIRQ		21
#define MCHP_KS_GIRQ_BIT	BIT(25)
#define MCHP_KS_DIRECT_NVIC	135

/* ADC */
#if (defined(CHIP_VARIANT_MEC1721LJ) || defined(CHIP_VARIANT_MEC1723LJ)\
		|| defined(CHIP_VARIANT_MEC1727LJ))
#define MCHP_ADC_CHAN_MASK GENMASK(15, 0)
#else
#define MCHP_ADC_CHAN_MASK GENMASK(7, 0)
#endif
#define MCHP_ADC_GIRQ			17
#define MCHP_ADC_GIRQ_SINGLE_BIT	BIT(8)
#define MCHP_ADC_GIRQ_REPEAT_BIT	BIT(9)
#define MCHP_ADC_SINGLE_DIRECT_NVIC	78
#define MCHP_ADC_REPEAT_DIRECT_NVIC	79
#define MCHP_ADC_CONFIG			REG32(MCHP_ADC_BASE + 0x7c)
#define MCHP_ADC_CONFIG_DFLT		0x0101U
#define MCHP_ADC_CFG_CLK_LO_TM_MSK	GENMASK(7, 0)
#define MCHP_ADC_CFG_CLK_HI_TM_MSK	GENMASK(15, 8)
#define MCHP_ADC_VREF_CSEL		REG32(MCHP_ADC_BASE + 0x80)
#define MCHP_ADC_VREF_CSEL_MSK(ch)	(0x03U << ((ch) * 2U))
#define MCHP_ADC_VREF_CSEL_GPIO(ch)	BIT((ch) * 2U)
#define MCHP_ADC_VREF_CTRL		REG32(MCHP_ADC_BASE + 0x84)
#define MCHP_ADC_VREF_CTRL_DFLT		0U
#define MCHP_ADC_VCTRL_CHRG_DLY_MSK	GENMASK(15, 0)
#define MCHP_ADC_VCTRL_SW_DLY_MSK	GENMASK(28, 16)
#define MCHP_ADC_VCTRL_DRV_UNUSED_LO	BIT(29)
#define MCHP_ADC_VCTRL_SEL_STS_RO_POS	30
#define MCHP_ADC_VCTRL_SEL_STS_RO_MSK	GENMASK(31, 30)
#define MCHP_ADC_SAR_ADC_CTRL		REG32(MCHP_ADC_BASE + 0x88)
#define MCHP_ADC_SAR_ADC_CTRL_DFLT	((0x202U << 7) | (0x03U << 1))
#define MCHP_ADC_SAC_DIFF_INPUT		BIT(0)
#define MCHP_ADC_SAC_RES_POS		1
#define MCHP_ADC_SAC_RES_MSK		GENMASK(2, 1)
#define MCHP_ADC_SAC_RES_10BIT		(2U << 1)
#define MCHP_ADC_SAC_RES_12BIT		(3U << 1)
#define MCHP_ADC_SAC_RJ_10BIT		BIT(3)
#define MCHP_ADC_SAC_WU_DLY_POS		7
#define MCHP_ADC_SAC_WU_DLY_MSK		GENMASK(16, 7)
#define MCHP_ADC_SAC_WU_DLY_DLFT	(0x202U << 7)

/* Hibernation timer */
#define MCHP_HTIMER_SPACING		0x20
#define MCHP_HTIMER_ADDR(n) (MCHP_HTIMER_BASE + ((n) * MCHP_HTIMER_SPACING))
#define MCHP_HTIMER_GIRQ		21
/* HTIMER[0:1] -> GIRQ21 bits[1:2] */
#define MCHP_HTIMER_GIRQ_BIT(n)		BIT(1 + (n))
#define MCHP_HTIMER_DIRECT_NVIC(n)	(112 + (n))

/* General Purpose SPI (GP-SPI) */
#define MCHP_SPI_BASE(port) (MCHP_GPSPI0_BASE + ((port) * 0x80))
#define MCHP_SPI_AR(port)	REG8(MCHP_SPI_BASE(port) + 0x00)
#define MCHP_SPI_CR(port)	REG8(MCHP_SPI_BASE(port) + 0x04)
#define MCHP_SPI_SR(port)	REG8(MCHP_SPI_BASE(port) + 0x08)
#define MCHP_SPI_TD(port)	REG8(MCHP_SPI_BASE(port) + 0x0c)
#define MCHP_SPI_RD(port)	REG8(MCHP_SPI_BASE(port) + 0x10)
#define MCHP_SPI_CC(port)	REG8(MCHP_SPI_BASE(port) + 0x14)
#define MCHP_SPI_CG(port)	REG8(MCHP_SPI_BASE(port) + 0x18)
/* Addresses of TX/RX register used in tables */
#define MCHP_SPI_TD_ADDR(ctrl)	(MCHP_SPI_BASE(ctrl) + 0x0c)
#define MCHP_SPI_RD_ADDR(ctrl)	(MCHP_SPI_BASE(ctrl) + 0x10)
/* All GP-SPI controllers connected to GIRQ18 */
#define MCHP_SPI_GIRQ			18
#define MCHP_SPI_GIRQ_TXBE_BIT(x)	BIT(2 + ((x) * 2))
#define MCHP_SPI_GIRQ_RXBF_BIT(x)	BIT(3 + ((x) * 2))
#define MCHP_GPSPI0_ID			0
#define MCHP_GPSPI1_ID			1

/*
 * Quad Master SPI (QMSPI)
 * MEC172x implements 16 descriptors, support for two chip selects,
 * chip select timing and a local DMA unit with 3 RX channels and
 * 3 TX channels. It retains support of the legacy DMA block.
 */
#define MCHP_QMSPI_MAX_DESCR	16
#define MCHP_QMSPI_GIRQ		18
#define MCHP_QMSPI_GIRQ_BIT	BIT(1)
#define MCHP_QMSPI_DIRECT_NVIC 91
/* SAF DMA mode when QMSPI when eSPI SAF is enabled */
#define MCHP_QMSPI_M_SAF_EN	BIT(2)
/* Local DMA enables in Mode register */
#define MCHP_QMSPI_M_LDRX_EN	BIT(3)
#define MCHP_QMSPI_M_LDTX_EN	BIT(4)
/* Chip select implemented in bit[13:12] of the Mode register. */
#define MCHP_QMSPI_M_CS_POS	12
#define MCHP_QMSPI_M_CS_MASK0	0x03
#define MCHP_QMSPI_M_CS_MASK	GENMASK(13, 12)
#define MCHP_QMSPI_M_CS0	0U
#define MCHP_QMSPI_M_CS1	BIT(12)
/* QMSPI alternate clock divider when CS1 is active. */
#define MCHP_QMSPI0_ALTM	REG32(MCHP_QMSPI0_BASE + 0xc0)
#define MCHP_QMSPI0_ALTM_EN	BIT(0)
/* QMSPI taps select */
#define MCHP_QMSPI0_TAPS		REG32(MCHP_QMSPI0_BASE + 0xd0)
/* QMSPI Taps adjust */
#define MCHP_QMSPI0_TAPS_ADJ		REG32(MCHP_QMSPI0_BASE + 0xd4)
#define MCHP_QMSPI0_TAPS_SCK_POS	0
#define MCHP_QMSPI0_TAPS_SCK_MSK	GENMASK(7, 0)
#define MCHP_QMSPI0_TAPS_CTL_POS	8
#define MCHP_QMSPI0_TAPS_CTL_MSK	GENMASK(15, 8)
/* QMSPI Taps control */
#define MCHP_QMSPI0_TAPS_CTRL		REG32(MCHP_QMSPI0_BASE + 0xd4)
#define MCHP_QMSPI0_TAPS_CTRL_MODE_POS	0
#define MCHP_QMSPI0_TAPS_CTRL_MODE_MSK	GENMASK(1, 0)
#define MCHP_QMSPI0_TAPS_CTRL_UPDATE	BIT(2)
#define MCHP_QMSPI0_TAPS_CTRL_GO	BIT(8)
#define MCHP_QMSPI0_TAPS_CTRL_MULT_POS	16
#define MCHP_QMSPI0_TAPS_CTRL_MULT_MSK	GENMASK(18, 16)
/* QMSPI LDMA descriptor enables */
#define MCHP_QMSPI0_LDRX_DEN	REG32(MCHP_QMSPI0_BASE + 0x100)
#define MCHP_QMSPI0_LDTX_DEN	REG32(MCHP_QMSPI0_BASE + 0x104)
/*
 * QMSPI LDMA channel registers.
 * Each channel implement 3 32-bit registers:
 * control, memory base address, and transfer length.
 */
#define MCHP_QMSPI0_LDRX_CHANS 3U
#define MCHP_QMSPI0_LDTX_CHANS 3U
#define MCHP_QMSPI0_LDRX_CTRL(n) REG32(MCHP_QMSPI0_BASE + 0x110 + ((n)*16U))
#define MCHP_QMSPI0_LDRX_MBASE(n) REG32(MCHP_QMSPI0_BASE + 0x114 + ((n)*16U))
#define MCHP_QMSPI0_LDRX_LEN(n) REG32(MCHP_QMSPI0_BASE + 0x118 + ((n)*16U))
#define MCHP_QMSPI0_LDTX_CTRL(n) REG32(MCHP_QMSPI0_BASE + 0x140 + ((n)*16U))
#define MCHP_QMSPI0_LDTX_MBASE(n) REG32(MCHP_QMSPI0_BASE + 0x144 + ((n)*16U))
#define MCHP_QMSPI0_LDTX_LEN(n) REG32(MCHP_QMSPI0_BASE + 0x148 + ((n)*16U))
/* LDMA RX or TX channel control register */
#define MCHP_QMSPI_LDC_MSK		GENMASK(6, 0)
#define MCHP_QMSPI_LDC_EN		BIT(0)
#define MCHP_QMSPI_LDC_RSTART_EN	BIT(1)
#define MCHP_QMSPI_LDC_RSTART_MA_EN	BIT(2)
#define MCHP_QMSPI_LDC_LEN_EN		BIT(3)
#define MCHP_QMSPI_LDC_ACC_SZ_POS	4
#define MCHP_QMSPI_LDC_ACC_SZ_MSK	GENMASK(5, 4)
#define MCHP_QMSPI_LDC_ACC_1BYTE	0
#define MCHP_QMSPI_LDC_ACC_2BYTES	(1U << 4)
#define MCHP_QMSPI_LDC_ACC_4BYTES	(2U << 4)
#define MCHP_QMSPI_LDC_INCR_ADDR	BIT(6)

/* eSPI */
/* IO BAR defines. Use with MCHP_ESPI_IO_BAR_xxxx macros */
#define MCHP_ESPI_IO_BAR_ID_CFG_PORT	0
#define MCHP_ESPI_IO_BAR_ID_MEM_CMPNT	1
#define MCHP_ESPI_IO_BAR_ID_MAILBOX	2
#define MCHP_ESPI_IO_BAR_ID_8042	3
#define MCHP_ESPI_IO_BAR_ID_ACPI_EC0	4
#define MCHP_ESPI_IO_BAR_ID_ACPI_EC1	5
#define MCHP_ESPI_IO_BAR_ID_ACPI_EC2	6
#define MCHP_ESPI_IO_BAR_ID_ACPI_EC3	7
#define MCHP_ESPI_IO_BAR_ID_ACPI_EC4	8
#define MCHP_ESPI_IO_BAR_ID_ACPI_PM1	9
#define MCHP_ESPI_IO_BAR_ID_P92		0xA
#define MCHP_ESPI_IO_BAR_ID_UART0	0xB
#define MCHP_ESPI_IO_BAR_ID_UART1	0xC
#define MCHP_ESPI_IO_BAR_ID_EMI0	0xD
#define MCHP_ESPI_IO_BAR_ID_EMI1	0xE
#define MCHP_ESPI_IO_BAR_ID_EMI2	0xF
#define MCHP_ESPI_IO_BAR_BDP0		0x10
#define MCHP_ESPI_IO_BAR_BDP0_ALT	0x11
#define MCHP_ESPI_IO_BAR_RTC		0x12
#define MCHP_ESPI_IO_BAR_TB32		0x14
#define MCHP_ESPI_IO_BAR_GLUE		0x16

/* Use with MCHP_ESPI_MBAR_EC_xxxx(x) macros */
#define MCHP_ESPI_MBAR_ID_MBOX		0
#define MCHP_ESPI_MBAR_ID_ACPI_EC_0	1
#define MCHP_ESPI_MBAR_ID_ACPI_EC_1	2
#define MCHP_ESPI_MBAR_ID_ACPI_EC_2	3
#define MCHP_ESPI_MBAR_ID_ACPI_EC_3	4
#define MCHP_ESPI_MBAR_ID_ACPI_EC_4	5
#define MCHP_ESPI_MBAR_ID_EMI_0		6
#define MCHP_ESPI_MBAR_ID_EMI_1		7
#define MCHP_ESPI_MBAR_ID_EMI_2		8
#define MCHP_ESPI_MBAR_ID_TB32		9

/* Use with MCHP_ESPI_IO_SERIRQ_REG(x) */
#define MCHP_ESPI_SIRQ_MBOX		0 /* Host SIRQ */
#define MCHP_ESPI_SIRQ_MBOX_SMI		1 /* Host SMI */
#define MCHP_ESPI_SIRQ_8042_KB		2 /* KIRQ */
#define MCHP_ESPI_SIRQ_8042_MS		3 /* MIRQ */
#define MCHP_ESPI_SIRQ_ACPI_EC0_OBF	4
#define MCHP_ESPI_SIRQ_ACPI_EC1_OBF	5
#define MCHP_ESPI_SIRQ_ACPI_EC2_OBF	6
#define MCHP_ESPI_SIRQ_ACPI_EC3_OBF	7
#define MCHP_ESPI_SIRQ_ACPI_EC4_OBF	8
#define MCHP_ESPI_SIRQ_UART0		9
#define MCHP_ESPI_SIRQ_UART1		10
#define MCHP_ESPI_SIRQ_EMI0_HEV		11 /* Host Event */
#define MCHP_ESPI_SIRQ_EMI0_EC2H	12 /* EC to Host */
#define MCHP_ESPI_SIRQ_EMI1_HEV		13
#define MCHP_ESPI_SIRQ_EMI1_EC2H	14
#define MCHP_ESPI_SIRQ_EMI2_HEV		15
#define MCHP_ESPI_SIRQ_EMI2_EC2H	16
#define MCHP_ESPI_SIRQ_RTC		17
#define MCHP_ESPI_SIRQ_EC		18

#define MCHP_ESPI_MSVW_BASE (MCHP_ESPI_VW_BASE)
#define MCHP_ESPI_SMVW_BASE ((MCHP_ESPI_VW_BASE) + 0x200ul)

/*
 * eSPI RESET, channel enables and operations except Master-to-Slave
 * WWires are all on GIRQ19
 */
#define MCHP_ESPI_GIRQ			19
#define MCHP_ESPI_PC_GIRQ_BIT		BIT(0)
#define MCHP_ESPI_BM1_GIRQ_BIT		BIT(1)
#define MCHP_ESPI_BM2_GIRQ_BIT		BIT(2)
#define MCHP_ESPI_LTR_GIRQ_BIT		BIT(3)
#define MCHP_ESPI_OOB_TX_GIRQ_BIT	BIT(4)
#define MCHP_ESPI_OOB_RX_GIRQ_BIT	BIT(5)
#define MCHP_ESPI_FC_GIRQ_BIT		BIT(6)
#define MCHP_ESPI_RESET_GIRQ_BIT	BIT(7)
#define MCHP_ESPI_VW_EN_GIRQ_BIT	BIT(8)
#define MCHP_ESPI_SAF_DONE_GIRQ_BIT	BIT(9)
#define MCHP_ESPI_SAF_ERR_GIRQ_BIT	BIT(10)
#define MCHP_ESPI_SAF_CACHE_GIRQ_BIT	BIT(11)

/* eSPI Master-to-Slave WWire interrupts are on GIRQ24 and GIRQ25 */
#define MCHP_ESPI_MSVW_0_6_GIRQ		24
#define MCHP_ESPI_MSVW_7_10_GIRQ	25
/*
 * Four source bits, SRC[0:3] per Master-to-Slave register
 * v = MSVW [0:10]
 * n = VWire SRC bit = [0:3]
 */
#define MCHP_ESPI_MSVW_GIRQ(v) (24 + ((v) > 6 ? 1 : 0))

#define MCHP_ESPI_MSVW_SRC_GIRQ_BIT(v, n) \
	(((v) > 6) ? (1ul << (((v)-7)+(n))) : (1ul << ((v)+(n))))

/* DMA */
#define MCHP_DMA_MAX_CHAN	16
#define MCHP_DMA_CH_OFS		0x40
#define MCHP_DMA_CH_OFS_BITPOS	6
#define MCHP_DMA_CH_BASE (MCHP_DMA_BASE + MCHP_DMA_CH_OFS)

/*
 * Available DMA channels.
 *
 * On MCHP, any DMA channel may serve any device. Since we have
 * 14 channels and 14 device request signals, we make each channel
 * dedicated to the device of the same number.
 */
enum dma_channel {
	/* Channel numbers */
	MCHP_DMAC_I2C0_SLAVE = 0,
	MCHP_DMAC_I2C0_MASTER,
	MCHP_DMAC_I2C1_SLAVE,
	MCHP_DMAC_I2C1_MASTER,
	MCHP_DMAC_I2C2_SLAVE,
	MCHP_DMAC_I2C2_MASTER,
	MCHP_DMAC_I2C3_SLAVE,
	MCHP_DMAC_I2C3_MASTER,
	MCHP_DMAC_I2C4_SLAVE,
	MCHP_DMAC_I2C5_MASTER,
	MCHP_DMAC_QMSPI0_TX,
	MCHP_DMAC_QMSPI0_RX,
	MCHP_DMAC_SPI0_TX,
	MCHP_DMAC_SPI0_RX,
	MCHP_DMAC_SPI1_TX,
	MCHP_DMAC_SPI1_RX,
	/* Channel count */
	MCHP_DMAC_COUNT,
};

/*
 * Peripheral device DMA Device ID's for bits [15:9]
 * in DMA channel control register.
 */
#define MCHP_DMA_I2C0_SLV_REQ_ID	0
#define MCHP_DMA_I2C0_MTR_REQ_ID	1
#define MCHP_DMA_I2C1_SLV_REQ_ID	2
#define MCHP_DMA_I2C1_MTR_REQ_ID	3
#define MCHP_DMA_I2C2_SLV_REQ_ID	4
#define MCHP_DMA_I2C2_MTR_REQ_ID	5
#define MCHP_DMA_I2C3_SLV_REQ_ID	6
#define MCHP_DMA_I2C3_MTR_REQ_ID	7
#define MCHP_DMA_I2C4_SLV_REQ_ID	8
#define MCHP_DMA_I2C4_MTR_REQ_ID	9
#define MCHP_DMA_QMSPI0_TX_REQ_ID	10
#define MCHP_DMA_QMSPI0_RX_REQ_ID	11
#define MCHP_DMA_SPI0_TX_REQ_ID		12
#define MCHP_DMA_SPI0_RX_REQ_ID		13
#define MCHP_DMA_SPI1_TX_REQ_ID		14
#define MCHP_DMA_SPI1_RX_REQ_ID		15

/*
 * Hardware delay register.
 * Write of 0 <= n <= 31 will stall the Cortex-M4
 * for n+1 microseconds. Interrupts will not be
 * serviced during the delay period. Reads have
 * no effect.
 */
#define MCHP_USEC_DELAY_REG_ADDR 0x08000000
#define MCHP_USEC_DELAY(x) (REG8(MCHP_USEC_DELAY_REG_ADDR) = (x))

#endif /* #ifndef __ASSEMBLER__ */
