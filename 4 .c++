#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

void displayMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "===================\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
}

void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter a new task: ";
    std::cin.ignore();
    std::getline(std::cin, description);
    tasks.push_back({description, false});
    std::cout << "Task added.\n";
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks available.\n";
        return;
    }

    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description << " [" 
                  << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted(std::vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) {
        return;
    }

    size_t taskNumber;
    std::cout << "Enter the task number to mark as completed: ";
    std::cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

void removeTask(std::vector<Task>& tasks) {
    viewTasks(tasks);
    if (tasks.empty()) {
        return;
    }

    size_t taskNumber;
    std::cout << "Enter the task number to remove: ";
    std::cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task removed.\n";
    } else {
        std::cout << "Invalid task number.\n";
    }
}

int main() {
    std::vector<Task> tasks;
    int choice = 0;

    while (choice != 5) {
        displayMenu();
        std::cout << "Choose an option: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice. Please choose a valid option.\n";
                break;
        }
    }

    return 0;
}
