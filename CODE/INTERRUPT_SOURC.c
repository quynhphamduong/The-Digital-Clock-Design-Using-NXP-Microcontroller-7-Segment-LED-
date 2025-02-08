#include "INTERRUPT.h"

void IRQ_init(int ID, int register_number, int priority)
{
    int number_register = ID / 32 ; 
    int bitlocation = ID % 32; 
	
   (*NVIC).NVIC_ISER_REG[number_register] |= (1u << bitlocation); 

   int bitlocation_priority = 8 * bitlocation + 4;

   (*NVIC).NVIC_IPR_REG[register_number] |= (priority << bitlocation_priority )  ;
}

