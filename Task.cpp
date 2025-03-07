#include "Task.hpp"

// Constructor, initialize task with description and set the task to not done by default
Task::Task(std::string desc) {
    description = desc;
    isTaskDone = false; // Default is not done
}

// Constructor for loading tasks from file
Task::Task(std::string desc, bool status) {
    description = desc;
    isTaskDone = status;
}

std::string Task::getDescription() const {  // Getter for name of task
    return description;
}

bool Task::getTaskStatus() const {  // Getter for task status
    return isTaskDone;
}

void Task::setTaskStatus(bool status) { // Setter for the status of a task
    isTaskDone = status;
} 

void Task::setDescription(std::string newDescription) { // Setter for description of task
    description = newDescription;
}