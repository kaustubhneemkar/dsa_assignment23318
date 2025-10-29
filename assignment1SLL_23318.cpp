/*"Efficient Data Management Using Linked Lists: Implementing Dynamic Operations for Contact Management System" Utilize singly Linked Lists to manage a Contact Management System.
 The system will support key operations such as:
  • Creating a contact list dynamically.
  •  Adding new contacts efficiently.
  • Deleting contacts when no longer needed. 
  • Searching for specific contacts based on name or number.
  • Reversing the contact list for alternate viewing orders.
  • Traversing through the list to display all stored contacts.
  SINGLY LINKED LIST:
  */

#include<bits/stdc++.h>
using namespace std;
class NODE
{ // NODE ATTRIBUTES
public:
    string contactnumber;
    string name;
    string mail_id;
    NODE *next;
    NODE(string name, string contactnumber,string mail_id)
    {
        this->name = name;
        this->contactnumber = contactnumber;
        this->mail_id = mail_id;
        next = NULL;
    }
}; // NODE CLOSED;

class LL
{
private:
    NODE *head;

public:
       // Create a valid new node from user input
   NODE* getnode() {
    string contact, name, M;
    while (true) {
        //INPUT CORRECT MAIL :
        cout << "Enter email ID: ";
        cin >> M;
        size_t atPos = M.find('@');//size_t is unsigned(non -ve only)int datatype (which can even handle index greater than int range.)
        size_t dotPos = M.find('.', atPos);//M.find("thing to be searched", starting position from where to be searched).

        if (atPos == string::npos || dotPos == string::npos || atPos == 0 || dotPos == M.size() - 1) { //npos is to check "if not present";
            cout << "Enter correct mail ID\n";
            continue;
        }
        //INPUT CORRECT CONTACT :
        cout << "Enter the contact number (10 digits): ";
        cin >> contact;
        if (contact.size() != 10 || !all_of(contact.begin(), contact.end(), ::isdigit)) {
            cout << "Invalid contact number! Try again.\n";
            continue;
        }
        //FINALLY CREATE NODE IF INPUTS ARE VALID;
        cout << "Enter the name: ";
        cin >> name;
        return new NODE(name, contact,M);
    }
}

    LL()
    {
        head = NULL;
    }
    void insertathead()
    {
        int a;
        cout << "enter the number of inputs u want at the head : ";
        cin >> a;
        while (a--)
        {
            string n, k;
            NODE *newnode = getnode();

            if (head == NULL)
            {
                head = newnode;
            }
            else
            {
                newnode->next = head;
                head = newnode;
            }
        }
    }

    void insertatend()
    {
        int a;
        cout << "enter the number of inputs u want at the end: ";
        cin >> a;
        while (a--)
        {
            string n, k;

            NODE *newnode = getnode();
            NODE *ptr = head;
            if (head == NULL)
            {
                head = newnode;
            }
            else
            {
                while (ptr->next != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = newnode;
            }
        }
    }

    void insertinbetween()
    {
        string n, k, x;
  
        NODE *newnode = getnode();
        cout << "enter the name after which u want ur new node to be inserted: ";
        cin >> x;
        NODE *ptr = head;
        while (ptr != NULL && ptr->name != x)
        {
            ptr = ptr->next;
        }
        if (ptr == NULL) {
    cout << "Name not found in the list.\n";
    return;
}
        newnode->next = ptr->next;
        ptr->next = newnode;
    }

    void display()
    {
        cout << "displaying the contact details stored int the LL:" << endl;
        NODE *ptr = head;
        while (ptr != NULL)
        {
            cout << "the contact number stored at this node is: " << ptr->contactnumber << endl
                 << "the name stored at this node is: " << ptr->name << endl;
            ptr = ptr->next;
        }
    }

    void search()
    {
        string x;
        cout << "enter the contact number to be searched:";
        cin >> x;
        NODE *temp;
        temp = head;
        while (temp != NULL && temp->contactnumber != x) {
    temp = temp->next;
}
if (temp == NULL) {
    cout << "number does not exist.\n";
} else {
    cout << "Number found! Name: " << temp->name << "\n";
}
    }
    void deletebyvalue()
    {
        NODE *ptr = head, *temp = NULL;
        if (head == NULL)
        {
            return;
        }
        string x;
        cout << "enter the contact number of the node which u want to delete: ";
        cin >> x;
        while (ptr->contactnumber != x)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        // delete the head
        if (ptr == head)
        {
            head = head->next;
            delete (ptr);
        }
        // delete at end
        else
        {
            temp->next = ptr->next;
            delete (ptr);
        }
    }

    void reverselist()
    {
        NODE *current, *prev, *nextone;
        prev = NULL;
        current = head;
        nextone = NULL;
        while (current != NULL)
        {
            nextone = current->next;
            current->next = prev;
            prev = current;
            current = nextone;
        }
        head=prev;
    }
};

int main()
{
    LL l;
    int k;
    {
        cout << "enter 1: if u want to insert at head: \nenter 2: if u want to insert at end: \nenter 3: if u want to insert between list:\n";
        cin >> k;
        
        switch (k)
        {
        case 1:
            l.insertathead();
            l.display();
            cout <<"\nthe reversed linked list is: \n";
            l.reverselist();
            l.display();
            break;

        case 2:
            l.insertatend();
            l.display();
            cout <<"\nthe reversed linked list is: \n";
            l.reverselist();
            l.display();
            break;

        case 3:
            l.insertinbetween();
            l.display();
            cout <<"\nthe reversed linked list is: \n";
            l.reverselist();
            l.display();
            break;

        default:
            break;
        }
    }

    return 0;
}
