#include "SYSTEMTICK.h"

void systick_config(uint32_t ticks, int INTERRUPT)
{
    (*SYSTICK).SYST_RVR = (uint32_t)(ticks - 1UL);  /* set reload register */
	(*SYSTICK).SYST_CVR = 0UL;                      /* Load the SysTick Counter Value */
	(*SYSTICK).SYST_CSR = 0u; 						/* Clear register*/
    (*SYSTICK).SYST_CSR = (1u << SYS_ENABLE) | (1u << SYS_CLKSOURCE) | (INTERRUPT << SYS_TICKINT)	;  /* SysTick Timer */
}

void check_ticks(uint32_t ms, long unsigned int frequency , int *DIV)
{
	/*check the tick to div each period that can store to the load register 24 bit*/
	if ((frequency / 1000UL) * ms > 16000000u)
	{
		*DIV = (frequency / 1000UL) * ms / 16000000u;
	}
	else
	{
		*DIV = 1; 
	}
	
}

void delay_ms(uint32_t ms, long unsigned int frequency)
{
	int div; 
	check_ticks(ms, frequency,&div); 
		
	div += 1; 
	for (int i = 0; i < div; i++)
	{
    	systick_config((frequency / 1000UL) * ms / div , 0);   
    	while(!((*SYSTICK).SYST_CSR & (1u << SYS_COUNTFLAG)));  // Wait for COUNTFLAG to be set
    	(*SYSTICK).SYST_CSR = 0;  // Disable SysTick
	}
}