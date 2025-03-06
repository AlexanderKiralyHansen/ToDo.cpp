#include "AddTask.hpp"
#include "Task.hpp"

int main()
{
	TodoList todo; //Create todolist object
	std::string userInput;

	while (true)
	{
		std::cout << "\n 1. Add task \n 2. Show tasks \n 3. Complete a task \n 4. Uncomplete a task\n 5. Exit \n Choose an option: " << std::endl;
		getline(std::cin, userInput);
		int choice;
		choice = stoi(userInput);
		/*std::cin >> choice;
		std::cin.ignore(); // Clear input buffer*/

		if (choice == 1) {
			std::cout << " Enter task description: ";
			getline(std::cin, userInput); //Get task description
			todo.addTask(userInput); //Add task to todolist
		}

		else if (choice == 2) {
			todo.showTasks(); //Display all tasks
		}

		else if (choice == 3) {
			todo.showTasks(); // Print all tasks with id number to make it easier for the user to select the right one
			std::cout << "\n What task would you like to mark as completed? Input the id number" << std::endl;
			getline(std::cin, userInput);
			todo.completeTask(stoi(userInput)-1, true);
		}

		else if (choice == 4) {	// Yes this could have been a function
			todo.showTasks(); // Print all tasks with id number to make it easier for the user to select the right one
			std::cout << "\n What task would you like to mark as incompleted? Input the id number" << std::endl;
			getline(std::cin, userInput);
			// int taskID = stoi(userInput)-1;
			todo.completeTask(stoi(userInput)-1, false);
		}

		else if (choice == 5) {
			std::cout << " Exiting program...\n";
			break; //Exit program
		}
		
		else {
			std::cout << " Invalid choice. Please try again.\n"; //Invalid choice
		}
	}

	return 0;
}