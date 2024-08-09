/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module: -Port
 *
 *  Description:  Port_configuration header file
 *
 *********************************************************************************************************************/
#ifndef PORT_LCFG_H
#define PORT_LCFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "../../common/Std_Types.h"
#include "PORT_types.h"
/****************************************************************************************************************************
 * 	CONFIGURABLE MACROS
 ****************************************************************************************************************************/
#define PREDEF_USED_PINS 10
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
/* Port A Channels */
	PORT_A0 = 0,PORT_A1,PORT_A2,PORT_A3,PORT_A4,PORT_A5,PORT_A6,PORT_A7,
	PORT_A8,PORT_A9,PORT_A10,PORT_A11,PORT_A12,PORT_A13,PORT_A14,PORT_A15 ,
/* Port B Channels */
		PORT_B0,PORT_B1,PORT_B2,PORT_B3,PORT_B4,PORT_B5,PORT_B6,PORT_B7,
		PORT_B8,PORT_B9,PORT_B10,PORT_B11,PORT_B12,PORT_B13,PORT_B14,PORT_B15,
/* Port C Channels */
				PORT_C0,PORT_C1,PORT_C2,PORT_C3,PORT_C4,PORT_C5,PORT_C6,PORT_C7,
				PORT_C8,PORT_C9,PORT_C10,PORT_C11,PORT_C12,PORT_C13,PORT_C14,PORT_C15
}																						Port_PinType;
typedef enum {
PORT_PIN_IN,
		PORT_PIN_OUT
}					Port_PinDirectionType;
typedef enum { /* 0 -- >15 , 12 reserved , 8 for pull (check down or up) */
IN_ANALOG = 0x0,
		OUT_PUSHPULL_10MHZ, OUT_PUSHPULL_2MHZ, OUT_PUSHPULL_50MHZ ,
IN_FLOATING ,   /* floating */
		OUT_OPENDRAIN_10MHZ, OUT_OPENDRAIN_2MHZ, OUT_OPENDRAIN_50MHZ ,
IN_PULL, /* pull type */
				AFIO_OUT_PUSHPULL_10MHZ, AFIO_OUT_PUSHPULL_2MHZ, AFIO_OUT_PUSHPULL_50MHZ ,
RESERVED , /* Reserved */
				AFIO_OUT_OPENDRAIN_10MHZ, AFIO_OUT_OPENDRAIN_2MHZ, AFIO_OUT_OPENDRAIN_50MHZ
}Port_PinModeType;

/* Pull Mode Type */
typedef enum {
PULL_DOWN = 0 , PULL_UP
}Port_PinPullType;

/* Pin Initial State Type */
typedef enum {
PORT_PIN_LOW , PORT_PIN_HIGH
}Port_InitialStateType;

typedef struct {
Port_PinType ChannelId ;
Port_PinDirectionType Direction ;
Port_PinModeType Mode ;
Port_PinPullType Pull ;
Port_DirectionChangable Changeability ; // true or false
Port_InitialStateType InitialState ;
}Port_ConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif  /* PORT_LCFG_H */

/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.h
 *********************************************************************************************************************/
