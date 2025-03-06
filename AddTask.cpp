#include "AddTask.hpp"


//Constructor, loads existing tasks from file
TodoList::TodoList()
{
    loadTasks();
}

//Adds task to list and saves to file
void TodoList::addTask(const std::string& taskDesc)
{
    todolist.push_back(Task(taskDesc));
    saveTasks(); //Add task to vector
    std::cout << " Task added:" << taskDesc << "\n"; //Save tasks to file
}

//Display current todo list
void TodoList::showTasks() const
{
    if (todolist.empty())   // Incase there are no tasks, no need to print them
        std::cout << " No tasks available.\n";

    else
    {
        std::cout << " Your Todo List:\n";
        for (size_t i=0; i < todolist.size(); i++)  // For loop to go through the entire todolist vector and print each object
        {
            std::cout << " " << i + 1 << ". \"" << todolist[i].getDescription() << "\" and current status is: ";    // Print the description of the task
            if (todolist[i].getTaskStatus() == true) {  // If statement to print a word and not 1 or 0 as the status 
                std::cout << "\"Complete\"" << std::endl;
            } else {
                std::cout << "\"Incomplete\"" << std::endl;
            }
        }
    }
}

//Save tasks to file
void TodoList::saveTasks() const
{
    std::ofstream file(filename); //Open file for writing
    for (const Task& task : todolist)
    {
        file << task.Task::getDescription() << "\n"; //Write task to new line
    }
}

//Load tasks from file into memory
void TodoList::loadTasks()
{
    std::ifstream file(filename); //Open file for reading
    std::string taskDesc;
    while (getline(file,taskDesc)) //Read all task lines
    {
        todolist.push_back(Task(taskDesc)); //Add task to list
    }
}

void TodoList::completeTask(int taskID, bool status) {  // Method to change completion status of a given task
    todolist[taskID].Task::setTaskStatus(status);       
}

// Delete task from the list