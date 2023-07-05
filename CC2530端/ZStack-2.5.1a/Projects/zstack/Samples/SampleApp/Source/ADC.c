#include "ADC.h"

void Init_ADC0(void)
{
    P0SEL  |= 0x01; 
    P0DIR  &= ~0x01; 
    APCFG  |= 0x01;        //p0_0允许使用模拟IO,检测电压由此检测电量
}

void Init_P06(void)
{
    P0SEL  |= 0x40; 
    P0DIR  &= ~0x40; 
    
}

uint16 Get_ADC(void)
{
    uint16 value;

    ADCIF = 0;            //清ADC 中断标志,采用基准电压avdd5:3.3V，通道0，启动AD转化

    ADCCON3 = (0x80 | 0x10 | 0x00);

    while ( !ADCIF )
    {
		
      ;  //等待AD转化结束
	
    }

    value = ADCH;

    value = value<< 8;

    value |= ADCL;              // AD值转化成电压值,0 表示 0V ，32768 表示 3.3V
	
//    value = (value * 330);      //电压值 = (value*3.3)/32768 （V)
//
//    value = value >> 15;        // 除以32768
	
    return value;       // 返回分辨率为0.01V的电压值
	

}

uint8 Get_P06(void)
{
    if(P0_6 == 0)
    {
      return 0;
    }else{
      return 1;
    }
}


