#include "../libstruct.h"

using namespace std;

/*
 * NO.141
 * Given a linked list, determine if it has a cycle in it. 
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast) {
            fast = fast->next;
            if (fast && (slow = slow->next)) fast = fast->next;
            else return false;
            if (slow == fast) return true;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}
