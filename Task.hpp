#ifndef TASK_HPP
#define TASK_HPP

#include <string>

//Single task
class Task
{
    public:
        Task(std::string desc);     //Constructor initialize task
        Task(std::string desc, bool status);// Constructor for loading tasks from file
        std::string getDescription() const; // Getter for task name
        bool getTaskStatus() const;         // Getter for task status
        void setTaskStatus(bool status);    // Setter for task status
        void setDescription(std::string newDescription);

    private:
        std::string description;    //Stores task description
        bool isTaskDone;            // Stores whether the task is done
};

#endif