#ifndef LPIT_H_
#define LPIT_H_

#include <stdint.h>

enum MCR_BIT
{
  M_CEN = 0u,                                /*Module Clock Enable*/                 
  SW_RST ,                                   /*Software Reset Bit*/
  DOZE_EN,                                   /*DOZE Mode Enable Bit*/
  DBG_EN                                     /*Debug Enable Bit*/
};

enum MSR_BIT
{
  TIF0 = 0,                                   /*Channel 0 Timer Interrupt Flag*/
  TIF1,                                       /*Channel 1 Timer Interrupt Flag*/
  TIF2,                                       /*Channel 2 Timer Interrupt Flag*/
  TIF3                                        /*Channel 3 Timer Interrupt Flag*/
};

enum MIER_BIT
{
  TIE0 = 0,                                   /*Channel 0 Timer Interrupt Enable*/
  TIE1,                                       /*Channel 1 Timer Interrupt Enable*/
  TIE2,                                       /*Channel 2 Timer Interrupt Enable*/
  TIE3                                        /*Channel 3 Timer Interrupt Enable*/
};

enum SETTEN_BIT
{
  SET_T_EN_0 = 0,                             /*Set Timer 0 Enable*/
  SET_T_EN_1,                                 /*Set Timer 1 Enable*/
  SET_T_EN_2,                                 /*Set Timer 2 Enable*/
  SET_T_EN_3                                  /*Set Timer 3 Enable*/
};

enum CLRTEN_BIT
{
  CLR_T_EN_0 = 0,                             /*Clear Timer 0 Enable*/
  CLR_T_EN_1,                                 /*Clear Timer 1 Enable*/
  CLR_T_EN_2,                                 /*Clear Timer 2 Enable*/
  CLR_T_EN_3                                  /*Clear Timer 3 Enable*/
};

enum TCTRL_BIT
{
  T_EN = 0u,                                  /*Timer Enable*/
  CHAIN,                                      /*Chain Channel*/
  MODE,                                       /*Timer Operation Mode*/
  TSOT = 16u,                                 /*Timer Start On Trigger*/
  TSOI,                                       /*Timer Stop On Interrupt*/
  TROT,                                       /*Timer Reload On Trigger*/
  TRG_SRC = 23u,                              /*Trigger Source*/
  TRG_SEL                                     /*Trigger Select*/
};

#define CHANNEL_0   (0u)
#define CHANNEL_1   (1u)
#define CHANNEL_2   (2u)
#define CHANNEL_3   (3u)




typedef struct 
{
    /*Version ID Register */
    volatile uint32_t VERID; // 0x0

    /*Parameter Register*/ 
    volatile uint32_t PARAM; //0x4

    /*Module Control Register */
    volatile uint32_t MCR; // 0x8

    /*Module Status Register*/
    volatile uint32_t MSR; // 0xC

    /*Module Interrupt Enable Register*/
    volatile uint32_t MIER; // 0x10    

    /*Set Timer Enable Register*/
    volatile uint32_t SETTEN; //0x14

    /*Clear Timer Enable Register */
    volatile uint32_t CLRTEN; // 0x18

    volatile uint32_t RESERVED_0;
		
    /*Timer Value Register n*/
    /*Current Timer Value n(STT n+1)*/
    /*Timer Control Register n(STT n+2)*/
    /*Reserved data*/
    volatile uint32_t TVAKL0; 
		volatile uint32_t CVAL0;
		volatile uint32_t TCTRL0;
		volatile uint32_t RESERVED_1;
		
	  volatile uint32_t TVAKL1; 
		volatile uint32_t CVAL1;
		volatile uint32_t TCTRL1;
		volatile uint32_t RESERVED_2;
		
		volatile uint32_t TVAKL2; 
		volatile uint32_t CVAL2;
		volatile uint32_t TCTRL2;
		volatile uint32_t RESERVED_3;
		
		volatile uint32_t TVAKL3; 
		volatile uint32_t CVAL3;
		volatile uint32_t TCTRL3;
		

}LPIT_type;

#define LPIPT_BASE_ADDR (0x40037000)
#define LPIT    ((LPIT_type*) LPIPT_BASE_ADDR)

/**
 * @brief Enables the module clock for the Low Power Interrupt Timer (LPIT).
 * 
 * This function configures the LPIT module to enable its clock and allow its operation. 
 * The function sets the `DBG_EN` bit to enable the module in debug mode, and the `M_CEN` bit
 * to enable the LPIT module's clock.
 * 
 * This setup is necessary for the LPIT to function correctly and participate in system operations.
 * 
 * @note The `DBG_EN` bit allows the LPIT module to continue operating during debug mode, while the `M_CEN`
 *       bit is required for the module to be clocked and thus operational.
 * 
 * @see LPIT
 */
void enable_module_clock(void); 

/**
 * @brief Enables interrupt requests for a specified LPIT (Low Power Interrupt Timer) channel.
 * 
 * This function enables the interrupt request for a given LPIT channel by setting the corresponding bit
 * in the LPIT module's interrupt enable register (`MIER`). The channel parameter specifies which channel's
 * interrupt should be enabled.
 * 
 * @param channel The LPIT channel number whose interrupt is to be enabled. This value should be within the valid
 *        range of LPIT channels supported by the hardware.
 * 
 * @note The `MIER` register controls the enabling of interrupts for each LPIT channel. Each bit corresponds
 *       to a specific channel. Setting a bit in this register allows interrupts from that channel to be
 *       generated and handled by the interrupt service routine.
 * 
 * @see LPIT
 */
void enable_interrupt(int channel);

/**
 * @brief Configures the timer value for a specified LPIT (Low Power Interrupt Timer) channel.
 * 
 * This function sets the timer value for a given LPIT channel and enables the timer for that channel.
 * The timer value is specified in `ticks`, which represents the number of timer counts. The function
 * configures the appropriate timer register based on the channel number and sets the timer enable bit
 * for that channel.
 * 
 * @param ticks The timer value to be set for the specified channel. This value is used to define the
 *        countdown period for the timer, with `ticks - 1` being written to the timer register.
 * @param channel The LPIT channel number to be configured. This should be one of the predefined channel
 *        constants (e.g., `CHANNEL_0`, `CHANNEL_1`, `CHANNEL_2`, `CHANNEL_3`).
 * 
 * @note The `TVAKL` register is used to set the timer value for the corresponding LPIT channel, and the
 *       `TCTRL` register is used to enable the timer by setting the `T_EN` bit. Ensure that the channel
 *       parameter is within the valid range of channels supported by the LPIT hardware.
 * 
 * @see LPIT
 * @see CHANNEL_0
 * @see CHANNEL_1
 * @see CHANNEL_2
 * @see CHANNEL_3
 */
void setup_value_timer(uint32_t ticks, int channel); 

#endif
