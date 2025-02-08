#include "LPUART.h"

void set_baudrate(int channel,long unsigned int frequency)
{
    unsigned int SBR_value; 

    SBR_value = frequency / (16 * 9600); 
    switch (channel)
    {
    case LUART_CHANNEL0:
    {
        (*LPUART0).BAUD |= (15u << OSR); 
        (*LPUART0).BAUD |= (SBR_value << SBR);
        break;
    } 
    case LUART_CHANNEL1:
    {
        (*LPUART1).BAUD |= (15u << OSR); 
        (*LPUART1).BAUD |= (SBR_value << SBR);
        break;
    } 
    case LUART_CHANNEL2:
    {
        (*LPUART2).BAUD |= (15u << OSR); 
        (*LPUART2).BAUD |= (SBR_value << SBR);
        break;
    } 
    default:
        break;
    }
}

void set_frame(int channel, int STOP_BIT, int DATA_LENGTH_TRANSFER, int PARITY_BIT)
{
    switch (channel)
    {
    case LUART_CHANNEL0:
    {
        if (STOP_BIT)
        {
            (*LPUART0).BAUD |= (1u << SBNS);  
        }
        else
        {
            (*LPUART0).BAUD &= ~(1u << SBNS);  
            
        }

        /*8 BIT LENGTH*/
        switch (DATA_LENGTH_TRANSFER)
        {
        case DATA_LENGTH7: 
        {
            break;
        }
        case DATA_LENGTH8: 
        {
            (*LPUART0).CTRL = 0; 
        }
        default:
            break;
        }

        /*NO PARITY*/
        (*LPUART0).CTRL &= ~(1u << PE_LPUART); 
        break;
    } 
    case LUART_CHANNEL1:
    {
        if (STOP_BIT)
        {
            (*LPUART1).BAUD |= (1u << SBNS);  
        }
        else
        {
            (*LPUART1).BAUD &= ~(1u << SBNS);  
            
        }

        /*8 BIT LENGTH*/
        switch (DATA_LENGTH_TRANSFER)
        {
        case DATA_LENGTH7: 
        {
            break;
        }
        case DATA_LENGTH8: 
        {
            (*LPUART1).CTRL = 0; 
        }
        default:
            break;
        }

        /*NO PARITY*/
        (*LPUART1).CTRL &= ~(1u << PE_LPUART); 
        break;
    } 
    case LUART_CHANNEL2:
    {
        if (STOP_BIT)
        {
            (*LPUART2).BAUD |= (1u << SBNS);  
        }
        else
        {
            (*LPUART2).BAUD &= ~(1u << SBNS);  
            
        }

        /*8 BIT LENGTH*/
        switch (DATA_LENGTH_TRANSFER)
        {
        case DATA_LENGTH7: 
        {
            break;
        }
        case DATA_LENGTH8: 
        {
            (*LPUART2).CTRL = 0; 
        }
        default:
            break;
        }

        /*NO PARITY*/
        (*LPUART2).CTRL &= ~(1u << PE_LPUART); 
        break;
    } 
    default:
        break;
    }
}

void enable_transmitter_or_receiver(int channel, int ENABLE_TRANSMIT, int ENABLE_RECIEVER)
{
    switch (channel)
    {
    case LUART_CHANNEL0:
    {
        if (ENABLE_TRANSMIT == ENABLE)
        {
            (*LPUART0).CTRL |= (1u << TE);
        }
        else
        {
            (*LPUART0).CTRL &= ~(1u << TE);
        }
        
         if (ENABLE_RECIEVER == ENABLE)
        {
            (*LPUART0).CTRL |= (1u << RE);
        }
        else
        {
            (*LPUART0).CTRL &= ~(1u << RE);
        }

        break; 
    } 
    case LUART_CHANNEL1:
    {
        if (ENABLE_TRANSMIT == ENABLE)
        {
            (*LPUART1).CTRL |= (1u << TE);
        }
        else
        {
            (*LPUART1).CTRL &= ~(1u << TE);
        }
        
         if (ENABLE_RECIEVER == ENABLE)
        {
            (*LPUART1).CTRL |= (1u << RE);
        }
        else
        {
            (*LPUART1).CTRL &= ~(1u << RE);
        }

        break;
    } 
    case LUART_CHANNEL2:
    {
        if (ENABLE_TRANSMIT == ENABLE)
        {
            (*LPUART2).CTRL |= (1u << TE);
        }
        else
        {
            (*LPUART2).CTRL &= ~(1u << TE);
        }
        
         if (ENABLE_RECIEVER == ENABLE)
        {
            (*LPUART2).CTRL |= (1u << RE);
        }
        else
        {
            (*LPUART2).CTRL &= ~(1u << RE);
        }

        break;
    } 
    default:
        break;
    }
}

void send_char(char data)
{
    while (((*LPUART1).STAT & (1u << TDRE)) == 0)
    {}
    (*LPUART1).DATA = data; 
}

void receive_char(char *data)
{
    while (((*LPUART1).STAT & (1u << RDRF)) == 0)
    {}

    *data = (*LPUART1).DATA; 
}

void send_string(char data_string[])
{
    uint32_t i = 0; 
    while (data_string[i] != '\0')
    {
        send_char(data_string[i]); 
        i++; 
    }
}

void receive_string_uart(char data_string[])
{
    uint32_t i = 0; 
    while (data_string[i] != '\0')
    {
        receive_char(&data_string[i]); 
        i++; 
    }
}
