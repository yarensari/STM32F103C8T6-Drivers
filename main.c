#include "../myDrivers/Inc/stm32f103xx.h"
#include <string.h>
#include <stdint.h>

static void GPIO_LedConfig();
static void GPIO_ButtonInterrupt_Config();
static void SPI_Config();
static void SPI_GPIO_Config();

SPI_HandleTypeDef_t SPI_Handle;

void EXTI1_IRQHandler()
{
	char msgToSend[] = "Hello World!\n";

	if(EXTI->PR & 0x2)
	{
		EXTI->PR |= (0x1U << 1U);
		SPI_TransmitData(&SPI_Handle, (uint8_t*)msgToSend, strlen(msgToSend) );
	}

}

int main(void)
{
	GPIO_LedConfig();
	GPIO_ButtonInterrupt_Config();

	SPI_GPIO_Config();
	SPI_Config();

	for(;;)
	{

	}

}

static void GPIO_LedConfig()
{
	GPIO_InitTypeDef_t GPIO_InitStruct = { 0 };

	RCC_GPIOC_CLK_ENABLE();
	RCC_GPIOA_CLK_ENABLE();

	GPIO_InitStruct.pinNumber = GPIO_PIN_13;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT;
	GPIO_InitStruct.OTYPE = GPIO_OTYPE_PP;
	GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
	GPIO_InitStruct.PuPd = GPIO_PUPD_NOPULL;

	GPIO_Init(GPIOC, &GPIO_InitStruct);

	memset(&GPIO_InitStruct, 0, sizeof(GPIO_InitStruct) );

	GPIO_InitStruct.pinNumber = GPIO_PIN_1;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.PuPd = GPIO_PUPD_PULLDOWN;

	GPIO_Init(GPIOA, &GPIO_InitStruct);

}

static void GPIO_ButtonInterrupt_Config()
{
	RCC_AFIO_CLK_ENABLE();

	EXTI_InitTypeDef_t EXTI_Struct = { 0 };

	EXTI_LineConfig(EXTI_PortSource_GPIOA, EXTI_LineSource_1);

	EXTI_Struct.EXTI_LineCmd = ENABLE;
	EXTI_Struct.EXTI_LineNumber = EXTI_LineSource_1;
	EXTI_Struct.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_Struct.TriggerSelection = EXTI_Trigger_Rising;

	EXTI_Init(&EXTI_Struct);

	NVIC_EnableInterrupt(EXTI1_IRQNumber);

}

static void SPI_Config()
{
	RCC_SPI1_CLK_ENABLE();

	SPI_Handle.Instance = SPI1;

	SPI_Handle.Init.BaudRate    = SPI_BAUDRATE_DIV8;
	SPI_Handle.Init.BusConfig   = SPI_BUS_FULLDUPLEX;
	SPI_Handle.Init.CPHA 	    = SPI_CPHA_FIRST;
	SPI_Handle.Init.CPOL 		= SPI_CPOL_LOW;
	SPI_Handle.Init.DFF_Format  = SPI_DFF_8BITS;
	SPI_Handle.Init.FrameFormat = SPI_FRAMEFORMAT_MSB;
	SPI_Handle.Init.Mode 	    = SPI_MODE_MASTER;
	SPI_Handle.Init.SSM_Cmd 	= SPI_SSM_ENABLE;


	SPI_Init(&SPI_Handle);

	SPI_PerihCmd(&SPI_Handle, ENABLE);

}

static void SPI_GPIO_Config()
{
	GPIO_InitTypeDef_t GPIO_InitStruct = { 0 };

	GPIO_InitStruct.pinNumber = GPIO_PIN_5 | GPIO_PIN_7; // PA5: SCK - PA7 : MOSI
	GPIO_InitStruct.Mode 	  = GPIO_MODE_AF;
	GPIO_InitStruct.OTYPE     = GPIO_OTYPE_PP;
	GPIO_InitStruct.PuPd 	  = GPIO_PUPD_NOPULL;
	GPIO_InitStruct.Speed 	  = GPIO_SPEED_HIGH;

	GPIO_Init(GPIOA, &GPIO_InitStruct);

}


