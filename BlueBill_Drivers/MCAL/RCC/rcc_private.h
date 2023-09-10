/*
 * rcc_private.h
 * 						""	 		TO a Way Full of Experiences & Successes		""
 *    						""	 	Author: Mohamed Ahmed "ABO KHALIL" 			""
 *    						 	"" 				Version 1.0				 	 ""
 *    						 	   ""            Layer: MCAL               ""
 *    								 ""	   Created on: Aug 10, 2023 	""
 */
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_
#include "../../utilities/std_types.h"
// Registers Addresses
#define RCC_BASE_ADDR       0x40021000
#define RCC    ((RCC_t*)(RCC_BASE_ADDR))
//Registers Macros
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
//*********************
#define ENABLED 1
#define DISABLED 0
#define BYPASS 0
#define CRYSTAL 1


#define HCLK_NO_DIV 0b000
#define HCLK_DIV2 0b100
#define HCLK_DIV4 0b101
#define HCLK_DIV8 0b110
#define HCLK_DIV16 0b111
#define SYSCLK_NO_DIV	0b0000
#define SYSCLK_DIV2		0b1000
#define SYSCLK_DIV4		0b1001
#define SYSCLK_DIV8		0b1010
#define SYSCLK_DIV16	0b1011
#define SYSCLK_DIV64	0b1100
#define SYSCLK_DIV128	0b1101
#define SYSCLK_DIV256	0b1110
#define SYSCLK_DIV512	0b1111
#define MCO_SYSCLK   0b100
#define MCO_HSI   0b101
#define MCO_HSE     0b110
#define MCO_PLL_DIV_2  0b111
#define MCO_NO_CLK		0b000

// Registers Typedefs


typedef struct{
uint32_t	RCC_CR ;
uint32_t	RCC_CFGR;
uint32_t	RCC_CIR;
uint32_t	RCC_APB2RSTR;
uint32_t	RCC_APB1RSTR;
uint32_t    RCC_AHBENR;
uint32_t	RCC_APB2ENR;
uint32_t	RCC_APB1ENR;
uint32_t	RCC_BDCR;
uint32_t	RCC_CSR;
}RCC_t ;

typedef enum
{
Out_NOCLK,
Out_SYSCLK,
Out_HSI ,
Out_HSE ,
Out_PLL_Div_2
}Out_MCO_t;



#define FlASH_ACR   *(( volatile uint32_t*)0x40022000)
#define LATENCY_OFFSET  0


typedef struct {
uint32_t    Reserved ;
uint32_t	BKP_DR1 ;
uint32_t	BKP_DR2 ;
uint32_t	BKP_DR3 ;
uint32_t	BKP_DR4 ;
uint32_t	BKP_DR10 ;
uint32_t	BKP_RTCCR ;
uint32_t	BKP_CR ;
uint32_t	BKP_CSR ;
uint32_t	BKP_DR11 ;
uint32_t	BKP_DR12 ;
uint32_t	BKP_DR13 ;
uint32_t	BKP_DR14 ;
uint32_t	BKP_DR15 ;
uint32_t	BKP_DR16 ;
uint32_t	BKP_DR17 ;
uint32_t	BKP_DR18 ;
uint32_t	BKP_DR19 ;
uint32_t	BKP_DR20 ;
uint32_t	BKP_DR21 ;
uint32_t	BKP_DR22 ;
uint32_t	BKP_DR23 ;
uint32_t	BKP_DR24 ;
uint32_t	BKP_DR25 ;
uint32_t	BKP_DR26 ;
uint32_t	BKP_DR27 ;
uint32_t	BKP_DR28 ;
uint32_t	BKP_DR29 ;
uint32_t	BKP_DR30 ;
uint32_t	BKP_DR31 ;
uint32_t	BKP_DR32 ;
uint32_t	BKP_DR33 ;
uint32_t	BKP_DR34 ;
uint32_t	BKP_DR35 ;
uint32_t	BKP_DR36 ;
uint32_t	BKP_DR37 ;
uint32_t	BKP_DR38 ;
uint32_t	BKP_DR39 ;
uint32_t	BKP_DR40 ;
uint32_t	BKP_DR41 ;
uint32_t	BKP_DR42 ;
}FLASH_t;





#endif /* RCC_PRIVATE_H_ */
