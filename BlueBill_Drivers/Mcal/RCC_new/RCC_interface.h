/*
 * RCC_interface.h
 *
 *  Created on: Jun 27, 2024
 *      Author: Mohamed Ahmed
 */

#ifndef RCC_NEW_RCC_INTERFACE_H_
#define RCC_NEW_RCC_INTERFACE_H_

/* includes */
#include "RCC_private.h"
/* =============================================================== */

extern u32 SYSCLK_FREQUENCY  ;
extern u8 SYSCLK_SRC ;
#define READY_TIMEOUT_CYCLES   400
#define TIMEOUT_CYCLES         400
/* =============================================================== */
typedef State_t ClockState_t ;
/* =============================================================== */
typedef enum /* System Clock Sources */{
HSI = 0,
HSE,
PLL
}SystemClock_SRC_t;
/* =============================================================== */
typedef enum /* External Clock Type */ {
HSE_RC,
HSE_CrystalorCeramicResounators
}HSE_Clock_t ;
/* =============================================================== */
typedef enum /* MCO pin Output  */{
MCO_NOCLK,
MCO_SYSCLK = 4,
MCO_HSI ,
MCO_HSE ,
PLL_DIV2
}MCO_Output_t;
/* =============================================================== */
typedef enum /* Buses Enum */ {
	AHB,
	APB2,
	APB1
}Bus_t ;
/* =============================================================== */
typedef enum /* USB Prescaler */ {
PLL_DIV_3D2,
PLL_NOT_DIV
}USB_Prescaler_t;
/* =============================================================== */
typedef enum /* ADC Prescaler */ {
APB2CLK_DIV_2,
APB2CLK_DIV_4,
APB2CLK_DIV_6,
APB2CLK_DIV_8,
}ADC_Prescaler_t;
/* =============================================================== */
typedef enum /* Pll input Source */ {
HSI_DIV_2,
HSE_NO_DIV,
HSE_DIV_2
}PLL_SRC_t;
/* =============================================================== */
typedef enum /* PLL Multiplication factor (Output PLL frequency must not exceeded 72 MHz */ {
PLL_MUL_2,
PLL_MUL_3,
PLL_MUL_4,
PLL_MUL_5,
PLL_MUL_6,
PLL_MUL_7,
PLL_MUL_8,
PLL_MUL_9,
PLL_MUL_10,
PLL_MUL_11,
PLL_MUL_12,
PLL_MUL_13,
PLL_MUL_14,
PLL_MUL_15,
PLL_MUL_16,
}PLL_MUL_t;
typedef enum /* AHB, APB(1,2) Prescalers */{
NO_DIV  =	4,
DIV_2 	= 	8,
DIV_4	= 	9,
DIV_8 	=	10,
DIV_16	= 	11,
DIV_64 	= 	12,
DIV_128 = 	13,
DIV_256 = 	14,
DIV_512 = 	15
}Prescaler_t;
/* =============================================================== */
typedef struct /* PLL Information */ {
PLL_SRC_t PLL_Source ;
PLL_MUL_t PLL_Mul ;
}PLL_Info_t;
/* =============================================================== */
typedef struct /* System Clock Configuration Struct */{
	SystemClock_SRC_t sysClkSource;
	HSE_Clock_t HSE_Type ; 	/* In Case of HSE Selected as System Clock */
	PLL_Info_t PLL_Info ;	/* In Case of PLL Selected as System Clock */
	Prescaler_t AHB_Prescaler ;
	Prescaler_t APB1Prescaler ; 	/* prescaler must be not exceeded 16 */
	Prescaler_t APB2Prescaler ;		/* prescaler must be not exceeded 16 */
	MCO_Output_t  MCO_OutSrc  ;
}SystemClockConfig_t;
/* =============================================================== */
/* interfaces */
void RCC_SystemClockConfig(const SystemClockConfig_t* systemclockconfig); /* done */
/* Peripherals Clock Enablers and Disablers */
void RCC_EnablePeripheralClock(Bus_t bus , u32 peripheral);  /* done */
void RCC_DisablePeripheralClock(Bus_t bus ,u32 peripheral); /* done */
/* Clocks Config Functions */
void RCC_HSEConfig(HSE_Clock_t HSE_clock ,ClockState_t state); /* done */
void RCC_HSIConfig(ClockState_t state); /* done */
void RCC_PLLConfig(const PLL_Info_t* pll_info, ClockState_t state) ;  /* done */
void RCC_EnableMCO(MCO_Output_t MCO_OutSrc) ; /* done */
/* Select System Clock Function */
void RCC_SelectSysClockSource(SystemClock_SRC_t source);  /* done */
/* prescalers Setters */
void RCC_SetUSBPrescaler(USB_Prescaler_t usbprescaler) ;
void RCC_SetADCPrescaler(ADC_Prescaler_t adcprescaler) ;
/* Interrupts Enablers and Disablers */
void RCC_EnableClockSecuritySystemInterrupt(void) ;
/*
void RCC_EnableInterrupt(RCC_Interrupt_t interrupt)  ;
void RCC_DisableInterrupt(RCC_Interrupt_t interrupt) ;
*/
void RCC_SetTrimval(u32 trimval ) ;

/* ==================================== */

#endif /* RCC_NEW_RCC_INTERFACE_H_ */
