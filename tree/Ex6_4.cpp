//
// Created by 陈远航 on 2023/7/5.
//
#include "BinaryTree.h"

/**
 * 输出先序的第k个结点
 * @param root 根结点
 * @param cnt 计数器
 * @param k 第 k 个
 */
void showNumberNDataInPre(BTNode *root, int &cnt, int k) {

    if (root == NULL) {
        return;
    }
    cnt++;
    if (cnt == k) {
        printf("No %d's data is %c", k, root->data);
    }
    showNumberNDataInPre(root->left, cnt, k);
    showNumberNDataInPre(root->right, cnt, k);
}

int main() {
    BTNode *root;
    createByPre(root); //ABD###C#F##
    int k, cnt = 0;
    getchar();
    scanf("%d", &k);
    showNumberNDataInPre(root, cnt, k);
    return 0;
}