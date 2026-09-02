#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        next = nullptr;
        prev = nullptr;
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

    ///////////////////////////////////////////////////////////////////
    void insert_end(int val)
    {                                       // DONE
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = newnode;
            return;
        }
        Node *curr = head;
        while (curr->next != nullptr)
        {
            curr = curr->next;
        }
        curr->next = newnode;
        newnode->prev = curr;
        display();
    }
    //////////////////////////////////////////////////////////////////
    void insert_beg(int val)
{
    Node *newnode = new Node(val);

    if (head != nullptr)
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    else
    {
        head = newnode;
    }

    display();
}
    /////////////////////////////////////////////////////////////////////
    void search(int val)
    {                                   //DONE
        if (head == nullptr)
        {
            cout << "List is Empty!";
            return;
        }
        int index = 0;
        Node *curr = head;
        while (curr != nullptr)
        {
            if (curr->data == val)
            {
                cout << "Val found at index:" << index << endl;
                return;
            }
            index++;
            curr = curr->next;
        }
        cout << "Value not found in list!";
    }
    //////////////////////////////////////////////////////////////////////
    void insert_bw(int val, int k)
    {                                                       // DONE
        Node *newnode = new Node(val);
        if (head == nullptr)
        {
            head = newnode;
            return;
        }
    
        Node *curr = head;
        for (int i = 0; i < k - 1; i++)
        {
            curr = curr->next;
        }
        Node *curr2 = curr->next;
        curr->next = newnode;
        newnode->prev;

        curr2->prev = newnode;
        newnode->next = curr2;
        display();
    }
    void display()
    { // displays in forward direction
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *curr = head;
        while (curr != nullptr)
        {
            cout << curr->data << "<->";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
    int size_ll()
    {
        int size;
        if (head == nullptr)
        {
            size = 0;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            size++;
            temp = temp->next;
        }
        return size;
    }
    //////////////////////////////////////////////////////////////////
    void delete_beg()
    {                                               //DONE
        if (head == nullptr)
        {
            cout << "List empty,cant delete element in beginning!\n";
        }
        if (head->next == nullptr)
        {
            head = nullptr;
        }
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }
        // Node *temp = head;
        // head = head->next;
        // temp->next = nullptr;
        // delete temp;
        Node* temp=head;
        head=head->next;

        head->prev=nullptr;
        temp->next=nullptr;

        delete temp;
        display();
    }
    ///////////////////////////////////////////////////////////////
    void delete_end()
    {                                              //DONE
        if (head == nullptr)
        {
            cout << "List empty,cant delete elements!";
            return;
        }
        if (head->next == nullptr)
        {
            head = nullptr;
        }
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *curr = head;
        while (curr->next->next != nullptr)
        {
            curr = curr->next;
        }
        Node* curr2=curr->next;
        curr->next = nullptr;

        curr2->next=nullptr;
        curr2->prev=nullptr;
        delete curr2;
        display();
    }
    ///////////////////////////////////////////////////////////
    void delete_atK(int k)
    {                                                           //DONE
        // cout<<"Index at which element is to be deleted:";
        // cin>>k;
        if (head == nullptr)
        {
            cout << "List empty,cant delete elements!";
            return;
        }
        int size = size_ll();
        if (size == 1)
        {
            delete_beg();
        }

        else if (k == size - 1)
        {
            delete_end();
        }
        else if (k > size - 1)
        {
            cout << "Invalid index,length of linked list insufficient!\n";
        }

        Node *curr = head;
        for (int i = 0; i < k - 1; i++)
        {
            curr = curr->next;
        }
        Node *curr2 = curr->next;
        curr->next=curr2->next;
        curr2->next->prev=curr;

        curr2->next=nullptr;
        curr2->prev=nullptr;
        delete curr2;
        display();
    }
};
int main(){
    LinkedList l;
    // l.insert_beg(5);
    // //l.display();

    // l.insert_end(7);
    // l.insert_bw(8,1); //5 8 7 null
    // l.search(7); //2
    cout<<"...";
    l.insert_beg(8);
    l.insert_end(7);
    // l.insert_end(9);
    // cout<<"123";
    // l.insert_beg(10);
    // l.insert_beg(12);
    // l.insert_beg(14);
    // l.insert_beg(25);
    // l.insert_beg(27);
    // l.insert_beg(30);   // 30 27 25 14 12 10 98
    l.delete_beg();
    return 0;
}