// Develop a Product Management System that stores product details such as Product ID,
// Product Name, and Price, and sorts the products based on their price using the Quick Sort
// algorithm. The program should display the sorted list in ascending or descending order
// through a menu-driven interface.

#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    int productId;
    string productName;
    double price;

public:
    
    Product() {
        productId = 0;
        productName = "";
        price = 0.0;
    }

    Product(int id, string name, double p) {
        productId = id;
        productName = name;
        price = p;
    }

    int getProductId() {return productId; }

    string getProductName() {
        return productName;
    }

    double getPrice() {
        return price;
    }

    
    void display() {
        cout << productId << "\t"<< productName << "\t\t"<< price << endl;
    }
};

class ProductManager {
private:
    Product* products;
    int size;

    void swapProducts(Product &a, Product &b) {
        Product temp = a;
        a = b;
        b = temp;
    }

    int partition(int low, int high, bool ascending) {
        double pivot = products[high].getPrice();
        int i = low - 1;
        for (int j = low; j<high;j++) {
            if(ascending) {
                if (products[j].getPrice() <= pivot) {
                    i++;
                    swapProducts(products[i], products[j]);
                }
            }
            else {
                if (products[j].getPrice() >= pivot) {
                    i++;
                    swapProducts(products[i], products[j]);
                }
            }
        }
        swapProducts(products[i+1],products[high]);
        return i + 1;
    }

    void quickSort(int low, int high, bool ascending) {
        if (low < high) {
            int pivotIndex = partition(low, high, ascending);

            quickSort(low, pivotIndex - 1, ascending);
            quickSort(pivotIndex + 1, high, ascending);
        }
    }

public:
    ProductManager(int n) {
        size = n;
        products = new Product[size];
    }
    ~ProductManager() {
        delete[] products;
    }

    void inputProducts() {
        for (int i = 0; i < size; i++) {
            int id;
            string name;
            double price;

            cout << "\nEnter details of Product " << i + 1 << endl;

            cout << "Product ID: ";
            cin >> id;
            //cin.ignore();
            cout << "Product Name: ";
            cin >> name;
            //getline(cin,name);

            cout << "Price: ";
            cin >> price;

            products[i] = Product(id, name, price);
        }
    }

    void displayProducts() {
        cout << "\n---------------------------------\n";
        cout << "ID\tName\t\tPrice\n";
        cout << "///////////////////////////////\n";

        for (int i = 0; i < size; i++) {
            products[i].display();
        }
        cout << "------------------\n";
    }

    
    void sortProducts(bool ascending) {// Sorting by quick sort
        quickSort(0, size - 1, ascending);
    }
};

int main() {
    int n;
    int choice;

    cout << "///////////////PRODUCT MANAGEMENT SYSTEM//////////\n";

    cout << "Enter number of products: ";
    cin >> n;

    ProductManager manager(n);

    
    manager.inputProducts();
    do {
        cout << "\n////////MENU/////////////\n";
        cout <<"1.Display Products\t"<<"2.Sort by Price- Ascending\n"<<"3.Sort by Price- Descending\t";
        cout <<"4.Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                manager.displayProducts();
                break;
            case 2:
                manager.sortProducts(true);
                cout << "\nProducts sorted by price in ASCENDING order:\n";
                manager.displayProducts();
                break;
            case 3:
                manager.sortProducts(false);
                cout << "\nProducts sorted by price in DESCENDING order:\n";
                manager.displayProducts();
                break;
            case 4:
                cout << "\nExiting program...\n";
                break;
            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}