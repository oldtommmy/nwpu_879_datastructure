//
// Created by 陈远航 on 2024/7/4.
//
#include "iostream"
#include "graph.h"
#include "SeqQueue.h"

#define MAXSIZE 10

using namespace std;


int visited[MAXSIZE]; // 访问标记数组

/**
 * 广度优先搜索 by 邻接矩阵
 * @param G 图
 * @param v 起始顶点
 */
void BFSByMGraph(MGraph G, int v) {

    for (int i = 0; i < G.n; i++) {
        visited[i] = 0;
    }

    SeqQueue queue;
    init(queue);
    cout << v << " ";
    visited[v] = 1;
    offer(queue, v); // 入队

    while (!empty(queue)) {
        int u; // 出队元素
        poll(queue, u);
        for (int w = 0; w < G.n; w++) { // 遍历所有顶点
            if (G.edge[u][w] == 1 && visited[w] == 0) { // 与u相邻且未访问
                cout << w << " "; // 访问 w
                visited[w] = 1; // 标记 w 已访问
                offer(queue, w); // w 入队
            }
        }
    }
}

/**
 * 避免非联通图的情况
 * 广度优先搜索 by 邻接矩阵
 * @param G 图
 */
void bfsByMGraph(MGraph G) {
    for (int i = 0; i < G.n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < G.n; i++) {
        if (visited[i] == 0) {
            BFSByMGraph(G, i);
        }
    }
}

/**
 * 广度优先搜索 by 邻接表
 * @param G 图
 * @param v 起始顶点
 */
 void BFSByAGraph(AGraph G, int v) {

    for (int i = 0; i < G.n; i++) {
        visited[i] = 0;
    }

    SeqQueue queue;
    init(queue);
    cout << v << " ";
    visited[v] = 1;
    offer(queue, v); // 入队

    while (!empty(queue)) {
        int u; // 出队元素
        poll(queue, u);
        ArcNode *p = G.adjList[u].first;
        while (p != nullptr) {
            if (visited[p->adjVex] == 0) { // 未访问
                cout << p->adjVex << " "; // 访问
                visited[p->adjVex] = 1; // 标记已访问
                offer(queue, p->adjVex); // 入队
            }
            p = p->next;
        }
    }
 }


/**
 * 避免非联通图的情况
 * 广度优先搜索 by 邻接表
 * @param G 图
 */
void bfsByAGraph(AGraph G) {
    for (int i = 0; i < G.n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < G.n; i++) {
        if (visited[i] == 0) {
            BFSByAGraph(G, i);
        }
    }
}


 /**
  * 获取两个顶点之间的最短距离 其中 v 是起始顶点 w 是终止顶点
  * 思想：广度优先搜索，每次遍历到一个顶点，就将其加入到队列中，然后再遍历与其相邻的顶点
  * 直到遍历到终止顶点，此时的距离就是最短距离，因为广度优先搜索是逐层遍历的
  * 不带权图的最短路径
  * @param G  图
  * @param v  起始顶点
  * @param w  终止顶点
  * @return  最短距离
  */
 int getMinDistanceByBFS(MGraph G, int v, int w) {

     for (int i = 0; i < G.n; i++) {
         visited[i] = 0;
     }

     SeqQueue queue;
     init(queue);
     visited[v] = 1;
     offer(queue, v); // 入队

     int distance[G.n]; // 距离数组
     for (int i = 0; i < G.n; i++) {
         distance[i] = -1; // distance[i] 指的是 v 到 i 的距离
     }
     distance[v] = 0;

     while (!empty(queue)) {
         int u; // 出队元素
         poll(queue, u); // 出队
         for (int x = 0; x < G.n; x++) { // 遍历所有顶点
             if (G.edge[u][x] == 1 && visited[x] == 0) { // 与u相邻且未访问
                 visited[x] = 1; // 标记 x 已访问
                 offer(queue, x); // x 入队
                 distance[x] = distance[u] + 1;
             }
         }
     }
     cout << "The distance between " << v << " and " << w << " is " << distance[w] << endl;
     return distance[w];
 }