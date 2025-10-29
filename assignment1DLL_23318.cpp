/*"Efficient Data Management Using Linked Lists: Implementing Dynamic Operations for Contact Management System" Utilize Doubly Linked Lists to manage a Contact Management System.
 The system will support key operations such as:
  • Creating a contact list dynamically.
  •  Adding new contacts efficiently.
  • Deleting contacts when no longer needed. 
  • Searching for specific contacts based on name or number.
  • Reversing the contact list for alternate viewing orders.
  • Traversing through the list to display all stored contacts.
  SINGLY LINKED LIST:
  */

#include <bits/stdc++.h>
using namespace std;
class NODE {
public:
    string contactnumber;
    string name;
    string mail_id;
    NODE *next, *prev;
    NODE(string name, string contactnumber,string mail_id) {
        this->name = name;
        this->mail_id = mail_id;
        this->contactnumber = contactnumber;
        next = nullptr;
        prev = nullptr;
    }
};
class DLL {
private:
    NODE* head;
public:
    DLL() {
        head = nullptr;
    }
    
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

    void insertathead() {
        int a;
        cout << "Enter the number of inputs you want at the head: ";
        cin >> a;
        while (a--) {
            NODE* newnode = getnode();
            newnode->next = head;
            if (head != nullptr) head->prev = newnode;
            head = newnode;
        }
    }
    void insertatend() {
        int a;
        cout << "Enter the number of inputs you want at the end: ";
        cin >> a;
        while (a--) {
            NODE* newnode = getnode();
            if (head == nullptr) {
                head = newnode;
            } else {
                NODE* ptr = head;
                while (ptr->next != nullptr) {
                    ptr = ptr->next;
                }
                ptr->next = newnode;
                newnode->prev = ptr;
            }
        }
    }
    void insertinbetween() {
        if (head == nullptr) {
            cout << "List is empty. Insert at head or end first.\n";
            return;
        }
        string x;
        cout << "Enter the name after which you want to insert the new contact: ";
        cin >> x;

        NODE* ptr = head;
        while (ptr != nullptr && ptr->name != x) {
            ptr = ptr->next;
        }
        if (ptr == nullptr) {
            cout << "Name not found in the list.\n";
            return;
        }
        NODE* newnode = getnode();
        newnode->next = ptr->next;
        newnode->prev = ptr;
        if (ptr->next != nullptr)
            ptr->next->prev = newnode;
        ptr->next = newnode;
    }
    void display() {
        NODE* ptr = head;
        if (ptr == nullptr) {
            cout << "DLL is empty\n";
            return;
        }
        while (ptr != nullptr) {
            cout << "Name: " << ptr->name
                 << " | Contact: " << ptr->contactnumber << "mail_id: " << ptr->mail_id <<"\n";
            ptr = ptr->next;
        }
    }
    void deletebyvalue() {
        if (head == nullptr) {
            cout << "DLL is empty\n";
            return;
        }
        string x;
        cout << "Enter the contact number you want to delete: ";
        cin >> x;
        NODE* ptr = head;
        while (ptr != nullptr && ptr->contactnumber != x) {
            ptr = ptr->next;
        }
        if (ptr == nullptr) {
            cout << "Contact number not found in the list.\n";
            return;
        }
        // Delete head
        if (ptr == head) {
            head = head->next;
            if (head != nullptr) head->prev = nullptr;
            delete ptr;
            return;
        }
        // Delete end
        if (ptr->next == nullptr) {
            ptr->prev->next = nullptr;
            delete ptr;
            return;
        }
        // Delete in-between
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        delete ptr;
    }
    void search() {//to search the element from the list
        if (head == nullptr) {
            cout << "The linked list is empty.\n";
            return;
        }
        string s;
        cout << "Enter the name to be searched: ";
        cin >> s;
        NODE* ptr = head;
        while (ptr != nullptr && ptr->name != s) {
            ptr = ptr->next;
        }
        if (ptr != nullptr) {
            cout << "Name " << s << " exists in the list :)\n";
        } else {
            cout << "Name " << s << " does not exist in the list :(\n";
        }
    }
    void reverseDLL() { //to reverse the LL
        NODE* temp = nullptr;
        NODE* current = head;

        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (temp != nullptr)
            head = temp->prev;
    }
    ~DLL() {
        NODE* current = head;
        while (current != nullptr) {
            NODE* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        cout << "All nodes deleted.\n";
    }
};
int main() {
    DLL l;
    int k;
    string s;
    cout << "Enter 1: Insert at head\n"
         << "Enter 2: Insert at end\n"
         << "Enter 3: Insert in between\n"
         << "Enter 4: Delete node\n";
    cin >> k;
    switch (k) {
        case 1:
            l.insertathead();
            l.display();
            break;
        case 2:
            l.insertatend();
            l.display();
            break;
        case 3:
            l.insertinbetween();
            l.display();
            break;
        case 4:
            l.deletebyvalue();
            l.display();
            break;
        default:
            cout << "Invalid choice\n";
            break;
    }
    cout << "Do you want to delete any node? (yes/no): ";
    cin >> s;
    if (s == "yes") {
        l.deletebyvalue();
        cout << "Updated list:\n";
        l.display();
    }
    return 0;
}
