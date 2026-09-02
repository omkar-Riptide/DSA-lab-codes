// Develop a Library Book Search System that stores book records sorted by Book ID and
// searches for a book using the Binary Search algorithm. The program should display the book
// details if found; otherwise, it should display an appropriate message.

#include <iostream>
using namespace std;

class Library {
public:
    int book_id;
    float price;
    string title, author_name;

    void take_info() {
        cout << "Enter 5-digit book id: ";
        cin >> book_id;

        cin.ignore();

        cout << "Enter title of book: ";
        getline(cin, title);

        cout << "Enter name of author: ";
        getline(cin, author_name);

        cout << "Enter price of book: ";
        cin >> price;
    }

    void display_by_id(int id, Library *array, int length) {

        int l = 0;
        int r = length - 1;

        while (l <= r) {

            int mid = (l + r) / 2;

            if (id == array[mid].book_id) {

                cout << "\nBook found!\n";
                cout << "Book ID: " << array[mid].book_id << endl;
                cout << "Title: " << array[mid].title << endl;
                cout << "Author: " << array[mid].author_name << endl;
                cout << "Price: " << array[mid].price << endl;

                return;   // book found, so stop searching
            }

            else if (id > array[mid].book_id) {
                l = mid + 1;
            }

            else {
                r = mid - 1;
            }
        }

        // If loop finishes, book was not found
        cout << "\nBook with ID " << id << " not found!\n";
    }
};

int main() {

    Library l;
    Library *arr;

    int n;

    cout << "Enter no. of book records: ";
    cin >> n;

    arr = new Library[n];

    cout << "\nEnter book information in ASCENDING order of Book ID.\n";

    for (int i = 0; i < n; i++) {
        cout << "\nEnter info of book no. " << i + 1 << ":\n";
        arr[i].take_info();
    }

    cout << "\n////////////////// Menu //////////////////\n";
    cout << "1. Search by ID\n";
    cout << "2. Exit\n";

    int choice;
    int main_id;

    do {

        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter ID to be searched: ";
                cin >> main_id;

                l.display_by_id(main_id, arr, n);
                break;

            case 2:
                cout << "Exiting......";
                break;

            default:
                cout << "Invalid option";
        }

    } while (choice != 2);

    delete[] arr;

    return 0;
}