#pragma once

#include <functional>

enum class TaskState { READY, RUNNING, SLEEPING, FINISHED };

class Task 
{
    public:
        Task(int id, int priority, std::function<void()> func);
        
        int                   id;
        int                   priority;
        int                   sleepTicks;
        TaskState             state;
        std::function<void()> body;
};