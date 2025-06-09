#pragma once

#include "Scheduler.h"
#include "Timer.h"

class RTOS 
{
    public:
        RTOS();
        void createTask(std::function<void()> body, int priority);
        void start();
        void sleep(int ticks);
        void tick();

    private:
        Scheduler scheduler;
        Timer     timer;
        int       taskIdCounter = 0;
};
