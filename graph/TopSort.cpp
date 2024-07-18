//
// Created by 陈远航 on 2023/11/12.
//
#include "graph.h"
#include "SeqStack.h"

bool topSort(AGraph *G) {
    SeqStack stack;
    init(stack);

    // 入度为0的顶点入栈
    for (int i = 0; i < G->n; ++i) {
        if (G->adjList[i].count == 0) {
            push(stack, i);
        }
    }

    int count = 0; // 计数
    while (!empty(stack)) {
        int v;
        pop(stack, v);
        cout << v << " ";
        count++;
        ArcNode *p = G->adjList[v].first;
        while (p) {
            int w = p->adjVex;
            G->adjList[w].count--;
            if (G->adjList[w].count == 0) {
                push(stack, w);
            }
            p = p->next;
        }
    }

    if (count < G->n) { // 有回路
        return false;
    } else { // 无回路
        return true;
    }
}

