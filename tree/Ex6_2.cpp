//
// Created by 陈远航 on 2023/7/5.
//
#include "BinaryTree.h"

//1. 分别求左子树和右子树的最大深度
//2. 然后取最大值 + 1
int getDepth(BTNode *root) {
    if (root == NULL) {
        return 0;
    }

    return std::max(getDepth(root->left), getDepth(root->right)) + 1;
}

int main() {
    BTNode *root;
    createByPre(root); //ABD###C#F## 3
    int depth = getDepth(root);
    printf("depth:%d", depth);
    return 0;
}