#include "GPIO.h"

void GPIO::setPinHigh(int pin) 
{
    if (pin >= 0 && pin < 32) 
    {
        pinStates[pin] = true;
    }
}

void GPIO::setPinLow(int pin) 
{
    if (pin >= 0 && pin < 32) 
    {
        pinStates[pin] = false;
    }
}

void GPIO::togglePin(int pin) 
{
    if (pin >= 0 && pin < 32) 
    {
        pinStates[pin] = !pinStates[pin];
    }
}

bool GPIO::getPinState(int pin) const 
{
    return (pin >= 0 && pin < 32) ? pinStates[pin] : false;
}