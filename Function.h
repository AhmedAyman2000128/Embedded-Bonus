#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "string.h"
#define RED 0x02
#define BLUE 0x04
#define GREEN 0x08
#define CR 0x0D
void Led_Init(void){
	SYSCTL_RCGCGPIO_R |=0x00000020;
	while((SYSCTL_PRGPIO_R & 0x20)==0){}
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R|= 0x0E;
	GPIO_PORTF_AFSEL_R &= ~ 0x0E;
	GPIO_PORTF_AMSEL_R &= ~ 0x0E;
	GPIO_PORTF_PCTL_R &= ~ 0x0000FFF0;
	GPIO_PORTF_DEN_R |= 0x0E;
	GPIO_PORTF_DIR_R |= 0x0E;
	GPIO_PORTF_DATA_R &=~0x0E;
}
void Output(unsigned char data){
	GPIO_PORTF_DATA_R&=~0x0E;
	GPIO_PORTF_DATA_R|=data;
}
void clear(unsigned char data){
	GPIO_PORTF_DATA_R&=data;
}
void sysTick_Init()
{
	NVIC_ST_CTRL_R=0;
	NVIC_ST_RELOAD_R=0x00ffffff;
	NVIC_ST_CURRENT_R=0;
	NVIC_ST_CTRL_R=0x05;
}
void sys_Wait(){
	NVIC_ST_RELOAD_R=16000-1;
	
	NVIC_ST_CURRENT_R=0;
	while((NVIC_ST_CTRL_R&0x10000)==0){};
}
void timeDelay(int time){
	int i;
	for(i=0;i<time;i++)
	{
		sys_Wait();
	}
}

