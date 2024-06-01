//
// Created by 陈远航 on 2023/6/28.
//
#include <iostream>
#define NULL nullptr //使得代码更贴近考研代码

//结点的定义
typedef struct LNode{
    int data;
    struct LNode *next;
} LNode; //别名标识处

/**
 * 初始化链表
 * @param head 链表的头结点
 */
void init(LNode *&head) {
    head = (LNode*) malloc(sizeof(LNode));
    head->next = NULL;
}


/**
 * 获取链表的长度
 * @param head 链表的头结点
 * @return
 */
int getLen(LNode *head) {
    int len = 0;
    LNode *current = head->next;
    while (current != NULL) {
        len++;
        current = current->next;
    }
    return len;
}



/**
 * 尾插法创建链表
 * @param n
 * @param data
 * @param size
 */
void createByTail(LNode *&head, int data[], int size) {
    LNode *tail, *current; //current指向新添加的节点、tail指向最后一个节点
    tail = head; //首先链表只有一个节点 故tail指向这个最后的节点 即tail的初始化
    //开始遍历data 把待添加的元素 加入到链表
    for (int i = 0; i < size; ++i) {
        //给新添加的节点分配空间
        current = (LNode*)malloc(sizeof(LNode));
        //赋值
        current->data = data[i];
        //添加进链表的末尾
        tail->next = current;
        //更新tail的位置
        tail = tail->next;
    }
    //添加完后 tail的next置空
    tail->next = NULL;
}

/**
 * 头插法创建链表
 * @param n
 * @param data
 * @param size
 */
void createByHead(LNode *&head, int data[], int size) {
    //head是头结点 current是新添加的结点
    LNode *current;
    for (int i = 0; i < size; ++i) {
        //为新添加的结点分配空间
        current = (LNode*) malloc(sizeof(LNode));
        current->data = data[i];
        //将current加入链表中 添加在链表的头部 的下一个
        current->next = head->next;
        head->next = current;
    }
}

/**
 * 删除一个值为 target 的元素
 * @param target
 * @param lNode
 * @return 删除是否成功
 */
bool deleteValue(int target, LNode *&n) {
    //我们在删除时，需要知道前一个node，这样才能将后半部分拼接起来
    LNode *pre;
    pre = n;
    //我们传入的n 是一个表头结点 实际上不含data
    //n->next才是第一个带有data的结点
    while (pre->next != NULL) {
        if (pre->next->data == target) {
            //此时pre的下一个结点即是我们要删去的结点
            break;
        }
        pre = pre->next;
    }
    //判断此时的pre是指向NULL还是 在待删结点的上一个结点的位置
    if (pre->next == NULL) {
        return false;
    }
    //注意释放内存
    LNode *toBeDeleted = pre->next;
    pre->next = pre->next->next;
    free(toBeDeleted);
    return true;
}


/**
 * 合并两个链表 尾插法
 * @param n1
 * @param n2
 * @param res
 */
void merge(LNode *n1, LNode *n2, LNode *&res) {
    //因为使用的是带表头结点的链表 所以这里指向n1->next
    LNode *p = n1->next;
    LNode *q = n2->next;
    LNode *tail;    //始终指向res的尾部
    res = (LNode*) malloc(sizeof(LNode)); //给 res 分配一个内存
    res->next = NULL;
    tail = res;
    free(n1);
    free(n2);
    while (p!=NULL && q!=NULL) {
        if (p->data <= q->data) {
            tail->next = p;
            p = p->next;
            tail = tail->next;
        } else{
            tail->next = q;
            q = q->next;
            tail = tail->next;
        }
    }
    tail->next = NULL;
    if (p!=NULL) {
        tail->next = p;
    } else {
        tail->next = q;
    }
}

/**
 * 合并链表 头插法 此处是非抢占式
 * 抢占式即不再重新建立一个头结点 而是占用已有的一个结点
 * @param n1
 * @param n2
 * @param res
 */
void mergeByHead(LNode *n1, LNode *n2, LNode *&res) {
    res = (LNode*) malloc(sizeof(LNode));
    LNode *head = res;
    LNode *p = n1->next;
    LNode *q = n2->next;
    LNode *current;
    free(n1);
    free(n2);
    head->next = NULL;
    while (p!=NULL && q!=NULL) {
        if (p->data <= q->data) {
            current = p;
            p = p->next;
            current->next = head->next;
            head->next = current;
        } else{
            current = q;
            q = q->next;
            current->next = head->next;
            head->next = current;
        }
    }

    if (q != NULL) {
        p = q;
    }

    while (p != NULL) {
        current = p;
        p = p->next;
        current->next = head->next;
        head->next = current;
    }
    free(p);
    free(q);
}

/**
 * 原链表都是由小到大
 * 抢占式头插法合并 且从大到小的顺序
 * @param n1
 * @param n2
 * @param res
 */
void mergeByHeadWithoutNewHead(LNode *n1, LNode *n2, LNode *&res) {
    res = (LNode*) malloc(sizeof(LNode));
    LNode *head  = n1;
    LNode *current;
    LNode *p = n1->next;
    LNode *q = n2->next;
    head->next = NULL;
    while (p != NULL && q != NULL) {
        if (q->data <= p->data) {
            current = q;
            q = q->next;
            current->next = head->next;
            head->next = current;
        } else {
            current = p;
            p = p->next;
            current->next = head->next;
            head->next = current;
        }
    }
    //为了保证递减 小的先插入
    while (p != NULL) {
        current = p;
        p = p->next;
        current->next = head->next;
        head->next = current;
    }
    while (q != NULL) {
        current = q;
        q = q->next;
        current->next = head->next;
        head->next = current;
    }
    res = head;
}


int main(){
    LNode *lNode1, *lNode2, *mergeOne;
    init(lNode1);
    init(lNode2);

    int data1[] = {1,3,5,7,9,11};
    int data2[] = {8,6,4,2};
    createByTail(lNode1, data1, 6);
    createByHead(lNode2, data2, 4);
    printf("lNode1 len:%d\n", getLen(lNode1));
    printf("lNode2 len:%d\n", getLen(lNode2));


    //mergeByHead(lNode1, lNode2, mergeOne);
    mergeByHeadWithoutNewHead(lNode1,lNode2,mergeOne);
    LNode *current = mergeOne->next;

    printf("merge one:\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    printf("mergeOne len:%d\n", getLen(mergeOne));

    int target = 11;
    if (deleteValue(target, mergeOne)) {
        current = mergeOne->next;
        printf("Delete value:%d successfully\nAfter delete:\n", target);
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
    } else {
        printf("No such value %d\n", target);
    }
    return 0;
}