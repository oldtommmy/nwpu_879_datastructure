//
// Created by 陈远航 on 2023/11/12.
//

#ifndef NWPU_GRAPH_H
#define NWPU_GRAPH_H
#define MAXSIZE 999999

#endif //NWPU_GRAPH_H
#include <cstdio>

typedef struct MGraph{
    int n, e;
    int edge[MAXSIZE][MAXSIZE];
} MGraph;

/**
 * 边表
 */
typedef struct ArcNode{
    int adjvex;
    struct ArcNode* next;
};

/**
 * 头结点表
 */
typedef struct VNode{
    int data;
    int count;
    struct ArcNode* first;
};

typedef struct AGraph{
    int n, e;
    struct VNode adjList[MAXSIZE];
};