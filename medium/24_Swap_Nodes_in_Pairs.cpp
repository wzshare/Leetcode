#include "../libstruct.h"

using namespace std;

/*
 * NO.24
 * Given a linked list, swap every two adjacent nodes and return its head.
 */

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **pp = &head, *a, *b;
        while ((a = *pp) && (b = a->next)) {
            a->next = b->next;
            b->next = a;
            *pp = b;
            pp = &(a->next);
        }
        return head;
    }
    ListNode* swapPairs1(ListNode* head) {
        ListNode* p = head;
        if(!p || !p->next)
            return head;
        p = head->next;
        head->next = swapPairs(p->next);
        p->next = head;
        return p;
    }
};

ListNode* testList()
{
    vector<int> vec = {2,3,4,5,6};
    ListNode *h = new ListNode(1), *p = h;
    for (auto v : vec) {
        p->next = new ListNode(v);
        p = p->next;
    }
    return h;
}

/*
 * input: 1->2->3->4->5->6
 * output: 2->1->4->3->6->5
 */
int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *h;
    h = solution.swapPairs(testList());
    while (h) {cout << h->val << " "; h = h->next;}
    cout << endl;
    h = solution.swapPairs1(testList());
    while (h) {cout << h->val << " "; h = h->next;}
    cout << endl;
    return 0;
}