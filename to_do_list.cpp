#include <iostream>
#include <map>
using namespace std;

struct Task {
    string title;
    bool completed = false;
};

map<string, Task> tasks;   

// ADD 
void addTask() {
    cin.ignore();
    Task t;

    cout << "\nEnter task title: ";
    getline(cin, t.title);

    tasks[t.title] = t;

    cout << "Task added.\n";
}

// VIEW 
void viewTasks() {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\n----------- TASK LIST -----------\n";
    for (auto &p : tasks) {
        Task t = p.second;

        cout << "\nTitle: " << t.title;
        cout << "\nStatus: " << (t.completed ? "Completed" : "Pending") << "\n";
    }
}

// MARK AS COMPLETED
void markCompleted() {
    cin.ignore();
    cout << "Enter task title to mark as completed: ";
    string title;
    getline(cin, title);

    if (tasks.find(title) == tasks.end()) {
        cout << "Task not found.\n";
        return;
    }

    tasks[title].completed = true;
    cout << "Task marked as completed.\n";
}

// DELETE 
void deleteTask() {
    cin.ignore();
    cout << "Enter task title to delete: ";
    string title;
    getline(cin, title);

    if (tasks.erase(title))
        cout << "Task deleted.\n";
    else
        cout << "Task not found.\n";
}

// MAIN
int main() {
    int choice;

    while (true) {
        cout << "\n=========== TODO MANAGER ===========\n";
        cout << "1. Add Task\n";
        cout << "2. View All Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(); break;
            case 2: viewTasks(); break;
            case 3: markCompleted(); break;
            case 4: deleteTask(); break;
            case 5: return 0;
            default: cout << "Invalid choice.\n";
        }
    }
}
