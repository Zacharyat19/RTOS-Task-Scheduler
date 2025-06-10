#pragma once

#include "../HAL/UART.h"
#include "../Utils/MessageQueue.h"

class Communication 
{
    public:
        Communication(UART& uart, MessageQueue& mq);
        void transmit();

    private:
        UART& uart;
        MessageQueue& queue;
};