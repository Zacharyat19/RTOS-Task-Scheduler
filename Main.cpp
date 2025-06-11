#include "RTOS/RTOS.h"
#include "Drivers/SensorDriver.h"
#include "Drivers/Communication.h"
#include "HAL/GPIO.h"

int main() 
{
    RTOS rtos;
    MessageQueue queue;
    ADC adc;
    UART uart;
    GPIO gpio;

    SensorDriver sensor(adc, queue);
    Communication comm(uart, queue);

    // Sensor polling task
    rtos.createTask([&]() 
    {
        while (true) 
        {
            sensor.pollSensor();
            rtos.sleep(3);
        }
    }, 1);

    // UART communication task
    rtos.createTask([&]() 
    {
        while (true) {
            comm.transmit();
            rtos.sleep(2);
        }
    }, 1);

    // GPIO toggling task
    rtos.createTask([&]() 
    {
        int pin = 5;
        while (true) 
        {
            gpio.togglePin(pin);
            rtos.sleep(4);
        }
    }, 1);

    rtos.start();

    return 0;
}