#include "Timer.h"

void Timer::advanceTicks()
{
    ++ticks;
}

void Timer::updateTasks(std::vector<std::shared_ptr<Task>>& tasks)
{
    for (auto& task : tasks) 
    {
        if (task->state == TaskState::SLEEPING) 
        {
            --task->sleepTicks;
            if (task->sleepTicks <= 0) 
            {
                task->state = TaskState::READY;
            }
        }
    }
}