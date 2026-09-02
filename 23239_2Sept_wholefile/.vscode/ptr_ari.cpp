#include<iostream>
using namespace std;

int main(){
    int *ptr;
    // int arr[5]={3,4,5,6,7};

    ptr=new int[5]{3,4,5,6,7};
    // ptr=arr;

    cout<<"for loop->>";
    for(int i=0;i<5;i++){
        cout<<ptr[i]<<" ";                                          
    }

    // cout<<"Manual->>";
    // cout<<endl;
    // cout<<*ptr; //3
    // cout<<*(ptr+1); //pointer ptr posi doesnt change ->>4
    // cout<<*(++ptr);//4,ptr moves ahead
    // cout<<*(ptr++);//4,ptr moves to point 5
    // cout<<*ptr; //5
    delete[] ptr;
    return 0;
}