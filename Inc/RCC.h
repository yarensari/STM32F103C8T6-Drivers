#ifndef INC_RCC_H_
#define INC_RCC_H_

#include "../myDrivers/Inc/stm32f103xx.h"

/*
 * RCC APB2 Peripherals Clock Control Macro Definitions
 *
 */

#define RCC_GPIOA_CLK_ENABLE()			do{ uint32_t tempValue = 0; \
											SET_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIOAEN); \
										    tempValue = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIOAEN); \
											UNUSED(tempValue); \
										  }while(0)

#define RCC_GPIOB_CLK_ENABLE()			do{ uint32_t tempValue = 0; \
											SET_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIOBEN); \
											tempValue = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIOBEN); \
											UNUSED(tempValue); \
										  }while(0)

#define RCC_GPIOC_CLK_ENABLE()			do{ uint32_t tempValue = 0; \
										   SET_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIOCEN); \
										   tempValue = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIOCEN); \
									       UNUSED(tempValue); \
										   }while(0)

#define RCC_GPIOD_CLK_ENABLE()			do{ uint32_t tempValue = 0; \
											SET_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIODEN); \
											tempValue = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIODEN); \
											UNUSED(tempValue); \
								        }while(0)

#define RCC_GPIOE_CLK_ENABLE()			do{ uint32_t tempValue = 0; \
										   SET_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIOEEN);\
										   tempValue = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIOEEN); \
										   UNUSED(tempValue); \
										   }while(0)

#define RCC_AFIO_CLK_ENABLE()			do{ uint32_t tempValue = 0; \
											SET_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN); \
											tempValue = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN); \
											UNUSED(tempValue); \
											}while(0)

#define RCC_SPI1_CLK_ENABLE()			do{ uint32_t tempValue = 0; \
											SET_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN); \
											tempValue = READ_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN); \
											UNUSED(tempValue); \
											}while(0)

#define RCC_GPIOA_CLK_DISABLE()			CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIOAEN)
#define RCC_GPIOB_CLK_DISABLE()			CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIOBEN)
#define RCC_GPIOC_CLK_DISABLE()			CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIOCEN)
#define RCC_GPIOD_CLK_DISABLE()			CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIODEN)
#define RCC_GPIOE_CLK_DISABLE()			CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_GPIOEEN)

#define RCC_AFIO_CLK_DISABLE()			CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_AFIOEN);

#define RCC_SPI1_CLK_DISABLE()			CLEAR_BIT(RCC->APB2ENR, RCC_APB2ENR_SPI1EN);

/*
 * RCC APB1 Peripherals Clock Control Macro Definitions
 *
 */

#define RCC_SPI2_CLK_ENABLE()			do{ uint32_t tempValue = 0; \
											SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN); \
											tempValue = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN); \
											UNUSED(tempValue); \
											}while(0)

#define RCC_SPI3_CLK_ENABLE()			do{ uint32_t tempValue = 0; \
									        SET_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN); \
											tempValue = READ_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN); \
											UNUSED(tempValue); \
											}while(0)

#define RCC_SPI2_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI2EN);
#define RCC_SPI3_CLK_DISABLE()			CLEAR_BIT(RCC->APB1ENR, RCC_APB1ENR_SPI3EN);

#endif /* INC_RCC_H_ */
