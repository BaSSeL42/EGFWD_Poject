#ifndef PORT_CFG_H_
#define PORT_CFG_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_Types.h"


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
	Port_Channel_A0,
	Port_Channel_A1,
	Port_Channel_A2,
	Port_Channel_A3,
	Port_Channel_A4,
	Port_Channel_A5,
	Port_Channel_A6,
	Port_Channel_A7,
	
	
	Port_Channel_B0,
	Port_Channel_B1,
	Port_Channel_B2,
	Port_Channel_B3,
	Port_Channel_B4,
	Port_Channel_B5,
	Port_Channel_B6,
	Port_Channel_B7,
	
	Port_Channel_C0,
	Port_Channel_C1,
	Port_Channel_C2,
	Port_Channel_C3,
	Port_Channel_C4,
	Port_Channel_C5,
	Port_Channel_C6,
	Port_Channel_C7,
	
	
	Port_Channel_D0,
	Port_Channel_D1,
	Port_Channel_D2,
	Port_Channel_D3,
	Port_Channel_D4,
	Port_Channel_D5,
	Port_Channel_D6,
	Port_Channel_D7,
	
	
	Port_Channel_E0,
	Port_Channel_E1,
	Port_Channel_E2,
	Port_Channel_E3,
	Port_Channel_E4,
	Port_Channel_E5,
	Port_Channel_E6_NA,
	Port_Channel_E7_NA,
	
	
	Port_Channel_F0,
	Port_Channel_F1,
	Port_Channel_F2,
	Port_Channel_F3,
	Port_Channel_F4
	
	
}enu_Port_ChannelType;


typedef enum
{
	Port_A,
	Port_B,
	Port_C,
	Port_D,
	Port_E,
	Port_F
	
}enu_Port_PortType;


typedef enum
{
    port_Dir_Input,
    port_Dir_Output
}enu_Port_PinDirectionType;

typedef enum
{
    Port_IntDisable,
    Port_IntFallingEdge,
    Port_IntRisingEdge,
    Port_IntBothEdges
	
}enu_Port_IntCtrType;

typedef enum
{
    Port_Mode_DIO,
    Port_Mode_UART_Tx,
    Port_Mode_UART_Rx,
    Port_Mode_SSI_Clk,
    Port_Mode_SSI_Fss,
    Port_Mode_SSI_Rx,
    Port_Mode_SSI_Tx,
    Port_Mode_I2C_Scl,
    Port_Mode_I2C_Sda,
    Port_Mode_PWM,
    Port_Mode_CCP,
    Port_Mode_AIN,
    Port_Mode_CAN_Rx,
    Port_Mode_CAN_Tx
	
}enu_Port_pinModeType;

typedef enum
{
    Port_Unlocked,
    Port_locked
}enu_Port_PinLockStatusType;


typedef enum
{
    Port_InternalAttach_NA,
    Port_InternalAttach_PullUpRes,
    Port_InternalAttach_PullDownRes,
    Port_InternalAttach_OpenDrain

}enu_Port_PinInternalAttachType;

typedef enum
{
    Port_CurrDrive_2mA,
    Port_CurrDrive_4mA,
    Port_CurrDrive_8mA
}enu_Port_pinOutputCurrentType;


typedef struct
{
    enu_Port_ChannelType    				Channel;
    enu_Port_PinDirectionType       Dir;
    enu_Port_pinModeType           	Mode;
    enu_Port_IntCtrType         		Interrupt;
    enu_Port_PinInternalAttachType 	AttachedRes;
    enu_Port_pinOutputCurrentType   CurrentDrive;
    /*enu_Port_PinLockStatusType     	LockStatus;*/
	
}Port_CfgType;


#endif /*   PORT_CFG_H_   */
/**********************************************************************************************************************
 *  END OF FILE: PORT_Cfg.h
 *********************************************************************************************************************/