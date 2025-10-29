//Aim: To implement and demonstrate the working of a Priority Queue and a Double-Ended Queue
//(Deque) supporting standard operations such as insertion, deletion, and display.
/*so basically a linked list where the node having highest priority is inserted at the head while the 
node having least priority is inserted at end and accordingly insert the new node in between as well on 
the basis of the priority*/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
   int priority;
   int data;
   Node* next;

    Node(int d, int p) {
        data = d;
        priority = p;
        next = NULL;
    }

};

class PriorityQueue
{
    Node *head;
    // Node* temp;

public:
    PriorityQueue()
    {
        head = NULL;
        //  temp = NULL;
    }

    // Insert by priority
    void insert()
    {
        // case 1: head == null
        int DATA,PRIO;
        cout<<"enter the data in this node: ";
        cin>>DATA;
        cout<<"enter the priority of this node: ";
        cin>>PRIO;
        Node *newnode = new Node(DATA, PRIO);
        if (head == NULL)
        {
            head = newnode;
        }

        // case 2 :insert by priority given that the pq is not empty
        if (head != NULL)
        {
            Node *temp;
            temp = head;
        }
        // Case a: insert before head if newnode has higher priority
        else if (newnode->priority > head->priority)
        {
            newnode->next = head;
            head = newnode;
        }
        // Case b: insert somewhere after head
        else
        {
            Node *temp = head;
            while (temp->next != NULL && temp->next->priority >= newnode->priority)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }

    void remove_highprio(){//delete the head
        Node *temp=head;
        head=head->next;
        delete temp;
        cout<<"node with highest priority is deleted : \n";
    }

    void display(){
        Node *temp=head;
        if(head==NULL){cout<<"pq is empty\n";return;}
        while(temp!=NULL){
           cout<<"the data stored in this node is: "<<temp->data<<" \n";
        }
    }


};

int main() {
    PriorityQueue pq;
    int choice, data, priority;

    do {
        cout << "\n--- Priority Queue Menu ---\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                pq.insert();
                break;
            case 2:
                pq.remove_highprio();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
