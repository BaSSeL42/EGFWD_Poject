/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
 #include"DIO.h"
 #include"Bit_Math.h"
 #include "Mcu_Hw.h"
 #include "STD_Types.h"
 
 
 
STD_LevelType Dio_ReadChannel(enu_Dio_ChannelType ChannelId)
{
	STD_LevelType ret;
	enu_Dio_PortType PortId = ChannelId / 8;
	enu_Dio_ChannelType ChannelPos = ChannelId%8;
	
	switch (PortId)
	{
		case Dio_Port_A:
		{
			ret = GetBit(PORTA_GPIODATA_REG, ChannelPos);
			break;
		}
		
		case Dio_Port_B:
		{
			ret = GetBit(PORTB_GPIODATA_REG, ChannelPos);
			break;
		}
		
		case Dio_Port_C:
		{
			ret = GetBit(PORTC_GPIODATA_REG, ChannelPos); 
			break;           
		}                  
											 
		case Dio_Port_D:   
		{                  
			ret = GetBit(PORTD_GPIODATA_REG, ChannelPos);
			break;           
		}                  
											 
		case Dio_Port_E:   
		{                  
			ret = GetBit(PORTE_GPIODATA_REG, ChannelPos);
			break;
		}
		
		case Dio_Port_F:
		{
			ret = GetBit(PORTF_GPIODATA_REG, ChannelPos);
			break;
		}
		
		default :
		{
			ret = STD_error;
			break;
		}
	}
	
	return ret;
	
}



void Dio_WriteChannel(enu_Dio_ChannelType ChannelId, STD_LevelType Level)
{
	  enu_Dio_PortType PortId = ChannelId / 8;
    enu_Dio_ChannelType ChannelPos = ChannelId % 8;
    switch(PortId)
    {
    case Dio_Port_A:
        if(Level == STD_low)
        {
            ClrBit(PORTA_GPIODATA_REG,ChannelPos);
        }
        else
        {
            SetBit(PORTA_GPIODATA_REG,ChannelPos);
        }
        break;

    case Dio_Port_B:
        if(Level == STD_low)
        {
            ClrBit(PORTB_GPIODATA_REG,ChannelPos);
        }
        else
        {
            SetBit(PORTB_GPIODATA_REG,ChannelPos);
        }
        break;

    case Dio_Port_C:
        if(Level == STD_low)
        {
            ClrBit(PORTC_GPIODATA_REG,ChannelPos);
        }
        else
        {
            SetBit(PORTC_GPIODATA_REG,ChannelPos);
        }
        break;
    case Dio_Port_D:
        if(Level == STD_low)
        {
            ClrBit(PORTD_GPIODATA_REG,ChannelPos);
        }
        else
        {
            SetBit(PORTD_GPIODATA_REG,ChannelPos);
        }
        break;
    case Dio_Port_E:
        if(Level == STD_low)
        {
            ClrBit(PORTE_GPIODATA_REG,ChannelPos);
        }
        else
        {
            SetBit(PORTE_GPIODATA_REG,ChannelPos);
        }
        break;
    case Dio_Port_F:
        if(Level == STD_low)
        {
            ClrBit(PORTF_GPIODATA_REG,ChannelPos);
        }
        else
        {
            SetBit(PORTF_GPIODATA_REG,ChannelPos);
        }
        break;
				
    default:
        /*error*/
        break;
    }
	
	
}



uint8 Dio_ReadPort(enu_Dio_PortType PortId )
{
	    uint8 ret;
    switch(PortId)
    {
    case Dio_Port_A:
        ret = (uint8)PORTA_GPIODATA_REG;
        break;

    case Dio_Port_B:
        ret = (uint8)PORTB_GPIODATA_REG;
        break;

    case Dio_Port_C:
        ret = (uint8)PORTC_GPIODATA_REG;
        break;
    case Dio_Port_D:
        ret = (uint8)PORTD_GPIODATA_REG;
        break;
    case Dio_Port_E:
        ret = (uint8)PORTE_GPIODATA_REG;
        break;
    case Dio_Port_F:
        ret = (uint8)PORTF_GPIODATA_REG;
        break;
    default:
        /*error*/
		ret = STD_error;
        break;
    }

    return ret;
	
	
}




void Dio_WritePort( enu_Dio_PortType PortId, uint8 Level)
{
	
    switch(PortId)
    {
    case Dio_Port_A:
        PORTA_GPIODATA_REG = Level;
        break;
    case Dio_Port_B:
        PORTB_GPIODATA_REG = Level;
        break;
    case Dio_Port_C:
        PORTC_GPIODATA_REG = Level;
        break;
    case Dio_Port_D:
        PORTD_GPIODATA_REG = Level;
        break;
    case Dio_Port_E:
        PORTE_GPIODATA_REG = Level;
        break;
    case Dio_Port_F:
        PORTF_GPIODATA_REG = Level;
        break;
    default:
        /*error*/
        break;
    }
	
}




void Dio_FlipChannel( enu_Dio_ChannelType ChannelId)
{
	  enu_Dio_PortType PortId = ChannelId / 8;
    enu_Dio_ChannelType ChannelPos = ChannelId % 8;

    switch(PortId)
    {
    case Dio_Port_A:
        ToggleBit(PORTA_GPIODATA_REG,ChannelPos);
        break;

    case Dio_Port_B:
        ToggleBit(PORTB_GPIODATA_REG,ChannelPos);
        break;

    case Dio_Port_C:
        ToggleBit(PORTC_GPIODATA_REG,ChannelPos);
        break;
    case Dio_Port_D:
        ToggleBit(PORTD_GPIODATA_REG,ChannelPos);
        break;
    case Dio_Port_E:
        ToggleBit(PORTE_GPIODATA_REG,ChannelPos);
        break;
    case Dio_Port_F:
        ToggleBit(PORTF_GPIODATA_REG,ChannelPos);
        break;
    default:
        /*error*/
        break;
    }
	
}







void Dio_FlipPort(enu_Dio_PortType PortId)
{
	    switch(PortId)
    {
    case Dio_Port_A:
        PORTA_GPIODATA_REG = ~ PORTA_GPIODATA_REG;
        break;
    case Dio_Port_B:
        PORTB_GPIODATA_REG = ~PORTB_GPIODATA_REG;
        break;
    case Dio_Port_C:
        PORTC_GPIODATA_REG = ~PORTC_GPIODATA_REG;
        break;
    case Dio_Port_D:
        PORTD_GPIODATA_REG = ~PORTD_GPIODATA_REG;
        break;
    case Dio_Port_E:
        PORTE_GPIODATA_REG = ~PORTE_GPIODATA_REG;
        break;
    case Dio_Port_F:
        PORTF_GPIODATA_REG= ~PORTF_GPIODATA_REG;
        break;
    default:
        /*error*/
        break;
    }
	
	
}

 
 
 