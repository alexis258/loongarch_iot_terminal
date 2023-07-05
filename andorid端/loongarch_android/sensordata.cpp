#include "sensordata.h"

sensordata::sensordata()
{

}

sensordata::sensordata(int rank)
{
    this->rank = rank;
}

//根据寄存器获取电压值
void sensordata::get_bat(int bat_uint16)
{
    double bat_float = 0.0;                  //节点电压
    bat_float = bat_uint16 * 3.3 / 32768;   //CC2530ADC测量值，电阻分压之后的值
    bat_float = bat_float * 4;              //电池实际电量值
    float bat_per = 0;
    if(bat_float >= BAT_MIN_V)
    {
        bat_per = (bat_float - BAT_MIN_V)/(BAT_MAX_V - BAT_MIN_V);
    }
    this->bat = (int) bat_per * 100;
}

sensordata::~sensordata()
{

}



