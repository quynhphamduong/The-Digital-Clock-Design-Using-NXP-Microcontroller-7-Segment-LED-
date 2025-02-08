#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include <stdint.h>

typedef struct 
{
    /*Interrupt Set-Enable Registers */
    volatile uint32_t NVIC_ISER_REG[8]; 

    /* Fill data to struct*/
    volatile uint32_t RESERVED_0[24]; 

    /* Interrupt Clear-Enable Registers */
    volatile uint32_t NVIC_ICER_REG[8]; 

    /* Fill data to struct*/
    volatile uint32_t RESERVED_1[24];

    /* Interrupt Set-Pending Registers */
    volatile uint32_t NVIC_ISPR_REG[8]; 

    /* Fill data to struct*/
    volatile uint32_t RESERVED_2[24];

    /* Interrupt Clear-Pending Registers */
    volatile uint32_t NVIC_ICPR_REG[8]; 

    /* Fill data to struct*/
    volatile uint32_t RESERVED_3[24];

     /* Interrupt Active Bit Register */
    volatile uint32_t NVIC_IABR_REG[8]; 

    /* Fill data to struct*/
    volatile uint32_t RESERVED_4[56];

    /* Interrupt Priority Register */
    volatile uint32_t NVIC_IPR_REG[60]; 

} NVIC_REG; 

#define NVIC_ISER_BASE (0xE000E100)
#define NVIC ((NVIC_REG*) NVIC_ISER_BASE) 

/**
 * @brief Initializes and configures an interrupt request (IRQ) in the NVIC (Nested Vector Interrupt Controller).
 * 
 * This function enables an interrupt with a specified ID, assigns it to a specific NVIC register, and sets its priority.
 * The configuration is done by modifying the NVIC's interrupt set-enable registers and interrupt priority registers.
 * 
 * The function performs the following actions:
 * 
 * - Calculates the appropriate NVIC interrupt set-enable register and bit position based on the interrupt ID.
 * - Enables the interrupt by setting the corresponding bit in the NVIC's interrupt set-enable register.
 * - Calculates the priority position within the NVIC priority register and sets the priority for the interrupt.
 * 
 * @param ID The interrupt ID. This determines which interrupt is to be configured.
 * @param register_number The index of the NVIC interrupt priority register to be used.
 * @param priority The priority level to be assigned to the interrupt. This value is shifted and masked
 *        to fit the NVIC's priority register format.
 * 
 * @note The NVIC priority registers are organized such that each interrupt has its own priority field. 
 *       The priority value is shifted and set based on its position within the priority register.
 * 
 * @see NVIC
 */
void IRQ_init(int ID, int register_number, int priority);

#endif
