/*
 * Port_Prv.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Mohamed Ahmed
 */

#ifndef PORT_PORT_PRIVATE_H_
#define PORT_PORT_PRIVATE_H_
#include "../../common/stm32f103c8t6.h"
#include "../../common/Std_Types.h"

typedef struct
{
volatile u32 CRL  ;
volatile u32 CRH  ;
volatile u32 IDR  ;
volatile u32 ODR  ;
volatile u32 BSRR ;
volatile u32 BRR  ;
volatile u32 LCKR ;
}PORT_GPIO_t;

#define PORT_GPIOA     ((volatile PORT_GPIO_t* )GPIOA_BASE_ADDR)
#define PORT_GPIOB     ((volatile PORT_GPIO_t*)GPIOB_BASE_ADDR)
#define PORT_GPIOC     ((volatile PORT_GPIO_t*)GPIOC_BASE_ADDR)

#endif /* PORT_PORT_PRIVATE_H_ */
