#include<iostream>
#include <chrono>//
using namespace std;
class Bubble_sort{
    public:
    int* arr;
    int n;
    /////////////////////////////////////////////////////////////////////
    void fill_arr(){
        cout<<"Enter size of the array:";
        cin>>n;

        arr=new int[n];
        cout<<"Enter array elements->";
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<"Unsorted array is:\n"<<"[";
        for(int i=0;i<n;i++){
            if(i==n-1){
                cout<<arr[i]<<"]";
                break;
                //return;
            }
            cout<<arr[i]<<" ";
        }
    }
    ///////////////////////////////////////////////////////////////////////////////
    void sort_bubble(){
        int temp;
        for(int i=0;i<n;i++){
            bool is_swap=false;
            for(int j=0;j<n-i-1;j++){
                if(arr[j]>arr[j+1]){
                    temp=arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                    is_swap=true;
                }
            }
            if(is_swap==false){
                break;
            }
        }
        //display_arr();
    }
    ////////////////////////////////////////////////////
    void insertion_sort(){
        for(int i=0;i<n;i++){
            int key=arr[i];
            int j=i-1;

            while(j<=0 && arr[j]>key){
                arr[j+1]=arr[j];
                j--;
            }
            arr[j+1]=key;
        }


    }
    ////////////////////////////////////////////////////////////
    void display_arr(){
        cout<<"\nSorted array is:\n"<<"[";
        for(int i=0;i<n;i++){
            if(i==n-1){
                cout<<arr[i]<<"]\n";
                //break;
                return;
            }
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    auto start = chrono::high_resolution_clock::now();//
    Bubble_sort b;

    // b.fill_arr();

    // b.sort_bubble();
    // b.display_arr();

    int choice;
    cout<<"1.Bubble Sort\n"<<"2.Insertion Sort\n"<<"3.Exit\n";
    //cin>>choice;

    do{ 
        cout<<"Enter choice:";
        cin>>choice;
        switch(choice){
            case 1:
                b.fill_arr();
                b.sort_bubble();
                b.display_arr();
                break;

            case 2:
                b.fill_arr();
                b.insertion_sort();
                b.display_arr();
                break;

            case 3:
                cout<<"Exiting......";
                break;
            default:
                cout<<"Invalid choice!";
        }

    }while(choice!=3);

    auto end = chrono::high_resolution_clock::now();//
    auto duration =chrono::duration_cast<chrono::microseconds>(end - start);//
    cout << "\nTime taken: "<< duration.count()<< " microseconds\n";//
    return 0;
}
