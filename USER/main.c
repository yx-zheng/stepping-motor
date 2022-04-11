#include "led.h"
#include "delay.h"
#include "sys.h"
#include "pwm.h"
#include "key.h"
//ALIENTEK Mini STM32开发板范例代码8
//PWM输出实验   
//技术支持：www.openedv.com
//广州市星翼电子科技有限公司

 int main(void)
 {	
	u16 pwmval=300;    
	u8 t=0;	
	delay_init();	    	 //延时函数初始化	  
	IO_Init();		  	//初始化与LED连接的硬件接口
	KEY_Init();				//key init
	TIM1_PWM_Init(719,9);//PWM频率=72000/(720*10)=10Khz 
	ENA = 0;
	delay_us(10);
	TIM_SetCompare1(TIM1,pwmval);
   	while(1)
	{
 				t=KEY_Scan(1);		//得到键值
		switch(t)
		{				 
			case KEY0_PRES:
				ENA = 1;
				DIR = 0;
				delay_ms(100);
				ENA = 0;
				break;
			case KEY1_PRES:
				ENA = 1;
				DIR = 1;
				delay_ms(100);
				ENA = 0;	
				break;
//			case WKUP_PRES:				
//				break;
			default:
				delay_ms(10);	
		}
	} 
}
	

