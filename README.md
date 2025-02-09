# The Digital Clock Design Using NXP Microcontroller, 7 Segment LED, Setting Time And Alarm Through GUI App ⏰💻

## Project Overview

- This document provides details descriptions about the The Digital Clock that our group creates and sets in the program.
- For understanding what we did and how to run the program, please check the section "Running the program"
- For architecture and detail design of the clock : [Architecture and Detail design.pdf](https://github.com/quynhphamduong/The-Digital-Clock-Design-Using-NXP-Microcontroller-7-Segment-LED-/blob/cdbe5cfcbc72dcd61f888e2d0aa1bb24a655f53d/Architecture%20and%20Detail%20design.pdf)


## Hardware
- NXP Microcontroller : S32K EVB - An Automotive Microcontroller
- 7 Segment LED : 74HC595

## Tools
- Keil uVision
- Visual Studio Code

## Library Contributors
- Tran Quang Nguyen Anh: FTFC (Flash), LPSPI, Unit test, Main
- Pham Duong Quynh : GPIO, LPUART, SCG, SYSTEM_TICK, PCC, INTERRUPT, Main

## Running the Program

1. **Start the Program:**
   - Once the program is flashed onto the board, it will begin execution immediately. The main loop will handle time and date updates, manage display settings, and check alarms.

2. **Interact with the Program:**
   Ater power on, the clock will display the time: 00-00-00 (date: 00.00.0000)
   - **Buttons:**
     - **BUTTON_PIN1 (PTC12):** Switches between time and date display modes.
     - **BUTTON_PIN2 (PTC13):** Toggles the display on and off.
   - **Display:**
     - When enabled, the 7-segment display will show either the current time or date based on the selected mode.
     - When disabled, the program allow you to set the new date and time for calculation and display. Furthermore alarm mode set also is enabled here. You can set alarm time for board (Display by GREEN LED in 1 second). Furthermore, you can also set the program display the real time through GUI app. 

   - **UART and SPI Outputs:**
     - The program sends the current time and date via UART and SPI.

## Note

   - You have to set up all data you have before push apply button on GUI 
   - With the unit test, you want to run unit test, you have to convert function emb_mock() in main.c file to comment and calls fucntions that we have revealed in test report excel. If no or call functions in UNIT_TEST.h, they can break the program. 
   
## License
   - Due to confidentiality constraints, the supporting libraries are not included in this repository. If you need access, please send me an email with the following details:

      **Subject**: Request for Embedded Project Libraries

      **Your Name & Affiliation**

      **Reason for Request** (e.g., Personal Learning, Research, Company Project)

      **Intended Use and Duration**

📩 Contact: [quynh.phamduong2003@gmail.com]

Confirmation that the libraries will not be redistributed
Access to libraries will be granted on a case-by-case basis to avoid misuse.
   
