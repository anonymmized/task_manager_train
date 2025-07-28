#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

void completeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\033[33mNo tasks to complete!\033[0m" << endl;
        return;
    }
     viewTasks(tasks);
    
}

int main() {
    vector<Task> tasks;

    cout << "\033[35mWelcome to To-Do List Manager!\033[0m" << endl;
    while (true) {
        cout << "\033[36m--- Menu ---\033[0m" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Exit" << endl;
        cout << "\033[38;5;208mEnter your choice (1-4): \033[0m";
        int choice;

        if (!(cin >> choice)) {
            cout << "\033[31mInvalid input! Enter a number.\033[0m" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(10000, '\n');

        if (choice == 1) {
             cout << "\033[33mAdd Task (not implemented yet)\033[0m" << endl;
             string addTask;
             cout << "\033[38;5;208mEnter task description: \033[0m";
             getline(cin, addTask);
             if (!addTask.empty()) {
                Task newTask;
                newTask.description = addTask;
                newTask.completed = false;
                tasks.push_back(newTask);
                cout << "\033[32mTask added: " << addTask << "\033[0m" << endl;
             } else {
                cout << "\033[31mTask description cannot be empty!\033[0m" << endl;
             }
        } else if (choice == 2) {
            cout << "\033[33mView Tasks (not implemented yet)\033[0m" << endl;
            for (size_t i = 0; i < tasks.size(); i++) {
                cout << "\033[33m" << i + 1 << ". " << tasks[i].description << "\033[0m";
                if (tasks[i].completed == 0) {
                    cout << " \033[31m[Not completed]\033[0m" << endl;
                } else if (tasks[i].completed == 1) {
                    cout << " \033[31m[Completed]\033[0m" << endl;
                }
            }
        } else if (choice == 3) {
            int completed_task_num;
            for (size_t i = 0; i < tasks.size(); i++) {
                cout << "\033[33m" << i + 1 << ". " << tasks[i].description << "\033[0m";
                if (tasks[i].completed == 0) {
                    cout << " \033[31m[Not completed]\033[0m" << endl;
                } else if (tasks[i].completed == 1) {
                    cout << " \033[31m[Completed]\033[0m" << endl;
                }
            }
            cout << "Enter number of task to complete: ";
            cin >> completed_task_num;
            if (completed_task_num - 1 < tasks.size()) {
                for (size_t j = 0; j < tasks.size(); j++) {
                    if (j == completed_task_num) {
                        tasks[j].completed = true;
                        cout << "\033[33m" << j + 1 << ". " << tasks[j].description << "\033[0m";
                        cout << " \033[31m[Completed]\033[0m" << endl; 
                        break;
                    }
                }
            } else {
                cout << "Error";
                break;
            }
            
        } else if (choice == 4) {
            cout << "\033[35mThanks for using To-Do List Manager!\033[0m" << endl;
            break;
        } else {
            cout << "\033[31mInvalid choice! Enter 1-4.\033[0m" << endl;
        }
    }
    return 0;
}