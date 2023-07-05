#ifndef __ADC_H__
#define __ADC_H__

#include <ioCC2530.h>
#include <string.h>
#include <stdio.h>

#define uint8 unsigned char
#define uint16 unsigned short
#define uint32 unsigned long
 
void Init_ADC0(void);
void Init_P06(void);
uint16 Get_ADC(void);
uint8 Get_P06(void);


#endif

