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
	enu_Port_ChannelType chId 		=  strPtr->Channel % Max_Size_Reg;
	enu_Port_PortType 	 portId 	=  strPtr->Channel / Max_Size_Reg;
	
	//volatile PORT_RegType* portAddr;
	
	/**************************************************************/
	/* SELECT PORT TYPE */
	/**************************************************************/
	switch (portId)
	{
		case (Port_A):
		{
			//portAddr = &PORTA_REG;
			SetBit(RCGCGPIO, R0);  /*Enable clock to GPIOA */
			break;
		}
		case (Port_B):
		{
			//portAddr = &PORTB_REG;
			SetBit(RCGCGPIO, R1);		/*Enable clock to GPIOB */
			break;
		}
		case (Port_C):
		{
			//portAddr = &PORTC_REG;
			SetBit(RCGCGPIO, R2);		/*Enable clock to GPIOC */
			break;
		}
		case (Port_D):
		{
			//portAddr = &PORTD_REG;
			SetBit(RCGCGPIO, R3);		/*Enable clock to GPIOD */
			break;
		}
		case (Port_E):
		{
			//portAddr = &PORTE_REG;
			SetBit(RCGCGPIO, R4);		/*Enable clock to GPIOE */
			break;
		}
		case (Port_F):
		{
			//portAddr = &PORTF_REG;
			SetBit(RCGCGPIO, R5);		/*Enable clock to GPIOF */
			break;
		}
	}
	
	/**************************************************************/
	/*  SET PIN DIRECTION  */
	/**************************************************************/
	if (strPtr->Dir == port_Dir_Output)
	{
	switch (portId)
	{
		case (Port_A):
		{
			SetBit(PORTA_GPIODIR_REG, chId);
			break;
		}
		case (Port_B):
		{
			SetBit(PORTB_GPIODIR_REG, chId);
			break;
		}
		case (Port_C):
		{
			SetBit(PORTC_GPIODIR_REG, chId);

			break;
		}
		case (Port_D):
		{
			SetBit(PORTD_GPIODIR_REG, chId);
		
			break;
		}
		case (Port_E):
		{
			SetBit(PORTE_GPIODIR_REG, chId);

			break;
		}
		case (Port_F):
		{
			SetBit(PORTF_GPIODIR_REG, chId);
			
			break;
		}
	}
		//SetBit(portAddr->GPIODIR, chId);
	}
	
	else
	{
	switch (portId)
	{
		case (Port_A):
		{
			ClrBit(PORTA_GPIODIR_REG, chId);
			break;
		}
		case (Port_B):
		{
			ClrBit(PORTB_GPIODIR_REG, chId);
			break;
		}
		case (Port_C):
		{
			ClrBit(PORTC_GPIODIR_REG, chId);
			break;
		}
		case (Port_D):
		{
			ClrBit(PORTD_GPIODIR_REG, chId);
			break;
		}
		case (Port_E):
		{
			ClrBit(PORTE_GPIODIR_REG, chId);
			break;
		}
		case (Port_F):
		{
			ClrBit(PORTF_GPIODIR_REG, chId);
			break;
		}
	}
		
		
		//ClrBit(portAddr->GPIODIR, chId);
	}
	
	/**************************************************************/
	/*  SET PIN MODE */
	/**************************************************************/	
	if(strPtr->Mode != Port_Mode_AIN )
    {
		switch (portId)
	{
		case (Port_A):
		{
			SetBit(PORTA_GPIODEN_REG, chId);
			break;
		}
		case (Port_B):
		{
			SetBit(PORTB_GPIODEN_REG, chId);
			break;
		}
		case (Port_C):
		{
			SetBit(PORTC_GPIODEN_REG, chId);

			break;
		}
		case (Port_D):
		{
			SetBit(PORTD_GPIODEN_REG, chId);
		
			break;
		}
		case (Port_E):
		{
			SetBit(PORTE_GPIODEN_REG, chId);

			break;
		}
		case (Port_F):
		{
			SetBit(PORTF_GPIODEN_REG, chId);
			
			break;
		}
	}
			
       /* enable digital */
      // SetBit(portAddr->GPIODEN,chId);
        /*disable ADC */
        //ClrBit(portAddr->GPIOADCCTL,chId);
    }
        
	 else
    {
	switch (portId)
	{
		case (Port_A):
		{
			ClrBit(PORTA_GPIODEN_REG, chId);
			break;
		}
		case (Port_B):
		{
			ClrBit(PORTB_GPIODEN_REG, chId);
			break;
		}
		case (Port_C):
		{
			ClrBit(PORTC_GPIODEN_REG, chId);
			break;
		}
		case (Port_D):
		{
			ClrBit(PORTD_GPIODEN_REG, chId);
			break;
		}
		case (Port_E):
		{
			ClrBit(PORTE_GPIODEN_REG, chId);
			break;
		}
		case (Port_F):
		{
			ClrBit(PORTF_GPIODEN_REG, chId);
			break;
		}
	}
			
        /* disable digital */
       // ClrBit(portAddr->GPIODEN,chId);
        /* enable ADC */
        //SetBit(portAddr->GPIOADCCTL,chId);
    }
		
	
	if (strPtr->Mode == Port_Mode_DIO)
	{
		switch (portId)
	{
		case (Port_A):
		{
			ClrBit(PORTA_GPIOAFSEL_REG, chId);
			break;
		}
		case (Port_B):
		{
			ClrBit(PORTB_GPIOAFSEL_REG, chId);
			break;
		}
		case (Port_C):
		{
			ClrBit(PORTC_GPIOAFSEL_REG, chId);
			break;
		}
		case (Port_D):
		{
			ClrBit(PORTD_GPIOAFSEL_REG, chId);
			break;
		}
		case (Port_E):
		{
			ClrBit(PORTE_GPIOAFSEL_REG, chId);
			break;
		}
		case (Port_F):
		{
			ClrBit(PORTF_GPIOAFSEL_REG, chId);
			break;
		}
	}
		
		
		//ClrBit(portAddr->GPIOAFSEL, chId);
	}
	else
	{
	//	SetBit(portAddr->GPIOAFSEL, chId);
	//	/*then choose mode do you want to useon GPIOCTL register*/
	//	if (strPtr->Mode == Port_Mode_PWM)
	//	{
	//		if (portId == Port_A && chId == 6)
	//		{
	//			portAddr->GPIOPCTL.PMC6 = 0x5;
	//		}
	//		else if (portId == Port_A && chId == 7)
	//		{
	//			portAddr->GPIOPCTL.PMC7 = 0x5;
	//		}
	//		else if(portId == Port_B && chId == 4)
	//		{
	//			portAddr->GPIOPCTL.PMC4 = 0x4;
	//		}
	//		else if(portId == Port_B && chId == 5)
	//		{
	//			portAddr->GPIOPCTL.PMC5 = 0x4;
	//		}
	//		
	//		else if(portId == Port_B && chId == 6)
	//		{
	//			portAddr->GPIOPCTL.PMC6 = 0x4;
	//		}
	//		else if(portId == Port_B && chId == 7)
	//		{
	//			portAddr->GPIOPCTL.PMC6 = 0x4;
	//		}
	//		else if(portId == Port_C && chId == 4)
	//		{
	//			portAddr->GPIOPCTL.PMC4 = 0x4;
	//		}
	//		else if(portId == Port_C && chId == 5)
	//		{
	//			portAddr->GPIOPCTL.PMC5 = 0x4;
	//		}
	//		else if(portId == Port_D && chId == 0)
	//		{
	//			portAddr->GPIOPCTL.PMC0 = 0x4;
	//		}
	//		else if (portId == Port_D && chId == 1)
	//		{
	//			portAddr->GPIOPCTL.PMC1 = 0x4;
	//		}
	//		else{
	//			
	//		}
	//}
	}
	
	/**************************************************************/
	/*  SET PIN INTERRUPT */
	/**************************************************************/
		if (strPtr->Interrupt == Port_IntDisable)
		{
	switch (portId)
	{
		case (Port_A):
		{
			ClrBit(PORTA_GPIOIM_REG , chId);
			break;
		}
		case (Port_B):
		{
			ClrBit(PORTB_GPIOIM_REG, chId);
			break;
		}
		case (Port_C):
		{
			ClrBit(PORTC_GPIOIM_REG, chId);
			break;
		}
		case (Port_D):
		{
			ClrBit(PORTD_GPIOIM_REG, chId);
			break;
		}
		case (Port_E):
		{
			ClrBit(PORTE_GPIOIM_REG, chId);
			break;
		}
		case (Port_F):
		{
			ClrBit(PORTF_GPIOIM_REG, chId);
			break;
		}
	}
			
			//ClrBit(portAddr->GPIOIM, chId);
		}
		else
		{
		//	SetBit(portAddr->GPIOIM, chId);
		//	if(strPtr->Interrupt == Port_IntRisingEdge)
		//	{
		//		SetBit(portAddr->GPIOIEV, chId);
		//	}
		//	else if(strPtr->Interrupt == Port_IntFallingEdge)
		//	{
		//		ClrBit(portAddr->GPIOIEV, chId);
		//	}
		//	else if(strPtr->Interrupt == Port_IntBothEdges)
		//	{
		//		SetBit(portAddr->GPIOIBE, chId);
		//	}
		}
		
	/**************************************************************/	
	/*  SET PIN ATTACH RESISTANCE*/
	/*************************************************************/
	//	if (strPtr->AttachedRes == Port_InternalAttach_PullUpRes)
	//	{
	//		SetBit(portAddr->GPIOPUR, chId);
	//	}
	//	else if(strPtr->AttachedRes == Port_InternalAttach_PullDownRes)
	//	{
	//		SetBit(portAddr->GPIOPDR, chId);
	//	}
	//	else if(strPtr->AttachedRes == Port_InternalAttach_OpenDrain)
	//	{
	//		SetBit(portAddr->GPIOODR, chId);
	//	}
		
	/**************************************************************/	
	/*  SET PIN CURRENT  */
	/**************************************************************/
	//	if(strPtr->CurrentDrive == Port_CurrDrive_2mA)
	//	{
	//		SetBit(portAddr->GPIODR2R, chId);
	//	}
	//	else if(strPtr->CurrentDrive == Port_CurrDrive_4mA)
	//	{
	//		SetBit(portAddr->GPIODR4R, chId);
	//	}
	//	else if(strPtr->CurrentDrive == Port_CurrDrive_8mA)
	//	{
	//		SetBit(portAddr->GPIODR8R, chId);
	//	}
					
	
}
