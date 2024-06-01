//
// Created by 陈远航 on 2023/7/5.
//
#include "BinaryTree.h"

int calculate(int a, int b, char c) {
    switch (c) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        default:
            return c - '0';
    }
}

/**
 * 1. 采用后序遍历的方式
 * 2. 我们先拿到左右两个孩子的值，再通过中间的根节点所指示的符号做相关操作
 * @param root
 */
int getValue(BTNode *root) {
    if (root != NULL) {
        int left = getValue(root->left);
        int right = getValue(root->right);
        return calculate(left, right, root->data);
    } else {
        return 0;
    }
}


int main() {
    BTNode *root;
    createByPre(root); //输入：*-4##+1##1##/6##2## -> (a-(b+c)) * (d/e)
    int res = getValue(root);
    printf("res = %d", res);
    return 0;
}