#include <iostream>
using namespace std;

// Node structure for the AVL Tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int val) : key(val), left(nullptr), right(nullptr), height(1) {}
};

// AVL Tree Class
class AVLTree {
public:
    Node* root;

    AVLTree() : root(nullptr) {}

    // Insert function
    Node* insert(Node* node, int key) {
        if (!node) 
            return new Node(key);

        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        if (getBalance(node) > 1) {
            if (key < node->left->key)
                return rotateRight(node); // Left-Left
            else {
                node->left = rotateLeft(node->left); // Left-Right
                return rotateRight(node);
            }
        }

        if (getBalance(node) < -1) {
            if (key > node->right->key)
                return rotateLeft(node); // Right-Right
            else {
                node->right = rotateRight(node->right); // Right-Left
                return rotateLeft(node);
            }
        }

        return node;
    }

    // Delete function
    Node* deleteNode(Node* node, int key) {
        if (!node) 
            return node;

        if (key < node->key)
            node->left = deleteNode(node->left, key);
        else if (key > node->key)
            node->right = deleteNode(node->right, key);
        else {
            if (!node->left || !node->right) {
                Node* temp = node->left ? node->left : node->right;

                if (!temp)
                    return nullptr;

                *node = *temp;
                delete temp;
            } else {
                Node* temp = getMinValueNode(node->right);
                node->key = temp->key;
                node->right = deleteNode(node->right, temp->key);
            }
        }

        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;

        if (getBalance(node) > 1) {
            if (getBalance(node->left) >= 0)
                return rotateRight(node); // Left-Left
            else {
                node->left = rotateLeft(node->left); // Left-Right
                return rotateRight(node);
            }
        }

        if (getBalance(node) < -1) {
            if (getBalance(node->right) <= 0)
                return rotateLeft(node); // Right-Right
            else {
                node->right = rotateRight(node->right); // Right-Left
                return rotateLeft(node);
            }
        }

        return node;
    }

    // Inorder traversal
    void inorder(Node* root) {
        if (root) {
            inorder(root->left);
            cout << root->key << " ";
            inorder(root->right);
        }
    }

private:
    // Utility functions
    int getHeight(Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(Node* node) {
        return node ? getHeight(node->left) - getHeight(node->right) : 0;
    }

    Node* rotateLeft(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        y->left = x;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    Node* rotateRight(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        x->right = y;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    Node* getMinValueNode(Node* node) {
        Node* current = node;
        while (current->left)
            current = current->left;

        return current;
    }
};

// Driver Code
int main() {
    AVLTree tree;
    int keys[] = {12, 27, 40, 8, 70, 35};

    for (int key : keys)
        tree.root = tree.insert(tree.root, key);

    cout << "Inorder Traversal of AVL Tree:\n";
    tree.inorder(tree.root);

    tree.root = tree.deleteNode(tree.root, 8);
    cout << "\n\nInorder Traversal after Deleting 8:\n";
    tree.inorder(tree.root);

    return 0;
}
