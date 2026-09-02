// A. Implement Quick Sort Algorithm to sort a list of elements in ascending order using divide
// and conquer approach.

#include<iostream>
using namespace std;
class Quickie{
    public:
    int partition(int arr[],int l,int r,int pivot){
        int start=l;
        for(int i=l;i<=r;i++){
            if(arr[i]<=pivot){
                swap(arr[i],arr[start]);
                start+=1;
            }
        }
        return start-1;
    }
    void quick_sort(int arr[],int l,int r){
        if(l>=r){return;}
        int pivot=arr[r];

        int pivotIndex=partition(arr,l,r,pivot);

        quick_sort(arr,l,pivotIndex-1);
        quick_sort(arr,pivotIndex+1,r);
    }
    void display_arr(int arr[],int size){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Quickie q;
    int n;
    cout<<"Enter size of array:";
    cin>>n;

    int *arr=new int[n];

    cout<<"Enter elements of array:\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Unsorted array:\n";
    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    q.display_arr(arr,n);
    cout<<endl;
    q.quick_sort(arr,0,n-1);
    cout<<"Sorted array:\n";

    // for(int i=0;i<n;i++){
    //     cout<<arr[i]<<" ";
    // }
    q.display_arr(arr,n);
    return 0;
}