/*
 * rcc_cnfig.h
 * 						""	 		TO a Way Full of Experiences & Successes		""
 *    						""	 	Author: Mohamed Ahmed "ABO KHALIL" 			""
 *    						 	"" 				Version 1.0				 	 ""
 *    						 	   ""            Layer: MCAL               ""
 *    								 ""	   Created on: Aug 10, 2023 	""
 */
// Include Guards to prevent multiple inclusion
#ifndef RCC_CNFIG_H_
#define RCC_CNFIG_H_

 // Includes
// ---------------------------

// Comments and Documentation
// --------------------------

// Preprocessor Directives

// -----------------------
//************************************************************************************
//#define CSS_MODE_ENABLED
//************************************************************************************
// HSI Configuration
#define HSI_CLK_ENABLED
#define TRIMMING_ENABLED
// Initial value is 0b10000 for each 1 increase  40 KHz increase in frequency
#define TRIMVAL    0b10000
//************************************************************************************
//#define HSE_CLK_ENABLED
#ifdef HSE_CLK_ENABLED
//HSE Configuration
// CRYSTAL or BYPASS
#define HSE_MODE   CRYSTAL
#endif
//************************************************************************************
//#define PLL_CLK_ENABLED
/*
 * Caution: The PLL output frequency must not exceed 72 MHz.
 * don't forget to write ob before the value
	0000: PLL input clock x 2
	0001: PLL input clock x 3
	0010: PLL input clock x 4
	0011: PLL input clock x 5
	0100: PLL input clock x 6
	0101: PLL input clock x 7
	0110: PLL input clock x 8
	0111: PLL input clock x 9
	1000: PLL input clock x 10
	1001: PLL input clock x 11
	1010: PLL input clock x 12
	1011: PLL input clock x 13
	1100: PLL input clock x 14
	1101: PLL input clock x 15
	1110: PLL input clock x 16
	1111: PLL input clock x 16
 */
//************************************
#define PLL_SRC_HSE 		0
#define PLL_SRC_HSI_DIV_2  	1
//************************************
#ifdef PLL_CLK_ENABLED
#define PLL_MUL  0b0000
#define PLL_SRC  PLL_SRC_HSE // Make Sure The SRC Clk is enabled
/*
Set and cleared by software to divide HSE before PLL entry. This bit can be written only
when PLL is disabled.
0: HSE clock not divided
1: HSE clock divided by 2
*/
#define PLL_XTPRE_VAL  0
#endif
//*******************ADJUST LATENCY**********************
#define LOW_CLK_LATENCY_24MHZ_ 0b000
#define MEDIUM_CLK_LATENCY_48MHZ_ 0b001
#define HIGH_CLK_LATENCY_72MHZ_  0b010
//*******************************************************
#define RCC_FLASH_LATENCY LOW_CLK_LATENCY_24MHZ_
//************************************************************************************



// #define HSE_CLK_ENABLED

// Macro Definitions
// ------------------
/*
 *  Set and cleared by software to select the frequency of the clock to the ADCs.
	00: PCLK2 divided by 2
	01: PCLK2 divided by 4
	10: PCLK2 divided by 6
	11: PCLK2 divided by 8
 *
 */
#define ADC_Prescalar  0b00
//********************************

#endif /* RCC_CNFIG_H_ */
// ---------------------------------
