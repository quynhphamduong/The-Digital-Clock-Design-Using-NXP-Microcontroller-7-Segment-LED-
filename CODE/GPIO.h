#ifndef GPIO_H_
#define GPIO_H_

#include <stdint.h>

typedef struct 
{
    // Port Data Output Register
    volatile uint32_t PDOR; // 0x00

    // Port Set Output Register
    volatile uint32_t PSOR; // 0x04

    // Port Clear Output Register
    volatile uint32_t PCOR; // 0x08

    // Port Toggle Output Register
    volatile uint32_t PTOR; // 0x0C

    // Port Data Input Register
    volatile uint32_t PDIR; // 0x10

    // Port Data Direction Register
    volatile uint32_t PDDR; // 0x14

    // Port Input Disable Register
    volatile uint32_t PIDR; // 0x18
} GPIO_type;

#define PORTA_BASE (0x400FF000u)
#define GPIOA ((GPIO_type *) PORTA_BASE)

#define PORTB_BASE (0x400FF040u)
#define GPIOB ((GPIO_type *) PORTB_BASE)

#define PORTC_BASE (0x400FF080u)
#define GPIOC ((GPIO_type *) PORTC_BASE)

#define PORTD_BASE (0x400FF0C0u)
#define GPIOD ((GPIO_type *) PORTD_BASE)

#define PORTE_BASE (0x400FF100u)
#define GPIOE ((GPIO_type *) PORTE_BASE)

#endif