//
// Created by 陈远航 on 2023/11/19.
//
#include "graph.h"

/**
 * 普利姆算法
 * 1. 首先任选一个顶点加入集合set
 * 2. 之后每次选未加入set的到 set的最近的那一条边加入
 * @param G
 * @param v
 * @param sum
 */
void prim(MGraph G, int v, int &sum) {
    int vSet[G.n], lowCast[G.e];
    int i, j;
    vSet[v] = 1;
    for (i = 0; i < G.n; i++) {
        lowCast[i] = G.edge[v][i];
    }
    //set中已经有了一个点 故共 n - 1 次循环
    for (i = 0; i < G.n - 1; i++) {
        //每次选择到set 最小的边
        int min = -1;
        for (j = 0; j < G.n; j++) {
            if (vSet[j] == 0 && G.edge[])
        }
    }
}