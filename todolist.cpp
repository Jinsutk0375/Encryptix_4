#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100;

struct Task {
    string description;
    bool completed;
    Task() : description(""), completed(false) {}
};

void addTask(Task tasks[], int &taskCount) {
    if (taskCount >= MAX_TASKS) {
        cout << "Task list is full!\n";
        return;
    }
    cout << "Enter a new task: ";
    cin.ignore();
    getline(cin, tasks[taskCount].description);
    tasks[taskCount].completed = false;
    taskCount++;
    cout << "Task added!\n";
}

void viewTasks(const Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks to show.\n";
        return;
    }
    cout << "\nTasks:\n";
    for (int i = 0; i < taskCount; ++i) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) cout << " [Completed]";
        cout << "\n";
    }
}

void markTaskAsCompleted(Task tasks[], int taskCount) {
    if (taskCount == 0) {
        cout << "No tasks to complete.\n";
        return;
    }
    cout << "Enter task number to mark as completed: ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber >= 1 && taskNumber <= taskCount) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void removeTask(Task tasks[], int &taskCount) {
    if (taskCount == 0) {
        cout << "No tasks to remove.\n";
        return;
    }
    cout << "Enter task number to remove: ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber >= 1 && taskNumber <= taskCount) {
        for (int i = taskNumber; i < taskCount; ++i) {
            tasks[i - 1] = tasks[i];
        }
        taskCount--;
        cout << "Task removed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void showMenu() {
    cout << "\n1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Task tasks[MAX_TASKS];
    int taskCount = 0;
    int choice;

    while (true) {
        showMenu();
        cin >> choice;
        switch (choice) {
            case 1: addTask(tasks, taskCount); break;
            case 2: viewTasks(tasks, taskCount); break;
            case 3: markTaskAsCompleted(tasks, taskCount); break;
            case 4: removeTask(tasks, taskCount); break;
            case 5: return 0;
            default: cout << "Invalid choice. Please try again.\n";
        }
    }
}
