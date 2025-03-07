#ifndef ADDTASK_HPP
#define ADDTASK_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Task.hpp"


//Manages all tasks
class TodoList
{
    private:
        std::vector<Task> todolist; //Stores all tasks
        const std::string filename = "Tasks.csv"; //File stores tasks
        


    public:
        TodoList(); //Constructor: Loads tasks from file
        void addTask(const std::string& taskDesc);  // Adds a task to the todolist
        void showTasks() const;                     // Displays all tasks in the todolist
        void saveTasks() const;                     // Saves all tasks to a file
        void loadTasks();                           // Loads tasks from a file
        void completeTask(int taskID, bool status); // Mark a task as complete or incomplete
        void renameTask(int taskID);                // Rename a given task
        //void deleteTask(int taskIndex); // Method for deleting tasks

};

#endif