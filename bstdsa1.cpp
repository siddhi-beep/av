#include <iostream>
using namespace std;

// BST Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to insert a node
Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// Function to find height (longest path from root)
int findHeight(Node* root) {
    if (root == nullptr)
        return 0;

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Function to find minimum value
int findMin(Node* root) {
    if (root == nullptr) {
        cout << "Tree is empty.\n";
        return -1;
    }

    Node* current = root;
    while (current->left != nullptr) {
        current = current->left;
    }
    return current->data;
}

// Inorder Traversal (to display the tree)
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

    cout << "Enter number of initial nodes: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "\nBST after initial insertion (Inorder Traversal): ";
    inorderTraversal(root);
    cout << endl;

    cout << "\nEnter value to insert: ";
    cin >> value;
    root = insert(root, value);

    cout << "\nBST after inserting new node (Inorder Traversal): ";
    inorderTraversal(root);
    cout << endl;

    int height = findHeight(root);
    cout << "\nNumber of nodes in longest path from root (Height): " << height << endl;

    int minValue = findMin(root);
    cout << "Minimum data value found in the tree: " << minValue << endl;

    return 0;
}