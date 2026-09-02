#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int rollNo;
    string name;
    float marks;
public:
    Student(){}
    Student(int r, string n, float m) {
        rollNo = r;
        name = n;
        marks = m;
    }
    float getMarks() {return marks; }

    void display() {cout << "Roll No:" <<rollNo<< "\tName:" << name<< "\tMarks:" << marks << endl; }
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
        //////  
        cout << "\nEnter Roll No:";
        cin >> rollNo;
        //////
        cin.ignore();
        cout << "Enter Name:";
        //cin >> name;
        getline(cin,name);
        /////
        cout << "Enter Marks:";
        cin >> marks;
        ////
        students[n] = Student(rollNo, name, marks);
        n++;

        cout << "Student added!\n";
    }
    void displayStudents() {
        if (n == 0) {
            cout << "\nNo student records available.\n";
            return;
        }
        cout << "\n======Student Records===\n";
        for (int i = 0; i < n; i++) {
            students[i].display();
        }
    }

    void insertionSort() {//insertion sort sorting displayed in ascending order
        for (int i = 1; i < n; i++) {
            Student key = students[i];
            int j = i - 1;
            while (j >= 0 && students[j].getMarks() > key.getMarks()) {
                students[j + 1] = students[j];
                j--;
            }

            students[j+1] = key;
        }

        cout <<"\nStudents sorted using Insertion Sort (Ascending).\n";
    }

    
    void bubbleSort(){// bubble sort sorting displayed in descensing order
        for (int i = 0;i<n-1;i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (students[j].getMarks() < students[j + 1].getMarks()) {
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
        cout << "\n///////////////Student Marks Management System//////////\n";
        cout << "1.Add Student\n";
        cout << "2.Display Students\n";
        cout << "3.Sort using Insertion Sort (Ascending)\n";
        cout << "4.Sort using Bubble Sort (Descending)\n";
        cout << "5.Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

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

    } while(choice!=5);

    return 0;
}