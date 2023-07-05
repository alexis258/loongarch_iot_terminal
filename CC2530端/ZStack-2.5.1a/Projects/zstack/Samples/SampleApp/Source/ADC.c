#include "ADC.h"

void Init_ADC0(void)
{
    P0SEL  |= 0x01; 
    P0DIR  &= ~0x01; 
    APCFG  |= 0x01;        //p0_0����ʹ��ģ��IO,����ѹ�ɴ˼�����
}

void Init_P06(void)
{
    P0SEL  |= 0x40; 
    P0DIR  &= ~0x40; 
    
}

uint16 Get_ADC(void)
{
    uint16 value;

    ADCIF = 0;            //��ADC �жϱ�־,���û�׼��ѹavdd5:3.3V��ͨ��0������ADת��

    ADCCON3 = (0x80 | 0x10 | 0x00);

    while ( !ADCIF )
    {
		
      ;  //�ȴ�ADת������
	
    }

    value = ADCH;

    value = value<< 8;

    value |= ADCL;              // ADֵת���ɵ�ѹֵ,0 ��ʾ 0V ��32768 ��ʾ 3.3V
	
//    value = (value * 330);      //��ѹֵ = (value*3.3)/32768 ��V)
//
//    value = value >> 15;        // ����32768
	
    return value;       // ���طֱ���Ϊ0.01V�ĵ�ѹֵ
	

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


