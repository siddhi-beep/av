#include <iostream>
#include <stdlib.h>
using namespace std;
struct node {
    char label[60];
    int chcount;
    node* child[50];
};
class general {
public:
    node* root;
    general() {
        root = NULL;
    }
    void insert();
    void display();
};

void general::insert() {
    if (root != NULL) {
        cout << "Book already exists. Please delete it before inserting a new one." << endl;
        return;
    }

    int chapCount;
    root = new node();
    cout << "Enter the name of book: " << endl;
    cin >> root->label;
    cout << "Enter the total number of chapters in book: " << endl;
    cin >> chapCount;
    root->chcount = chapCount;

    for (int i = 0; i < chapCount; i++) {
        root->child[i] = new node();
        cout << "Enter the name of chapter " << i + 1 << ": " << endl;
        cin >> root->child[i]->label;
        cout << "Enter the number of sections: " << endl;
        cin >> root->child[i]->chcount;

        for (int j = 0; j < root->child[i]->chcount; j++) {
            root->child[i]->child[j] = new node();
            cout << "Enter the name of section " << j + 1 << ": " << endl;
            cin >> root->child[i]->child[j]->label;
            cout << "Enter the number of sub sections: " << endl;
            cin >> root->child[i]->child[j]->chcount;

            for (int k = 0; k < root->child[i]->child[j]->chcount; k++) {
                root->child[i]->child[j]->child[k] = new node();
                cout << "Enter the name of sub section " << k + 1 << ": " << endl;
                cin >> root->child[i]->child[j]->child[k]->label;
            }
        }
    }
}

void general::display() {
    if (root == NULL) {
        cout << "No book exists. Please insert a book first." << endl;
        return;
    }

    cout << " Hierarchy of Book " << endl;
    cout << "Book Name: " << root->label << endl;
    for (int i = 0; i < root->chcount; i++) {
        cout << "Chapter " << i + 1 << ": " << root->child[i]->label << endl;
        for (int j = 0; j < root->child[i]->chcount; j++) {
            cout << "Section " << j + 1 << ": " << root->child[i]->child[j]->label << endl;
            for (int k = 0; k < root->child[i]->child[j]->chcount; k++) {
                cout << "Sub Section " << k + 1 << ": " << root->child[i]->child[j]->child[k]->label << endl;
            }
        }
    }
}

int main() {
    general g;
    int ch;
    do {
        cout << "   MENU  " << endl;
        cout << "1. Insert." << endl;
        cout << "2. Display." << endl;
        cout << "3. Exit." << endl;
        cout << "Enter the choice: " << endl;
        cin >> ch;
        switch (ch) {
        case 1:
            g.insert();
            break;
        case 2:
            g.display();
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please choose a valid option." << endl;
        }
    } while (ch != 3);
    return 0;
}