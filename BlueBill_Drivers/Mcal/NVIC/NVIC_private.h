/*
 * NVIC_private.h
 *
 *  Created on: Jun 29, 2024
 *      Author: Mohamed Ahmed
 */

#ifndef NVIC_NVIC_PRIVATE_H_
#define NVIC_NVIC_PRIVATE_H_

typedef struct {

	volatile u32 EXTI_IMR ;
	volatile u32 EXTI_EMR ;
	volatile u32 EXTI_RTSR ;
	volatile u32 EXTI_FTSR ;
	volatile u32 EXTI_SWIER ;
	volatile u32 EXTI_PR ;
}EXTI_RegDef_t;




typedef struct {

	volatile u32 NVIC_ISER[3] ;
	volatile u32 Reserved_1[29] ;
	volatile u32 NVIC_ICER[3] ;
	volatile u32 Reserved_2[29] ;
	volatile u32 NVIC_ISPR [3] ;
	volatile u32 Reserved_3 [29] ;
	volatile u32 NVIC_ICPR[3] ;
	volatile u32 Reserced_4[29];
	volatile u32 NVIC_IABR[3] ;
	volatile u32 Reserced_5[61];
	volatile u8 NVIC_IPR[84] ;
	volatile u32 Reserced_6[683];
	volatile u32 NVIC_STIR ;
}NVIC_RegDef_t;

#define NVIC_REG    	((NVIC_RegDef_t*) NVIC_BASE_ADDR)

#endif /* NVIC_NVIC_PRIVATE_H_ */
