#include<iostream>
#include<string>
using namespace std;

const int t = 10;

struct person {
    string name;
    long long phone;
};

class HashTable {
    person* table[t];
    bool occupied[t];

public:
    HashTable() {
        for (int i = 0; i < t; i++) {
            table[i] = nullptr;
            occupied[i] = false;
        }
    }

    int hashFunction(long long phone) {
        return phone % t;
    }

    void insert(string name, long long phone) {
        int index = hashFunction(phone);
        int startIndex = index;
        while (occupied[index]) {
            if (table[index] && table[index]->phone == phone) {
                cout << "doble same number is not allowed";
                return;
            }
            index = (index + 1) % t;
            if (index == startIndex) {
                cout << "table is full";
                return;
            }
        }

        table[index] = new person{name, phone};
        occupied[index] = true;
        cout << "inserted: " << name << " at index " << index << endl;
    }

    int search(long long phone, string& foundName) {
        int index = hashFunction(phone);
        int comparisons = 0;
        int startIndex = index;

        while (occupied[index]) {
            comparisons++;
            if (table[index] && table[index]->phone == phone) {
                foundName = table[index]->name;
                return comparisons;
            }
            index = (index + 1) % t;
            if (index == startIndex) break;
        }

        foundName = "";
        return comparisons;
    }

    void display() {
        cout << "\n--- Hash Table ---\n";
        for (int i = 0; i < t; i++) {
            if (table[i]) {
                cout << i << " -> " << table[i]->name << " : " << table[i]->phone << endl;
            } else {
                cout << i << " -> [empty]";
            }
        }
    }
};

int main() {
    HashTable tb;
    int n;

    cout << "Enter number of persons: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        long long phone;
        cout << "Enter person name and phone number: ";
        cin >> name >> phone;
        tb.insert(name, phone);
    }

    tb.display();

    int m;
    cout << "enter number of phone numbers to search: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        long long phone;
        cout << "enter phone number to search: ";
        cin >> phone;
        string name;
        int comparisons = tb.search(phone, name);
        if (name != "")
            cout << "found: " << name << " with " << comparisons << " comparisons.\n";
        else
            cout << "phone number not found. comparisons made: " << comparisons << endl;
    }

    return 0;
}
