#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    string song;
    string artist;
    int duration;
    Node *next;
    Node *prev;

    Node(string s, string a,int dur)
    {
        song = s;
        artist = a;
        duration=dur;
        next = NULL;
        prev = NULL;
    }
};

class Playlist
{
private:
    Node *head;

public:
    Playlist()
    {
        head = NULL;
    }

    // Add Song
    void addSong()
    {
        string song, artist;
        int duration;
        cin.ignore();

        cout << "\nEnter Song Name : ";
        getline(cin, song);

        cout << "Enter Artist Name : ";
        getline(cin, artist);

        cout<<"Enter song duration(in seconds):";
        cin>>duration;
        Node *newNode = new Node(song, artist,duration);

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newNode;
            newNode->prev = temp;
        }

        cout << "\nSong Added Successfully!\n";
    }

    // Display Playlist
    void displayPlaylist()
    {
        if (head == NULL)
        {
            cout << "\nPlaylist is Empty.\n";
            return;
        }

        Node *temp = head;

        cout << "\n========== PLAYLIST ==========\n";

        int i = 1;

        while (temp != NULL)
        {
            cout << i << ". " << temp->song
                 << " - " << temp->artist << "-"<<"Duration:"<<temp->duration<<endl;

            temp = temp->next;
            i++;
        }

        cout << "==============================\n";
    }

    // Search Song
    void searchSong()
    {
        if (head == NULL)
        {
            cout << "\nPlaylist is Empty.\n";
            return;
        }

        string name;

        cin.ignore();

        cout << "\nEnter Song Name : ";
        getline(cin, name);

        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->song == name)
            {
                cout << "\nSong Found!\n";
                cout << "Song   : " << temp->song << endl;
                cout << "Artist : " << temp->artist << endl;
                cout << "Duration(in seconds) : " << temp->duration << endl;
                return;
            }

            temp = temp->next;
        }

        cout << "\nSong Not Found.\n";
    }

    // Delete Song
    void deleteSong()
    {
        if (head == NULL)
        {
            cout << "\nPlaylist is Empty.\n";
            return;
        }

        string name;

        cin.ignore();

        cout << "\nEnter Song Name to Delete : ";
        getline(cin, name);

        Node *temp = head;

        while (temp != NULL)
        {
            if (temp->song == name)
            {
                if (temp == head)
                {
                    head = head->next;

                    if (head != NULL)
                        head->prev = NULL;
                }
                else
                {
                    temp->prev->next = temp->next;

                    if (temp->next != NULL)
                        temp->next->prev = temp->prev;
                }

                delete temp;

                cout << "\nSong Deleted Successfully!\n";
                return;
            }

            temp = temp->next;
        }

        cout << "\nSong Not Found.\n";
    }

    // Play Songs
    void playSongs()
    {
        if (head == NULL)
        {
            cout << "\nPlaylist is Empty.\n";
            return;
        }

        displayPlaylist();

        string name;

        cin.ignore();

        cout << "\nWhich song do you want to play? : ";
        getline(cin, name);

        Node *current = head;

        while (current != NULL)
        {
            if (current->song == name)
                break;

            current = current->next;
        }

        if (current == NULL)
        {
            cout << "\nSong Not Found.\n";
            return;
        }

        cout << "\nNow Playing : "
             << current->song
             << " - "
             << current->artist<<"-"<<current->duration
             << endl;

        int choice;

        while (true)
        {
            cout << "\n1. Next Song";
            cout << "\n2. Previous Song";
            cout << "\n3. Stop Playing";

            cout << "\nEnter Choice : ";
            cin >> choice;

            if (choice == 1)
            {
                if (current->next == NULL)
                {
                    cout << "\nNo Next Song Available.\n";
                }
                else
                {
                    current = current->next;

                    cout << "\nPlaying Next Song...\n";
                    cout << current->song
                         << " - "
                         << current->artist
                         << endl;
                }
            }
            else if (choice == 2)
            {
                if (current->prev == NULL)
                {
                    cout << "\nNo Previous Song Available.\n";
                }
                else
                {
                    current = current->prev;

                    cout << "\nPlaying Previous Song...\n";
                    cout << current->song
                         << " - "
                         << current->artist<<"-"<<current->duration
                         << endl;
                }
            }
            else if (choice == 3)
            {
                cout << "\nMusic Stopped.\n";
                return;
            }
            else
            {
                cout << "\nInvalid Choice.\n";
            }
        }
    }
};

int main()
{
    Playlist playlist;
    int choice;
    do{
        cout << "\n====================================";
        cout << "\n      MUSIC PLAYLIST MANAGER";
        cout << "\n///////////////////////////////////////////////////";
        cout << "\n1. Add Song";
        cout << "\n2. Delete Song";
        cout << "\n3. Search Song";
        cout << "\n4. Display Playlist";
        cout << "\n5. Play Songs";
        cout << "\n6. Exit";

        cout << "\n\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            playlist.addSong();
            break;

        case 2:
            playlist.deleteSong();
            break;

        case 3:
            playlist.searchSong();
            break;

        case 4:
            playlist.displayPlaylist();
            break;

        case 5:
            playlist.playSongs();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while(choice != 6);

    return 0;
}