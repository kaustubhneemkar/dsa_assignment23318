//Aim: To implement and demonstrate the working of a Priority Queue and a Double-Ended Queue
//(Deque) supporting standard operations such as insertion, deletion, and display.
/*so basically a linked list where the node having highest priority is inserted at the head while the 
node having least priority is inserted at end and accordingly insert the new node in between as well on 
the basis of the priority*/

#include <bits/stdc++.h>
using namespace std;
class NODE {
public:
    int age;
    string name;
    int priority;
    NODE *next;
    NODE *prev;

    NODE(int a, int p, string s) {
        age = a;
        priority = p;
        name = s;
        next = prev = NULL;
    }
};

class PQ {
public:
    NODE *front;
    NODE *rear;

    PQ() {
        front = NULL;
        rear = NULL;
    }

    void enque() {
        int ag, prio;
        string na;
        cout << "Enter the name of the patient: ";
        cin >> na;
        cout << "Enter the age of the patient: ";
        cin >> ag;
        cout << "Enter the priority [1->ICU, 2->Accident case, 3->Normal checkup]: ";
        cin >> prio;

        NODE *newnode = new NODE(ag, prio, na);

        // If empty queue
        if (front == NULL) {
            front = rear = newnode;
        } 
        else {
            rear->next = newnode;
            newnode->prev = rear;
            rear = newnode;
        }
    }

    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty! No patient to dequeue.\n";
            return;
        }

        NODE *temp = front;

        // STEP 1: Find the highest priority present in queue
        int highestPriority = 3;  // default lowest
        NODE *check = front;
        while (check != NULL) {
            highestPriority = min(highestPriority, check->priority);
            check = check->next;
        }

        // STEP 2: Find first occurrence of that highest priority
        while (temp != NULL && temp->priority != highestPriority) {
            temp = temp->next;
        }

        // STEP 3: Delete that node
        if (temp == NULL) return;  // safeguard

        cout << "Deleting patient: " << temp->name 
             << " (Age: " << temp->age 
             << ", Priority: " << temp->priority << ")\n";

        if (temp == front && temp == rear) { // only one node
            front = rear = NULL;
        }
        else if (temp == front) {
            front = front->next;
            front->prev = NULL;
        }
        else if (temp == rear) {
            rear = rear->prev;
            rear->next = NULL;
        }
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void display() {
        if (front == NULL) {
            cout << "Queue is empty!\n";
            return;
        }

        cout << "\nCurrent Patients in Queue:\n";
        NODE *temp = front;
        while (temp != NULL) {
            cout << "Name: " << temp->name 
                 << " | Age: " << temp->age 
                 << " | Priority: " << temp->priority << endl;
            temp = temp->next;
        }
        cout << "-----------------------------------\n";
    }
};

int main() {
    PQ q;
    int choice;

    do {
        cout << "\n1. Enqueue Patient\n2. Dequeue Patient\n3. Display Queue\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            q.enque();
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            q.display();
            break;
        case 4:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
