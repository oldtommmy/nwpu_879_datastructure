//
// Created by 陈远航 on 2023/7/5.
//
#include "BinaryTree.h"
#define MAXSIZE 10

typedef struct Node{
    BTNode *node;
    int level; //层数
} Node;

int getWidth(BTNode *root) {
    int width = 0, max = 0;
    Node queue[MAXSIZE];
    int front, rear;
    //current是当前计算的层数 nodeLevel是当前访问结点的层数
    int currentLevel, nodeLevel;
    front = rear = 0;
    BTNode *cur;
    if (root != NULL) {
        rear++;
        queue[rear].node = root;
        queue[rear].level = 1;
        currentLevel = 1;
        while (front != rear) {
            front++;
            cur = queue[front].node;
            nodeLevel = queue[front].level;
            if (cur->left != NULL) {
                rear++;
                queue[rear].node = cur->left;
                queue[rear].level = queue[front].level + 1;
            }

            if (cur->right != NULL) {
                rear++;
                queue[rear].node = cur->right;
                queue[rear].level = queue[front].level + 1;
            }
            if (currentLevel != nodeLevel) {
                max = max > width ? max : width;
                currentLevel++;
                width = 1;
            } else {
                width++;
            }
        }
    }
    max = max > width ? max : width;
    return max;
}


int main() {
    BTNode *root;
    createByPre(root); //abd##e##cf###
    int width = getWidth(root);
    printf("width:%d", width);
    return 0;
}