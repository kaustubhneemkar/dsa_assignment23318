/*ROLL NO 23318 ASSIGNMENT-2 [TO-DO LIST]
Task Scheduling System (Queue): Managing tasks in a first-in, first-out (FIFO) order, such
as print job scheduling or process management in an operating system.
*/

#include <iostream>
using namespace std;

// Enum for difficulty and priority levels
enum Level { LOW = 0, MEDIUM = 1, HIGH = 2 };

// Structure to represent a Task
struct Task {
    string title;
    Level difficulty;
    Level priority;
    Task* next;
};

// Class to represent a queue of tasks
class TaskQueue {
    Task* front;
    Task* rear;

public:
    TaskQueue() {
        front = NULL;
        rear = NULL;
    }

    // Create a new task node with user input
    Task* createTask() {
        Task* newTask = new Task();
        int diff, prio;

        cout << "Enter task title: ";
        cin >> newTask->title;

        cout << "Enter difficulty (0: Low, 1: Medium, 2: High): ";
        cin >> diff;

        cout << "Enter priority (0: Low, 1: Medium, 2: High): ";
        cin >> prio;

        // Convert input integers into enum values
        newTask->difficulty = static_cast<Level>(diff);
        newTask->priority = static_cast<Level>(prio);
        newTask->next = NULL;

        return newTask;
    }

    // Add a task to the queue (at the rear)
    void enqueue() {
        Task* newTask = createTask();

        if (rear == NULL) {  // If queue is empty
            front = rear = newTask;
        } else {
            rear->next = newTask;
            rear = newTask;
        }

        cout << "Task added successfully!\n";
    }

    // Remove a task from the queue (from the front)
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty! No task to remove.\n";
            return;
        }

        Task* temp = front;
        front = front->next;

        cout << "ask \"" << temp->title << "\" completed and removed.\n";
        delete temp;

        if (front == NULL)  // If queue became empty
            rear = NULL;
    }

    // Show the front (next) task
    void peek() {
        if (front == nullptr) {
            cout << "No tasks in the queue.\n";
            return;
        }

        cout << "\n--- Next Task ---\n";
        cout << "Title: " << front->title << endl;
        cout << "Difficulty: " << front->difficulty << endl;
        cout << "Priority: " << front->priority << endl;
        cout << "-----------------\n";
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    TaskQueue tq;
    int choice;

    while (true) {
        cout << "\n=== Task Scheduler Menu ===\n";
        cout << "1. Add Task\n";
        cout << "2. Complete Task\n";
        cout << "3. View Next Task\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tq.enqueue();
                break;
            case 2:
                tq.dequeue();
                break;
            case 3:
                tq.peek();
                break;
            case 0:
                cout << " Exiting program. Bye!\n";
                return 0;
            default:
                cout << " Invalid choice. Try again.\n";
        }
    }
}

}


