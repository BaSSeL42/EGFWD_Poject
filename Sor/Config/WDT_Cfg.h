#ifndef WDT_CFG_H_
#define WDT_CFG_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

 typedef enum
 {
	 STD, //standard
	 NMI // Non Maskable Interrupt
	 
 }enu_InterruptType;
 
 typedef enum{
	 Reset_Enable,
	 Reset_Disable
 }enu_rstEn;
 
 
 typedef void(*ptr2func)(void);
 
 typedef struct
 {
	 enu_InterruptType IntType;
	 enu_rstEn 		rstEn;
	 ptr2func ptrFun;
	 
 }wdtCfg;





#endif /*   WDT_CFG_H_   */
/**********************************************************************************************************************
 *  END OF FILE: WDT_cfg.h
 *********************************************************************************************************************/