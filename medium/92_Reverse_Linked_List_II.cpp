#include "../libstruct.h"

using namespace std;

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode **mptr = &head, **nptr = mptr;
        while (--n) {
            nptr = &((*nptr)->next);
            if (--m)
                mptr = &((*mptr)->next);
        }
        ListNode **temp = mptr;
        *mptr = *nptr;
        *nptr = *temp;
        return head;
    }
};

ListNode* test()
{
    vector<int> vec = {1, 2, 3, 4, 5};
    ListNode *head = new ListNode(0);
    for (auto v : vec) {
        ListNode *t = new ListNode(v);
        head->next = t;
    }
    return head->next;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    ListNode *head = test();
    solution.reverseBetween(head, 2, 4);
    return 0;
}