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
			ret = GetBit(PORTA_REG.GPIODATA, ChannelPos);
			break;
		}
		
		case Dio_Port_B:
		{
			ret = GetBit(PORTB_REG.GPIODATA, ChannelPos);
			break;
		}
		
		case Dio_Port_C:
		{
			ret = GetBit(PORTC_REG.GPIODATA, ChannelPos);
			break;
		}
		
		case Dio_Port_D:
		{
			ret = GetBit(PORTD_REG.GPIODATA, ChannelPos);
			break;
		}
		
		case Dio_Port_E:
		{
			ret = GetBit(PORTE_REG.GPIODATA, ChannelPos);
			break;
		}
		
		case Dio_Port_F:
		{
			ret = GetBit(PORTF_REG.GPIODATA, ChannelPos);
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
            ClrBit(PORTA_REG.GPIODATA,ChannelPos);
        }
        else
        {
            SetBit(PORTA_REG.GPIODATA,ChannelPos);
        }
        break;

    case Dio_Port_B:
        if(Level == STD_low)
        {
            ClrBit(PORTB_REG.GPIODATA,ChannelPos);
        }
        else
        {
            SetBit(PORTB_REG.GPIODATA,ChannelPos);
        }
        break;

    case Dio_Port_C:
        if(Level == STD_low)
        {
            ClrBit(PORTC_REG.GPIODATA,ChannelPos);
        }
        else
        {
            SetBit(PORTC_REG.GPIODATA,ChannelPos);
        }
        break;
    case Dio_Port_D:
        if(Level == STD_low)
        {
            ClrBit(PORTD_REG.GPIODATA,ChannelPos);
        }
        else
        {
            SetBit(PORTD_REG.GPIODATA,ChannelPos);
        }
        break;
    case Dio_Port_E:
        if(Level == STD_low)
        {
            ClrBit(PORTE_REG.GPIODATA,ChannelPos);
        }
        else
        {
            SetBit(PORTE_REG.GPIODATA,ChannelPos);
        }
        break;
    case Dio_Port_F:
        if(Level == STD_low)
        {
            ClrBit(PORTF_REG.GPIODATA,ChannelPos);
        }
        else
        {
            SetBit(PORTF_REG.GPIODATA,ChannelPos);
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
        ret = (uint8)PORTA_REG.GPIODATA;
        break;

    case Dio_Port_B:
        ret = (uint8)PORTB_REG.GPIODATA;
        break;

    case Dio_Port_C:
        ret = (uint8)PORTC_REG.GPIODATA;
        break;
    case Dio_Port_D:
        ret = (uint8)PORTD_REG.GPIODATA;
        break;
    case Dio_Port_E:
        ret = (uint8)PORTE_REG.GPIODATA;
        break;
    case Dio_Port_F:
        ret = (uint8)PORTF_REG.GPIODATA;
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
        PORTA_REG.GPIODATA = Level;
        break;
    case Dio_Port_B:
        PORTB_REG.GPIODATA = Level;
        break;
    case Dio_Port_C:
        PORTC_REG.GPIODATA = Level;
        break;
    case Dio_Port_D:
        PORTD_REG.GPIODATA = Level;
        break;
    case Dio_Port_E:
        PORTE_REG.GPIODATA = Level;
        break;
    case Dio_Port_F:
        PORTF_REG.GPIODATA = Level;
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
        ToggleBit(PORTA_REG.GPIODATA,ChannelPos);
        break;

    case Dio_Port_B:
        ToggleBit(PORTB_REG.GPIODATA,ChannelPos);
        break;

    case Dio_Port_C:
        ToggleBit(PORTC_REG.GPIODATA,ChannelPos);
        break;
    case Dio_Port_D:
        ToggleBit(PORTD_REG.GPIODATA,ChannelPos);
        break;
    case Dio_Port_E:
        ToggleBit(PORTE_REG.GPIODATA,ChannelPos);
        break;
    case Dio_Port_F:
        ToggleBit(PORTF_REG.GPIODATA,ChannelPos);
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
        PORTA_REG.GPIODATA = ~ PORTA_REG.GPIODATA;
        break;
    case Dio_Port_B:
        PORTB_REG.GPIODATA = ~PORTB_REG.GPIODATA;
        break;
    case Dio_Port_C:
        PORTC_REG.GPIODATA = ~PORTC_REG.GPIODATA;
        break;
    case Dio_Port_D:
        PORTD_REG.GPIODATA = ~PORTD_REG.GPIODATA;
        break;
    case Dio_Port_E:
        PORTE_REG.GPIODATA = ~PORTE_REG.GPIODATA;
        break;
    case Dio_Port_F:
        PORTF_REG.GPIODATA = ~PORTF_REG.GPIODATA;
        break;
    default:
        /*error*/
        break;
    }
	
	
}

 
 
 