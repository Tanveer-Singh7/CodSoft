#include <iostream>
#include <string>

using namespace std;

const int MAX_TASKS = 100; // Maximum number of tasks

class TodoList
{
private:
    string tasks[MAX_TASKS];   // Array to store tasks
    bool completed[MAX_TASKS]; // Array to store completion status of tasks
    int numTasks;              // Number of tasks currently in the list

public:
    TodoList() : numTasks(0) {}

    void addTask(const string &description)
    {
        if (numTasks < MAX_TASKS)
        {
            tasks[numTasks] = description;
            completed[numTasks] = false; // Set completion status to false initially
            numTasks++;
            cout << "Task added successfully.\n";
        }
        else
        {
            cout << "Cannot add task. Todo list is full.\n";
        }
    }

    void viewTasks()
    {
        if (numTasks == 0)
        {
            cout << "No tasks found.\n";
            return;
        }
        cout << "Tasks:\n";
        for (int i = 0; i < numTasks; ++i)
        {
            cout << "\t" << i + 1 << ". " << tasks[i];
            if (completed[i])
            {
                cout << " -completed" << endl;
            }
            else
            {
                cout << " -pending" << endl;
            }
        }
    }

    void markTaskAsCompleted(int index)
    {
        if (index >= 1 && index <= numTasks)
        {
            completed[index - 1] = true; // Mark task as completed
            cout << "\tTask '" << tasks[index - 1] << "' marked as completed.\n";
        }
        else
        {
            cout << "Invalid task index.\n";
        }
    }

    void removeTask(int index)
    {
        if (index >= 1 && index <= numTasks)
        {
            cout << "\tTask '" << tasks[index - 1] << "' removed successfully.\n";
            for (int i = index - 1; i < numTasks - 1; ++i)
            {
                tasks[i] = tasks[i + 1];
                completed[i] = completed[i + 1];
            }
            numTasks--;
        }
        else
        {
            cout << "Invalid task index.\n";
        }
    }
};

int main()
{
    TodoList todoList;
    int choice;

    while (true)
    {
        cout << "\n\n--------------Todo List Manager-----------------------\n\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string taskDescription;
            cout << "\tEnter task description: ";
            cin.ignore(); // Ignore newline character in input buffer
            getline(cin, taskDescription);
            todoList.addTask(taskDescription);
            break;
        }
        case 2:
            todoList.viewTasks();
            break;
        case 3:
        {
            int index;
            cout << "Enter the index of the task to mark as completed: ";
            cin >> index;
            todoList.markTaskAsCompleted(index);
            break;
        }
        case 4:
        {
            int index;
            cout << "Enter the index of the task to remove: ";
            cin >> index;
            todoList.removeTask(index);
            break;
        }
        case 5:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}