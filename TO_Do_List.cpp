#include <iostream>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void displayInstructions() {
    system("cls");
    cout << "To-Do List Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Quit" << endl;
    cout << "Press any key to go back to the main menu." << endl;
    _getch();
}

void addTask() {
    system("cls");
    Task task;
    cout << "Enter the description of the task: ";
    cin.ignore();
    getline(cin, task.description);
    task.completed = false;
    tasks.push_back(task);
    cout << "Task added successfully!" << endl;
    _getch();
}

void viewTasks() {
    system("cls");
    if (tasks.empty()) {
        cout << "No tasks in the list." << endl;
    }
    else {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". ";
            if (tasks[i].completed) {
                cout << "[X] ";
            }
            else {
                cout << "[ ] ";
            }
            cout << tasks[i].description << endl;
        }
    }
    _getch();
}

void markTaskCompleted() {
    system("cls");
    viewTasks();
    if (tasks.empty()) {
        cout << "No tasks to mark as completed." << endl;
        _getch();
        return;
    }

    cout << "Enter the task number to mark as completed: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    }
    else {
        cout << "Invalid task number." << endl;
    }
    _getch();
}

void removeTask() {
    system("cls");
    viewTasks();
    if (tasks.empty()) {
        cout << "No tasks to remove." << endl;
        _getch();
        return;
    }

    cout << "Enter the task number to remove: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed successfully!" << endl;
    }
    else {
        cout << "Invalid task number." << endl;
    }
    _getch();
}

int main() {
    while (true) {
        system("cls");
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;

        char choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case '1':
            addTask();
            break;
        case '2':
            viewTasks();
            break;
        case '3':
            markTaskCompleted();
            break;
        case '4':
            removeTask();
            break;
        case '5':
            cout << "Thanks for using the To-Do List Manager. Goodbye!" << endl;
            return 0;
        default:
            displayInstructions();
            break;
        }
    }

    return 0;
}
