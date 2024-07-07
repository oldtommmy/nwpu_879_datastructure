//
// Created by 陈远航 on 2023/11/12.
//

#ifndef NWPU_GRAPH_H
#define NWPU_GRAPH_H
#define MAXSIZE 999999
#define VertexType int

#endif //NWPU_GRAPH_H
#include <cstdio>

/**
 * 邻接矩阵
 */
typedef struct MGraph{
    int n, e; // 顶点数和边数
    VertexType edge[MAXSIZE][MAXSIZE];
} MGraph;

/**
 * 边表
 */
typedef struct ArcNode{
    int adjVex; // 该边指向的顶点
    struct ArcNode* next; // 指向下一条边的指针
} ArcNode;

/**
 * 头结点
 */
typedef struct VNode{
    int data; // 顶点信息
    int count; // 出度
    struct ArcNode* first; // 指向第一条边的指针
} VNode;

/**
 * 邻接表
 */
typedef struct AGraph{
    int n, e; // 顶点数和边数
    struct VNode adjList[MAXSIZE]; // 头结点数组
} AGraph;