//
// Created by 陈远航 on 2024/7/10.
//
#include "graph.h"
#include "algorithm"

typedef struct Edge{
    int begin; // 边的起点
    int end; // 边的终点
    int weight; // 边的权值
} Edge;

Edge edges[MAXSIZE]; // 边集数组
int unionSet[MAXSIZE]; // 并查集数组 用于判断是否形成回路 unionSet[i] = j 表示i的父节点是j

/**
 * 查找i的根节点
 * @param set 并查集
 * @param i 节点
 * @return 根节点
 */
int findRoot(int set[], int i) {
    while (set[i] != i) {
        i = set[i];
    }
    return i;
}

/**
 * kruskal算法 适合稀疏图 也就是边的数量远小于顶点的数量
 * @param G 图
 * @param sum 最小生成树的权值
 */
void Kruskal(MGraph G, int &sum) {
    int n = G.n, e = G.e;
    int k = 0; // 边集数组的下标
    for (int i = 0; i < n; ++i) {
        unionSet[i] = i; // 初始化并查集
    }

    // 将图的所有边存入边集数组
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (G.edge[i][j] != INT_MAX) {
                edges[k].begin = i;
                edges[k].end = j;
                edges[k].weight = G.edge[i][j];
                k++;
            }
        }
    }

    // 对边集数组按权值从小到大排序
    // 此处使用冒泡排序
    for (int i = 0; i < e - 1; ++i) {
        bool flag = false;
        for (int j = 0; j < e - i - 1; ++j) {
            if (edges[j].weight > edges[j + 1].weight) {
                swap(edges[j], edges[j + 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }

    // 选取n-1条边
    for (int i = 0; i < e; ++i) {
        int begin = edges[i].begin, end = edges[i].end;
        int root1 = findRoot(unionSet, begin);
        int root2 = findRoot(unionSet, end);
        if (root1 != root2) { // 不构成回路
            unionSet[root1] = root2; // 合并两个集合
            sum += edges[i].weight;
        }
    }
}