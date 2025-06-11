#include "Communication.h"

Communication::Communication(UART& uart, MessageQueue& mq) : uart(uart), queue(mq) {}

void Communication::transmit() 
{
    int msg;
    if (queue.receive(msg)) 
    {
        uart.send("Sensor value: " + std::to_string(msg));
    }
}