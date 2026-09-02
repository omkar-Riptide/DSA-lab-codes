#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};
class LinkedList{
    public:
        Node* head;
        LinkedList(){
            head=nullptr;
        }
        //Node* curr=head;

        void insert(int val){
            Node* newnode=new Node(val);
            if(head==nullptr){
                head=newnode;
                return;
            }
            Node* curr = head;
            while (curr->next!=nullptr){
            curr=curr->next;
            }
            curr->next = newnode;
        }
        void display(){
            if(head==nullptr){
                cout<<"List is empty";
            }
            Node* curr =head;
            
            while(curr!=nullptr){
                cout<<curr->data<<"->";
                curr=curr->next;
            }
            cout<<"NULL";
        }
};
int main(){
    int choice;
    LinkedList l1;
    int val;
    do{
        cout<<"\n1.APPEND at end"<<endl<<"2.Display LinkedList\n"<<"ENTER CHOICE:";
        cin>>choice;

        switch(choice){
            case 1:
                cout<<"Enter value:";
                cin>>val;
                l1.insert(val);
                break;
            case 2:
                l1.display();
                break;
            case 3:
                cout<<"EXITING.......";
            default:
                cout<<"Invalid operation!";
        }
    }while(choice!=3);
    return 0;
}