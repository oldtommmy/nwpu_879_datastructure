//
// Created by 陈远航 on 2024/6/30.
//
#include <cstdio>
#define MAXSIZE 100
/**
 * 并查集
 */
int sets[MAXSIZE];

/**
 * 初始化
 * @param n
 */
void init(int n) {
    for (int i = 0; i < n; i++) {
        sets[i] = i;
    }
}

/**
 * 查找根结点
 * @param x
 * @return
 */
int findRoot(int x) {
    while (sets[x] != x) {
        x = sets[x];
    }
    printf("%d\n", x); // 打印根结点
    return x;
}

/**
 * 合并
 * @param x
 * @param y
 */
void unionSet(int x, int y) {
    int rootX = findRoot(x);
    int rootY = findRoot(y);
    if (rootX != rootY) {
        sets[rootX] = rootY;
    }
}

