// Develop a Library Book Search System that stores book records sorted by Book ID and
// searches for a book using the Binary Search algorithm. The program should display the book
// details if found; otherwise, it should display an appropriate message.

#include<iostream>
using namespace std;

class Library{
    public:
    int book_id;
    float price;
    string title,author_name;
    void take_info(){    
        cout<<"Enter 5-digit book id:";
        cin>>book_id;
        cin.ignore();
        cout<<"Enter title of book:";
        getline(cin,title);
        cout<<"Enter name of author:";
        cin>>author_name;
        cout<<"Enter cprice of book:";
        cin>>price;
        }
    
    
    void display_by_id(int id,Library *array,int length){
        // for(int i=0;i<length;i++){
        //     if(id==array[i].id){
        //         cout<<"\nName of Student:"<<array[i].name<<endl;
        //         cout<<"ID of student:"<<array[i].id<<endl;
        //         cout<<"Department of student:"<<array[i].dept<<endl;
        //         cout<<"CGPA of student:"<<array[i].cgpa<<endl;

        //     }
        //     else{
        //         if(i==length){
        //             cout<<"Student name not found!";
        //         }
        //         else{
        //             continue;
        //         }
        //     }
        // }
        int l=0;
        int r=length-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(id==array[mid].book_id){
                cout<<"Element found at index:"<<mid;
            }
            if(id>array[mid].book_id){
                    l=mid+1;
                }
            else if(id<array[mid].book_id){
                    r=mid-1;
                }
        }
    }

    
};
int main(){
    Library l;
    Library *arr;
    int n;
    cout<<"Enter no. of student records:";
    cin>>n;
    arr=new Library[n];
    cout<<"\nEnter book ids in ascending/descending order\n";
    for(int i=0;i<n;i++){
        cout<<"Enter info of book no. :"<<i+1<<endl;
        arr[i].take_info();
    }
    cout<<"//////////////////Menu//////////////\n";
    cout<<"1.Search by id\n"<<"2.Exit\n";
    int choice;
    int main_id;
    string main_name;
    do{
        cout<<"\nEnter choice:";
        cin>>choice;
        switch(choice){
            case 1:
                //cin.ignore();
                cout<<"Enter id to be searched:";
                cin>>main_id;
                l.display_by_id(main_id,arr,n);
                break;
            case 2:
                cout<<"Exiting......";
                break;
            default:
                cout<<"Invalid option";
        }
    }while(choice!=2);
    return 0;
}