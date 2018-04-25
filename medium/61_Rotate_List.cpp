#include "../libstruct.h"

using namespace std;

/* 
 * NO.61
 * Given a linked list, rotate the list to the right by k places, where k is non-negative.
 */

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return head;
        int l = 0;
        ListNode *p = head, *end;
        while (p && ++l) p = (end = p)->next;
        k %= l; k = l - k - 1;
        p = head;
        while (k--) p = p->next;
        end->next = head;
        head = p->next;
        p->next = NULL;
        return head;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}