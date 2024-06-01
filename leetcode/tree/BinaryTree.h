//
// Created by 陈远航 on 2023/11/16.
//

#ifndef NWPU_BINARYTREE_H
#define NWPU_BINARYTREE_H

#endif //NWPU_BINARYTREE_H
#include <vector>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};