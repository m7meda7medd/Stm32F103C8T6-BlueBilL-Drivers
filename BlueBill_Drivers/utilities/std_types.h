/*
 * std_types.h
 * 						""	 		TO a Way Full of Experiences & Successes		""
 *    						""	 	Author: Mohamed Ahmed "ABO KHALIL" 			""
 *    						 	"" 				Version 1.0				 	 ""
 *    								 ""	   Created on: Aug 10, 2023 	""
 */


#ifndef STD_TYPES_H_
#define STD_TYPES_H_


typedef enum
{
RESET ,
SET
}State_t;
// Standard typedefs for fixed-width integer types
typedef unsigned char uint8_t;
typedef signed char sint8_t;
typedef unsigned short uint16_t;
typedef signed short sint16_t;
typedef unsigned long uint32_t;
typedef signed int sint32_t;
typedef unsigned long long uint64_t;
typedef signed long long sint64_t;

// Boolean typedef
typedef unsigned char bool;
#define false ((bool)0)
#define true  ((bool)1)
// Bit manipulation macros
// bit_MATH
#define BIT_MASK  (uint32_t)1
#define SET_BIT(REG,BIT)   		REG	|=	(	BIT_MASK	<<	 BIT	)
#define CLR_BIT(REG,BIT)  	 	REG	&=	~(	BIT_MASK	<<	 BIT	)
#define TOGGLE_BIT(REG,BIT) 	REG	^= 	(	BIT_MASK	<<	 BIT	)
#define RETURN_BIT(REG,BIT)     (REG &  (	BIT_MASK	<< 	 BIT ) >> BIT)
// Make Sure That the Register have zero bits .
#define SET_BITS(REG,START, ... )  			\
	REG|=(0b##__VA_ARGS__ << START) ;






#endif /* STD_TYPES_H_ */



