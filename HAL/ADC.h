#pragma once

class ADC 
{
    public:
        int read(int channel) { return channel * 100; }
};