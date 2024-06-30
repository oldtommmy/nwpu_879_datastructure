//
// Created by 陈远航 on 2023/7/8.
//
#include "iostream"
using namespace std;

/**
 * 哈夫曼树
 */
typedef struct HTNode {
    double weight; // 结点权值
    int parent; // 记录父结点的下标 0 表示没有父结点 从 1 开始使用
    int left, right; // 记录左右孩子的下标 0 表示没有左右孩子 从 1 开始使用
} HTNode;

// 选择两个权值最小的 结点 下标 s1 s2 为这两个结点的下标 n 为当前结点个数
void selectMinWeight(HTNode* ht, int& s1, int& s2, int n) {
    // 找到两个权值最小的结点下标
    s1 = s2 = 0;
    for (int i = 1; i <= n; i++) {
        if (ht[i].parent == 0) { // 未使用的结点
            if (s1 == 0 || ht[i].weight < ht[s1].weight) { // 未初始化 或者找到更小的
                s2 = s1; // 将原来的最小值赋给次小值
                s1 = i; // 更新最小值
            } else if (s2 == 0 || ht[i].weight < ht[s2].weight) { // 未初始化 或者找到更小的
                s2 = i; // 更新次小值
            }
        }
    }

    // 将已经选择的结点标记为已用
    ht[s1].parent = ht[s2].parent = n + 1;
}


void create(HTNode*& ht, int n) {
    int m = 2 * n - 1;  // 从 1 开始使用,n 个结点,那么总共需要 2n - 1 个结点
    ht = new HTNode[m + 1]; // 从 1 开始使用,所以需要 m + 1 个结点

    // 初始化每一个结点
    for (int i = 1; i <= m; i++) {
        ht[i].left = 0;
        ht[i].right = 0;
        ht[i].parent = 0;
    }

    // 输入权值
    for (int i = 1; i <= n; i++) {
        cin >> ht[i].weight;
    }

    // 开始构造 每次拿两个权值最小的结点 然后将生成的结点放入ht中
    int s1, s2;
    for (int i = n + 1; i <= m; i++) { // 构造的新结点放在 n + 1 到 m 中
        selectMinWeight(ht, s1, s2, n);
        ht[i].weight = ht[s1].weight + ht[s2].weight;
    }
}

typedef char** HuffmanCode; // HuffmanCode 是一个二维数组类型 存放每一个结点的编码串

// hc 是一个二维数组存放每一个结点的编码串
void huffmanEncoding(HTNode*& ht, HuffmanCode &hc, int n) {
    hc = new char*[n + 1];     // 从 1 开始使用 存 n 个结点的编码
    for (int i = 1; i <= n; i++) { // 为每个结点分配内存
        hc[i] = new char[n + 1];
    }
    char* code = new char[n];  // 每个结点的编码长度最长是 n - 1
    code[n - 1] = '\0';

    // 编码开始
    // 从叶子结点开始向上回溯
    for (int i = 1; i <= n; i++) {
        int c = i;  // 记录当前结点在数组中的下标
        int start = n - 1; // 记录当前编码串的开始位置
        int p = ht[i].parent;  // 记录当前结点的父亲在数组中的下标

        while (p != 0) { // 当前结点不是根结点
            start--; // 从后往前存放编码串
            if (ht[p].left == c) {
                code[start] = '0';
            } 
            if (ht[p].right == c) {
                code[start] = '1';
            }
            c = p; // 更新当前结点
            p = ht[p].parent;
        }

        hc[i][0] = '\0'; // 清空当前编码字符串
        strcpy(hc[i], &code[start]);
    }

    delete[] code; // 删除临时数组 code
    // 在使用完hc后，释放所有分配的内存
    for (int i = 1; i <= n; i++) {
        delete[] hc[i]; // 释放每个编码字符串的内存
    }
    delete[] hc; //删除临时数组 hc
}
