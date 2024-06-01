//
// Created by 陈远航 on 2024/5/31.
//
#include "stdio.h"


void fun(int n)
{
    n = 4;
}

int main()
{
    int n = 3;
    fun(4);
    printf("%d\n", n);
    return 0;
}