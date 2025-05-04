#include <iostream>
#include <string>
using namespace std;

const int TABLE_SIZE = 10;

struct Node {
    string key;
    string value;
    Node* next;
    
    Node(string k, string v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashMap {
    Node* table[TABLE_SIZE];

    int hashFunction(string key) {
        int hash = 0;
        for (char ch : key)
            hash += ch;
        return hash % TABLE_SIZE;
    }

public:
    HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = nullptr;
    }

    void insert(string key, string value) {
        int index = hashFunction(key);
        Node* head = table[index];

        Node* temp = head;
        while (temp != nullptr) {
            if (temp->key == key) {
                temp->value = value;
                cout << "Key updated.\n";
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(key, value);
        newNode->next = head;
        table[index] = newNode;
        cout << "Key inserted.\n";
    }

    void find(string key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->key == key) {
                cout << "Value: " << temp->value << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Key not found.\n";
    }

    void remove(string key) {
        int index = hashFunction(key);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->key == key) {
                if (prev == nullptr)
                    table[index] = temp->next;
                else
                    prev->next = temp->next;
                delete temp;
                cout << "Key deleted.\n";
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Key not found to delete.\n";
    }

    void display() {
        cout << "\nHash Table:\n";
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << "[" << temp->key << " : " << temp->value << "] -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashMap dict;
    int choice;
    string key, value;

    do {
        cout << "\nDictionary Operations:\n";
        cout << "1. Insert\n2. Find\n3. Delete\n4. Display\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key: ";
            cin >> key;
            cout << "Enter value: ";
            cin >> value;
            dict.insert(key, value);
            break;
        case 2:
            cout << "Enter key to find: ";
            cin >> key;
            dict.find(key);
            break;
        case 3:
            cout << "Enter key to delete: ";
            cin >> key;
            dict.remove(key);
            break;
        case 4:
            dict.display();
            break;
        case 0:
            cout << "Exiting.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
