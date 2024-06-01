//
// Created by 陈远航 on 2023/11/12.
//
#include "graph.h"

int topSort(AGraph *G) {
    int i, top = -1, pop, n = G->n;
    //首先用栈将入度为0的存储起来
    int stack[MAXSIZE];
    for(i = 0; i < G->n; i++) {
        if (G->adjList[i].count == 0) {
            stack[++top] = i;
        }
    }
    //每次输出入度 为0的 并把以它出发的边去掉
    while (top != -1) {
        pop = stack[--top];
        ArcNode *p = G->adjList[pop].first;
        printf("%d", pop);
        n--;
        while (p != nullptr) {
            G->adjList[p->adjvex].count--;
            if (G->adjList[p->adjvex].count == 0) {
                stack[++top] = p->adjvex;
            }
            p = p->next;
        }
    }

    if(n == 0) {
        return 1;
    } else {
        return 0;
    }
}

