/**********************************************************************************************************************/
 /* INCLUDES*/
 /*********************************************************************************************************************/
#include "Port.h"
#include "Port_Cfg.h"
#include "Mcu_Hw.h"
#include "Bit_Math.h"
#include "STD_Types.h"

/**********************************************************************************************************************/
 /* LOCAL MACROS*/
 /*********************************************************************************************************************/
#define Max_Size_Reg		8

/**********************************************************************************************************************/
 /* CONST LOCAL MACROS for RCGCGPIO REGISTER*/
 /*********************************************************************************************************************/
#define R0			0
#define R1			1
#define R2			2
#define R3			3
#define R4			4
#define R5			5


/**********************************************************************************************************************/
 /* GLOBAL FUNCTIONS*/
 /*********************************************************************************************************************/
 
void Port_Init(Port_CfgType* strPtr)
{
	enu_Port_ChannelType chId 		= strPtr->Channel % Max_Size_Reg;
	enu_Port_PortType 	 portId 	= strPtr->Channel / Max_Size_Reg;
	volatile PORT_RegType* portAddr;
	
	/**************************************************************/
	/* SELECT PORT TYPE */
	/**************************************************************/
	switch (portId)
	{
		case (Port_A):
		{
			portAddr = &PORTA_REG;
			SetBit(RCGCGPIO, R0);  /*Enable clock to GPIOA */
			break;
		}
		case (Port_B):
		{
			portAddr = &PORTB_REG;
			SetBit(RCGCGPIO, R1);		/*Enable clock to GPIOB */
			break;
		}
		case (Port_C):
		{
			portAddr = &PORTC_REG;
			SetBit(RCGCGPIO, R2);		/*Enable clock to GPIOC */
			break;
		}
		case (Port_D):
		{
			portAddr = &PORTD_REG;
			SetBit(RCGCGPIO, R3);		/*Enable clock to GPIOD */
			break;
		}
		case (Port_E):
		{
			portAddr = &PORTE_REG;
			SetBit(RCGCGPIO, R4);		/*Enable clock to GPIOE */
			break;
		}
		case (Port_F):
		{
			portAddr = &PORTF_REG;
			SetBit(RCGCGPIO, R5);		/*Enable clock to GPIOF */
			break;
		}
	}
	
	/**************************************************************/
	/*  SET PIN DIRECTION  */
	/**************************************************************/
	if (strPtr->Dir == port_Dir_Output)
	{
		SetBit(portAddr->GPIODIR, chId);
	}
	else
	{
		ClrBit(portAddr->GPIODIR, chId);
	}
	
	/**************************************************************/
	/*  SET PIN MODE */
	/**************************************************************/	
	if(strPtr->Mode != Port_Mode_AIN )
    {
       /* enable digital */
       SetBit(portAddr->GPIODEN,chId);
        /*disable ADC */
        ClrBit(portAddr->GPIOADCCTL,chId);
    }
        
	 else
    {
        /* disable digital */
        ClrBit(portAddr->GPIODEN,chId);
        /* enable ADC */
        SetBit(portAddr->GPIOADCCTL,chId);
    }
		
	
	if (strPtr->Mode == Port_Mode_DIO)
	{
		ClrBit(portAddr->GPIOAFSEL, chId);
	}
	else
	{
		SetBit(portAddr->GPIOAFSEL, chId);
		/*then choose mode do you want to useon GPIOCTL register*/
		if (strPtr->Mode == Port_Mode_PWM)
		{
			if (portId == Port_A && chId == 6)
			{
				portAddr->GPIOPCTL.PMC6 = 0x5;
			}
			else if (portId == Port_A && chId == 7)
			{
				portAddr->GPIOPCTL.PMC7 = 0x5;
			}
			else if(portId == Port_B && chId == 4)
			{
				portAddr->GPIOPCTL.PMC4 = 0x4;
			}
			else if(portId == Port_B && chId == 5)
			{
				portAddr->GPIOPCTL.PMC5 = 0x4;
			}
			
			else if(portId == Port_B && chId == 6)
			{
				portAddr->GPIOPCTL.PMC6 = 0x4;
			}
			else if(portId == Port_B && chId == 7)
			{
				portAddr->GPIOPCTL.PMC6 = 0x4;
			}
			else if(portId == Port_C && chId == 4)
			{
				portAddr->GPIOPCTL.PMC4 = 0x4;
			}
			else if(portId == Port_C && chId == 5)
			{
				portAddr->GPIOPCTL.PMC5 = 0x4;
			}
			else if(portId == Port_D && chId == 0)
			{
				portAddr->GPIOPCTL.PMC0 = 0x4;
			}
			else if (portId == Port_D && chId == 1)
			{
				portAddr->GPIOPCTL.PMC1 = 0x4;
			}
			else{
				
			}
		}
	}
	
	/**************************************************************/
	/*  SET PIN INTERRUPT */
	/**************************************************************/
		if (strPtr->Interrupt == Port_IntDisable)
		{
			ClrBit(portAddr->GPIOIM, chId);
		}
		else
		{
			SetBit(portAddr->GPIOIM, chId);
			if(strPtr->Interrupt == Port_IntRisingEdge)
			{
				SetBit(portAddr->GPIOIEV, chId);
			}
			else if(strPtr->Interrupt == Port_IntFallingEdge)
			{
				ClrBit(portAddr->GPIOIEV, chId);
			}
			else if(strPtr->Interrupt == Port_IntBothEdges)
			{
				SetBit(portAddr->GPIOIBE, chId);
			}
		}
		
	/**************************************************************/	
	/*  SET PIN ATTACH RESISTANCE*/
	/*************************************************************/
		if (strPtr->AttachedRes == Port_InternalAttach_PullUpRes)
		{
			SetBit(portAddr->GPIOPUR, chId);
		}
		else if(strPtr->AttachedRes == Port_InternalAttach_PullDownRes)
		{
			SetBit(portAddr->GPIOPDR, chId);
		}
		else if(strPtr->AttachedRes == Port_InternalAttach_OpenDrain)
		{
			SetBit(portAddr->GPIOODR, chId);
		}
		
	/**************************************************************/	
	/*  SET PIN CURRENT  */
	/**************************************************************/
		if(strPtr->CurrentDrive == Port_CurrDrive_2mA)
		{
			SetBit(portAddr->GPIODR2R, chId);
		}
		else if(strPtr->CurrentDrive == Port_CurrDrive_4mA)
		{
			SetBit(portAddr->GPIODR4R, chId);
		}
		else if(strPtr->CurrentDrive == Port_CurrDrive_8mA)
		{
			SetBit(portAddr->GPIODR8R, chId);
		}
					
	
}
