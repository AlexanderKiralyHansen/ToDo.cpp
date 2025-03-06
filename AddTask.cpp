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
    if (todolist.empty())
        std::cout << " No tasks available.\n";

    else
    {
        std::cout << " Your Todo List:\n";
        for (size_t i=0; i < todolist.size(); i++)
        {
            std::cout << " " << i + 1 << ". \"" << todolist[i].getDescription() << "\" and current status is: ";
            if (todolist[i].getTaskStatus() == true) {
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

void TodoList::completeTask(int taskID, bool status) {
    todolist[taskID].Task::setTaskStatus(status);
}

// Delete task from the list