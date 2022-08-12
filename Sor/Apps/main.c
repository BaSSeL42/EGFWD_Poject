#include "Port.h"
#include "Mcu_Hw.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "GPT.h"
#include "SysTick.h"


#define TATOCINT		0

volatile uint8 flag = 1;

int main(void)
{
 Port_CfgType 				PortF_Pin1_CFG;

	
	PortF_Pin1_CFG.Channel 			= Port_Channel_F1;
	PortF_Pin1_CFG.Dir 					= port_Dir_Output;
	PortF_Pin1_CFG.Mode		 			= Port_Mode_DIO;
	PortF_Pin1_CFG.Interrupt 		= Port_IntDisable;
	PortF_Pin1_CFG.AttachedRes 	= Port_InternalAttach_NA;
	PortF_Pin1_CFG.CurrentDrive = Port_CurrDrive_2mA;
	
	
	/****** intialize port f ***************/
	
	//SetBit(RCGCGPIO, 5);
	//RCGCGPIO |= 0x20;

	/*
	PORTF_GPIODIR_REG = 0x0E;
	PORTF_GPIOAFSEL_REG &= ~0x0E;
	PORTF_GPIODEN_REG = 0x0E;*/
	
	
	//SetBit(PORTF_GPIODEN_REG ,1);
	//SetBit(PORTF_GPIODIR_REG, 1);
	//ClrBit(PORTF_GPIOAFSEL_REG, 1);
	
	
	Port_Init(&PortF_Pin1_CFG);
	
	
	
	//SysTick_Init(1000); /* 1000 ms  --> 1 sec */

	

	SysTick_Init(1000);
		
	
	
	while(1)
	{

		
	}
	
	
	return 0;
}





void SysTick_Handler(void)
{
	if (flag == 1)
	{
		Dio_WriteChannel(Dio_Channel_F1, STD_high);
		flag = 0;
		SysTick_Init(500);
	}
	else
	{
		Dio_WriteChannel(Dio_Channel_F1, STD_low);
		flag = 1;
		SysTick_Init(1000);
	}
	
}





//void TIMER0A_Handler(void)
//{
	//SetBit(TIMER0_REG.GPTMICR, TATOCINT);   //Clear Flag TIMER0A Interrupt
	//Dio_FlipChannel(Dio_Channel_F4);
//}