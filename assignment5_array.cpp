//CREATON OF DEQUE USING ARRAY
//IN DQ INSERTION AND DELETION CAN BE DONE FROM BOTH THE ENDS

/*
#include <iostream>
using namespace std;

#define SIZE 5

class Deque {
    int arr[SIZE];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertFront(int x) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            front--;
        }
        arr[front] = x;
        cout << "Inserted at front: " << x << endl;
    }

    void insertRear(int x) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        if (front == -1) {
            front = rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = x;
        cout << "Inserted at rear: " << x << endl;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Deleted from front: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Deleted from rear: " << arr[rear] << endl;
        if (front == rear) {
            front = rear = -1;
        } else if (rear == 0) {
            rear = SIZE - 1;
        } else {
            rear--;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    int choice, data;

    do {
        cout << "\n--- Deque Menu ---\n";
        cout << "1. Insert Front\n2. Insert Rear\n3. Delete Front\n4. Delete Rear\n5. Display\n6. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                dq.insertFront(data);
                break;
            case 2:
                cout << "Enter data: ";
                cin >> data;
                dq.insertRear(data);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                dq.display();
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 6);

    return 0;
}


*/


#include<bits/stdc++.h>
using namespace std;
#define size 5

class DQ{
    public:
    int arr[size];
    int front,rear;
    DQ(){
        front=rear=-1;
    }

    void insert_at_head(){
        int data;
        cout<<"enter the number to be inserted at the head: ";
        cin>>data;
        //case 1 : nothing is inserted yet in the DQ (empty dq)
        if(front==-1 && rear==-1){
            front++;rear++;
            arr[front]=data;
        }

        //case2: rear!=-1 and front<=rear
        if(front<=rear){
            if(rear==4){cout<<"the DQ is full\n";return;}
            else{}
        } 

    }
};

int main(){




}
