#include <iostream>
using namespace std;

class Sort {
public:
    int* arr;
    int n;
    Sort(){
        arr = nullptr;
        n = 0;
    }
    ~Sort(){
        delete[] arr;
    }
    void fill_arr() {
        cout << "Enter size of the array: ";
        cin >> n;
        delete[] arr;
        arr = new int[n];
        cout << "Enter array elements -> ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << "Unsorted array is:\n[";
        for (int i = 0; i < n; i++) {
            cout << arr[i];
            if (i != n - 1)
                cout<< " ";
        }
        cout << "]\n";
    }
////////////////////////////////////////////////////////////////////////////////
    void sort_bubble() {
        for (int i = 0; i < n - 1; i++) {
            bool is_swap = false;
            for (int j= 0; j<n-i-1;j++) {
                if (arr[j]>arr[j+1]) {
                    int temp= arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;

                    is_swap = true;
                }
            }
            if (is_swap==false) //(!is_swap)-koi sorting nhi .already sorted ,break
                break;
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////
    void insertion_sort() {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j+1]=arr[j];
                j--;
            }

            arr[j+1]=key;
        }
    }

    void display_arr() {
        cout << "Sorted array is:\n[";
        for (int i = 0; i < n; i++) {
            cout << arr[i];

            if (i!=n-1)
                cout << " ";
        }

        cout << "]\n";
    }
};

int main() {
    Sort b;
    int choice;

    do {
        cout << "\n////////////MENU ///////////////////////\n";
        cout << "1.Bubble Sort\n"<< "2.Insertion Sort\n"<< "3.Exit\n"<< "Enter choice: ";
        cin >> choice;

        switch (choice) {
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
            cout << "Exiting......\n";
            break;

        default:
            cout<<"Invalid choice!\n";
        }

    } while (choice != 3);

    return 0;
}
