
/*
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
class Task
{
	public:
	std::string _description;
	Task(std::string description){
		_description = description;
	}
};

class TodoList
{
	
	public:
	std::vector<Task> todolist;
	TodoList(){}
};

int main() {

    TodoList todo = TodoList();

    return 0;
}*/

#include "AddTask.hpp"

int main()
{
	TodoList todo;

	while (true)
	{
		std::cout << "\n1. Add Task\n2. Show Tasks\n3. Exit\n Choose an option: ";
		int choice;
		std::cin >> choice;
		std::cin.ignore(); // Cleear input buffer

		if (choice == 1)
		{
			std::cout << "Enter task description: ";
			std::string taskDesc;
			getline(std::cin, taskDesc);
			todo.addTask(taskDesc);
		}

		else if (choice == 2)
		{
			todo.showTasks();
		}

		else if (choice == 3)
		{
			std::cout << "Exiting program...\n";
		}
		
		else
		{
			std::cout << "Invalid choice. Please try again.\n";
		}
	}

	return 0;
}