//
// 链式队列
// Created by 陈远航 on 2023/6/30.
//
#include <iostream>
#define NULL nullptr // clion 总是提示我使用nullptr 报 warning 很烦人 所以这里定义NULL为nullptr

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

/**
 * 初始化队列
 * @param queue
 */
void init(LinkedQueue *&queue) {
    queue = (LinkedQueue*) malloc(sizeof(LinkedQueue));
    queue->rear = queue->front = NULL;
}

/**
 * 判断队空
 * @param queue
 * @return
 */
bool empty(LinkedQueue *queue) {
    return queue->front == NULL;
}

/**
 * 入队
 * @param queue
 * @param value 入队的值
 */
void offer(LinkedQueue *&queue, int value) {
    QNode *node = (QNode*) malloc(sizeof(QNode));
    node->data = value;
    node->next = NULL;

    //队列为空时 特殊处理 front和rear都指向node
    if (queue->rear == NULL) {
        queue->rear = node;
        queue->front = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

/**
 * 出队
 * @param queue
 * @param value 出队的值
 * @return
 */
bool poll(LinkedQueue *&queue, int &value) {
    QNode *node;
    if (empty(queue)) {
        return false;
    }

    node = queue->front;
    value = node->data;

    //队列只有一个元素时 特殊处理
    //要保证queue为空时，rear和front都指向NULL，而不是野指针
    if (queue->front == queue->rear) {
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
