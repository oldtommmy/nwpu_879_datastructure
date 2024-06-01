#include <iostream>
/**
 * 使用链表表示两个长整数相加
 * 1. 原链表由地位开始存储
 * 2. 注意进位
 */

// 结点的定义
typedef struct LNode {
    int data;
    struct LNode* next;
} LNode;  // 别名标识处

LNode* add(LNode* a, LNode* b) {
    LNode *res, *cur;
    LNode *p = a->next, *q = b->next;
    res = a;
    res->next = nullptr;
    int sum = 0, flag = 0;
    while (p != nullptr && q != nullptr) {
        sum = p->data + q->data + flag;
        if (sum >= 10) {
            flag = 1;
            sum %= 10;
        } else {
            flag = 0;
        }
        cur = (LNode*)malloc(sizeof(LNode));
        cur->data = sum;
        cur->next = res->next;
        res->next = cur;
        p = p->next;
        q = q->next;
    }
    while (p != nullptr) {
        cur = (LNode*)malloc(sizeof(LNode));
        sum = p->data + flag;
        if (sum >= 10) {
            flag = 1;
            sum %= 10;
        } else {
            flag = 0;
        }
        cur->data = sum;
        cur->next = res->next;
        res->next = cur;
        p = p->next;
    }
    while (q != nullptr) {
        cur = (LNode*)malloc(sizeof(LNode));
        sum = q->data + flag;
        if (sum >= 10) {
            flag = 1;
            sum %= 10;
        } else {
            flag = 0;
        }
        cur->data = sum;
        cur->next = res->next;
        res->next = cur;
        q = q->next;
    }
    if (flag == 1) {
        cur = (LNode*)malloc(sizeof(LNode));
        cur->data = 1;
        cur->next = res->next;
        res->next = cur;
    }

    return res;
}

/**
 * 头插法创建链表
 * @param n
 * @param data
 * @param size
 */
void createByHead(LNode*& head, int data[], int size) {
    // head是头结点 current是新添加的结点
    LNode* current;
    head->next = NULL;
    for (int i = 0; i < size; ++i) {
        current = (LNode*)malloc(sizeof(LNode));
        current->data = data[i];
        current->next = head->next;
        head->next = current;
    }
}

void print(LNode* p) {
    LNode* current = p->next;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int n1[] = {1,2,4,5};
    int n2[] = {1,2,4,5};
    LNode* l1 = (LNode*)malloc(sizeof(LNode));
    LNode* l2 = (LNode*)malloc(sizeof(LNode));
    LNode* l3;

    createByHead(l1, n1, 4);
    createByHead(l2, n2, 4);

    printf("first one: ");
    print(l1);
    printf("second one: ");
    print(l2);

    l3 = add(l1, l2);
    printf("sum = ");
    print(l3);
    return 0;
}