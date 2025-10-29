/*assignment 3 ROLL_NO:23318; kaustubhneemkar
1. Understand how to use array of structures in C/C++.
2. Implement and apply different sorting algorithms: Bubble Sort, Insertion Sort, and Quick
Sort.
3. Implement and apply different searching algorithms: Linear Search and Binary Search.
4. Analyse performance: Passes, swaps, comparisons, and time complexity.*/

//in each of the sorting technique output each iteration seperately**********************************

#include <bits/stdc++.h>
using namespace std;

class studentdetail {
public:
    int rollno;
    string name;
    float sgpa;
};

class student {
public:
    int n;
    studentdetail s[20];

    void accept() {//function to take input details rom the user
        cout << "Enter number of students: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            cout << "\nEnter details of student " << i + 1 << ":\n";
            cout << "Roll No: ";
            cin >> s[i].rollno;
            cout << "Name: ";
            cin >> s[i].name;
            cout << "SGPA: ";
            cin >> s[i].sgpa;
        }
    }

    void display() {//function to display the details 
        cout << "\n---- Student Records ----\n";
        cout << "RollNo" <<"\t\t\t" << "Name" << "\t\t\t" << "SGPA\n";
        for (int i = 0; i < n; i++) {
            cout << s[i].rollno<< "\t\t\t"<< s[i].name<< "\t\t\t" << s[i].sgpa << endl;
        }
    }

    // Bubble Sort (by Roll No)
    void BUBBLE_SORT() {
        cout << "\nBubble Sort Iterations:\n";
        for (int i = 0; i < n - 1; i++) {//n-1 because the last element is always sorted after sorting the rest all elements
            cout << "Iteration " << i + 1 << ": ";//this line just shows the number of iteration going on
            for (int j = 0; j < n - i - 1; j++) {
                if (s[j].rollno > s[j + 1].rollno) {
                    studentdetail temp = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = temp;
                }
            }
            for (int k = 0; k < n; k++)
                cout << s[k].rollno << " ";
            cout << endl;
        }
    }

    // Insertion Sort (by Name)
    void INSERTION_SORT() {
        cout << "\nInsertion Sort Iterations:\n";
        for (int i = 1; i < n; i++) {
            studentdetail key = s[i];
            int j = i - 1;
            while (j >= 0 && s[j].name > key.name) {
                s[j + 1] = s[j];
                j--;
            }
            s[j + 1] = key;

            cout << "Iteration " << i << ": ";
            for (int k = 0; k < n; k++)
                cout << s[k].name << " ";
            cout << endl;
        }
    }

    // Binary Search (by Name)
    void BINARY_SEARCH() {
        string key;
        cout << "Enter name to search: ";
        cin >> key;

        // Sort by Name first
        INSERTION_SORT();//this is necessary because the bonary serach cn be applied only on sorted data

        int low = 0, high = n - 1, mid;
        int step = 1;
        while (low <= high) {
            mid = (low + high) / 2;
            cout << "Step " << step++ << ": low=" << low << " mid=" << mid << " high=" << high << endl;
            if (s[mid].name == key) {
                cout << "Student found: RollNo=" << s[mid].rollno << " Name=" << s[mid].name << " SGPA=" << s[mid].sgpa << endl;
                return;
            } else if (s[mid].name < key) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        cout << "Student not found.\n";
    }

    // Linear Search (by SGPA)
    void LINEAR_SEARCH() {
        float key;
        cout << "Enter SGPA to search: ";
        cin >> key;

        bool found = false;
        for (int i = 0; i < n; i++) {
            cout << "Checking index " << i << " (SGPA=" << s[i].sgpa << ")\n";
            if (s[i].sgpa == key) {
                cout << "Found: RollNo=" << s[i].rollno << " Name=" << s[i].name<< " SGPA=" << s[i].sgpa << endl;
                found = true;
            }
        }
        if (!found) cout << "No student with SGPA " << key << " found.\n";
    }

    // Quick Sort helpers (by SGPA, descending) with depth track
    int partition(int low, int high) {
        float pivot = s[high].sgpa;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (s[j].sgpa > pivot) {
                i++;
                studentdetail temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
        studentdetail temp = s[i + 1];
        s[i + 1] = s[high];
        s[high] = temp;
        return (i + 1);
    }

    void QUICK_SORT(int low, int high, int depth = 1) {
        if (low < high) {
            int pi = partition(low, high);

            cout << "Depth " << depth << " ,Pivot at index " << pi << " (SGPA=" << s[pi].sgpa << "): ";
            for (int k = low; k <= high; k++)
                cout << s[k].sgpa << " ";
            cout << endl;

            QUICK_SORT(low, pi - 1, depth + 1);
            QUICK_SORT(pi + 1, high, depth + 1);
        }
    }
};

int main() {
    student c;
    c.accept();

    int choice;
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
            c.QUICK_SORT(0, c.n - 1);
            cout << "\nSorted by SGPA (Descending).\n";
            c.display();
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

