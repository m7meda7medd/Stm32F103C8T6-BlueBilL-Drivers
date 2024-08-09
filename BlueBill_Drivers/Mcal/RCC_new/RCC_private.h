/*
 * RCC_private.h
 *
 *  Created on: Jun 27, 2024
 *      Author: Mohamed Ahmed
 */

#ifndef RCC_NEW_RCC_PRIVATE_H_
#define RCC_NEW_RCC_PRIVATE_H_
/* =============================================================== */
/* Includes */
#include "../../common/Std_Types.h"
#include "../../common/stm32f103c8t6.h"
/* =============================================================== */
#define MAXTRIMVAL  0b11111
#define TRIMVAL_MASK  MAXTRIMVAL
#define APB_PRESCALER_OFFSET  4
#define RCC_CFGR_HPRE_MASK    (u32) 0xF   /* Mask for AHB prescaler */
#define RCC_CFGR_PPRE_MASK   (u32) 0xEF  /* Mask for APB prescaler */
#define MASK_3BITS (u32)0x7       /* 3 bit mask */
#define MASK_4BITS (u32)0xF       /* 4 bit mask */
#define MASK_2BITS (u32)0x3       /* 3 bit mask */
 /* Registers Bit Definetion */
#define HSION 0
#define HSIRDY 1
#define PLLON 24
#define PLLRDY 25
#define HSEON  16
#define HSERDY 17
#define HSEBYP 18
#define CSS    19
#define HSITRIM 3
#define MCO_OFFSET  24
#define PLLMUL_OFFSET   18
#define HSI_SYSCLK 0b00
#define HSE_SYSCLK 0b01
#define PLL_SYSCLK 0b10
#define NA 0b11
#define SW_OFFSET 0
#define SWS_OFFSET 2
#define HPRE_OFFSET 4
#define PPRE1_OFFSET 8
#define PPRE2_OFFSET 11
#define ADCPRE_OFFSET 14
#define PLLSRC 16
#define PLLXTRPE 17
#define USBPRE 22
/* =============================================================== */
// AHB Peripherals Enable
#define DMA1   1
#define DMA2   2
#define SRAM   4
#define FLITF  16
#define CRC    64
#define FSMC   256
#define SDIO   1024

// APB2 Peripherals Enable
#define AFIO    1
#define GPIOA   4
#define GPIOB   8
#define GPIOC   16
#define GPIOD   32
#define GPIOE   64
#define GPIOF   128
#define GPIOG   256
#define ADC1    512
#define ADC2    1024
#define TIM1    (u32) 2048
#define SPI1    (u32) 4096
#define TIM8    (u32) 8192
#define USART1  (u32) 16384
#define ADC3    (u32) 32768
#define TIM9    (u32) 524288
#define TIM10   (u32) 1048576
#define TIM11   (u32) 2097152

// APB1 Peripherals Enable
#define TIM2     1
#define TIM3     2
#define TIM4     (u32) 4
#define TIM5     (u32) 8
#define TIM6     (u32) 16
#define TIM7     (u32) 32
#define TIM12    (u32) 64
#define TIM13    (u32) 128
#define TIM14    (u32) 256
#define WWDG     (u32) 2048
#define SPI2     (u32) 16384
#define SPI3     (u32) 32768
#define USART2   (u32) 131072
#define USART3   (u32) 262144
#define UART4    (u32) 524288
#define UART5    (u32) 1048576
#define I2C1     (u32) 2097152
#define I2C2     (u32) 4194304
#define USB      (u32) 8388608
#define CAN      (u32) 33554432
#define BKP      (u32) 134217728
#define PWR      (u32) 268435456
#define DAC      (u32) 536870912



typedef struct{ /* RCC Registers typedef */
u32	CR 		;
u32	CFGR   	;
u32	CIR		;
u32	APB2RSTR;
u32	APB1RSTR;
u32 AHBENR	;
u32	APB2ENR	;
u32	APB1ENR	;
u32	BDCR   	;
u32	CSR  	;
}RCC_t ;
/* =============================================================== */
#define RCC    ((volatile RCC_t*)(RCC_BASE_ADDR))
/* =============================================================== */
#define FlASH_ACR   (( volatile u32*)0x40022000)
#define LATENCY_OFFSET  0
/* =============================================================== */
typedef struct {     /* Flash Typedef */
u32    Reserved ;
u32	BKP_DR1 ;
u32	BKP_DR2 ;
u32	BKP_DR3 ;
u32	BKP_DR4 ;
u32	BKP_DR10 ;
u32	BKP_RTCCR ;
u32	BKP_CR ;
u32	BKP_CSR ;
u32	BKP_DR11 ;
u32	BKP_DR12 ;
u32	BKP_DR13 ;
u32	BKP_DR14 ;
u32	BKP_DR15 ;
u32	BKP_DR16 ;
u32	BKP_DR17 ;
u32	BKP_DR18 ;
u32	BKP_DR19 ;
u32	BKP_DR20 ;
u32	BKP_DR21 ;
u32	BKP_DR22 ;
u32	BKP_DR23 ;
u32	BKP_DR24 ;
u32	BKP_DR25 ;
u32	BKP_DR26 ;
u32	BKP_DR27 ;
u32	BKP_DR28 ;
u32	BKP_DR29 ;
u32	BKP_DR30 ;
u32	BKP_DR31 ;
u32	BKP_DR32 ;
u32	BKP_DR33 ;
u32	BKP_DR34 ;
u32	BKP_DR35 ;
u32	BKP_DR36 ;
u32	BKP_DR37 ;
u32	BKP_DR38 ;
u32	BKP_DR39 ;
u32	BKP_DR40 ;
u32	BKP_DR41 ;
u32	BKP_DR42 ;
}FLASH_t;
/* =============================================================== */




#endif /* RCC_NEW_RCC_PRIVATE_H_ */
