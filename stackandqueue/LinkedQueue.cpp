//
// 链式队列
// Created by 陈远航 on 2023/6/30.
//
#include <iostream>

//队结点的定义
typedef struct QNode{
    int data;
    struct QNode* next;
} QNode;

//链队的定义
typedef struct LinkedQueue{
    struct QNode* front;
    struct QNode* rear;
} LinkedQueue;


void init(LinkedQueue *&queue) {
    queue = (LinkedQueue*) malloc(sizeof(LinkedQueue));
    queue->rear = queue->front = NULL;
}

//队空
bool empty(LinkedQueue *queue) {
    return queue->front == NULL;
}

//入队
//只剩下单个 node 时，应该特别处理
void offer(LinkedQueue *&queue, int value) {
    QNode *node = (QNode*) malloc(sizeof(QNode));
    node->data = value;
    node->next = NULL;
    if (queue->rear == NULL) {
        queue->rear = node;
        queue->front = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

//出队
//注意此处 只剩下单个 node 时，应该特别处理
bool poll(LinkedQueue *&queue, int &value) {
    QNode *node;
    if (empty(queue)) {
        return false;
    }

    node = queue->front;
    value = node->data;
    if (queue->front == queue->rear) { //要保证queue为空时，rear和front都指向NULL，而不是野指针
        queue->rear = queue->front = NULL;
    } else {
        queue->front = node->next;
    }
    free(node);
    return true;
}

int main() {
    LinkedQueue *queue;
    int value;
    init(queue);
    for (int i = 0; i < 10; ++i) {
        offer(queue,i + 1);
    }
    while (!empty(queue)) {
        poll(queue, value);
        printf("%d ", value);
    }
    return 0;
}
