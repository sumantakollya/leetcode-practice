// Codechef problem link : https://www.codechef.com/learn/course/linked-lists/LINKEDLIST02/problems/LINK02P10
#include <iostream>

using namespace std;

// Node structure for doubly linked list
struct Node {
    int songId;
    Node* prev;
    Node* next;
    
    Node(int id) : songId(id), prev(NULL), next(NULL) {}
};

class MusicPlayer {
public:
    Node *head,*tail;
    Node *currentSong;
    
    MusicPlayer()
    {
        head = NULL;
        tail = NULL;
        currentSong = NULL;
    }

    // Function to add a song to the end of the list
    void addSong(int songId) {
        
        Node *newNode = new Node(songId);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            currentSong = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
       
    }

    // Function to play the next song
    void playNext() {
        currentSong = currentSong->next;
    }

    // Function to play the previous song
    void playPrev() {
        currentSong = currentSong->prev;
    }

    // Function to switch to a specific song
    void switchSong(int songId) {
        for (auto iter = head; iter != NULL; iter=iter->next)
        {
            if (iter->songId == songId)
            {
                currentSong = iter;
                return;
            }
        }
    }

    // Function to return the songId of the current song playing
    int current() {
        return currentSong->songId; 
    }
};

int main() {
    MusicPlayer player;
    int query, songId;
    int q;
    cin >> q;
    while (q--) {
        cin >> query;

        switch (query) {
            case 1:
                cin >> songId;
                player.addSong(songId);
                break;
            case 2:
                player.playNext();
                break;
            case 3:
                player.playPrev();
                break;
            case 4:
                cin >> songId;
                player.switchSong(songId);
                break;
            case 5:
                cout << player.current() << endl;
                break;
            default:
                cout << "Invalid query!" << endl; 
        }
    }

    return 0;
}
