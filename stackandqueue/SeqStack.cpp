//
// Created by 陈远航 on 2023/6/30.
//
#include <iostream>
#define MAXSIZE 5

/**
 * 顺序栈的定义
 */
typedef struct SeqStack{
    int data[MAXSIZE];
    int top; //栈顶指针
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
 * 入栈
 * @param stack
 * @param value
 */
bool push(SeqStack &stack, int value) {
    if (stack.top == MAXSIZE - 1) {
        return false;
    }
    stack.data[stack.top + 1] = value;
    stack.top++;
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

int main(){
    SeqStack stack;
    int popValue;
    init(stack);
    for (int i = 0; i < MAXSIZE; ++i) {
        push(stack, i);
    }
    while (!empty(stack)) {
        pop(stack, popValue);
        printf("%d ", popValue);
    }
    return 0;
}