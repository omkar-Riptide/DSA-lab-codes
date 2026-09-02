#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    string name;
    string phone;
    string email;

    Node* next;

    Node(string n, string p, string e)
    {
        name = n;
        phone = p;
        email = e;
        next = NULL;
    }
};

class ContactList
{
private:
    Node* head;

public:
    ContactList()
    {
        head = NULL;
    }

    void addContact()
    {
        string name, phone, email;

        cout << "\nEnter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Phone Number: ";
        getline(cin, phone);

        cout << "Enter Email: ";
        getline(cin, email);

        Node* newNode = new Node(name, phone, email);

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;

        cout << "\nContact Added Successfully!\n";
    }

    void displayContacts()
    {
        if(head == NULL)
        {
            cout << "\nNo Contacts Available.\n";
            return;
        }

        Node* temp = head;

        cout << "\n----------- CONTACT LIST -----------\n";

        while(temp != NULL)
        {
            cout << "Name  : " << temp->name << endl;
            cout << "Phone : " << temp->phone << endl;
            cout << "Email : " << temp->email << endl;
            cout << "//////////////////////////////////// \n";

            temp = temp->next;
        }
    }

    void searchContact()
    {
        if(head == NULL)
        {
            cout << "\nContact List is Empty.\n";
            return;
        }

        string name;

        cout << "\nEnter Name to Search: ";
        cin.ignore();
        getline(cin, name);

        Node* temp = head;

        while(temp != NULL)
        {
            if(temp->name == name)
            {
                cout << "\nContact Found!\n";
                cout << "Name:" << temp->name << endl;
                cout << "Phone:" << temp->phone << endl;
                cout << "Email:" << temp->email << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "\nContact Not Found.\n";
    }

    void updateContact()
    {
        if(head == NULL)
        {
            cout << "\nContact List is Empty.\n";
            return;
        }

        string name;

        cout << "\nEnter Name to Update: ";
        cin.ignore();
        getline(cin, name);

        Node* temp = head;

        while(temp != NULL)
        {
            if(temp->name == name)
            {
                cout << "Enter New Phone Number: ";
                getline(cin, temp->phone);

                cout << "Enter New Email: ";
                getline(cin, temp->email);

                cout << "\nContact Updated Successfully!\n";
                return;
            }

            temp = temp->next;
        }

        cout << "\nContact Not Found.\n";
    }

    void deleteContact()
    {
        if(head == NULL)
        {
            cout << "\nContact List is Empty.\n";
            return;
        }

        string name;

        cout << "\nEnter Name to Delete: ";
        cin.ignore();
        getline(cin, name);

        Node* temp = head;
        Node* prev = NULL;

        while(temp != NULL)
        {
            if(temp->name == name)
            {
                if(prev == NULL)
                {
                    head = head->next;
                }
                else
                {
                    prev->next = temp->next;
                }

                delete temp;

                cout << "\nContact Deleted Successfully!\n";
                return;
            }

            prev = temp;
            temp = temp->next;
        }

        cout << "\nContact Not Found.\n";
    }
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
    }
};

int main()
{
    ContactList contacts;

    int choice;

    do
    {
        cout << "\n/////////////////////////////////////////////\n";
        cout << "      CONTACT MANAGEMENT SYSTEM\n";
        cout << "///////////////////////////////////////////////\n";
        cout << "1. Add Contact\n";
        cout << "2. Display Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Update Contact\n";
        cout << "5. Delete Contact\n";
        cout<<  "6. Reverse contact list";
        cout << "7. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                contacts.addContact();
                break;

            case 2:
                contacts.displayContacts();
                break;

            case 3:
                contacts.searchContact();
                break;

            case 4:
                contacts.updateContact();
                break;

            case 5:
                contacts.deleteContact();
                break;
            
            case 6:
                contacts.reverse_ll();
                break;

            case 7:
                cout << "\nExiting.........\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 7);

    return 0;
}



