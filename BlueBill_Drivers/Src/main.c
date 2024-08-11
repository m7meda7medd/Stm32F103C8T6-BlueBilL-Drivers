/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */
#include <stdint.h>
#include <stdio.h>

#include "../Mcal/Dio/DIO_interface.h"
#include "../Mcal/Port/PORT_interface.h"
#include "../Mcal/RCC_new/RCC_interface.h"
#include "../Mcal/NVIC/NVIC_interface.h"
extern Port_ConfigType PortCfg[PREDEF_USED_PINS] ;

SystemClockConfig_t systemclockconfig ={
		.sysClkSource=HSI,
		.AHB_Prescaler=NO_DIV,
		.APB1Prescaler=NO_DIV,
		.APB2Prescaler=NO_DIV,
		
};


int main(void)
{
	RCC_SystemClockConfig(&systemclockconfig) ;
	RCC_EnablePeripheralClock(APB2, GPIOA | GPIOB | GPIOC | USART1) ;
	Port_Init(PortCfg) ;
	Dio_WriteChannel(DIO_C13, STD_LOW) ;
	NVIC_EnableIRQ(USART1_IRQ) ;
	NVIC_SetPendingIRQ(USART1_IRQ) ;


	/* Some Initializations of PSP */

	while (1)
	{

	Dio_WriteChannel(DIO_C13, STD_HIGH) ;

	}
}

void USART1_IRQHandler (void){

Dio_WriteChannel(DIO_C13, STD_LOW) ;
}

