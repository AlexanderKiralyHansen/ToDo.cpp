#ifndef TASK_HPP
#define TASK_HPP

#include <string>

//Single task
class Task
{
    public:
        Task(std::string desc);     //Constructor initialize task
        std::string getDescription() const;
        bool getTaskStatus() const;

    private:
        std::string description;    //Stores task description
        bool isTaskDone;            // Stores whether the task is done
};

#endif