/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl.h
 *       Module:  INTCTRL
 *
 *  Description:  Header file for interrupts control module
 *
 *********************************************************************************************************************/
#ifndef NVIC_NVIC_INTERFACE_H
#define NVIC_NVIC_INTERFACE_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../common/Std_Types.h"
#include "../../common/compiler.h"
#include "../../common/stm32f103c8t6.h"
#include "NVIC_private.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum {
WWDG_IRQ,PVD_IRQ,TAMPER_IRQ,RTC_IRQ,FLASH_IRQ,RCC_IRQ,
EXTI0_IRQ,EXTI1_IRQ,EXTI2_IRQ,EXTI3_IRQ,EXTI4_IRQ,
DMA1_Channel1_IRQ,DMA1_Channel2_IRQ,DMA1_Channel3_IRQ,DMA1_Channel4_IRQ,DMA1_Channel5_IRQ,DMA1_Channel6_IRQ,DMA1_Channel7_IRQ,
ADC1_2_Global_IRQ,
USB_HP_CAN_TX_IRQ, USB_LP_CAN_RX0_IRQ,
CAN_RX1_IRQ,CAN_SCE_IRQ,
EXTI9_5_IRQ,
TIM1_BRK_IRQ,TIM1_UP_IRQ,TIM1_TRG_COM_IRQ,TIM1_CC_IRQ,
TIM2_IRQ,TIM3_IRQ,TIM4_IRQ,I2C1_EV_IRQ,I2C1_ER_IRQ,I2C2_EV_IRQ,I2C2_ER_IRQ,SPI1_IRQ,SPI2_IRQ,USART1_IRQ,USART2_IRQ,USART3_IRQ,EXTI15_10_IRQ,RTCAlarm_IRQ,USBWakeup_IRQ,TIM8_BRK_IRQ,TIM8_UP_IRQ,
TIM8_TRG_COM_IRQ,TIM8_CC_IRQ,ADC3_IRQ,
FSMC_IRQ,
SDIO_IRQ,
TIM5_IRQ,
SPI3_IRQ,
UART4_IRQ,UART5_IRQ,
TIM6_IRQ,TIM7_IRQ,
DMA2_Channel1_IRQ,DMA2_Channel2_IRQ,DMA2_Channel3_IRQ,DMA2_Channel4_5_IRQ
}IRQn_Type;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void NVIC_EnableIRQ(IRQn_Type IRQn);
void NVIC_DisableIRQ(IRQn_Type IRQn);

//void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority);
//u32 NVIC_GetPriority(IRQn_Type IRQn);

void NVIC_SetPendingIRQ(IRQn_Type IRQn);
void NVIC_ClearPendingIRQ(IRQn_Type IRQn);
u8 NVIC_GetPendingIRQ(IRQn_Type IRQn);

u8 NVIC_GetActive(IRQn_Type IRQn);

void NVIC_SystemReset(void);

void NVIC_SetPriorityGrouping(u32 PriorityGroup);
u32 NVIC_GetPriorityGrouping(void);




#endif  /* NVIC_H */

/**********************************************************************************************************************
 *  END OF FILE: nvic_interface.h 
 *********************************************************************************************************************/
