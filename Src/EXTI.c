#include "../myDrivers/Inc/EXTI.h"

/**
 * @brief	EXTI_Init for valid GPIO port and line number
 *
 * @param	EXTI_InitStruct = User Config Structure
 *
 * @retval void
 */

void EXTI_Init(EXTI_InitTypeDef_t *EXTI_InitStruct)
{
	uint32_t tempValue = 0;

	tempValue = (uint32_t)EXTI_BASE_ADDR;

	if(EXTI_InitStruct->EXTI_LineCmd != DISABLE)
	{
		EXTI->IMR  &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
		EXTI->EMR  &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

		tempValue += EXTI_InitStruct->EXTI_Mode;
		*( (__IO uint32_t*)tempValue ) |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);

		tempValue = (uint32_t)EXTI_BASE_ADDR;

		EXTI->RTSR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);
		EXTI->FTSR &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

		if(EXTI_InitStruct->TriggerSelection == EXTI_Trigger_RF)
		{
			EXTI->RTSR |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);
			EXTI->FTSR |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);

		}else
		{
			tempValue += EXTI_InitStruct->TriggerSelection;
			*( (__IO uint32_t*)tempValue ) |= (0x1U << EXTI_InitStruct->EXTI_LineNumber);

		}

	}else
	{
		tempValue += EXTI_InitStruct->EXTI_Mode;
		*( (uint32_t*)tempValue ) &= ~(0x1U << EXTI_InitStruct->EXTI_LineNumber);

	}
}

/**
 * @brief	GPIO_LineConfig, Configures the port and pin for AFIO_EXTI
 *
 * @param	PortSource = Port Value A - G @def_group PORT_Values
 *
 * @param 	EXTI_LineSource = Pin Numbers & Line Numbers @def_group EXTI_Line_Values
 *
 * @retval void
 */

void EXTI_LineConfig(uint8_t PortSource, uint8_t EXTI_LineSource)
{
	uint32_t tempValue = 0;

	tempValue = AFIO->EXTI_CR[EXTI_LineSource >> 2U];
	tempValue &= ~(0xFU << (EXTI_LineSource & 0x3U) * 4 );
	tempValue |= (PortSource << (EXTI_LineSource & 0x3U) * 4 );
	AFIO->EXTI_CR[EXTI_LineSource >> 2U] = tempValue;
}

/**
 * @brief	NVIC_EnableInterrupt
 *
 * @param	IRQNumber = IRQ Number of Line
 *
 * @retval void
 */

void NVIC_EnableInterrupt(IRQNumber_TypeDef_t IRQNumber)
{
	uint32_t tempValue = 0;

	tempValue = *( NVIC_ISER0 + (IRQNumber >> 5U) );
	tempValue &= ~(0x1U << (IRQNumber & 0x1FU) );
	tempValue |= (0x1U << (IRQNumber & 0x1FU) );

	*( NVIC_ISER0 + (IRQNumber >> 5) ) = tempValue;
}
