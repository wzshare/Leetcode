#include "../libstruct.h"

using namespace std;

/*
 * NO.2
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The digits are stored in reverse order and each of their nodes contain a single 
 * digit. Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, 
 * except the number 0 itself.
 */ 

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode *head = new ListNode(0), *p = head;
        while(l1 || l2 || c)
        {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + c;
            c = sum / 10;
            p->next = new ListNode(sum % 10);
            p = p->next;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
        }

        return head->next;
    }
};

/*
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 */
int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *l1 = new ListNode(2), *l2 = new ListNode(5);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);
    ListNode *p = solution.addTwoNumbers(l1, l2);
    while (p) {cout << p->val; p = p->next;}
    cout << endl;
    return 0;
}