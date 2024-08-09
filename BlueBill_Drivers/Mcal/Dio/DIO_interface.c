/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        @file  Dio.c
 *        @brief : Dio interface source file 
 *
 *      @details
 *				Dio Source file
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "DIO_interface.h"
/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/
static volatile GPIO_t* DIO_PortArr[PORTS_COUNT] = {(DIO_GPIOA),(DIO_GPIOB),(DIO_GPIOA)} ;
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static Channel_Direction_t Get_Channel_Direction(Dio_ChannelType ChannelID) ;
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : static Channel_Direction_t Get_Channel_Direction(Dio_ChannelType ChannelId)
* \Description     : Local Function returns the direction of the Channel
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId Dio_ChannelType
* \Parameters (out): None
* \Return value:   : Channel_Direction_t  INPUT_STATE
*                                    	  PUSHPULL_STATE
*                                    	  OPENDRAIN_STATE
*******************************************************************************/
static Channel_Direction_t Get_Channel_Direction(Dio_ChannelType ChannelId){
	/* Get pin number from Channel ID */

	u8 pin = ChannelId % PINS_COUNT ;

	/* Initial value */

	u8 mode_val = 0 ;
	u8 cnf_val = 0 ;

	Dio_PortType port = (u8)(ChannelId/PINS_COUNT); /* Get the Port from ChannelId */
	 if ((port <= DIO_PORTC) && (pin < PINS_COUNT))
	 {		/* Get the Mode of the Pin  */
			mode_val = (DIO_PortArr[port]->CRL && (DIO_MASK<<(pin * 4))) >> (pin * 4) ;
			if (mode_val == INPUT_STATE)
			{
				return INPUT_STATE ;
			}
			else
			{
				/* get the value of configuration register */
				cnf_val = (DIO_PortArr[port]->CRL && (DIO_MASK << ((pin * 4) + 2))) >>((pin * 4) + 2) ;
				if (cnf_val % 2 == 0)
				{
					return PUSHPULL_STATE ;
				}
				else
				{
					return OPEN_DRAIN_STATE ;
				}
			}
	 }
	 else
	 {
			return CHANNEL_DIR_ERROR ;
	 }
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
/******************************************************************************
* \Syntax          : Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId)
* \Description     : Read the Level of Dio Channel
* \Service ID [hex]: 0x00
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId   Dio_ChannelType
* \Parameters (out): None
* \Return value:   : Dio_LevelType  STD_LOW - STD_HIGH
*
*******************************************************************************/
Dio_LevelType Dio_ReadChannel (Dio_ChannelType ChannelId){
	u8 pin = ChannelId % PINS_COUNT ; /* Pin value <0 ---> 15> */
	Dio_PortType port = ChannelId / PINS_COUNT ;
	Dio_LevelType ret = STD_INVALID  ; /* initialized with invalid value */

	Channel_Direction_t Dir = Get_Channel_Direction(ChannelId) ;

	if ((Dir == INPUT_STATE) || (Dir == OPEN_DRAIN_STATE))
	{
			if ((port  < PORTS_COUNT) && (pin < PINS_COUNT))
			{
					/* Read the value of the Pin from IDR Register */
					ret = (DIO_PortArr[port]->IDR & (BIT_MASK << pin)) >> pin ;
			}
	}
	else if (Dir == PUSHPULL_STATE)
	{
		if ((port  < PORTS_COUNT) && (pin < PINS_COUNT))
		{
			/* Read the value of the Pin from IDR Register */
			ret = (DIO_PortArr[port]->ODR & (BIT_MASK << pin)) >> pin ;
		}
	}
	else
	{
		/* Trap Error */
	}
	return ret ;
}

/******************************************************************************
* \Syntax          : Std_ReturnType Dio_WriteChannel(DioChannel_Type ChannelId,Dio_LevelType Level)
* \Description     : This Service Writes a level to a channel
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId   Dio_ChannelType ,
* 				     Level 		 Dio_LevelType
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
Std_ReturnType Dio_WriteChannel(Dio_ChannelType ChannelId , Dio_LevelType Level){
	Std_ReturnType ret = E_OK ;
	u8  pin = ChannelId % PINS_COUNT ;  // < 0 ---> 15 >
	Dio_PortType port = ChannelId / PINS_COUNT ;
			/* Validate the Pin and the Port */
		 if ((pin < PINS_COUNT) && (port < PORTS_COUNT))
		 {
			 /* Check the Entered Level */
			 if ((Level != STD_HIGH) && (Level != STD_LOW)){
				 ret = E_NOT_OK ;
			 }
			 else {
				 /* change the Level of the Pin */
			 (STD_HIGH == Level) ? (DIO_PortArr[port]->ODR |= ( BIT_MASK << pin )) :
					 (DIO_PortArr[port]->ODR &= ~( BIT_MASK << pin )) ;
			 }
		 }
		 else
		 {
			 /* Trap Error */
			ret = E_NOT_OK ;
		 }
return ret ;
}
/******************************************************************************
* \Syntax          : Std_ReturnType Dio_FlipChannel(Dio_ChannelType ChannelId)
* \Description     : Flips The Level of a channel
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId   Dio_ChannelType
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
Std_ReturnType Dio_FlipChannel(Dio_ChannelType ChannelId){
	Std_ReturnType ret = E_OK ;
	u8 pin = ChannelId % PINS_COUNT ;
	Dio_PortType port = ChannelId / PINS_COUNT ;
		/* Validate the Pin and The Port */
		if ((pin < PINS_COUNT) && (port < PORTS_COUNT))
		 {
			/* Flip The Desired Pin */
			DIO_PortArr[port]->ODR ^= ( BIT_MASK << pin )  ;
		 }
		 else
		 {
			 /* Trap Error */
			ret = E_NOT_OK ;
		 }
	return ret ;
}
/******************************************************************************
* \Syntax          : Std_ReturnType Dio_WriteChannelAtomic(DioChannel_Type ChannelId,Dio_LevelType Level)
* \Description     : This Service Writes a level to a channel (Atomically)
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Reentrant
* \Parameters (in) : ChannelId   Dio_ChannelType ,
* 				     Level 		 Dio_LevelType
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/
Std_ReturnType Dio_WriteChannelAtomic(Dio_ChannelType ChannelId , Dio_LevelType Level){
	Std_ReturnType ret = E_OK ;
	u8  pin = ChannelId % PINS_COUNT ;  // < 0 ---> 15 >
	Dio_PortType port = ChannelId / PINS_COUNT ;
	if (STD_HIGH == Level)
	{
		/* SET The Channel from BSRR register */
		DIO_PortArr[port]->BSRR = (BIT_MASK << pin ) ;
	}
	else if (STD_LOW == Level)
	{
		/* reset the Channel from BSRR register */
		DIO_PortArr[port]->BSRR = (BIT_MASK << (pin + PINS_COUNT) ) ;
	}
	else {
		ret = E_NOT_OK ;
	}
return ret ;
}

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
