#ifndef MCU_HW_H_
#define MCU_HW_H_


/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include"STD_Types.h"



/**********************************************************************************************************************
 * GPIO REGISTER
 *********************************************************************************************************************/
typedef struct
{
	uint32 PMC0:4;
	uint32 PMC1:4;
	uint32 PMC2:4;
	uint32 PMC3:4;
	uint32 PMC4:4;
	uint32 PMC5:4;
	uint32 PMC6:4;
	uint32 PMC7:4;
	
}str_GPIOPCTL_REG;


typedef struct	
{
	  uint32 GPIODATA    ;
    uint32 GPIODIR     ;
    uint32 GPIOIS      ;
    uint32 GPIOIBE     ;
    uint32 GPIOIEV     ;
    uint32 GPIOIM      ;
    uint32 GPIORIS     ;
    uint32 GPIOMIS     ;
    uint32 GPIOICR     ;
    uint32 GPIOAFSEL   ; /*offset : 0x420 -> 424 */

    uint8 Reserved_2[0xDC];
    uint32 GPIODR2R    ; /*offset : 0x500 */
    uint32 GPIODR4R    ;
    uint32 GPIODR8R    ;
    uint32 GPIOODR     ;
    uint32 GPIOPUR     ;
    uint32 GPIOPDR     ;
    uint32 GPIOSLR     ;
    uint32 GPIODEN     ;
    uint32 GPIOLOCK    ;
    uint32 GPIOCR      ;
    uint32 GPIOAMSEL   ;
    str_GPIOPCTL_REG GPIOPCTL    ;
    uint32 GPIOADCCTL  ;
    uint32 GPIODMACTL  ;
	
}PORT_RegType ;
	

#define PORTA_REG     (*((volatile PORT_RegType*)0x40004000))
#define PORTB_REG     (*((volatile PORT_RegType*)0x40005000))
#define PORTC_REG     (*((volatile PORT_RegType*)0x40006000))
#define PORTD_REG     (*((volatile PORT_RegType*)0x40007000))
#define PORTE_REG     (*((volatile PORT_RegType*)0x40024000))
#define PORTF_REG     (*((volatile PORT_RegType*)0x40025000))


/**********************************************************************************************************************
 * WatchDog REGISTER
 *********************************************************************************************************************/

#define WDT_BASE_ADDRESS		0x40001000

#define WDTLOAD_REG					(*((volatile uint32*)(WDT_BASE_ADDRESS + 0x000)))
#define WDTCTL_REG					(*((volatile uint32*)(WDT_BASE_ADDRESS + 0x008)))
#define WDTICR_REG					(*((volatile uint32*)(WDT_BASE_ADDRESS + 0x00C)))



/**********************************************************************************************************************
 * Timer REGISTER
 *********************************************************************************************************************/

typedef struct
{
	uint32 GPTMCFG;
	uint32 GPTMTAMR;
	uint32 GPTMTBMR;
	uint32 GPTMCTL;
	uint32 GPTMSYNC;
	uint32 GPTMIMR;
	uint32 GPTMRIS;
	uint32 GPTMMIS;
	uint32 GPTMICR;
	uint32 GPTMTAILR;
	uint32 GPTMTBILR;
	uint32 GPTMTAMATCHR;
	uint32 GPTMTBMATCHR;
	uint32 GPTMTAPR;
	uint32 GPTMTBPR;
	uint32 GPTMTAPMR;
	uint32 GPTMTBPMR;
	uint32 GPTMTAR;
	uint32 GPTMTBR;
	uint32 GPTMTAV;
	uint32 GPTMTBV;
	uint32 GPTMRTCPD;
	uint32 GPTMTAPS;
	uint32 GPTMTBPS;
	uint32 GPTMTAPV;
	uint32 GPTMTBPV;
	uint32 GPTMPP;
	
}TIMER_RegType;


#define TIMER0_REG 				(*((volatile TIMER_RegType*)0x40030000))
#define TIMER1_REG				(*((volatile TIMER_RegType*)0x40031000))
#define TIMER2_REG				(*((volatile TIMER_RegType*)0x40032000))
#define TIMER3_REG				(*((volatile TIMER_RegType*)0x40033000))
#define TIMER4_REG				(*((volatile TIMER_RegType*)0x40034000))
#define TIMER5_REG				(*((volatile TIMER_RegType*)0x40035000))
	
#define WIDE_TIMER0_REG		(*((volatile TIMER_RegType*)0x40036000))
#define WIDE_TIMER1_REG		(*((volatile TIMER_RegType*)0x40037000))
#define WIDE_TIMER2_REG		(*((volatile TIMER_RegType*)0x4003C000))
#define WIDE_TIMER3_REG		(*((volatile TIMER_RegType*)0x4003D000))
#define WIDE_TIMER4_REG		(*((volatile TIMER_RegType*)0x4003E000))
#define WIDE_TIMER5_REG		(*((volatile TIMER_RegType*)0x4003F000))


/**********************************************************************************************************************
 * SYSTEM CONTROL REGISTER
 *********************************************************************************************************************/

#define SYS_CTRL_BASE_ADDR		 0x400FE000		

#define RCGCTIMER				(*((volatile uint32*)(SYS_CTRL_BASE_ADDR + 0x604)))
#define RCGCGPIO				(*((volatile uint32*)(SYS_CTRL_BASE_ADDR + 0x608)))
#define RCGCWTIMER			(*((volatile uint32*)(SYS_CTRL_BASE_ADDR + 0x65C)))

	

/**********************************************************************************************************************
 * IntCtrl REGISTER
 *********************************************************************************************************************/
#define EXCEP_BASE_ADD		0xE000E000

/*********************/
/* FOR NVIC REGISTER  */
/*********************/
typedef struct
{
	uint32 				:5;
	uint32 INTA		:3; /*4n*/
	uint32 				:5;
	uint32 INTB		:3; /*4n+1*/
	uint32 				:5;
	uint32 INTc		:3; /*4n+2*/
	uint32 				:5;
	uint32 INTD		:3; /*4n+3*/
}str_PRI_REG;

typedef union
{
	str_PRI_REG		StrPriReg;
	uint32				AllReg;
	
}un_PRI_TAG;


/*				Interrupt 0-31 Set Enable							*/
#define EN0			(*(volatile uint32*)(EXCEP_BASE_ADD + 0x0100))
	/*				Interrupt 32-63 Set Enable							*/
#define EN1			(*(volatile uint32*)(EXCEP_BASE_ADD + 0x0104))
	/*				Interrupt 64-95 Set Enable							*/
#define EN2			(*(volatile uint32*)(EXCEP_BASE_ADD + 0x0108))
	/*				Interrupt 96-127 Set Enable							*/
#define EN3			(*(volatile uint32*)(EXCEP_BASE_ADD + 0x010C))
		/*				Interrupt 128-138 Set Enable							*/
#define EN4			(*(volatile uint32*)(EXCEP_BASE_ADD + 0x0110))


/*Interrupt Priority 0-3 */
#define PRI0  (*((volatile un_PRI_TAG*)(EXCEP_BASE_ADD+0x0400)))
/*Interrupt Priority 4-7 */
#define PRI1  (*((volatile un_PRI_TAG*)(EXCEP_BASE_ADD+0x0404)))
/*Interrupt Priority 8-11 */
#define PRI2  (*((volatile un_PRI_TAG*)(EXCEP_BASE_ADD+0x0408)))
/*Interrupt Priority 12-15 */
#define PRI3  (*((volatile un_PRI_TAG*)(EXCEP_BASE_ADD+0x040C)))
/*Interrupt Priority 16-19 */
#define PRI4  (*((volatile un_PRI_TAG*)(EXCEP_BASE_ADD+0x0410)))
/*Interrupt Priority 20-23 */
#define PRI5  (*((volatile un_PRI_TAG*)(EXCEP_BASE_ADD+0x0414)))
/*Interrupt Priority 24-27 */
#define PRI6  (*((volatile un_PRI_TAG*)(EXCEP_BASE_ADD+0x0418)))
/*Interrupt Priority 28-31 */
#define PRI7  (*((volatile un_PRI_TAG*)(EXCEP_BASE_ADD+0x041C)))
/*Interrupt Priority 32-35 */
#define PRI8  (*((volatile un_PRI_TAG*)(EXCEP_BASE_ADD+0x0420)))
/*Interrupt Priority 36-39 */
#define PRI9  (*((volatile un_PRI_TAG*)(EXCEP_BASE_ADD+0x0424)))
/*Interrupt Priority 40-43 */
#define PRI10 (*((volatile un_PRI_TAG*)(EXCEP_BASE_ADD+0x0428)))



/* Trigger any INT by SW */
#define SWTRIG *((volatile uint32*)(EXCEP_BASE_ADD+0x0F00))

/*********************/
/* FOR SCB REGISTER  */
/*********************/

/* INTCTRL Implementation */
/**********************************/
typedef struct 
{
	uint32 VECACT  		:8;
	uint32				 		:3;
	uint32 RETBASE 		:1;
	uint32 VECPEND 		:8;
	uint32				 		:2;
	uint32 ISRPEND 		:1;
	uint32 ISRPRE  		:1;
	uint32				 		:1;
	uint32 PENDSTCLR  :1;
	uint32 PENDSTSET  :1;
	uint32 UNPENDSV  	:1;
	uint32 PENDSV  		:1;
	uint32				 		:2;
	uint32 NMISET  		:1;
	
}str_INTCTRL_REG;
typedef union
{
	str_INTCTRL_REG		StrReg_INTCTRL;
	uint32 						UseAllReg_INTCTRL;
}un_INTCTRL_TAG;



/* VTABL Implementation */
/**********************************/
typedef struct 
{
	uint32  		   :10;
	uint32 OFFSET	 :22;
	
}str_VTABLE_REG;



/* APINT Implementation */
/**********************************/
typedef struct 
{
	uint32 VECTRESET  	:1;
	uint32 VECTCLRACT  	:1;
	uint32 SYSRESREQ  	:1;
	uint32				 			:5;
	uint32 PRIGROUP  		:3;
	uint32				 			:4;
	uint32 ENDIANESS  	:1;
	uint32 VECTKEY  		:16;
	
}str_APINT_REG;
typedef union
{
	str_APINT_REG		StrReg_APINT;
	uint32 					UseAllReg_APINT;
}un_APINT_TAG;


/* SYSPRI1 Implementation */
/**********************************/
typedef struct 
{
	uint32   			:5;
	uint32 MEM  	:3;
	uint32   			:5;
	uint32 BUS  	:3;
	uint32   			:5;
	uint32 USAGE  :3;
	uint32   			:8;

}str_SYSPRI1_REG;
typedef union
{
	str_SYSPRI1_REG		StrReg_SYSPRI1;
	uint32 						UseAllReg_SYSPRI1;
}un_SYSPRI1_TAG;



/* SYSPR2 Implementation */
/**********************************/
typedef struct 
{
	uint32   			:29;
	uint32 MEM  	:3;

}str_SYSPR2_REG;
typedef union
{
	str_SYSPR2_REG		StrReg_SYSPRI2;
	uint32 						UseAllReg_SYSPRI2;
}un_SYSPRI2_TAG;



/* SYSPRI3 Implementation */
/**********************************/
typedef struct 
{
	uint32   				:5;
	uint32 DEBUG  	:3;
	uint32   				:13;
	uint32 PENDSV  	:3;
	uint32   				:5;
	uint32 TICK  		:3;


}str_SYSPRI3_REG;
typedef union
{
	str_SYSPRI3_REG		StrReg_SYSPRI3;
	uint32 						UseAllReg_SYSPRI3;
}un_SYSPRI3_TAG;



/* SYSHNDCTRL Implementation */
/**********************************/
typedef struct 
{
	uint32  MEMA 		:1;
	uint32  BUSA 		:1;
	uint32   				:1;
	uint32  USGA		:1;
	uint32   				:3;
	uint32  SVCA 		:1;
	uint32  MON 		:1;
	uint32   				:1;
	uint32  PNDSV 	:1;
	uint32  TICK		:1;
	uint32  USAGEP	:1;
	uint32  MEMP		:1;
	uint32  BUSP		:1;
	uint32  SVC			:1;
	uint32  MEM			:1;
	uint32  BUS			:1;
	uint32  USAGE		:1;
	uint32   				:13;

}str_SYSHNDCTRL_REG;
typedef union
{
	str_SYSHNDCTRL_REG		StrReg_SYSHNDCTRL;
	uint32 								UseAllReg_SYSHNDCTRL;
}un_SYSHNDCTRL_TAG;



/* FAULTSTAT Implementation */
/**********************************/
typedef struct 
{
	uint32  IERR 				:1;
	uint32  DERR 				:1;
	uint32   						:1;
	uint32  MUSTKE			:1;
	uint32  MSTKE 			:1;
	uint32  MLSPERR 		:1;
	uint32       				:1;
	uint32  MMARV 			:1;
	uint32  IBUS 				:1;
	uint32  PRECISE			:1;
	uint32  IMPRE				:1;
	uint32  BUSTKE			:1;
	uint32  BSTKE				:1;
	uint32  BLSPERR			:1;
	uint32  						:1;
	uint32  BFARV				:1;
	uint32  UNDEF				:1;
	uint32  INVSTAT			:1;
	uint32  INVPC				:1;
	uint32  NOCP				:1;
	uint32   						:4;
	uint32  UNALIGN			:1;
	uint32  DIV0				:1;
	uint32   						:6;
	
}str_FAULTSTAT_REG;
typedef union
{
	str_FAULTSTAT_REG		StrReg_FAULTSTAT;
	uint32 								UseAllReg_FAULTSTAT;
}un_FAULTSTAT_TAG;



/* HFAULTSTAT Implementation */
/**********************************/
typedef struct 
{
	uint32   					:1;
	uint32  VECT 			:1;
	uint32   					:28;
	uint32  FORCED		:1;
	uint32  DBG 			:1;

	
}str_HFAULTSTAT_REG;
typedef union
{
	str_HFAULTSTAT_REG		StrReg_HFAULTSTAT;
	uint32 								UseAllReg_HFAULTSTAT;
}un_HFAULTSTAT_TAG;




/* Interrupt Control and State */
#define INTCTRL			(*(volatile un_INTCTRL_TAG*)(EXCEP_BASE_ADD + 0x0D04))
	/* Vector Table Offset*/
#define VTABLE			(*(volatile str_VTABLE_REG*)(EXCEP_BASE_ADD + 0x0D08))
	/* Application Interrupt and Reset Control */
#define APINT				(*(volatile un_APINT_TAG*)(EXCEP_BASE_ADD + 0x0D08))	
	/* System Handler Priority1 */
#define SYSPRI1			(*(volatile un_SYSPRI1_TAG*)(EXCEP_BASE_ADD + 0x0D18))	
	/* System Handler Priority2 */
#define SYSPRI2			(*(volatile un_SYSPRI2_TAG*)(EXCEP_BASE_ADD + 0x0D1C))	
	/* System Handler Priority3 */
#define SYSPRI3			(*(volatile un_SYSPRI3_TAG*)(EXCEP_BASE_ADD + 0x0D20))	
	/* System Handler Control and State */
#define SYSHNDCTRL	(*(volatile un_SYSHNDCTRL_TAG*)(EXCEP_BASE_ADD + 0x0D24))	
	/* Configurable Fault Status */
#define FAULTSTAT		(*(volatile un_FAULTSTAT_TAG*)(EXCEP_BASE_ADD + 0x0D28))
	/* Hard Fault Status */
#define HFAULTSTAT	(*(volatile un_HFAULTSTAT_TAG*)(EXCEP_BASE_ADD + 0x0D2C))



#endif /*   MCU_HW_H_  */
/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/