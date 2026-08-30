/*
 * program.c
 *
 *  Created on: Aug 11, 2026
 *      Author: TaThuan
 */
#include "program.h"
#include "main.h"
#include "Flash_STMF1.h"

#define APP1_ADDRESS    0x08002000U
#define APP2_ADDRESS    0x08004800U


void khoitao(void){
//	Flash_EraseSector(31);
//	Flash_ProgramWord(0x08007C00,0x12345678);
	if(HAL_GPIO_ReadPin(Btn_GPIO_Port, Btn_Pin) == 0 ){
		JumpToApplication(APP1_ADDRESS); // blink Led 1 Hz
	}else {
		JumpToApplication(APP2_ADDRESS); // blink Led 10 Hz

	}


}
void chuongtrinhchinh(void){


}
