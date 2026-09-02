// A. Implement the Stack using an Array and Linked List to perform basic operations such as
// Push, Pop, Peek (Top), Display and Check whether Stack is Empty or Full.

#include<iostream>
using namespace std;
class Stack{
    public:
    int max_size;
    int top=-1;
    int *arr;
    void take_size(int n){
        max_size=n;
        arr=new int[max_size];
    }
    void push(int val){
        if(top==max_size-1){
            cout<<"\nStack overflow!\n";
            return;
        }
        arr[top+1]=val;
        top+=1;


    }
    void display_top(){
        if(top==-1){cout<<"\nStack is empty!\n";return;}
        cout<<arr[top]<<endl;}
    void pop(){
        if(top==-1){
            cout<<"Stack underflow!\n";
            return;
        }
        cout<<"Element popped:"<<arr[top];
        top-=1;
    }
    void isEmpty(){
        if(top==-1){cout<<"\nStack is empty!\n";}
        else{cout<<"\nStack is not empty.....\n";}
    }
    void isFull(){
        if(top==max_size-1){cout<<"Stack overflow!\n";}
        else{cout<<"Stack is not full,elements can be pushed!\n";}
    }
    ~Stack(){
        delete[] arr;
    }
};
int main(){
    Stack st;
    int ms;
    cout<<"Enter max size of stack:";
    cin>>ms;
    st.take_size(ms);

    // st.display_top();
    // st.isEmpty();
    // int temp;
    // cout<<"Enter element to be pushed:";
    // cin>>temp;
    // st.push(temp);
    // st.display_top();
    // st.isEmpty();
    int choice;
    int temp;
    do{
        cout<<"1.Push value\t2.Pop value\t3.View top\n4.View if Empty\t5.View if Full\n6.Exit\n";
        cout<<"Enter choice:";
        cin>>choice;

        switch(choice){
            case 1:
            cout<<"Enter value to be pushed;";
            cin>>temp;
            st.push(temp);
            break;

            case 2:
            st.pop();
            break;

            case 3:
            st.display_top();
            break;

            case 4:
            st.isEmpty();
            break;

            case 5:
            st.isFull();
            break;

            case 6:
            cout<<"Exiting....";
            break;

            default:
            cout<<"Invalid option!";
        }


    }while(choice!=6);
    return 0;
}