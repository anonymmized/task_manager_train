#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

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
        } else if (choice == 2) {
            cout << "\033[33mView Tasks (not implemented yet)\033[0m" << endl;
        } else if (choice == 3) {
            cout << "\033[33mMark Task as Completed (not implemented yet)\033[0m" << endl;
        } else if (choice == 4) {
            cout << "\033[35mThanks for using To-Do List Manager!\033[0m" << endl;
            break;
        } else {
            cout << "\033[31mInvalid choice! Enter 1-4.\033[0m" << endl;
        }
    }

    return 0;
}