/*
 * rcc.c
 * 						""	 		T0 a way full of experiences & successes		""
 *    						""	 	Author: Mohamed Ahmed "ABO KHALIL" 			""
 *    						 	"" 				Version 1.0				 	 ""
 *    						 	   ""            Layer: MCAL               ""
 *    								 ""	   Created on: Aug 10, 2023 	""
 */



 // Includes
#include "../MCAL/RCC/rcc.h"
#include "../MCAL/GPIO/gpio.h"
// ---------------------------
//static functions declarations
static inline void vRCC_WaitForHSIStable(void);
static inline void vRCC_WaitForHSEStable(void);
static inline void vRCC_WaitForPLLStable(void);
//************************************************


const PinConfig_t MCO_Pin = {
	.Pin = Pin_8 ,
	.Port=Port_A ,
	.Mode =AFIO_OUT_PUSH_PULL_10MHZ,
	.Direction= OUTPUT
};
#ifdef HSI_CLK_ENABLED
static void vRCC_SetHSI(void) ;
static void vRCC_SetHSI(void)
{
	SET_BIT(RCC->RCC_CR,HSION) ; // Enable 8 MHZ Internal RC
	vRCC_WaitForHSIStable()    ; // wait for it to be Ready
	// Bits of HSICAL initialized automatically at startup

#ifdef TRIMMING_ENABLED // Trimming it
	RCC->RCC_CR |= (TRIMVAL << HSITRIM) ;
#endif
}
#endif
//************************************************
#ifdef HSE_CLK_ENABLED
static void vRCC_SetHSE(void) ;

static void vRCC_SetHSE(void)
{
#if HSE_MODE == BYPASS
SET_BIT(RCC->RCC_CR,HSEBYP) ;
#else

#endif
	SET_BIT(RCC->RCC_CR,HSEON) ; // enable HSE CLK
	vRCC_WaitForHSEStable() ;    // wait for it to be Ready
}
#endif
// **********************************************
#ifdef PLL_CLK_ENABLED
static void vRCC_SetPLL(void) ;

static void vRCC_SetPLL(){
#if (PLL_MUL > 0b1111)
   #error  "Invalid PLL_MUL value"
#else
	RCC->RCC_CFGR |= (PLL_MUL<<PLLMUL_OFFSET);
	RCC->RCC_CFGR  |= (PLL_SRC << PLLSRC ) ;
	RCC->RCC_CFGR |= (PLL_XTRPE <<PLLXTRPE) ;
	SET_BIT(RCC->RCC_CR,PLLON)  ;
	vRCC_WaitForPLLStable() ;
#endif
}
#endif
//***********************************************

// -----------------------------------------------

// Functions Implementation
void vRCC_Init(const RCCConfig_t* RCCconfig)
{
	GPIO_Init(&MCO_Pin) ;
	  // enable all clocks enabled from configurations File
vRCC_EnableMCO(RCCconfig->MCO_OutSrc) ;
FlASH_ACR |= (RCC_FLASH_LATENCY << LATENCY_OFFSET) ;
#ifdef HSE_CLK_ENABLED

	vRCC_SetHSE() ;
#endif

#ifdef HSI_CLK_ENABLED
	vRCC_SetHSI();
#endif

#ifdef CSS_MODE_ENABLED // Clock Security System
	SET_BIT(RCC->RCC_CR,CSS)  ;
#endif
#if PLL_CLK_ENABLED
	vRCC_SetPLL() ;
#endif
vRCC_SetSystemClock(
			RCCconfig->sysClkSource,
			RCCconfig->AHBPrescaler,
			RCCconfig->APB1Prescaler,
			RCCconfig->APB2Prescaler);
}


void vRCC_SetSystemClock(CLK_t sysClkSource, PRE_t AHBPrescaler, PRE_t APB1Prescaler, PRE_t APB2Prescaler)
{

switch (AHBPrescaler)
	 {
		case NO_DIV :
			(RCC->RCC_CFGR) |= (SYSCLK_NO_DIV << HPRE_OFFSET) ;
			break ;
		case DIV_2 :
			(RCC->RCC_CFGR) |= (SYSCLK_DIV2 << HPRE_OFFSET) ;
			break ;
		case DIV_4 :
			(RCC->RCC_CFGR) |= (SYSCLK_DIV4 << HPRE_OFFSET) ;
			break ;
		case DIV_8 :
			(RCC->RCC_CFGR) |= (SYSCLK_DIV8 << HPRE_OFFSET) ;
			break ;
		case DIV_16 :
			(RCC->RCC_CFGR) |= (SYSCLK_DIV16 << HPRE_OFFSET) ;
			break ;
	   	case DIV_64 :
			(RCC->RCC_CFGR) |= (SYSCLK_DIV64 << HPRE_OFFSET) ;
	   		break ;
	   	case DIV_128 :
			(RCC->RCC_CFGR) |= (SYSCLK_DIV128 << HPRE_OFFSET) ;
	   		break ;
	 	case DIV_256  :
			(RCC->RCC_CFGR) |= (SYSCLK_DIV256 << HPRE_OFFSET) ;
	 		break ;
		case DIV_512  :
			(RCC->RCC_CFGR) |= (SYSCLK_DIV512 << HPRE_OFFSET) ;
			break ;
		default :
			// error detection
	 }
switch (APB1Prescaler)
	 {
	    case NO_DIV :
	    	(RCC->RCC_CFGR) |= (HCLK_NO_DIV << PPRE1_OFFSET) ;
	    	break ;
	    case DIV_2 :
	    	(RCC->RCC_CFGR) |= (HCLK_DIV2 << PPRE1_OFFSET) ;
	    	break ;
	   	case DIV_4 :
	   		(RCC->RCC_CFGR) |= (HCLK_DIV4 << PPRE1_OFFSET) ;
	   		break ;
	   	case DIV_8 :
	   		(RCC->RCC_CFGR) |= (HCLK_DIV8 << PPRE1_OFFSET) ;
	   		break ;
	   	case DIV_16 :
	   		(RCC->RCC_CFGR) |= (HCLK_DIV16 << PPRE1_OFFSET) ;
	   		break ;
	   	default :
	   		// Error Detection

	 }
switch (APB2Prescaler)
	 {
	case NO_DIV :
		(RCC->RCC_CFGR) |= (HCLK_NO_DIV << PPRE2_OFFSET) ;
		break ;
	case DIV_2 :
		(RCC->RCC_CFGR) |= (HCLK_DIV2 << PPRE2_OFFSET) ;
		break ;
	case DIV_4 :
		(RCC->RCC_CFGR) |= (HCLK_DIV4 << PPRE2_OFFSET) ;
		break ;
	case DIV_8 :
		(RCC->RCC_CFGR) |= (HCLK_DIV8 << PPRE2_OFFSET) ;
		break ;
	case DIV_16 :
		(RCC->RCC_CFGR) |= (HCLK_DIV16 << PPRE2_OFFSET) ;
		break ;
	default :
		// error detection
	 }


 if (sysClkSource == HSE )
 {
	 RCC->RCC_CFGR |=(HSE_SYSCLK << SW_OFFSET ) ;

 }
 else if (sysClkSource == HSI)
 {
	 RCC->RCC_CFGR |=(HSI_SYSCLK << SW_OFFSET ) ;
 }
 else if (sysClkSource == PLL)
 {
	 RCC->RCC_CFGR |=(PLL_SYSCLK << SW_OFFSET );
 }
 else
 {
	 // Error Detection
 }
 RCC->RCC_CFGR |=(ADC_Prescalar << ADCPRE_OFFSET) ; // Set ADC Prescalar
}

void vRCC_EnablePeripheralClock(Bus_t BusName , Peripheral_t PeripheralName )
{
switch (BusName)
{
	case RCC_AHB :
		{
			SET_BIT(RCC->RCC_AHBENR,PeripheralName) ;
			break;
		}
	case RCC_APB1 :
		{
			SET_BIT(RCC->RCC_APB1ENR,PeripheralName) ;
			break;
		}
	case RCC_APB2  :
		{
			SET_BIT(RCC->RCC_APB2ENR,PeripheralName) ;
			break ;
		}
	default :
		{
			// To detect errors
		}
}
}
void vRCC_DisablePeripheralClock(Bus_t BusName , Peripheral_t PeripheralName){
	switch (BusName)
	{
		case RCC_AHB :
		{
			CLR_BIT(RCC->RCC_AHBENR,PeripheralName) ;
			break ;
		}
		case RCC_APB1 :
		{
			CLR_BIT(RCC->RCC_APB1ENR,PeripheralName) ;
			break;
		}
		case RCC_APB2  :
		{
			CLR_BIT(RCC->RCC_APB2ENR,PeripheralName) ;
			break ;
		}
		default :
		{
			// To detect errors
		}
	}
}

static inline void vRCC_WaitForHSIStable(void)
{
	while (RESET == RETURN_BIT(RCC->RCC_CR,HSIRDY)) ;

}
static inline void vRCC_WaitForHSEStable(void)
{
	while (RESET == RETURN_BIT(RCC->RCC_CR,HSERDY)) ;
}
static inline void vRCC_WaitForPLLStable(void)
{
	while (RESET == RETURN_BIT(RCC->RCC_CR,PLLRDY)) ;
}

void vRCC_EnableMCO(Out_MCO_t OutCLK)
{

if (OutCLK == Out_SYSCLK )
{
// Make Sure The Clock not exceed 50 MHZ
RCC->RCC_CFGR |= ((MCO_SYSCLK << MCO_OFFSET)) ;
}
else if (OutCLK == Out_HSE )
{
	RCC->RCC_CFGR |= ((MCO_HSE	<<	MCO_OFFSET)) ;

}
else if (OutCLK == Out_HSI)
{
	RCC->RCC_CFGR |= ((MCO_HSI << MCO_OFFSET)) ;

}
else if (OutCLK == Out_PLL_Div_2)
{

	RCC->RCC_CFGR |= ((MCO_PLL_DIV_2	<<	MCO_OFFSET)) ;

}
else
{
	RCC->RCC_CFGR |= ((MCO_NO_CLK	<<	MCO_OFFSET)) ;
}
}



void vRCC_ResetPeripheral(Bus_t BusName , Peripheral_t PeripheralName )
{
switch (BusName)
	{

	case RCC_APB1 :
		{
			SET_BIT(RCC->RCC_APB1RSTR,PeripheralName) ;
			break;
		}
	case RCC_APB2  :
		{
			SET_BIT(RCC->RCC_APB2RSTR,PeripheralName) ;
			break ;
		}
	default :
		{
			// To detect Input errors
		}
	}


}








//---------------------------------


