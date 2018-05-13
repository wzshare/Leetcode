#include "../libstruct.h"

using namespace std;

/*
 * NO.142
 * Given a linked list, return the node where the cycle begins. 
 * If there is no cycle, return null.
 */

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head, *p = NULL;
        while(fast) {
            fast = fast->next;
            if (slow == p) return p;
            if (fast && (slow = slow->next)) fast = fast->next;
            else return NULL;
            if (p) p = p->next;
            else if (fast == slow) {
                p = fast;
                slow = head;
            }
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}
