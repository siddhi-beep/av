#include <iostream>
using namespace std;

// Define the BST Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a node in the BST
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Function to search for a specific value in the tree
bool search(Node* root, int value) {
    if (root == nullptr)
        return false;

    if (root->data == value)
        return true;

    if (value < root->data)
        return search(root->left, value);

    return search(root->right, value);
}

// Function to swap the left and right pointers at every node
void swapChildren(Node* root) {
    if (root == nullptr)
        return;

    // Swap the left and right children
    swap(root->left, root->right);

    // Recurse for left and right subtrees
    swapChildren(root->left);
    swapChildren(root->right);
}

// Inorder traversal to display the tree
void inorderTraversal(Node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

int main() {
    Node* root = nullptr;
    int n, value;

    // Construct the BST by inserting values
    cout << "Enter number of nodes to insert: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    // Inorder traversal of the tree
    cout << "\nBST after insertion (Inorder Traversal): ";
    inorderTraversal(root);
    cout << endl;

    // Insert a new node
    cout << "\nEnter a value to insert: ";
    cin >> value;
    root = insert(root, value);

    cout << "\nBST after inserting new node (Inorder Traversal): ";
    inorderTraversal(root);
    cout << endl;

    // Search for a specific value
    cout << "\nEnter a value to search for: ";
    cin >> value;
    if (search(root, value)) {
        cout << "Value " << value << " found in the tree.\n";
    } else {
        cout << "Value " << value << " not found in the tree.\n";
    }

    // Swap the left and right children of every node
    swapChildren(root);

    // Inorder traversal after swapping the children
    cout << "\nBST after swapping left and right children (Inorder Traversal): ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}