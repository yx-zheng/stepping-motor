#include "led.h"
#include "delay.h"
#include "sys.h"
#include "pwm.h"
//ALIENTEK Mini STM32开发板范例代码8
//PWM输出实验   
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司

 int main(void)
 {	
	u16 pwmval=300;    
//	u8 dir=1;	
	delay_init();	    	 //延时函数初始化	  
	LED_Init();		  	//初始化与LED连接的硬件接口
	TIM1_PWM_Init(719,9);//PWM频率=72000/(720*10)=10Khz 
	TIM_SetCompare1(TIM1,pwmval);
   	while(1)
	{
 		delay_ms(300);	 	   					 
		LED1 = 0; 
		delay_ms(300);
		LED1 = 1;
	} 
}

