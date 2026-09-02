#include<iostream>
using namespace std;

class Student_info{
    public:
        string name;
        int roll;
        float sub[5];
        void take_info(){
            cout<<"Enter name of Student:";
            getline(cin, name);
            cout<<"Enter roll no. of Student:";
            cin>>roll;
            for(int i=0;i<5;i++){
                cout<<"Enter marks of subject "<<i+1<<":";
                cin>>sub[i];
            }
        }
        void print_info(){
            cout<<"Name of Student:"<<name<<endl;
            cout<<"Roll no. of student:"<<roll<<endl;
            for(int i=1;i<5;i++){
                cout<<"Marks of subject "<<i+1<<":"<<sub[i]<<endl;
            }
        }
        void print_aggre(){
            float total=0;
            for(int i=0;i<5;i++){
                total+=sub[i];
            }
            cout<<"Total marks="<<total<<endl;
            cout<<"Percentage of student:"<<total/5;
        }
};
int main(){
    int choice,n; //n=no. of students
    int i=0;
    char response;

    cout<<"Enter totl no. of students:";
    cin>>n;
    Student_info s[n];

    do{
        if(i==4){
            break;
        }
        Student_info s[i];
        s[i].take_info();
        int choice;
        cout<<"Press 1 for Info display"<<endl<<"Press 2 for marksheet:"<<endl<<"Press 3 for Exit:"<<endl;
        cin>>choice;

        switch(choice){
            case 1:
                s[i].print_info();
                break;
            case 2:
                s[i].print_aggre();
                break;
            case 3:
                cout<<"Exit complete!";
                break;
            default:
                cout<<"Choose valid option!";
        }
        cout<<"Do you wish to proceed further?(y/n):";
        cin>>response;
        i+=1;
    }while(response=='y');

    return 0;
}