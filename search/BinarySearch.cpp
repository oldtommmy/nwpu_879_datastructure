//
// Created by 陈远航 on 2024/7/18.
//
#include "iostream"

using namespace std;

/**
 * @param nums
 * @param key
 * @param n 数组大小
 */
int binarySearch(int nums[], int key, int n) {
    int left, right, mid;
    left = 0;
    right = n - 1;
    while (left <= right) {
        mid = (left + right) / 2;
        if (key > nums[mid]) {
            left = mid + 1;
        } else if (key < nums[mid]) {
            right = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int key;
    cout << "input key to search: ";
    cin >> key;
    int index = binarySearch(nums, key, 9);
    if (index != -1) {
        cout << "find " << key << " at index " << index << endl;
    } else {
        cout << "not found" << endl;
    }
    return 0;
}