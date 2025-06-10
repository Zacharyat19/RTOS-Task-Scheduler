#pragma once

class GPIO 
{
    public:
        void setPinHigh(int pin);
        void setPinLow(int pin);
        void togglePin(int pin);
        bool getPinState(int pin) const;

    private:
        bool pinStates[32] = {false};
};