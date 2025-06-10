#pragma once

#include <queue>
#include <mutex>

class MessageQueue 
{
    public:
        void send(int message);
        bool receive(int& message);

    private:
        std::queue<int> queue;
        std::mutex mtx;
};