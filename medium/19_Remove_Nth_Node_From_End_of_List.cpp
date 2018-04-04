#include "../libstruct.h"

using namespace std;

/*
 * NO.19
 * Given a linked list, remove the nth node from the end of list and return its head.
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (n <= 0) return head;
        ListNode **p = &head, *q = head;;
        while (n > 1) {
            q = q->next;
            n--;
        }
        while (q->next) {
            p = &((*p)->next);
            q = q->next;
        }
        *p = (*p)->next;
        return head;
    }
};

/*
 * input: linked list: 1->2->3, and n = 2.
 * output: 1->3
 */ 
int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    solution.removeNthFromEnd(head, 2);
    while(head) {cout << head->val << " "; head = head->next;}
    return 0;
}