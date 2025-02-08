#ifndef PORT_H_
#define PORT_H_

#include <stdint.h>
#include "PCC.h"
#include "SCG.h"

enum MUX_VALUE
{
    DISABLE = 0, 
    ALTERNATIVE1 , 
    ALTERNATIVE2,
    ALTERNATIVE3,
    ALTERNATIVE4,
    ALTERNATIVE5,
    ALTERNATIVE6,
    ALTERNATIVE7
};

enum PCR_BIT
{
    PS = 0,                            /*Pull Select*/
    PE,                                /*Pull Enable*/
    PFE = 4,                           /*Passive Filter Enable*/
    DSE = 6,                           /*Drive Strength Enable*/
    MUX = 8,                           /*Pin Mux Control*/
    LK = 15,                           /*Lock Register*/
    IRQC,                              /*Interrupt Configuration*/
    ISF = 24                           /*Interrupt Status Flag*/
};

/**
 * @brief Mask for configuring GPIO as the multiplexer selection.
 * 
 * This macro sets the multiplexer selection to GPIO by setting bit 8 to 1.
 */
#define PORT_MUX_MASK_GPIO                 (ALTERNATIVE1 << 8u) ///< MUX = 001

/**
 * @brief Mask for configuring chip-specific LPUART as the multiplexer selection.
 * 
 * This macro sets the multiplexer selection to chip-specific LPUART by setting bits 8 and 9.
 */
#define PORT_MUX_MASK_CHIP_SPECIFIC_LPUART (ALTERNATIVE2 << 8u) ///< MUX = 010

/**
 * @brief Mask to set the pull-up resistor in a GPIO configuration.
 * 
 * This macro enables the pull-up resistor by setting bit 1 to 1.
 */
#define SET_PE_MASK                        (1u << 1u) ///< PE = 1

/**
 * @brief Mask to set the pull-down resistor in a GPIO configuration.
 * 
 * This macro enables the pull-down resistor by setting bit 0 to 1.
 */
#define SET_PS_MASK                        (1u) ///< PS = 1

/**
 * @brief Disable interrupt trigger edge configuration.
 * 
 * This macro disables the interrupt by clearing bit 16.
 */
#define DISABLE_INTERRUPT    ~(1u << 16u) ///< Disable interrupt trigger edge

/**
 * @brief Configure interrupt to trigger on both rising and falling edges.
 * 
 * This macro configures the interrupt to trigger on both edges by setting bits 16 and 17.
 */
#define INTERRUPT_BOTH_EDGE  (11u << 16u) ///< Both edge trigger

/**
 * @brief Configure interrupt to trigger on the falling edge.
 * 
 * This macro configures the interrupt to trigger on the falling edge by setting bits 16 and 17.
 */
#define INTERRUPT_FALLING_EDGE (10u << 16u) ///< Falling edge trigger

/**
 * @brief Configure interrupt to trigger on the rising edge.
 * 
 * This macro configures the interrupt to trigger on the rising edge by setting bits 16 and 17.
 */
#define INTERRUPT_RISING_EDGE (9u << 16u) ///< Rising edge trigger


typedef struct 
{
    // Pin Control Register n [0:31]
    volatile uint32_t PORT_PCR[32]; // 0x00 - 0x7C

    // Global Pin Control Low Register
    volatile uint32_t PORT_GPCLR;// 0x80

    // Global Pin Control High Register
    volatile uint32_t PORT_GPCHR;// 0x84

    // Global Interrupt Control Low Register
    volatile uint32_t PORT_GICLR;// 0x88

    // Global Interrupt Control High Register
    volatile uint32_t PORT_GICHR;// 0x8C

    // Fill data struct 
    uint32_t  RESERVED_0[4]; // 0x90 0x94 0x98 0x9C

    // Interrupt Status Flag Register
    volatile uint32_t PORT_ISFR; // 0xA0

    // Fill data struct 
    uint32_t  RESERVED_1[7]; // 0xA4 0xA8 0xAC 0xB0 0xB4 0xB8 0xBC

    // Digital Filter Enable Register
    volatile uint32_t PORT_DFER; // 0xC0

    // Digital Filter Clock Register
    volatile uint32_t PORT_DFCR; // 0xC4

    // Digital Filter Width Register
    volatile uint32_t PORT_DFWR; // 0xC8



} PORT_type; 

#define PORTA_BASE_ADDR (0x40049000u) 
#define PORTA   ((PORT_type*) PORTA_BASE_ADDR )

#define PORTB_BASE_ADDR (0x4004A000u)
#define PORTB   ((PORT_type*) PORTB_BASE_ADDR )

#define PORTC_BASE_ADDR (0x4004B000u)
#define PORTC   ((PORT_type*) PORTC_BASE_ADDR )

#define PORTD_BASE_ADDR (0x4004C000u)
#define PORTD   ((PORT_type*) PORTD_BASE_ADDR )

#define PORTE_BASE_ADDR (0x4004D000u)
#define PORTE   ((PORT_type*) PORTE_BASE_ADDR )

/**
 * @brief Configures the PCR (Pin Control Register) settings for a specified port.
 * 
 * This function sets up the pin control for a given port including the direction, pull-up/pull-down resistor settings,
 * and interrupt configuration. The function applies settings to the specified port (A to E) and pin based on the input parameters.
 * 
 * @param PORT The port to configure. It should be one of the following characters:
 *             - 'A' for PORTA
 *             - 'B' for PORTB
 *             - 'C' for PORTC
 *             - 'D' for PORTD
 *             - 'E' for PORTE
 * @param PORT_SET_UP The pin number within the specified port to configure (e.g., 0-31).
 * @param PORT_DIRECTION The direction of the pin. It can be:
 *                       - 'I' for input
 *                       - 'O' for output
 * @param PULL_SELECTION The pull-up/pull-down resistor configuration. It can be:
 *                       - 0 for pull-down resistor
 *                       - 1 for pull-up resistor
 * @param ENABLE_INTERRUPT The interrupt configuration for the pin. It can be:
 *                         - 0 to disable interrupts
 *                         - 1 for rising edge interrupt
 *                         - 2 for falling edge interrupt
 *                         - 3 for both edge interrupt
 * 
 * @note If the port or direction parameters are not valid, the function does nothing.
 * 
 * @warning This function assumes the presence of the appropriate hardware register definitions and may not work correctly
 *          if the hardware setup differs from the expected configuration.
 */
void set_up_port_pcr(char PORT, unsigned int PORT_SET_UP, char PORT_DIRECTION, unsigned int PULL_SELECTION, unsigned int ENABLE_INTERRUPT); 

/**
 * @brief Configures the pin control settings for UART ports.
 * 
 * This function sets up the pins and peripheral clock control for the specified UART channels.
 * It enables the clock for the selected UART channel, configures the corresponding port,
 * and sets the pin muxing to the appropriate UART function.
 * 
 * @param channel The UART channel to configure. It can be one of the following:
 *                - LUART_CHANNEL0 for UART channel 0
 *                - LUART_CHANNEL1 for UART channel 1
 *                - LUART_CHANNEL2 for UART channel 2
 * 
 * @note 
 * - This function calls `ENABLE_PCC_LUART` to enable the clock for the specified UART channel.
 * - It also calls `Enable_PCC_PORT` to enable the clock for the corresponding port.
 * - It sets the pin muxing for the UART transmit (TX) and receive (RX) pins.
 * 
 * @warning 
 * - The function does not include a `break` statement in each case, which means that it will fall through
 *   to the subsequent case statements. Make sure that this behavior is intentional or add `break` statements
 *   as needed to prevent undesired fall-through.
 * - The function assumes that the provided `channel` values and port configurations are correct and available.
 */
void set_up_port_uart(int channel); 
#endif /* PORT_H_*/