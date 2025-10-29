#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

class Student {
public:
    int rollNo;
    char name[50], division[10], address[100], dob[15];
    float percentage;
    char grade;

    void input() {
        cout << "\nEnter Roll Number: ";
        cin >> rollNo;
        cin.ignore();
        cout << "Enter Name: ";
        cin.getline(name, 50);
        cout << "Enter Division: ";
        cin.getline(division, 10);
        cout << "Enter Address: ";
        cin.getline(address, 100);
        cout << "Enter Date of Birth (DD/MM/YYYY): ";
        cin.getline(dob, 15);
        cout << "Enter Percentage: ";
        cin >> percentage;
        cout << "Enter Grade: ";
        cin >> grade;
    }

    void display() const {
        cout << "\nRoll No: " << rollNo
             << "\nName: " << name
             << "\nDivision: " << division
             << "\nAddress: " << address
             << "\nDOB: " << dob
             << "\nPercentage: " << percentage
             << "\nGrade: " << grade
             << "\n-----------------------------------";
    }
};

string convertPipeToSpace(string line) {
    for (int i = 0; i < line.length(); i++) {
        if (line[i] == '|')
            line[i] = ' ';
    }
    return line;
}

void CreateAFile() {
    ofstream outFile("StudentData.txt", ios::out);
    if (!outFile) {
        cout << "\nError opening file!";
        return;
    }

    int n;
    cout << "\nEnter number of students to add: ";
    cin >> n;

    Student s;
    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Student " << i + 1 << ":";
        s.input();
        outFile << s.rollNo << "|" << s.name << "|" << s.division << "|"
                << s.address << "|" << s.dob << "|" << s.percentage << "|"
                << s.grade << "\n";
    }

    outFile.close();
    cout << "\nFile created and data stored successfully!";
}

void DisplayFileContents() {
    ifstream inFile("StudentData.txt", ios::in);
    if (!inFile) {
        cout << "\nFile not found!";
        return;
    }

    string line;
    cout << "\n--- Student Database ---";
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        cout << "\n" << convertPipeToSpace(line);
    }
    inFile.close();
    cout << "\n-------------------------";
}

void AddNewRecords() {
    ofstream outFile("StudentData.txt", ios::app);
    if (!outFile) {
        cout << "\nFile not found!";
        return;
    }

    Student s;
    cout << "\nEnter details of new student:";
    s.input();

    outFile << s.rollNo << "|" << s.name << "|" << s.division << "|"
            << s.address << "|" << s.dob << "|" << s.percentage << "|"
            << s.grade << "\n";

    outFile.close();
    cout << "\nRecord added successfully!";
}

void SearchRecord() {
    ifstream inFile("StudentData.txt");
    if (!inFile) {
        cout << "\nFile not found!";
        return;
    }

    int roll;
    cout << "\nEnter roll number to search: ";
    cin >> roll;

    bool found = false;
    string line;

    while (getline(inFile, line)) {
        if (line.empty()) continue;
        int pos = line.find('|');
        int fileRoll = atoi(line.substr(0, pos).c_str());
        if (fileRoll == roll) {
            cout << "\nRecord Found:\n" << convertPipeToSpace(line);
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nRecord not found!";
    inFile.close();
}

void ModifyRecord() {
    ifstream inFile("StudentData.txt");
    ofstream tempFile("Temp.txt");
    if (!inFile || !tempFile) {
        cout << "\nError opening file!";
        return;
    }

    int roll;
    cout << "\nEnter roll number to modify: ";
    cin >> roll;

    Student s;
    string line;
    bool found = false;

    while (getline(inFile, line)) {
        if (line.empty()) continue;
        int pos = line.find('|');
        int fileRoll = atoi(line.substr(0, pos).c_str());

        if (fileRoll == roll) {
            cout << "\nExisting Record: " << convertPipeToSpace(line);
            cout << "\nEnter new details:";
            s.input();
            tempFile << s.rollNo << "|" << s.name << "|" << s.division << "|"
                     << s.address << "|" << s.dob << "|" << s.percentage << "|"
                     << s.grade << "\n";
            found = true;
        } else {
            tempFile << line << "\n";
        }
    }

    inFile.close();
    tempFile.close();
    remove("StudentData.txt");
    rename("Temp.txt", "StudentData.txt");

    if (found)
        cout << "\nRecord modified successfully!";
    else
        cout << "\nRecord not found!";
}

void DeleteRecord() {
    ifstream inFile("StudentData.txt");
    ofstream tempFile("Temp.txt");
    if (!inFile || !tempFile) {
        cout << "\nError opening file!";
        return;
    }

    int roll;
    cout << "\nEnter roll number to delete: ";
    cin >> roll;

    string line;
    bool found = false;
    while (getline(inFile, line)) {
        if (line.empty()) continue;
        int pos = line.find('|');
        int fileRoll = atoi(line.substr(0, pos).c_str());

        if (fileRoll == roll) {
            cout << "\nRecord deleted successfully!";
            found = true;
            continue;
        } else {
            tempFile << line << "\n";
        }
    }

    inFile.close();
    tempFile.close();
    remove("StudentData.txt");
    rename("Temp.txt", "StudentData.txt");

    if (!found)
        cout << "\nRecord not found!";
}

int main() {
    int choice;
    do {
        cout << "\n\n===== STUDENT DATABASE MENU =====";
        cout << "\n1. Create File";
        cout << "\n2. Display All Records";
        cout << "\n3. Add New Record";
        cout << "\n4. Search Record";
        cout << "\n5. Modify Record";
        cout << "\n6. Delete Record";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: CreateAFile(); break;
        case 2: DisplayFileContents(); break;
        case 3: AddNewRecords(); break;
        case 4: SearchRecord(); break;
        case 5: ModifyRecord(); break;
        case 6: DeleteRecord(); break;
        case 7: cout << "\nExiting Program..."; break;
        default: cout << "\nInvalid choice!"; break;
        }
    } while (choice != 7);

    return 0;
}
