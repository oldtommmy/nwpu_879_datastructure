#include <iostream>
using namespace std;

typedef struct QNode {
    int data;
    int high;  // 优先级
    struct QNode* next;
} QNode;

// 入队
QNode* enQueue(QNode*& head, int data, int high) {
    QNode* node = (QNode*)malloc(sizeof(QNode));
    node->data = data;
    node->high = high;
    node->next = nullptr;
    if (head == nullptr) {
        return node;
    }
    if (head->high <= node->high) {
        node->next = head;
        head = node;
    } else {
        QNode* cur = head;
        while (cur->next != nullptr) {
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
    if (head == nullptr) {
        return nullptr;
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
    for (size_t i = 0; i < 5; i++) {
        outQueue(node, out);
    }

    return 0;
}