//
// Created by 陈远航 on 2023/11/19.
//
#include "graph.h"

/**
 * 普利姆算法 适合稠密图 也就是边比较多的图
 * 1. 首先任选一个顶点加入集合set
 * 2. 之后每次从未加入到 set 集合的顶点中选取到已加入到 set 集合的顶点的最小边加入到 set 集合
 * @param G 图
 * @param v 起始顶点
 * @param sum 最小生成树的权值
 */
void prim(MGraph G, int v, int &sum) {
    // vSet 为 1 表示已经加入set
    // lowCast 为vSet中的顶点到未加入set的顶点的最小边
    int vSet[G.n], lowCast[G.e];
    vSet[v] = 1; // 选取v为起始点
    for (int i = 0; i < G.n; ++i) {
        if (i != v) {
            lowCast[i] = G.edge[v][i];
        }
    }

    // 选取剩余的 n-1 个顶点
    for (int i = 0; i < G.n - 1; ++i) {
        int min = INT_MAX, k = -1; // k 为最小边的顶点, min 为最小边
        for (int j = 0; j < G.n; ++j) {
            if (vSet[j] == 0 && lowCast[j] < min) {
                min = lowCast[j];
                k = j;
            }
        }
        if (k == -1) { // 说明没有找到最小边
            break;
        }
        vSet[k] = 1;
        sum += min;
        for (int j = 0; j < G.n; ++j) { // 更新 lowCast
            if (vSet[j] == 0 && G.edge[k][j] < lowCast[j]) {
                lowCast[j] = G.edge[k][j];
            }
        }
    }
}