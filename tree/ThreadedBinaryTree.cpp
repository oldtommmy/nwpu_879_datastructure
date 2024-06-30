//
// Created by 陈远航 on 2023/7/7.
//
#include "iostream"
#define NULL nullptr

typedef struct TBTNode{
    char data;
    struct TBTNode *lChild, *rChild;
    int lTag, rTag; // 0：表示指向孩子 1：指向前驱后继
} TBTNode;

/**
 * 创建二叉树
 * @param root
 */
void createByPre(TBTNode *&root) {
    char data;
    scanf("%c", &data);
    if (data == '#') {
        root = NULL;
    } else {
        root = (TBTNode*) malloc(sizeof(TBTNode));
        root->data = data;
        createByPre(root->lChild);
        createByPre(root->rChild);
    }
}

/**
 * 线索化中序二叉树
 * @param cur 当前结点
 * @param pre 上一个访问的结点
 */
void changeToInOrderThreadedTree(TBTNode *&cur, TBTNode *&pre) {
    if (cur == NULL) {
        return;
    }

    changeToInOrderThreadedTree(cur->lChild, pre);
    //我们在此处可以处理的是 当前结点的 lChild 和 上一个结点的 rChild
    if (cur->lChild == NULL) {
        cur->lTag = 1;
        cur->lChild = pre;
    }
    if (pre != NULL && pre->rChild == NULL) {
        pre->rTag  = 1;
        pre->rChild = cur;
    }
    pre = cur;
    changeToInOrderThreadedTree(cur->rChild, pre);
}

void toTBT(TBTNode *root) {
    TBTNode *pre = NULL;
    if (root != NULL) {
        changeToInOrderThreadedTree(root, pre);
        root->lTag = 0;
        root->lChild = pre;
    }
}

//找最左结点
TBTNode *first(TBTNode *root) {
    while (root->lChild != NULL) {
        root = root->lChild;
    }
    return root;
}

TBTNode *next(TBTNode *root) {
    if (root->rTag == 0) {
        return first(root->rChild);
    } //tag = 0,指向右孩子，则把右孩子当做根结点，去找子树的最左结点
    return root->rChild; //tag = 1, 指向后继结点
}

/**
 * 线索化中序遍历
 * @param root 根结点
 */
void inOrderVisit(TBTNode *root) {
    for(TBTNode *node = first(root); node != NULL; node = next(node)) {
        printf("%c ", node->data);
    }
}


int main() {
    TBTNode *root;
    createByPre(root);
    toTBT(root);
    inOrderVisit(root);
    return 0;
}
