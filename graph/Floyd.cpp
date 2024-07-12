//
// Created by 陈远航 on 2024/7/10.
//
#include "graph.h"

/** Floyd算法 解决多源最短路径问题
 * 思想是：对于每一对顶点i和j，看看是否存在一个顶点k，使得i到k和k到j的路径长度之和小于i到j的路径长度
 * 如果存在这样的k，那么i到j的最短路径就是i到k和k到j的路径之和，否则i到j的最短路径就是i到j的路径
 * @param G 图
 * @param dist 最短路径长度 dist[i][j] = k 表示从i到j的最短路径长度
 * @param path 最短路径 path[i][j] = k 表示从i到j的最短路径经过k
 */
void floyd(MGraph G, int dist[][MAXSIZE], int path[][MAXSIZE]) {
    int n = G.n;
    for (int i = 0; i < n; ++i) { // 初始化
        for (int j = 0; j < n; ++j) {
            dist[i][j] = G.edge[i][j];
            if (i != j && G.edge[i][j] < INT_MAX) { // i到j有边
                path[i][j] = i;
            } else {
                path[i][j] = -1; // i到j无边
            }
        }
    }

    for (int k = 0; k < n; ++k) { // 顶点k作为中间顶点
        for (int i = 0; i < n; ++i) { // 顶点i
            for (int j = 0; j < n; ++j) { // 顶点j
                // 顶点i到顶点j的最短路径经过顶点k 比直接到顶点j的路径短 更新
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}