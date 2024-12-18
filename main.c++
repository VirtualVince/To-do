#include <iostream>
#include <vector>
#include <string>

void displayMenu() {
    std::cout << "\n--- To-Do List Menu ---\n";
    std::cout << "1. Add a task\n";
    std::cout << "2. View tasks\n";
    std::cout << "3. Delete a task\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

void addTask(std::vector<std::string>& tasks) {
    std::cout << "Enter the task: ";
    std::string task;
    std::cin.ignore(); // Clear the input buffer
    std::getline(std::cin, task);
    tasks.push_back(task);
    std::cout << "Task added successfully!\n";
}

void viewTasks(const std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
    } else {
        std::cout << "\n--- Your Tasks ---\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i] << "\n";
        }
    }
}

void deleteTask(std::vector<std::string>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to delete.\n";
        return;
    }
    viewTasks(tasks);
    std::cout << "Enter the number of the task to delete: ";
    int index;
    std::cin >> index;
    if (index > 0 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + (index - 1));
        std::cout << "Task deleted successfully!\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

int main() {
    std::vector<std::string> tasks;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                deleteTask(tasks);
                break;
            case 4:
                std::cout << "Exiting the application. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
