
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Node{
public:
    string name,phone,email;
    Node* next;
    Node(string n,string p,string e){name=n;phone=p;email=e;next=NULL;}
};

class ContactList{
    Node* head;
    bool validName(string s){
        if(s.empty()) return false;
        for(char c:s) if(!(isalpha((unsigned char)c)||c==' ')) return false;
        return true;
    }
    bool validPhone(string s){
        if(s.size()!=10) return false;
        for(char c:s) if(!isdigit((unsigned char)c)) return false;
        return true;
    }
    void sortContacts(){
        for(Node*i=head;i;i=i->next)
            for(Node*j=i->next;j;j=j->next)
                if(i->name>j->name){
                    swap(i->name,j->name);
                    swap(i->phone,j->phone);
                    swap(i->email,j->email);
                }
    }
public:
    ContactList(){head=NULL;}

    void addContact(){
        string name,phone,email;
        cin.ignore();
        do{
            cout<<"\nEnter Name: ";
            getline(cin,name);
            if(!validName(name)) cout<<"Invalid! Only alphabets and spaces allowed.\n";
        }while(!validName(name));
        do{
            cout<<"Enter Phone Number: ";
            getline(cin,phone);
            if(!validPhone(phone)) cout<<"Phone must be exactly 10 digits.\n";
        }while(!validPhone(phone));
        cout<<"Enter Email: "; 
        getline(cin,email);
        Node* n=new Node(name,phone,email);
        if(!head){
            head=n;
        }
        else{
            Node*t=head; 
            while(t->next)t=t->next; 
            t->next=n;
        }
        cout<<"\nContact Added Successfully!\n";
    }

    void displayContacts(){
        if(!head){cout<<"\nNo Contacts.\n";return;}
        sortContacts();
        for(Node*t=head;t;t=t->next){
            cout<<"\n=================================\n";
            cout<<"Name  : "<<t->name<<"\nPhone : "<<t->phone<<"\nEmail : "<<t->email;
            cout<<"\n=================================\n";
        }
    }

    Node* find(string key){for(Node*t=head;t;t=t->next) if(t->name==key) return t; return NULL;}

    void searchContact(){
        if(!head){cout<<"\nEmpty.\n";return;}
        string key; cin.ignore(); cout<<"Enter Name: "; getline(cin,key);
        Node*t=find(key);
        if(!t) cout<<"Contact Not Found.\n";
        else cout<<"\nName: "<<t->name<<"\nPhone: "<<t->phone<<"\nEmail: "<<t->email<<"\n";
    }

    void updateContact(){
        if(!head){cout<<"\nEmpty.\n";return;}
        string key; cin.ignore(); cout<<"Enter Name to Update: "; getline(cin,key);
        Node*t=find(key);
        if(!t){cout<<"Contact Not Found.\n";return;}
        string nm;
        do{
            cout<<"Enter New Name: ";
            getline(cin,nm);
            if(!validName(nm)) cout<<"Invalid Name.\n";
        }while(!validName(nm));
        t->name=nm;
        do{
            cout<<"Enter New Phone: ";
            getline(cin,t->phone);
            if(!validPhone(t->phone)) cout<<"Invalid Phone.\n";
        }while(!validPhone(t->phone));
        cout<<"Enter New Email: "; getline(cin,t->email);
        cout<<"Updated Successfully.\n";
    }

    void deleteContact(){
        if(!head){cout<<"\nEmpty.\n";return;}
        string key; cin.ignore(); cout<<"Enter Name to Delete: "; getline(cin,key);
        Node*cur=head,*pre=NULL;
        while(cur){
            if(cur->name==key){
                if(pre) pre->next=cur->next; else head=cur->next;
                delete cur; cout<<"Deleted Successfully.\n"; return;
            }
            pre=cur; cur=cur->next;
        }
        cout<<"Contact Not Found.\n";
    }

    void reverseContacts(){
        Node*prev=NULL,*cur=head,*nxt;
        while(cur){nxt=cur->next; cur->next=prev; prev=cur; cur=nxt;}
        head=prev;
        cout<<"List Reversed.\n";
    }
};

int main(){
    ContactList contacts; int choice;
    do{
        cout<<"\n=========== CONTACT MANAGEMENT ===========\n";
        cout<<"1. Add Contact\n2. Display Contacts\n3. Search Contact\n4. Update Contact\n5. Delete Contact\n6. Reverse Contact List\n7. Exit\n";
        cout<<"Enter Choice: ";
        cin>>choice;
        switch(choice){
            case 1: contacts.addContact(); break;
            case 2: contacts.displayContacts(); break;
            case 3: contacts.searchContact(); break;
            case 4: contacts.updateContact(); break;
            case 5: contacts.deleteContact(); break;
            case 6: contacts.reverseContacts(); break;
            case 7: cout<<"Thank You!\n"; break;
            default: cout<<"Invalid Choice!\n";
        }
    }while(choice!=7);
}
