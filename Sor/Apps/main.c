#include "Port.h"
#include "Mcu_Hw.h"
#include "Bit_Math.h"
#include "DIO.h"
#include "GPT.h"

#define TATOCINT		0

int main(void)
{
 Port_CfgType 				PortF_Pin4_CFG;

	
	PortF_Pin4_CFG.Channel 			= Port_Channel_F4;
	PortF_Pin4_CFG.Dir 					= port_Dir_Output;
	PortF_Pin4_CFG.Mode		 			= Port_Mode_DIO;
	PortF_Pin4_CFG.Interrupt 		= Port_IntDisable;
	PortF_Pin4_CFG.AttachedRes 	= Port_InternalAttach_NA;
	PortF_Pin4_CFG.CurrentDrive = Port_CurrDrive_2mA;
	
	Port_Init(&PortF_Pin4_CFG);
	TIMER0A_Init(1000); /* 1000 ms  --> 1 sec */
	
	
	
	
	while(1)
	{
		
	}
	
	
	return 0;
}



void TIMER0A_Handler(void)
{
	SetBit(TIMER0_REG.GPTMICR, TATOCINT); /*Clear Flag TIMER0A Interrupt*/
	Dio_FlipChannel(Dio_Channel_F4);
}