#include "led.h"
#include "delay.h"
#include "sys.h"
#include "pwm.h"
//ALIENTEK Mini STM32�����巶������8
//PWM���ʵ��   
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾

 int main(void)
 {	
	u16 pwmval=300;    
//	u8 dir=1;	
	delay_init();	    	 //��ʱ������ʼ��	  
	LED_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
	TIM1_PWM_Init(719,9);//PWMƵ��=72000/(720*10)=10Khz 
	TIM_SetCompare1(TIM1,pwmval);
   	while(1)
	{
 		delay_ms(300);	 	   					 
		LED1 = 0; 
		delay_ms(300);
		LED1 = 1;
	} 
}

