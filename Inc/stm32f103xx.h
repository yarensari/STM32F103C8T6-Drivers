#ifndef INC_STM32F103XX_H_
#define INC_STM32F103XX_H_

#include <stdint.h>

/*
 * Microsprocessor defines
 *
 */

#define NVIC_ISER0						( (uint32_t*)(0xE000E100) )

#define __IO volatile

#define SET_BIT(REG, BIT)				( (REG) |=  (BIT) )
#define CLEAR_BIT(REG, BIT)				( (REG) &= ~(BIT) )
#define READ_BIT(REG, BIT)				( (REG) &   (BIT) )
#define UNUSED(x)						(void)x

typedef enum
{
	ENABLE  = 0x1U,
	DISABLE = !ENABLE

}FunctionalState_t;

/*
 * IRQ Numbers of MCU == Vector Table
 *
 */

typedef enum
{
	EXTI0_IRQNumber = 6,
	EXTI1_IRQNumber = 7,
	EXTI2_IRQNumber = 8,
	EXTI3_IRQNumber = 9,
	EXTI4_IRQNumber = 10

}IRQNumber_TypeDef_t;

/*
 * Memory Base Address
 *
 */

#define FLASH_BASE_ADDR					(0x08000000UL)                    /*  Flash Base Address (up to 128KB)  */
#define SRAM_BASE_ADDR					(0x20000000UL)                    /*  SRAM Base Address 20KB            */


/*
 * Peripheral Base Addresses
 *
 */

#define PERIPH_BASE_ADDR				(0x40000000UL)                    /*  Base Address for ALL peripherals  */

#define APB1_BASE_ADDR					PERIPH_BASE_ADDR                  /*  APB1 Bus Domain Base Address      */
#define APB2_BASE_ADDR					(PERIPH_BASE_ADDR + 0x00010000UL) /*  APB2 Bus Domain Base Address      */
#define AHB_BASE_ADDR					(PERIPH_BASE_ADDR + 0x00018000UL) /*  AHB Bus Domain Base Address       */


/*
 * APB1 Peripherals Base Addresses
 *
 */

#define TIM2_BASE_ADDR					(APB1_BASE_ADDR + 0x0000UL) 	  /*  Timer 2 Base Address   */
#define TIM3_BASE_ADDR					(APB1_BASE_ADDR + 0x4000UL)		  /*  Timer 3 Base Address   */
#define TIM4_BASE_ADDR					(APB1_BASE_ADDR + 0x8000UL)       /*  Timer 4 Base Address   */
#define TIM5_BASE_ADDR					(APB1_BASE_ADDR + 0xC000UL)       /*  Timer 5 Base Address   */
#define TIM6_BASE_ADDR					(APB1_BASE_ADDR + 0x1000UL)		  /*  Timer 6 Base Address   */
#define TIM7_BASE_ADDR					(APB1_BASE_ADDR + 0x1400UL)		  /*  Timer 7 Base Address   */
#define TIM12_BASE_ADDR					(APB1_BASE_ADDR + 0x1800UL)		  /*  Timer 12 Base Address  */
#define TIM13_BASE_ADDR					(APB1_BASE_ADDR + 0x1C00UL)		  /*  Timer 13 Base Address  */
#define TIM14_BASE_ADDR					(APB1_BASE_ADDR + 0x2000UL) 	  /*  Timer 14 Base Address  */

#define SPI2_BASE_ADDR					(APB1_BASE_ADDR + 0x3800UL)		  /*  SPI 2 Base Address     */
#define SPI3_BASE_ADDR					(APB1_BASE_ADDR + 0x3C00UL) 	  /*  SPI 3 Base Address     */

#define USART2_BASE_ADDR				(APB1_BASE_ADDR + 0x4400UL)		  /*  USART 2 Base Address   */
#define USART3_BASE_ADDR				(APB1_BASE_ADDR + 0x4800UL)		  /*  USART 3 Base Address   */
#define UART4_BASE_ADDR					(APB1_BASE_ADDR + 0x4C00UL)		  /*  UART 4 Base Address    */
#define UART5_BASE_ADDR 				(APB1_BASE_ADDR + 0x5000UL)		  /*  UART 5 Base Address    */

#define I2C1_BASE_ADDR					(APB1_BASE_ADDR + 0x5400UL) 	  /*  I2C 1 Base Address     */
#define I2C2_BASE_ADDR 					(APB1_BASE_ADDR + 0x5800UL)		  /*  I2C 2 Base Address     */


/*
 * APB2 Peripherals Base Addresses
 *
 */

#define TIM1_BASE_ADDR					(APB2_BASE_ADDR + 0x2C00UL) 	  /*  Timer 1 Base Address  */
#define TIM8_BASE_ADDR					(APB2_BASE_ADDR + 0x3400UL)	      /*  Timer 8 Base Address  */

#define USART1_BASE_ADDR				(APB2_BASE_ADDR + 0x3800UL)		  /*  USART 1 Base Address  */

#define SPI1_BASE_ADDR					(APB2_BASE_ADDR + 0x3000UL)		  /*  SPI 1 Base Address    */

#define AFIO_BASE_ADDR					APB2_BASE_ADDR				      /*  AFIO Base Address     */
#define EXTI_BASE_ADDR					(APB2_BASE_ADDR + 0x0400UL)		  /*  EXTI Base Address     */

#define GPIOA_BASE_ADDR					(APB2_BASE_ADDR + 0x0800UL)		  /*  GPIOA Base Address    */
#define GPIOB_BASE_ADDR					(APB2_BASE_ADDR + 0x0C00UL)		  /*  GPIOB Base Address    */
#define GPIOC_BASE_ADDR					(APB2_BASE_ADDR + 0x1000UL)		  /*  GPIOC Base Address    */
#define GPIOD_BASE_ADDR					(APB2_BASE_ADDR + 0x1400UL)		  /*  GPIOD Base Address    */
#define GPIOE_BASE_ADDR					(APB2_BASE_ADDR + 0x1800UL)		  /*  GPIOE Base Address    */
#define GPIOF_BASE_ADDR					(APB2_BASE_ADDR + 0x1C00UL)		  /*  GPIOF Base Address    */
#define GPIOG_BASE_ADDR					(APB2_BASE_ADDR + 0x2000UL)		  /*  GPIOG Base Address    */


/*
 * AHB Peripherals Base Addresses
 *
 */

#define RCC_BASE_ADDR					(AHB_BASE_ADDR + 0x9000UL)        /*  RCC Base Address  */


/*
 * Peripheral Structure Definitions
 *
 */

typedef struct
{
	__IO uint32_t CR[2];  			/* !< GPIO Port Configuration Register      				Address Offset = 0x0000 */
	__IO uint32_t IDR;    			/* !< GPIO Port Input Data Register         				Address Offset = 0x0008 */
	__IO uint32_t ODR;	  			/* !< GPIO Port Output Data Register        				Address Offset = 0x000C */
	__IO uint32_t BSRR;	  			/* !< GPIO Port Bit Set/Reset Register      				Address Offset = 0x0010 */
	__IO uint32_t BRR;    			/* !< GPIO Port Bit Reset Register          				Address Offset = 0x0014 */
	__IO uint32_t LCKR;  	 		/* !< GPIO Port Configuration Lock Register 				Address Offset = 0x0018 */

}GPIO_TypeDef_t;

typedef struct
{
	__IO uint32_t CR;       		/* !< RCC Clock Control Register                			Address Offset = 0x0000 */
	__IO uint32_t CFGR;     		/* !< RCC Clock Control Register                			Address Offset = 0x0004 */
	__IO uint32_t CIR;      		/* !< RCC Clock Interrupt Register              			Address Offset = 0x0008 */
	__IO uint32_t APB2RSTR; 		/* !< RCC APB2 Peripheral Reset Register        			Address Offset = 0x000C */
	__IO uint32_t APB1RSTR; 		/* !< RCC APB1 Peripheral Reset Register        			Address Offset = 0x0010 */
	__IO uint32_t AHBENR;   		/* !< RCC AHB Peripheral Clock Enable Register  			Address Offset = 0x0014 */
	__IO uint32_t APB2ENR;  		/* !< RCC APB2 Peripheral Clock Enable Register 			Address Offset = 0x0018 */
	__IO uint32_t APB1ENR;  		/* !< RCC APB1 Peripheral Clock Enable Register 			Address Offset = 0x001C */
	__IO uint32_t BDCR;     		/* !< RCC Backup Domain Control Register        			Address Offset = 0x0020 */
	__IO uint32_t CSR;      		/* !< RCC Control/Status Register               			Address Offset = 0x0024 */

}RCC_TypeDef_t;

typedef struct
{
	__IO uint32_t EVCR;     		/* !< AFIO Event Control Register							Address Offset = 0x0000 */
	__IO uint32_t MAPR;				/* !< AF Remap and Debug I/O Configuration Register 1		Address Offset = 0x0004 */
	__IO uint32_t EXTI_CR[4];		/* !< AFIO External Interrupt Configuration Registers		Address Offset = 0x0008 */
	__IO uint32_t MAPR2; 			/* !< AF Remap and Debug I/O Configuration Register 2 		Address Offset = 0x001C */

}AFIO_TypeDef_t;

typedef struct
{
	__IO uint32_t IMR;				/* !< EXTI Interrupt Mask Register 							Address Offset = 0x0000 */
	__IO uint32_t EMR;				/* !< EXTI Event Mask Register 								Address Offset = 0x0004 */
	__IO uint32_t RTSR;				/* !< EXTI Rising Trigger Selection Register 				Address Offset = 0x0008 */
	__IO uint32_t FTSR;				/* !< EXTI Falling Trigger Selection Register				Address Offset = 0x000C */
	__IO uint32_t SWIER;			/* !< EXTI Software Interrupt Event Register 				Address Offset = 0x0010 */
	__IO uint32_t PR;				/* !< EXTI Pending Register									Address Offset = 0x0014 */

}EXTI_TypeDef_t;

typedef struct
{
	__IO uint32_t CR1;				/*!< SPI Control Register 1 								Address Offset = 0x0000 */
	__IO uint32_t CR2;				/*!< SPI Control Register 2									Address Offset = 0x0004 */
	__IO uint32_t SR;				/*!< SPI Status Register									Address Offset = 0x0008 */
	__IO uint32_t DR;				/*!< SPI Data Register 										Address Offset = 0x000C */
	__IO uint32_t CRCPR;			/*!< SPI CRC Polynomial Register							Address Offset = 0x0010 */
	__IO uint32_t RXCRCR;			/*!< SPI RX CRC Register									Address Offset = 0x0014 */
	__IO uint32_t TXCRCR;			/*!< SPI TX CRC Register 									Address Offset = 0x0018 */
	__IO uint32_t I2SCFGR;			/*!< SPI_I2S Configuration Register							Address Offset = 0x001C */
	__IO uint32_t I2SPR;			/*!< SPI_I2S Prescaler Register 							Address Offset = 0x0020 */

}SPI_TypeDef_t;

/*
 * Bases address definitions of ports
 *
 */

#define GPIOA							( (GPIO_TypeDef_t *) (GPIOA_BASE_ADDR) )
#define GPIOB							( (GPIO_TypeDef_t *) (GPIOB_BASE_ADDR) )
#define GPIOC							( (GPIO_TypeDef_t *) (GPIOC_BASE_ADDR) )
#define GPIOD							( (GPIO_TypeDef_t *) (GPIOD_BASE_ADDR) )
#define GPIOE							( (GPIO_TypeDef_t *) (GPIOE_BASE_ADDR) )
#define GPIOF							( (GPIO_TypeDef_t *) (GPIOF_BASE_ADDR) )
#define GPIOG							( (GPIO_TypeDef_t *) (GPIOG_BASE_ADDR) )

#define RCC								( (RCC_TypeDef_t *)  (RCC_BASE_ADDR)   )

#define AFIO							( (AFIO_TypeDef_t *) (AFIO_BASE_ADDR)  )

#define EXTI							( (EXTI_TypeDef_t *) (EXTI_BASE_ADDR)  )

#define SPI1							( (SPI_TypeDef_t *) (SPI1_BASE_ADDR)   )
#define SPI2							( (SPI_TypeDef_t *) (SPI2_BASE_ADDR)   )
#define SPI3							( (SPI_TypeDef_t *) (SPI3_BASE_ADDR)   )

/*
 * Bit Definitions
 *
 */

#define RCC_APB2ENR_GPIOAEN_Pos 		(2U)							  // RCC APB2ENR Register GPIOAEN Bit Position
#define RCC_APB2ENR_GPIOAEN_Msk			(0x1 << RCC_APB2ENR_GPIOAEN_Pos)  // RCC APB2ENR Register GPIOAEN Bit Mask
#define RCC_APB2ENR_GPIOAEN				RCC_APB2ENR_GPIOAEN_Msk           // RCC APB2ENR Register GPIOAEN Macro

#define RCC_APB2ENR_GPIOBEN_Pos			(3U)                              // RCC APB2ENR Register GPIOBEN Bit Position
#define RCC_APB2ENR_GPIOBEN_Msk			(0x1 << RCC_APB2ENR_GPIOBEN_Pos)  // RCC APB2ENR Register GPIOBEN Bit Mask
#define RCC_APB2ENR_GPIOBEN				RCC_APB2ENR_GPIOBEN_Msk           // RCC APB2ENR Register GPIOBEN Macro

#define RCC_APB2ENR_GPIOCEN_Pos			(4U)							  // RCC APB2ENR Register GPIOCEN Bit Position
#define RCC_APB2ENR_GPIOCEN_Msk			(0x1 << RCC_APB2ENR_GPIOCEN_Pos)  // RCC APB2ENR Register GPIOCEN Bit Mask
#define RCC_APB2ENR_GPIOCEN				RCC_APB2ENR_GPIOCEN_Msk			  // RCC APB2ENR Register GPICEN Macro

#define RCC_APB2ENR_GPIODEN_Pos			(5U)							  // RCC APB2ENR Register GPIODEN Bit Position
#define RCC_APB2ENR_GPIODEN_Msk			(0x1 << RCC_APB2ENR_GPIODEN_Pos)  // RCC APB2ENR Register GPIODEN Bit Mask
#define RCC_APB2ENR_GPIODEN				RCC_APB2ENR_GPIODEN_Msk     	  // RCC APB2ENR Register GPIODEN Macro

#define RCC_APB2ENR_GPIOEEN_Pos			(6U)							  // RCC APB2ENR Register GPIOEEN Bit Position
#define RCC_APB2ENR_GPIOEEN_Msk			(0x1 << RCC_APB2ENR_GPIOEEN_Pos)  // RCC APB2ENR Register GPIOEEN Bit Mask
#define RCC_APB2ENR_GPIOEEN				RCC_APB2ENR_GPIOEEN_Msk     	  // RCC APB2ENR Register GPIOEEN Macro

#define RCC_APB2ENR_AFIOEN_Pos			(0U)							  // RCC APB2ENR Register AFIOEN Bit Position
#define RCC_APB2ENR_AFIOEN_Msk			(0x1 << RCC_APB2ENR_AFIOEN_Pos)	  // RCC APB2ENR Register AFIOEN Bit Mask
#define RCC_APB2ENR_AFIOEN				RCC_APB2ENR_AFIOEN_Msk			  // RCC APB2ENR Register AFIOEN Macro

#define RCC_APB2ENR_SPI1EN_Pos			(12U)							  // RCC APB2ENR Register SPI1EN Bit Position
#define RCC_APB2ENR_SP1EN_Msk			(0x1 << RCC_APB2ENR_SPI1EN_Pos)	  // RCC APB2ENR Register SPI1EN Bit Mask
#define RCC_APB2ENR_SPI1EN				RCC_APB2ENR_SP1EN_Msk			  // RCC APB2ENR Register SPI1EN Macro

#define RCC_APB1ENR_SPI2EN_Pos			(14U)							  // RCC APB1ENR Register SPI2EN Bit Position
#define RCC_APB1ENR_SPI2EN_Msk			(0x1 << RCC_APB1ENR_SPI2EN_Pos)	  // RCC APB1ENR Register SPI2EN Bit Mask
#define RCC_APB1ENR_SPI2EN				RCC_APB1ENR_SPI2EN_Msk			  // RCC APB1ENR Register SPI2EN Macro

#define RCC_APB1ENR_SPI3EN_Pos			(15U)							  // RCC APB1ENR Register SPI3EN Bit Position
#define RCC_APB1ENR_SPI3EN_Msk			(0x1 << RCC_APB1ENR_SPI3EN_Pos)   // RCC APB1ENR Register SPI3EN Bit Mask
#define RCC_APB1ENR_SPI3EN				RCC_APB1ENR_SPI3EN_Msk			  // RCC APB1ENR Register SPI3EN Macro

#define SPI_CR1_SPE						(6U)							  // SPI CR1 Register SPE Bit Position
#define SPI_SR_RXE						(0U)							  // SPI SR Register RXE Bit Position
#define SPI_SR_TXE						(1U)							  // SPI SR Register TXE Bit Position
#define SPI_SR_BSY						(7U)							  // SPI SR Register BSY Bit Position

/*
 * Flag Definitions
 *
 */

#define SPI_RXE_FLAG					(0x1U << SPI_SR_RXE)
#define SPI_TXE_FLAG					(0x1U << SPI_SR_TXE)
#define SPI_BSY_FLAG					(0x1U << SPI_SR_BSY)

#include "../myDrivers/Inc/RCC.h"
#include "../myDrivers/Inc/GPIO.h"
#include "../myDrivers/Inc/EXTI.h"
#include "../myDrivers/Inc/SPI.h"


#endif /* INC_STM32F103XX_H_ */
