//
// Created by 陈远航 on 2024/7/6.
//

#ifndef MASTER_EXAM_SEQSTACK_H
#define MASTER_EXAM_SEQSTACK_H

#endif //MASTER_EXAM_SEQSTACK_H
#include <iostream>
#define MAXSIZE 5

/**
 * 顺序栈的定义
 */
typedef struct SeqStack{
    int data[MAXSIZE];
    int top; //栈顶指针 指向的是栈顶元素
} SeqStack;

/**
 * 初始化栈
 * top = -1表示栈空
 * @param stack
 */
void init(SeqStack &stack) {
    stack.top = -1;
}

/**
 * 判断栈空
 * @param stack
 * @return
 */
bool empty(SeqStack stack) {
    return stack.top == -1;
}

/**
 * 判断栈满
 * @param stack
 * @return
 */
bool full(SeqStack stack) {
    return stack.top == MAXSIZE - 1;
}

/**
 * 入栈
 * @param stack
 * @param value
 */
bool push(SeqStack &stack, int value) {
    if (full(stack)) {
        return false;
    }
    stack.top++;
    stack.data[stack.top] = value;
    return true;
}

/**
 * 出栈
 * @param stack
 * @param popValue
 * @return
 */
bool pop(SeqStack &stack, int &popValue) {
    if (empty(stack)) {
        return false;
    }
    popValue = stack.data[stack.top];
    stack.data[stack.top] = 0;
    stack.top--;
    return true;
}