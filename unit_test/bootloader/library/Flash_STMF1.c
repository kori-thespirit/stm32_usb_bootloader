/*
 * Flash_STMF1.c
 *
 *  Created on: Aug 20, 2026
 *      Author: TaThuan
 */
#include "Flash_STMF1.h"

typedef void (*pFunction)(void);

Flash_Publish(void) Flash_Unlock(void){
    if ((Flash->CR & (1 << 7)) != 0)
    {
        Flash->KEYR = 0x45670123;
        Flash->KEYR = 0xCDEF89AB;
    }
}
Flash_Publish(void) Flash_Lock(void){
	Flash->CR |= (1 << 7);
}
Flash_Publish(void) Flash_EraseSector(uint32_t Sector){
	Flash_Unlock();
	while(Flash->SR & (1 << 0)); // kiểm tra thanh ghi status register xem có hành động nào xảy ra kh ?

//	if(Flash->CR & (1 << 7) != 0) // kiểm tra key đã được unlock
	Flash->CR |= (1 << 1);  // đưa thanh ghi CR bit PER để tiến hanh xóa từng sector
	Flash->AR = Page_ADDR(Sector); // đưa địa chỉ Page vào thanh ghi AR
	Flash->CR |= (1 << 6); // dua bit STRT len 1
	while(Flash->SR & (1 << 0));

	Flash->CR &= ~(1 << 1);
	Flash_Lock();
}
Flash_Publish(void) Flash_ProgramHalfWord(uint32_t Address,uint16_t Data){
	Flash_Unlock();
	while (Flash->SR & (1 << 0));

	Flash->CR |= (1 << 0); // đưa bit PG lên 1 để tiến hành lập trình

	*(volatile uint16_t *)Address = Data; //
	while (Flash->SR & (1 << 0));

	Flash->CR &= ~(1 << 0);
	Flash_Lock();

}
Flash_Publish(void) Flash_ProgramWord(uint32_t Address,uint32_t Data){
	Flash_Unlock();
	while (Flash->SR & (1 << 0));
	Flash->CR |= (1 << 0); // đưa bit PG lên 1 để tiến hành lập trình
	*(volatile uint16_t *)Address = (uint16_t)(Data & 0xFFFF);
	while (Flash->SR & (1 << 0));

	*(volatile uint16_t *)(Address + 2) = (uint16_t)(Data >> 16);
	while (Flash->SR & (1 << 0));

	Flash->CR &= ~(1 << 0);
	Flash_Lock();

}


Flash_Publish(void) JumpToApplication(uint32_t App_Address)
{
    // Disable all interrupts
    __disable_irq();
    SysTick->CTRL = 0;
    SysTick->LOAD = 0;
    SysTick->VAL = 0;
    // Clear pending interrupt requests for fault handlers
    SCB->SHCSR &= ~(SCB_SHCSR_USGFAULTENA_Msk |
                    SCB_SHCSR_BUSFAULTENA_Msk |
                    SCB_SHCSR_MEMFAULTENA_Msk);
    // Set the main stack pointer
    __set_MSP(*(uint32_t *)App_Address);
    // Read New Reset_Handler from Offset 4 of New Application
    void * pNewResetAddress = *((uint32_t*)(App_Address + 4));
    // Create a function pointer to the new application's reset handler
    void (*pNewAppResetHandler)(void) = (void*)(pNewResetAddress);
    // Jump to the new application's reset handler
    pNewAppResetHandler();
}

