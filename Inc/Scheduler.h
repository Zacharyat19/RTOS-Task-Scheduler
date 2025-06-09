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
        void                  setSchedulingPolicy(int policy);

    private:
        std::vector<std::shared_ptr<Task>> taskQueue;
        size_t                             roundRobinIndex = 0;
        int                                currentPolicy = 0;
};
