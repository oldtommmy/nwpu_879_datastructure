#include <iostream>

using namespace std;

typedef struct Polynode {
    int exp;     // 指数
    float ceof;  // 系数
    struct Polynode* next;
} polynode, node;

// 尾插法创建多项式
void create(polynode*& p) {
    polynode* tail;
    tail = p;
    while (true) {
        auto* node = (polynode*)malloc(sizeof(polynode));
        int exp;
        float ceof;
        printf("input ceof:");
        scanf("%f", &ceof);
        if (ceof == 0) {
            free(node);
            break;
        }
        printf("input exp:");
        scanf("%d", &exp);
        node->ceof = ceof;
        node->exp = exp;
        tail->next = node;
        tail = tail->next;
    }
}

void show(polynode* p) {
    if (p == nullptr) {
        return;
    }
    node* cur = p->next;
    while (cur->next != nullptr) {
        printf("(%.3fx^%d)+", cur->ceof, cur->exp);
        cur = cur->next;
    }
    printf("(%fx^%d)", cur->ceof, cur->exp);
}

int main() {
    polynode* p = (polynode*) malloc(sizeof(polynode));
    create(p);
    show(p);
    return 0;
}