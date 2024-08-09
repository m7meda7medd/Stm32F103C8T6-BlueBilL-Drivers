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
#include "PORT_interface.h"
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

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/


/******************************************************************************
* \Syntax          : Std_ReturnType Port_Init(const Port_ConfigType* PortCfg )
* \Description     : Initialize all Used Pins
*
* \Sync\Async      : Synchronous
* \Reentrancy      : Non Reentrant
* \Parameters (in) : PortCfg   Pointer to const Port_ConfigType
* \Parameters (out): None
* \Return value:   : Std_ReturnType  E_OK
*                                    E_NOT_OK
*******************************************************************************/

Std_ReturnType Port_Init(const Port_ConfigType* PortCfg ){
	Std_ReturnType ret = E_OK ;
	u8 pin , Mode ;
	Port__PortType port  ;

	if (NULL == PortCfg)
	{
		/* Error Accessing NULL Pointer */
		ret = E_NOT_OK ;

	}
	else
	{

		for (u8 u8_index = 0 ; u8_index <PREDEF_USED_PINS ; u8_index++)
		{
			port =(PortCfg[u8_index].ChannelId)/16 ;
			pin = (PortCfg[u8_index].ChannelId)%16 ;
			Mode = (PortCfg[u8_index].Mode) ;
			switch (port)
			{
				case PORT_PORTA :
					if (pin <= PORT_A7)
						{

							PORT_GPIOA->CRL &=~(0b1111 << ( pin * 4))  ; /* Clear bits of CRL Register */
							PORT_GPIOA->CRL |=(Mode << (pin * 4) )   ;
						}
					else
						{
							PORT_GPIOA->CRH &= ~(0b1111 << ((pin-8) * 4) ) ;// Clear Bits
							PORT_GPIOA->CRH |=   (Mode << ((pin-8) * 4) )   ;
						}
					/* Setting Pull Down and Pull Up and Output initialized Values */
					if (IN_PULL == Mode)
					{
						switch (PortCfg[u8_index].Pull)
						{
							case PULL_DOWN :
								CLR_BIT(PORT_GPIOA->ODR,pin) ;
								break ;
							case PULL_UP:
								SET_BIT(PORT_GPIOA->ODR,pin) ; ;
								break ;
							default :
								// Not Pull Pin
						}
					}
					break ;
					case PORT_PORTB :
						if (pin <= PORT_A7 )
						{
							PORT_GPIOB->CRL &=~(0b1111 << (pin * 4) ) ;// Clear Bits
							PORT_GPIOB->CRL |=(Mode << (pin * 4))   ;
						}
						else
						{
							PORT_GPIOB->CRH &= ~(0b1111 << ((pin-8) * 4) ) ;// Clear Bits
							PORT_GPIOB->CRH |=   (Mode << ((pin-8) * 4) )   ;
						}
						// Handle Pull_Down and Pull_Up and Output initialized Values
						if (IN_PULL == Mode)
						{
							switch (PortCfg[u8_index].Pull)
							{
								case PULL_DOWN :
									CLR_BIT(PORT_GPIOB->ODR,pin) ;
									break ;
								case PULL_UP:
									SET_BIT(PORT_GPIOB->ODR,pin) ; ;
									break ;
								default :
									// error
									// invalid configuration
							}
						}
						break ;
					case PORT_PORTC :
						if (pin <= PORT_A7)
						{
							PORT_GPIOC->CRL &=~(0b1111 << (pin * 4) ) ;// Clear Bits
							PORT_GPIOC->CRL |=(Mode << (pin * 4))   ;
						}
						else
						{
							PORT_GPIOC->CRH &= ~(0b1111 << ((pin - 8) * 4) ) ; // Clear Bits
							PORT_GPIOC->CRH |=   (Mode << ((pin - 8) * 4) )   ;
						}
						// Setting Pull up and Pull down and Output  initialized Values
						if (IN_PULL == Mode)
						{
							switch (PortCfg[u8_index].Pull)
							{
								case PULL_DOWN :
									CLR_BIT((PORT_GPIOC->ODR),pin) ;
									break ;
								case PULL_UP:
									SET_BIT((PORT_GPIOC->ODR),pin) ; ;
									break ;
								default :
									// error
									// invalid configuration
							}
						}
						break ;
					default :
						ret = E_NOT_OK ;
				}
			// Initialize Output Pins Values
			if (PortCfg[u8_index].Direction == PORT_PIN_OUT)
			{
				switch (port)
				{
				case PORT_PORTA :
					(PortCfg[u8_index].InitialState == PORT_PIN_HIGH) ? (SET_BIT((PORT_GPIOA->ODR),pin)) : (CLR_BIT((PORT_GPIOA->ODR),pin)) ;
					break ;
				case PORT_PORTB :
					(PortCfg[u8_index].InitialState == PORT_PIN_HIGH) ? (SET_BIT((PORT_GPIOB->ODR),pin)) : (CLR_BIT((PORT_GPIOB->ODR),pin)) ;
					break ;
				case PORT_PORTC :
					(PortCfg[u8_index].InitialState == PORT_PIN_HIGH) ? (SET_BIT((PORT_GPIOC->ODR),pin)) : (CLR_BIT((PORT_GPIOC->ODR),pin)) ;
					break ;
				default :
					//error

				}
			}
		}

	}
	return ret ;
}


/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
