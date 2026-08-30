/*
 * Flash_STMF1.h
 *
 *  Created on: Aug 20, 2026
 *      Author: TaThuan
 */

#ifndef INC_FLASH_STM32_F1
#define INC_FLASH_STM32_F1

#include "stdlib.h"
#include "stdint.h"
#include "stm32f1xx_hal.h"
#ifdef __cplusplus
extern "C" {
#endif

#define Flash_Publish(type) type
#define Flash_Private(type) static type

typedef struct {
	volatile uint32_t ACR;
	volatile uint32_t KEYR;
	volatile uint32_t OPTKEYR;

	volatile uint32_t SR;
	volatile uint32_t CR;
	volatile uint32_t AR;
	volatile uint32_t Reserved;
	volatile uint32_t OBR;
	volatile uint32_t WRPR;
}Flash_Types;

#define Flash_BaseADDR 0x40022000UL
#define Flash 		((Flash_Types *) Flash_BaseADDR)

#define FLASH_MEMORY_BASE 0x08000000UL
#define FLASH_PAGE_SIZE_   0x400UL
#define Page_ADDR(number) (FLASH_MEMORY_BASE + number * FLASH_PAGE_SIZE_)



Flash_Publish(void) Flash_Unlock(void);
Flash_Publish(void) Flash_Lock(void);
Flash_Publish(void) Flash_EraseSector(uint32_t Sector);
Flash_Publish(void) Flash_EraseAll(void);
Flash_Publish(void) Flash_ProgramHalfWord(uint32_t Address,uint16_t Data);
Flash_Publish(void) Flash_ProgramWord(uint32_t Address,uint32_t Data);


Flash_Publish(void) JumpToApplication(uint32_t App_Address);
#ifdef __cplusplus
}
#endif



#endif
