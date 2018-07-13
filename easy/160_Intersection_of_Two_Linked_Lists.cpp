#include "../libstruct.h"

using namespace std;

/*
 * No.160
 * Write a program to find the node at which the intersection of two singly linked lists begins. 
 */

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0, n = 0;
        ListNode *p = headA, *q = headB;
        while (headA) {
            headA = headA->next;
            m++;
        }
        while (headB) {
            headB = headB->next;
            n++;
        }
        if (m > n) {
            int diff = m - n;
            while (diff--) p = p->next;
        } else {
            int diff = n - m;
            while (diff--) q = q->next;
        }
        while (p && q) {
            if (p == q) return p;
            p = p->next;
            q = q->next;
        }
        return NULL;
    }
};