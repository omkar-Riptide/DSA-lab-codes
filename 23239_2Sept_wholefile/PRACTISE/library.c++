#include<iostream>
using namespace std;

struct Library{
    int bookid,no_copy;
    float price;
    string title;
    string auth_name,publi_name;

    void book_Info(){
        int choice,choice2;
        do{
        cout << "\n1. Modify";   
        //getline(cin, name);
        cout << "\n2. Display";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Modify operation selected";
                cout << "\n1. Modify BOOK ID";   
                cout << "\n2. PRICE";
                cout << "\n3. COPIES REMAINING:";
                cout << "\nEnter choice: ";
                cin>>choice2;

                switch(choice2){
                    case 1:
                        cout<<"New book id:";
                        cin>>bookid;
                    case2:
                        cout<<"New book price:";
                        cin>>price;
                    case 3:
                        cout<<"Remaining no. of copies:";
                        cin>>no_copy;
                    default:
                        cout<<"Enter valid choice2:";

                }
                break;

            case 2:
                cout << "Display operation selected";
                cout<<"Book ID:"<<bookid<<endl;
                cout<<"Book title:"<<title<<endl;
                cout<<"Author name:"<<auth_name<<endl;
                cout<<"Publication name:"<<publi_name<<endl;
                cout<<"Price:"<<price<<endl;
                cout<<"NO. of remaining copies:"<<no_copy;
                break;

            case 3:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(choice != 3);
    }

};
int main(){
        Library b1;
        Library *ptr;
        ptr=&b1;
        cout<<"Enter book name:";
        getline(cin,ptr->title);

        cout<<"Enter book ID:";
        cin>>ptr->bookid;

        cout<<"Author name:";
        getline(cin,ptr->auth_name);

        cout<<"Publication name:";
        getline(cin,ptr->publi_name);

        cout<<'No. of copies available:';
        cin>>ptr->no_copy;

        cout<<'Price of book:';
        cin>>ptr->price;

        ptr->book_Info();

        return 0;
}