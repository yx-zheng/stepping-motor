#include "led.h"
#include "delay.h"
#include "sys.h"
#include "pwm.h"
#include "key.h"
//ALIENTEK Mini STM32�����巶������8
//PWM���ʵ��   
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾

 int main(void)
 {	
	u16 pwmval=300;    
	u8 t=0;	
	delay_init();	    	 //��ʱ������ʼ��	  
	IO_Init();		  	//��ʼ����LED���ӵ�Ӳ���ӿ�
	KEY_Init();				//key init
	TIM1_PWM_Init(719,9);//PWMƵ��=72000/(720*10)=10Khz 
	ENA = 0;
	delay_us(10);
	TIM_SetCompare1(TIM1,pwmval);
   	while(1)
	{
 				t=KEY_Scan(1);		//�õ���ֵ
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
	

