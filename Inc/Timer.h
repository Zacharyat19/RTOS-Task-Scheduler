#pragma once

#include <vector>
#include <memory>

#include "Task.h"

class Timer 
{
    public:
        void advanceTicks();
        void updateTasks(std::vector<std::shared_ptr<Task>>& tasks);
        int  getTick() const;

    private:
        int currentTick = 0;
};
