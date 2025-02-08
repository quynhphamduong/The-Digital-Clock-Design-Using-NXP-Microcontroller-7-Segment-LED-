#include "LPIT.h"

void enable_module_clock(void)
{
    (*LPIT).MCR |= (1u << DBG_EN) | (1u << M_CEN);
}

void enable_interrupt(int channel)
{
	(*LPIT).MIER |= (1u << channel);
}

void setup_value_timer(uint32_t ticks, int channel)
{ 
    switch (channel)
    {
    case CHANNEL_0: 
    {
        (*LPIT).TVAKL0 = ticks  - 1;
        (*LPIT).TCTRL0 |= (1u << T_EN);
        break; 
    }
    case CHANNEL_1: 
    {
        (*LPIT).TVAKL1 = ticks  - 1;
        (*LPIT).TCTRL1 |= (1u << T_EN);
        break; 
    }
    case CHANNEL_2: 
    {
        (*LPIT).TVAKL2 = ticks  - 1;
        (*LPIT).TCTRL2 |= (1u << T_EN);
        break; 
    }
    case CHANNEL_3: 
    {
        (*LPIT).TVAKL0 = ticks  - 1;
        (*LPIT).TCTRL2 |= (1u << T_EN);
        break; 
    }
    default:
        break;
    }

}