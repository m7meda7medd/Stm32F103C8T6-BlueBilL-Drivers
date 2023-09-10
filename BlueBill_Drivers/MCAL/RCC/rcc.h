/*
 * rcc.h
 * 						""	 		TO a Way Full of Experiences & Successes		""
 *    						""	 	Author: Mohamed Ahmed "ABO KHALIL" 			""
 *    						 	"" 				Version 1.0				 	 ""
 *    						 	   ""        Layer: MCAL                   ""
 *    								 ""	   Created on: Aug 10, 2023 	""
 */


// Include Guards to prevent multiple inclusion
#ifndef RCC_H_
#define RCC_H_
 // Includes
#include "rcc_cnfig.h"
#include "../utilities/std_types.h"
#include "rcc_private.h"
#include <stdarg.h>
#include <stdio.h>
// ---------------------------
// Comments and Documentation
// --------------------------

// Preprocessor Directives
#define REG_ADDR(oxBASE,oxOFFSET)     (	oxBASE	+	oxOFFSET	)
// -----------------------

// Forward Declarations
// ---------------------
// Type Definitions and Enumerations
typedef enum
		{
	RCC_AHB,
	RCC_APB1,
	RCC_APB2
		}Bus_t ;
typedef enum
{// AHB Peripherals Enable
     DMA1,
     DMA2,
     SRAM,
     Reserved_10,
     FLITF,
     Reserved_9,
     CRC,
     Reserved_8,
     FSMC,
     Reserved_7,
     SDIO,
	// from 0 till 6
//*************************
// APB2 Peripherals Enable
	// from  7 till 21
    AFIO= 0,
    Reserved_0,
    IOA,
    IOB,
    IOC,
    IOD,
    GPIOE,
    GPIOF,
    GPIOG,
    ADC1,
    ADC2,
    TIM1,
    SPI1,
    TIM8,
    USART1,
    ADC3,
    Reserved_1,
	Reserved_3,
	Reserved_4,
    TIM9,
    TIM10,
    TIM11,
//****************************
// APB1 Peripherals able
	// from 0 till 29
  TIM2 =0,
  TIM3,
  TIM4,
  TIM5,
  TIM6,
  TIM7,
  TIM12,
  TIM13,
  TIM14,
  WWDG=11,
  SPI2=14,
  SPI3,
  Reserved_5,
  USART2,
  USART3,
  UART4,
  UART5,
  I2C1,
  I2C2,
  USB,
  Reserved_6_2,
  CAN,
  Reserved_7_1,
  BKP,
  PWR,
  DAC,
//**********************************
}Peripheral_t;


typedef enum
{
HSE,
PLL,
HSI,
}CLK_t;

typedef enum
{
NO_DIV =1,
DIV_2 = 2 ,
DIV_4 = 4 ,
DIV_8 =8,
DIV_16 = 16,
DIV_64 = 64,
DIV_128 = 128,
DIV_256 = 256,
DIV_512 = 512
}PRE_t;
typedef struct {
	CLK_t sysClkSource;
	PRE_t AHBPrescaler;
	PRE_t APB1Prescaler;
	PRE_t APB2Prescaler ;
	Out_MCO_t  MCO_OutSrc ;
}RCCConfig_t;

 // Must not excedded 36MHZ
// ---------------------------------
// Macro Definitions
// ------------------

// Function Declarations
void vRCC_Init(const RCCConfig_t* RCCconfig) ;
void vRCC_SetSystemClock(CLK_t sysClkSource, PRE_t AHBPrescaler, PRE_t APB1Prescaler, PRE_t APB2Prescaler);
void vRCC_EnablePeripheralClock( Bus_t BusName , Peripheral_t PeripheralName ) ;
void vRCC_DisablePeripheralClock(Bus_t BusName , Peripheral_t PeripheralName);
void vRCC_ResetPeripheral(Bus_t BusName , Peripheral_t PeripheralName);
void vRCC_EnableMCO(Out_MCO_t OutCLK) ;
// ----------------------

// Constant Definitions
// ---------------------




// Global Variables
// -----------------

// Conditional Compilation Blocks
// ------------------------------






#endif /* RCC_H_ */
// --------------------------------------------
