#ifndef TIMER_CFG_H_
#define TIMER_CFG_H_


/**********************************************************************************************************************
 * GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
#include "STD_Types.h"


typedef enum
{
	one_shot,
	periodic
	
}enu_timerType;


typedef enum
{
	single_mode,
	concatenate_mode_timer_cfg,
	concatenate_mode_timer_rtc
	
}enu_timerHwMode;

typedef enum
{
	COUNT_DOWN=0,
	COUNT_UP
}enu_timerDirection;


typedef enum
{
	TIMER0,
	TIMER1,
	TIMER2,
	TIMER3,
	TIMER4,
	TIMER5,
	
	WIDE_TIMER0,
	WIDE_TIMER1,
	WIDE_TIMER2,
	WIDE_TIMER3,
	WIDE_TIMER4,
	WIDE_TIMER5
	
}enu_TimerchannelId;

typedef enum
{
	NON_INVERTED,
	INVERTED
	
}enu_PWMOutputLevel;


typedef uint32 u32_time_ms;

typedef struct
{
	enu_timerType  			GPT_type;
	enu_timerHwMode 		HwMode;
	enu_timerDirection	TimerDir;
	enu_TimerchannelId 	ChId;
	enu_PWMOutputLevel  OutLevel;
	u32_time_ms					time_ms;
	
}str_Gpt_ConfigType;

#endif /*   TIMER_CFG_H_   */
/**********************************************************************************************************************
 *  END OF FILE: TIMER_Cfg.h
 *********************************************************************************************************************/