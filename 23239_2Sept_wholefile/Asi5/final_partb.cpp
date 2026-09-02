// Develop a Student Record Management System that stores student details and searches for a
// student by roll number or name using the Linear Search algorithm. The program should
// display the student's details if found; otherwise, it should display an appropriate message.
#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int id;
    float cgpa;
    string name, dept;

    void take_info() {
        cout<<"Enter 5-digit student roll no.: ";
        cin>>id;

        cin.ignore();

        cout<<"Enter name of the student: ";
        getline(cin, name);

        cout<<"Enter department of student: ";
        cin >> dept;

        cout << "Enter cgpa of student: ";
        cin >> cgpa;
    }
    void display_by_name(string name, Student *array, int length) {
        bool found = false;
        for (int i = 0; i < length; i++) {
            if (name == array[i].name) {
                cout << "\nName of Student: " << array[i].name << endl;
                cout << "ID of student: " << array[i].id << endl;
                cout << "Department of student: " << array[i].dept << endl;
                cout << "CGPA of student: " << array[i].cgpa << endl;

                found = true;
                break;
            }
        }
        if(found==false) {
            cout <<"Student name not found!" << endl;
        }
    }
    void display_by_id(int id, Student *array, int length) {
        bool found = false;
        for (int i = 0; i < length; i++){
            if (id == array[i].id) {
                cout <<"\nName of Student:"<< array[i].name<<endl;
                cout <<"ID of student:" << array[i].id<<endl;
                cout <<"Department of student:" << array[i].dept << endl;
                cout <<"CGPA of student:" << array[i].cgpa << endl;
                found = true;
                break;
            }
        }
        if (found==false) {
            cout << "Student ID not found!" << endl;
        }
    }
};

int main() {
    Student s;
    Student *arr;
    int n;

    cout << "Enter no. of student records: ";
    cin >> n;

    arr = new Student[n];
    for (int i = 0; i < n; i++) {
        cout << "\nEnter info of student: " << i + 1 << endl;
        arr[i].take_info();
    }
    cout << "\n////////////////// Menu //////////////\n";
    cout << "1. Search by name\n";
    cout << "2. Search by id\n";
    cout << "3. Exit\n";

    int choice;
    int main_id;
    string main_name;

    do {
        cout << "\nEnter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cin.ignore();
                cout << "Enter name to be searched: ";
                getline(cin, main_name);

                s.display_by_name(main_name, arr, n);
                break;

            case 2:
                cout << "Enter id to be searched: ";
                cin >> main_id;

                s.display_by_id(main_id, arr, n);
                break;

            case 3:
                cout << "Exiting......";
                break;

            default:
                cout << "Invalid option";
        }

    } while (choice != 3);
    delete[] arr;
  return 0;
}


// Enter no. of student records: 3

// Enter info of student: 1
// Enter 5-digit student roll no.: 45671
// Enter name of the student: Omkar Kinkar
// Enter department of student: IT
// Enter cgpa of student: 9.85

// Enter info of student: 2
// Enter 5-digit student roll no.: 12345
// Enter name of the student: Aayush Sirsavkar
// Enter department of student: CSE
// Enter cgpa of student: 9.23

// Enter info of student: 3
// Enter 5-digit student roll no.: 23456
// Enter name of the student: Siddharth Patil
// Enter department of student: AIML
// Enter cgpa of student: 9.5

// ////////////////// Menu //////////////
// 1. Search by name
// 2. Search by id
// 3. Exit

// Enter choice: 2
// Enter id to be searched: 12345

// Name of Student: Aayush Sirsavkar
// ID of student: 12345
// Department of student: CSE
// CGPA of student: 9.23

// Enter choice: 1
// Enter name to be searched: Omkar Kinkar

// Name of Student: Omkar Kinkar
// ID of student: 45671
// Department of student: IT
// CGPA of student: 9.85

// Enter choice: 3
// Exiting......