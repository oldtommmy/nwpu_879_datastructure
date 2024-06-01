//
// Created by 陈远航 on 2023/7/5.
//

#ifndef NWPU_BINARYTREE_H
#define NWPU_BINARYTREE_H

#endif //NWPU_BINARYTREE_H
#include "iostream"
typedef struct BTNode{
    char data;
    struct BTNode *left;
    struct BTNode *right;
} BTNode;


void init(BTNode *&root) {
    root = (BTNode*) malloc(sizeof(BTNode));
    root->left = NULL;
    root->right = NULL;
}

/**
 * 先序创建树 根左右
 * @param data
 * @param root
 */
void createByPre(BTNode *&root) {
    char data;
    scanf("%c", &data);
    if (data == '#') {
        root = NULL;
    } else {
        root = (BTNode*) malloc(sizeof(BTNode));
        root->data = data;
        createByPre(root->left);
        createByPre(root->right);
    }
}