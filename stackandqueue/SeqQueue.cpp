//
// 循环队列
// Created by 陈远航 on 2023/6/30.
//
#include <iostream>


#define MAXSIZE 10

/**
 * 循环队列的定义
 */
typedef struct SeqQueue{
    int data[MAXSIZE]; //实际上只能存 MAXSIZE - 1 个数据
    int front; //队首指针
    int rear; //队尾指针
}SeqQueue;


/**
 * 初始化队列
 * @param queue
 */
void init(SeqQueue &queue) {
    queue.front = queue.rear = 0;
}

/**
 * 判断队空
 * @param queue
 * @return
 */
bool empty(SeqQueue queue) {
    return queue.front == queue.rear;
}

/**
 * 判断队满
 * @param queue
 * @return
 */
bool full(SeqQueue queue) {
    return (queue.rear + 1) % MAXSIZE == queue.front;
}

/**
 * 入队
 * @param queue
 * @param value
 * @return
 */
bool offer(SeqQueue &queue, int value) {
    if (full(queue)) {
        return false;
    }
    queue.data[queue.rear] = value;
    queue.rear = (queue.rear + 1) % MAXSIZE;
    return true;
}

/**
 * 出队
 * @param queue
 * @param outValue
 * @return
 */
bool poll(SeqQueue &queue, int &outValue) {
    if (empty(queue)) {
        return false;
    }
    outValue = queue.data[queue.front];
    queue.front = (queue.front + 1) % MAXSIZE;
    return true;
}

int main() {
    SeqQueue queue;
    init(queue);
    int value;
    for (int i = 0; i < 20; ++i) {
        if (!offer(queue, i)) {
            break;
        }
    }
    while (!empty(queue)) {
        poll(queue, value);
        printf("%d ", value);
    }
    return 0;
}