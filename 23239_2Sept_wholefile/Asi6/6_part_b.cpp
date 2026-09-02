// Develop a Student Marks Management System that stores the marks of students (along with
// other details) and sorts them in ascending order using Insertion Sort and in descending order
// using Bubble Sort.


#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;

public:
    Student() {}

    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
    }

    float getMarks() {
        return marks;
    }

    void display() {
        cout << "Roll No: " << rollNo
             << "\tName: " << name
             << "\tMarks: " << marks << endl;
    }
};

class StudentManagement {
private:
    Student students[100];
    int n;

public:
    StudentManagement() {
        n = 0;
    }

    void addStudent() {
        int rollNo;
        string name;
        float marks;

        // -------- Roll Number Validation --------
        while (true) {
            string input;

            cout << "\nEnter 5-digit Roll No: ";
            cin >> input;

            // Check whether all characters are digits
            bool allDigits = true;

            for (char c : input) {
                if (!isdigit(c)) {
                    allDigits = false;
                    break;
                }
            }

            // Check exactly 5 digits
            if (allDigits && input.length() == 5) {
                rollNo = stoi(input);
                break;
            }

            cout << "Invalid Roll No! Please enter exactly 5 digits.\n";
        }

        // -------- Name Validation --------
        cin.ignore();

        while (true) {
            cout << "Enter Name: ";
            getline(cin, name);

            bool validName = true;

            if (name.empty()) {
                validName = false;
            }

            for (char c : name) {
                if (!isalpha(c) && c != ' ') {
                    validName = false;
                    break;
                }
            }

            if (validName) {
                break;
            }

            cout << "Invalid Name! Name should contain only alphabets and spaces.\n";
        }

        // -------- Marks Validation --------
        while (true) {
            cout << "Enter Marks: ";

            if (cin >> marks) {
                if (marks >= 0 && marks <= 100) {
                    break;
                }

                cout << "Invalid Marks! Marks should be between 0 and 100.\n";
            }
            else {
                cout << "Invalid input! Please enter numeric marks.\n";
                cin.clear();
                cin.ignore(1000, '\n');
            }
        }

        students[n] = Student(rollNo, name, marks);
        n++;

        cout << "Student added successfully!\n";
    }

    void displayStudents() {
        if (n == 0) {
            cout << "\nNo student records available.\n";
            return;
        }

        cout << "\n--- Student Records ---\n";

        for (int i = 0; i < n; i++) {
            students[i].display();
        }
    }

    // Insertion Sort - Ascending based on Marks
    void insertionSort() {
        for (int i = 1; i < n; i++) {
            Student key = students[i];
            int j = i - 1;

            while (j >= 0 &&
                   students[j].getMarks() > key.getMarks()) {

                students[j + 1] = students[j];
                j--;
            }

            students[j + 1] = key;
        }

        cout << "\nStudents sorted using Insertion Sort (Ascending).\n";
    }

    // Bubble Sort - Descending based on Marks
    void bubbleSort() {
        for (int i = 0; i < n - 1; i++) {

            for (int j = 0; j < n - i - 1; j++) {

                if (students[j].getMarks() <
                    students[j + 1].getMarks()) {

                    Student temp = students[j];
                    students[j] = students[j + 1];
                    students[j + 1] = temp;
                }
            }
        }

        cout << "\nStudents sorted using Bubble Sort (Descending).\n";
    }
};

int main() {

    StudentManagement system;
    int choice;

    do {
        cout << "\n/////////////// Student Marks Management System //////////\n";
        cout << "1.Add Student\n";
        cout << "2.Display Students\n";
        cout << "3.Sort using Insertion Sort (Ascending)\n";
        cout << "4.Sort using Bubble Sort (Descending)\n";
        cout << "5.Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        // Validate menu choice
        if (cin.fail()) {
            cout << "\nInvalid input! Please enter a number from 1 to 5.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {

            case 1:
                system.addStudent();
                break;

            case 2:
                system.displayStudents();
                break;

            case 3:
                system.insertionSort();
                system.displayStudents();
                break;

            case 4:
                system.bubbleSort();
                system.displayStudents();
                break;

            case 5:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}

