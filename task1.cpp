#include <iostream>
#include <stack>

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
        } else {
            Node* current = root;
            Node* parent = nullptr;

            while (true) {
                parent = current;

                if (value < current->data) {
                    current = current->left;
                    if (current == nullptr) {
                        parent->left = newNode;
                        return;
                    }
                } else {
                    current = current->right;
                    if (current == nullptr) {
                        parent->right = newNode;
                        return;
                    }
                }
            }
        }
    }

    bool search(int value) {
        if (root == nullptr) {
            return false;
        }

        Node* current = root;
        while (current != nullptr) {
            if (value == current->data) {
                return true;
            } else if (value < current->data) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        return false;
    }
};

int main() {
    BinarySearchTree bst;

    bst.insert(5);
    bst.insert(3);
    bst.insert(8);
    bst.insert(2);
    bst.insert(4);
    bst.insert(7);
    bst.insert(9);


    std::cout << bst.search(4) << std::endl;
    std::cout << bst.search(6) << std::endl;

    return 0;
}

