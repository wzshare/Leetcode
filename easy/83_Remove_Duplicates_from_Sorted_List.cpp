#include <iostream>
#include "../libstruct.h"

using namespace std;

/*
 * No.83
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p = head, *q;
        while (p && p->next) {
            q = p->next;
            if (p->val == q->val) p->next = q->next;
            else p = p->next;
        }
        return head;
    }
};

ListNode* testList(vector<int> &vec)
{
    ListNode *h = new ListNode(0), *p = h;
    for (auto v : vec) {
        p->next = new ListNode(v);
        p = p->next;
    }
    return h->next;
}

//input: 1->1->1->2->2->3->3
//output: 1->2->3
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> input = {1, 1, 1, 2, 2, 3, 3};
    ListNode *output = solution.deleteDuplicates(testList(input));
    while (output->next) { cout << output->val << "->"; output = output->next;}
    cout << output->val << endl;
    return 0;
}