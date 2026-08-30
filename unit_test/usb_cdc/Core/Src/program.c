/*
 * program.c
 *
 *  Created on: Aug 30, 2026
 *      Author: TaThuan
 */
/**/
#include "stdint.h"
uint8_t TxBuffer[] = "Hello World! From STM32 USB CDC Device To Virtual COM Port\r\n";
uint8_t TxBufferLen = sizeof(TxBuffer);

void khoitao(void){
}
void chuongtrinhchinh(void){
	static uint32_t tick = 0 ;
	if(HAL_GetTick() - tick >= 3000){
		tick = HAL_GetTick();
		CDC_Transmit_FS(TxBuffer, TxBufferLen);
	}
}

