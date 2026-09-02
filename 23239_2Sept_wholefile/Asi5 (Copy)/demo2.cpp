#include<iostream>
using namespace std;
class LS{
    public:
        void ls_search(int array[],int key,int n){
            for(int i=0;i<n;i++){
                if(i==n-1 && array[i]!=key){
                    cout<<"Element not found";
                }
                if(array[i]==key){
                    cout<<"Element found at index:"<<i;
                    break;
                }
                else{
                    continue;
                }
            }
        }
};
int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n]={};
    for(int i=0;i<n;i++){
        cout<<"Enter index "<<i<<" element:";
        cin>>arr[i];
    }
    int k;
    cout<<"Enter element to be found:";
    cin>>k;

    LS s;
    s.ls_search(arr,k,n);
    return 0;
}