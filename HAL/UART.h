#pragma once

#include <string>

class UART 
{
    public:
        void        send(const std::string& data);
        std::string receive();

    private:
        std::string rxBuffer;
};