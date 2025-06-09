#pragma once

#include <functional>

enum class TaskState 
{
    READY,
    RUNNING,
    BLOCKED,
    SLEEPING,
    FINISHED
};

struct Task 
{
    int                   id;
    int                   priority;
    int                   sleepTicks;  
    TaskState             state;
    std::function<void()> body;

    Task(int id, int priority, std::function<void()> func);
};
