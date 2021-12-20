#pragma once

template <typename T>
class MyBinaryTree {
private:
    struct node {
        T key;
        node* parent;
        node* left;
        node* right;
        node(T newKey) : key(newKey), parent(nullptr), left(nullptr), right(nullptr) {}
    };

    void deleteSubtree(node* node) {
        if (node->left) {
            deleteSubtree(node->left);
        }
        if (node->right) {
            deleteSubtree(node->right);
        }
        delete node;
    }

    void insertSubtree(node* newNode) {
        if (!root) {
            root = newNode;
        }
        else {
            node* temp = root;
            bool isFinished = false;
            while (!isFinished) {
                newNode->parent = temp;
                if (newNode->key < temp->key) {
                    if (temp->left) {
                        temp = temp->left;
                    }
                    else {
                        temp->left = newNode;
                        isFinished = true;
                    }
                }
                else {
                    if (temp->right) {
                        temp = temp->right;
                    }
                    else {
                        temp->right = newNode;
                        isFinished = true;
                    }
                }
            }
        }
    }

    node* findNode(T key) {
        node* temp = root;
        while (temp) {
            if (key < temp->key) {
                temp = temp->left;
            }
            else if (key > temp->key) {
                temp = temp->right;
            }
            else {
                return temp;
            }
        }
        return nullptr;
    }

    node* root;

public:
    MyBinaryTree() : root(nullptr) {}
    ~MyBinaryTree() {
        if (root) {
            deleteSubtree(root);
        }
    }

    void insert(T key) {
        node* newNode = new node(key);
        insertSubtree(newNode);
    }

    bool find(T key) {
        return findNode(key);
    }

    void remove(T key) {
        node* temp = findNode(key);
        if (temp) {
            if (temp == root) {
                delete root;
                root = nullptr;
            }
            else {
                if (key < temp->parent->key) {
                    temp->parent->left = temp->left;
                }
                else {
                    temp->parent->right = temp->left;
                }
                if (temp->left) {
                    temp->left->parent = temp->parent;
                }
                if (temp->right) {
                    insertSubtree(temp->right);
                }
                delete temp;
            }
        }
    }
};
