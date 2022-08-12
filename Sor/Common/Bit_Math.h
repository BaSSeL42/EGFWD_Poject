#ifndef BIT_MATH_H_
#define BIT_MATH_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_Types.h"



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

#define SetBit(Val, bit)						Val |= ((uint32) 1<< bit)
#define ClrBit(Val, bit)						Val &= ~((uint32) 1<< bit)
#define GetBit(Val, bit)					((Val >> bit)& (uint32)1)

#define ToggleBit(Val, bit)					Val ^= ((uint32) 1<< bit)

#define GET_REG(BASE_ADDR, REG_TYPE, REG_OFFSET)                (*((volatile REG_TYPE*)(BASE_ADDR+REG_OFFSET)))




#endif /*   BIT_MATH_H_   */
/**********************************************************************************************************************
 *  END OF FILE: Bit_Math.h
 *********************************************************************************************************************/
 