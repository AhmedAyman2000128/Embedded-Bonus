#include "stdint.h"
#include "C:/Keil/EE319Kware/inc/tm4c123gh6pm.h"
#include "string.h"
#include "Function.h" //contain initilizations for initializations
#define RED 0x02
#define BLUE 0x04
#define GREEN 0x08
unsigned long x=0x02;
void SystemInit(){}
	
	//Ahmed Ayman Abd El Fatah 2000128
	
	int main(){
		Led_Init();
		sysTick_Init();
		while(1){
			Output(x);
			x=x+2;
			if(x==0x10)
			{
				x=0x02;
			}
			timeDelay(1000);
			clear(~0x0E);
		}
	}
