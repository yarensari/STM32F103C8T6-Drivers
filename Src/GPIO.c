#ifndef SRC_GPIO_C_
#define SRC_GPIO_C_

#include "../myDrivers/Inc/GPIO.h"

#define GPIO_MAX_PIN_NUMBER				(uint16_t)16U

#define GPIO_CR_MODE_INPUT				(uint32_t)0x0U 		/* 0000 */
#define GPIO_CR_CNF_ANALOG				(uint32_t)0x0U 		/* 0000 */
#define GPIO_CR_CNF_INPUT_FLOATING		(uint32_t)0x4U 		/* 0100 */
#define GPIO_CR_CNF_PUPD				(uint32_t)0x8U 		/* 1000 */
#define GPIO_CR_CNF_OUTPUT_PP			(uint32_t)0x0U 		/* 0000 */
#define GPIO_CR_CNF_OUTPUT_OD			(uint32_t)0x4U 		/* 0100 */
#define GPIO_CR_CNF_AF_PP				(uint32_t)0x8U 		/* 1000 */
#define GPIO_CR_CNF_AF_OD				(uint32_t)0xCU 		/* 1100 */

/**
 * @brief	GPIO_Init, Configures the port and pin
 *
 * @param	GPIOx = GPIO Port Base Address
 *
 * @param 	GPIOConfigStruct = User Config Structures
 *
 * @retval void
 */

void GPIO_Init(GPIO_TypeDef_t *GPIOx, GPIO_InitTypeDef_t *GPIOConfigStruct){
	uint16_t position;
	uint16_t fakePosition;
	uint16_t lastPosition;

	for(position = 0; position < GPIO_MAX_PIN_NUMBER; position++){
		fakePosition = (0x1 << position);
		lastPosition = (GPIOConfigStruct->pinNumber) & fakePosition;

		if(fakePosition == lastPosition){
			uint32_t config = 0x0U;
			config = GPIOx->CR[position >> 3U];
			config &= ~( 0xFU << ( (position & 7U) >> 2) );
			/* Mode Config*/
			switch(GPIOConfigStruct->Mode){
				case GPIO_MODE_ANALOG:
					config |= ( (GPIO_CR_MODE_INPUT + GPIO_CR_CNF_ANALOG) << ( (position & 7U) >> 2) ) ;
					break;
				case GPIO_MODE_INPUT:
					/* Pull Up - Pull Down Config */
					if(GPIOConfigStruct->PuPd == GPIO_PUPD_NOPULL){
						config |= ( (GPIO_CR_MODE_INPUT + GPIO_CR_CNF_INPUT_FLOATING) << ( (position & 7U) >> 2) );
					}else if(GPIOConfigStruct->PuPd == GPIO_PUPD_PULLUP){
						config |= ( (GPIO_CR_MODE_INPUT + GPIO_CR_CNF_PUPD) << ( (position & 7U) >> 2) );
						/* Set ODR */
						GPIOx->ODR |= (0x1 << position);
					}else{ /* PULL DOWN*/
						config |= ( (GPIO_CR_MODE_INPUT + GPIO_CR_CNF_PUPD) << ( (position & 7U) >> 2) );
						/* Set ODR */
						GPIOx->ODR &= ~(0x1 << position);
					}
					break;
				case GPIO_MODE_OUTPUT:
					/* Speed and Push Pull - Open Drain Config */
					if(GPIOConfigStruct->OTYPE == GPIO_OTYPE_PP){
						config |= ( (GPIOConfigStruct->Speed + GPIO_CR_CNF_OUTPUT_PP) << ( (position & 7U) >> 2) );
					}else if(GPIOConfigStruct->OTYPE == GPIO_OTYPE_OD){
						config |= ( (GPIOConfigStruct->Speed + GPIO_CR_CNF_OUTPUT_OD) << ( (position & 7U) >> 2) );
					}
					break;
				case GPIO_MODE_AF:
					/* Speed and Push Pull - Open Drain Config */
					if(GPIOConfigStruct->OTYPE == GPIO_OTYPE_PP){
						config |= ( (GPIOConfigStruct->Speed + GPIO_CR_CNF_AF_PP) << ( (position & 7U) >> 2) );
					}else if(GPIOConfigStruct->OTYPE == GPIO_OTYPE_OD){
						config |= ( (GPIOConfigStruct->Speed + GPIO_CR_CNF_AF_OD) << ( (position & 7U) >> 2) );
					}
					break;
				default:
					break;
			}
			GPIOx->CR[position >> 3U] = config;
		}
	}
}

/**
 * @brief	GPIO_Write_Pin, makes pin HIGH or LOW
 *
 * @param	GPIOx = GPIO Port Base Address
 *
 * @param	pinNumber = GPIO Pin Numbers 0 - 15
 *
 * @param 	pinState = GPIO_Pin_Reset or GPIO_Pin_Set
 *
 * @retval	void
 */

void GPIO_WritePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber, GPIO_PinState_t pinState){

	if(pinState != GPIO_Pin_Reset){
		GPIOx->BSRR = pinNumber;
	}else{
		GPIOx->BSRR = (pinNumber << 16U);
	}
}

/**
 * @brief	GPIO_Read_Pin, reads the pin of GPIOx Port
 *
 * @param	GPIOx = GPIO Port Base Address
 *
 * @param	pinNumber = GPIO Pin Numbers 0 - 15
 *
 * @retval	GPIO_PinState_t
 */

GPIO_PinState_t GPIO_ReadPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber){
	GPIO_PinState_t bitStatus = GPIO_Pin_Reset;

	if((GPIOx->IDR & pinNumber) != GPIO_Pin_Reset){
		bitStatus = GPIO_Pin_Set;
	}

	return bitStatus;
}

/**
 * @brief	GPIO_Lock_Pin, locks the pin of GPIOx Port
 *
 * @param	GPIOx = GPIO Port Base Address
 *
 * @param	pinNumber = GPIO Pin Numbers 0 - 15
 *
 * @retval	void
 */

void GPIO_LockPin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber) {
	uint32_t tempValue = (0x1U << 16U) | pinNumber;

	GPIOx->LCKR = tempValue;  		// LCKR[16] = '1' + LCKR[15:0] = DATA
	GPIOx->LCKR = pinNumber;		// LCKR[16] = '0' + LCKR[15:0] = DATA
	GPIOx->LCKR = tempValue;  		// LCKR[16] = '1' + LCKR[15:0] = DATA
	tempValue = GPIOx->LCKR;  		// Read Lock Register
}

/**
 * @brief	GPIO_Toggle_Pin, toggles the pin of GPIOx Port
 *
 * @param	GPIOx = GPIO Port Base Address
 *
 * @param	pinNumber = GPIO Pin Numbers 0 - 15
 *
 * @retval	void
 */

void GPIO_TogglePin(GPIO_TypeDef_t *GPIOx, uint16_t pinNumber){
	uint32_t tempODRRegister = GPIOx->ODR;

	GPIOx->BSRR = ( (tempODRRegister & pinNumber) << 16U) | (~tempODRRegister & pinNumber);

}

#endif /* SRC_GPIO_C_ */
