//
// Created by 陈远航 on 2024/7/10.
//
#include "graph.h"
#include "algorithm"

/**Dijkstra算法 解决单源最短路径问题
 * @param G 图
 * @param v 起始顶点
 * @param dist 最短路径长度 dist[i] = j 表示从v到i的最短路径长度
 * @param path 最短路径 path[i] = j 表示从v到i的最短路径经过j
 */
void dijkstra(MGraph G, int v, int dist[], int path[]) {
    int n = G.n;
    int set[n]; // s[i] = 1 表示顶点i已经加入s中
    for (int i = 0; i < n; ++i) { // 初始化
        dist[i] = G.edge[v][i];
        set[i] = 0;
        if (G.edge[v][i] < INT_MAX) {
            path[i] = v;
        } else {
            path[i] = -1;
        }
    }
    dist[v] = 0;
    set[v] = 1;

    for (int i = 0; i < n - 1; ++i) {
        int min = INT_MAX, u = -1; // u 为最小边的顶点
        for (int j = 0; j < n; ++j) {
            if (set[j] == 0 && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        if (u == -1) {
            break;
        }
        set[u] = 1;
        for (int j = 0; j < n; ++j) { // 更新dist
            // 未加入s中的顶点 且u到j有边
            if (set[j] == 0 && G.edge[u][j] < INT_MAX && dist[u] + G.edge[u][j] < dist[j]) {
                dist[j] = dist[u] + G.edge[u][j];
                path[j] = u;
            }
        }
    }
}
