#include "../myDrivers/Inc/SPI.h"

/**
 * @brief	SPI_Init, Configures the SPI peripheral
 *
 * @param	SPI_Handle = User config structure
 *
 * @retval	void
 */

void SPI_Init(SPI_HandleTypeDef_t *SPI_Handle)
{
	uint32_t tempValue = 0;

	tempValue = SPI_Handle->Instance->CR1;

	tempValue |= (SPI_Handle->Init.Mode) | (SPI_Handle->Init.CPHA) | (SPI_Handle->Init.CPOL) | (SPI_Handle->Init.BaudRate) | (SPI_Handle->Init.DFF_Format) | \
				 (SPI_Handle->Init.FrameFormat) | (SPI_Handle->Init.BusConfig) | (SPI_Handle->Init.SSM_Cmd);

	SPI_Handle->Instance->CR1 = tempValue;

	SPI_PerihCmd(&SPI_Handle, ENABLE);

}

/**
 * @brief	SPI_PerihCmd, Enable or Disable SPI Peripheral
 *
 * @param	SPI_Handle = User config structure
 *
 * @param	stateOfSPI = ENABLE or DISABLE
 *
 * @retval	void
 */

void SPI_PerihCmd(SPI_HandleTypeDef_t *SPI_Handle, FunctionalState_t stateOfSPI)
{

	if(stateOfSPI != ENABLE)
	{
		SPI_Handle->Instance->CR1 |= (0x1U << SPI_CR1_SPE);
	}else
	{
		SPI_Handle->Instance->CR1 &= ~(0x1U << SPI_CR1_SPE);
	}

}

/**
 * @brief	SPI_TransmitData, Transmits data to the slave
 *
 * @param	SPI_Handle = User config structure
 *
 * @param	pData = Address of data to send
 *
 * @param	sizeOfData = Length of your data in bytes
 *
 * @retval	void
 */

void SPI_TransmitData(SPI_HandleTypeDef_t *SPI_Handle, uint16_t *pData, uint16_t sizeOfData)
{
	if(SPI_Handle->Init.DFF_Format == SPI_DFF_16BITS)
	{
		while(sizeOfData > 0)
		{
			if(SPI_GetFlagStatus(&SPI_Handle, SPI_TXE_FLAG))
			{
				SPI_Handle->Instance->DR = *( (uint16_t*)pData);

				pData += sizeof(uint16_t);
				sizeOfData -= 2; // decrease 2 byte (16bit)
			}
		}
	}else // SPI_DFF_8BITS
	{
		while(sizeOfData > 0)
		{
			if(SPI_GetFlagStatus(&SPI_Handle, SPI_TXE_FLAG))
			{
				SPI_Handle->Instance->DR = *pData;

				pData += sizeof(uint8_t);
				sizeOfData --; // decrease 1 byte (8bit)

			}
		}
	}

	while( SPI_GetFlagStatus(&SPI_Handle, SPI_BSY_FLAG) ); // Wait Busy Flag

}

/**
 * @brief	SPI_GetFlagStatus, Return the flag of SR register
 *
 * @param	SPI_Handle = User config structure
 *
 * @param	SPI_Flag = Flag name of SR register
 *
 * @retval	SPI_FlagStatus_t
 */

SPI_FlagStatus_t SPI_GetFlagStatus(SPI_HandleTypeDef_t *SPI_Handle, uint16_t SPI_Flag)
{

	return ( (SPI_Handle->Instance->SR) & (SPI_Flag) ) ? SPI_FLAG_SET : SPI_FLAG_RESET;

}
