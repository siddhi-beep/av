#include <iostream>
#include <cstring>
using namespace std;

const int maxcities = 100;

struct Node {
    int time;
    char city[50];
    Node* next;
};

class flight {
    Node* list[maxcities];
    char cities[maxcities][50];
    int numc;

public:
    flight() {
        numc = 0;
        for (int i = 0; i < maxcities; i++) {
            list[i] = NULL;
        }
    }

    void addcity() {
        cout << "Enter number of cities: ";
        cin >> numc;
        cin.ignore(); // clear newline from input buffer

        cout << "Enter names of the cities:" << endl;
        for (int i = 0; i < numc; i++) {
            cout << "City " << i + 1 << ": ";
            cin.getline(cities[i], 50);
        }

        for (int i = 0; i < numc; i++) {
            for (int j = 0; j < numc; j++) {
                if (i == j) continue;

                char ch;
                cout << "Is there a flight between " << cities[i] << " and " << cities[j] << "? (y/n): ";
                cin >> ch;

                if (ch == 'y' || ch == 'Y') {
                    int time;
                    cout << "Enter time required from " << cities[i] << " to " << cities[j] << " (in minutes): ";
                    cin >> time;
                    cin.ignore(); 

                    Node* newNode = new Node;
                    newNode->time = time;
                    strcpy(newNode->city, cities[j]);
                    newNode->next = list[i];
                    list[i] = newNode;
                }
            }
        }
    }

    void display() {
        cout << "Flight routes from source to destination:";
        for (int i = 0; i < numc; i++) {
            cout << cities[i] << " -> ";
            Node* temp = list[i];
            while (temp) {
                cout << temp->city << " (" << temp->time << " min) -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int choice;
    flight f;

    do {
     
        cout << "1. Enter flight routes";
        cout << "2. Display flight connections";
     
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            f.addcity();
            break;
        case 2:
            f.display();
            break;
       
        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 2);

    return 0;
}
