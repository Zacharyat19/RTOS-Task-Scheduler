#pragma once

#include <vector>
#include <memory>

#include "Task.h"

class Timer 
{
    public:
        void advanceTicks();
        void updateTasks(std::vector<std::shared_ptr<Task>>& tasks);
        int  getTick() const { return ticks; }

    private:
        int ticks = 0;
};