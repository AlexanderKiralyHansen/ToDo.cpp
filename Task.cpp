#include "Task.hpp"

// Constructor, initialize task with description and set the task to not done by default
Task::Task(std::string desc)
{
    description = desc;
    isTaskDone = false;
}

std::string Task::getDescription() const {
    return(description);
}

bool Task::getTaskStatus() const {
    return(isTaskDone);
}