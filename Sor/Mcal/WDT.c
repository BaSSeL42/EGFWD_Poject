#include <Interrupt
#include "WDT.h"
#include "WDT_Cfg.h"
#include "Mcu_Hw.h"
#include "STD_Types.h"
#include "Bit_Math.h"

#define INTTYPE		2
#define RESEN			1	
#define INTEN			0

#define WRC				31

void WDG_Init(wdtCfg* strPtr)
{
	SetBit(WDTCTL_REG, INTEN);   // enable WDT Interrupt
	
	
	/******* Choose if u want Standered or non maskable interrupt  ***********/
	if (strPtr ->IntType == STD)
	{
		ClrBit(WDTCTL_REG, INTTYPE);
	}
	else
	{
		SetBit(WDTCTL_REG, INTTYPE);
	}
	
	
	
	/************* Configure reset enable or disable          ******************/
	
	if (strPtr ->rstEn == Reset_Enable)
	{
		SetBit(WDTCTL_REG, RESEN);
	}
	else
	{
		ClrBit(WDTCTL_REG, RESEN);
	}
	
	
	
	
}

void WDG_SetTrigger(uint16 timeOut)
{
	uint32 total_ticks;
	float32 tickEq;
	tickEq = (float32)(timeOut / 62.5)*1000000;  // if CPU frequency is 16MHZ with no prescalar
	total_ticks = (uint32) tickEq;
	
	WDTLOAD_REG = total_ticks;
	
	
	
}