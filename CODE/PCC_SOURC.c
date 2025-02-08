#include "PCC.h"

void enable_PCC_PORT(char Enable_PORT)
{
   if (Enable_PORT== 'A')
   {
        (*PCC).PCC_PORTA |= ENABLE_PCC_PORT_MASK; 
   }  
   else if (Enable_PORT == 'B')
   {
        (*PCC).PCC_PORTB |= ENABLE_PCC_PORT_MASK; 
   }
   else if (Enable_PORT == 'C')
   {
        (*PCC).PCC_PORTC |= ENABLE_PCC_PORT_MASK; 
   }
   else if (Enable_PORT == 'D')
   {
        (*PCC).PCC_PORTD |= ENABLE_PCC_PORT_MASK; 
   }
   else if (Enable_PORT == 'E')
   {
        (*PCC).PCC_PORTE |= ENABLE_PCC_PORT_MASK;
   }
   else 
   {
    /*do no thing*/
   }

}

void enable_PCC_LPIT(void)
{
     (*PCC).PCC_LPIT |= ENABLE_PCC_LPIT_MASK | (6u << PCS_PCC);
     
}

void enable_PCC_LUART(int channel,unsigned int CLOCK_SOURCE)
{
     switch (channel)
     {
     case LUART_CHANNEL0: 
     {
          (*PCC).PCC_LPUART0 |= ENABLE_PCC_LUART_MASK | (CLOCK_SOURCE << PCS_PCC);
          break;
     }
     case LUART_CHANNEL1: 
     {
          (*PCC).PCC_LPUART1 |= ENABLE_PCC_LUART_MASK | (CLOCK_SOURCE << PCS_PCC);
          break;
     }
     case LUART_CHANNEL2: 
     {
          (*PCC).PCC_LPUART2 |= ENABLE_PCC_LUART_MASK | (CLOCK_SOURCE << PCS_PCC);
          break;
     }
     default:
          break;
     }
}