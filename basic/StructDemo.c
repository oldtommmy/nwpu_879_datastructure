//
// Created by TommyChan on 2023/6/26.
//
#include <stdio.h>

typedef struct Node{
    int num;
    struct Node *next; // 定义下一个节点
} Node;

int main() {
    Node n1, n2, n3;
    n1.num = 1;
    n2.num = 2;
    n3.num = 3;
    n1.next = &n2;
    n2.next = &n3;
    n3.next = 0;
    printf("n3's address:%x\n", &n3);
    Node* current = &n1;
    while (current != 0) {
        printf("Current num:%d, current address:%x\n", current->num, current);
        current = current->next;
    }
    return 0;
}
