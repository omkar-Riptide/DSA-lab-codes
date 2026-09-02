#include <iostream>
#include <string>
using namespace std;

class Student {
public:
    int id;
    float cgpa;
    string name, dept;

    void take_info() {
        cout << "Enter 5-digit student roll no.: ";
        cin >> id;

        cin.ignore();

        cout << "Enter name of the student: ";
        getline(cin, name);

        cout << "Enter department of student: ";
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

        if (!found) {
            cout << "Student name not found!" << endl;
        }
    }

    void display_by_id(int id, Student *array, int length) {
        bool found = false;

        for (int i = 0; i < length; i++) {
            if (id == array[i].id) {

                cout << "\nName of Student: " << array[i].name << endl;
                cout << "ID of student: " << array[i].id << endl;
                cout << "Department of student: " << array[i].dept << endl;
                cout << "CGPA of student: " << array[i].cgpa << endl;

                found = true;
                break;
            }
        }

        if (!found) {
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