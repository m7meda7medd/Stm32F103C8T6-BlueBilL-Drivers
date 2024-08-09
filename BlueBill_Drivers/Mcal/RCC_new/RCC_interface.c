/*
 * RCC_interface.c
 *
 *  Created on: Jun 27, 2024
 *      Author: Mohamed Ahmed
 */

/* includes */
#include "RCC_interface.h"
/* =============================== */
#define RCC_CHECK_APB_PRESCALER(APB1, APB2)    	    \
 if ((APB1 > DIV_16) || (APB2 > DIV_16)){		\
	 /* invalid Prescalers Selection */   \
	 /* APB(1,2) Prescalers must not exceeded 16 */ \
	 while(1) ; \
   }

/* static u32* buses_enable_arr[3] = {&(RCC->AHBENR),&(RCC->APB1ENR),&(RCC->APB2ENR)} ; */
u32 SYSCLK_FREQUENCY  ;
u8 SYSCLK_SRC ;
/* Static interfaces */

static u8 RCC_HSE_WaitReady(u32 timeoutcycles) ;
static u8 RCC_HSI_WaitReady(u32 timeoutcycles) ;
static u8 RCC_PLL_WaitReady(u32 timeoutcycles) ;
static SystemClock_SRC_t RCC_Check_SystemClock(u32 timeoutcycles ) ;
/* =============================== */






/* interfaces */
void RCC_SystemClockConfig(const SystemClockConfig_t* systemclockconfig){
	/* check on APB1 and APB2 Prescalers */
	RCC_CHECK_APB_PRESCALER(systemclockconfig->APB1Prescaler,systemclockconfig->APB2Prescaler) ;
	/* Clear Prescaler Values */
	RCC->CFGR &= ~(RCC_CFGR_HPRE_MASK << HPRE_OFFSET)  ;
	RCC->CFGR &= ~((RCC_CFGR_PPRE_MASK) << PPRE1_OFFSET) ;
	/* set system prescalers  (AHB, APB1, APB2 ) */
	RCC->CFGR |= ((systemclockconfig->AHB_Prescaler) << HPRE_OFFSET) ;
	RCC->CFGR |= ((systemclockconfig->APB1Prescaler - APB_PRESCALER_OFFSET) << PPRE1_OFFSET) ;
	RCC->CFGR |= ((systemclockconfig->APB2Prescaler - APB_PRESCALER_OFFSET) << PPRE2_OFFSET) ;
	/* configure system clock */
	switch (systemclockconfig->sysClkSource) {
		case HSI :
			/* Configure HSI Clock */
			RCC_HSIConfig(ON) ;
			SYSCLK_SRC = HSI ;
			break;
		case HSE :
			/* Configure HSE Clock */

			 RCC_HSEConfig(systemclockconfig->HSE_Type, ON) ;
			 SYSCLK_SRC = HSE ;
			 break;
		case PLL :
			/* Configure PLL  */
			 RCC_PLLConfig(&(systemclockconfig->PLL_Info), ON) ;

			 PLL_SRC_t pll_source = systemclockconfig->PLL_Info.PLL_Source ;
			 if (pll_source == HSI_DIV_2){
				 RCC_HSIConfig(ON) ;
			 }else if (pll_source == HSE_NO_DIV) {
				 RCC_HSEConfig(systemclockconfig->HSE_Type, ON) ;
			 }else if (pll_source == HSE_DIV_2){
				 RCC_HSEConfig(systemclockconfig->HSE_Type, ON) ;
			 }
			 SYSCLK_SRC = PLL ;
			 break;
		default:
			/* invalid System Clock Selection */
			/* System Clock must be (HSI or HSE or PLL ) */
			while (1) ;
			break;
	}
	/* Select the Output of MCO Pin */
	if (systemclockconfig->MCO_OutSrc != MCO_NOCLK) {
		/* enable MCO Pin */
		RCC_EnableMCO(systemclockconfig->MCO_OutSrc) ;
	}
	/* select system clock source  */
	RCC_SelectSysClockSource(systemclockconfig->sysClkSource) ;

}
/* Peripherals Clock Enablers and Disablers */
/* Clocks Config Functions */
void RCC_HSEConfig(HSE_Clock_t HSE_clock ,ClockState_t state){
	if ( ON == state){
		/* Configure the Type of HSE */
		 if (HSE_clock == HSE_RC) {
			 /* Enable Bypassing of external crystal */
			 SET_BIT(RCC->CR,HSEBYP) ;
		 }else {
			 /* External 4- 16 MHz Crystal Not Bypassed */
			 CLR_BIT(RCC->CR,HSEBYP) ;
		 }
		/* Enable HSE Clock */
		SET_BIT(RCC->CR,HSEON) ;
		if (RCC_HSE_WaitReady(READY_TIMEOUT_CYCLES)){
			/* Can't Start HSE */
			while(1) ;
		}
	}else {
	  CLR_BIT(RCC->CR, HSEON) ;
	}
}
void RCC_HSIConfig(ClockState_t state){
	if ( ON == state){

		/* Enable HSI Clock */
		SET_BIT(RCC->CR,HSION) ;
		if (RCC_HSI_WaitReady(READY_TIMEOUT_CYCLES)){
			/* Can't Start HSE */
			while(1) ;
		}
	}else {
	  CLR_BIT(RCC->CR,HSION) ;
	}
}
void RCC_PLLConfig(const PLL_Info_t* pll_info, ClockState_t state){
	/* Configure Pll Multiplication Factor */

	PLL_SRC_t source = pll_info->PLL_Source ;
	PLL_MUL_t multipier = pll_info->PLL_Mul ;

	if ((multipier<= PLL_MUL_16) && (multipier >= 0))
	{
		/*Clear The Previous PLL MUL Bits */
		RCC->CFGR &= ~(MASK_4BITS << PLLMUL_OFFSET) ;
		/* Set the new value of the PLL MUL */
		RCC->CFGR |= (multipier << PLLMUL_OFFSET) ;
		/* Configure The Source of the PLL */
		switch (source) {
			case HSI_DIV_2:
				CLR_BIT(RCC->CFGR,PLLSRC) ;
				break;
			default:
				/* in case HSE( NO_DIV- DIV/2 ) */
				if (source == HSE_DIV_2) {
					SET_BIT(RCC->CFGR,PLLXTRPE) ;
				}else {
					CLR_BIT(RCC->CFGR,PLLXTRPE) ;
				}
				SET_BIT(RCC->CFGR,PLLSRC) ;
				break;
		}
		RCC_PLL_WaitReady(READY_TIMEOUT_CYCLES) ;
	}
	// check on the ouput frequency of pll
}
void RCC_SelectSysClockSource(SystemClock_SRC_t source){
	if (source <=  PLL ){
	/* Clear The Previous SW bits */
		RCC->CFGR &= ~(MASK_2BITS << SW_OFFSET) ;
		RCC->CFGR |= (source << SW_OFFSET) ;
		u8 source ;
		source = RCC_Check_SystemClock(TIMEOUT_CYCLES) ;
		if (source == /* not applicable */ 3) {
			/* can't set source for system clock */
			while (1) ;
		}
	}else {
		/* invalid source */
		while (1) ;
	}
}

void RCC_EnablePeripheralClock(Bus_t bus ,u32 peripheral){
	/* Enable Peripheral  at bus */
	/* 	AHB =  0
	 * 	APB2 = 1
	 *  APB1 = 2
	 */
	if (bus > APB1) {
		/* invalid bus */
		while (1) ;
	}
	*(((u32*)&(RCC->AHBENR))+bus) |= peripheral;
}
void RCC_DisablePeripheralClock(Bus_t bus ,u32 peripheral){
	/* Disable Peripheral  at bus */
	*(((u32*) &(RCC->AHBENR)) + bus) &= ~peripheral;
}
/* Select System Clock Function */

/* prescalers Setters */
void RCC_SetUSBPrescaler(USB_Prescaler_t usbprescaler) {
	(usbprescaler == PLL_DIV_3D2) ? CLR_BIT(RCC->CFGR,USBPRE) : SET_BIT(RCC->CFGR,USBPRE) ;
}

void RCC_SetADCPrescaler(ADC_Prescaler_t adcprescaler) {
	/* Delete the previous Prescaler */
	RCC->CFGR &= ~(MASK_2BITS << ADCPRE_OFFSET) ;
	/* Set the New ADC Prescaler value */
	RCC->CFGR |= (adcprescaler << ADCPRE_OFFSET) ;
}
/* Interrupts Enablers and Disablers */
inline void RCC_EnableClockSecuritySystem(void) {
	/* Enable CSS */
	SET_BIT(RCC->CR,CSS) ;
}
/*
void RCC_EnableInterrupt(RCC_Interrupt_t interrupt)  ;
void RCC_DisableInterrupt(RCC_Interrupt_t interrupt) ;
*/
void RCC_SetTrimval(u32 trimval){
	if (trimval > MAXTRIMVAL) {
		/* Do nothing  */

	}else {
		/* Clear HSITRIM bits */
		RCC->CR &= ~(TRIMVAL_MASK << HSITRIM) ;
		/* set new Trimval */
		RCC->CR |= (trimval << HSITRIM) ;
	}
}
void RCC_EnableMCO(MCO_Output_t MCO_OutSrc) {
	if (((MCO_OutSrc - MCO_SYSCLK) < MCO_NOCLK ) && (MCO_OutSrc != MCO_NOCLK)){
		/* Invalid MCO Source */
		while (1) ;
	}else {
		/* Clear Previous MCO Source Bits */
		RCC->CFGR &= ~ (MASK_3BITS << MCO_OFFSET) ;
		/* Choose MCO Source */
		RCC->CFGR |= (MCO_OutSrc << MCO_OFFSET) ;
	}
}
static u8 RCC_HSE_WaitReady(u32 timeoutcycles){
	/* wait for the HSE Clock to be Ready */
	while ((!RETURN_BIT(RCC->CR,HSERDY)) && (timeoutcycles > 0)) {
		__asm volatile ("NOP") ;
		timeoutcycles-- ;
	}
	if (timeoutcycles == 0) {
		/* in case of ready the expression = 0 else = 1  */
		return !(RETURN_BIT(RCC->CR,HSERDY)) ;
	}else {
		return 0 ;
	}
}
static u8 RCC_PLL_WaitReady(u32 timeoutcycles){
	/* wait for the HSE Clock to be Ready */
	while ((!RETURN_BIT(RCC->CR,PLLRDY)) && (timeoutcycles > 0)) {
		__asm volatile ("NOP") ;
		timeoutcycles-- ;
	}
	if (timeoutcycles == 0) {
		/* in case of ready the expression = 0 else = 1  */
		return !(RETURN_BIT(RCC->CR,PLLRDY)) ;
	}else {
		return 0 ;
	}
}
static u8 RCC_HSI_WaitReady(u32 timeoutcycles){
	/* wait for the HSE Clock to be Ready */
	while ((!RETURN_BIT(RCC->CR,HSIRDY)) && (timeoutcycles > 0)) {
		/* No operation Instruction */
		__asm volatile ("NOP") ;
		timeoutcycles-- ;
	}
	if (timeoutcycles == 0) {
		/* in case of ready the expression = 0 else = 1  */
		return !(RETURN_BIT(RCC->CR,HSIRDY)) ;
	}else {
		return 0 ;
	}
}
static SystemClock_SRC_t RCC_Check_SystemClock(u32 timeoutcycles ){
	u8 sws  = 0 ;
	u8 sw = 0 ;
	/* read the two bits */
	sw = (u8) (RCC->CFGR & (0x3)) ;
	sws = (u8) ((RCC->CFGR & (0xC)) >> SWS_OFFSET) ;
	while ((sw != sws) && (timeoutcycles != 0)){
		/* No operation Instruction */
		__asm volatile ("NOP") ;
		timeoutcycles-- ;
	}
	if (timeoutcycles == 0) {
		if (sw != sws ){
			return 3 /* Not Applicable */ ;
		}
	}
	return sws ;
}
/* ==================================== */
