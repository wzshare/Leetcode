#include "../libstruct.h"

using namespace std;

/*
 * NO.86
 * Given a linked list and a value x, partition it such that all nodes less than x 
 * come before nodes greater than or equal to x.
 * You should preserve the original relative order of the nodes in each of the two 
 * partitions.
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *h1 = new ListNode(0), *h2 = new ListNode(0);
        ListNode *p = h1, *q = h2, *t = head;
        while (t != NULL) {
            if (t->val < x) {
                p->next = t;
                p = p->next;
            }
            else {
                q->next = t;
                q = q->next;
            }
            t = t->next;
        }
        q->next = NULL;
        p->next = h2->next;
        return h1->next;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}