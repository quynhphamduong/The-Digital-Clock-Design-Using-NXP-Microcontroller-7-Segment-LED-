#ifndef LPUART_H_
#define LPUART_H_

#include <stdint.h>
#include "PCC.h"

#define ENABLE 1 
#define DISABLE 0 

#define STOP_BIT_2 1
#define STOP_BIT_1 0 

enum DATALENGTH
{   
    DATA_LENGTH7 = 7, 
    DATA_LENGTH8, 
    DATA_LENGTH9,
    DATA_LENGTH10,
}; 

enum BAUD_BIT 
{
    SBR = 0,                                /*Baud Rate Modulo Divisor*/
    SBNS = 13,                              /*Stop Bit Number Select*/
    RXEDGIE,                                /*RX Input Active Edge Interrupt Enable*/
    LBKDIE,                                 /*RX Input Active Edge Interrupt Enable*/
    RESYNCDIS,                              /*Resynchronization Disable*/
    BOTHEDGE,                               /*Both Edge Sampling*/
    MATCFG,                                 /*Match Configuration*/
    RIDMAE = 20,                            /*Receiver Idle DMA Enable*/
    RDMAE =21,                              /*Receiver Full DMA Enable*/
    TDMAE = 23,                             /*Transmitter DMA Enable*/
    OSR = 24,                               /*Oversampling Ratio*/
    M10 = 29,                               /*10-bit Mode select*/
    MAEN2 = 30,                             /*Match Address Mode Enable 2*/
    MAEN1 = 31                              /*Match Address Mode Enable 1*/
}; 

enum STAT_BIT
{
    MA2F = 14,                              /*Match 2 Flag*/            
    MA1F,                                   /*Match 1 Flag*/
    PF,                                     /*Parity Error Flag*/
    FE,                                     /*Framing Error Flag*/
    NF,                                     /*Noise Flag*/
    OR,                                     /*Receiver Overrun Flag*/
    IDLE,                                   /*Idle Line Flag*/
    RDRF,                                   /*Receive Data Register Full Flag*/
    TC,                                     /*Transmission Complete Flag*/
    TDRE,                                   /*Transmit Data Register Empty Flag*/
    RAF,                                    /*Receiver Active Flag*/
    LBKDE_STAT,                             /*LIN Break Detection Enable*/
    BRK13,                                  /*Receive Wake Up Idle Detect*/
    RWUID_STAT,                             /*Receive Wake Up Idle Detect*/
    RXINV,                                  /*Receive Data Inversion*/
    MSBF,                                   /*MSB First*/
    RXEDGIF,                                /*RXD Pin Active Edge Interrupt Flag*/
    LBKDIF                                  /*LIN Break Detect Interrupt Flag*/
};                  

enum CTRL_BIT
{
    PT = 0,                                 /*Parity type*/
    PE_LPUART,                              /*Parity enable*/
    ILT,                                    /*Idle line type select*/
    WAKE,                                   /*Reciever wakeup method select */
    M,                                      /*9-bit or 8-bit mode select*/
    RSRC,                                   /*Reciever source select*/
    DOZEEN,                                 /*Doze enable*/
    LOOPS,                                  /*Loop mode select*/
    IDLECFG,                                /*IDLE configuration */
    M7 = 11,                                /*7-bit mode select*/
    MA2IE = 14,                             /*Match 2 interrut enable*/
    MA1IE,                                  /*Match 1 interrut enable*/
    SBK,                                    /*Send break*/
    RWU,                                    /*Reciever wakeu control*/
    RE,                                     /*Reciever enable*/
    TE,                                     /*Transmitter enable*/
    ILIE,                                   /*IDLE line interrut enable*/
    RIE,                                    /*Reciever interrut enable*/ 
    TCIE,                                   /*Tranmission complete interrupt enable*/
    TIE,                                    /*Transmit Interrupt Enable*/
    PEIE,                                   /*Parity Error Interrupt Enable*/
    FEIE,                                   /*Framing Error Interrupt Enable*/
    NEIE,                                   /*Noise Error Interrupt Enable*/
    ORIE,                                   /*Overrun Interrupt Enable*/
    TXINV,                                  /*Transmit Data Inversion*/
    TXDIR,                                  /*TXD Pin Direction in Single-Wire Mode*/
    R9T8,                                   /*Receive Bit 9 / Transmit Bit 8*/
    R8T9                                    /*Receive Bit 8 / Transmit Bit 9*/
}; 

enum DATA_BIT
{
    R0T0_DATA = 0,                          /*Read receive data buffer 0 or write transmit data buffer 0.*/
    R1T1_DATA,                              /*Read receive data buffer 1 or write transmit data buffer 1.*/
    R2T2_DATA,                              /*Read receive data buffer 2 or write transmit data buffer 2*/
    R3T3_DATA,                              /*Read receive data buffer 3 or write transmit data buffer 3.*/
    R4T4_DATA,                              /*Read receive data buffer 4 or write transmit data buffer 4*/
    R5T5_DATA,                              /*Read receive data buffer 5 or write transmit data buffer 5*/
    R6T6_DATA,                              /*Read receive data buffer 6 or write transmit data buffer 6*/
    R7T7_DATA,                              /*Read receive data buffer 7 or write transmit data buffer 7.*/
    R8T8_DATA,                              /*Read receive data buffer 8 or write transmit data buffer 8.*/
    R9T9_DATA,                              /*Read receive data buffer 9 or write transmit data buffer 9.*/
    IDLINE_DATA = 11,                       /*Idle Line*/
    RXEMPT_DATA,                            /*Receive Buffer Empty*/
    FRETSC_DATA,                            /*Frame Error / Transmit Special Character*/
    PARATYE_DATA,                           /*The current received dataword contained in DATA[R9:R0] was received with noise*/
    NOISY_DATA                              /*The current received dataword contained in DATA[R9:R0] was received with noise*/
};

enum MATCH_BIT
{
    MA1_MATCH = 0,                          /*Match Address 1*/
    MA2_MATCH = 16                          /*Match Address 2*/
};

enum MODIR_BIT
{
    TXCTSE_MATCH = 0,                       /*Transmitter clear-to-send enable*/
    TXRTSE_MATCH,                           /*Transmitter request-to-send enable*/
    TXRTSPOL_MATCH,                         /*Transmitter request-to-send polarity*/
    RXRTSE_MATCH,                           /*Receiver request-to-send enable*/
    TXCTSC_MATCH,                           /*Transmit CTS Configuration*/
    TXCTSSRC_MATCH,                         /*Transmit CTS Source*/
    RTSWATER_MATCH = 8,                     /*Receive RTS Configuration*/
    TNP_MATCH = 16,                         /*Transmitter narrow pulse*/
    IREN_MATCH                              /*Infrared enable*/
};

enum FIFO_BIT
{
    RXFIFOSIZE = 0,                         /*Receive FIFO Buffer Depth*/
    RXFE_FIFO = 3,                          /*Receive FIFO Enable*/
    TXFIFOSIZE,                             /*Transmit FIFO Buffer Depth*/
    TXFE_FIFO = 7,                          /*Transmit FIFO Enable*/
    RXUFE_FIFO,                             /*Receive FIFO Underflow Interrupt Enable*/
    TXOFE_FIFO,                             /*Transmit FIFO Overflow Interrupt Enable*/
    RXIDEN_FIFO,                            /*Receiver Idle Empty Enable*/
    RXFLUSH_FIFO = 14,                      /*Receive FIFO/Buffer Flush*/
    TXFLUSH_FIFO,                           /*Transmit FIFO/Buffer Flush*/
    RXUF_FIFO,                              /*Receiver Buffer Underflow Flag*/
    TXOF_FIFO,                              /*Transmitter Buffer Overflow Flag*/
    RXEMPT_FIFO = 22,                       /*Receive Buffer/FIFO Empty*/
    TXEMPT_FIFO,                            /*Transmit Buffer/FIFO Empty*/

};

enum WATER_BIT
{
    TXWATER = 0,                            /*Transmit Watermark*/
    TXCOUNT_WATER = 8,                      /*Transmit Counter*/
    RXWATER = 16,                           /*Receive Watermark*/
    RXCOUNT_WATER =24                       /*Receive Counter*/
};

typedef struct 
{
    /*Version ID Register */
    volatile uint32_t   VERID; 

    /*Parameter Register */
    volatile uint32_t   PARAM; 

    /*LPUART Global Register */
    volatile uint32_t   GLOBAL;

    /*LPUART Pin Configuration Register */
    volatile uint32_t   PINCFG;

    /*LPUART Baud Rate Registe */
    volatile uint32_t   BAUD;
    
    /*LPUART Status Register*/
    volatile uint32_t   STAT;

    /*LPUART Control Register */
    volatile uint32_t   CTRL;

    /*LPUART Data Register */
    volatile uint32_t   DATA;

    /*LPUART Match Address Register */
    volatile uint32_t   MATCH;
    
    /*LPUART Modem IrDA Register*/
    volatile uint32_t   MODIR;

    /*LPUART FIFO Register*/
    volatile uint32_t   FIFO;

    /*LPUART FIFO Register*/
    volatile uint32_t   WATER;
}LPUART_TYPE ;

#define LPUART0_BASE_ADDR   (0x4006A000)
#define LPUART0             ((LPUART_TYPE*) LPUART0_BASE_ADDR)

#define LPUART1_BASE_ADDR   (0x4006B000)
#define LPUART1             ((LPUART_TYPE*) LPUART1_BASE_ADDR)

#define LPUART2_BASE_ADDR   (0x4006C000)
#define LPUART2             ((LPUART_TYPE*) LPUART2_BASE_ADDR)

/**
 * @brief Sets the baud rate for the specified LPUART channel.
 * 
 * This function configures the baud rate of the specified LPUART channel. The baud rate is calculated based on the provided frequency
 * and a fixed divisor of 16 with a default baud rate of 9600 bps. The function updates the Baud Rate Register (BAUD) of the LPUART
 * module with the calculated value.
 * 
 * @param channel The LPUART channel to configure. This should be one of the predefined LPUART channel constants:
 *        - `LUART_CHANNEL0`
 *        - `LUART_CHANNEL1`
 *        - `LUART_CHANNEL2`
 * 
 * @param frequency The clock frequency used for calculating the baud rate. This value is used to compute the Serial Baud Rate (SBR) value.
 * 
 * @note The function performs the following actions:
 *       - Calculates the SBR value using the formula: `SBR_value = frequency / (16 * 9600)`.
 *       - Configures the Over Sampling Ratio (OSR) to 15.
 *       - Sets the SBR value in the Baud Rate Register (BAUD) for the selected LPUART channel.
 * 
 * @see LUART_CHANNEL0
 * @see LUART_CHANNEL1
 * @see LUART_CHANNEL2
 * @see LPUART
 */
void set_baudrate(int channel,long unsigned int frequency); 

/**
 * @brief Configures the frame settings for the specified LPUART channel.
 * 
 * This function sets up the frame format for the specified LPUART channel, including stop bits, data length, and parity settings.
 * 
 * @param channel The LPUART channel to configure. This should be one of the predefined LPUART channel constants:
 *        - `LUART_CHANNEL0`
 *        - `LUART_CHANNEL1`
 *        - `LUART_CHANNEL2`
 * 
 * @param STOP_BIT Specifies the number of stop bits:
 *        - Non-zero value to enable 2 stop bits.
 *        - Zero value to enable 1 stop bit.
 * 
 * @param DATA_LENGTH_TRANSFER Specifies the data length for the transfer:
 *        - `DATA_LENGTH7` for 7-bit data length.
 *        - `DATA_LENGTH8` for 8-bit data length.
 * 
 * @param PARITY_BIT Specifies the parity setting:
 *        - Non-zero value to enable parity (not implemented in this function).
 *        - Zero value to disable parity.
 * 
 * @note The function performs the following actions:
 *       - Configures the stop bit setting in the Baud Rate Register (BAUD).
 *       - Configures the data length in the Control Register (CTRL).
 *       - Disables parity in the Control Register (CTRL).
 * 
 * @see LUART_CHANNEL0
 * @see LUART_CHANNEL1
 * @see LUART_CHANNEL2
 * @see LPUART
 */
void set_frame(int channel, int STOP_BIT, int DATA_LENGTH_TRANSFER, int PARITY_BIT);

/**
 * @brief Enables or disables the transmitter and/or receiver for the specified LPUART channel.
 * 
 * This function controls the transmitter and receiver functions of the LPUART channels. It allows enabling or disabling
 * the transmitter and receiver independently based on the specified parameters.
 * 
 * @param channel The LPUART channel to configure. This should be one of the predefined LPUART channel constants:
 *        - `LUART_CHANNEL0`
 *        - `LUART_CHANNEL1`
 *        - `LUART_CHANNEL2`
 * 
 * @param ENABLE_TRANSMIT Indicates whether to enable or disable the transmitter:
 *        - `ENABLE` to enable the transmitter.
 *        - Any other value to disable the transmitter.
 * 
 * @param ENABLE_RECIEVER Indicates whether to enable or disable the receiver:
 *        - `ENABLE` to enable the receiver.
 *        - Any other value to disable the receiver.
 * 
 * @note The function performs the following actions:
 *       - Sets or clears the `TE` bit in the Control Register (CTRL) to enable or disable the transmitter.
 *       - Sets or clears the `RE` bit in the Control Register (CTRL) to enable or disable the receiver.
 * 
 * @see LUART_CHANNEL0
 * @see LUART_CHANNEL1
 * @see LUART_CHANNEL2
 * @see LPUART
 */
void enable_transmitter_or_receiver(int channel, int ENABLE_TRANSMIT, int ENABLE_RECIEVER); 

/**
 * @brief Sends a character over the LPUART1.
 * 
 * This function waits until the transmit data register is empty and then sends a single character through
 * the LPUART1 module. It blocks until the transmit data register is ready to accept new data.
 * 
 * @param data The character to be sent over the LPUART1.
 * 
 * @note This function checks the `TDRE` (Transmit Data Register Empty) flag in the status register to determine
 *       if the transmit data register is ready. It uses polling to wait until the `TDRE` flag is set before
 *       writing the data to the `DATA` register.
 */
void send_char(char data); 

/**
 * @brief Receives a character from LPUART1.
 * 
 * This function waits until the receive data register is full and then reads a single character from
 * the LPUART1 module. It blocks until the receive data register contains valid data.
 * 
 * @param data Pointer to a variable where the received character will be stored.
 * 
 * @note This function checks the `RDRF` (Receive Data Register Full) flag in the status register to determine
 *       if the receive data register contains valid data. It uses polling to wait until the `RDRF` flag is set
 *       before reading the data from the `DATA` register and storing it in the location pointed to by `data`.
 */
void receive_char(char *data);

/**
 * @brief Sends a string of characters over LPUART1.
 * 
 * This function sends each character of the provided string to the LPUART1 module one by one.
 * It uses the `send_char` function to transmit each character and continues until the null terminator
 * of the string is encountered.
 * 
 * @param data_string Array of characters (string) to be sent.
 * 
 * @note This function sends characters sequentially by calling `send_char` for each character in the
 *       `data_string`. It continues to send characters until the null terminator (`'\0'`) is reached,
 *       which signifies the end of the string.
 */
void send_string(char data_string[]); 


void receive_string_uart(char data_string[]);
#endif