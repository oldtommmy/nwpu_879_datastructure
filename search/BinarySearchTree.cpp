//
// Created by 陈远航 on 2024/7/17.
//
#include "BinarySearchTree.h"

BTNode* search(BTNode *root, int value) {
    if (root == nullptr) {
        return nullptr;
    }

    if (value > root->data) {
        return search(root->right, value);
    } else if (value < root->data) {
        return search(root->left, value);
    } else {
        return root;
    }
}

void insert(BTNode *&root, int value) {
    if (root == nullptr) {
        root = (BTNode*) malloc(sizeof(BTNode));
        root->data = value;
        root->left = nullptr;
        root->right = nullptr;
    } else if (value > root->data) {
        insert(root->right, value);
    } else if (value < root->data) {
        insert(root->left, value);
    }
}

void createBST(BTNode *&root) {
    int data;
    cout << "input data to create binary search tree: (end with -1)" << endl;
    cin >> data;
    while (data != -1) { // -1 结束输入 用于测试 eg: 5 3 7 2 4 6 8 -1
        insert(root, data);
        cin >> data;
    }
}

void printBST(BTNode *root) {
    if (root != nullptr) {
        printBST(root->left);
        cout << root->data << " ";
        printBST(root->right);
    }
}

int main() {
    BTNode *root = nullptr;
    createBST(root);

    printBST(root);
    cout << endl;

    int value;
    cout << "input value to search: ";
    cin >> value;
    BTNode *node = search(root, value);
    if (node != nullptr) {
        cout << "found" << endl;
    } else {
        cout << "not found" << endl;
    }

    return 0;
}