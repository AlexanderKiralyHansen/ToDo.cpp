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
        file << task.Task::getDescription() << "," << task.Task::getTaskStatus() << "\n"; //Write task to new line
    }
    file.close();
}

//Load tasks from file into memory
void TodoList::loadTasks()
{
    std::ifstream file(filename); //Open file for reading
    std::string currentLine;

    while (getline(file, currentLine)) {        // While file still has a line with a task, read the next
        std::vector <std::string> fileData;     // Vector to store data when split

        std::stringstream toSplit(currentLine); // Creates a stream with the input of the read line, this allows the getline to be used on it
        while (toSplit.good()){                 // As long as we get new data, repeat
            std::string tmpStorage;             // Tmp variable, this is the output of the getline
            getline(toSplit, tmpStorage,',');   // Check the line until a "," is met, then stop there
            fileData.push_back(tmpStorage);     // Pushback the line before the ","
        }
        todolist.push_back(Task(fileData[0], stoi(fileData[1]))); //Add task to list
        fileData.clear();   // Clear the vector so we dont have garbage
    }
}

void TodoList::completeTask(int taskID, bool status) {  // Method to change completion status of a given task
    todolist[taskID].Task::setTaskStatus(status);
    saveTasks();       
}

void TodoList::renameTask(int taskID) {
    std::string newDescription;
    std::cout << "What would you like to rename task: "<< taskID << std::endl;
    getline(std::cin, newDescription);
    todolist[taskID-1].setDescription(newDescription);
    saveTasks();
}