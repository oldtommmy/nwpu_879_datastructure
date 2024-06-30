//
// Created by 陈远航 on 2023/6/30.
//
#include <iostream>
#define MAXSIZE 15
#define NULL nullptr  // CLion 有黄色的warning 比较碍眼

typedef struct BTNode {
    char data;
    struct BTNode* left;
    struct BTNode* right;
} BTNode;

void init(BTNode*& root) {
    root = (BTNode*) malloc(sizeof(BTNode));
    root->left = NULL;
    root->right = NULL;
}

/**
 * 先序创建树 根左右
 * @param data
 * @param root
 */
void createByPre(BTNode*& root) {
    char data;
    scanf("%c", &data);
    if (data == '#') {
        root = NULL;
    } else {
        root = (BTNode*) malloc(sizeof(BTNode));
        root->data = data;
        createByPre(root->left);
        createByPre(root->right);
    }
}

/**
 * 先序遍历
 * @param root
 */
void preOrder(BTNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

/**
 * 非递归的先序遍历
 * *** 自己定义栈 ***
 * 模拟系统递归调用时使用栈
 * @param root 根结点
 */
void preOrderNonRecursion(BTNode* root) {
    BTNode* stack[MAXSIZE];
    int top = -1;
    BTNode* node;
    if (root != NULL) {
        stack[++top] = root;
    }
    while (top != -1) {
        node = stack[top--];
        printf("%c ", node->data);
        if (node->right != NULL) {
            stack[++top] = node->right;
        }
        if (node->left != NULL) {
            stack[++top] = node->left;
        }
    }
}

/**
 * 中序遍历
 * @param root
 */
void inOrder(BTNode* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    printf("%c ", root->data);
    inOrder(root->right);
}

/**
 * 非递归的中序遍历 ⭐️⭐️⭐️
 * 1. 使用一个指针去遍历树
 * 2. 首先查找左孩子，直到遍历指针为NULL
 * 3. 此时从栈中弹出，输出data
 * 4. 遍历指针指向弹出的元素，若有右孩子，则指向右孩子，重复以上操作
 * 参考视频：https://www.bilibili.com/video/BV1Zf4y1a77g/?vd_source=7aaca833504124307819810a986fc5e6
 * @param root
 */
void inNonRecursion(BTNode* root) {
    BTNode* stack[MAXSIZE];
    int top = -1;
    BTNode* node = root;  // 遍历指针
    while (node != NULL || top != -1) {
        while (node != NULL) {
            stack[++top] = node;
            node = node->left;  // 左
        }
        node = stack[top--];
        printf("%c ", node->data);  // 中
        node = node->right;         // 右
    }
}

/**
 * 后序遍历
 * @param root
 */
void postOrder(BTNode* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%c ", root->data);
}

/**
 * 非递归后序遍历
 * 1. 逆后序遍历是在前序遍历的基础上将左右子树遍历顺序改一下
 * 2. 即变为 根 右 左
 * 3. 使用一个额外的栈用来倒置
 * @param root
 */
void postNonRecursion(BTNode* root) {
    BTNode *stack[MAXSIZE], *helper[MAXSIZE];
    int stackTop = -1, helpTop = -1;
    BTNode* node;
    if (root != NULL) {
        stack[++stackTop] = root;
    }

    while (stackTop != -1) {
        node = stack[stackTop--];
        helper[++helpTop] = node;
        if (node->left != NULL) {
            stack[++stackTop] = node->left;
        }
        if (node->right != NULL) {
            stack[++stackTop] = node->right;
        }
    }
    while (helpTop != -1) {
        printf("%c ", helper[helpTop--]->data);
    }
}

/**
 * 层次遍历 使用到队列
 * @param root
 */
void level(BTNode* root) {
    int front, rear;
    BTNode* queue[MAXSIZE];
    front = rear = 0;
    BTNode* cur;
    if (root != NULL) {
        rear = (rear + 1) % MAXSIZE;
        queue[rear] = root;
        while (front != rear) {
            front = (front + 1) % MAXSIZE;
            cur = queue[front];
            printf("%c ", cur->data);
            if (cur->left != NULL) {
                rear = (rear + 1) % MAXSIZE;
                queue[rear] = cur->left;
            }

            if (cur->right != NULL) {
                rear = (rear + 1) % MAXSIZE;
                queue[rear] = cur->right;
            }
        }
    }
}

int main() {
    BTNode* root;
    init(root);
    createByPre(root);  // ABD##H##C#F##
    printf("Pre:");
    preOrder(root);
    printf("\nPre Non Recursion:");
    preOrderNonRecursion(root);
    printf("\nIn:");
    inOrder(root);
    printf("\nIn Non Recursion:");
    inNonRecursion(root);
    printf("\nPost:");
    postOrder(root);
    printf("\nPost Non Recursion:");
    postNonRecursion(root);
    printf("\nLevel:");
    level(root);
    return 0;
}