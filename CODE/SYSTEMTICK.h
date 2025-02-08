#ifndef SYSTEMTICK_H_
#define SYSTEMTICK_H_

#include <stdint.h>

/**
 * @brief SysTick Count Flag Bit
 * 
 * This bit flag is set when the SysTick counter reaches zero and 
 * generates an interrupt. It indicates that the counter has overflowed.
 */
#define SYS_COUNTFLAG    (16u)

/**
 * @brief SysTick Clock Source
 * 
 * This bit field defines the clock source for the SysTick timer. 
 * A value of 2 indicates the use of the processor clock.
 */
#define SYS_CLKSOURCE    (2u)

/**
 * @brief SysTick Interrupt Enable Bit
 * 
 * This bit enables or disables the SysTick interrupt. 
 * A value of 1 enables the interrupt, while 0 disables it.
 */
#define SYS_INTER        (1u)

/**
 * @brief SysTick Interrupt Enable Bit for Timer
 * 
 * This bit controls whether the SysTick timer interrupt is enabled. 
 * A value of 1 enables the interrupt.
 */
#define SYS_TICKINT      (1u)

/**
 * @brief SysTick Timer Enable Bit
 * 
 * This bit enables or disables the SysTick timer. 
 * A value of 0 enables the timer.
 */
#define SYS_ENABLE       (0u)


typedef struct 
{
    /* Systick Control and Status Register */
    volatile unsigned int SYST_CSR;
    /* Systick Reload Value Register */
    volatile unsigned int SYST_RVR;
    /* Systick Current Value Register */
    volatile unsigned int SYST_CVR;
    /* Systick Calibration Value Register */
    volatile const unsigned int SYST_CALIB;
} SysTick_Type;

#define SYSTICK_BASE_ADDRESS (0xE000E010)
#define SYSTICK ((SysTick_Type*)SYSTICK_BASE_ADDRESS)

/**
 * @brief Configures the SysTick timer.
 * 
 * This function initializes the SysTick timer with a specified number of ticks and enables or disables 
 * the SysTick interrupt based on the provided parameter.
 * 
 * @param ticks Number of ticks to count before generating a SysTick interrupt. 
 *              This value is used to set the reload value for the SysTick timer. The SysTick timer 
 *              will reload with this value each time it reaches zero.
 * @param INTERRUPT Specifies whether the SysTick interrupt should be enabled or disabled. 
 *                  Use a value of 1 to enable the interrupt and 0 to disable it.
 * 
 * @note This function:
 * - Sets the SysTick Reload Value Register (`SYST_RVR`) to `ticks - 1` to count the specified number of ticks.
 * - Clears the current value of the SysTick Counter Value Register (`SYST_CVR`).
 * - Clears the SysTick Control and Status Register (`SYST_CSR`) and then configures it by:
 *   - Setting the SysTick Timer Enable bit (`SYS_ENABLE`).
 *   - Selecting the clock source bit (`SYS_CLKSOURCE`).
 *   - Configuring the interrupt enable bit based on the `INTERRUPT` parameter (`SYS_TICKINT`).
 */
void systick_config(uint32_t ticks, int INTERRUPT); 

/**
 * @brief Calculates the division factor to ensure the tick period fits within the load register's range.
 * 
 * This function computes a division factor based on the requested time period in milliseconds and 
 * the given frequency, so that the tick value can be stored in the 24-bit reload register of the SysTick timer.
 * 
 * @param ms The desired time period in milliseconds for the tick.
 * @param frequency The frequency of the clock source in Hz. This is used to determine the tick rate.
 * @param DIV Pointer to an integer where the computed division factor will be stored. 
 *            The division factor ensures that the calculated tick value fits within the 24-bit register.
 * 
 * @note The function checks if the tick value required for the given period exceeds the maximum 
 *       value that can be stored in a 24-bit register (16,000,000). If so, it calculates the 
 *       appropriate division factor to reduce the tick value to fit within the 24-bit limit. 
 *       If the tick value is within the limit, the division factor is set to 1.
 */
void check_ticks(uint32_t ms, long unsigned int frequency, int *DIV);

/**
 * @brief Delays the program execution for a specified number of milliseconds.
 * 
 * This function uses the SysTick timer to create a delay of approximately `ms` milliseconds.
 * The function first determines an appropriate division factor to ensure that the delay 
 * fits within the 24-bit reload register of the SysTick timer. It then configures the 
 * SysTick timer for the calculated tick value and waits for the COUNTFLAG to be set, 
 * indicating that the delay period has elapsed.
 * 
 * @param ms The delay time in milliseconds.
 * @param frequency The frequency of the clock source in Hz. This is used to calculate the tick rate.
 * 
 * @note The `check_ticks` function is called to determine if a division factor is needed to fit 
 *       the delay period into the 24-bit SysTick reload register. The SysTick timer is configured 
 *       to generate the required delay, and the program waits for the COUNTFLAG to indicate that 
 *       the delay period has passed. The SysTick timer is then disabled to ensure that it does not 
 *       continue to count.
 */
void delay_ms(uint32_t ms, long unsigned int frequency);
#endif 