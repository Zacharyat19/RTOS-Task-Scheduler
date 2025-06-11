#include "Task.h"

Task::Task(int id, int priority, std::function<void()> func) : 
id(id), priority(priority), state(TaskState::READY), sleepTicks(0), body(func) {}