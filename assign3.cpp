/*assignment 3 ROLL_NO:23318; kaustubhneemkar
1. Understand how to use array of structures in C/C++.
2. Implement and apply different sorting algorithms: Bubble Sort, Insertion Sort, and Quick
Sort.
3. Implement and apply different searching algorithms: Linear Search and Binary Search.
4. Analyse performance: Passes, swaps, comparisons, and time complexity.*/

//in each of the sorting technique output each iteration seperately**********************************

#include <bits/stdc++.h>
using namespace std;
#define m 15 //setting a max upper limit to the strength of the class: 
struct studentdetail {
    int rollno;
    string name;
    float sgpa;
};

class myclass {
public:
    struct studentdetail s[m]; // structure array
    int n;

void inputdata() {
    cout << "Enter the number of students currently present (Max capacity = 15): ";
    cin >> n;

    if (n > m) {
        cout << "Error: the number " << n << " is out of range (max " << m << ").\n";
        n = 0; // reset to avoid invalid state
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "\nEnter the name of the student: ";
        cin >> s[i].name;
        cout << "Enter the roll number of the student: ";
        cin >> s[i].rollno;
        cout << "Enter the SGPA of the student: ";
        cin >> s[i].sgpa;
    }
    cout << "\nData entry completed.\n";
}

    void BUBBLE_SORT() {  // Bubble Sort (by roll number)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++) {
                if (s[j].rollno > s[j + 1].rollno) {
                    studentdetail temp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp;
                }
            }
        }
        cout << "\nSorted by Roll Number (Bubble Sort).\n";
    }

    // Insertion Sort (by name)
    void INSERTION_SORT() {
        for (int i = 1; i < n; i++) {
            studentdetail key = s[i];
            int j = i - 1;
            while (j >= 0 && s[j].name > key.name) {
                s[j + 1] = s[j];
                j--;
            }
            s[j + 1] = key;
        }
        cout << "\nSorted by Name (Insertion Sort).\n";
    }

    // Binary Search (by name)
    void BINARY_SEARCH() {
        INSERTION_SORT(); // ensure names are sorted
        string NAME;
        cout << "\nEnter the name to be searched: ";
        cin >> NAME;

        int l = 0, h = n - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (NAME == s[mid].name) {
                cout << "Yes, " << NAME << " is present (Roll No: " << s[mid].rollno
                     << ", SGPA: " << s[mid].sgpa << ")\n";
                return;
            } else if (NAME < s[mid].name) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << "The name " << NAME << " does not exist in the list.\n";
    }

    // Linear Search (by SGPA)
    void LINEAR_SEARCH() {
        float SGPA;
        cout << "\nEnter the SGPA to be searched: ";
        cin >> SGPA;

        bool found = false;
        for (int i = 0; i < n; i++) {
                cout << "Yes, Roll No " << s[i].rollno << " (" << s[i].name
                     << ") has SGPA " << SGPA << "\n";
                found = true;
        }
        if (!found)
            cout << "No student has SGPA: " << SGPA << "\n";
    }

    // Quick Sort helpers (by SGPA, descending)
    int partition(int low, int high) {
        float pivot = s[high].sgpa; 
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (s[j].sgpa > pivot) { // > for descending
                i++;
                swap(s[i], s[j]);
            }
        }
        swap(s[i + 1], s[high]);
        return (i + 1);
    }

    void QUICK_SORT(int low, int high) {
        if (low < high) {
            int pi = partition(low, high);
            QUICK_SORT(low, pi - 1);
            QUICK_SORT(pi + 1, high);
        }
    }

    // Display (tabular format)
    void display() {
        if (n == 0) {
            cout << "\nNo student data available!\n";
            return;
        }

        cout << fixed << setprecision(2); // format SGPA nicely
        cout << "\nRoll Number\t\tSGPA\t\t\tName\n";
        cout << "------------------------------------------------------------\n";

        for (int i = 0; i < n; i++) {
            cout << s[i].rollno << "\t\t\t";
            cout << s[i].sgpa << "\t\t\t";
            cout << s[i].name << "\n";
        }

        cout << "------------------------------------------------------------\n";
        cout << "Data displayed successfully\n";
    }
};

int main() {
    myclass c;
    int choice;

    c.inputdata();

    do {
        cout << "\n========== MENU ==========\n";
        cout << "1. Display all student details\n";
        cout << "2. Bubble Sort by Roll Number\n";
        cout << "3. Insertion Sort by Name\n";
        cout << "4. Binary Search by Name\n";
        cout << "5. Linear Search by SGPA\n";
        cout << "6. Quick Sort by SGPA (Descending)\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            c.display();
            break;
        case 2:
            c.BUBBLE_SORT();
            c.display();
            break;
        case 3:
            c.INSERTION_SORT();
            c.display();
            break;
        case 4:
            c.BINARY_SEARCH();
            break;
        case 5:
            c.LINEAR_SEARCH();
            break;
        case 6:
            if (c.n > 0) {
                c.QUICK_SORT(0, c.n - 1);
                cout << "\nSorted by SGPA (Descending).\n";
                c.display();
            } else {
                cout << "\nNo data to sort.\n";
            }
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

