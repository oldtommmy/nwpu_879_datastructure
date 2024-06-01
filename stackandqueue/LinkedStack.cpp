//
// Created by 陈远航 on 2023/6/30.
//
#include <iostream>

/**
 * 链栈的实现
 */
typedef struct LNode{
    int data;
    struct LNode *next;
}LNode;

//初始化
void init(LNode *&node) {
    node = (LNode*) malloc(sizeof(LNode));
    node->next = NULL;
}

//判空
bool empty(LNode *node) {
    return node->next == NULL;
}

//入栈：和链表的头插法一致
void push(LNode *&node, int target) {
    LNode *cur = (LNode*) malloc(sizeof(LNode));
    cur->data = target;
    cur->next = node->next;
    node->next = cur;
}

//出栈
bool pop(LNode *&node, int &popValue) {
    if (empty(node)) {
        return false;
    }

    popValue = node->next->data;
    node->next = node->next->next;
    return true;
}

int main() {
    LNode *stack;
    int popValue;
    init(stack);
    for (int i = 0; i < 10; ++i) {
        push(stack,i);
    }
    while (!empty(stack)) {
        pop(stack, popValue);
        printf("%d ", popValue);
    }
    return 0;
}


