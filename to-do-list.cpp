#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(const string &desc) : description(desc), completed(false) {}
};

class ToDoListManager {
private:
    vector<Task> tasks;

public:
    void addTask() {
        cout << "Enter the task description: ";
        string description;
        cin.ignore();  // Clear the input buffer
        getline(cin, description);
        tasks.emplace_back(description);
        cout << "Task added!" << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
        } else {
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].description 
                     << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
            }
        }
    }

    void markTaskCompleted() {
        viewTasks();
        cout << "Enter the number of the task to mark as completed: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].completed = true;
            cout << "Task marked as completed!" << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask() {
        viewTasks();
        cout << "Enter the number of the task to remove: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task removed!" << endl;
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void menu() {
        while (true) {
            cout << "\nTo-Do List Manager" << endl;
            cout << "1. Add Task" << endl;
            cout << "2. View Tasks" << endl;
            cout << "3. Mark Task as Completed" << endl;
            cout << "4. Remove Task" << endl;
            cout << "5. Exit" << endl;
            cout << "Choose an option: ";
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    addTask();
                    break;
                case 2:
                    viewTasks();
                    break;
                case 3:
                    markTaskCompleted();
                    break;
                case 4:
                    removeTask();
                    break;
                case 5:
                    return;
                default:
                    cout << "Invalid option. Please try again." << endl;
            }
        }
    }
};

int main() {
    ToDoListManager manager;
    manager.menu();
    return 0;
}
