/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  STD_Types.h
 *    Component:  -
 *       Module:  -
 *
 *  Description:  Provision of Standard Types
 *
 *********************************************************************************************************************/



#ifndef STD_TYPES_H
#define STD_TYPES_H





/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef unsigned char  		uint8;
typedef unsigned short  	uint16;
typedef unsigned int  	 	uint32;

typedef signed char  			sint8;
typedef signed short  		sint16;
typedef signed int  			sint32;

typedef float							float32;
typedef double						float64;




typedef enum 
{
	STD_low = 0,
	STD_high = 1,
	STD_error
}STD_LevelType;


typedef enum 
{
	STD_off = 0,
	STD_on = 1
}STD_BoolType;



typedef enum 
{
	STD_suspended = 0,
	STD_active = 1
}STD_StatusType;


typedef enum 
{
	False = 0,
	True = 1
}boolean;


typedef enum 
{
	STD_disable = 0,
	STD_enable= 1
}STD_EnType;


typedef enum 
{
	E_OK ,
	E_NOT_OK
}STD_ReturnType;


typedef void(*ptr2func)(void);








/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/


#endif /* STD_TYPES_H */
/**********************************************************************************************************************
 *  END OF FILE: STD_Types.h
 *********************************************************************************************************************/
