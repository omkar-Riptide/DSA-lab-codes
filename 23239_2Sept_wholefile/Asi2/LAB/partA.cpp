#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList
{
public:
    Node *head;

    LinkedList()
    {
        head = nullptr;
    }

    // Insert at beginning
    void insert_beg(int val)
    {
        Node *newnode = new Node(val);

        if (head == nullptr)
        {
            head = newnode;
        }
        else
        {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    // Insert at end
    void insert_end(int val)
    {
        Node *newnode = new Node(val);

        if (head == nullptr)
        {
            head = newnode;
            return;
        }

        Node *curr = head;
        while (curr->next != nullptr)
            curr = curr->next;

        curr->next = newnode;
        newnode->prev = curr;
    }

    // Size
    int size_ll()
    {
        int size = 0;
        Node *temp = head;

        while (temp != nullptr)
        {
            size++;
            temp = temp->next;
        }

        return size;
    }

    // Search
    void search(int val)
    {
        Node *curr = head;
        int index = 0;

        while (curr != nullptr)
        {
            if (curr->data == val)
            {
                cout << "Found at index " << index << endl;
                return;
            }

            curr = curr->next;
            index++;
        }

        cout << "Value not found.\n";
    }

    // Insert after index k
    void insert_bw(int val, int k)
    {
        if (k < 0 || k >= size_ll())
        {
            cout << "Invalid index.\n";
            return;
        }

        Node *curr = head;

        for (int i = 0; i < k; i++)
            curr = curr->next;

        Node *newnode = new Node(val);

        newnode->next = curr->next;
        newnode->prev = curr;

        if (curr->next != nullptr)
            curr->next->prev = newnode;

        curr->next = newnode;
    }

    // Delete beginning
    void delete_beg()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        Node *temp = head;
        head = head->next;

        if (head != nullptr)
            head->prev = nullptr;

        delete temp;
    }

    // Delete end
    void delete_end()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *curr = head;

        while (curr->next != nullptr)
            curr = curr->next;

        curr->prev->next = nullptr;

        delete curr;
    }

    // Delete at index
    void delete_atK(int k)
    {
        int size = size_ll();

        if (k < 0 || k >= size)
        {
            cout << "Invalid index.\n";
            return;
        }

        if (k == 0)
        {
            delete_beg();
            return;
        }

        if (k == size - 1)
        {
            delete_end();
            return;
        }

        Node *curr = head;

        for (int i = 0; i < k; i++)
            curr = curr->next;

        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;

        delete curr;
    }

    // Reverse Doubly Linked List
    void reverse()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *curr = head;
        Node *temp = nullptr;

        while (curr != nullptr)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        if (temp != nullptr)
            head = temp->prev;

        cout << "Linked List Reversed Successfully.\n";
    }

    // Display
    void display()
    {
        if (head == nullptr)
        {
            cout << "NULL\n";
            return;
        }

        Node *curr = head;

        while (curr != nullptr)
        {
            cout << curr->data << " <-> ";
            curr = curr->next;
        }

        cout << "NULL\n";
    }
};

int main()
{
    LinkedList l;

    int choice, val, index;

    do
    {
        cout << "\n========= MENU =========\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Index\n";
        cout << "4. Delete Beginning\n";
        cout << "5. Delete End\n";
        cout << "6. Delete at Index\n";
        cout << "7. Search Element\n";
        cout << "8. Display List\n";
        cout << "9. Reverse List\n";
        cout << "10. Size of List\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            l.insert_beg(val);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> val;
            l.insert_end(val);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> val;
            cout << "Enter index after which to insert: ";
            cin >> index;
            l.insert_bw(val, index);
            break;

        case 4:
            l.delete_beg();
            break;

        case 5:
            l.delete_end();
            break;

        case 6:
            cout << "Enter index to delete: ";
            cin >> index;
            l.delete_atK(index);
            break;

        case 7:
            cout << "Enter value to search: ";
            cin >> val;
            l.search(val);
            break;

        case 8:
            l.display();
            break;

        case 9:
            l.reverse();
            break;

        case 10:
            cout << "Size of Linked List = " << l.size_ll() << endl;
            break;

        case 11:
            cout << "Exiting Program...\n";
            break;

        default:
            cout << "Invalid Choice!\n";
        }

    } while (choice != 11);

    return 0;
}