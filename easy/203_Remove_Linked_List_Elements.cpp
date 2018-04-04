#include "../libstruct.h"

using namespace std;

/*
 * NO.203
 * Remove all elements from a linked list of integers that have value val.
 */

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode **p = &head;
        while (*p) {
            if ((*p)->val == val)
                *p = (*p)->next;
            else
                p = &((*p)->next);
        }
        return head;
    }
};

/*
 * input: linked list: 1->2->3->2, and n = 2.
 * output: 1->3
 */
int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    solution.removeElements(head, 2);
    while(head) {cout << head->val << " "; head = head->next;}
    return 0;
}