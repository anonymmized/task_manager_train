#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct Task {
    string description;
    bool completed;
};

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\033[33mNo tasks in the list!\033[0m" << endl;
        return;
    }
    cout << "\033[36m--- Task List ---\033[0m" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " \033[32m[Completed]\033[0m" << endl;
        } else {
            cout << " \033[31m[Pending]\033[0m" << endl;
        }
    }
}

void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\033[33mNo tasks to delete!\033[0m" << endl;
        return;
    }
    viewTasks(tasks);
    cout << "\033[38;5;208mEnter number of task to delete: \033[0m";
    int taskNumber;
    if (!(cin >> taskNumber)) {
        cout << "\033[31mInvalid input! Enter a number.\033[0m" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    cin.ignore(10000, '\n');
    if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + (taskNumber - 1));
        cout << "\033[32mTask " << taskNumber << " deleted!\033[0m" << endl;
    } else {
        cout << "\033[31mInvalid task number!\033[0m" << endl;
    }
}

void completeTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\033[33mNo tasks to complete!\033[0m" << endl;
        return;
    }
    viewTasks(tasks);
    cout << "\033[38;5;208mEnter number of task to complete: \033[0m";
    int taskNumber;
    if (!(cin >> taskNumber)) {
        cout << "\033[31mInvalid input! Enter a number.\033[0m" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    cin.ignore(10000, '\n');
    if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
        tasks[taskNumber - 1].completed = true;
        cout << "\033[32mTask " << taskNumber << " marked as completed!\033[0m" << endl;
    } else {
        cout << "\033[31mInvalid task number!\033[0m" << endl;
    }
}

void saveTasks(const vector<Task>& tasks) {
    ofstream outFile("tasks.txt");
    if (!outFile.is_open()) {
        cout << "\033[31mError saving tasks to file!\033[0m" << endl;
        return;
    }
    for (size_t i = 0; i < tasks.size(); i++) {
        outFile << tasks[i].description << "," << tasks[i].completed << "\n";
    }
    outFile.close();
    cout << "\033[32mTasks saved to file!\033[0m" << endl;
}

void loadTasks(vector<Task>& tasks) {
    ifstream inFile("tasks.txt");
    if (!inFile.is_open()) {
        cout << "\033[33mNo tasks found or error loading file!\033[0m" << endl;
        return;
    }
    string line, description;
    while (getline(inFile, line)) {
        stringstream ss(line);
        getline(ss, description, ',');
        int completed;
        ss >> completed;
        if (!description.empty()) {
            Task task;
            task.description = description;
            task.completed = static_cast<bool>(completed);
            tasks.push_back(task);
        }
    }
    inFile.close();
    if (!tasks.empty()) {
        cout << "\033[32mTasks loaded from file!\033[0m" << endl;
    }
}

void editTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\033[33mNo tasks to edit!\033[0m" << endl;
        return;
    }
    viewTasks(tasks);
    cout << "\033[38;5;208mEnter number of task to edit: \033[0m";
    int taskNumber;
    if (!(cin >> taskNumber)) {
        cout << "\033[31mInvalid input! Enter a number.\033[0m" << endl;
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }
    cin.ignore(10000, '\n');
    if (taskNumber >= 1 && taskNumber <= static_cast<int>(tasks.size())) {
        cout << "\033[38;5;208mEnter new description: \033[0m";
        string editTask;
        getline(cin, editTask);
        if (editTask.empty()) {
            cout << "\033[31mDescription cannot be empty!\033[0m" << endl;
            return;
        }
        tasks[taskNumber - 1].description = editTask;
        cout << "\033[32mTask " << taskNumber << " updated!\033[0m" << endl;
    } else {
        cout << "\033[31mInvalid task number!\033[0m" << endl;
    }
}

int main() {
    vector<Task> tasks;
    cout << "\033[35mWelcome to To-Do List Manager!\033[0m" << endl;
    loadTasks(tasks);
    while (true) {
        cout << "\033[36m--- Menu ---\033[0m" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Edit Task" << endl;
        cout << "6. Save tasks to file" << endl;
        cout << "7. Exit" << endl;
        cout << "\033[38;5;208mEnter your choice (1-7): \033[0m";
        int choice;
        if (!(cin >> choice)) {
            cout << "\033[31mInvalid input! Enter a number.\033[0m" << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }
        cin.ignore(10000, '\n');
        if (choice == 1) {
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
            viewTasks(tasks);
        } else if (choice == 3) {
            completeTask(tasks);
        } else if (choice == 4) {
            deleteTask(tasks);
        } else if (choice == 5) {
            editTask(tasks);
        } else if (choice == 6) {
            saveTasks(tasks);
        } else if (choice == 7) {
            saveTasks(tasks);
            cout << "\033[35mThanks for using To-Do List Manager!\033[0m" << endl;
            break;
        } else {
            cout << "\033[31mInvalid choice! Enter 1-7.\033[0m" << endl;
        }
    }
    return 0;
}