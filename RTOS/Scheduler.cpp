#include "Scheduler.h"

std::shared_ptr<Task> Scheduler::getNextTask()
{
    if (policy == 0) 
    {
        for (size_t i = 0; i < tasks.size(); ++i) 
        {
            roundRobinIndex = (roundRobinIndex + 1) % tasks.size();
            if (tasks[roundRobinIndex]->state == TaskState::READY) 
            {
                return tasks[roundRobinIndex];
            }
        }
    } 
    else if (policy == 1) 
    {
        std::shared_ptr<Task> best = nullptr;
        for (auto& task : tasks) 
        {
            if (task->state == TaskState::READY && (!best || task->priority > best->priority)) 
            {
                best = task;
            }
        }

        return best;
    }

    return nullptr;
}

void Scheduler::addTask(std::shared_ptr<Task> task)
{
    tasks.push_back(task);
}

void Scheduler::removeFinished()
{
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [](const std::shared_ptr<Task>& task) 
    {
        return task->state == TaskState::FINISHED;
    }), tasks.end());
}