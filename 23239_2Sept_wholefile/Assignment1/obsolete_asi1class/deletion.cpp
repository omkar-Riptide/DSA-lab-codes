#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        next = nullptr;
        data = val;
    }
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }
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
    void insert_end(int val){
        Node *newnode = new Node(val);
        if (head == nullptr){
            head = newnode;
            return;
        }
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newnode;
    }
    /////////////////////////////////////////////
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

    }
    ///////////////////////////////////////////////
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

    }
    ///////////////////////////////////////////////////////////////
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
    }
    ///////////////////////////////////////////////////////////////
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
    //////////////////////////////////////////////////////////////
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

int main()
{
    LinkedList l1;
    l1.insert_end(5);
    l1.insert_end(6);
    l1.insert_end(7);
    l1.insert_end(8);
    l1.insert_end(9);
    l1.display();

    // l1.delete_end();
    // l1.display();
    
    // l1.delete_beg();
    // l1.display();

    // l1.delete_atK(1);
    // l1.display();
    l1.reverse_ll();
    l1.display();

    return 0;
}