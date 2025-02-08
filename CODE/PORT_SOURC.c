#include "PORT.h"
#include "GPIO.h"

void set_up_port_pcr(char PORT, unsigned int PORT_SET_UP, char PORT_DIRECTION, unsigned int PULL_SELECTION, unsigned int ENABLE_INTERRUPT)
{
    switch (PORT)
    {
    case 'A':
    {
        /*Set PORT to be an GPIO*/
        (*PORTA).PORT_PCR[PORT_SET_UP] |= PORT_MUX_MASK_GPIO; 

        /*Set PORT's direction*/
        if (PORT_DIRECTION == 'I')
        {
            (*GPIOA).PDDR &= ~(1u << PORT_SET_UP); 

            /*Switch pull selection */
            switch (PULL_SELECTION)
            {
            /*Pull down*/
            case 0:
            {
                (*PORTA).PORT_PCR[PORT_SET_UP] &= ~SET_PS_MASK; 
                break; 
            }
            /*Pull up*/
            case 1:
            {
                (*PORTA).PORT_PCR[PORT_SET_UP] |= SET_PS_MASK;
                break;
            }
            default:
                break;
            }

            /*Enable pull*/
            (*PORTA).PORT_PCR[PORT_SET_UP] |= SET_PE_MASK;
        }
        else if (PORT_DIRECTION == 'O')
        {
            (*GPIOA).PDDR |= (1u << PORT_SET_UP); 
            /*Disable pull*/
            (*PORTA).PORT_PCR[PORT_SET_UP] &= ~SET_PE_MASK;
        }
        else 
        {
            /*do no thing*/
        }

        /*Set up interrupt*/
        switch (ENABLE_INTERRUPT)
        {
        /*Disable */
        case 0: 
        {
            (*PORTA).PORT_PCR[PORT_SET_UP] &= DISABLE_INTERRUPT;
            break; 
        }

        /*Rising edge*/
        case 1:
        {
            (*PORTA).PORT_PCR[PORT_SET_UP] |= INTERRUPT_RISING_EDGE; 
            break;
        }

        /*Falling edge*/
        case 2: 
        {
            (*PORTA).PORT_PCR[PORT_SET_UP] |= INTERRUPT_FALLING_EDGE; 
            break;
        }
        case 3: 
        {
           (*PORTA).PORT_PCR[PORT_SET_UP] |= INTERRUPT_BOTH_EDGE; 
            break; 
        }
        default:
            break;
        }
        break;
    } 
    case 'B': 
    {
    /*Set PORT to be an GPIO*/
        (*PORTB).PORT_PCR[PORT_SET_UP] |= PORT_MUX_MASK_GPIO; 

        /*Set PORT's direction*/
        if (PORT_DIRECTION == 'I')
        {
            (*GPIOB).PDDR &= ~(1u << PORT_SET_UP); 

            /*Switch pull selection */
            switch (PULL_SELECTION)
            {
            /*Pull down*/
            case 0:
            {
                (*PORTB).PORT_PCR[PORT_SET_UP] &= ~SET_PS_MASK; 
                break; 
            }
            /*Pull up*/
            case 1:
            {
                (*PORTB).PORT_PCR[PORT_SET_UP] |= SET_PS_MASK;
                break;
            }
            default:
                break;
            }

            /*Enable pull*/
            (*PORTB).PORT_PCR[PORT_SET_UP] |= SET_PE_MASK;
        }
        else if (PORT_DIRECTION == 'O')
        {
            (*GPIOB).PDDR |= (1u << PORT_SET_UP); 
            /*Disable pull*/
            (*PORTB).PORT_PCR[PORT_SET_UP] &= ~SET_PE_MASK;
        }
        else 
        {
            /*do no thing*/
        }

        /*Set up interrupt*/
        switch (ENABLE_INTERRUPT)
        {
        /*Disable */
        case 0: 
        {
            (*PORTB).PORT_PCR[PORT_SET_UP] &= DISABLE_INTERRUPT;
            break; 
        }

        /*Rising edge*/
        case 1:
        {
            (*PORTB).PORT_PCR[PORT_SET_UP] |= INTERRUPT_RISING_EDGE; 
            break;
        }

        /*Falling edge*/
        case 2: 
        {
            (*PORTB).PORT_PCR[PORT_SET_UP] |= INTERRUPT_FALLING_EDGE; 
            break;
        }
        case 3: 
        {
           (*PORTB).PORT_PCR[PORT_SET_UP] |= INTERRUPT_BOTH_EDGE; 
            break; 
        }
        default:
            break;
        }

        break;
    }    
    case 'C':
    {
        /*Set PORT to be an GPIO*/
        (*PORTC).PORT_PCR[PORT_SET_UP] |= PORT_MUX_MASK_GPIO; 

        /*Set PORT's direction*/
        if (PORT_DIRECTION == 'I')
        {
            (*GPIOC).PDDR &= ~(1u << PORT_SET_UP); 

            /*Switch pull selection */
            switch (PULL_SELECTION)
            {
            /*Pull down*/
            case 0:
            {
                (*PORTC).PORT_PCR[PORT_SET_UP] &= ~SET_PS_MASK; 
                break; 
            }
            /*Pull up*/
            case 1:
            {
                (*PORTC).PORT_PCR[PORT_SET_UP] |= SET_PS_MASK;
                break;
            }
            default:
                break;
            }

            /*Enable pull*/
            (*PORTC).PORT_PCR[PORT_SET_UP] |= SET_PE_MASK;
        }
        else if (PORT_DIRECTION == 'O')
        {
            (*GPIOC).PDDR |= (1u << PORT_SET_UP); 
            /*Disable pull*/
            (*PORTC).PORT_PCR[PORT_SET_UP] &= ~SET_PE_MASK;
        }
        else 
        {
            /*do no thing*/
        }

        /*Set up interrupt*/
        switch (ENABLE_INTERRUPT)
        {
        /*Disable */
        case 0: 
        {
            (*PORTC).PORT_PCR[PORT_SET_UP] &= DISABLE_INTERRUPT;
            break; 
        }

        /*Rising edge*/
        case 1:
        {
            (*PORTC).PORT_PCR[PORT_SET_UP] |= INTERRUPT_RISING_EDGE; 
            break;
        }

        /*Falling edge*/
        case 2: 
        {
            (*PORTC).PORT_PCR[PORT_SET_UP] |= INTERRUPT_FALLING_EDGE; 
            break;
        }
        case 3: 
        {
           (*PORTC).PORT_PCR[PORT_SET_UP] |= INTERRUPT_BOTH_EDGE; 
            break; 
        }
        default:
            break;
        }
        
        break;
    } 
    case 'D': 
    {
        /*Set PORT to be an GPIO*/
        (*PORTD).PORT_PCR[PORT_SET_UP] |= PORT_MUX_MASK_GPIO; 

        /*Set PORT's direction*/
        if (PORT_DIRECTION == 'I')
        {
            (*GPIOD).PDDR &= ~(1u << PORT_SET_UP); 

            /*Switch pull selection */
            switch (PULL_SELECTION)
            {
            /*Pull down*/
            case 0:
            {
                (*PORTD).PORT_PCR[PORT_SET_UP] &= ~SET_PS_MASK; 
                break; 
            }
            /*Pull up*/
            case 1:
            {
                (*PORTD).PORT_PCR[PORT_SET_UP] |= SET_PS_MASK;
                break;
            }
            default:
                break;
            }

            /*Enable pull*/
            (*PORTD).PORT_PCR[PORT_SET_UP] |= SET_PE_MASK;
        }
        else if (PORT_DIRECTION == 'O')
        {
            (*GPIOD).PDDR |= (1u << PORT_SET_UP); 
            /*Disable pull*/
            (*PORTD).PORT_PCR[PORT_SET_UP] &= ~SET_PE_MASK;
        }
        else 
        {
            /*do no thing*/
        }

        /*Set up interrupt*/
        switch (ENABLE_INTERRUPT)
        {
        /*Disable */
        case 0: 
        {
            (*PORTD).PORT_PCR[PORT_SET_UP] &= DISABLE_INTERRUPT;
            break; 
        }

        /*Rising edge*/
        case 1:
        {
            (*PORTD).PORT_PCR[PORT_SET_UP] |= INTERRUPT_RISING_EDGE; 
            break;
        }

        /*Falling edge*/
        case 2: 
        {
            (*PORTD).PORT_PCR[PORT_SET_UP] |= INTERRUPT_FALLING_EDGE; 
            break;
        }
        case 3: 
        {
           (*PORTD).PORT_PCR[PORT_SET_UP] |= INTERRUPT_BOTH_EDGE; 
            break; 
        }
        default:
            break;
        }
        break;
    }
    case 'E':
    {
        /*Set PORT to be an GPIO*/
        (*PORTE).PORT_PCR[PORT_SET_UP] |= PORT_MUX_MASK_GPIO; 

        /*Set PORT's direction*/
        if (PORT_DIRECTION == 'I')
        {
            (*GPIOE).PDDR &= ~(1u << PORT_SET_UP); 

            /*Switch pull selection */
            switch (PULL_SELECTION)
            {
            /*Pull down*/
            case 0:
            {
                (*PORTE).PORT_PCR[PORT_SET_UP] &= ~SET_PS_MASK; 
                break; 
            }
            /*Pull up*/
            case 1:
            {
                (*PORTE).PORT_PCR[PORT_SET_UP] |= SET_PS_MASK;
                break;
            }
            default:
                break;
            }

            /*Enable pull*/
            (*PORTE).PORT_PCR[PORT_SET_UP] |= SET_PE_MASK;
        }
        else if (PORT_DIRECTION == 'O')
        {
            (*GPIOE).PDDR |= (1u << PORT_SET_UP); 
            /*Disable pull*/
            (*PORTE).PORT_PCR[PORT_SET_UP] &= ~SET_PE_MASK;
        }
        else 
        {
            /*do no thing*/
        }

        /*Set up interrupt*/
        switch (ENABLE_INTERRUPT)
        {
        /*Disable */
        case 0: 
        {
            (*PORTE).PORT_PCR[PORT_SET_UP] &= DISABLE_INTERRUPT;
            break; 
        }

        /*Rising edge*/
        case 1:
        {
            (*PORTE).PORT_PCR[PORT_SET_UP] |= INTERRUPT_RISING_EDGE; 
            break;
        }

        /*Falling edge*/
        case 2: 
        {
            (*PORTE).PORT_PCR[PORT_SET_UP] |= INTERRUPT_FALLING_EDGE; 
            break;
        }
        case 3: 
        {
           (*PORTE).PORT_PCR[PORT_SET_UP] |= INTERRUPT_BOTH_EDGE; 
            break; 
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }


}

void set_up_port_uart(int channel)
{
    switch (channel)
    {
    case LUART_CHANNEL0:
    {
        enable_PCC_LUART(LUART_CHANNEL0,SOSCDIV2_CLOCK);

        enable_PCC_PORT('B'); 

        (*PORTB).PORT_PCR[0] |= PORT_MUX_MASK_CHIP_SPECIFIC_LPUART; 
        (*PORTB).PORT_PCR[1] |= PORT_MUX_MASK_CHIP_SPECIFIC_LPUART; 
        break; 
    }
    case LUART_CHANNEL1:
    {
        enable_PCC_LUART(LUART_CHANNEL1,SOSCDIV2_CLOCK);

        enable_PCC_PORT('C');

        (*PORTC).PORT_PCR[6] |= PORT_MUX_MASK_CHIP_SPECIFIC_LPUART; 
        (*PORTC).PORT_PCR[7] |= PORT_MUX_MASK_CHIP_SPECIFIC_LPUART; 
        break; 
    }
    case LUART_CHANNEL2:
    {
        enable_PCC_LUART(LUART_CHANNEL2,SOSCDIV2_CLOCK);

        enable_PCC_PORT('E');

        (*PORTC).PORT_PCR[12] |= PORT_MUX_MASK_CHIP_SPECIFIC_LPUART; 
        (*PORTC).PORT_PCR[17] |= PORT_MUX_MASK_CHIP_SPECIFIC_LPUART;
        break; 
    }
    default:
        break;
    }
}