#include "sensordata.h"

sensordata::sensordata()
{

}

sensordata::sensordata(int rank)
{
    this->rank = rank;
}

//简单移动平均滤波算法，对ADC寄存器滤波
int sensordata::SMA_Filter(int Input)
{
    int i;
    int output = 0;
    for (i = 0; i < Number - 1; i++)
    {
        Filter_Arr[i] = Filter_Arr[i + 1];
        output += Filter_Arr[i];
    }
    Filter_Arr[Number - 1] = Input;
    output += Input;
    output /= Number;
    return (int)output;
}

//根据寄存器获取电压值
void sensordata::get_bat(int bat_uint16)
{
    double bat_float = 0.0;                  //节点电压
    bat_float = bat_uint16 * 3.3 / 32768;   //CC2530ADC测量值，电阻分压之后的值
    bat_float = bat_float * (180+56)/56;              //电池实际电量值
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

//根据寄存器获取电量百分比
void sensordata::get_bat_2()
{
    qDebug()<< 1;
    if(this->bat_uint16 <= 30340 && this->bat_uint16 >= 25935)
    {
        sma_data = SMA_Filter(this->bat_uint16);

        this->bat = (int) 100*(sma_data - 25935)/(30340 - 25935);


//        qDebug()<< "bat_now"<< this->bat;
//        qDebug()<< "bat_min"<< bat_min;

        if(this->bat - bat_min >= 3)
        {
            bat_min = this->bat;   //移除12%这类数据影响
        }
        if(this->bat <= bat_min)   //移除电量会增大的影响
        {
            bat_min = this->bat;
            if(bat_min <= 0)
            {
                bat_min = 100;
            }
        }else{
            this->bat = bat_min;
        }
        qDebug()<< "bat_end"<< this->bat;
    }
}

//防止阿里云物联网掉线跳变
void sensordata::get_state()
{
    if(this->state == 0)
    {
        this->get_state_off++;
        if(this->get_state_off == 2)
        {
            this->state = 0;
            this->get_state_off = 0;
        }
    }
}



