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
        display();
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
        display();
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
        display();
    }
////////////////////////////////////////////////////////////////////
    int size_ll(){
        int size;
        if(head==nullptr){
            size=0;
        }
        Node* temp=head;
        while(temp!=nullptr){
            size++;
            temp=temp->next;
        }
        return size;
    }
    //////////////////////////////////////////////////////////////////
    void delete_beg(){
        if(head==nullptr){
            cout<<"List empty,cant delete element in beginning!\n";
        }
        if(head->next==nullptr){
            head=nullptr;
        }
        if (head==nullptr){
            cout<<"List is empty!" << endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=nullptr;
        delete temp;
        display();

    }
    ///////////////////////////////////////////////////////////////
    void delete_end(){
        if (head == nullptr){
            cout << "List empty,cant delete elements!";
            return;
        }
        if (head->next == nullptr){
            head=nullptr;
        }
        if (head==nullptr){
            cout<<"List is empty" << endl;
            return;
        }
        Node *curr = head;
        while (curr->next->next != nullptr){
            curr = curr->next;
        }
        curr->next = nullptr;
        display();
    }
    ///////////////////////////////////////////////////////////
    void delete_atK(int k){
        // cout<<"Index at which element is to be deleted:";
        // cin>>k;
        if(head==nullptr){
            cout<<"List empty,cant delete elements!";
            return;
        }
        int size=size_ll();
        if(size==1){
            delete_beg();
        }

        else if(k==size-1){
            delete_end();
        }
        else if(k>size-1){
            cout<<"Invalid index,length of linked list insufficient!\n";
        }

        Node* curr=head;
        for(int i=0;i<k-1;i++){
            curr=curr->next;
        }
        Node* curr2=curr->next;
        curr->next=curr2->next;
        delete curr2;
        display();
    }
    //////////////////////////////////////////////////////////////////
    void reverse_ll(){
        Node* prev=nullptr;
        Node*  curr=head;
        Node* nextnode=nullptr;

        while(curr!=nullptr){
            nextnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextnode;
        }
        head=prev;
        display();
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
    int choice,val,idx,k;
    do{
        cout<<"\n1.Insert at the end:"<<endl<<"2.Insert at beginning\n"<<"3.Search element:\n";
        cout<<"4.Insert in between at index k\n"<<"5.Delete from beginning:\n"<<"6.Delete from end:\n";
        cout<<"7.Delete in between:\n"<<"8.Reverse linked list:\n"<<"9.Display:\n"<<"10.Exit:";
        cout<<"\nEnter choice:";
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
            l1.delete_beg();
            break;
        case 6:
            l1.delete_end();
            break;
        
        case 7:
            cout<<"Insert index k of deletion:";
            cin>>k;
            l1.delete_atK(k);
            break;
            
        case 8:
            l1.reverse_ll();
            break;
        case 9:
            l1.display();
            break;
        case 10:
            cout<<"Exiting........";
            break;
        default:
            cout<<"Invalid option selection!";
        }

    }while(choice!=10);
    
    return 0;
}