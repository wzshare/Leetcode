#include "../libstruct.h"

using namespace std;

/*
 * NO.21
 * Merge two sorted linked lists and return it as a new list. The new list 
 * should be made by splicing together the nodes of the first two lists.
 */

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *h = new ListNode(0), *t = h;
        while (l1 && l2) {
            t = t->next = l1->val < l2->val ? l1 : l2;
            t == l1 ? l1 = l1->next : l2 = l2->next;
        }
        t->next = l1 ? l1 : l2;
        return h->next;
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

/*
 * Input: 1->2->4, 1->3->4
 * Output: 1->1->2->3->4->4
 */
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> vec1 = {1, 2, 4};
    vector<int> vec2 = {1, 3, 4};
    ListNode *h = solution.mergeTwoLists(testList(vec1), testList(vec2));
    while (h) {cout << h->val << " "; h = h->next;}
    cout << endl;
    return 0;
}