#pragma once

#include "../HAL/ADC.h"
#include "../Utils/MessageQueue.h"

class SensorDriver 
{
    public:
        SensorDriver(ADC& adc, MessageQueue& mq);
        void pollSensor();

    private:
        ADC&          adc;
        MessageQueue& queue;
};