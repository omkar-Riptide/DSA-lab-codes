#include <iostream>
using namespace std;

class Sorting {
public:

    // Display array
    void display(int arr[], int n) {
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    // 1. Selection Sort
    void selectionSort(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;

            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[minIndex])
                    minIndex = j;
            }

            swap(arr[i], arr[minIndex]);
        }
    }

    // 2. Insertion Sort
    void insertionSort(int arr[], int n) {
        for (int i = 1; i < n; i++) {
            int key = arr[i];
            int j = i - 1;

            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j--;
            }

            arr[j + 1] = key;
        }
    }

    // Partition function for Quick Sort
    int partition(int arr[], int low, int high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }

        swap(arr[i + 1], arr[high]);

        return i + 1;
    }

    // 3. Quick Sort
    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

    // Find maximum element for Radix Sort
    int getMax(int arr[], int n) {
        int maxVal = arr[0];

        for (int i = 1; i < n; i++) {
            if (arr[i] > maxVal)
                maxVal = arr[i];
        }

        return maxVal;
    }

    // Counting sort used by Radix Sort
    void countingSort(int arr[], int n, int exp) {
        int output[100];
        int count[10] = {0};

        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            count[digit]++;
        }

        for (int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
            int digit = (arr[i] / exp) % 10;

            output[count[digit] - 1] = arr[i];
            count[digit]--;
        }

        for (int i = 0; i < n; i++)
            arr[i] = output[i];
    }

    // 4. Radix Sort
    void radixSort(int arr[], int n) {
        int maxVal = getMax(arr);

        for (int exp = 1; maxVal / exp > 0; exp *= 10)
            countingSort(arr, n, exp);
    }
};


int main() {

    int arr[] = {64, 25, 12, 22, 11};
    int n = 5;

    Sorting s;

    cout << "Original array: ";
    s.display(arr, n);

    // Selection Sort
    s.selectionSort(arr, n);
    cout << "Selection Sort: ";
    s.display(arr, n);


    // Reset array
    int arr2[] = {64, 25, 12, 22, 11};

    // Insertion Sort
    s.insertionSort(arr2, n);
    cout << "Insertion Sort: ";
    s.display(arr2, n);


    // Reset array
    int arr3[] = {10, 7, 8, 9, 1, 5};
    int n3 = 6;

    // Quick Sort
    s.quickSort(arr3, 0, n3 - 1);
    cout << "Quick Sort: ";
    s.display(arr3, n3);


    // Reset array
    int arr4[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n4 = 8;

    // Radix Sort
    s.radixSort(arr4, n4);
    cout << "Radix Sort: ";
    s.display(arr4, n4);

    return 0;
}