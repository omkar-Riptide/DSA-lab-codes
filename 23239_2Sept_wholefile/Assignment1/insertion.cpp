#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        next=nullptr;
        data=val;
    }
};
class LinkedList{
    public:
    Node* head;
    LinkedList(){
        head=nullptr;
    }
    //Node* curr=head;
///////////////////////////////////////////////////////////////////
    void insert_end(int val){
        Node* newnode=new Node(val);
        if (head==nullptr){
            head=newnode;
            return;
        }
        Node* curr = head;
        while(curr->next != nullptr){
            curr=curr->next;
        }
        curr->next=newnode;
    }
//////////////////////////////////////////////////////////////////
    void insert_beg(int val){
        Node* newnode=new Node(val);
        if(head==nullptr){
            head=newnode;
            return;
        }
        Node* curr=head;
        head=newnode;
        head->next=curr;
    }
/////////////////////////////////////////////////////////////////////
    void search(int val){
        if(head==nullptr){
            cout<<"List is Empty!";
            return;
        }
        int index=0;
        Node* curr=head;
        while(curr!=nullptr){
            if(curr->data==val){
                cout<<"Val found at index:"<<index<<endl;
                return;
            }          
            index++;
            curr=curr->next;           
        }
        cout<<"Value not found in list!";

    }
//////////////////////////////////////////////////////////////////////
    void insert_bw(int val,int k){
        Node* newnode=new Node(val);
        if(head==nullptr){
            head=newnode;
            return;
        }
        //int i=0;
        Node* curr=head;
        for(int i=0;i<k-1;i++){
            curr=curr->next;
        }
        newnode->next=curr->next;
        curr->next=newnode;

    }
/////////////////////////////////////////////////////////////////////
    void display(){
        if (head==nullptr){
            cout<<"List is empty" << endl;
            return;
        }

        Node* curr = head;
        while(curr != nullptr){
            cout << curr->data << "->";
            curr=curr->next;
        }
        cout<<"NULL"<< endl;
    }
};
int main(){
    LinkedList l1;
    // l1.insert_end(5);
    // l1.insert_end(88);
    // l1.display();

    // l1.insert_beg(91);
    // l1.display();

    // l1.search(5);

    // l1.insert_bw(24,1);
    // l1.display();

    int choice,val,idx;
    do{
        cout<<"\n1.Insert at the end:"<<endl<<"2.Insert at beginning\n"<<"3.Search element:\n";
        cout<<"4.Insert in between at index k\n"<<"5.Display:\n"<<"6.Exit.....\n"<<"Enter choice:";
        cin>>choice;

        switch (choice)
        {
        case 1:
            cout<<"Value to be inserted at end:";
            cin>>val;
            l1.insert_end(val);
            break;
        case 2:
            cout<<"Value to be inserted at beginning:";
            cin>>val;
            l1.insert_beg(val);
            break;
        case 3:
            cout<<"Value to be searched:";
            cin>>val;
            l1.search(val);
            break;
        case 4:
            cout<<"Value to be inserted at between:";
            cin>>val;
            cout<<"Element to be inserted at index:";
            cin>>idx;
            l1.insert_bw(val,idx);
            break;
        case 5:
            l1.display();
            break;
        case 6:
            cout<<"Exiting.........";
            break;
        
        default:
            cout<<"Invalid option selection!";
        }

    }while(choice!=6);
    
    return 0;
}