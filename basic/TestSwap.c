#include <stdio.h>

/**
 * C 语言中交换数组两元素 需要传入指针
 * @param p
 * @param q
 */
void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}


int main()
{
    int nums[3] = {1, 2, 3};
    int nums1[3] = {2,5,9};
    swap(&nums, &nums1);
    for (int i = 0; i < 3; ++i) {
        printf("%d ", nums[i]);
    }
    return 0;
}