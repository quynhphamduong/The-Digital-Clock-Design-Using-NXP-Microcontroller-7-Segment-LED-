#ifndef PCC_H_
#define PCC_H_

#include <stdint.h>

enum PCC_BIT
{
    PCS_PCC = 24,
    CGC = 30
};

/**
 * @brief Mask to enable a specific port in the PCC_PORT register.
 * 
 * This macro defines the bit mask to set bit 30 of the PCC_PORT register, enabling a specific port.
 */
#define ENABLE_PCC_PORT_MASK  (1u << 30u) // Set bit 30 of PCC_PORT register 

/**
 * @brief Mask to enable the LPIT module in the PCC_LPIT register.
 * 
 * This macro defines the bit mask to set bit 30 of the PCC_LPIT register, enabling the LPIT module.
 */
#define ENABLE_PCC_LPIT_MASK  (1u << 30u) // Set bit 30 of PCC_LPIT register

/**
 * @brief Mask to enable the LPUART module in the PCC_LPUART register.
 * 
 * This macro defines the bit mask to set bit 30 of the PCC_LPUART register, enabling the LPUART module.
 */
#define ENABLE_PCC_LUART_MASK (1u << 30u) // Set bit 30 of PCC_LPUART register

/**
 * @brief Channel identifier for LPUART channel 0.
 * 
 * This macro defines the channel identifier for the first LPUART channel.
 */
#define LUART_CHANNEL0        (0u)

/**
 * @brief Channel identifier for LPUART channel 1.
 * 
 * This macro defines the channel identifier for the second LPUART channel.
 */
#define LUART_CHANNEL1        (1u)

/**
 * @brief Channel identifier for LPUART channel 2.
 * 
 * This macro defines the channel identifier for the third LPUART channel.
 */
#define LUART_CHANNEL2        (2u)

typedef struct 
{
    volatile uint32_t PCC_FTFC;       // 0x80 PCC FTFC Register
    volatile uint32_t PCC_DMAMUX;     // 0x84 PCC DMAMUX Register
    volatile uint32_t RESERVED_0[2];  // 0x88, 0x8C Reserved
    volatile uint32_t PCC_FlexCAN0;   // 0x90 PCC FlexCAN0 Register
    volatile uint32_t PCC_FlexCAN1;   // 0x94 PCC FlexCAN1 Register
    volatile uint32_t PCC_FTM3;       // 0x98 PCC FTM3 Register
    volatile uint32_t PCC_ADC1;       // 0x9C PCC ADC1 Register
    volatile uint32_t RESERVED_1[3];  // 0xA0 0xA4 0xA8 Reserved
    volatile uint32_t PCC_FlexCAN2;   // 0xAC PCC FlexCAN2 Register
    volatile uint32_t PCC_LPSPI0;     // 0xB0 PCC LPSPI0 Register
    volatile uint32_t PCC_LPSPI1;     // 0xB4 PCC LPSPI1 Register
    volatile uint32_t PCC_LPSPI2;     // 0xB8 PCC LPSPI2 Register
    volatile uint32_t RESERVED_2[2];  // 0xBC 0xC0 Reserved
    volatile uint32_t PCC_PDB1;       // 0xC4 PCC PDB1 Register
    volatile uint32_t PCC_CRC;        // 0xC8 PCC CRC Register
    volatile uint32_t RESERVED_3[3];  // 0xCC, 0xD0 0xD4 Reserved
    volatile uint32_t PCC_PDB0;       // 0xD8 PCC PDB0 Register
    volatile uint32_t PCC_LPIT;       // 0xDC PCC LPIT Register
    volatile uint32_t PCC_FTM0;       // 0xE0 PCC FTM0 Register
    volatile uint32_t PCC_FTM1;       // 0xE4 PCC FTM1 Register
    volatile uint32_t PCC_FTM2;       // 0xE8 PCC FTM2 Register
    volatile uint32_t PCC_ADC0;       // 0xEC PCC ADC0 Register
    volatile uint32_t RESERVED_4[1];  // 0xF0 Reserved
    volatile uint32_t PCC_RTC;        // 0xF4 PCC RTC Register
    volatile uint32_t RESERVED_5[2];  // 0xF8, 0xFC Reserved
    volatile uint32_t PCC_LPTMR0;     // 0x100 PCC LPTMR0 Register
    volatile uint32_t RESERVED_6[8];  // 0x104 - 0x120 Reserved
    volatile uint32_t PCC_PORTA;      // 0x124 PCC PORTA Register
    volatile uint32_t PCC_PORTB;      // 0x128 PCC PORTB Register
    volatile uint32_t PCC_PORTC;      // 0x12C PCC PORTC Register
    volatile uint32_t PCC_PORTD;      // 0x130 PCC PORTD Register
    volatile uint32_t PCC_PORTE;      // 0x134 PCC PORTE Register
    volatile uint32_t RESERVED_7[6];  // 0x138 - 0x14C Reserved
    volatile uint32_t PCC_SAI0;       // 0x150 PCC SAI0 Register
    volatile uint32_t PCC_SAI1;       // 0x154 PCC SAI1 Register
    volatile uint32_t RESERVED_8[4];  // 0x158 - 0x164 Reserved
    volatile uint32_t PCC_FlexIO;     // 0x168 PCC FlexIO Register
    volatile uint32_t RESERVED_9[6];  // 0x16C - 0x180 Reserved
    volatile uint32_t PCC_EWM;        // 0x184 PCC EWM Register
    volatile uint32_t RESERVED_10[4]; // 0x188 - 0x194 Reserved
    volatile uint32_t PCC_LPI2C0;     // 0x198 PCC LPI2C0 Register
    volatile uint32_t PCC_LPI2C1;     // 0x19C PCC LPI2C1 Register
    volatile uint32_t RESERVED_11[2]; // 0x1A0, 0x1A4 Reserved
    volatile uint32_t PCC_LPUART0;    // 0x1A8 PCC LPUART0 Register
    volatile uint32_t PCC_LPUART1;    // 0x1AC PCC LPUART1 Register
    volatile uint32_t PCC_LPUART2;    // 0x1B0 PCC LPUART2 Register
    volatile uint32_t RESERVED_12[1]; // 0x1B4 Reserved
    volatile uint32_t PCC_FTM4;       // 0x1B8 PCC FTM4 Register
    volatile uint32_t PCC_FTM5;       // 0x1BC PCC FTM5 Register
    volatile uint32_t PCC_FTM6;       // 0x1C0 PCC FTM6 Register
    volatile uint32_t PCC_FTM7;       // 0x1C4 PCC FTM7 Register
    volatile uint32_t RESERVED_13[1]; // 0x1C8 Reserved
    volatile uint32_t PCC_CMP0;       // 0x1CC PCC CMP0 Register
    volatile uint32_t RESERVED_14[2]; // 0x1D0, 0x1D4 Reserved
    volatile uint32_t PCC_QSPI;       // 0x1D8 PCC QSPI Register
    volatile uint32_t RESERVED_15[2]; // 0x1DC, 0x1E0 Reserved
    volatile uint32_t PCC_ENET;       // 0x1E4 PCC ENET Register
} PCCn;

#define PCC_BASE  (0x40065080u) // PCC addess base 
#define PCC ((PCCn*) PCC_BASE) 

/**
 * @brief Enables a specific port in the PCC_PORT register.
 * 
 * This function sets the bit mask defined by `ENABLE_PCC_PORT_MASK` to enable a particular port in the
 * PCC_PORT register based on the provided port identifier.
 * 
 * @param Enable_PORT A character representing the port to be enabled. It can be:
 *                    - 'A': Enable port A
 *                    - 'B': Enable port B
 *                    - 'C': Enable port C
 *                    - 'D': Enable port D
 *                    - 'E': Enable port E
 * 
 * If the provided port identifier does not match any of the valid options, the function does nothing.
 */
void enable_PCC_PORT(char Enable_PORT); 

/**
 * @brief Enables the LPIT module in the PCC_LPIT register.
 * 
 * This function sets the bit mask defined by `ENABLE_PCC_LPIT_MASK` to enable the LPIT (Low Power Interrupt Timer) module 
 * in the PCC_LPIT register and configures the clock source for the LPIT module.
 * 
 * Specifically, this function:
 * - Sets bit 30 of the PCC_LPIT register to enable the LPIT module.
 * - Configures the clock source for the LPIT module using a predefined value (6u) for the `PCS_PCC` field.
 */
void enable_PCC_LPIT(void);

/**
 * @brief Enables the LUART module in the PCC register for a specified channel.
 * 
 * This function sets the bit mask defined by `ENABLE_PCC_LUART_MASK` to enable the LUART (Low Power UART) module 
 * in the appropriate PCC_LPUART register based on the specified channel. It also configures the clock source 
 * for the LUART module using the provided `CLOCK_SOURCE` value.
 * 
 * @param channel The LUART channel to be enabled. Possible values are:
 *                - `LUART_CHANNEL0`: Enable LUART channel 0.
 *                - `LUART_CHANNEL1`: Enable LUART channel 1.
 *                - `LUART_CHANNEL2`: Enable LUART channel 2.
 * 
 * @param CLOCK_SOURCE The clock source to be configured for the LUART module. The value is shifted into the `PCS_PCC` field.
 * 
 * @note The function does not perform validation of the `channel` or `CLOCK_SOURCE` parameters. Ensure that the provided
 *       values are valid and correctly configured for your application.
 */
void enable_PCC_LUART(int channel,unsigned int CLOCK_SOURCE); 

#endif /* PCC_H_*/