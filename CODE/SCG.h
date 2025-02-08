#ifndef SCG_H_
#define SCG_H_

#include <stdint.h>


/**
 * @brief Mask for selecting the System Clock Source (SCS) to use the external oscillator.
 * 
 * This mask selects the System Oscillator (SOSC) as the system clock source.
 */
#define SCS_SOSC_SCR_MASK   (1u)

/**
 * @brief Mask for selecting the System Clock Source (SCS) to use the internal ring oscillator.
 * 
 * This mask selects the Internal Ring Oscillator Clock (SIRC) as the system clock source.
 */
#define SCS_SIRC_SCR_MASK   (2u)

/**
 * @brief Mask for selecting the System Clock Source (SCS) to use the internal fast clock.
 * 
 * This mask selects the Fast Internal Reference Clock (FIRC) as the system clock source.
 */
#define SCS_FIRC_SCR_MASK   (3u)

/**
 * @brief Mask for selecting the System Clock Source (SCS) to use the phase-locked loop.
 * 
 * This mask selects the Phase-Locked Loop (PLL) as the system clock source.
 */
#define SCS_PLL_SCR_MASK    (6u)

/**
 * @brief Lock bit mask for the Fast Internal Reference Clock Status Register (FIRCCSR).
 * 
 * This mask is used to check if the FIRC clock configuration is locked.
 */
#define FIRCCSR_LK_MASK     (1u << 23u)

/**
 * @brief Lock bit mask for the Slow Internal Reference Clock Status Register (SIRCCSR).
 * 
 * This mask is used to check if the SIRC clock configuration is locked.
 */
#define SIRCCSR_LK_MASK     (1u << 23u)

/**
 * @brief Lock bit mask for the System Oscillator Clock Status Register (SOSCCSR).
 * 
 * This mask is used to check if the SOSC clock configuration is locked.
 */
#define SOSCCSR_LK_MASK     (1u << 23u)

/**
 * @brief Lock bit mask for the System PLL Clock Status Register (SPLLCSR).
 * 
 * This mask is used to check if the PLL clock configuration is locked.
 */
#define SPLLCSR_LK_MASK     (1u << 23u)

/**
 * @brief Clock divider and configuration settings for the System Oscillator (SOSC).
 * 
 * - SOSCDIV1: Divider value for SOSC.
 * - SOSC_EREF: External reference oscillator.
 * - SOSC_HGO: High gain oscillator.
 * - SOSC_RANGE: SOSC range setting.
 * - SOSCDIV2: Additional divider setting.
 * - SOSC_LK_SCR: Lock bit location for SOSC.
 * - SOSC_VLD_SCR: Valid bit location for SOSC.
 */
#define SOSCDIV1            (0u)
#define SOSC_EREF           (2u)
#define SOSC_HGO            (3u)
#define SOSC_RANGE          (4u)
#define SOSCDIV2            (8u)
#define SOSC_LK_SCR         (23u)
#define SOSC_VLD_SCR        (24u)

/**
 * @brief Clock divider and configuration settings for the Fast Internal Reference Clock (FIRC).
 * 
 * - FIRCDIV1: Divider value for FIRC.
 * - FIRCRANGE: Range setting for FIRC.
 * - FIRCDIV2: Additional divider setting.
 * - FIRC_LK_SCR: Lock bit location for FIRC.
 * - FIRC_VLD_SCR: Valid bit location for FIRC.
 */
#define FIRCDIV1            (0u)
#define FIRCRANGE           (0u)
#define FIRCDIV2            (8u)
#define FIRC_LK_SCR         (23u)
#define FIRC_VLD_SCR        (24u)

/**
 * @brief Clock divider and configuration settings for the Slow Internal Reference Clock (SIRC).
 * 
 * - SIRCDIV1: Divider value for SIRC.
 * - SIRCRANGE: Range setting for SIRC.
 * - SIRCDIV2: Additional divider setting.
 * - SIRC_LK_SCR: Lock bit location for SIRC.
 * - SIRC_VLD_SCR: Valid bit location for SIRC.
 */
#define SIRCDIV1            (0u)
#define SIRCRANGE           (0u)
#define SIRCDIV2            (8u)
#define SIRC_LK_SCR         (23u)
#define SIRC_VLD_SCR        (24u)

/**
 * @brief Clock divider and configuration settings for the Phase-Locked Loop (PLL).
 * 
 * - SPLLDIV1: Divider value for PLL.
 * - SPLL_SOURCE_CCFG: Source configuration for PLL.
 * - SPLLDIV2: Additional divider setting for PLL.
 * - SPLL_PREDIV: Pre-divider setting for PLL.
 * - SPLL_MULT: Multiplier setting for PLL.
 * - SPLL_LK_SCR: Lock bit location for PLL.
 * - SPLL_VLD_SCR: Valid bit location for PLL.
 */
#define SPLLDIV1            (0u)
#define SPLL_SOURCE_CCFG    (0u)
#define SPLLDIV2            (8u)
#define SPLL_PREDIV         (8u)
#define SPLL_MULT           (16u)
#define SPLL_LK_SCR         (23u)
#define SPLL_VLD_SCR        (24u)

/**
 * @brief Bit location definitions for various clock dividers and settings.
 * 
 * - DIVlOW_BITLOCATION: Bit location for low divider.
 * - DIVBUS_BITLOCATION: Bit location for bus divider.
 * - DIVCORE_BITLOCATION: Bit location for core divider.
 * - SCS_BITLOCATION: Bit location for System Clock Source.
 */
#define DIVlOW_BITLOCATION  (0u)
#define DIVBUS_BITLOCATION  (4u)
#define DIVCORE_BITLOCATION (16u)
#define SCS_BITLOCATION     (24u)


enum CLOCK_SOURCE_DIV2
{
    SOSCDIV2_CLOCK = 1, 
    SIRCDIV2_CLOCK, 
    FIRCDIV2_CLOCK, 
    SPLLDIV2_CLOCK = 6, 
    LPO128
};


typedef struct 
{
    /*Version ID Register*/
    volatile uint32_t SCG_VERID ; // 0x0 

    /*Parameter Register*/
    volatile uint32_t SCG_PARAM ; // 0x4

    /*Fill data in struct*/
    volatile uint32_t RESERVED_0[2] ; // 0x08 0x0C

    /*Clock Status Registe*/
    volatile uint32_t SCG_CSR ; // 0x10 

    /*Run Clock Control RegisteR*/
    volatile uint32_t SCG_RCCR ; // 0x14 

    /*VLPR Clock Control Register*/
    volatile uint32_t SCG_VCCR ; // 0x18

    /*HSRUN Clock Control Register*/
    volatile uint32_t SCG_HCCR ; // 0x1C

    /*SCG CLKOUT Configuration Register*/
    volatile uint32_t SCG_CLKOUTCNFG ; // 0x20 

    /*Fill data in struct*/
    volatile uint32_t RESERVED_1[55] ; 

    /*System OSC Control Status Register*/
    volatile uint32_t SCG_SOSCCSR ; // 0x100

    /*System OSC Divide Register*/
    volatile uint32_t SCG_SOSCDIV ; // 0x104 

    /*System Oscillator Configuration Register*/
    volatile uint32_t SCG_SOSCCFG ; // 0x108

    /*Fill data in struct*/
    volatile uint32_t RESERVED_2[61] ; 

    /*Slow IRC Control Status Register*/
    volatile uint32_t SCG_SIRCCSR ; // 0x200 

    /*Slow IRC Divide Register */
    volatile uint32_t SCG_SIRCDIV ; // 0x204

    /*Slow IRC Configuration Register*/
    volatile uint32_t SCG_SIRCCFG ; // 0x208

    /*Fill data in struct*/
    volatile uint32_t RESERVED_3[61] ; 

    /*Fast IRC Control Status Register */
    volatile uint32_t SCG_FIRCCSR ; // 0x300 

    /*Fast IRC Divide Register */
    volatile uint32_t SCG_FIRCDIV ; // 0x304 
    
    /*Fast IRC Configuration Register*/
    volatile uint32_t SCG_FIRCCFG ; // 0x308 

    /*Fill data in struct*/
    volatile uint32_t RESERVED_4[189] ; 

    /*System PLL Control Status Register*/
    volatile uint32_t SCG_SPLLCSR ; // 0x600

    /*System PLL Divide Register */
    volatile uint32_t SCG_SPLCDIV ; // 0x604

     /*System PLL Configuration Register*/
    volatile uint32_t SCG_SPLCCFG ; // 0x608

} SCG_OFFSET; 

#define SCG_ADDR_BASE (0x40064000)
#define SCG ((SCG_OFFSET*) SCG_ADDR_BASE) 

/**
 * @brief Configures the System Oscillator (SOSC) settings.
 * 
 * This function configures the System Oscillator (SOSC) by setting its 
 * dividers, high gain oscillator (HGO) settings, range, and external 
 * reference (EREF). It unlocks and disables the SOSC configuration, 
 * applies the new settings, and then enables the SOSC while checking 
 * for validity.
 * 
 * @param DIV1     Divider value for the first divider.
 * @param DIV2     Divider value for the second divider.
 * @param HGO      High gain oscillator setting.
 * @param RANGE    Range setting.
 * @param EREF    External reference setting.
 */
void config_SOSSC(unsigned int DIV1, unsigned int DIV2, unsigned int HGO, unsigned RANGE, unsigned int EREF);

/**
 * @brief Configures the Phase-Locked Loop (PLL) settings.
 * 
 * This function configures the Phase-Locked Loop (PLL) by setting its 
 * dividers, pre-divider, and multiplier. It unlocks and disables the 
 * PLL configuration, applies the new settings, and then enables the PLL 
 * while checking for validity.
 * 
 * @param DIV1     Divider value for the first divider.
 * @param DIV2     Divider value for the second divider.
 * @param PREDIV   Pre-divider value.
 * @param MULT     Multiplier value.
 */
void config_SPLL(unsigned int DIV1, unsigned int DIV2, unsigned int PREDIV, unsigned int MULT ); 

/**
 * @brief Configures the Fast Internal Reference Clock (FIRC) settings.
 * 
 * This function configures the Fast Internal Reference Clock (FIRC) by 
 * setting its dividers and range. It unlocks and disables the FIRC 
 * configuration, applies the new settings, and then enables the FIRC while 
 * checking for validity.
 * 
 * @param DIV1     Divider value for the first divider.
 * @param DIV2     Divider value for the second divider.
 * @param RANGE    Range setting.
 */
void config_FIRC(unsigned int DIV1, unsigned int DIV2, unsigned int RANGE);

/**
 * @brief Configures the Slow Internal Reference Clock (SIRC) settings.
 * 
 * This function configures the Slow Internal Reference Clock (SIRC) by 
 * setting its dividers and range. It unlocks and disables the SIRC 
 * configuration, applies the new settings, and then enables the SIRC while 
 * checking for validity.
 * 
 * @param DIV1     Divider value for the first divider.
 * @param DIV2     Divider value for the second divider.
 * @param RANGE    Range setting.
 */
void config_SIRC(unsigned int DIV1, unsigned int DIV2,unsigned int RANGE);

/**
 * @brief Configures the Reset and Clock Control Register (RCCR).
 * 
 * This function configures the Reset and Clock Control Register (RCCR) 
 * by setting the System Clock Source (SCS), core, bus, and low dividers. 
 * It applies the new settings and then checks if the configuration is valid.
 * 
 * @param SCS       System Clock Source.
 * @param DIV_CORE  Core clock divider.
 * @param DIV_BUS   Bus clock divider.
 * @param DIV_LOW   Low clock divider.
 */
void config_RCCR(unsigned int SCS, unsigned int DIV_CORE, unsigned int DIV_BUS, unsigned int DIV_LOW); 
#endif
