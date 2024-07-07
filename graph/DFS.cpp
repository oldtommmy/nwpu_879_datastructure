//
// Created by 陈远航 on 2024/7/6.
//
#include "graph.h"
#include "SeqStack.h"
#define MAXSIZE 10

using namespace std;

int visited[MAXSIZE]; // 访问标记数组

/**
 * 深度优先搜索 by 邻接矩阵
 * @param G 图
 * @param v 起始顶点
 */
void DFSByMGraph(MGraph G, int v) {
    for (int i = 0; i < G.n; i++) {
        visited[i] = 0;
    }

    SeqStack stack;
    init(stack);
    cout << v << " ";
    visited[v] = 1;
    push(stack, v); // 入栈

    while (!empty(stack)) {
        int out; // 出栈元素
        pop(stack, out);
        for (int w = 0; w < G.n; w++) { // 遍历所有顶点
            if (G.edge[out][w] == 1 && visited[w] == 0) { // 与out相邻且未访问
                cout << w << " "; // 访问 w
                visited[w] = 1; // 标记 w 已访问
                push(stack, w); // w 入栈
                break;
            }
        }
    }
}

/** 避免非联通图的情况
 * 深度优先搜索 by 邻接矩阵
 * @param G 图
 */
void dfsByMGraph(MGraph G) {
    for (int i = 0; i < G.n; ++i) {
        visited[i] = 0;
    }
    for (int i = 0; i < G.n; ++i) {
        if (visited[i] == 0) {
            DFSByMGraph(G, i);
        }
    }
}


/**
 * 深度优先搜索 by 邻接表
 * @param G 图
 * @param v 起始顶点
 */
 void DFSByAGraph(AGraph G, int v) {
    for (int i = 0; i < G.n; i++) {
        visited[i] = 0;
    }

    SeqStack stack;
    init(stack);
    cout << v << " ";
    visited[v] = 1;
    push(stack, v); // 入栈
    while (!empty(stack)) {
        int out; // 出栈元素
        pop(stack, out);
        ArcNode *p = G.adjList[out].first;
        while (p != nullptr) {
            if (visited[p->adjVex] == 0) { // 未访问
                cout << p->adjVex << " "; // 访问
                visited[p->adjVex] = 1; // 标记已访问
                push(stack, p->adjVex); // 入栈
                p = p->next;
            }
        }
    }
 }

/** 避免非联通图的情况
 *  深度优先搜索 by 邻接表
 *  @param G 图
 */
void dfsByAGraph(AGraph G) {
    for (int i = 0; i < G.n; ++i) {
        visited[i] = 0;
    }
    for (int i = 0; i < G.n; ++i) {
        if (visited[i] == 0) {
            DFSByAGraph(G, i);
        }
    }
}

/**
 * 递归实现深度优先搜索 by 邻接矩阵
 * @param G 图
 * @param v 起始顶点
 */
void DFSWithRecursionByMGraph(MGraph G, int v) {
    cout << v << " ";
    visited[v] = 1;
    for (int w = 0; w < G.n; w++) {
        if (G.edge[v][w] == 1 && visited[w] == 0) {
            DFSWithRecursionByMGraph(G, w);
        }
    }
}

/** 避免非联通图的情况
 * 递归实现深度优先搜索 by 邻接矩阵
 * @param G 图
 */
void dfsWithRecursionByMGraph(MGraph G) {
    for (int i = 0; i < G.n; ++i) {
        visited[i] = 0;
    }
    for (int i = 0; i < G.n; ++i) {
        if (visited[i] == 0) {
            DFSWithRecursionByMGraph(G, i);
        }
    }
}

/**
 * 递归实现深度优先搜索 by 邻接表
 * @param G 图
 * @param v 起始顶点
 */
void DFSWithRecursionByAGraph(AGraph G, int v) {
    cout << v << " ";
    visited[v] = 1;
    ArcNode *p = G.adjList[v].first;
    while (p != nullptr) {
        if (visited[p->adjVex] == 0) {
            DFSWithRecursionByAGraph(G, p->adjVex);
        }
        p = p->next;
    }
}

/** 避免非联通图的情况
 * 递归实现深度优先搜索 by 邻接表
 * @param G 图
 */
void dfsWithRecursionByAGraph(AGraph G) {
    for (int i = 0; i < G.n; ++i) {
        visited[i] = 0;
    }
    for (int i = 0; i < G.n; ++i) {
        if (visited[i] == 0) {
            DFSWithRecursionByAGraph(G, i);
        }
    }
}