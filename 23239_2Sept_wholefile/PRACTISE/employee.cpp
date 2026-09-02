#include<iostream>
using namespace std;

class Employee{
    private:
    string emp_name;
    int emp_id;
    float emp_salary;
    public:
    Employee(string name,int id,float salary){
        emp_name=name;
        emp_id=id;
        emp_salary=salary;
    }
    void print_info(){
        cout<<"Name of employee:"<<emp_name<<endl;
        cout<<"Employee ID:"<<emp_id<<endl;
        cout<<"Emplyee salary:"<<emp_salary<<endl;
    }
    ~Employee(){
        cout<<"----------End of Employee Info-------------";
    }
};
int main(){
    string name_;
    int id_;
    float salary_;

    cout<<"Input Employee name:";
    getline(cin, name_);
    cout<<"Input Employee ID:";
    cin>>id_;
    cout<<"Input Employee Salary:";
    cin>>salary_;

    Employee E1(name_,id_,salary_);
    E1.print_info();
    return 0;
}
