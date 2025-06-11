#pragma once

#include <vector>
#include <memory>

#include "Task.h"

class Scheduler 
{
    public:
        std::shared_ptr<Task> getNextTask();
        void                  addTask(std::shared_ptr<Task> task);
        void                  removeFinished();
        void                  setSchedulingPolicy(int policy) { this->policy = policy; }

    private:
        std::vector<std::shared_ptr<Task>> tasks;
        int                                roundRobinIndex = -1;
        int                                policy = 0;
};