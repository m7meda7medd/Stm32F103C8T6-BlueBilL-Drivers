/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  <Std_types.h>
 *       Module:  -
 *
 *  Description:  Header file for standard typedefs and macros.
 *
 *********************************************************************************************************************/
#ifndef STD_TYPES_H
#define STD_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// Standard typedefs for fixed-width Decimal types
typedef unsigned char 		u8;			/* 0 ---> 255 */
typedef signed char 		s8;			/* -128 ---> 127 */
typedef unsigned short 		u16;		/* 0 ---> 65535 */
typedef signed short 		s16;		/*  -32768 ---> 32767 */
typedef unsigned long 		u32;		/* 0 ---> 4294967295 */
typedef signed long 		s32;		/* -2147483648 ---> 2147483647 */
typedef unsigned long long 	u64;		/* 0 ---> 1.8e19 */
typedef signed long long 	s64;		/* -9.2e18 ---> 9.2e18-1 */
// Boolean typedef
typedef unsigned char bool;
/*******************************************************************************************/
#define false ((bool)0)
#define true  ((bool)1)
/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
// Bit manipulation macros
#define BIT_MASK  (u32)1
#define SET_BIT( REG , BIT )   		(REG	|= (	BIT_MASK	<<	 BIT	))
#define CLR_BIT( REG , BIT )  	 	(REG	&= ~(	BIT_MASK	<<	 BIT	))
#define TOGGLE_BIT( REG , BIT ) 	(REG	^= 	(	BIT_MASK	<<	 BIT	))
#define RETURN_BIT( REG , BIT )     (REG &  (	BIT_MASK	<< 	 BIT ) >> BIT)
/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

/********************************/
typedef enum /* standard return type ( E_OK, E_NOT_OK ) */{
E_OK ,
E_NOT_OK
}Std_ReturnType;

typedef enum /* basic State enum */ {
OFF,
ON
}State_t;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

#endif  /* Std_Types.h */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/


