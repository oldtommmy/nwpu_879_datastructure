//
// Created by 陈远航 on 2023/6/29.
//
#include<cstdio>
#define MAXSIZE 1000

/**
 * 顺序表的定义 静态分配
 */
typedef struct SqList{
    int data[MAXSIZE];
    int length, maxSize; // length 表示当前元素个数 maxSize 表示最大容量
} SqList;

/**
 * 初始化顺序表
 * @param sqList
 */
void init(SqList &sqList) {
    sqList.length = 0;
    sqList.maxSize = MAXSIZE;
}


/**
 * 查找元素 返回 index 不存在返回-1
 * @param target
 * @param sqList
 * @return index
 */
int findIndex(int target, SqList &sqList) {
    int i;
    for (i = 0; i < sqList.length; i++) {
        if (sqList.data[i] == target) {
            return i;
        }
    }
    return -1;
}

/**
 * 插入元素到 index 位置
 * @param value
 * @param sqList
 */
void insert(int value, SqList &sqList, int index) {
    if (sqList.length == sqList.maxSize) {
        return;
    }
    if (index < 0 || index >= sqList.maxSize) {
        return;
    }
    for (int i = sqList.length; i > index; i--) {
        sqList.data[i] = sqList.data[i - 1];
    }
    sqList.data[index] = value;
    sqList.length++;
}

void deleteNum(int value, SqList &sqList) {
    int index = findIndex(value, sqList);
    if (index == -1) {
        return;
    }
    for (int i = index; i < sqList.length - 1; i++) {
        sqList.data[i] = sqList.data[i + 1];
    }
    sqList.length--;
}

int main(){
    SqList sqList;
    init(sqList);
    for (int i = 0; i < 5; ++i) {
        sqList.data[i] = i * 10;
        sqList.length++;
    }
    for (int i = 0; i < sqList.length; ++i) {
        printf("%d ", sqList.data[i]);
    }
    printf("\n");
    // 0 10 20 30 40
    insert(100, sqList, 2);
    deleteNum(20, sqList);
    // 0 10 100 30 40
    for (int i = 0; i < sqList.length; ++i) {
        printf("%d ", sqList.data[i]);
    }
    return 0;
}