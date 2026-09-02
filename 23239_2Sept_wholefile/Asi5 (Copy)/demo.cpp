#include<iostream>
using namespace std;
void linear_search(int array[],int key,int n){
    //int n=sizeof(array);
    //bool found=false;

    for(int i=0;i<n;i++){
        if(i==n-1 && array[i]!=key){
            cout<<"Element not found";
        }
        if(array[i]==key){
            cout<<"Element found at index:"<<i;
            break;
            //found=true;
        }
        else{
            continue;
        }
    }

}

int main(){
    int arr[]={2,45,67,43,98,455};
    int n=sizeof(arr);
    //sort(arr,arr+n);
    int k=43;
    linear_search(arr,k,n);


    return 0;
}