#include <bits/stdc++.h>
using namespace std;

// -------- Hash Bucket Node --------
class HASHED_NODE {
public:
    int index;               // bucket index
    HASHED_NODE* down;       // next bucket
    NODE* chainHead;   // head of linked list (students in this bucket)

    HASHED_NODE(int y) {
        index = y;
        down = NULL;
        chainHead = NULL;
    }
};

// -------- Hash List (10 buckets) --------
//BASICALLY INSTEAD OF USING ARRAY , I HAVE USED LL OVERE HERE , WHICH HANDLES THE HASH KEY (%10) AND SUPPORTS CHAINING ACCORDINGLY......
class HASHED_LIST {
public:
    HASHED_NODE* HEAD, *TAIL;

    HASHED_LIST() {
        HEAD = TAIL = NULL;

        // Creating 10 buckets (0–9)
        for (int i = 0; i < 10; i++) {
            HASHED_NODE* newnode = new HASHED_NODE(i);
            if (HEAD == NULL) {
                HEAD = newnode;
                TAIL = newnode;
            } else {
                TAIL->down = newnode;
                TAIL = TAIL->down;
            }
        }
    }

    // function to find bucket by index
    HASHED_NODE* getBucket(int idx) {
        HASHED_NODE* temp = HEAD;
        while (temp != NULL && temp->index != idx) {
            temp = temp->down;
        }
        return temp;
    }
};

// -------- Student Node --------
class NODE {
public:
    int roll_no, marks;
    string name;
    NODE* next;

    NODE(int r, int m, string n) {
        roll_no = r;
        marks = m;
        name = n;
        next = NULL;
    }
};

// -------- Hash Functions --------
class HF {
public:
    HASHED_LIST* l; // pointer to hash buckets

    HF(HASHED_LIST* list) {
        l = list;
    }

    // Insert student
    void insert_at_end(int r, int m, string n) {
        NODE* newnode = new NODE(r, m, n);
        int z = r % 10;  // hash function

        // find correct bucket
        HASHED_NODE* bucket = l->getBucket(z);

        // insert into student chain
        if (bucket->chainHead == NULL) {
            bucket->chainHead = newnode;
        } else {
            NODE* temp = bucket->chainHead;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newnode;
        }
    }

    // Display hash table
    void display() {
        HASHED_NODE* temp = l->HEAD;
        while (temp != NULL) {
            cout << "Bucket " << temp->index << ": ";
            NODE* st = temp->chainHead;
            if (st == NULL) {
                cout << "empty";
            } else {
                while (st != NULL) {
                    cout << "[Roll:" << st->roll_no << ", Name:" << st->name
                         << ", Marks:" << st->marks << "] -> ";
                    st = st->next;
                }
                cout << "NULL";
            }
            cout << endl;
            temp = temp->down;
        }
    }
};

// -------- MAIN --------
int main() {
    HASHED_LIST l;      // create 10 buckets
    HF h(&l);           // pass buckets to hash functions

    // insert students
    h.insert_at_end(11, 85, "Sumit");
    h.insert_at_end(22, 90, "Amit");
    h.insert_at_end(32, 78, "Neha");
    h.insert_at_end(41, 92, "Ravi");
    h.insert_at_end(15, 80, "Priya");

    // display hash table
    h.display();

    return 0;
}
