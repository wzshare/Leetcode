#include "../libstruct.h"

using namespace std;

/*
 * NO.234
 * Given a singly linked list, determine if it is a palindrome.
 */

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) return true;
        ListNode *p = head, *q = head, *t;
        int size = 0;
        while(p && ++size) p = p->next;
        size /= 2;
        while(size--) q = q->next;
        p = q->next;
        q->next = NULL;
        while (p) {
            t = p->next;
            p->next = q;
            q = p;
            p = t;
        }
        while(head && q && head != q) {
            if (head->val != q->val) return false;
            head = head->next;
            q = q->next;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *head = new ListNode(1);
    ListNode *next = new ListNode(0);
    head->next = next;
    next = new ListNode(0);
    head->next->next = next;
    solution.isPalindrome(head);
    return 0;
}