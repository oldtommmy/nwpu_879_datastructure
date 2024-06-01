//
// Created by 陈远航 on 2023/7/5.
//
#include "BinaryTree.h"

/**
 * 此处采用先序遍历 实际上三种方式都可以
 * @param root
 * @param res
 * @param target
 */
void find(BTNode *root, BTNode *&res, char target) {
    if (root == NULL) {
        return;
    }

    if (root->data == target) {
        res = root;
    } else {
        find(root->left, res, target);
        if (res == NULL) { //剪枝
            find(root->right, res, target);
        }
    }
}

int main() {
    BTNode *root;
    createByPre(root); //ABD###C#F##
    BTNode *res;
    res = NULL;
    char target;
    getchar();
    scanf("%c", &target);
    find(root, res, target);
    if (res != NULL) {
        printf("res->data = %c", res->data);
    } else {
        printf("res = NULL\n");
    }

    return 0;
}