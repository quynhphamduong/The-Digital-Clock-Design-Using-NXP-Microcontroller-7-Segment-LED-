#ifndef EMB_MOCK_H_
#define EMB_MOCK_H_

/**************************************************************************************
 *                                USED LIBRARY
 **************************************************************************************/
#include "GPIO.h"
#include "LPIT.h"
#include "LPSPI.h"
#include "LPUART.h"
#include "PCC.h"
#include "PORT.h"
#include "SCG.h"
#include "SYSTEMTICK.h"
#include "INTERRUPT.h" 
#include "FTFC.h"
#include "UNIT_TEST.h"
#include <ctype.h>
#include <string.h>

/************************************************************************************************
 *                                 DEFINE VARIABLE
 ***********************************************************************************************/
/**
 * @file    color_and_button_pins.h
 * @brief   Defines for LED colors and button pins.
 */

/**
 * @def BLUE
 * @brief Defines the GPIO pin number for the blue LED.
 */
#define BLUE 0

/**
 * @def RED
 * @brief Defines the GPIO pin number for the red LED.
 */
#define RED 15

/**
 * @def GREEN
 * @brief Defines the GPIO pin number for the green LED.
 */
#define GREEN 16

/**
 * @def BUTTON_PIN1
 * @brief Defines the GPIO pin number for the SW2 button.
 */
#define BUTTON_PIN1 12

/**
 * @def BUTTON_PIN2
 * @brief Defines the GPIO pin number for the SW3 button.
 */
#define BUTTON_PIN2 13
/************************************************************************************************
 *                                 DEFINE FUNCTION
 ***********************************************************************************************/
/**
 * @brief Receives date and time data in normal and alarm modes from UART input.
 *
 * This function waits for the input of 23 characters via UART, storing them into
 * appropriate date, time, and time alarm variables based on the state indicated by
 * the '.' character. The input format is expected to be:
 * "YYYYMMDD.HHMMSS.HHMMSS", where the first '.' separates the date from the time,
 * and the second '.' separates the time from the time alarm.
 *
 * The function saves the date in `g_date[8]`, the time in `g_time[6]`, and the time 
 * alarm in `g_time_alarm[6]`. It assumes that the input data is valid and correctly
 * formatted.
 *
 * @param void No parameters.
 * @return void No return value.
 */
void receive_date_and_time_in_normal_and_alarm_mode(void); 

/**
 * @brief Increments the time stored in the `g_time` array by one second.
 *
 * This function increments the time stored in the global `g_time` array, which is 
 * assumed to be in the format "HHMMSS" (hours, minutes, seconds). The function 
 * handles the rollover of seconds, minutes, and hours, adjusting the array as needed.
 * If the time reaches "23:59:59" and rolls over, the function resets the time to "00:00:00" 
 * and calls `update_date()` to increment the date.
 *
 * @param void No parameters.
 * @return void No return value.
 */
void update_time(void); 

/**
 * @brief Sends the current time via UART in the format "HH:MM:SS".
 *
 * This function transmits the current time stored in the `g_time` array via UART. 
 * The time is sent in the format "HH:MM:SS", followed by a newline character. 
 * The global `g_time` array is expected to contain the time in "HHMMSS" format, 
 * and the function adds the necessary colons between hours, minutes, and seconds.
 *
 * @param void No parameters.
 * @return void No return value.
 */
void send_time_via_uart(void); 

/**
 * @brief Sends the current time via SPI in a specific format.
 *
 * This function transmits the current time stored in the `g_time` array via SPI. 
 * The time is sent in reverse order of "SS:MM:HH", with each digit transmitted separately.
 * Additionally, a delimiter (0x0A) is sent between the seconds, minutes, and hours.
 * The global `g_time` array is expected to contain the time in "HHMMSS" format, and the 
 * function subtracts the ASCII offset ('0') to transmit the numeric values.
 *
 * @param void No parameters.
 * @return void No return value.
 */
void send_time_via_spi(void);

/**
 * @brief Increments the date stored in the `g_date` array by one day.
 *
 * This function updates the date stored in the global `g_date` array, which is 
 * assumed to be in the format "DDMMYYYY" (day, month, year). It handles month-end 
 * transitions, including year-end, and adjusts for leap years when updating the date.
 *
 * The function first calculates the current day, month, and year from the `g_date` 
 * array, then determines if the date is the last day of the month. If so, it resets 
 * the day to 1 and increments the month. If the month exceeds 12, it resets the month 
 * to January (1) and increments the year. Otherwise, it simply increments the day.
 *
 * Leap years are taken into account by adjusting February's day count to 29 if 
 * the year is a leap year.
 *
 * @param void No parameters.
 * @return void No return value.
 */
void update_date(void); 

/**
 * @brief Sends the current date via UART in the format "DD-MM-YYYY".
 *
 * This function transmits the current date stored in the `g_date` array via UART.
 * The date is sent in the format "DD-MM-YYYY", followed by a newline character.
 * The global `g_date` array is expected to contain the date in "DDMMYYYY" format,
 * and the function adds the necessary hyphens between the day, month, and year components.
 *
 * @param void No parameters.
 * @return void No return value.
 */
void send_date_via_uart(void);

/**
 * @brief Sends the current date via SPI in reverse order.
 *
 * This function transmits the current date stored in the `g_date` array via SPI. 
 * The date is sent in reverse order as "YYYYMMDD", with each digit transmitted 
 * separately. The global `g_date` array is expected to contain the date in 
 * "DDMMYYYY" format, and the function subtracts the ASCII offset ('0') to 
 * transmit the numeric values.
 *
 * @param void No parameters.
 * @return void No return value.
 */
void send_date_via_spi(void);

/**
 * @brief Checks if the current time matches the alarm time.
 *
 * This function compares the current time stored in the `g_time` array with the alarm time 
 * stored in the `g_time_alarm` array. The comparison is done for the first 6 characters 
 * of the arrays, corresponding to the format "HHMMSS". If the times match, the function 
 * returns 1, indicating that the alarm should trigger. Otherwise, it returns 0.
 *
 * @return int Returns 1 if the current time matches the alarm time, otherwise returns 0.
 */
int check_alarm(void); 

/**
 * @brief Configures a 7-segment LED display via SPI.
 *
 * This function sets up a 7-segment LED display by sending the necessary configuration commands via SPI.
 * The commands configure the display for normal operation, enable decoding for all digits, turn on all digits,
 * and set the display intensity to full.
 *
 * The specific commands sent are as follows:
 * - 0x0C, 0x01: Set the display to normal operation mode.
 * - 0x09, 0xFF: Enable decoding for all digits.
 * - 0x0B, 0x07: Turn on all digits.
 * - 0x0A, 0x0F: Set the display intensity to full.
 *
 * @param void No parameters.
 * @return void No return value.
 */
void set_up_led_7_segment(void);  

/**
 * @brief Interrupt handler for LPIT Channel 2, handling time, date, and flash memory operations.
 *
 * This function serves as the interrupt handler for LPIT Channel 2. It performs the following operations:
 * 
 * - Clears the interrupt flag for Channel 2.
 * - Updates the current time using the `update_time()` function.
 * - Sends the updated date and time to the computer via UART using `send_date_via_uart()` and `send_time_via_uart()`.
 * - Clears any existing flash memory errors using `clear_error_flash()`.
 * - Configures the flash memory partition for subsequent operations using `program_partition()`.
 * - Sets the FlexRAM to emulate EEPROM using `set_flexram_to_emulated_eeprom()`.
 * - Saves the current date and time to flash memory using `write_date_to_flash(g_date)` and `write_time_to_flash(g_time)`.
 * - Clears the error flag again to ensure no errors persist.
 * - Reconfigures the flash partition and FlexRAM as needed.
 * - Saves the alarm time to flash memory using `write_time_alarm_to_flash(g_time_alarm)`.
 *
 * @param void No parameters.
 * @return void No return value.
 */
void LPIT0_Ch2_IRQHandler(void); 

/**
 * @brief Interrupt handler for PORTC, managing button presses and display states.
 *
 * This function serves as the interrupt handler for PORTC. It processes interrupts triggered by button presses
 * on PORTC and updates the display state accordingly. The function performs the following operations:
 *
 * - Checks if the interrupt source flag (IRQF) indicates that BUTTON_PIN1 has triggered an interrupt.
 *   If so, clears the interrupt flag and toggles the `g_display_select` state variable.
 *
 * - Checks if the interrupt source flag (IRQF) indicates that BUTTON_PIN2 has triggered an interrupt.
 *   If so, clears the interrupt flag and toggles the `g_display_enable` state variable.
 *
 * - If `g_display_enable` is set to 0 (disabled):
 *   - Turns off the 7-segment LED display by sending the shutdown command via SPI.
 *   - Updates the date and time data by calling `receive_date_and_time_in_normal_and_alarm_mode()`.
 *
 * @param void No parameters.
 * @return void No return value.
 */
void PORTC_IRQHandler(void);

/**
 * @brief Initializes and configures various peripherals and runs the main application loop.
 *
 * This function sets up and configures the following components:
 * 
 * - **Clock Configuration**:
 *   - SOSC: 8MHz, SOSCDIV1: Disabled, SOSCDIV2: 8MHz
 *   - SPLL: 80MHz, SPLLDIV1: Disabled, SPLLDIV2: 20MHz
 *   - RCCR: CORE_CLK: 80MHz, BUS_CLK: 40MHz, LOW_CLK: 26.67MHz
 * 
 * - **Port Configuration**:
 *   - Configures PORTC pins BUTTON_PIN1 and BUTTON_PIN2 as input with rising edge trigger and interrupt enabled.
 *   - Configures PORTD pin GREEN as output with no pull-up/pull-down resistors and no interrupt.
 * 
 * - **Interrupt Configuration**:
 *   - Initializes interrupts for PORTC and LPIT.
 * 
 * - **SPI Configuration**:
 *   - Enables SPI module and initializes it as master.
 * 
 * - **LPIT Configuration**:
 *   - Initializes LPIT with a 20-second timer interval.
 * 
 * - **UART Configuration**:
 *   - Sets up LPUART channel 1 with a baud rate of 9600 bps, 8-bit length, and 1 stop bit.
 * 
 * - **Flash Memory Operations**:
 *   - Clears error flags, programs flash partitions, sets FlexRAM to emulate EEPROM, and reads date, time, and alarm time from flash memory.
 * 
 * - **Main Application Loop**:
 *   - Continuously checks for alarm conditions and updates LED status.
 *   - Based on the display enable state, configures and sends data to a 7-segment LED display via SPI.
 * 
 * @param void No parameters.
 * @return void No return value.
 */
void emb_mock(void); 

/**
 * @brief Unit test for updating time and date functions.
 *
 * This function performs a unit test of the `update_time()` function by setting a predefined date and time,
 * calling `update_time()` to update the time, and then clearing the date and time variables. The function
 * is designed to validate the correctness of the time updating logic.
 *
 * - Sets the global date variable `g_date` to "31122000" (December 31, 2000).
 * - Sets the global time variable `g_time` to "235959" (23:59:59).
 * - Calls `update_time()` to update the time, simulating the transition from one second to the next.
 * - Clears the `g_date` and `g_time` variables by setting all characters to '0'.
 *
 * @param void No parameters.
 * @return void No return value.
 */
void ut_update_time_and_date(void);

/**
 * @brief Unit test for checking alarm functionality.
 *
 * This function performs a unit test of the `check_alarm()` function by setting predefined alarm and current
 * time values, calling `check_alarm()` to verify if the alarm condition is met, and then clearing the time
 * and alarm variables. The function is designed to validate the correctness of the alarm checking logic.
 *
 * - Sets the global alarm time variable `g_time_alarm` to "235959" (23:59:59).
 * - Sets the global current time variable `g_time` to "235959" (23:59:59).
 * - Calls `check_alarm()` to check if the current time matches the alarm time.
 * - Clears the `g_time` and `g_time_alarm` variables by setting all characters to '0' or '\0'.
 *
 * @param void No parameters.
 * @return void No return value.
 */
void ut_check_alarm(void); 

/**
 * @brief Unit test for writing to and reading from flash memory.
 *
 * This function performs a unit test to verify the correctness of writing to and reading from flash memory. 
 * It involves setting predefined date and time values, writing these values to flash, reading them back,
 * and then performing additional verification by swapping and writing the original values back. 
 * This function ensures the flash memory operations are functioning as expected.
 *
 * - Sets the global `ut_date` variable to "31122000" (December 31, 2000) and `ut_time` to "235959" (23:59:59).
 * - Clears any error flags in the flash module.
 * - Configures the flash memory partition and sets FlexRAM to emulated EEPROM.
 * - Reads the current date from flash memory into `g_date`, writes `ut_date` to flash.
 * - Clears error flags again, configures the flash partition, and sets FlexRAM.
 * - Reads the current time from flash memory into `g_time`, writes `ut_time` to flash.
 * - Clears error flags, configures the flash partition, and sets FlexRAM.
 * - Reads the date and time back from flash memory into `ut_date` and `ut_time`, respectively.
 * - Writes the original date and time values (`g_date` and `g_time`) back to flash.
 *
 * @param void No parameters.
 * @return void No return value.
 */
void ut_write_read_with_flash(void);
#endif