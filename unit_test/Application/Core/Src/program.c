/*
 * program.c
 *
 *  Created on: Aug 25, 2026
 *      Author: TaThuan
 */
#include "program.h"
#include "main.h"

void khoitao(void){

	  HAL_GPIO_WritePin(LEDC_GPIO_Port, LEDC_Pin, GPIO_PIN_RESET);

}
void chuongtrinhchinh(void){

	static uint32_t delay = 0;
	if(HAL_GetTick() - delay >= 100){
		delay = HAL_GetTick();
		HAL_GPIO_TogglePin(LEDC_GPIO_Port, LEDC_Pin);

	}
}
