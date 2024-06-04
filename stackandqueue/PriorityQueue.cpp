#include <iostream>
#define NULL nullptr // clion 总是提示我使用nullptr 报 warning 很烦人 所以这里定义NULL为nullptr

using namespace std;

/**
 * 优先级队列
 * 什么是优先级队列？ 优先级队列是一种特殊的队列，它的出队顺序不是先进先出，
 * 而是按照元素的优先级高低来出队, 优先级高的元素先出队。
 * 优先级队列的实现有很多种方式，这里我们使用链表来实现优先级队列。
 */
typedef struct QNode {
    int data;
    int high;  // 优先级
    struct QNode* next;
} QNode;

/**
 * 入队
 * @param head
 * @param data
 * @param high
 * @return 返回队列头结点
 */
QNode* enQueue(QNode*& head, int data, int high) {
    QNode* node = (QNode*) malloc(sizeof(QNode));
    node->data = data;
    node->high = high;
    node->next = NULL;
    if (head == NULL) {
        return node;
    }
    if (head->high <= node->high) {
        node->next = head;
        head = node;
    } else {
        QNode* cur = head;
        while (cur->next != NULL) {
            if (cur->next->high <= node->high) {
                break;
            } else {
                cur = cur->next;
            }
        }
        node->next = cur->next;
        cur->next = node;
    }
    return head;
}

// 出队
QNode* outQueue(QNode*& head, int& outData) {
    if (head == NULL) {
        return NULL;
    }
    outData = head->data;
    printf("out of queue : %d\n", outData);
    QNode* tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

int main() {
    QNode* node = (QNode*)malloc(sizeof(QNode));
    node->data = 1;
    node->high = 1;
    enQueue(node, 2, 2);
    enQueue(node, 3, 3);
    enQueue(node, -1, -1);
    int out = 0;
    for (int i = 0; i < 5; i++) {
        outQueue(node, out);
    }

    return 0;
}