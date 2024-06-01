//
// Created by 陈远航 on 2023/7/8.
//
#include "iostream"
using namespace std;

/**
 * 哈夫曼树
 */
typedef struct HTNode {
    double weight;
    int parent;
    int left, right;
} HTNode;

// 选择两个权值最小的
void selectMinWeight(HTNode* ht, int& s1, int& s2, int n) {
    // 找到两个权值最小的结点下标
    s1 = s2 = 0;
    for (int i = 1; i <= n; i++) {
        if (ht[i].parent == 0) {
            if (s1 == 0 || ht[i].weight < ht[s1].weight) {
                s2 = s1;
                s1 = i;
            } else if (s2 == 0 || ht[i].weight < ht[s2].weight) {
                s2 = i;
            }
        }
    }

    // 将已经选择的结点标记为已用
    ht[s1].parent = ht[s2].parent = n + 1;
}


void create(HTNode*& ht, int n) {
    int m = 2 * n - 1;  // 从 1 开始使用
    ht = new HTNode[m + 1];

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
    for (int i = n + 1; i <= m; i++) {
        selectMinWeight(ht, s1, s2, n);
        ht[i].weight = ht[s1].weight + ht[s2].weight;
    }
}

typedef char** HuffmanCode;

// hc 是一个二维数组存放每一个结点的编码串
void huffumanEncoding(HTNode*& ht, HuffmanCode &hc, int n) {
    hc = new char*[n + 1];     // 从 1 开始使用 存 n 个结点的编码
    char* code = new char[n];  // 每个结点的编码长度最长是 n - 1
    code[n - 1] = '\0';

    // 编码开始
    for (int i = 1; i <= n; i++) {
        int c = i;  // 记录当前结点在数组中的下标
        int start = n - 1;
        int p = ht[i].parent;  // 记录当前结点的父亲在数组中的下标

        while (p != 0) {
            start--;
            if (ht[p].left == c) {
                code[start] = '0';
            } 
            if (ht[p].right == c) {
                code[start] = '1';
            } 
            p = ht[p].parent;
        }

        strcpy(hc[i], &code[start]);
    }
    delete(hc); //删除临时数组 hc
}
