#include "ListNode.h"

class Solution {
   public:
    // 203.移除元素：给你一个链表的头节点 head 和一个整数 val
    // ，请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next != nullptr) {
            if (cur->next->val == val) {
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete (tmp);
            } else {
                cur = cur->next;
            }
        }
        if (cur->val == val) {
            delete (cur);
        }
        return dummy->next;
    }

    // 206.翻转链表:给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* tmp;
        ListNode* cur = head;
        while (cur != nullptr) {
            tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    // 24.两两交换链表中的结点：给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必
    //须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while (cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp1 = cur->next->next->next;
            ListNode* tmp2 = cur->next;
            cur->next = cur->next->next;
            cur->next->next = tmp2;
            tmp2->next = tmp1;
            cur = cur->next->next;
        }
        return dummy->next;
    }

    //19.给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
    //双指针的经典应用，如果要删除倒数第n个节点，让fast移动n步，然后让fast和slow同时移动，直到  
    //fast指向链表末尾。删掉slow所指向的节点就可以了。
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* slow = dummyHead;
        ListNode* fast = dummyHead;
        while(n-- && fast != NULL) {
            fast = fast->next;
        }
        fast = fast->next; // fast再提前走一步，因为需要让slow指向删除节点的上一个节点
        while (fast != NULL) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next; 
        return dummyHead->next;
    }

    //160.给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两
    //个链表没有交点，返回 null 。
    //我们求出两个链表的长度，并求出两个链表长度的差值，然后让curA移动到，和curB 末尾对齐的位置
    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curA = headA;
        ListNode* curB = headB;
        int lenA = 0, lenB = 0;
        while (curA != NULL) { // 求链表A的长度
            lenA++;
            curA = curA->next;
        }
        while (curB != NULL) { // 求链表B的长度
            lenB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        // 让curA为最长链表的头，lenA为其长度
        if (lenB > lenA) {
            swap (lenA, lenB);
            swap (curA, curB);
        }
        // 求长度差
        int gap = lenA - lenB;
        // 让curA和curB在同一起点上（末尾位置对齐）
        while (gap--) {
            curA = curA->next;
        }
        // 遍历curA 和 curB，遇到相同则直接返回
        while (curA != NULL) {
            if (curA == curB) {
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
        return NULL;
    }
};
