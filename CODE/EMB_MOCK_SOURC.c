#include "EMB_MOCK.h"
/**
 * @file    globals.h
 * @brief   Global variables for time, date, and display settings.
 */

/**
 * @var char g_time[6]
 * @brief Global variable to store the current time.
 * 
 * The array is initialized with the value {'0','0','0','0','0','0','0','0'}. 
 * The array is expected to hold time in the format HHMMSS, where HH,MM and SS are
 * three-digit representations of hours,minutes and seconds respectively.
 */
char g_time[6] = {'0','0','0','0','0','0'}; 

/**
 * @var char g_date[8]
 * @brief Global variable to store the current date.
 * 
 * The array is initialized with the value {'0','0','0','0','0','0','0','0'}. 
 * The format is DDMMYYYY, where DD is the day, MM is the month, and YYYY is the year.
 */
char g_date[8] = {'0','0','0','0','0','0','0','0'}; 

/**
 * @var char g_time_alarm[6]
 * @brief Global variable to store the alarm time.
 * 
 * The array is expected to hold time in the format HHMMSS , where HH,MM and SS are
 * three-digit representations of hours,minutes and seconds respectively.
 */
char g_time_alarm[6]; 

/**
 * @var int g_display_enable
 * @brief Global variable to enable or disable the display.
 * 
 * - 0: Off
 * - 1: On
 */
int g_display_enable = 0;

/**
 * @var int g_display_select
 * @brief Global variable to select between time and date display.
 * 
 * - 0: Display time
 * - 1: Display date
 */
int g_display_select = 0; /*0: Time, 1: Date */

/************************************************************************************************
 *                                 EXECUTE FUNCTION
 ***********************************************************************************************/
void receive_date_and_time_in_normal_and_alarm_mode(void)
{
    char string[23];
    int index = 0;
    int state = 0;  // 0: Date, 1: Time, 2: Time Alarm

    /*Clear string buffer*/
    memset(string, '\0', sizeof(string));

    /*Receive characters until the buffer is full or a newline is encountered*/
    while (index < 23 )
    {
        receive_char(&string[index]);
			
        if (string[index] == '.')
        {
            /*Move to the next state when '.' is encountered*/
            state += 1;
            index += 1;
            continue;
        }

        /*Save corresponding data to corresponding variables */
        if (state == 0 && index < 8)
        {
            g_date[index] = string[index];
        }
        else if (state == 1 && index < 15)
        {
            g_time[index - 9] = string[index];
        }
        else if (state == 2 && index < 22)
        {
            g_time_alarm[index - 16] = string[index];
        }

        index += 1;
    }
}


void update_time(void)
{
    // Increment seconds
    g_time[5] += 1;
    if (g_time[5] > '9') 
    {
        g_time[5] = '0';
        g_time[4] += 1;
    }

    // Increment tens of seconds
    if (g_time[4] > '5') 
    {
        g_time[4] = '0';
        g_time[3] += 1;
    }

    // Increment minutes
    if (g_time[3] > '9') 
    {
        g_time[3] = '0';
        g_time[2] += 1;
    }

    // Increment tens of minutes
    if (g_time[2] > '5') 
    {
        g_time[2] = '0';
        g_time[1] += 1;
    }

    // Increment hours
    if (g_time[1] > '9') 
    {
        g_time[1] = '0';
        g_time[0] += 1;
    }

    // Increment tens of hours
    if ((g_time[0] == '2') && (g_time[1] > '3')) 
    {
        g_time[0] = '0';
        g_time[1] = '0';

        update_date(); 
    }
}

void send_time_via_uart(void)
{
    send_char(g_time[0]); 
    send_char(g_time[1]); 
    send_char(':'); 
    send_char(g_time[2]); 
    send_char(g_time[3]); 
    send_char(':');
    send_char(g_time[4]); 
    send_char(g_time[5]); 
    send_char('\n');
}

void send_time_via_spi(void)
{
    spi_transmit(CHANNEL1_SPI,0x01, g_time[5] - '0');
	spi_transmit(CHANNEL1_SPI,0x02, g_time[4] - '0');
	spi_transmit(CHANNEL1_SPI,0x03,0x0A);
	spi_transmit(CHANNEL1_SPI,0x04, g_time[3] - '0');
	spi_transmit(CHANNEL1_SPI,0x05, g_time[2] - '0');
	spi_transmit(CHANNEL1_SPI,0x06,0x0A);
	spi_transmit(CHANNEL1_SPI,0x07, g_time[1] - '0');
	spi_transmit(CHANNEL1_SPI,0x08, g_time[0] - '0');
}

void update_date(void)
{
    /*Assume g_date is in DDMMYYYY format*/ 
    int day = (g_date[0] - '0') * 10 + (g_date[1] - '0');
    int month = (g_date[2] - '0') * 10 + (g_date[3] - '0');
    int year = (g_date[4] - '0') * 1000 + (g_date[5] - '0') * 100 + (g_date[6] - '0') * 10 + (g_date[7] - '0');

    /*Number of days in each month*/ 
    int days_in_months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /*Check for leap year*/
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        days_in_months[1] = 29; // February has 29 days in a leap year
    }

    /*Check if the date is the last day of the month*/
    if (day == days_in_months[month - 1]) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    } else {
        day++;
    }

    /*Update the date values*/
    g_date[0] = (day / 10) + '0';
    g_date[1] = (day % 10) + '0';
    g_date[2] = (month / 10) + '0';
    g_date[3] = (month % 10) + '0';
    g_date[4] = (year / 1000) + '0';
    g_date[5] = ((year % 1000) / 100) + '0';
    g_date[6] = ((year % 100) / 10) + '0';
    g_date[7] = (year % 10) + '0';
}

void send_date_via_uart(void)
{
    send_char(g_date[0]); 
    send_char(g_date[1]); 
    send_char('-');
    send_char(g_date[2]); 
    send_char(g_date[3]); 
    send_char('-');
    send_char(g_date[4]); 
    send_char(g_date[5]); 
    send_char(g_date[6]); 
    send_char(g_date[7]); 
    send_char('\n');
}

void send_date_via_spi(void)
{
    spi_transmit(CHANNEL1_SPI,0x01, g_date[7] - '0');
	spi_transmit(CHANNEL1_SPI,0x02, g_date[6] - '0');
	spi_transmit(CHANNEL1_SPI,0x03, g_date[5] - '0');
	spi_transmit(CHANNEL1_SPI,0x04, g_date[4] - '0');
	spi_transmit(CHANNEL1_SPI,0x05, g_date[3] - '0');
	spi_transmit(CHANNEL1_SPI,0x06, g_date[2] - '0');
	spi_transmit(CHANNEL1_SPI,0x07, g_date[1] - '0');
	spi_transmit(CHANNEL1_SPI,0x08, g_date[0] - '0');
}

int check_alarm(void)
{
    /* Check if the current time matches the alarm time */
    int is_time_match = strncmp(g_time, g_time_alarm, 6) == 0;
    
    /* Return 1 if both date and time match, otherwise return 0 */
    return is_time_match;
}

void set_up_led_7_segment(void)
{
    /*Send command to 7-led segment*/
	spi_transmit(CHANNEL1_SPI,0x0C,0x01);   /*Normal operation*/
	spi_transmit(CHANNEL1_SPI,0x09,0xFF);   /*Decode all digits*/
	spi_transmit(CHANNEL1_SPI,0x0B,0x07);   /*All digits on */
	spi_transmit(CHANNEL1_SPI,0x0A,0x0F);   /*Full intensity*/
}

void LPIT0_Ch2_IRQHandler(void)
{
    /*Clear flag*/
    (*LPIT).MSR |= (1u << CHANNEL_2);

    /*Process time and date data */
    update_time(); 

    /*Send to computer*/
    send_date_via_uart(); 
    send_time_via_uart(); 

    /*Clear error flag*/
	clear_error_flash();

    /*Set up flash part that will be accessed*/
	program_partition(); 

    /*Set flexRam to emulated eeprom*/
    set_flexram_to_emulated_eeprom();
				
    /*Save time and date to flash*/
	write_date_to_flash(g_date);
	write_time_to_flash(g_time); 

   /*Clear error flag*/
	clear_error_flash();

    /*Set up flash part that will be accessed*/
	program_partition(); 

    /*Set flexRam to emulated eeprom*/
    set_flexram_to_emulated_eeprom();

    /*Save alarm time to flash*/
    write_time_alarm_to_flash(g_time_alarm);
}

void PORTC_IRQHandler(void)
{
    /* check IRQF*/
    if ((*PORTC).PORT_ISFR & (1u << BUTTON_PIN1))
    {
        /* CLear flag */ 
		(*PORTC).PORT_ISFR |= (1u << BUTTON_PIN1);

        /*Change state*/
        g_display_select ^= 1; 
    }

    /* SW3 is pressed*/
    if ((*PORTC).PORT_ISFR & (1u << BUTTON_PIN2))
    {
        /* CLear flag */ 
		(*PORTC).PORT_ISFR |= (1u << BUTTON_PIN2);

        /*Change state*/
        g_display_enable ^= 1; 
    }

    if(g_display_enable == 0)
    {
	    /*Turn off 7_led segments */
        spi_transmit(CHANNEL1_SPI,0x0C,0x00); /*Shutdown mode*/
			
        /*Update new date and time*/
        receive_date_and_time_in_normal_and_alarm_mode(); 
    }
}

void emb_mock(void)
{
    /*Enable clock*/
    enable_PCC_PORT('C');
    enable_PCC_PORT('D');


    /*******************************************************
	 * PTC12 = INPUT, RISING EDGE TRIGGER, ENABLE INTERRUPT
	 * PTC13 = INPUT, RISING EDGE TRIGGER, ENABLE INTERRUPT
	 *******************************************************/

    set_up_port_pcr('C',BUTTON_PIN1,'I',1,1); 
	set_up_port_pcr('C',BUTTON_PIN2,'I',1,1);

    /*Set no pull, output , no interrupt*/ 
	set_up_port_pcr('D',GREEN,'O',2,0);
	
    /*Enable interrupt port*/
    IRQ_init(61, 15, 1);


    /******************************************************************
	* SOSC: 8MHz, SOSCDIV1 : DISABLE, SOSCDIV2: 8MHz
	* SPLL: 80MHz, SPLLDIV1: DISABLE, SPLLDIV2: 20MHz
	* RCCR: CORE_CLK: 80MHz, BUS_CLK: 40MHz, LOW_CLK: 26.67MHz
	******************************************************************/
    config_SOSSC(0, 1, 1, 3, 1);
    config_SPLL(0, 3, 0, 4);
    config_RCCR(SCS_PLL_SCR_MASK, 0, 1, 2);

    /*Set up SPI*/
    enable_pcc_spi(CHANNEL1_SPI,SPLLDIV2_CLOCK);
    spi_init_master(CHANNEL1_SPI); 

    /*Initialize LPIT*/
    enable_PCC_LPIT();

	enable_module_clock(); 

	enable_interrupt(CHANNEL_2);

	setup_value_timer(20000000,CHANNEL_2); 

    /*Enable interrupt LPIT*/
    IRQ_init(50, 12, 0); 

    /*Set up LPUART*/
    /*Enable PCC , choose clock source, MUX set*/
    set_up_port_uart(LUART_CHANNEL1); 

    /*Baudrate = 9600 bps*/
    set_baudrate(LUART_CHANNEL1,8000000); 
    /*no parity, 8 bit length, 1 stop bit*/
    set_frame(CHANNEL_1,STOP_BIT_1, DATA_LENGTH8 , DISABLE);
    /*enable transmit*/
    enable_transmitter_or_receiver(CHANNEL_1, ENABLE, ENABLE);
		

    /*Clear error flag*/
	clear_error_flash();

    /*Set up flash part that will be accessed*/
	program_partition(); 

    /*Set flexRam to emulated eeprom*/
    set_flexram_to_emulated_eeprom();

    /*Read date from flash memory*/	
	read_date_from_flash(g_date); 

    /*Read time from flash memory*/	
	read_time_from_flash(g_time); 

    /*Clear error flag*/
	clear_error_flash();

    /*Set up flash part that will be accessed*/
	program_partition(); 

    /*Set flexRam to emulated eeprom*/
    set_flexram_to_emulated_eeprom();

    /*Read alarm time from flash memory*/
    read_time_alarm_from_flash(g_time_alarm); 
		
    /*Wait interrupt*/
    while(1)
    {   
        /*Check alarm*/
        if(check_alarm())
        {
            /*Led On*/
            (*GPIOD).PDOR &= ~(1u << GREEN); 
        }
        else
        {   
            /*Led Off*/
            (*GPIOD).PDOR |= (1u << GREEN); 
        }
        
        /*Check display mode enable*/
        if(g_display_enable)
        {
            /*Send command to 7-led segment (operation mode)*/
	        set_up_led_7_segment(); 

            /*Check displayed data*/
            if(g_display_select == 0)
            {
                /*Send time via spi*/
                send_time_via_spi(); 
            }
            else 
            {
                /*Send via spi*/
                send_date_via_spi(); 
            }
        }
        else 
        {
            /*Turn off 7_led segments */
            spi_transmit(CHANNEL1_SPI,0x0C,0x00); /*Shutdown mode*/
        }
    }
}

void ut_update_time_and_date(void)
{
    /*Unit test update time and date functions*/
    strcpy(g_date,"31122000"); 
    strcpy(g_time,"235959"); 
    update_time() ;

    memset(g_date,'0',sizeof(g_date)); 
	memset(g_time,'0',sizeof(g_time));
}

void ut_check_alarm(void)
{
    /*unit test check alarm*/
	strcpy(g_time_alarm,"235959");
	strcpy(g_time,"235959");
	
	check_alarm(); 
	
	memset(g_time,'0',sizeof(g_time));
	memset(g_time_alarm,'\0',sizeof(g_time_alarm));
}

void ut_write_read_with_flash(void)
{

    char ut_date[8]; 
    char ut_time[6]; 

    strcpy(ut_date,"31122000"); 
    strcpy(ut_time,"235959"); 
    /*Clear error flag*/
	clear_error_flash();

    /*Set up flash part that will be accessed*/
	program_partition(); 

    /*Set flexRam to emulated eeprom*/
    set_flexram_to_emulated_eeprom();

    read_date_from_flash(g_date); 

    write_date_to_flash(ut_date); 
	
	/*Clear error flag*/
	clear_error_flash();

    /*Set up flash part that will be accessed*/
	program_partition(); 

    /*Set flexRam to emulated eeprom*/
    set_flexram_to_emulated_eeprom();

    read_time_from_flash(g_time); 

    write_time_to_flash(ut_time); 

    memset(ut_date, '\0', sizeof(ut_date)); 
    memset(ut_time, '\0', sizeof(ut_time)); 
		
	/*Clear error flag*/
	clear_error_flash();

    /*Set up flash part that will be accessed*/
	program_partition(); 

    /*Set flexRam to emulated eeprom*/
    set_flexram_to_emulated_eeprom();

    read_date_from_flash(ut_date); 
		
	write_date_to_flash(g_date);
		
	/*Clear error flag*/
	clear_error_flash();

    /*Set up flash part that will be accessed*/
	program_partition(); 

    /*Set flexRam to emulated eeprom*/
    set_flexram_to_emulated_eeprom();

	read_time_from_flash(ut_time);
    write_time_to_flash(g_time); 

}
