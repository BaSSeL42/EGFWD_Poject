/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_H
#define INTCTRL_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "STD_Types.h"
#include "Mcu_Hw.h"
#include "IntCtrl_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum {
		/*EXCEPTIONS*/
		/***********/
  Reset_IRQ                    = -15,
  NonMaskableInt_IRQ           = -14,
  HardFault_IRQ                = -13,
  MemoryManagement_IRQ         = -12,
  BusFault_IRQ                 = -11,
  UsageFault_IRQ               = -10,
  SVCall_IRQ                   =  -5,
  DebugMonitor_IRQ             =  -4,
  PendSV_IRQ                   =  -2,
  SysTick_IRQ                  =  -1,
	
	/*IRQ*/
	/****/
  GPIOA_IRQ                    =   0,
  GPIOB_IRQ                    =   1,
  GPIOC_IRQ                    =   2,
  GPIOD_IRQ                    =   3,
  GPIOE_IRQ                    =   4,
  UART0_IRQ                    =   5,
  UART1_IRQ                    =   6,
  SSI0_IRQ                     =   7,
  I2C0_IRQ                     =   8,
  PWM0_FAULT_IRQ               =   9,
  PWM0_0_IRQ                   =  10,
  PWM0_1_IRQ                   =  11,
  PWM0_2_IRQ                   =  12,
  QEI0_IRQ                     =  13,
  ADC0SS0_IRQ                  =  14,
  ADC0SS1_IRQ                  =  15,
  ADC0SS2_IRQ                  =  16,
  ADC0SS3_IRQ                  =  17,
  WATCHDOG0_1_IRQ              =  18,
  TIMER0A_IRQ                  =  19,
  TIMER0B_IRQ                  =  20,
  TIMER1A_IRQ                  =  21,
  TIMER1B_IRQ                  =  22,
  TIMER2A_IRQ                  =  23,
  TIMER2B_IRQ                  =  24,
  COMP0_IRQ                    =  25,
  COMP1_IRQ                    =  26,
	
  SYSCTL_IRQ                   =  28,
  FLASH_CTRL_IRQ               =  29,
  GPIOF_IRQ                    =  30,
	
  UART2_IRQ                    =  33,
  SSI1_IRQ                     =  34,
  TIMER3A_IRQ                  =  35,
  TIMER3B_IRQ                  =  36,
  I2C1_IRQ                     =  37,
  QEI1_IRQ                     =  38,
  CAN0_IRQ                     =  39,
  CAN1_IRQ                     =  40,
	
  HIB_IRQ                      =  43,
  USB0_IRQ                     =  44,
  PWM0_3_IRQ                   =  45,
  UDMA_IRQ                     =  46,
  UDMAERR_IRQ                  =  47,
  ADC1SS0_IRQ                  =  48,
  ADC1SS1_IRQ                  =  49,
  ADC1SS2_IRQ                  =  50,
  ADC1SS3_IRQ                  =  51,
	
  SSI2_IRQ                     =  57,
  SSI3_IRQ                     =  58,
  UART3_IRQ                    =  59,
  UART4_IRQ                    =  60,
  UART5_IRQ                    =  61,
  UART6_IRQ                    =  62,
  UART7_IRQ                    =  63,
  I2C2_IRQ                     =  68,
  I2C3_IRQ                     =  69,
  TIMER4A_IRQ                  =  70,
  TIMER4B_IRQ                  =  71,
	
  TIMER5A_IRQ                  =  92,
  TIMER5B_IRQ                  =  93,
  WTIMER0A_IRQ                 =  94,
  WTIMER0B_IRQ                 =  95,
  WTIMER1A_IRQ                 =  96,
  WTIMER1B_IRQ                 =  97,
  WTIMER2A_IRQ                 =  98,
  WTIMER2B_IRQ                 =  99,
  WTIMER3A_IRQ                 = 100,
  WTIMER3B_IRQ                 = 101,
  WTIMER4A_IRQ                 = 102,
  WTIMER4B_IRQ                 = 103,
  WTIMER5A_IRQ                 = 104,
  WTIMER5B_IRQ                 = 105,
  SYSEXC_IRQ                   = 106,
	
  PWM1_0_IRQ                   = 134,
  PWM1_1_IRQ                   = 135,
  PWM1_2_IRQ                   = 136,
  PWM1_3_IRQ                   = 137,
  PWM1_FAULT_IRQ               = 138
	
}enu_InterruptIRQ;

typedef enum
{
	EN_0 = 0,
	EN_1,
	EN_2,
	EN_3
	
}enu_ENx;



typedef enum{
USE_ALL_GROUPS = 4,                     /* 8 Groups and 1 Subgroup*/
USE_4_GROUPS_2_SUBGROUPS = 5,           /* 4 Groups and 2 Subgroups*/
USE_2_GROUPS_4_SUBGROUPS = 6,           /* 2 Groups and 4 Subgroups*/
USE_ALL_SUBGROUPS = 7                  /* 1 Group and 8 Subgroups*/
}enu_Group_SubgroupType;



typedef struct 
{
    uint8 INT_STATE  :1;  /* Assign to 1 to Enable it*/
    uint8            :3;
    uint8 PRI_GRP    :3;  /* Priority Groups Assigning*/
    uint8            :1;
}str_UserIntBF;
typedef union 
{
    uint8 					REG;
    str_UserIntBF StrUserBF;
}un_UserIntTag;



typedef enum
{
	SUB_GROUP_PRIO_0 = 0,
	SUB_GROUP_PRIO_1 = 1,
	SUB_GROUP_PRIO_2 = 2,
	SUB_GROUP_PRIO_3 = 3,
	SUB_GROUP_PRIO_4 = 4,
	SUB_GROUP_PRIO_5 = 5,
	SUB_GROUP_PRIO_6 = 6,
	SUB_GROUP_PRIO_7 = 7
	
}enu_SubGroupPrioType;


typedef enum
{
	GROUP_PRIO_0 = 0,
	GROUP_PRIO_1 = 1,
	GROUP_PRIO_2 = 2,
	GROUP_PRIO_3 = 3,
	GROUP_PRIO_4 = 4,
	GROUP_PRIO_5 = 5,
	GROUP_PRIO_6 = 6,
	GROUP_PRIO_7 = 7
	
}enu_GroupPrioType;



typedef struct 
{
	enu_InterruptIRQ 			nterruptIRQ;
	enu_GroupPrioType 		Group_Prio;
	enu_SubGroupPrioType 	Sub_Group_Prio;
	
} str_IntCfgType;


typedef struct 
{
    enu_Group_SubgroupType 	groupspriority_config; 
		str_IntCfgType 					Int_Cfg[CFG_INT_NUM];
} str_UserDataType;


/**********************************************************************************************************************/
 /*  APIs */
 /*********************************************************************************************************************/

void IntCrtl_Init(void);

void Interrupt_Set_and_Cfg(uint8 int_num,uint8 pri_group);

void Groups_Cfg(enu_Group_SubgroupType type);

#endif  /* INTCTRL_H*/
/**********************************************************************************************************************/
 /*  END OF FILE: IntCtrl.h*/
 /*********************************************************************************************************************/