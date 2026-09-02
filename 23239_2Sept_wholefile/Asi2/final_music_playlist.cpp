#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    string song;
    string artist;
    float duration;
    Node *next;
    Node *prev;

    Node(string s, string a, float d)
    {
        song = s;
        artist = a;
        duration = d;
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
        float duration;

        cin.ignore();

        cout << "\nEnter Song Name : ";
        getline(cin, song);

        cout << "Enter Artist Name : ";
        getline(cin, artist);

        cout << "Enter Song Duration (in minutes) : ";
        cin >> duration;

        Node *newNode = new Node(song, artist, duration);

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

        // Display warning if duration is invalid for playing
        if (duration < 1.00 || duration > 15.00)
        {
            cout << "Warning: This song cannot be played because its duration ";
            cout << "must be between 1.00 and 15.00 minutes.\n";
        }
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

        cout << "\n============================== PLAYLIST ==============================\n";

        int i = 1;

        while (temp != NULL)
        {
            cout << i << ". " << temp->song
                 << " - " << temp->artist
                 << " - Duration: " << temp->duration << " min";

            if (temp->duration < 1.00 || temp->duration > 15.00)
            {
                cout << " [Cannot be Played]";
            }

            cout << endl;

            temp = temp->next;
            i++;
        }

        cout << "=======================================================================\n";
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
                cout << "Song     : " << temp->song << endl;
                cout << "Artist   : " << temp->artist << endl;
                cout << "Duration : " << temp->duration << " min" << endl;

                if (temp->duration < 1.00 || temp->duration > 15.00)
                {
                    cout << "Status   : Cannot be Played" << endl;
                }
                else
                {
                    cout << "Status   : Can be Played" << endl;
                }

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

        // Check duration of selected song
        if (current->duration < 1.00 || current->duration > 15.00)
        {
            cout << "\nCannot Play This Song!\n";
            cout << "Song Duration: " << current->duration << " min\n";
            cout << "Allowed Duration: 1.00 to 15.00 minutes.\n";
            return;
        }

        cout << "\nNow Playing : "
             << current->song
             << " - "
             << current->artist
             << " (" << current->duration << " min)"
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

                    // Check duration of next song
                    if (current->duration < 1.00 || current->duration > 15.00)
                    {
                        cout << "\nNext Song Cannot Be Played!\n";
                        cout << "Song : " << current->song << endl;
                        cout << "Duration : " << current->duration << " min\n";
                    }
                    else
                    {
                        cout << "\nPlaying Next Song...\n";
                        cout << current->song
                             << " - "
                             << current->artist
                             << " (" << current->duration << " min)"
                             << endl;
                    }
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

                    // Check duration of previous song
                    if (current->duration < 1.00 || current->duration > 15.00)
                    {
                        cout << "\nPrevious Song Cannot Be Played!\n";
                        cout << "Song : " << current->song << endl;
                        cout << "Duration : " << current->duration << " min\n";
                    }
                    else
                    {
                        cout << "\nPlaying Previous Song...\n";
                        cout << current->song
                             << " - "
                             << current->artist
                             << " (" << current->duration << " min)"
                             << endl;
                    }
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

    do
    {
        cout << "\n====================================";
        cout << "\n      MUSIC PLAYLIST MANAGER";
        cout << "\n====================================";
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

    } while (choice != 6);

    return 0;
}



// ====================================
//       MUSIC PLAYLIST MANAGER
// ====================================
// 1. Add Song
// 2. Delete Song
// 3. Search Song
// 4. Display Playlist
// 5. Play Songs
// 6. Exit

// Enter Choice : 1

// Enter Song Name : loser
// Enter Artist Name : tame impala
// Enter Song Duration (in minutes) : 3.59

// Song Added Successfully!

// ====================================
//       MUSIC PLAYLIST MANAGER
// ====================================
// 1. Add Song
// 2. Delete Song
// 3. Search Song
// 4. Display Playlist
// 5. Play Songs
// 6. Exit

// Enter Choice : 1

// Enter Song Name : beleiver
// Enter Artist Name : imagine dragons
// Enter Song Duration (in minutes) : 4.02

// Song Added Successfully!

// ====================================
//       MUSIC PLAYLIST MANAGER
// ====================================
// 1. Add Song
// 2. Delete Song
// 3. Search Song
// 4. Display Playlist
// 5. Play Songs
// 6. Exit

// Enter Choice : 1

// Enter Song Name : lose yourself
// Enter Artist Name : eminem
// Enter Song Duration (in minutes) : 7.08

// Song Added Successfully!

// ====================================
//       MUSIC PLAYLIST MANAGER
// ====================================
// 1. Add Song
// 2. Delete Song
// 3. Search Song
// 4. Display Playlist
// 5. Play Songs
// 6. Exit

// Enter Choice : 1

// Enter Song Name : night changes
// Enter Artist Name : onedirection
// Enter Song Duration (in minutes) : 3.58

// Song Added Successfully!

// ====================================
//       MUSIC PLAYLIST MANAGER
// ====================================
// 1. Add Song
// 2. Delete Song
// 3. Search Song
// 4. Display Playlist
// 5. Play Songs
// 6. Exit

// Enter Choice : 1

// Enter Song Name : way less sad
// Enter Artist Name : ajr
// Enter Song Duration (in minutes) : 5.30

// Song Added Successfully!

// ====================================
//       MUSIC PLAYLIST MANAGER
// ====================================
// 1. Add Song
// 2. Delete Song
// 3. Search Song
// 4. Display Playlist
// 5. Play Songs
// 6. Exit

// Enter Choice : 3

// Enter Song Name : loser

// Song Found!
// Song     : loser
// Artist   : tame impala
// Duration : 3.59 min
// Status   : Can be Played

// ====================================
//       MUSIC PLAYLIST MANAGER
// ====================================
// 1. Add Song
// 2. Delete Song
// 3. Search Song
// 4. Display Playlist
// 5. Play Songs
// 6. Exit

// Enter Choice : 4

// ============================== PLAYLIST ==============================
// 1. loser - tame impala - Duration: 3.59 min
// 2. beleiver - imagine dragons - Duration: 4.02 min
// 3. lose yourself - eminem - Duration: 7.08 min
// 4. night changes - onedirection - Duration: 3.58 min
// 5. way less sad - ajr - Duration: 5.3 min
// =======================================================================

// ====================================
//       MUSIC PLAYLIST MANAGER
// ====================================
// 1. Add Song
// 2. Delete Song
// 3. Search Song
// 4. Display Playlist
// 5. Play Songs
// 6. Exit

// Enter Choice : 5

// ============================== PLAYLIST ==============================
// 1. loser - tame impala - Duration: 3.59 min
// 2. beleiver - imagine dragons - Duration: 4.02 min
// 3. lose yourself - eminem - Duration: 7.08 min
// 4. night changes - onedirection - Duration: 3.58 min
// 5. way less sad - ajr - Duration: 5.3 min
// =======================================================================

// Which song do you want to play? : lose yourself

// Now Playing : lose yourself - eminem (7.08 min)

// 1. Next Song
// 2. Previous Song
// 3. Stop Playing
// Enter Choice : 2

// Playing Previous Song...
// beleiver - imagine dragons (4.02 min)

// 1. Next Song
// 2. Previous Song
// 3. Stop Playing
// Enter Choice : 1

// Playing Next Song...
// lose yourself - eminem (7.08 min)

// 1. Next Song
// 2. Previous Song
// 3. Stop Playing
// Enter Choice : 1

// Playing Next Song...
// night changes - onedirection (3.58 min)

// 1. Next Song
// 2. Previous Song
// 3. Stop Playing
// Enter Choice : 3

// Music Stopped.

// ====================================
//       MUSIC PLAYLIST MANAGER
// ====================================
// 1. Add Song
// 2. Delete Song
// 3. Search Song
// 4. Display Playlist
// 5. Play Songs
// 6. Exit

// Enter Choice : 2

// Enter Song Name to Delete : night changes

// Song Deleted Successfully!

// ====================================
//       MUSIC PLAYLIST MANAGER
// ====================================
// 1. Add Song
// 2. Delete Song
// 3. Search Song
// 4. Display Playlist
// 5. Play Songs
// 6. Exit

// Enter Choice : 4

// ============================== PLAYLIST ==============================
// 1. loser - tame impala - Duration: 3.59 min
// 2. beleiver - imagine dragons - Duration: 4.02 min
// 3. lose yourself - eminem - Duration: 7.08 min
// 4. way less sad - ajr - Duration: 5.3 min
// =======================================================================

// ====================================
//       MUSIC PLAYLIST MANAGER
// ====================================
// 1. Add Song
// 2. Delete Song
// 3. Search Song
// 4. Display Playlist
// 5. Play Songs
// 6. Exit

// Enter Choice : 6

// Thank You!