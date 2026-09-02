#include<iostream>
using namespace std;

class BS{
public:
    void binary_search(){
        int n;
        cout<<"Enter size of array:";
        cin>>n;

        int arr[n];

        cout<<"Enter elements in ascending order\n";
        for(int i=0;i<n;i++){
            cout<<"Enter index "<<i<<" element:";
            cin>>arr[i];
        }

        int key;
        cout<<"Enter element to be found:";
        cin>>key;

        int l=0;
        int r=n-1;

        while(l<=r){
            int mid=(l+r)/2;

            if(key==arr[mid]){
                cout<<"Element found at index: "<<mid;
                return;
            }

            if(key>arr[mid]){
                l=mid+1;
            }
            else{
                r=mid-1;//m
            }
        }

        cout<<"Element not found";
    }
};

int main(){
    BS b;
    b.binary_search();

    return 0;
}
