#include "RTOS.h"

RTOS::RTOS() : taskIdCounter(0) {}

void RTOS::createTask(std::function<void()> body, int priority) 
{
    auto task = std::make_shared<Task>(taskIdCounter++, priority, body);
    tasks.push_back(task);
    scheduler.addTask(task);
}

void RTOS::start() 
{
    while (true) 
    {
        tick();
    }
}

void RTOS::tick() 
{
    timer.advanceTicks();
    timer.updateTasks(tasks);

    auto task = scheduler.getNextTask();
    if (task) 
    {
        task->state = TaskState::RUNNING;
        task->body();
        if (task->state == TaskState::RUNNING) 
        {
            task->state = TaskState::READY;
        }
    }

    scheduler.removeFinished();
}

void RTOS::sleep(int ticks) 
{
    for (auto& task : tasks) {

        if (task->state == TaskState::RUNNING) 
        {
            task->sleepTicks = ticks;
            task->state = TaskState::SLEEPING;
            break;
        }
    }
}