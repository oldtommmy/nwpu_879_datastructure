//
// Created by 陈远航 on 2023/11/10.
//
#include <stdio.h>

void change(int *a) {
    *a = 12;
}

int main()
{
    int a = 1;
    printf("%d\n", &a);

    change(&a);
    printf("%d", &a);
}
