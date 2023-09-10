/*
 * gpio.h
 * 						""	 		TO a Way Full of Experiences & Successes		""
 *    						""	 	Author: Mohamed Ahmed "ABO KHALIL" 			""
 *    						 	"" 				Version 1.0				 	 ""
 *    						 	   ""            Layer: MCAL               ""
 *    								 ""	   Created on: SEP 5, 2023 	""
 */
#ifndef GPIO_H_
#define GPIO_H_
#include "../utilities/std_types.h"
#include "gpio_private.h"
#include "gpio_cnfig.h"

//******************** PinConfig Modes ***************************
#define IN_ANALOG 0b0000
#define IN_FLOATING 0b0100
#define IN_PULL 0b1000
#define OUT_PUSH_PULL_10MHZ 0b0001
#define OUT_PUSH_PULL_2MHZ 0b0010
#define OUT_PUSH_PULL_50MHZ 0b0011
#define OUT_OPEN_DRAIN_10MHZ 0b0101
#define OUT_OPEN_DRAIN_2MHZ  0b0110
#define OUT_OPEN_DRAIN_50MHZ 0b0111
#define AFIO_OUT_PUSH_PULL_10MHZ 0b1001
#define AFIO_OUT_PUSH_PULL_2MHZ 0b1010
#define AFIO_OUT_PUSH_PULL_50MHZ 0b1011
#define AFIO_OUT_OPEN_DRAIN_10MHZ 0b1101
#define AFIO_OUT_OPEN_DRAIN_2MHZ  0b1110
#define AFIO_OUT_OPEN_DRAIN_50MHZ 0b1111
// Modes ***************************
//**********************Directions****************************
#define INPUT  0
#define OUTPUT 1
//**************************************
#define NONE  0
#define PULL_UP 1
#define PULL_DOWN 2
typedef enum {
Pin_0,
Pin_1,
Pin_2,
Pin_3,
Pin_4,
Pin_5,
Pin_6,
Pin_7,
Pin_8,
Pin_9,
Pin_10,
pin_11,
Pin_12,
Pin_13,
Pin_14,
pin_15
}Pin_t;
typedef enum {
Port_A ,
Port_B ,
Port_C
}Port_t;
typedef enum
{
R_OK ,
R_NOK
}state_type_t;

typedef struct
{
Pin_t Pin ;
Port_t Port ;
uint8_t Mode ;
uint8_t Direction ;
//case of Output Pin
State_t State ;
// case of Pull (PULL_UP-PULL_DOWN)
uint8_t Pull ;
}PinConfig_t;


state_type_t GPIO_Init(const PinConfig_t* Pin) ;
state_type_t GPIO_SetPinValue(const PinConfig_t* Pin,State_t Value) ;
state_type_t  GPIO_ReadPin(const PinConfig_t* Pin ,uint8_t*Ret_Val) ;
state_type_t GPIO_TogglePin(const PinConfig_t* Pin);







#endif
