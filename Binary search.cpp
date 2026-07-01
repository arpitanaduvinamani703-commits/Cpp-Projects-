#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

Node* insert(Node* root, int value) {
    if(root == NULL)
        return new Node(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void inorder(Node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

bool search(Node* root, int key) {
    if(root == NULL)
        return false;

    if(root->data == key)
        return true;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}

int main() {
    Node* root = NULL;
    int choice, value;

    do {
        cout << "\n===== BINARY SEARCH TREE =====";
        cout << "\n1. Insert";
        cout << "\n2. Display (Inorder)";
        cout << "\n3. Search";
        cout << "\n4. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice) {

        case 1:
            cout << "Enter Value: ";
            cin >> value;
            root = insert(root, value);
            break;

        case 2:
            cout << "BST Elements: ";
            inorder(root);
            cout << endl;
            break;

        case 3:
            cout << "Enter Value to Search: ";
            cin >> value;

            if(search(root, value))
                cout << "Value Found!" << endl;
            else
                cout << "Value Not Found!" << endl;
            break;

        case 4:
            cout << "Program Ended.";
            break;

        default:
            cout << "Invalid Choice!";
        }

    } while(choice != 4);

    return 0;
}
