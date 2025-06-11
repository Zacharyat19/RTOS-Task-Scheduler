#include "MessageQueue.h"

void MessageQueue::send(int message) 
{
    std::lock_guard<std::mutex> lock(mtx);
    queue.push(message);
}

bool MessageQueue::receive(int& message) 
{
    std::lock_guard<std::mutex> lock(mtx);
    if (!queue.empty()) 
    {
        message = queue.front();
        queue.pop();
        return true;
    }
    
    return false;
}