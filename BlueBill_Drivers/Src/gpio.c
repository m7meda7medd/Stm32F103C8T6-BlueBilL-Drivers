/*
 * gpio.c
 * 						""	 		TO a Way Full of Experiences & Successes		""
 *    						""	 	Author: Mohamed Ahmed "ABO KHALIL" 			""
 *    						 	"" 				Version 1.0				 	 ""
 *    						 	   ""            Layer: MCAL               ""
 *    								 ""	   Created on: SEP 5, 2023 	""
 */
#include "../MCAL/GPIO/gpio.h"
#include "../MCAL/RCC/rcc.h"
//#define CRL_MODEx(GPIOx,Dir,MODEx) GPIOx->CRL.MODE##MODEx = Dir
//#define CRH_MODEx(GPIOx,Dir,MODEx) GPIOx->CRH.MODE##MODEx = Dir
//#define CRL_CNFx(GPIOx,Dir,CNFx) GPIOx->CRL.CNF##CNFx  = Dir
//#define CRH_CNFx(GPIOx,Dir,CNFx) GPIOx->CRH.CNF##CNFx = Dir

/*
 *
 * @Brief: This Function is used to Set Direction of the Pin
 *
 *
 *
 * @Parameters : PinConfig_t* Pin "Pointer To structure OF type PinConfig_t"
 *
 *
 * @Return : R_OK  in case of No errors Happen
 *			 R_NOK in case of error Happened
 */



state_type_t GPIO_Init(const PinConfig_t* Pin){
state_type_t ret = R_OK ;
switch (Pin->Port)
{
	case Port_A :
		vRCC_EnablePeripheralClock(RCC_APB2, IOA) ;
		if (Pin->Pin <= Pin_7)
			{
				GPIOA->CRL &=~(0b1111 << ( Pin->Pin * 4))  ;// Clear Bits
				GPIOA->CRL |=(Pin->Mode << (Pin->Pin * 4) )   ;
			}
		else
			{
				GPIOA->CRH &= ~(0b1111 << ((Pin->Pin-8) * 4) ) ;// Clear Bits
				GPIOA->CRH |=   (Pin->Mode << ((Pin->Pin-8) * 4) )   ;
			}
		// Handle Pull_Down and Pull_Up and Output initialized Values
		if (INPUT == Pin->Direction)
		{
			switch (Pin->Pull)
			{
				case PULL_DOWN :
					GPIOA->ODR &= ~(BIT_MASK << Pin->Pin ) ;
					break ;
				case PULL_UP:
					GPIOA->ODR |=(BIT_MASK << Pin->Pin ) ;
					break ;
				default :
					// Not Pull Pin
			}
		break ;
		case Port_B :
			vRCC_EnablePeripheralClock(RCC_APB2, IOB) ;
			if (Pin->Pin <= Pin_7)
			{
				GPIOB->CRL &=~(0b1111 << (Pin->Pin * 4) ) ;// Clear Bits
				GPIOB->CRL |=(Pin->Mode << (Pin->Pin * 4))   ;
			}
			else
			{
				GPIOB->CRH &= ~(0b1111 << ((Pin->Pin-8) * 4) ) ;// Clear Bits
				GPIOB->CRH |=   (Pin->Mode << ((Pin->Pin-8) * 4) )   ;
			}
			// Handle Pull_Down and Pull_Up and Output initialized Values
			switch (Pin->Pull)
			{
			case PULL_DOWN :
				GPIOB->ODR &= ~(BIT_MASK << Pin->Pin ) ;
				break ;
			case PULL_UP :
				GPIOB->ODR |=(BIT_MASK << Pin->Pin ) ;
				break ;
				default :
			}

			break ;
		case Port_C :
			vRCC_EnablePeripheralClock(RCC_APB2, IOC) ;
			if (Pin->Pin <= Pin_7)
			{
				GPIOC->CRL &=~(0b1111 << (Pin->Pin * 4) ) ;// Clear Bits
				GPIOC->CRL |=(Pin->Mode << (Pin->Pin * 4))   ;
			}
			else
			{
				GPIOC->CRH &= ~(0b1111 << ((Pin->Pin-8) * 4) ) ; // Clear Bits
				GPIOC->CRH |=   (Pin->Mode << ((Pin->Pin-8) * 4) )   ;
			}
			// Handle Pull_Down and Pull_Up and Output   initialized Values
			switch (Pin->Pull)
			{
			case PULL_DOWN :
				GPIOC->ODR &= ~(BIT_MASK << Pin->Pin ) ;
				break ;
			case PULL_UP :
				GPIOC->ODR |=(BIT_MASK << Pin->Pin ) ;
				break ;
				default :
			}

			break ;
		default :
			ret = R_NOK ;
	}
}
// Initialize Output Pins Values
if (Pin->Direction == OUTPUT)
{

	GPIO_SetPinValue(Pin,Pin->State) ;

}
return ret ;

}

state_type_t  GPIO_ReadPin(const PinConfig_t* Pin ,state_type_t*Ret_Val){
state_type_t ret = R_OK ;
switch (Pin->Direction)
{
	case INPUT :
		switch (Pin->Port)
		{
			case Port_A  :
				*Ret_Val = (GPIOA->IDR & (BIT_MASK<<Pin->Pin)) >> Pin->Pin ;
				break ;
			case Port_B :
				*Ret_Val = (GPIOB->IDR & (BIT_MASK<<Pin->Pin)) >> Pin->Pin ;
				break ;
			case Port_C :
				*Ret_Val = (GPIOC->IDR & (BIT_MASK<<Pin->Pin)) >> Pin->Pin ;
				break ;
			default :
				ret = R_NOK ;
		}
		break ;
	case OUTPUT :
		switch (Pin->Port)
		{
			case Port_A  :
				*Ret_Val = (GPIOA->ODR & (BIT_MASK<<Pin->Pin)) >> Pin->Pin ;
				break ;
			case Port_B :
				*Ret_Val = (GPIOB->ODR & (BIT_MASK<<Pin->Pin)) >> Pin->Pin ;
				break ;
			case Port_C :
				*Ret_Val = (GPIOC->ODR & (BIT_MASK<<Pin->Pin)) >> Pin->Pin ;
				break ;
			default :
				ret = R_NOK ;
		}
		break ;

}


return ret ;

}

state_type_t GPIO_SetPinValue(const PinConfig_t* Pin, State_t Value ){
state_type_t ret = R_OK ;

if (Pin->Direction == OUTPUT)
{
	if (SET == Value)
	{
		switch (Pin->Port)
		{
			case Port_A :
				GPIOA->ODR |= (BIT_MASK << Pin->Pin ) ;
				break ;
			case Port_B :
				GPIOB->ODR |= (BIT_MASK << Pin->Pin) ;
				break ;
			case Port_C :
				GPIOC->ODR |= (BIT_MASK << Pin->Pin) ;
				break ;
			default :
				ret = R_NOK ;
		}
	}
	else if (RESET == Value)
	{
		switch (Pin->Port)
		{
			case Port_A :
				GPIOA->ODR &= ~(BIT_MASK << Pin->Pin) ;
				break ;
			case Port_B :
				GPIOB->ODR &= ~(BIT_MASK << (Pin->Pin)) ;
				break ;
			case Port_C :
				GPIOC->ODR &= ~(BIT_MASK << Pin->Pin) ;
				break ;
			default :
				ret = R_NOK ;
		}

	}
	else
	{
		ret = R_NOK ;
	}
}

return ret ;
}
state_type_t GPIO_TogglePin(const PinConfig_t* Pin){
state_type_t ret = R_OK ;
	if (Pin->Direction == OUTPUT)
	{
			switch (Pin->Port)
			{
				case Port_A :
					GPIOA->ODR ^= (BIT_MASK << Pin->Pin ) ;
					break ;
				case Port_B :
					GPIOB->ODR ^= (BIT_MASK << Pin->Pin) ;
					break ;
				case Port_C :
					GPIOC->ODR ^= (BIT_MASK << Pin->Pin) ;
					break ;
				default :
					ret = R_NOK ;
			}
	}
	return ret ;
}
















