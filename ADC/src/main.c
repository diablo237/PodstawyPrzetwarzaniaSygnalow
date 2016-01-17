/**
  ******************************************************************************
  * @file    Project/STM32F4xx_StdPeriph_Templates/main.c 
  * @author  
  * @version 
  * @date    06-March-2015
  * @brief   Main program body
  ******************************************************************************
  * @attention
  ******************************************************************************
  */

#include "main.h"
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_adc.h"
#include "stm32f4xx_dma.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_tim.h"

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
void _GPIO_Init(void) {
GPIO_InitTypeDef	GPIO_InitStructure;

/*Enabling GPIO clock*/	
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

/*GPIO PA5 configuration*/	
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

/*GPIO PA5 configuration*/		
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AN;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
}


void _ADC_Init(void) {
ADC_InitTypeDef ADC_InitStructure;
ADC_CommonInitTypeDef ADC_CommonInitStruct;
		
/*Enabling ADC clock*/
RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);
RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC2, ENABLE);
	
/*ADC1 configuration*/
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_NbrOfConversion = 2;
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_10b;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE; 
	ADC_Init(ADC1,&ADC_InitStructure);
	
/*ADC2 configuration*/
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConvEdge_None;
	ADC_InitStructure.ADC_NbrOfConversion = 2;
	ADC_InitStructure.ADC_Resolution = ADC_Resolution_10b;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE; 
	ADC_Init(ADC2,&ADC_InitStructure);

/*ADC common init configuration for Multi mode ADC*/
	ADC_CommonInitStruct.ADC_Mode = ADC_DualMode_RegSimult;
	ADC_CommonInitStruct.ADC_DMAAccessMode = //ADC_DMAAccessMode_Disabled; ADC_DMAAccessMode_1; ADC_DMAAccessMode_2; ADC_DMAAccessMode_3 
	ADC_CommonInitStruct.ADC_Prescaler = //ADC_Prescaler_Div2; ADC_Prescaler_Div4; ADC_Prescaler_Div6; ADC_Prescaler_Div8
	ADC_CommonInitStruct.ADC_TwoSamplingDelay = ADC_TwoSamplingDelay_5Cycles; //ADC_TwoSamplingDelay_5Cycles - i tak dalej po 1 do 20 cykli	

/*Enabling ADC*/	
	ADC_Cmd(ADC1, ENABLE);
	ADC_Cmd(ADC2, ENABLE);

/*Regular channels config*/
	ADC_RegularChannelConfig(ADC1,ADC_Channel_1,1,ADC_SampleTime_144Cycles);
	ADC_RegularChannelConfig(ADC2,ADC_Channel_2,1,ADC_SampleTime_144Cycles);

/*Activating continuous mode*/
	ADC_ContinuousModeCmd(ADC1, ENABLE);
	ADC_ContinuousModeCmd(ADC2, ENABLE);

/*DMA for Multi mode ADC*/
	ADC_MultiModeDMARequestAfterLastTransferCmd(ENABLE);
	
/*Reading the ADCs converted values*/	
	ADC_GetMultiModeConversionValue();
}
int main(void) {
	
  /* Infinite loop */
  while (1)
  {
  }
}



#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line) { 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1) {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
