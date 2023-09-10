/*
 * gpio_private.h
 * 						""	 		TO a Way Full of Experiences & Successes		""
 *    						""	 	Author: Mohamed Ahmed "ABO KHALIL" 			""
 *    						 	"" 				Version 1.0				 	 ""
 *    						 	   ""            Layer: MCAL               ""
 *    								 ""	   Created on: SEP 5, 2023 	""
 */
#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


typedef struct
{
uint32_t CRL ;
uint32_t CRH ;
uint32_t IDR  ;
uint32_t ODR  ;
uint32_t BSRR ;
uint32_t BRR  ;
uint32_t LCKR ;
}GPIO_t;

#define GPIOA     ((volatile GPIO_t* )0x40010800)
#define GPIOB     ((volatile GPIO_t*)0x40010C00)
#define GPIOC     ((volatile GPIO_t*)0x40011000)

//******************************Private****************************************

#endif
