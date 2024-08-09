/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio_Prv.h
 *       Module:  Dio
 *
 *  Description:  Dio Private File
 *
 *********************************************************************************************************************/
#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

/**********************************************************************************************************************
 *INCLUDES
 *********************************************************************************************************************/
#include "../../common/Std_Types.h"
#include "../../common/Mcu_Hw.h"
/*********************************************************************************************************************
**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
*********************************************************************************************************************/
typedef struct
{
volatile u32 CRL  ;
volatile u32 CRH  ;
volatile u32 IDR  ;
volatile u32 ODR  ;
volatile u32 BSRR ;
volatile u32 BRR  ;
volatile u32 LCKR ;
}GPIO_t;
/*  Current Channel Direction Typedef  */
typedef enum {
CHANNEL_DIR_ERROR = -1 ,
INPUT_STATE = 0 ,
PUSHPULL_STATE  ,
OPEN_DRAIN_STATE ,
}Channel_Direction_t ;
/**********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#ifndef DIO_GPIOA
#define DIO_GPIOA     ((volatile GPIO_t* )GPIOA_BASE_ADDR)
#define DIO_GPIOB     ((volatile GPIO_t*)GPIOB_BASE_ADDR)
#define DIO_GPIOC     ((volatile GPIO_t*)GPIOC_BASE_ADDR)
#endif
/**********************************************************************************************************************
 *  Private Constant MACROS
 *********************************************************************************************************************/
#define  DIO_MASK    0x00000003u
#define  PORTS_COUNT 3
#define  PINS_COUNT  16
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/


 /*  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif  /* DIO_PRIVATE_H */

/**********************************************************************************************************************
 *  END OF FILE: Dio_Private.h
 *********************************************************************************************************************/


