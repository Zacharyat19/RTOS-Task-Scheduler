#include "SensorDriver.h"

SensorDriver::SensorDriver(ADC& adc, MessageQueue& mq) : adc(adc), queue(mq) {}

void SensorDriver::pollSensor() 
{
    int value = adc.read(0);
    queue.send(value);
}