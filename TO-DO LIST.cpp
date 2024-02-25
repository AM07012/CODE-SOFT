#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

class ToDoListManager {
	private:
    	vector<Task> tasks;

	public:
    	void addTask(const string& description) {
        	Task newTask = {description, false};
        	tasks.push_back(newTask);
        	cout<<"Task"<<description<<"added."<<endl;
    }

    	void viewTasks() {
        	if (tasks.empty()) {
            	cout << "No tasks in the list." << std::endl;
        }	 else {
            cout<<"Tasks:"<<endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                string status = (tasks[i].completed) ? "Completed" : "Pending";
                cout << i + 1 << ". " << tasks[i].description << " - " << status <<endl;
            }
        }
    }

    void markCompleted(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            tasks[taskIndex - 1].completed = true;
			cout << "Task '" << tasks[taskIndex - 1].description << "' marked as completed." <<endl;
        } else {
            cout << "Invalid task index." <<endl;
        }
    }

    void removeTask(size_t taskIndex) {
        if (taskIndex >= 1 && taskIndex <= tasks.size()) {
            Task removedTask = tasks[taskIndex - 1];
            tasks.erase(tasks.begin() + taskIndex - 1);
            cout << "Task '" << removedTask.description << "' removed." <<endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }
};

int main() {
    ToDoListManager todoListManager;

    while (true) {
        cout << "\n--- ToDo List Manager ---" << endl;
        cout << "1. Add Task" <<endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter the task: ";
                cin.ignore();
                getline(cin, taskDescription);
                todoListManager.addTask(taskDescription);
                break;
            }
            case 2:
                todoListManager.viewTasks();
                break;
            case 3: {
                size_t taskIndex;
                cout << "Enter the task index to mark as completed: ";
                cin >> taskIndex;
                todoListManager.markCompleted(taskIndex);
                break;
            }
            case 4: {
                size_t taskIndex;
                cout << "Enter the task index to remove: ";
                cin >> taskIndex;
                todoListManager.removeTask(taskIndex);
                break;
            }
            case 5:
                cout << "Exiting the ToDo List Manager." <<endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." <<endl;
        }
    }

    return 0;
}
