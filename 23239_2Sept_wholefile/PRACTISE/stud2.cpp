#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int roll;
    string name;
    int marks[5];

public:
    void addStudent(){
        cout<<"\nEnter Roll Number: ";
        cin>>roll;

        cin.ignore();
        cout <<"Enter Name: ";
        getline(cin,name);

        cout << "Enter Marks of 5 Subjects:\n";
        for (int i=0; i<5;i++)
        {
            cout<< "Subject "<<i+1<< ": ";
            cin>>marks[i];
        }
    }

    void displayMarks(){
        cout<< "\nMarks: ";
        for(int i = 0; i<5;i++){
            cout << marks[i]<<" ";
        }
        cout<<endl;
    }

    void displayInfo()
    {
        cout << "\nRoll Number: " << roll;
        cout << "\nName: " << name;
        cout << "\nMarks: ";
        for (int i = 0; i<5;i++)
            cout << marks[i] << " ";
        cout << endl;
    }

    void displayAggregate()
    {
        int total = 0;
        for (int i =0; i<5; i++){
            total+=marks[i];
        }
        float avg =total/5.0;

        cout<< "\nTotal Marks = "<<total;
        cout<< "\nAverage = " <<avg<< endl;
    }
};

int main()
{
    Student s[5];
    int choice;
    do{
        cout << "\n---- MAIN MENU ------\n";
        cout << "1. Add Details of 5 Students\n";
        cout << "2. Display Marks of All Students\n";
        cout << "3. Particular Student Menu\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice){
        case 1:
            for(int i = 0; i < 5; i++){
                cout << "\nEnter Details of Student " << i + 1 << endl;
                s[i].addStudent();
            }
            break;

        case 2:
            for (int i = 0; i < 5; i++){
                cout << "\nStudent " << i + 1;
                s[i].displayMarks();
            }
            break;

        case 3:
        {
            int n;
            cout << "\nEnter Student Number (1-5): ";
            cin >> n;
            if(n < 1|| n > 5){
                cout << "Invalid Student Number!\n";
                break;
            }
            int ch;
            do{
                cout << "\n----- STUDENT MENU -----\n";
                cout << "1. View Aggregate\n";
                cout << "2. View Student Information\n";
                cout << "3. Back to Main Menu\n";
                cout << "Enter Choice: ";
                cin >> ch;
                switch (ch){
                case 1:
                    s[n - 1].displayAggregate();
                    break;

                case 2:
                    s[n - 1].displayInfo();
                    break;

                case 3:
                    cout << "Returning to Main Menu...\n";
                    break;

                default:
                    cout << "Invalid Choice!\n";
                }

            }while(ch!=3);
            break;
        }
        case 4:
            cout << "Program Ended.\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while(choice!=4);

    return 0;
}

