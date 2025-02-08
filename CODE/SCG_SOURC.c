#include "SCG.h"

void config_SOSSC(unsigned int DIV1, unsigned int DIV2, unsigned int HGO, unsigned RANGE, unsigned int EREF)
{
    volatile uint32_t temp = 0; 

    (*SCG).SCG_SOSCCSR = 0x00000000;  // unlock and disable
	(*SCG).SCG_SOSCDIV = 0x00000000;  // clear

    /*Set DIV*/
    temp |= (DIV1 << SOSCDIV1) | (DIV2 << SOSCDIV2); 
    (*SCG).SCG_SOSCDIV = temp; 

    temp = 0; 
    /*config range and HGO*/
    temp |= (HGO << SOSC_HGO) | (RANGE << SOSC_RANGE) | (EREF << SOSC_EREF); 
    (*SCG).SCG_SOSCCFG = temp; 

    while (((*SCG).SCG_SOSCCSR & SOSCCSR_LK_MASK)) // check unlock
	{}
			
	(*SCG).SCG_SOSCCSR |= 1u;  // enable 
			
	while (!((*SCG).SCG_SOSCCSR & (1u << SOSC_VLD_SCR))) // check valid 
	{}
}

void config_SPLL(unsigned int DIV1, unsigned int DIV2, unsigned int PREDIV, unsigned int MULT )
{
    volatile uint32_t temp = 0; 

    (*SCG).SCG_SPLLCSR = 0u; // unlcck and disble 
    (*SCG).SCG_SPLCDIV = 0u; // clear 

    /*Set DIV*/
    temp |= (DIV1 << SPLLDIV1) | (DIV2 << SPLLDIV2); 
    (*SCG).SCG_SPLCDIV = temp; 

    temp = 0; 

    temp |= (MULT << SPLL_MULT) | (PREDIV << SPLL_PREDIV); // Div factor = 1, Mult factor = 20
	(*SCG).SCG_SPLCCFG = temp; 

    while ((*SCG).SCG_SPLLCSR & SPLLCSR_LK_MASK) // check unlock 
	{}
			
	(*SCG).SCG_SPLLCSR = 1u; // enable
		
	while (!((*SCG).SCG_SPLLCSR & (1u << SPLL_VLD_SCR))) // check valid
	{}

}

void config_RCCR(unsigned int SCS, unsigned int DIV_CORE, unsigned int DIV_BUS, unsigned int DIV_LOW)
{
    volatile uint32_t temp = 0; 

    temp |= (SCS << SCS_BITLOCATION) | (DIV_CORE << DIVCORE_BITLOCATION) | (DIV_BUS << DIVBUS_BITLOCATION) | (DIV_LOW << DIVlOW_BITLOCATION); 
    (*SCG).SCG_RCCR = temp; 

	while ( (((*SCG).SCG_RCCR & 0xF000000u) >> 24u) != SCS) // Check valid
	{}
}

void config_FIRC(unsigned int DIV1, unsigned int DIV2, unsigned int RANGE)
{
    volatile uint32_t temp = 0; 

    (*SCG).SCG_FIRCCSR = 0u; // unlcck and disble 
	(*SCG).SCG_FIRCDIV = 0u; // clear

    /*Set DIV*/
    temp |= (DIV1 << FIRCDIV1) | (DIV2 << FIRCDIV2); 
    (*SCG).SCG_FIRCDIV = temp; 

    
    temp = 0;
    /*Set RANGE*/ 
    temp |= (RANGE << FIRCRANGE); 
    (*SCG).SCG_FIRCCFG = temp; 

    while (((*SCG).SCG_FIRCCSR & FIRCCSR_LK_MASK)) // check unlock
	{}

	(*SCG).SCG_FIRCCSR |= 1u ; 

	while (!((*SCG).SCG_FIRCCSR & (1u << FIRC_VLD_SCR))) // check valid 
	{}


} 

void config_SIRC(unsigned int DIV1, unsigned int DIV2,unsigned int RANGE)
{
    volatile uint32_t temp = 0; 

    (*SCG).SCG_SIRCCSR = 0u; // unlcck and disble 
	(*SCG).SCG_SIRCDIV = 0u; // clear

    /*Set DIV*/
    temp |= (DIV1 << SIRCDIV1) | (DIV2 << SIRCDIV2); 
    (*SCG).SCG_SIRCDIV = temp; 

    temp = 0;
    /*Set RANGE*/ 
    temp |= (RANGE << SIRCRANGE); 
    (*SCG).SCG_SIRCCFG = temp; 

    while (((*SCG).SCG_SIRCCSR & SIRCCSR_LK_MASK)) // check unlock
	{}

	(*SCG).SCG_SIRCCSR |= 1u ; 

	while (!((*SCG).SCG_SIRCCSR & (1u << SIRC_VLD_SCR))) // check valid 
	{}
}