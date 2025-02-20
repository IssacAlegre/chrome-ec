/* Copyright 2020 The Chromium OS Authors. All rights reserved.
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/**
 * @file
 * @brief Register map for the STM32G4 family of chips
 *
 * This header file should not be included directly.
 * Please include registers.h instead.
 *
 * Known Chip Variants
 * - STM32G431
 */

#ifndef __CROS_EC_REGISTERS_H
#error "This header file should not be included directly."
#endif

/* --- IRQ numbers --- */
#define STM32_IRQ_WWDG             0
#define STM32_IRQ_PVD              1
#define STM32_IRQ_TAMPER_STAMP     2
#define STM32_IRQ_RTC_WAKEUP       3
#define STM32_IRQ_FLASH            4
#define STM32_IRQ_RCC              5
#define STM32_IRQ_EXTI0            6
#define STM32_IRQ_EXTI1            7
#define STM32_IRQ_EXTI2            8
#define STM32_IRQ_EXTI3            9
#define STM32_IRQ_EXTI4           10
#define STM32_IRQ_DMA_CHANNEL_1   11
#define STM32_IRQ_DMA_CHANNEL_2   12
#define STM32_IRQ_DMA_CHANNEL_3   13
#define STM32_IRQ_DMA_CHANNEL_4   14
#define STM32_IRQ_DMA_CHANNEL_5   15
#define STM32_IRQ_DMA_CHANNEL_6   16
#define STM32_IRQ_DMA_CHANNEL_7   17
#define STM32_IRQ_ADC1            18
#define STM32_IRQ_USB_HP          19
#define STM32_IRQ_USB_LP          20
#define STM32_IRQ_FDCAN_IT0       21
#define STM32_IRQ_FDCAN_IT1       22
#define STM32_IRQ_EXTI9_5         23
#define STM32_IRQ_TIM15           24
#define STM32_IRQ_TIM16           25
#define STM32_IRQ_TIM17           26
#define STM32_IRQ_TIM1_CC         27
#define STM32_IRQ_TIM2            28
#define STM32_IRQ_TIM3            29
#define STM32_IRQ_TIM4            30
#define STM32_IRQ_I2C1_EV         31
#define STM32_IRQ_I2C1_ER         32
#define STM32_IRQ_I2C2_EV         33
#define STM32_IRQ_I2C2_ER         34
#define STM32_IRQ_SPI1            35
#define STM32_IRQ_SPI2            36
#define STM32_IRQ_USART1          37
#define STM32_IRQ_USART2          38
#define STM32_IRQ_USART3          39
#define STM32_IRQ_EXTI15_10       40
#define STM32_IRQ_RTC_ALARM       41
#define STM32_IRQ_USB_FS_WAKEUP   42
#define STM32_IRQ_TIM8_BREAK      43
#define STM32_IRQ_TIM8_UP         44
#define STM32_IRQ_TIM8_TRG_COM    45
#define STM32_IRQ_TIM8_CC         46
#define STM32_IRQ_LPTIM1          49
#define STM32_IRQ_SPI3            51
#define STM32_IRQ_USART4          52
#define STM32_IRQ_TIM6_DAC        54
#define STM32_IRQ_TIM7            55
#define STM32_IRQ_DMA2_CHANNEL1   56
#define STM32_IRQ_DMA2_CHANNEL2   57
#define STM32_IRQ_DMA2_CHANNEL3   58
#define STM32_IRQ_DMA2_CHANNEL4   59
#define STM32_IRQ_DMA2_CHANNEL5   60
#define STM32_IRQ_UCPD1           63
#define STM32_IRQ_COMP_1_2_3      64
#define STM32_IRQ_COMP_4          65
#define STM32_IRQ_CRS             75
#define STM32_IRQ_SAI1            76
#define STM32_IRQ_FPU             81
#define STM32_IRQ_RNG             90
#define STM32_IRQ_LPUART          91
#define STM32_IRQ_I2C3_EV         92
#define STM32_IRQ_I2C3_ER         93
#define STM32_IRQ_DMAMUX_OVR      94
#define STM32_IRQ_DMA1_CHANNEL8   96
#define STM32_IRQ_DMA2_CHANNEL6   97
#define STM32_IRQ_DMA2_CHANNEL7   98
#define STM32_IRQ_DMA2_CHANNEL8   99
#define STM32_IRQ_CORDIC          100
#define STM32_IRQ_FMAC            101

/* LPUART gets accessed as UART9 in STM32 uart driver */
#define STM32_IRQ_USART9 STM32_IRQ_LPUART

/* To simplify code generation, define DMA channel 13 - 14 */
#define STM32_IRQ_DMA_CHANNEL_13   STM32_IRQ_DMA2_CHANNEL6
#define STM32_IRQ_DMA_CHANNEL_14   STM32_IRQ_DMA2_CHANNEL7

/* aliases for easier code sharing */
#define STM32_IRQ_I2C1 STM32_IRQ_I2C1_EV
#define STM32_IRQ_I2C2 STM32_IRQ_I2C2_EV
#define STM32_IRQ_I2C3 STM32_IRQ_I2C3_EV

#ifdef CHIP_VARIANT_STM32G431
#define CHIP_VARIANT_STM32G431X
#endif

/* Embedded flash option bytes base address */
#define STM32_OPTB_BASE             0x1FFF7800

/* Peripheral base addresses */
#define STM32_PERIPH_BASE           (0x40000000UL)
/* Peripheral memory map */
#define STM32_APB1PERIPH_BASE       (STM32_PERIPH_BASE + 0x00000000UL)
#define STM32_APB2PERIPH_BASE       (STM32_PERIPH_BASE + 0x00010000UL)
#define STM32_AHB1PERIPH_BASE       (STM32_PERIPH_BASE + 0x00020000UL)
#define STM32_AHB2PERIPH_BASE       (STM32_PERIPH_BASE + 0x08000000UL)

/* APB1 peripherals */
#define STM32_APB1PERIPH(offset)    (STM32_APB1PERIPH_BASE + offset)
#define STM32_TIM2_BASE             STM32_APB1PERIPH(0x0000UL)
#define STM32_TIM3_BASE             STM32_APB1PERIPH(0x0400UL)
#define STM32_TIM4_BASE             STM32_APB1PERIPH(0x0800UL)
#define STM32_TIM6_BASE             STM32_APB1PERIPH(0x1000UL)
#define STM32_TIM7_BASE             STM32_APB1PERIPH(0x1400UL)
#define STM32_CRS_BASE              STM32_APB1PERIPH(0x2000UL)
#define STM32_TAMP_BASE             STM32_APB1PERIPH(0x2400UL)
#define STM32_RTC_BASE              STM32_APB1PERIPH(0x2800UL)
#define STM32_WWDG_BASE             STM32_APB1PERIPH(0x2C00UL)
#define STM32_IWDG_BASE             STM32_APB1PERIPH(0x3000UL)
#define STM32_SPI2_BASE             STM32_APB1PERIPH(0x3800UL)
#define STM32_SPI3_BASE             STM32_APB1PERIPH(0x3C00UL)
#define STM32_USART2_BASE           STM32_APB1PERIPH(0x4400UL)
#define STM32_USART3_BASE           STM32_APB1PERIPH(0x4800UL)
#define STM32_UART4_BASE            STM32_APB1PERIPH(0x4C00UL)
#define STM32_I2C1_BASE             STM32_APB1PERIPH(0x5400UL)
#define STM32_I2C2_BASE             STM32_APB1PERIPH(0x5800UL)
/* USB_IP Peripheral Registers base address */
#define STM32_USB_FS_BASE           STM32_APB1PERIPH(0x5C00UL)
/* USB_IP Packet Memory Area base address */
#define STM32_USB_PMAADDR           STM32_APB1PERIPH(0x6000UL)
#define STM32_FDCAN1_BASE           STM32_APB1PERIPH(0x6400UL)
/* FDCAN configuration registers base address */
#define STM32_FDCAN_CONFIG_BASE     STM32_APB1PERIPH(0x6500UL)
#define STM32_PWR_BASE              STM32_APB1PERIPH(0x7000UL)
#define STM32_I2C3_BASE             STM32_APB1PERIPH(0x7800UL)
#define STM32_LPTIM1_BASE           STM32_APB1PERIPH(0x7C00UL)
#define STM32_LPUART1_BASE          STM32_APB1PERIPH(0x8000UL)
#define STM32_I2C4_BASE             STM32_APB1PERIPH(0x8400UL)
/* UART9 is used as link to LPUART in STM32 uart.c implementation */
#define STM32_USART9_BASE           STM32_APB1PERIPH(0x8000UL)
#define STM32_I2C4_BASE             STM32_APB1PERIPH(0x8400UL)
#define STM32_UCPD1_BASE            STM32_APB1PERIPH(0xA000UL)
#define STM32_SRAMCAN_BASE          STM32_APB1PERIPH(0xA400UL)

/* APB2 peripherals */
#define STM32_APB2PERIPH(offset)    (STM32_APB2PERIPH_BASE + offset)
#define STM32_SYSCFG_BASE           STM32_APB2PERIPH(0x0000UL)
#define STM32_VREFBUF_BASE          STM32_APB2PERIPH(0x0030UL)
#define STM32_COMP1_BASE            STM32_APB2PERIPH(0x0200UL)
#define STM32_COMP2_BASE            STM32_APB2PERIPH(0x0204UL)
#define STM32_COMP3_BASE            STM32_APB2PERIPH(0x0208UL)
#define STM32_COMP4_BASE            STM32_APB2PERIPH(0x020CUL)
#define STM32_OPAMP_BASE            STM32_APB2PERIPH(0x0300UL)
#define STM32_OPAMP1_BASE           STM32_APB2PERIPH(0x0300UL)
#define STM32_OPAMP2_BASE           STM32_APB2PERIPH(0x0304UL)
#define STM32_OPAMP3_BASE           STM32_APB2PERIPH(0x0308UL)
#define STM32_EXTI_BASE             STM32_APB2PERIPH(0x0400UL)
#define STM32_TIM1_BASE             STM32_APB2PERIPH(0x2C00UL)
#define STM32_SPI1_BASE             STM32_APB2PERIPH(0x3000UL)
#define STM32_TIM8_BASE             STM32_APB2PERIPH(0x3400UL)
#define STM32_USART1_BASE           STM32_APB2PERIPH(0x3800UL)
#define STM32_TIM15_BASE            STM32_APB2PERIPH(0x4000UL)
#define STM32_TIM16_BASE            STM32_APB2PERIPH(0x4400UL)
#define STM32_TIM17_BASE            STM32_APB2PERIPH(0x4800UL)
#define STM32_SAI1_BASE             STM32_APB2PERIPH(0x5400UL)
#define STM32_SAI1_Block_A_BASE     (SAI1_BASE + 0x0004UL)
#define STM32_SAI1_Block_B_BASE     (SAI1_BASE + 0x0024UL)

/* AHB1 peripherals */
#define STM32_AHB1PERIPH(offset)    (STM32_AHB1PERIPH_BASE + offset)
#define STM32_DMA1_BASE             STM32_AHB1PERIPH(0x0000UL)
#define STM32_DMA2_BASE             STM32_AHB1PERIPH(0x0400UL)
#define STM32_DMAMUX_BASE           STM32_AHB1PERIPH(0x0800UL)
#define STM32_CORDIC_BASE           STM32_AHB1PERIPH(0x0C00UL)
#define STM32_RCC_BASE              STM32_AHB1PERIPH(0x1000UL)
#define STM32_FMAC_BASE             STM32_AHB1PERIPH(0x1400UL)
#define STM32_FLASH_REGS_BASE       STM32_AHB1PERIPH(0x2000UL)
#define STM32_CRC_BASE              STM32_AHB1PERIPH(0x3000UL)

#define STM32_DMA1_CHAN(offset)     (STM32_DMA1_BASE + offset)
#define STM32_DMA1_Channel1_BASE    STM32_DMA1_CHAN(0x0008UL)
#define STM32_DMA1_Channel2_BASE    STM32_DMA1_CHAN(0x001CUL)
#define STM32_DMA1_Channel3_BASE    STM32_DMA1_CHAN(0x0030UL)
#define STM32_DMA1_Channel4_BASE    STM32_DMA1_CHAN(0x0044UL)
#define STM32_DMA1_Channel5_BASE    STM32_DMA1_CHAN(0x0058UL)
#define STM32_DMA1_Channel6_BASE    STM32_DMA1_CHAN(0x006CUL)

#define STM32_DMA2_CHAN(offset)     (STM32_DMA2_BASE + offset)
#define STM32_DMA2_Channel1_BASE    STM32_DMA2_CHAN(0x0008UL)
#define STM32_DMA2_Channel2_BASE    STM32_DMA2_CHAN(0x001CUL)
#define STM32_DMA2_Channel3_BASE    STM32_DMA2_CHAN(0x0030UL)
#define STM32_DMA2_Channel4_BASE    STM32_DMA2_CHAN(0x0044UL)
#define STM32_DMA2_Channel5_BASE    STM32_DMA2_CHAN(0x0058UL)
#define STM32_DMA2_Channel6_BASE    STM32_DMA2_CHAN(0x006CUL)

#define STM32_DMAMUX(offset)          (STM32_DMAMUX_BASE + offset)
#define STM32_DMAMUX_Channel0_BASE    STM32_DMAMUX(0x0000UL)
#define STM32_DMAMUX_Channel1_BASE    STM32_DMAMUX(0x0004UL)
#define STM32_DMAMUX_Channel2_BASE    STM32_DMAMUX(0x0008UL)
#define STM32_DMAMUX_Channel3_BASE    STM32_DMAMUX(0x000CUL)
#define STM32_DMAMUX_Channel4_BASE    STM32_DMAMUX(0x0010UL)
#define STM32_DMAMUX_Channel5_BASE    STM32_DMAMUX(0x0014UL)
#define STM32_DMAMUX_Channel6_BASE    STM32_DMAMUX(0x0020UL)
#define STM32_DMAMUX_Channel7_BASE    STM32_DMAMUX(0x0024UL)
#define STM32_DMAMUX_Channel8_BASE    STM32_DMAMUX(0x0028UL)
#define STM32_DMAMUX_Channel9_BASE    STM32_DMAMUX(0x002CUL)
#define STM32_DMAMUX_Channel10_BASE   STM32_DMAMUX(0x0030UL)
#define STM32_DMAMUX_Channel11_BASE   STM32_DMAMUX(0x0034UL)
#define STM32_DMAMUX_RequestGenerator0_BASE  STM32_DMAMUX(0x0100UL)
#define STM32_DMAMUX_RequestGenerator1_BASE  STM32_DMAMUX(0x0104UL)
#define STM32_DMAMUX_RequestGenerator2_BASE  STM32_DMAMUX(0x0108UL)
#define STM32_DMAMUX_RequestGenerator3_BASE  STM32_DMAMUX(0x010CUL)
#define STM32_DMAMUX_ChannelStatus_BASE      STM32_DMAMUX(0x0080UL)
#define STM32_DMAMUX_RequestGenStatus_BASE   STM32_DMAMUX(0x0140UL)

/* AHB2 peripherals */
#define STM32_AHB2PERIPH(offset)    (STM32_AHB2PERIPH_BASE + offset)
#define STM32_GPIOA_BASE            STM32_AHB2PERIPH(0x0000UL)
#define STM32_GPIOB_BASE            STM32_AHB2PERIPH(0x0400UL)
#define STM32_GPIOC_BASE            STM32_AHB2PERIPH(0x0800UL)
#define STM32_GPIOD_BASE            STM32_AHB2PERIPH(0x0C00UL)
#define STM32_GPIOE_BASE            STM32_AHB2PERIPH(0x1000UL)
#define STM32_GPIOF_BASE            STM32_AHB2PERIPH(0x1400UL)
#define STM32_GPIOG_BASE            STM32_AHB2PERIPH(0x1800UL)
#define STM32_ADC1_BASE             STM32_AHB2PERIPH(0x08000000UL)
#define STM32_ADC2_BASE             STM32_AHB2PERIPH(0x08000100UL)
#define STM32_ADC12_COMMON_BASE     STM32_AHB2PERIPH(0x08000300UL)
#define STM32_DAC_BASE              STM32_AHB2PERIPH(0x08000800UL)
#define STM32_DAC1_BASE             STM32_AHB2PERIPH(0x08000800UL)
#define STM32_DAC3_BASE             STM32_AHB2PERIPH(0x08001000UL)
#define STM32_RNG_BASE              STM32_AHB2PERIPH(0x08060800UL)

#define STM32_UNIQUE_ID_BASE        0x1FFF7590
#define STM32_DBGMCU_BASE           0xE0042000

#ifndef __ASSEMBLER__

/* Register definitions */

/* --- UCPD --- */
#define STM32_UCPD_REG(port, offset) \
	REG32(((STM32_UCPD1_BASE + ((port) * 0x400)) + (offset)))

#define STM32_UCPD_CFGR1(port)              STM32_UCPD_REG(port, 0x00)
#define STM32_UCPD_CFGR2(port)              STM32_UCPD_REG(port, 0x04)
#define STM32_UCPD_CR(port)                 STM32_UCPD_REG(port, 0x0c)
#define STM32_UCPD_IMR(port)                STM32_UCPD_REG(port, 0x10)
#define STM32_UCPD_SR(port)                 STM32_UCPD_REG(port, 0x14)
#define STM32_UCPD_ICR(port)                STM32_UCPD_REG(port, 0x18)
#define STM32_UCPD_TX_ORDSETR(port)         STM32_UCPD_REG(port, 0x1c)
#define STM32_UCPD_TX_PAYSZR(port)          STM32_UCPD_REG(port, 0x20)
#define STM32_UCPD_TXDR(port)               STM32_UCPD_REG(port, 0x24)
#define STM32_UCPD_RX_ORDSETR(port)         STM32_UCPD_REG(port, 0x28)
#define STM32_UCPD_RX_PAYSZR(port)          STM32_UCPD_REG(port, 0x2c)
#define STM32_UCPD_RXDR(port)               STM32_UCPD_REG(port, 0x30)
#define STM32_UCPD_RX_ORDEXTR1(port)        STM32_UCPD_REG(port, 0x34)
#define STM32_UCPD_RX_ORDEXTR2(port)        STM32_UCPD_REG(port, 0x38)

/* --- UCPD CFGR1 Bit Definitions --- */
#define STM32_UCPD_CFGR1_HBITCLKD_SHIFT     0
#define STM32_UCPD_CFGR1_HBITCLKD_MASK      ((0x3f) << \
					     (STM32_UCPD_CFGR1_HBITCLKD_SHIFT))
#define STM32_UCPD_CFGR1_HBITCLKD_VAL(x)    ((x) << \
					     STM32_UCPD_CFGR1_HBITCLKD_SHIFT)
#define STM32_UCPD_CFGR1_IFRGAP_SHIFT       6
#define STM32_UCPD_CFGR1_IFRGAP_MASK        ((0x1f) << \
					     (STM32_UCPD_CFGR1_IFRGAP_SHIFT))
#define STM32_UCPD_CFGR1_IFRGAP_VAL(x)      ((x) << \
					     STM32_UCPD_CFGR1_IFRGAP_SHIFT)
#define STM32_UCPD_CFGR1_TRANSWIN_SHIFT     11
#define STM32_UCPD_CFGR1_TRANSWIN_MASK      ((0x1f) << \
					     (STM32_UCPD_CFGR1_TRANSWIN_SHIFT))
#define STM32_UCPD_CFGR1_TRANSWIN_VAL(x)    ((x) << \
					     STM32_UCPD_CFGR1_TRANSWIN_SHIFT)
#define STM32_UCPD_CFGR1_PSC_CLK_SHIFT      17
#define STM32_UCPD_CFGR1_PSC_CLK_MASK       ((0x7) << \
					     STM32_UCPD_CFGR1_PSC_CLK_SHIFT)
#define STM32_UCPD_CFGR1_PSC_CLK_VAL(x)     ((x) << \
					     STM32_UCPD_CFGR1_PSC_CLK_SHIFT)
#define STM32_UCPD_CFGR1_RXORDSETEN_SHIFT   20
#define STM32_UCPD_CFGR1_RXORDSETEN_MASK    ((0x1ff) << \
					     STM32_UCPD_CFGR1_RXORDSETEN_SHIFT)
#define STM32_UCPD_CFGR1_RXORDSETEN_VAL(x)  ((x) << \
					     STM32_UCPD_CFGR1_RXORDSETEN_SHIFT)
#define STM32_UCPD_CFGR1_TXDMAEN            BIT(29)
#define STM32_UCPD_CFGR1_RXDMAEN            BIT(30)
#define STM32_UCPD_CFGR1_UCPDEN             BIT(31)

/* --- UCPD CFGR2 Bit Definitions --- */
#define STM32_UCPD_CFGR2_RXFILTDIS          BIT(0)
#define STM32_UCPD_CFGR2_RXFILT2N3          BIT(1)
#define STM32_UCPD_CFGR2_FORCECLK           BIT(2)
#define STM32_UCPD_CFGR2_WUPEN              BIT(3)

/* --- UCPD CR Bit Definitions --- */
#define STM32_UCPD_CR_TXMODE_SHIFT          0
#define STM32_UCPD_CR_TXMODE_MASK           ((0x3) << \
					     (STM32_UCPD_CR_TXMODE_SHIFT))
#define STM32_UCPD_CR_TXMODE_VAL(x)         ((x) << STM32_UCPD_CR_TXMODE_SHIFT)
#define STM32_UCPD_CR_TXSEND                BIT(2)
#define STM32_UCPD_CR_TXHRST                BIT(3)
#define STM32_UCPD_CR_RXMODE                BIT(4)
#define STM32_UCPD_CR_PHYRXEN               BIT(5)
#define STM32_UCPD_CR_PHYCCSEL              BIT(6)
#define STM32_UCPD_CR_ANASUBMODE_SHIFT      7
#define STM32_UCPD_CR_ANASUBMODE_MASK       ((0x3) << \
					     (STM32_UCPD_CR_ANASUBMODE_SHIFT))
#define STM32_UCPD_CR_ANASUBMODE_VAL(x)     ((x) << \
					     STM32_UCPD_CR_ANASUBMODE_SHIFT)
#define STM32_UCPD_CR_ANAMODE               BIT(9)
#define STM32_UCPD_CR_CCENABLE_SHIFT        10
#define STM32_UCPD_CR_CCENABLE_MASK         ((0x3) << \
					     (STM32_UCPD_CR_CCENABLE_SHIFT))
#define STM32_UCPD_CR_CCENABLE_VAL(x)       ((x) << \
					     STM32_UCPD_CR_CCENABLE_SHIFT)
#define STM32_UCPD_CR_FRSRXEN               BIT(16)
#define STM32_UCPD_CR_FRSTX                 BIT(17)
#define STM32_UCPD_CR_RDCH                  BIT(18)
#define STM32_UCPD_CR_CC1TCDIS              BIT(20)
#define STM32_UCPD_CR_CC2TCDIS              BIT(21)

/* TX mode message types */
#define STM32_UCPD_CR_TXMODE_DEF            0
#define STM32_UCPD_CR_TXMODE_CBL_RST        1
#define STM32_UCPD_CR_TXMODE_BIST           2

/* --- UCPD IMR Bit Definitions --- */
#define STM32_UCPD_IMR_TXISIE               BIT(0)
#define STM32_UCPD_IMR_TXMSGDISCIE          BIT(1)
#define STM32_UCPD_IMR_TXMSGSENTIE          BIT(2)
#define STM32_UCPD_IMR_TXMSGABTIE           BIT(3)
#define STM32_UCPD_IMR_HRSTDISCIE           BIT(4)
#define STM32_UCPD_IMR_HRSTSENTIE           BIT(5)
#define STM32_UCPD_IMR_TXUNDIE              BIT(6)
#define STM32_UCPD_IMR_RXNEIE               BIT(8)
#define STM32_UCPD_IMR_RXORDDETIE           BIT(9)
#define STM32_UCPD_IMR_RXHRSTDETIE          BIT(10)
#define STM32_UCPD_IMR_RXOVRIE              BIT(11)
#define STM32_UCPD_IMR_RXMSGENDIE           BIT(12)
#define STM32_UCPD_IMR_TYPECEVT1IE          BIT(14)
#define STM32_UCPD_IMR_TYPECEVT2IE          BIT(15)
#define STM32_UCPD_IMR_FRSEVTIE             BIT(20)

/* --- UCPD SR Bit Definitions --- */
#define STM32_UCPD_SR_TXIS                  BIT(0)
#define STM32_UCPD_SR_TXMSGDISC             BIT(1)
#define STM32_UCPD_SR_TXMSGSENT             BIT(2)
#define STM32_UCPD_SR_TXMSGABT              BIT(3)
#define STM32_UCPD_SR_HRSTDISC              BIT(4)
#define STM32_UCPD_SR_HRSTSENT              BIT(5)
#define STM32_UCPD_SR_TXUND                 BIT(6)
#define STM32_UCPD_SR_RXNE                  BIT(8)
#define STM32_UCPD_SR_RXORDDET              BIT(9)
#define STM32_UCPD_SR_RXHRSTDET             BIT(10)
#define STM32_UCPD_SR_RXOVR                 BIT(11)
#define STM32_UCPD_SR_RXMSGEND              BIT(12)
#define STM32_UCPD_SR_RXERR                 BIT(13)
#define STM32_UCPD_SR_TYPECEVT1             BIT(14)
#define STM32_UCPD_SR_TYPECEVT2             BIT(15)
#define STM32_UCPD_SR_VSTATE_CC1_SHIFT      16
#define STM32_UCPD_SR_VSTATE_CC1_MASK       ((0x3) << \
					       (STM32_UCPD_SR_VSTATE_CC1_SHIFT))
#define STM32_UCPD_SR_VSTATE_CC1_VAL(x)     ((x) << \
					     STM32_UCPD_SR_VSTATE_CC1_SHIFT)
#define STM32_UCPD_SR_VSTATE_CC2_SHIFT      18
#define STM32_UCPD_SR_VSTATE_CC2_MASK       ((0x3) << \
					     (STM32_UCPD_SR_VSTATE_CC2_SHIFT))
#define STM32_UCPD_SR_VSTATE_CC2_VAL(x)     ((x) << \
					     STM32_UCPD_SR_VSTATE_CC2_SHIFT)
#define STM32_UCPD_SR_FRSEVT                BIT(20)

#define STM32_UCPD_SR_VSTATE_OPEN           3
#define STM32_UCPD_SR_VSTATE_RA             0

/* --- UCPD ICR Bit Definitions --- */
#define STM32_UCPD_ICR_TXMSGDISCCF          BIT(1)
#define STM32_UCPD_ICR_TXMSGSENTCF          BIT(2)
#define STM32_UCPD_ICR_TXMSGABTCF           BIT(3)
#define STM32_UCPD_ICR_HRSTDISCCF           BIT(4)
#define STM32_UCPD_ICR_HRSTSENTCF           BIT(5)
#define STM32_UCPD_ICR_TXUNDCF              BIT(6)
#define STM32_UCPD_ICR_RXORDDETCF           BIT(9)
#define STM32_UCPD_ICR_RXHRSTDETCF          BIT(10)
#define STM32_UCPD_ICR_RXOVRCF              BIT(11)
#define STM32_UCPD_ICR_RXMSGENDCF           BIT(12)
#define STM32_UCPD_ICR_TYPECEVT1CF          BIT(14)
#define STM32_UCPD_ICR_TYPECEVT2CF          BIT(15)
#define STM32_UCPD_ICR_FRSEVTCF             BIT(20)


/* --- UCPD TX_ORDSETR Bit Definitions --- */
#define STM32_UCPD_TX_ORDSETR_SHIFT        0
#define STM32_UCPD_TX_ORDSETR_MASK         ((0xfffff) << \
					    (STM32_UCPD_TX_ORDSETR_SHIFT))
#define STM32_UCPD_TX_ORDSETR_VAL(x)       ((x) << STM32_UCPD_TX_ORDSETR_SHIFT)

/* --- UCPD TX_PAYSZR Bit Definitions --- */
#define STM32_UCPD_TX_PAYSZR_SHIFT        0
#define STM32_UCPD_TX_PAYSZR_MASK         ((0x3ff) << \
					   (STM32_UCPD_TX_PAYSZR_SHIFT))
#define STM32_UCPD_TX_PAYSZR_VAL(x)       ((x) << STM32_UCPD_TX_PAYSZR_SHIFT)

/* --- UCPD TXDR Bit Definitions --- */
#define STM32_UCPD_TXDR_SHIFT             0
#define STM32_UCPD_TXDR_MASK              ((0xff) << \
					   (STM32_UCPD_TXDR_SHIFT))
#define STM32_UCPD_TXDR_VAL(x)            ((x) << STM32_UCPD_TXDR_SHIFT)

/* --- UCPD RX_ORDSETR Bit Definitions --- */
#define STM32_UCPD_RXORDSETR_SHIFT        0
#define STM32_UCPD_RXORDSETR_MASK         ((0x7) << \
					   (STM32_UCPD_RXORDSETR_SHIFT))
#define STM32_UCPD_RXORDSETR_VAL(x)       ((x) << STM32_UCPD_RXORDSETR_SHIFT)
#define STM32_UCPD_RXSOP3OF4              BIT(3)
#define STM32_UCPD_RXSOPKINVALID_SHIFT    4
#define STM32_UCPD_RXSOPKINVALID_MASK     ((0x7) << \
					   (STM32_UCPD_RXSOPKINVALID_SHIFT))
#define STM32_UCPD_RXSOPKINVALID_VAL(x)   ((x) << \
					   STM32_UCPD_RXSOPKINVALID_SHIFT)

/* --- UCPD RX_PAYSZR Bit Definitions --- */
#define STM32_UCPD_RX_PAYSZR_SHIFT        0
#define STM32_UCPD_RX_PAYSZR_MASK         ((0x3ff) << \
					   (STM32_UCPD_RX_PAYSZR_SHIFT))
#define STM32_UCPD_RX_PAYSZR_VAL(x)       ((x) << STM32_UCPD_RX_PAYSZR_SHIFT)

/* --- UCPD TXDR Bit Definitions --- */
#define STM32_UCPD_RXDR_SHIFT             0
#define STM32_UCPD_RXDR_MASK              ((0xff) << \
					   (STM32_UCPD_RXDR_SHIFT))
#define STM32_UCPD_RXDR_VAL(x)            ((x) << STM32_UCPD_RXDR_SHIFT)


/* --- USART --- */
#define STM32_USART_CR1(base)      STM32_USART_REG(base, 0x00)
#define STM32_USART_CR2(base)      STM32_USART_REG(base, 0x04)
#define STM32_USART_CR3(base)      STM32_USART_REG(base, 0x08)
#define STM32_USART_BRR(base)      STM32_USART_REG(base, 0x0C)
#define STM32_USART_GTPR(base)     STM32_USART_REG(base, 0x10)
#define STM32_USART_SR(base)       STM32_USART_REG(base, 0x1C)
#define STM32_USART_RDR(base)      STM32_USART_REG(base, 0x24)
#define STM32_USART_TDR(base)      STM32_USART_REG(base, 0x28)

/* --- USART bit definitions -- */
#define STM32_USART_SR_ORE		BIT(3)
#define STM32_USART_SR_RXNE		BIT(5)
#define STM32_USART_SR_TC		BIT(6)
#define STM32_USART_SR_TXE		BIT(7)

#define STM32_USART_CR1_UE		BIT(0)
#define STM32_USART_CR1_RE		BIT(2)
#define STM32_USART_CR1_TE		BIT(3)
#define STM32_USART_CR1_RXNEIE		BIT(5)
#define STM32_USART_CR1_TCIE		BIT(6)
#define STM32_USART_CR1_TXEIE		BIT(7)
#define STM32_USART_CR1_PS		BIT(9)
#define STM32_USART_CR1_PCE		BIT(10)
#define STM32_USART_CR1_M		BIT(12)
#define STM32_USART_CR1_OVER8		BIT(15)

#define STM32_USART_CR3_EIE		BIT(0)
#define STM32_USART_CR3_DMAR		BIT(6)
#define STM32_USART_CR3_DMAT		BIT(7)
#define STM32_USART_CR3_ONEBIT		BIT(11)


/* --- GPIO --- */
#define STM32_GPIO_MODER(b)     REG32((b) + 0x00)
#define STM32_GPIO_OTYPER(b)    REG16((b) + 0x04)
#define STM32_GPIO_OSPEEDR(b)   REG32((b) + 0x08)
#define STM32_GPIO_PUPDR(b)     REG32((b) + 0x0C)
#define STM32_GPIO_IDR(b)       REG16((b) + 0x10)
#define STM32_GPIO_ODR(b)       REG16((b) + 0x14)
#define STM32_GPIO_BSRR(b)      REG32((b) + 0x18)
#define STM32_GPIO_LCKR(b)      REG32((b) + 0x1C)
#define STM32_GPIO_AFRL(b)      REG32((b) + 0x20)
#define STM32_GPIO_AFRH(b)      REG32((b) + 0x24)

#define GPIO_ALT_SYS                 0x0
#define GPIO_ALT_TIM2                0x1
#define GPIO_ALT_I2C3                0x2
#define GPIO_ALT_TIM9_11             0x3
#define GPIO_ALT_I2C                 0x4
#define GPIO_ALT_SPI                 0x5
#define GPIO_ALT_SPI3                0x6
#define GPIO_ALT_USART               0x7
#define GPIO_ALT_I2C_23              0x9
#define GPIO_ALT_USB                 0xA
#define GPIO_ALT_LCD                 0xB
#define GPIO_ALT_LPUART              0xC
#define GPIO_ALT_SAI1                0xD
#define GPIO_ALT_RI                  0xE
#define GPIO_ALT_EVENTOUT            0xF

/* --- I2C --- */
#define stm32g4_i2c_reg(base, offset) ((uint16_t *)((base) + (offset)))

#define STM32_I2C_CR1(base)            REG32(stm32g4_i2c_reg(base, 0x00))
#define STM32_I2C_CR2(base)            REG32(stm32g4_i2c_reg(base, 0x04))
#define STM32_I2C_OAR1(base)           REG16(stm32g4_i2c_reg(base, 0x08))
#define STM32_I2C_OAR2(base)           REG16(stm32g4_i2c_reg(base, 0x0C))
#define STM32_I2C_TIMINGR(base)        REG32(stm32g4_i2c_reg(base, 0x10))
#define STM32_I2C_TIMEOUTR(base)       REG32(stm32g4_i2c_reg(base, 0x14))
#define STM32_I2C_ISR(base)            REG32(stm32g4_i2c_reg(base, 0x18))
#define STM32_I2C_ICR(base)            REG32(stm32g4_i2c_reg(base, 0x1C))
#define STM32_I2C_PECR(base)           REG32(stm32g4_i2c_reg(base, 0x20))
#define STM32_I2C_RXDR(base)           REG32(stm32g4_i2c_reg(base, 0x24))
#define STM32_I2C_TXDR(base)           REG32(stm32g4_i2c_reg(base, 0x28))

/* --- I2C CR1 Bit Definitions --- */
#define STM32_I2C_CR1_PE            BIT(0)
#define STM32_I2C_CR1_TXIE          BIT(1)
#define STM32_I2C_CR1_RXIE          BIT(2)
#define STM32_I2C_CR1_ADDRIE        BIT(3)
#define STM32_I2C_CR1_NACKIE        BIT(4)
#define STM32_I2C_CR1_STOPIE        BIT(5)
#define STM32_I2C_CR1_ERRIE         BIT(7)
#define STM32_I2C_CR1_WUPEN         BIT(18)

/* --- I2C CR2 Bit Definitions --- */
#define STM32_I2C_CR2_RD_WRN        BIT(10)
#define STM32_I2C_CR2_START         BIT(13)
#define STM32_I2C_CR2_STOP          BIT(14)
#define STM32_I2C_CR2_NACK          BIT(15)
#define STM32_I2C_CR2_RELOAD        BIT(24)
#define STM32_I2C_CR2_AUTOEND       BIT(25)

/* --- I2C ISR Bit Definitions --- */
#define STM32_I2C_ISR_TXE           BIT(0)
#define STM32_I2C_ISR_TXIS          BIT(1)
#define STM32_I2C_ISR_RXNE          BIT(2)
#define STM32_I2C_ISR_ADDR          BIT(3)
#define STM32_I2C_ISR_NACK          BIT(4)
#define STM32_I2C_ISR_STOP          BIT(5)
#define STM32_I2C_ISR_TC            BIT(6)
#define STM32_I2C_ISR_TCR           BIT(7)
#define STM32_I2C_ISR_BERR          BIT(8)
#define STM32_I2C_ISR_ARLO          BIT(9)
#define STM32_I2C_ISR_OVR           BIT(10)
#define STM32_I2C_ISR_PECERR        BIT(11)
#define STM32_I2C_ISR_TIMEOUT       BIT(12)
#define STM32_I2C_ISR_ALERT         BIT(13)
#define STM32_I2C_ISR_BUSY          BIT(15)
#define STM32_I2C_ISR_DIR           BIT(16)

/* --- I2C ICR Bit Definitions --- */
#define STM32_I2C_ICR_ADDRCF        BIT(3)
#define STM32_I2C_ICR_NACKCF        BIT(4)
#define STM32_I2C_ICR_STOPCF        BIT(5)
#define STM32_I2C_ICR_BERRCF        BIT(8)
#define STM32_I2C_ICR_ARLOCF        BIT(9)
#define STM32_I2C_ICR_OVRCF         BIT(10)
#define STM32_I2C_ICR_TIMEOUTCF     BIT(12)
#define STM32_I2C_ICR_ALL           0x3F38

/* --- I2C TIMINGR bit Definitions --- */
#define STM32_I2C_TIMINGR_SCLL_OFF 0
#define STM32_I2C_TIMINGR_SCLH_OFF 8
#define STM32_I2C_TIMINGR_SDADEL_OFF 16
#define STM32_I2C_TIMINGR_SCLDEL_OFF 20
#define STM32_I2C_TIMINGR_PRESC_OFF 28

/* --- Power / Reset / Clocks --- */

#define STM32_RCC_CR                    REG32(STM32_RCC_BASE + 0x00)
#define STM32_RCC_ICSCR                 REG32(STM32_RCC_BASE + 0x04)
#define STM32_RCC_CFGR                  REG32(STM32_RCC_BASE + 0x08)
#define STM32_RCC_PLLCFGR               REG32(STM32_RCC_BASE + 0x0C)
#define STM32_RCC_CIER                  REG32(STM32_RCC_BASE + 0x18)
#define STM32_RCC_CIFR                  REG32(STM32_RCC_BASE + 0x1C)
#define STM32_RCC_CICR                  REG32(STM32_RCC_BASE + 0x20)
#define STM32_RCC_AHB1RSTR              REG32(STM32_RCC_BASE + 0x28)
#define STM32_RCC_AHB2RSTR              REG32(STM32_RCC_BASE + 0x2C)
#define STM32_RCC_AHB3RSTR              REG32(STM32_RCC_BASE + 0x30)
#define STM32_RCC_APB1RSTR1             REG32(STM32_RCC_BASE + 0x38)
#define STM32_RCC_APB1RSTR2             REG32(STM32_RCC_BASE + 0x3C)
#define STM32_RCC_APB2RSTR              REG32(STM32_RCC_BASE + 0x40)
#define STM32_RCC_AHB1ENR               REG32(STM32_RCC_BASE + 0x48)
#define STM32_RCC_AHB2ENR               REG32(STM32_RCC_BASE + 0x4C)
#define STM32_RCC_AHB3ENR               REG32(STM32_RCC_BASE + 0x50)
#define STM32_RCC_APB1ENR1              REG32(STM32_RCC_BASE + 0x58)
#define STM32_RCC_APB1ENR2              REG32(STM32_RCC_BASE + 0x5C)
#define STM32_RCC_APB2ENR               REG32(STM32_RCC_BASE + 0x60)
#define STM32_RCC_AHB1SMENR             REG32(STM32_RCC_BASE + 0x68)
#define STM32_RCC_AHB2SMENR             REG32(STM32_RCC_BASE + 0x6C)
#define STM32_RCC_AHB3SMENR             REG32(STM32_RCC_BASE + 0x70)
#define STM32_RCC_APB1SMENR1            REG32(STM32_RCC_BASE + 0x78)
#define STM32_RCC_APB1SMENR2            REG32(STM32_RCC_BASE + 0x7C)
#define STM32_RCC_APB2SMENR             REG32(STM32_RCC_BASE + 0x80)
#define STM32_RCC_CCIPR                 REG32(STM32_RCC_BASE + 0x88)
#define STM32_RCC_BDCR                  REG32(STM32_RCC_BASE + 0x90)
#define STM32_RCC_CSR                   REG32(STM32_RCC_BASE + 0x94)
#define STM32_RCC_CRRCR                 REG32(STM32_RCC_BASE + 0x98)
#define STM32_RCC_CCIPR2                REG32(STM32_RCC_BASE + 0x9C)

#define STM32_RCC_APB1ENR STM32_RCC_APB1ENR1
#define STM32_RCC_AHBENR STM32_RCC_APB1ENR

/* --- RCC CR Bit Definitions --- */
#define STM32_RCC_CR_HSION		BIT(8)
#define STM32_RCC_CR_HSIRDY		BIT(10)
#define STM32_RCC_CR_HSEON		BIT(16)
#define STM32_RCC_CR_HSERDY		BIT(17)
#define STM32_RCC_CR_PLLON		BIT(24)
#define STM32_RCC_CR_PLLRDY		BIT(25)

/* --- RCC PLLCFGR Bit Definitions --- */
#define  PLLCFGR_PLLSRC_OFF		0
#define  PLLCFGR_PLLSRC(val)		(((val) & 0x3) << PLLCFGR_PLLSRC_OFF)
#define  PLLCFGR_PLLSRC_HSI		2
#define  PLLCFGR_PLLSRC_HSE		3
/* PLL Division factor */
#define  PLLCFGR_PLLM_OFF		4
#define  PLLCFGR_PLLM(val)		(((val) & 0x1f) << PLLCFGR_PLLM_OFF)
/* PLL Multiplication factor */
#define  PLLCFGR_PLLN_OFF		8
#define  PLLCFGR_PLLN(val)		(((val) & 0x7f) << PLLCFGR_PLLN_OFF)
#define  PLLCFGR_PLLQ_EN		BIT(20)
#define  PLLCFGR_PLLQ_OFF		21
#define  PLLCFGR_PLLQ(val)		(((val) & 0x3) << PLLCFGR_PLLQ_OFF)
/* System and main CPU clock */
#define  PLLCFGR_PLLR_EN		BIT(24)
#define  PLLCFGR_PLLR_OFF		25
#define  PLLCFGR_PLLR(val)		(((val) & 0x3) << PLLCFGR_PLLR_OFF)
#define  PLLCFGR_PLLP_OFF		27
#define  PLLCFGR_PLLP(val)		(((val) & 0x1f) << PLLCFGR_PLLP_OFF)

/* --- RCC CFGR Bit Definitions --- */
#define STM32_RCC_CFGR_SW_HSI		(1 << 0)
#define STM32_RCC_CFGR_SW_HSE		(2 << 0)
#define STM32_RCC_CFGR_SW_PLL		(3 << 0)
#define STM32_RCC_CFGR_SW_MASK		(3 << 0)
#define STM32_RCC_CFGR_SWS_HSI		(1 << 2)
#define STM32_RCC_CFGR_SWS_HSE		(2 << 2)
#define STM32_RCC_CFGR_SWS_PLL		(3 << 2)
#define STM32_RCC_CFGR_SWS_MASK		(3 << 2)
/* AHB Prescalar: */
#define  CFGR_HPRE_OFF			4
#define  CFGR_HPRE(val)			(((val) & 0xf) << CFGR_HPRE_OFF)
/* APB1 Low Speed Prescalar < 45MHz */
#define  CFGR_PPRE1_OFF			8
#define  CFGR_PPRE1(val)		(((val) & 0x7) << CFGR_PPRE1_OFF)
/* APB2 High Speed Prescalar < 90MHz */
#define  CFGR_PPRE2_OFF			11
#define  CFGR_PPRE2(val)		(((val) & 0x7) << CFGR_PPRE2_OFF)
/* RTC CLock: Must equal 1MHz */
#define  CFGR_RTCPRE_OFF		16
#define  CFGR_RTCPRE(val)		(((val) & 0x1f) << CFGR_RTCPRE_OFF)

/* --- RCC AHB1ENR Bit Definitions --- */
#define STM32_RCC_AHB1ENR_DMA1EN	BIT(0)
#define STM32_RCC_AHB1ENR_DMA2EN	BIT(1)
#define STM32_RCC_AHB1ENR_DMAMUXEN	BIT(2)

/* --- RCC AHB2ENR Bit Definitions --- */
#define STM32_RCC_AHB2ENR_GPIO_PORTA	BIT(0)
#define STM32_RCC_AHB2ENR_GPIO_PORTB	BIT(1)
#define STM32_RCC_AHB2ENR_GPIO_PORTC	BIT(2)
#define STM32_RCC_AHB2ENR_GPIO_PORTD	BIT(3)
#define STM32_RCC_AHB2ENR_GPIO_PORTE	BIT(4)
#define STM32_RCC_AHB2ENR_GPIO_PORTF	BIT(5)
#define STM32_RCC_AHB2ENR_GPIO_PORTG	BIT(6)
#define STM32_RCC_AHB2ENR_GPIOMASK	(0x7f << 0)
#define STM32_RCC_AHB2ENR_ADC12EN	BIT(13)
#define STM32_RCC_APB2ENR_ADC345EN	BIT(14)
#define STM32_RCC_AHB2ENR_RNGEN		BIT(26)

/* --- RCC APB1ENR1 Bit Definitions --- */
#define STM32_RCC_APB1ENR1_TIM2EN                BIT(0)
#define STM32_RCC_APB1ENR1_TIM3EN                BIT(1)
#define STM32_RCC_APB1ENR1_TIM4EN                BIT(2)
#define STM32_RCC_APB1ENR1_TIM5EN                BIT(3)
#define STM32_RCC_APB1ENR1_TIM6EN                BIT(4)
#define STM32_RCC_APB1ENR1_TIM7EN                BIT(5)
#define STM32_RCC_APB1ENR1_WWDGEN                BIT(11)
#define STM32_RCC_APB1ENR1_USART2                BIT(17)
#define STM32_RCC_APB1ENR1_USART3                BIT(18)
#define STM32_RCC_APB1ENR1_UART4                 BIT(19)
#define STM32_RCC_APB1ENR1_UART5                 BIT(20)
#define STM32_RCC_APB1ENR1_I2C1EN                BIT(21)
#define STM32_RCC_APB1ENR1_I2C2EN                BIT(22)
#define STM32_RCC_APB1ENR1_USBEN                 BIT(23)
#define STM32_RCC_APB1ENR1_PWREN                 BIT(28)
#define STM32_RCC_APB1ENR1_I2C3EN                BIT(30)

#define STM32_RCC_PWREN STM32_RCC_APB1ENR1_PWREN

/* --- RCC APB1ENR2 Bit Definitions --- */
#define STM32_RCC_APB1ENR2_LPUART1EN             BIT(0)
#define STM32_RCC_APB1ENR2_I2C4EN                BIT(1)
#define STM32_RCC_APB1ENR2_UPCD1EN               BIT(8)

/* --- RCC APB2ENR Bit Definitions --- */
#define STM32_RCC_APB2ENR_SYSCFGEN	BIT(0)
#define STM32_RCC_APB2ENR_TIM1		BIT(11)
#define STM32_RCC_APB2ENR_SPI1EN	BIT(12)
#define STM32_RCC_APB2ENR_TIM8		BIT(13)
#define STM32_RCC_APB2ENR_USART1        BIT(14)
#define STM32_RCC_APB2ENR_SPI4EN	BIT(15)
#define STM32_RCC_APB2ENR_TIM15	BIT(16)
#define STM32_RCC_APB2ENR_TIM16	BIT(17)
#define STM32_RCC_APB2ENR_TIM17	BIT(18)
#define STM32_RCC_APB2ENR_TIM20	BIT(20)

#define STM32_RCC_PB2_USART1		STM32_RCC_APB2ENR_USART1

/* gpio.c needs STM32_RCC_SYSCFGEN */
#define STM32_RCC_SYSCFGEN STM32_RCC_APB2ENR_SYSCFGEN

/* --- RCC APB1RSTR1 Bit Definitions --- */
#define STM32_RCC_APB1RSTR1_USB_RST     BIT(23)
#define STM32_RCC_APB1RSTR              STM32_RCC_APB1RSTR1
#define STM32_RCC_PB1_USB               STM32_RCC_APB1RSTR1_USB_RST

/* --- RCC CSR Bit Definitions --- */
#define STM32_RCC_CSR_LSION		BIT(0)
#define STM32_RCC_CSR_LSIRDY		BIT(1)

/* --- RCC CCIPR Bit Definitions --- */
#define STM32_RCC_CCIPR_UART_SYSCLK      0x1
#define STM32_RCC_CCIPR_USART1SEL_MASK   0x3
#define STM32_RCC_CCIPR_USART1SEL_SHIFT  0
#define STM32_RCC_CCIPR_LPUART1SEL_MASK  0x3
#define STM32_RCC_CCIPR_LPUART1SEL_SHIFT 10
#define STM32_RCC_CCIPR_I2C1SEL_MASK     0x3
#define STM32_RCC_CCIPR_I2C1SEL_SHIFT    12
#define STM32_RCC_CCIPR_I2C2SEL_MASK     0x3
#define STM32_RCC_CCIPR_I2C2SEL_SHIFT    14
#define STM32_RCC_CCIPR_I2C3SEL_MASK     0x3
#define STM32_RCC_CCIPR_I2C3SEL_SHIFT    16

#define STM32_RCC_CCIPR2_I2C4SEL_MASK    0x3

#define STM32_RCC_CCIPR_I2CNSEL_MASK     0x3
#define STM32_RCC_CCIPR_I2CNSEL_SHIFT(n) (STM32_RCC_CCIPR_I2C1SEL_SHIFT + n * 2)
#define STM32_RCC_CCIPR_I2CNSEL_HSI      0x2
/* --- RCC CRRCR Bit Definitions */
#define RCC_CRRCR_HSI48O               BIT(0)
#define RCC_CRRCR_HSIRDY               BIT(1)

/* Reset causes definitions */
/*
 * Reset causes in RCC CSR register. The generic names are required
 */
#define STM32_RCC_RESET_CAUSE STM32_RCC_CSR
#define STM32_RCC_CSR_RMVF              BIT(24)
#define STM32_RCC_CSR_BORRS             BIT(25)
#define STM32_RCC_CSR_PIN               BIT(26)
#define STM32_RCC_CSR_POR               BIT(27)
#define STM32_RCC_CSR_SFT               BIT(28)
#define STM32_RCC_CSR_IWDG              BIT(29)
#define STM32_RCC_CSR_WWDG              BIT(30)
#define STM32_RCC_CSR_LPWR              BIT(31)


#define  RESET_CAUSE_WDG                (STM32_RCC_CSR_WWDG | \
					 STM32_RCC_CSR_IWDG)
#define  RESET_CAUSE_SFT                STM32_RCC_CSR_SFT
#define  RESET_CAUSE_POR                STM32_RCC_CSR_POR
#define  RESET_CAUSE_PIN                STM32_RCC_CSR_PIN
#define  RESET_CAUSE_RMVF               STM32_RCC_CSR_RMVF
#define  RESET_CAUSE_OTHER              (STM32_RCC_CSR_LPWR | \
					 STM32_RCC_CSR_BORRS)
/* Power cause in PWR CSR register */
#define STM32_PWR_CR1                   REG32(STM32_PWR_BASE + 0x00)
#define STM32_PWR_CR2                   REG32(STM32_PWR_BASE + 0x04)
#define STM32_PWR_CR3                   REG32(STM32_PWR_BASE + 0x08)
#define STM32_PWR_CR4                   REG32(STM32_PWR_BASE + 0x0C)
#define STM32_PWR_SR1                   REG32(STM32_PWR_BASE + 0x10)
#define STM32_PWR_SR2                   REG32(STM32_PWR_BASE + 0x14)
#define STM32_PWR_SCR                   REG32(STM32_PWR_BASE + 0x18)
#define STM32_PWR_SCR_CSBF              BIT(8)
#define STM32_PWR_SR1_SBF               BIT(8)

#define STM32_PWR_RESET_CAUSE STM32_PWR_SR1
#define  RESET_CAUSE_SBF                STM32_PWR_SR1_SBF
#define STM32_PWR_RESET_CAUSE_CLR STM32_PWR_SCR
#define  RESET_CAUSE_SBF_CLR            STM32_PWR_SCR_CSBF

#define STM32_PWR_CR1_DBP               BIT(8)

#define STM32_PWR_CR3_UCPD1_STDBY       BIT(13)
#define STM32_PWR_CR3_UCPD1_DBDIS       BIT(14)

/* --- System Config Registers --- */
#define STM32_SYSCFG_MEMRMP             REG32(STM32_SYSCFG_BASE + 0x00)
#define STM32_SYSCFG_PMC                REG32(STM32_SYSCFG_BASE + 0x04)
#define STM32_SYSCFG_EXTICR(n)          REG32(STM32_SYSCFG_BASE + 8 + 4 * (n))
#define STM32_SYSCFG_CMPCR              REG32(STM32_SYSCFG_BASE + 0x20)
#define STM32_SYSCFG_CFGR               REG32(STM32_SYSCFG_BASE + 0x2C)

/* --- Watchdogs --- */

/* --- Real-Time Clock --- */
#define STM32_RTC_TR                REG32(STM32_RTC_BASE + 0x00)
#define STM32_RTC_DR                REG32(STM32_RTC_BASE + 0x04)
#define STM32_RTC_SSR               REG32(STM32_RTC_BASE + 0x08)
#define STM32_RTC_ISR               REG32(STM32_RTC_BASE + 0x0C)
#define STM32_RTC_PRER              REG32(STM32_RTC_BASE + 0x10)
#define STM32_RTC_WUTR              REG32(STM32_RTC_BASE + 0x14)
#define STM32_RTC_CR                REG32(STM32_RTC_BASE + 0x18)


#define STM32_RTC_WPR               REG32(STM32_RTC_BASE + 0x24)
#define STM32_RTC_CALR              REG32(STM32_RTC_BASE + 0x28)
#define STM32_RTC_SHIFTR            REG32(STM32_RTC_BASE + 0x2C)
#define STM32_RTC_TSTR              REG32(STM32_RTC_BASE + 0x30)
#define STM32_RTC_TSDR              REG32(STM32_RTC_BASE + 0x34)
#define STM32_RTC_TSSSR             REG32(STM32_RTC_BASE + 0x38)

#define STM32_RTC_ALRMAR            REG32(STM32_RTC_BASE + 0x40)
#define STM32_RTC_ALRMASSR          REG32(STM32_RTC_BASE + 0x44)
#define STM32_RTC_ALRMBR            REG32(STM32_RTC_BASE + 0x48)
#define STM32_RTC_ALRMBSSR          REG32(STM32_RTC_BASE + 0x44)

/* --- RTC CR Bit Definitions --- */
#define STM32_RTC_CR_BYPSHAD        BIT(5)
#define STM32_RTC_CR_ALRAE          BIT(8)
#define STM32_RTC_CR_ALRAIE         BIT(12)
/* --- RTC ICSR Bit Definitions --- */
#define STM32_RTC_ISR_ALRAWF        BIT(0)
#define STM32_RTC_ISR_RSF           BIT(5)
#define STM32_RTC_ISR_INITF         BIT(6)
#define STM32_RTC_ISR_INIT          BIT(7)
#define STM32_RTC_ISR_ALRAF         BIT(8)
/* --- RTC PRER Bit Definitions --- */
#define STM32_RTC_PRER_A_MASK       (0x7f << 16)
#define STM32_RTC_PRER_S_MASK       (0x7fff << 0)


/* --- Tamper and Backup --- */
#define STM32_TAMP_BKPxR(n)         REG32(STM32_TAMP_BASE + 0x100 + 4 * (n))
#define STM32_BKP_DATA(n)           STM32_TAMP_BKPxR(n)
#define STM32_BKP_BYTES             64


/* --- SPI --- */

/* The SPI controller registers */
struct stm32_spi_regs {
	uint16_t cr1;
	uint16_t _pad0;
	uint16_t cr2;
	uint16_t _pad1;
	unsigned sr;
	uint8_t dr;
	uint8_t _pad2;
	uint16_t _pad3;
	unsigned int crcpr;
	unsigned int rxcrcr;
	unsigned int txcrcr;
	unsigned int i2scfgr;
	unsigned int i2spr;
};
/* Must be volatile, or compiler optimizes out repeated accesses */
typedef volatile struct stm32_spi_regs stm32_spi_regs_t;

#define STM32_SPI1_REGS ((stm32_spi_regs_t *)STM32_SPI1_BASE)
#define STM32_SPI2_REGS ((stm32_spi_regs_t *)STM32_SPI2_BASE)
#define STM32_SPI3_REGS ((stm32_spi_regs_t *)STM32_SPI3_BASE)
#define STM32_SPI4_REGS ((stm32_spi_regs_t *)STM32_SPI4_BASE)

#define STM32_SPI_CR1_BIDIMODE		BIT(15)
#define STM32_SPI_CR1_BIDIOE		BIT(14)
#define STM32_SPI_CR1_CRCEN		BIT(13)
#define STM32_SPI_CR1_SSM		BIT(9)
#define STM32_SPI_CR1_SSI		BIT(8)
#define STM32_SPI_CR1_LSBFIRST		BIT(7)
#define STM32_SPI_CR1_SPE		BIT(6)
#define STM32_SPI_CR1_BR_DIV64R		(5 << 3)
#define STM32_SPI_CR1_BR_DIV4R		BIT(3)
#define STM32_SPI_CR1_MSTR		BIT(2)
#define STM32_SPI_CR1_CPOL		BIT(1)
#define STM32_SPI_CR1_CPHA		BIT(0)
#define STM32_SPI_CR2_FRXTH		BIT(12)
#define STM32_SPI_CR2_DATASIZE(n)	(((n) - 1) << 8)
#define STM32_SPI_CR2_TXEIE		BIT(7)
#define STM32_SPI_CR2_RXNEIE		BIT(6)
#define STM32_SPI_CR2_NSSP		BIT(3)
#define STM32_SPI_CR2_SSOE		BIT(2)
#define STM32_SPI_CR2_TXDMAEN		BIT(1)
#define STM32_SPI_CR2_RXDMAEN		BIT(0)

#define STM32_SPI_SR_RXNE		BIT(0)
#define STM32_SPI_SR_TXE		BIT(1)
#define STM32_SPI_SR_CRCERR		BIT(4)
#define STM32_SPI_SR_BSY		BIT(7)
#define STM32_SPI_SR_FRLVL		(3 << 9)
#define STM32_SPI_SR_FTLVL		(3 << 11)

/* --- Debug --- */
#define STM32_DBGMCU_IDCODE         REG32(STM32_DBGMCU_BASE + 0x00)
#define STM32_DBGMCU_CR             REG32(STM32_DBGMCU_BASE + 0x04)
#define STM32_DBGMCU_APB1FZ         REG32(STM32_DBGMCU_BASE + 0x08)
#define STM32_DBGMCU_APB2FZ         REG32(STM32_DBGMCU_BASE + 0x0C)

/* --- DBGMCU CR Bit Definitions --- */
#define  STM32_DBGMCU_CR_SLEEP                      BIT(0)
#define  STM32_DBGMCU_CR_STOP                       BIT(1)
#define  STM32_DBGMCU_CR_STBY                       BIT(2)
#define  STM32_DBGMCU_CR_TRACE_MASK                 (BIT(5)|BIT(6)|BIT(7))
#define   STM32_DBGMCU_CR_TRACE_EN                   BIT(5)
#define   STM32_DBGMCU_CR_TRACE_MODE_ASYNC           0
#define   STM32_DBGMCU_CR_TRACE_MODE_SYNC1           BIT(6)
#define   STM32_DBGMCU_CR_TRACE_MODE_SYNC2           BIT(7)
#define   STM32_DBGMCU_CR_TRACE_MODE_SYNC4           (BIT(6)|BIT(7))
/* --- DBGMCU APB1FZ Bit Definitions --- */
#define  STM32_DBGMCU_APB1FZ_TIM2                   BIT(0)
#define  STM32_DBGMCU_APB1FZ_TIM3                   BIT(1)
#define  STM32_DBGMCU_APB1FZ_TIM4                   BIT(2)
#define  STM32_DBGMCU_APB1FZ_TIM5                   BIT(3)
#define  STM32_DBGMCU_APB1FZ_TIM6                   BIT(4)
#define  STM32_DBGMCU_APB1FZ_TIM7                   BIT(5)
#define  STM32_DBGMCU_APB1FZ_RTC                    BIT(10)
#define  STM32_DBGMCU_APB1FZ_WWDG                   BIT(11)
#define  STM32_DBGMCU_APB1FZ_IWDG                   BIT(12)
#define  STM32_DBGMCU_APB1FZ_I2C1_SMBUS_TIMEOUT     BIT(21)
#define  STM32_DBGMCU_APB1FZ_I2C2_SMBUS_TIMEOUT     BIT(22)
#define  STM32_DBGMCU_APB1FZ_I2C3_SMBUS_TIMEOUT     BIT(30)
/* --- DBGMCU  APB2FZ Bit Definitions --- */
#define  STM32_DBGMCU_APB2FZ_TIM1                   BIT(11)
#define  STM32_DBGMCU_APB2FZ_TIM8                   BIT(13)
#define  STM32_DBGMCU_APB2FZ_TIM15                  BIT(16)
#define  STM32_DBGMCU_APB2FZ_TIM16                  BIT(17)
#define  STM32_DBGMCU_APB2FZ_TIM17                  BIT(18)
#define  STM32_DBGMCU_APB2FZ_TIM20                  BIT(20)

/* --- Flash --- */
#define STM32_FLASH_REG(off)        REG32(STM32_FLASH_REGS_BASE + (off))
#define STM32_FLASH_ACR             STM32_FLASH_REG(0x00)
#define STM32_FLASH_PDKEYR          STM32_FLASH_REG(0x04)
#define STM32_FLASH_KEYR            STM32_FLASH_REG(0x08)
#define STM32_FLASH_OPTKEYR         STM32_FLASH_REG(0x0c)
#define STM32_FLASH_SR              STM32_FLASH_REG(0x10)
#define STM32_FLASH_CR              STM32_FLASH_REG(0x14)
#define STM32_FLASH_ECCR            STM32_FLASH_REG(0x18)
#define STM32_FLASH_OPTR            STM32_FLASH_REG(0x20)
#define STM32_FLASH_PCROP1SR        STM32_FLASH_REG(0x24)
#define STM32_FLASH_PCROP1ER        STM32_FLASH_REG(0x28)
#define STM32_FLASH_WRP1AR          STM32_FLASH_REG(0x2C)
#define STM32_FLASH_WRP1BR          STM32_FLASH_REG(0x30)

/* --- FLASH CR Bit Definitions --- */
#define STM32_FLASH_ACR_LATENCY_SHIFT (0)
#define STM32_FLASH_ACR_LATENCY_MASK  (0xf << STM32_FLASH_ACR_LATENCY_SHIFT)
#define STM32_FLASH_ACR_PRFTEN      BIT(8)
#define STM32_FLASH_ACR_ICEN        BIT(9)
#define STM32_FLASH_ACR_DCEN        BIT(10)
#define STM32_FLASH_ACR_ICRST       BIT(11)
#define STM32_FLASH_ACR_DCRST       BIT(12)

/* --- FLASH KEYR Bit Definitions --- */
#define  FLASH_KEYR_KEY1            0x45670123
#define  FLASH_KEYR_KEY2            0xCDEF89AB

/* --- FLASH OPTKEYR Bit Definitions --- */
#define  FLASH_OPTKEYR_KEY1         0x08192A3B
#define  FLASH_OPTKEYR_KEY2         0x4C5D6E7F

/* --- FLASH SR Bit Definitions --- */
#define  FLASH_SR_BUSY              BIT(16)
#define  FLASH_SR_OPTVERR           BIT(15)
#define  FLASH_SR_RDERR             BIT(14)
#define  FLASH_SR_FASTERR           BIT(9)
#define  FLASH_SR_MISERR            BIT(8)
#define  FLASH_SR_PGSERR            BIT(7)
#define  FLASH_SR_SIZERR            BIT(6)
#define  FLASH_SR_PGAERR            BIT(5)
#define  FLASH_SR_WRPERR            BIT(4)
#define  FLASH_SR_PROGERR           BIT(3)
#define  FLASH_SR_OPERR             BIT(1)
#define  FLASH_SR_ERR_MASK          (FLASH_SR_OPTVERR | FLASH_SR_RDERR | \
				     FLASH_SR_FASTERR | FLASH_SR_PGSERR | \
				     FLASH_SR_SIZERR | FLASH_SR_PGAERR |  \
				     FLASH_SR_WRPERR |  FLASH_SR_PROGERR | \
				     FLASH_SR_OPERR)

/* --- FLASH CR Bit Definitions --- */
#define  FLASH_CR_PG                BIT(0)
#define  FLASH_CR_PER               BIT(1)
#define  FLASH_CR_STRT              BIT(16)
#define  FLASH_CR_OPTSTRT           BIT(17)
#define  FLASH_CR_OBL_LAUNCH        BIT(27)
#define  FLASH_CR_OPTLOCK           BIT(30)
#define  FLASH_CR_LOCK              BIT(31)
#define  FLASH_CR_PNB(sec)          (((sec) & 0x7f) << 3)
#define  FLASH_CR_PNB_MASK          FLASH_CR_PNB(0x7f)

#define STM32_FLASH_MIN_WRITE_SIZE  (CONFIG_FLASH_WRITE_SIZE * 2)

/* --- FLASH Option bytes --- */
#define STM32_OPTB_USER_RDP         REG32(STM32_OPTB_BASE + 0x00)
#define STM32_OPTB_PCROP1_START     REG32(STM32_OPTB_BASE + 0x08)
#define STM32_OPTB_PCROP1_END       REG32(STM32_OPTB_BASE + 0x10)
#define STM32_OPTB_WRP1AR           REG32(STM32_OPTB_BASE + 0x18)
#define STM32_OPTB_WRP1BR           REG32(STM32_OPTB_BASE + 0x20)
#define STM32_OPTB_SECURE_MEM       REG32(STM32_OPTB_BASE + 0x28)

#define STM32_OPTB_REG_READ(n)  REG32(STM32_FLASH_REG(0x20) + (n * 4))
#define STM32_OPTB_READ(n)      REG32(STM32_OPTB_BASE + ((n) * 8))
#define STM32_OPTB_COMP_READ(n) REG32(STM32_OPTB_BASE + ((n) * 8) + 0x4)

#define STM32_OPTB_USER_nBOOT1      BIT(23)
#define STM32_OPTB_USER_nSWBOOT0    BIT(26)
#define STM32_OPTB_USER_nBOOT0      BIT(27)
#define STM32_OPTB_ENTRY_NUM 6

/* --- External Interrupts --- */
#define STM32_EXTI_IMR              REG32(STM32_EXTI_BASE + 0x00)
#define STM32_EXTI_EMR              REG32(STM32_EXTI_BASE + 0x04)
#define STM32_EXTI_RTSR             REG32(STM32_EXTI_BASE + 0x08)
#define STM32_EXTI_FTSR             REG32(STM32_EXTI_BASE + 0x0c)
#define STM32_EXTI_SWIER            REG32(STM32_EXTI_BASE + 0x10)
#define STM32_EXTI_PR               REG32(STM32_EXTI_BASE + 0x14)

#define EXTI_RTC_ALR_EVENT BIT(17)

/* --- ADC --- */
#define STM32_ADC_ISR              REG32(STM32_ADC1_BASE + 0x00)
#define STM32_ADC_IER              REG32(STM32_ADC1_BASE + 0x04)
#define STM32_ADC_CR               REG32(STM32_ADC1_BASE + 0x08)
#define STM32_ADC_CFGR             REG32(STM32_ADC1_BASE + 0x0C)
#define STM32_ADC_CFGR2            REG32(STM32_ADC1_BASE + 0x10)
#define STM32_ADC_SMPR1            REG32(STM32_ADC1_BASE + 0x14)
#define STM32_ADC_SMPR2            REG32(STM32_ADC1_BASE + 0x18)
#define STM32_ADC_TR1              REG32(STM32_ADC1_BASE + 0x20)
#define STM32_ADC_TR2              REG32(STM32_ADC1_BASE + 0x24)
#define STM32_ADC_TR3              REG32(STM32_ADC1_BASE + 0x28)
#define STM32_ADC_JOFR(n)          REG32(STM32_ADC1_BASE + 0x14 + ((n)&3) * 4)
#define STM32_ADC_HTR              REG32(STM32_ADC1_BASE + 0x24)
#define STM32_ADC_LTR              REG32(STM32_ADC1_BASE + 0x28)
#define STM32_ADC_SQR(n)           REG32(STM32_ADC1_BASE + 0x30 + ((n)&3) * 4)
#define STM32_ADC_SQR1             REG32(STM32_ADC1_BASE + 0x30)
#define STM32_ADC_SQR2             REG32(STM32_ADC1_BASE + 0x34)
#define STM32_ADC_SQR3             REG32(STM32_ADC1_BASE + 0x38)
#define STM32_ADC_SQR4             REG32(STM32_ADC1_BASE + 0x3C)
#define STM32_ADC_DR               REG32(STM32_ADC1_BASE + 0x40)
#define STM32_ADC_JSQR             REG32(STM32_ADC1_BASE + 0x4C)
#define STM32_ADC_JDR(n)           REG32(STM32_ADC1_BASE + 0x80 + ((n)&3) * 4)


/* --- ADC CR Bit Definitions --- */
#define STM32_ADC_CR_ADEN          BIT(0)
#define STM32_ADC_CR_ADSTART       BIT(2)
#define STM32_ADC_CR_ADVREGEN      BIT(28)
#define STM32_ADC_CR_CAL           BIT(31)

#define STM32_ADC_CFGR_CONT        BIT(13)
#define STM32_ADC_CR2_ALIGN        BIT(15)

/* --- Comparators --- */


/* --- DMA --- */
/*
 * Available DMA streams, numbered from 0.
 *
 *
 * Channels 0 - 5 are managed by controller DMA1, 6 - 11 by DMA2.
 */
enum dma_channel {
	/* Channel numbers */
	STM32_DMAC_CH1 = 0,
	STM32_DMAC_CH2 = 1,
	STM32_DMAC_CH3 = 2,
	STM32_DMAC_CH4 = 3,
	STM32_DMAC_CH5 = 4,
	STM32_DMAC_CH6 = 5,
	STM32_DMAC_CH7 = 6,
	/*
	 * Skip CH8, it should belong to DMA engine 1.
	 * Sharing code with STM32s that have 16 engines will be easier.
	 */
	STM32_DMAC_CH9 = 8,
	STM32_DMAC_CH10 = 9,
	STM32_DMAC_CH11 = 10,
	STM32_DMAC_CH12 = 11,
	STM32_DMAC_CH13 = 12,
	STM32_DMAC_CH14 = 13,

	/* Channel functions */
	STM32_DMAC_ADC = STM32_DMAC_CH1,
	STM32_DMAC_SPI1_RX = STM32_DMAC_CH2,
	STM32_DMAC_SPI1_TX = STM32_DMAC_CH3,
	STM32_DMAC_DAC_CH1 = STM32_DMAC_CH2,
	STM32_DMAC_DAC_CH2 = STM32_DMAC_CH3,
	STM32_DMAC_I2C2_TX = STM32_DMAC_CH4,
	STM32_DMAC_I2C2_RX = STM32_DMAC_CH5,
	STM32_DMAC_USART1_RX = STM32_DMAC_CH10,
	STM32_DMAC_USART1_TX = STM32_DMAC_CH11,
	STM32_DMAC_USART3_RX = STM32_DMAC_CH12,
	STM32_DMAC_USART3_TX = STM32_DMAC_CH13,
	STM32_DMAC_I2C1_TX = STM32_DMAC_CH5,
	STM32_DMAC_I2C1_RX = STM32_DMAC_CH6,
	STM32_DMAC_PMSE_ROW = STM32_DMAC_CH6,
	STM32_DMAC_PMSE_COL = STM32_DMAC_CH7,
	STM32_DMAC_SPI2_RX = STM32_DMAC_CH4,
	STM32_DMAC_SPI2_TX = STM32_DMAC_CH5,
	STM32_DMAC_SPI3_RX = STM32_DMAC_CH9,
	STM32_DMAC_SPI3_TX = STM32_DMAC_CH10,
	STM32_DMAC_LPUART_RX = STM32_DMAC_CH9,
	STM32_DMAC_LPUART_TX = STM32_DMAC_CH10,
	STM32_DMAC_COUNT = 14,
};

#define STM32_DMAC_PER_CTLR 8

#define STM32_REQ_USART1_TX 4
#define STM32_REQ_USART1_RX 4

#define STM32_REQ_USART2_TX 4
#define STM32_REQ_USART2_RX 4

#define STM32_I2C1_TX_REQ_CH 1
#define STM32_I2C1_RX_REQ_CH 1

#define STM32_I2C2_TX_REQ_CH 7
#define STM32_I2C2_RX_REQ_CH 7

#define STM32_I2C3_TX_REQ_CH 3
#define STM32_I2C3_RX_REQ_CH 1

#define STM32_FMPI2C4_TX_REQ_CH 2
#define STM32_FMPI2C4_RX_REQ_CH 2

#define STM32_SPI1_TX_REQ_CH 3
#define STM32_SPI1_RX_REQ_CH 3
#define STM32_SPI2_TX_REQ_CH 0
#define STM32_SPI2_RX_REQ_CH 0
#define STM32_SPI3_TX_REQ_CH 0
#define STM32_SPI3_RX_REQ_CH 0

/* Registers for a single channel of the DMA controller */
struct stm32_dma_chan {
	uint32_t	ccr;		/* Control */
	uint32_t	cndtr;		/* Number of data to transfer */
	uint32_t	cpar;		/* Peripheral address */
	uint32_t	cmar;		/* Memory address */
	uint32_t	reserved;
};

/* Always use stm32_dma_chan_t so volatile keyword is included! */
typedef volatile struct stm32_dma_chan stm32_dma_chan_t;

/* Common code and header file must use this */
typedef stm32_dma_chan_t dma_chan_t;

/* Registers for the DMA controller */
struct stm32_dma_regs {
	uint32_t	isr;
	uint32_t	ifcr;
	stm32_dma_chan_t chan[STM32_DMAC_COUNT];
};

/* Always use stm32_dma_regs_t so volatile keyword is included! */
typedef volatile struct stm32_dma_regs stm32_dma_regs_t;

#define STM32_DMA1_REGS ((stm32_dma_regs_t *)STM32_DMA1_BASE)


#define STM32_DMA_CCR_CHANNEL(channel)		 (0)
#define STM32_DMA2_REGS ((stm32_dma_regs_t *)STM32_DMA2_BASE)
#define STM32_DMA_REGS(channel) \
	((channel) < STM32_DMAC_PER_CTLR ? STM32_DMA1_REGS : STM32_DMA2_REGS)
#define STM32_DMA_CSELR(channel) \
	REG32(((channel) < STM32_DMAC_PER_CTLR ? \
			STM32_DMA1_BASE : STM32_DMA2_BASE)  + 0xA8)

/* Bits for DMA controller regs (isr and ifcr) */
#define STM32_DMA_CH_OFFSET(channel)   (4 * ((channel) % STM32_DMAC_PER_CTLR))
#define STM32_DMA_ISR_MASK(channel, mask) \
	((mask) << STM32_DMA_CH_OFFSET(channel))
#define STM32_DMA_ISR_GIF(channel)	STM32_DMA_ISR_MASK(channel, BIT(0))
#define STM32_DMA_ISR_TCIF(channel)	STM32_DMA_ISR_MASK(channel, BIT(1))
#define STM32_DMA_ISR_HTIF(channel)	STM32_DMA_ISR_MASK(channel, BIT(2))
#define STM32_DMA_ISR_TEIF(channel)	STM32_DMA_ISR_MASK(channel, BIT(3))
#define STM32_DMA_ISR_ALL(channel)	STM32_DMA_ISR_MASK(channel, 0x0f)

#define STM32_DMA_GIF                   BIT(0)
#define STM32_DMA_TCIF                  BIT(1)
#define STM32_DMA_HTIF                  BIT(2)
#define STM32_DMA_TEIF                  BIT(3)
#define STM32_DMA_ALL                   0xf

#define STM32_DMA_GET_ISR(channel)      \
	((STM32_DMA_REGS(channel)->isr >> STM32_DMA_CH_OFFSET(channel)) \
	& STM32_DMA_ALL)
#define STM32_DMA_SET_ISR(channel, val) \
	(STM32_DMA_REGS(channel)->isr = \
	((STM32_DMA_REGS(channel)->isr & \
	~(STM32_DMA_ALL << STM32_DMA_CH_OFFSET(channel))) | \
	(((val) & STM32_DMA_ALL) << STM32_DMA_CH_OFFSET(channel))))
#define STM32_DMA_GET_IFCR(channel)      \
	((STM32_DMA_REGS(channel)->ifcr >> STM32_DMA_CH_OFFSET(channel)) \
	& STM32_DMA_ALL)
#define STM32_DMA_SET_IFCR(channel, val) \
	(STM32_DMA_REGS(channel)->ifcr = \
	((STM32_DMA_REGS(channel)->ifcr & \
	~(STM32_DMA_ALL << STM32_DMA_CH_OFFSET(channel))) | \
	(((val) & STM32_DMA_ALL) << STM32_DMA_CH_OFFSET(channel))))


/* Bits for DMA channel regs */
#define STM32_DMA_CCR_EN		BIT(0)
#define STM32_DMA_CCR_TCIE		BIT(1)
#define STM32_DMA_CCR_HTIE		BIT(2)
#define STM32_DMA_CCR_TEIE		BIT(3)
#define STM32_DMA_CCR_DIR		BIT(4)
#define STM32_DMA_CCR_CIRC		BIT(5)
#define STM32_DMA_CCR_PINC		BIT(6)
#define STM32_DMA_CCR_MINC		BIT(7)
#define STM32_DMA_CCR_PSIZE_8_BIT	(0 << 8)
#define STM32_DMA_CCR_PSIZE_16_BIT	(1 << 8)
#define STM32_DMA_CCR_PSIZE_32_BIT	(2 << 8)
#define STM32_DMA_CCR_MSIZE_8_BIT	(0 << 10)
#define STM32_DMA_CCR_MSIZE_16_BIT	(1 << 10)
#define STM32_DMA_CCR_MSIZE_32_BIT	(2 << 10)
#define STM32_DMA_CCR_PL_LOW		(0 << 12)
#define STM32_DMA_CCR_PL_MEDIUM		(1 << 12)
#define STM32_DMA_CCR_PL_HIGH		(2 << 12)
#define STM32_DMA_CCR_PL_VERY_HIGH	(3 << 12)
#define STM32_DMA_CCR_MEM2MEM		BIT(14)

/* The requests for the DMA1/DMA2 controllers are routed through DMAMUX. */
/* DMAMUX registers */
#define STM32_DMAMUX_CxCR(x)      REG32(STM32_DMAMUX_BASE + 4 * (x))
#define STM32_DMAMUX_CSR          REG32(STM32_DMAMUX_BASE + 0x80)
#define STM32_DMAMUX_CFR          REG32(STM32_DMAMUX_BASE + 0x84)
#define STM32_DMAMUX_RGxCR(x)     REG32(STM32_DMAMUX_BASE + 0x100 + 4 * (x))
#define STM32_DMAMUX_RGSR         REG32(STM32_DMAMUX_BASE + 0x140)
#define STM32_DMAMUX_RGCFR        REG32(STM32_DMAMUX_BASE + 0x144)

enum dmamux1_request {
	DMAMUX_REQ_ADC1 = 5,
	DMAMUX_REQ_DAC1_CH1 = 6,
	DMAMUX_REQ_DAC1_CH2 = 7,
	DMAMUX_REQ_TIM6_UP = 8,
	DMAMUX_REQ_TIM7_UP = 9,
	DMAMUX_REQ_SPI1_RX = 10,
	DMAMUX_REQ_SPI1_TX = 11,
	DMAMUX_REQ_SPI2_RX = 12,
	DMAMUX_REQ_SPI2_TX = 13,
	DMAMUX_REQ_SPI3_RX = 14,
	DMAMUX_REQ_SPI3_TX = 15,
	DMAMUX_REQ_I2C1_RX = 16,
	DMAMUX_REQ_I2C1_TX = 17,
	DMAMUX_REQ_I2C2_RX = 18,
	DMAMUX_REQ_I2C2_TX = 19,
	DMAMUX_REQ_I2C3_RX = 20,
	DMAMUX_REQ_I2C3_TX = 21,
	DMAMUX_REQ_I2C4_RX = 22,
	DMAMUX_REQ_I2C4_TX = 23,
	DMAMUX_REQ_USART1_RX = 24,
	DMAMUX_REQ_USART1_TX = 25,
	DMAMUX_REQ_USART2_RX = 26,
	DMAMUX_REQ_USART2_TX = 27,
	DMAMUX_REQ_USART3_RX = 28,
	DMAMUX_REQ_USART3_TX = 29,
	DMAMUX_REQ_UART4_RX = 30,
	DMAMUX_REQ_UART4_TX = 31,
	DMAMUX_REQ_USART5_RX = 32,
	DMAMUX_REQ_UART5_TX = 33,
	DMAMUX_REQ_LPUART1_RX = 34,
	DMAMUX_REQ_LPUART1_TX = 35,
	DMAMUX_REQ_ADC2 = 36,
	DMAMUX_REQ_ADC3 = 37,
	DMAMUX_REQ_ADC4 = 38,
	DMAMUX_REQ_ADC5 = 39,
	DMAMUX_REQ_QUADSPI = 40,
	DMAMUX_REQ_DAC2_CH1 = 41,
	DMAMUX_REQ_TIM1_CH1 = 42,
	DMAMUX_REQ_TIM1_CH2 = 43,
	DMAMUX_REQ_TIM1_CH3 = 44,
	DMAMUX_REQ_TIM1_CH4 = 45,
	DMAMUX_REQ_TIM1_UP = 46,
	DMAMUX_REQ_TIM1_TRIG = 47,
	DMAMUX_REQ_TIM1_COM = 48,
	DMAMUX_REQ_TIM8_CH1 = 49,
	DMAMUX_REQ_TIM8_CH2 = 50,
	DMAMUX_REQ_TIM8_CH3 = 51,
	DMAMUX_REQ_TIM8_CH4 = 52,
	DMAMUX_REQ_TIM8_UP = 53,
	DMAMUX_REQ_TIM8_TRIG = 54,
	DMAMUX_REQ_TIM8_COM = 55,
	DMAMUX_REQ_TIM2_CH1 = 56,
	DMAMUX_REQ_TIM2_CH2 = 57,
	DMAMUX_REQ_TIM2_CH3 = 58,
	DMAMUX_REQ_TIM2_CH4 = 59,
	DMAMUX_REQ_TIM2_UP = 60,
	DMAMUX_REQ_TIM3_CH1 = 61,
	DMAMUX_REQ_TIM3_CH2 = 62,
	DMAMUX_REQ_TIM3_CH3 = 63,
	DMAMUX_REQ_TIM3_CH4 = 64,
	DMAMUX_REQ_TIM3_UP = 65,
	DMAMUX_REQ_TIM3_TRIG = 66,
	DMAMUX_REQ_TIM4_CH1 = 67,
	DMAMUX_REQ_TIM4_CH2 = 68,
	DMAMUX_REQ_TIM4_CH3 = 69,
	DMAMUX_REQ_TIM4_CH4 = 70,
	DMAMUX_REQ_TIM4_UP = 71,
	DMAMUX_REQ_TIM5_CH1 = 72,
	DMAMUX_REQ_TIM5_CH2 = 73,
	DMAMUX_REQ_TIM5_CH3 = 74,
	DMAMUX_REQ_TIM5_CH4 = 75,
	DMAMUX_REQ_TIM5_UP = 76,
	DMAMUX_REQ_TIM5_TRIG = 77,
	DMAMUX_REQ_TIM15_CH1 = 78,
	DMAMUX_REQ_TIM15_UP = 79,
	DMAMUX_REQ_TIM15_TRIG = 80,
	DMAMUX_REQ_TIM15_COM = 81,
	DMAMUX_REQ_TIM16_CH1 = 82,
	DMAMUX_REQ_TIM16_UP = 83,
	DMAMUX_REQ_TIM17_CH1 = 84,
	DMAMUX_REQ_TIM17_UP = 85,
	DMAMUX_REQ_TIM20_CH1 = 86,
	DMAMUX_REQ_TIM20_CH2 = 87,
	DMAMUX_REQ_TIM20_CH3 = 88,
	DMAMUX_REQ_TIM20_CH4 = 89,
	DMAMUX_REQ_TIM20_UP = 90,
	DMAMUX_REQ_AES_IN = 91,
	DMAMUX_REQ_AES_OUT = 92,
	DMAMUX_REQ_TIM20_TRIG = 93,
	DMAMUX_REQ_TIM20_COM = 94,
	DMAMUX_REQ_DAC3_CH1 = 102,
	DMAMUX_REQ_DAC3_CH2 = 103,
	DMAMUX_REQ_DAC4_CH1 = 104,
	DMAMUX_REQ_DAC4_CH2 = 105,
	DMAMUX_REQ_SPI4_RX = 106,
	DMAMUX_REQ_SPI4_TX = 107,
	DMAMUX_REQ_SAI1_A = 108,
	DMAMUX_REQ_SAI1_B = 109,
};
/* LPUART gets accessed as UART9 in STM32 uart module */
#define DMAMUX_REQ_UART9_RX DMAMUX_REQ_LPUART1_RX
#define DMAMUX_REQ_UART9_TX DMAMUX_REQ_LPUART1_TX

/* --- CRC --- */
#define STM32_CRC_DR                REG32(STM32_CRC_BASE + 0x0)
#define STM32_CRC_DR32              REG32(STM32_CRC_BASE + 0x0)
#define STM32_CRC_DR16              REG16(STM32_CRC_BASE + 0x0)
#define STM32_CRC_DR8               REG8(STM32_CRC_BASE + 0x0)

#define STM32_CRC_IDR               REG32(STM32_CRC_BASE + 0x4)
#define STM32_CRC_CR                REG32(STM32_CRC_BASE + 0x8)
#define STM32_CRC_INIT              REG32(STM32_CRC_BASE + 0x10)
#define STM32_CRC_POL               REG32(STM32_CRC_BASE + 0x14)

#define STM32_CRC_CR_RESET          BIT(0)
#define STM32_CRC_CR_POLYSIZE_32    (0 << 3)
#define STM32_CRC_CR_POLYSIZE_16    (1 << 3)
#define STM32_CRC_CR_POLYSIZE_8     (2 << 3)
#define STM32_CRC_CR_POLYSIZE_7     (3 << 3)
#define STM32_CRC_CR_REV_IN_BYTE    (1 << 5)
#define STM32_CRC_CR_REV_IN_HWORD   (2 << 5)
#define STM32_CRC_CR_REV_IN_WORD    (3 << 5)
#define STM32_CRC_CR_REV_OUT        BIT(7)


/* --- USB --- */
#define STM32_USB_EP(n)            REG16(STM32_USB_FS_BASE + (n) * 4)

#define STM32_USB_CNTR             REG16(STM32_USB_FS_BASE + 0x40)

#define STM32_USB_CNTR_FRES	    BIT(0)
#define STM32_USB_CNTR_PDWN	    BIT(1)
#define STM32_USB_CNTR_LP_MODE	    BIT(2)
#define STM32_USB_CNTR_FSUSP	    BIT(3)
#define STM32_USB_CNTR_RESUME	    BIT(4)
#define STM32_USB_CNTR_L1RESUME	    BIT(5)
#define STM32_USB_CNTR_L1REQM	    BIT(7)
#define STM32_USB_CNTR_ESOFM	    BIT(8)
#define STM32_USB_CNTR_SOFM	    BIT(9)
#define STM32_USB_CNTR_RESETM	    BIT(10)
#define STM32_USB_CNTR_SUSPM	    BIT(11)
#define STM32_USB_CNTR_WKUPM	    BIT(12)
#define STM32_USB_CNTR_ERRM	    BIT(13)
#define STM32_USB_CNTR_PMAOVRM	    BIT(14)
#define STM32_USB_CNTR_CTRM	    BIT(15)

#define STM32_USB_ISTR             REG16(STM32_USB_FS_BASE + 0x44)

#define STM32_USB_ISTR_EP_ID_MASK   (0x000f)
#define STM32_USB_ISTR_DIR	    BIT(4)
#define STM32_USB_ISTR_L1REQ	    BIT(7)
#define STM32_USB_ISTR_ESOF	    BIT(8)
#define STM32_USB_ISTR_SOF	    BIT(9)
#define STM32_USB_ISTR_RESET	    BIT(10)
#define STM32_USB_ISTR_SUSP	    BIT(11)
#define STM32_USB_ISTR_WKUP	    BIT(12)
#define STM32_USB_ISTR_ERR	    BIT(13)
#define STM32_USB_ISTR_PMAOVR	    BIT(14)
#define STM32_USB_ISTR_CTR	    BIT(15)

#define STM32_USB_FNR              REG16(STM32_USB_FS_BASE + 0x48)

#define STM32_USB_FNR_RXDP_RXDM_SHIFT (14)
#define STM32_USB_FNR_RXDP_RXDM_MASK  (3 << STM32_USB_FNR_RXDP_RXDM_SHIFT)

#define STM32_USB_DADDR            REG16(STM32_USB_FS_BASE + 0x4C)
#define STM32_USB_BTABLE           REG16(STM32_USB_FS_BASE + 0x50)
#define STM32_USB_LPMCSR           REG16(STM32_USB_FS_BASE + 0x54)
#define STM32_USB_BCDR             REG16(STM32_USB_FS_BASE + 0x58)

#define STM32_USB_BCDR_BCDEN	    BIT(0)
#define STM32_USB_BCDR_DCDEN	    BIT(1)
#define STM32_USB_BCDR_PDEN	    BIT(2)
#define STM32_USB_BCDR_SDEN	    BIT(3)
#define STM32_USB_BCDR_DCDET	    BIT(4)
#define STM32_USB_BCDR_PDET	    BIT(5)
#define STM32_USB_BCDR_SDET	    BIT(6)
#define STM32_USB_BCDR_PS2DET	    BIT(7)
#define STM32_USB_BCDR_DPPU	    BIT(15)

/* --- USB Endpoint bit definitions  --- */
#define EP_MASK     0x0F0F
#define EP_TX_DTOG  0x0040
#define EP_TX_MASK  0x0030
#define EP_TX_VALID 0x0030
#define EP_TX_NAK   0x0020
#define EP_TX_STALL 0x0010
#define EP_TX_DISAB 0x0000
#define EP_RX_DTOG  0x4000
#define EP_RX_MASK  0x3000
#define EP_RX_VALID 0x3000
#define EP_RX_NAK   0x2000
#define EP_RX_STALL 0x1000
#define EP_RX_DISAB 0x0000

#define EP_STATUS_OUT 0x0100

#define EP_TX_RX_MASK (EP_TX_MASK | EP_RX_MASK)
#define EP_TX_RX_VALID (EP_TX_VALID | EP_RX_VALID)

#define STM32_TOGGLE_EP(n, mask, val, flags) \
	STM32_USB_EP(n) = (((STM32_USB_EP(n) & (EP_MASK | (mask))) \
			^ (val)) | (flags))

/* --- TRNG --- */
#define STM32_RNG_CR                REG32(STM32_RNG_BASE + 0x0)
#define STM32_RNG_SR                REG32(STM32_RNG_BASE + 0x4)
#define STM32_RNG_DR                REG32(STM32_RNG_BASE + 0x8)

/* --- RNG CR Bit Definitions --- */
#define STM32_RNG_CR_RNGEN          BIT(2)
#define STM32_RNG_CR_IE             BIT(3)
#define STM32_RNG_CR_CED            BIT(5)
/* --- RNG SR_DRDY Bit Definitions --- */
#define STM32_RNG_SR_DRDY           BIT(0)

/* --- AXI interconnect --- */

/* STM32H7: AXI_TARGx_FN_MOD exists for masters x = 1, 2 and 7 */
#define STM32_AXI_TARG_FN_MOD(x)    REG32(STM32_GPV_BASE + 0x1108 + \
					  0x1000 * (x))
#define  WRITE_ISS_OVERRIDE         BIT(1)
#define  READ_ISS_OVERRIDE          BIT(0)

/* --- MISC --- */
#define STM32_UNIQUE_ID_ADDRESS     REG32_ADDR(STM32_UNIQUE_ID_BASE)
#define STM32_UNIQUE_ID_LENGTH      (3 * 4)

#endif /* !__ASSEMBLER__ */

