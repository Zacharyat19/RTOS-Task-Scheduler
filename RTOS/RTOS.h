#pragma once

#include <vector>
#include <memory>
#include <functional>

#include "Scheduler.h"
#include "Timer.h"

class RTOS 
{
    public:
        RTOS();
        void createTask(std::function<void()> body, int priority);
        void start();
        void tick();
        void sleep(int ticks);

    private:
        Scheduler                          scheduler;
        Timer                              timer;
        std::vector<std::shared_ptr<Task>> tasks;
        int                                taskIdCounter;
};