//
// Created by 陈远航 on 2023/10/18.
//
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

void show(vector<int> nums);

/**
 * 直接插入排序 升序
 * 1. 每次排序都能将新的元素，插入至前面、已经排好序的数组中的正确位置
 * 2. 每一轮，我们要记录当前指向的元素至 temp 中
 * 3. 从前一个元素开始，往前遍历，若小于当前待排元素，则继续往前遍历，直到找到插入位置
 * 4. 然后凑后往前，将元素向后移一个位子（这就是为什么要记录到 temp 中），因为会覆盖
 * 5. 直到空出我们要插入的位置，将 temp 填入
 * 时间复杂度
 * Best: O(n)
 * Worst: O(n^2)
 * Avl: O(n^2)
 */
void insertSort(vector<int> &nums) {
    int temp, j;
    for (int i = 0; i < nums.size(); ++i) {
        temp = nums[i];
        j = i - 1;
        while (j >= 0 && nums[j] > temp) {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = temp;
    }
}

/**
 * 折半插入排序
 * 1. 整体思路和直接插入相似
 * 2. 不同的是找插入点这一步骤采取的是二分法，因为前面的数组已经排好序了
 * 时间复杂度
 * Best: O(nlog2n)
 * Worse: O(n^2)
 * Avl: O(n^2)
 */
void insertSortByHalf(vector<int> &nums) {

    int temp, j, left, right, mid;
    for (int i = 0; i < nums.size(); ++i) {
        temp = nums[i];
        left = 0;
        right = i - 1;
        while (left <= right) {
            mid = (left + right) / 2;
            if (temp > nums[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        j = i - 1;
        while (j >= right + 1 && j >= 0) { //⭐️易错：注意此处是 right + 1
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = temp;
    }
}

/**
 * 希尔排序（缩小增量排序）
 * 1. 我们需要一个增量序列，如 5、2、1
 * 2. 第一轮选择最大的增量 5 ，分割子数组，
 * 其中，子数组中的每个元素相隔增量为5，然后对每个子数组使用直接插入排序
 * 3. 第二轮，增量设定为 2 ... ...
 * 时间复杂度
 * Best: O(nlog2n)
 * Worse: O(n^2)
 * Avl: O(n^2)
 * https://www.bilibili.com/video/BV1BK4y1478X
 */
void shellSort(vector<int> &nums) {
    //temp是完成插入排序的记录
    int temp, i, j, inc;
    //一般我们设置初始增量为 n / 2（数组长度一半）， 之后每过一轮缩小一倍
    for (inc = nums.size() / 2; inc > 0; inc /= 2) {

        //序列内部使用直接插入排序
        for (i = inc; i < nums.size(); i++) {
            temp = nums[i];
            j = i - inc;
            //这里我们会从后往前将整个以inc为增量的相隔开的元素组成的数组完成一个直接插入
            while (j >= 0 && nums[j] > temp) {
                nums[j + inc] = nums[j];
                j -= inc;
            }
            nums[j + inc] = temp;
        }
    }
}

/**
 * 快速排序：分制的思想 （不稳定）
 * 1. 每次选择一个基准 pivot 作为比较的参考，比基准小的放前面，大的放后面
 * 2. 每次完成一轮 step1 的操作，我们选择的 pivot 就已经处在正确的位置上
 * 3. 我们对 pivot 所划分的两个子数组再次进行如上的步骤
 * 4. 每次选择 pivot 都是选择的是数组的第一个元素
 * 时间复杂度
 * 最好：O(nlog2n)
 * 最差：O(n^2)
 * 平均:O(nlog2n)
 */
void quickSort(vector<int> &nums, int low, int high) {

    // ij双指针 i在前 j在后遍历
    // 当j的元素小于pivot或i的元素大于pivot 交换ij的元素
    int i = low, j = high, pivot;
    if (low < high) {
        pivot = nums[low]; // 选择第一个元素作为基准
        while (i < j) { // i == j 时退出
            while (i < j && nums[j] >= pivot) { // 从后往前找到比基准小的 while 结束时 nums[j] < pivot
                j--;
            }
            if (i < j) { // 交换
                swap(nums[i], nums[j]);
                i++;
            }
            while (i < j && nums[i] <= pivot) { // 从前往后找到比基准大的 while 结束时 nums[i] > pivot
                i++;
            }
            if (i < j) {
                swap(nums[i], nums[j]); // 交换
                j--;
            }
        }
        show(nums); // 每轮划分的结果
        // 递归调用 对左右两个子数组进行排序 i == j 此时的位置就是基准的位置 也就是说基准已经在正确的位置上了
        quickSort(nums, low, i - 1);
        quickSort(nums, i + 1, high);
    }
}



/**
 * 堆的调整 （大顶堆为例）
 * 1. 下标为i的节点父节点的下标为 整数除法(i-1)/2
 * 2. 下标为i的节点左孩子的下标为 i * 2 + 1
 * 3. 下标为i的节点右孩子的下标为 i * 2 + 2
 * 为了满足堆的特性，我们每要找出当前节点和其两个孩子中
 * 最大的置于当前待维护的下标处，而交换后，可能又会影响交换后
 * 那个孩子节点的子树，因此需要递归去调整
 * @param nums 存储堆的数组
 * @param i 需要维护的结点下标
 * @param n 堆的个数
 */
 void heapAdjust(vector<int> &nums, int i, int n) {
    int largest = i; //假设目前的节点是最大的
    int lSon = 2 * i + 1;
    int rSon = 2 * i + 2;
    if (lSon < n && nums[lSon] > nums[largest]) {
        largest = lSon;
    }
    if (rSon < n && nums[rSon] > nums[largest]) {
        largest = rSon;
    }
    if (i != largest) {
        swap(nums[i], nums[largest]);
        //交换后可能会破坏堆的性质 故递归调整largest这个结点的堆
        heapAdjust(nums, largest, n);
    }
 }

/**
 * 删除堆顶元素:
 * 1. 通常删除堆的元素即是将堆顶的元素和数组最后一个元素交换
 * 2. 然后堆元素个数减一，再从堆顶调整堆
 * @param nums 存储堆的数组
 * @param n 堆的个数
*/
void deleteHeapTop(vector<int> &nums, int &n) {
    if (n <= 0) {
        // 堆已经为空
        return;
    }

    // 将堆顶元素与最后一个元素交换
    swap(nums[0], nums[n - 1]);
    // 堆的大小减1
    n--;

    // 对交换后的堆顶元素进行堆的调整
    heapAdjust(nums, 0, n);
}

 /**
  * 堆排序 （升序用大顶堆）
  * 概念：大顶堆就是每个节点都满足，左孩子和右孩子都比父节点小的一棵，完全二叉树
  * 建堆时间复杂度 O(N)
  * 堆排序复杂度 O(NlogN)
  * 使用数组存储大顶堆 下标符合：
  * 1. 下标为i的节点父节点的下标为 整数除法(i-1)/2
  * 2. 下标为i的节点左孩子的下标为 i * 2 + 1
  * 3. 下标为i的节点右孩子的下标为 i * 2 + 2
  * @param nums
  */
 void heapSort(vector<int> &nums) {
    //建堆 从数组最后一个元素的父结点开始 (n - 1 - 1) / 2 = n / 2 - 1
    int i, n = nums.size(); //n为堆的个数 因为要移出堆 所以用此变量记录
    for(i = n / 2 - 1; i >= 0 ; i--) {
        heapAdjust(nums, i, n);
    }

    /** 排序
     * 1. 第一次交换 最后一个 和 第一个 （也就是堆顶的元素，堆顶永远是最大值）
     * 2. 将最后一个元素 移除堆 （此时堆顶的最大的那个元素已经放在了数组的最后一个位置）
     * 3. 对堆顶的元素重新进行堆的维护，然后接着继续对此时的堆做step1、2的相同操作
     * 4. 直到只剩下一个元素 不用再继续去操作
     */
     for (i = nums.size() - 1; i > 0; i--) {
         swap(nums[i], nums[0]);
         n--;
         heapAdjust(nums, 0, n);
     }
 }

/**
 * 合并划分的数组
 * @param nums
 * @param tempArr 临时数组 完成两个子序列的合并
 * @param left
 * @param mid
 * @param right
 */
void merge(int nums[], int tempArr[], int left, int mid, int right) {
    //i 是数组1的指针 mid + 1是数组2的指针 k是临时数组的指针
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (nums[i] < nums[j]) {
            tempArr[k++] = nums[i++];
        } else {
            tempArr[k++] = nums[j++];
        }
    }
    //合并剩下的
    while (i <= mid) {
        tempArr[k++] = nums[i++];
    }
    while (j <= right) {
        tempArr[k++] = nums[j++];
    }
    //更新到原数组中
    while (left <= right) {
        nums[left] = tempArr[left];
        left++;
    }
}

 /**
  * 归并排序
  * 1. 先划分
  * 2. 后合并
  * @param nums
  * @param tempArr 临时数组 用于合并 main 函数中要用 malloc 初始化
  * @param left
  * @param right
  * @param n
  */
void mergeSort(int nums[], int tempArr[], int left, int right) {
     //只有一个元素时 不用继续划分
     if (left < right) {
         int mid = (left + right) / 2;
         mergeSort(nums, tempArr, left, mid);
         mergeSort(nums, tempArr, mid + 1, right);
         //合并
         merge(nums, tempArr, left, mid, right);
     }
}

/**
 * 冒泡排序（升序）
 * 1. 每轮比较都是从前往后，若后一个小于前一个，则交换
 * 2. 直到 i = n - j (j 即排序轮次，初始化为0)，则完成此轮排序
 * 3. 每轮排序都将最大的元素安放到了偏后的位置
 * 时间复杂度
 * 最好 O(n)
 * 最差 O(n^2)
 * 平均 O(n^2)
 */
void bubbleSort(vector<int> &nums, int n) {
    int flag, i, j;
    for(i = 0; i < n - 1; i++) {
        flag = 0;
        for(j = 0; j < n - i; j++) {
            if (nums[j] > nums[j + 1]) {
                swap(nums[j], nums[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

/**
 * 简单选择排序
 * 1. 每次在未排序数组中选择一个最小的放在最前面
 * 2. 然后循环往后
 * @param nums
 */
void selectSort(vector<int> &nums) {
    int i, j, min;
    for (i = 0; i < nums.size() - 1; i++) {
        min = i;
        for(j = i + 1; j < nums.size(); j++) {
            if (nums[j] < nums[min]) {
                min = j;
            }
        }
        swap(nums[i], nums[min]);
    }
}

void show(vector<int> nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
}


int main() {
    vector<int> nums;
    cout << "input nums: ";
    for (int i = 0; i < 7; ++i) {
        int num;
        cin >> num;
        nums.push_back(num);
    } // 4 2 5 1 7 6 3
    //insertSort(nums);
    //insertSortByHalf(nums);
    //shellSort(nums);
    quickSort(nums, 0, nums.size() - 1);
    //selectSort(nums);
    int numArr[8] = {1, 79, 23, 4, -1, 332, 34, 112};
    //heapSort(nums);
    //int *tempArrForMerge = (int *) ::malloc(8 * sizeof(int));
    //mergeSort(numArr, tempArrForMerge, 0, 7);
    //free(tempArrForMerge);
    //cout << "mergeSort:";
//    for (int i = 0; i < 8; ++i) {
//        cout << numArr[i] << " ";
//    }
//    cout << endl;
    //bubbleSort(nums, 8);
    //cout << "select:";
    show(nums);
    return 0;
}