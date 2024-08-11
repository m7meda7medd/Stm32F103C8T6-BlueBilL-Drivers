/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "NVIC_interface.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
/* Enable IRQn */
void NVIC_EnableIRQ(IRQn_Type IRQn){
	/* get the index of ISE Register */
	u8 index = 	   IRQn / 32 ;
	u8 IRQn_bit =  IRQn % 32 ;

	/* from 0 ---- 31 in the ISER[0] */
	/* from 32 ------ 63 in ISER[1] */
	NVIC_REG->NVIC_ISER[index] |= (BIT_MASK << IRQn_bit) ;
}

/* Disable Interrupt */
void NVIC_DisableIRQ(IRQn_Type IRQn){
	/* get the index of ICE Register */
	u8 index = 	   IRQn / 32 ;
	u8 IRQn_bit =  IRQn % 32 ;

	/* from 0 ---- 31 in the ICER[0] */
	/* from 32 ------ 63 in ICER[1] */
	NVIC_REG->NVIC_ICER[index] |= (BIT_MASK << IRQn_bit) ;
}
/* Set Priority of IRQn */
void NVIC_SetPriority(IRQn_Type IRQn, u8 priority);

/* Get the Priority of IRQn */
u8 NVIC_GetPriority(IRQn_Type IRQn);

/* Set Pending flag of IRQn */
void NVIC_SetPendingIRQ(IRQn_Type IRQn){
	/* get the index of ISP Register */
	u8 index = 	   IRQn / 32 ;
	u8 IRQn_bit =  IRQn % 32 ;

	/* from 0 ---- 31 in the ISPR[0] */
	/* from 32 ------ 63 in ISPR[1] */
	NVIC_REG->NVIC_ISPR[index] |= (BIT_MASK << IRQn_bit) ;
}
/* Clear Pending flag of IRQn */
void NVIC_ClearPendingIRQ(IRQn_Type IRQn){
	/* get the index of ICP Register */
	u8 index = 	   IRQn / 32 ;
	u8 IRQn_bit =  IRQn % 32 ;

	/* from 0 ---- 31 in the ICPR[0] */
	/* from 32 ------ 63 in ICPR[1] */
	NVIC_REG->NVIC_ICPR[index] |= (BIT_MASK << IRQn_bit) ;
}
/* Get the Pending flag of IRQn */
u8 NVIC_GetPendingIRQ(IRQn_Type IRQn){
	/* get the index of ICP Register */
	u8 index = 	   IRQn / 32 ;
	u8 IRQn_bit =  IRQn % 32 ;

	/* Return the Pending flag bit of IRQn in ISPR[index] */
	return RETURN_BIT(NVIC_REG->NVIC_ISPR[index],IRQn_bit) ;
}

/* Get the active flag of IRQn */
u8 NVIC_GetActive(IRQn_Type IRQn){
	/* get the index of ICP Register */
	u8 index = 	   IRQn / 32 ;
	u8 IRQn_bit =  IRQn % 32 ;


	return RETURN_BIT(NVIC_REG->NVIC_IABR[index],IRQn_bit) ;
}

void NVIC_SystemReset(void);

void NVIC_SetPriorityGrouping(u32 PriorityGroup);
u32 NVIC_GetPriorityGrouping(void);
/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType FunctionName(AnyType parameterName)
* \Description     : Describe this service
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : parameterName   Parameter Describtion
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
