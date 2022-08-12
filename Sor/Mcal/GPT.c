#include "GPT.h"
#include "Bit_Math.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************/
/*  Constant Macros for GPTMTAMR register*/
/*********************************************************************************************************************/
#define TAMR0		0
#define TAMR1		1
#define TACMR		2
#define TAAMS		3
#define TACDIR	4

/**********************************************************************************************************************/
/*  Constant Macros for GPTMCTL register*/
/*********************************************************************************************************************/
#define TAEN			0
#define TAPWML		6

/**********************************************************************************************************************/
/*  Constant Macros for GPTMIMR register*/
/*********************************************************************************************************************/
#define TATOIM		0

/**********************************************************************************************************************/
/*  Constant Macros for RCGCTIMER & RCGCWTIMER register*/
/*********************************************************************************************************************/
#define R0			0
#define R1			1
#define R2			2
#define R3			3
#define R4			4
#define R5			5

/**********************************************************************************************************************/
/*  Constant Macros for GPTMIMR register*/
/*********************************************************************************************************************/
#define TATOIM		0

/**********************************************************************************************************************/
/*  Constant Macros for GPTMICR register*/
/*********************************************************************************************************************/
#define TATOCINT		0




/**********************************************************************************************************************/
/*  LOCAL FUNCTION PROTOTYPES*/
/*********************************************************************************************************************/
static uint32 GPT_SetRegTimeValue(uint32 time_ms);

/**********************************************************************************************************************/
/*  LOCAL FUNCTIONS*/
/*********************************************************************************************************************/
 static uint32 GPT_SetRegTimeValue(uint32 time_ms)
 {
	 /*if frequency is F_CPU = 16MHZ*/
	 uint32 result;
	 result = (time_ms*1000000)/(uint32)62.5;
	 return result-1;
 }
/**********************************************************************************************************************/
/*  GLOBAL FUNCTIONS*/
/*********************************************************************************************************************/
 
void PWM_Init(str_Gpt_ConfigType* strPtr)
{
	volatile TIMER_RegType* regAddr;
	
/*Select timer type */
/************************/
	switch (strPtr->ChId)
	{
		case (TIMER0):
		{
			regAddr = &TIMER0_REG;
			SetBit(RCGCTIMER, R0);		/*Activate TIMER0*/
			
			break;
		}
		case (TIMER1):
		{
			regAddr = &TIMER1_REG;
			SetBit(RCGCTIMER, R1);		/*Activate TIMER1*/
			break;
		}
		case (TIMER2):
		{
			regAddr = &TIMER2_REG;
			SetBit(RCGCTIMER, R2);		/*Activate TIMER2*/
			break;
		}
		case (TIMER3):
		{
			regAddr = &TIMER3_REG;
			SetBit(RCGCTIMER, R3);		/*Activate TIMER3*/
			break;
		}
		case (TIMER4):
		{
			regAddr = &TIMER4_REG;
			SetBit(RCGCTIMER, R4);		/*Activate TIMER4*/
			break;
		}
		case (TIMER5):
		{
			regAddr = &TIMER5_REG;
			SetBit(RCGCTIMER, R5);		/*Activate TIMER5*/
			break;
		}
		
		case (WIDE_TIMER0):
		{
			regAddr = &WIDE_TIMER0_REG;
			SetBit(RCGCWTIMER, R0);		/*Activate WIDE TIMER0*/
			break;
		}
		case (WIDE_TIMER1):
		{
			regAddr = &WIDE_TIMER1_REG;
			SetBit(RCGCWTIMER, R1);		/*Activate WIDE TIMER1*/
			break;
		}
		case (WIDE_TIMER2):
		{
			regAddr = &WIDE_TIMER2_REG;
			SetBit(RCGCWTIMER, R2);		/*Activate WIDE TIMER2*/
			break;
		}
		case (WIDE_TIMER3):
		{
			regAddr = &WIDE_TIMER0_REG;
			SetBit(RCGCWTIMER, R3);		/*Activate WIDE TIMER3*/
			break;
		}
		case (WIDE_TIMER4):
		{
			regAddr = &WIDE_TIMER4_REG;
			SetBit(RCGCWTIMER, R4);		/*Activate WIDE TIMER4*/
			break;
		}
		case (WIDE_TIMER5):
		{
			regAddr = &WIDE_TIMER5_REG;
			SetBit(RCGCWTIMER, R5);		/*Activate WIDE TIMER5*/
			break;
		}
		
	}
	
/* Ensure the timer is disabled before making any changes*/
/********************************************************/
	ClrBit(regAddr ->GPTMCTL, TAEN); 
	
/*Select timer Mode */
/************************/
	if (strPtr ->HwMode == single_mode)
	{
		regAddr ->GPTMCFG = 0x00000004;
	}
	else if (strPtr ->HwMode == concatenate_mode_timer_rtc)
	{
		regAddr ->GPTMCFG = 0x00000001;
	}
	else  /* concatenate_mode_timer_cfg */
	{
		regAddr ->GPTMCFG = 0x00000000;
	}
	
	/*  some intialization    */
	SetBit(regAddr ->GPTMTAMR, TAAMS); /*enable PWM mode*/
	ClrBit(regAddr ->GPTMTAMR, TACMR); /*Edge Count*/
	/************************************/
	
/*Select timer generation type */
/*******************************/
	if (strPtr ->GPT_type == one_shot)
	{
		SetBit(regAddr ->GPTMTAMR, TAMR0);
		ClrBit(regAddr ->GPTMTAMR, TAMR1);
	}
	else /*Continouse Mode*/
	{
		ClrBit(regAddr ->GPTMTAMR, TAMR0);
		SetBit(regAddr ->GPTMTAMR, TAMR1);
	}
	
	
	/*Select timer direction mode */
/*******************************/
	if (strPtr->TimerDir == COUNT_DOWN)
	{
		ClrBit(regAddr->GPTMTAMR, TACDIR);
	}
	else
	{
		SetBit(regAddr->GPTMTAMR, TACDIR);
	}
	
	
	
/*Select timer level (Inverted or not) */
/***************************************/
	if (strPtr ->OutLevel == NON_INVERTED)
	{
		ClrBit(regAddr ->GPTMCTL, TAPWML);
	}
	else
	{
		SetBit(regAddr ->GPTMCTL, TAPWML);
	}
	
/*Load timer start value */
/************************/
	regAddr->GPTMTAILR = GPT_SetRegTimeValue(strPtr->time_ms); 
	
/* Enable timer*/
/**************/
	SetBit(regAddr->GPTMIMR, TATOIM);
	SetBit(regAddr ->GPTMCTL, TAEN); 
	
	
}
















void TIMER0A_Init(uint32 time_ms)
{
	volatile TIMER_RegType* regAddr;
	
/*Select timer type */
/************************/
	regAddr = &TIMER0_REG;
	SetBit(RCGCTIMER, R0);		/*Activate TIMER0*/
				
/* Ensure the timer is disabled before making any changes*/
/********************************************************/
	ClrBit(regAddr ->GPTMCTL, TAEN); 	

/*  Select timer Mode (Concatenate Mode ---> 32 bit )   */
/****************************************************************/
	regAddr ->GPTMCFG = 0x00000000;
	
/*Select timer generation type  as periodic mode*/
/***********************************************/
		ClrBit(regAddr ->GPTMTAMR, TAMR0);
		SetBit(regAddr ->GPTMTAMR, TAMR1);
		
/*Select timer direction mode as COUNT DOWN MODE */
/**********************************************/
	ClrBit(regAddr->GPTMTAMR, TACDIR);
		
/*Load timer start value */
/************************/
	regAddr->GPTMTAILR = GPT_SetRegTimeValue(time_ms); 		
	
/*Bus clock resolution (prescalar) */
/**********************************/		
	regAddr->GPTMTAPR = 0;
	
/*Clear Flag on TimerA */
/**********************************/
	SetBit(regAddr->GPTMICR, TATOCINT);
			
/*Enable TimerA0 Interrupt */
/***************************/	
	SetBit(regAddr->GPTMIMR, TATOIM);	
	
/*Set priority for Timer0A (0--->7) 
***********************************/	
	PRI4.StrPriReg.INTD = 5; /*As #IRQ of TIMER0A = 19,  so we select PRI4 due its range 16-->19, SET PRIORITY TO 5  */
				
/*Enable IRQ 19 on NVIC */
/***********************************/
	SetBit(EN0, 19);  /*		Enable Interrupt Of Timer0A on NVIC register		*/

/* Enable timer*/
/********************************************************/
	SetBit(regAddr ->GPTMCTL, TAEN); 
	
/* Enable Global Interrupt*/
/********************************************************/
	__enable_irq();
	
}
