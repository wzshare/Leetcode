#include "../libstruct.h"
#include <queue>

using namespace std;

/* 
 * NO.23
 * Merge k sorted linked lists and return it as one sorted list.
 * Analyze and describe its complexity. 
 */

class Solution {
public:
    struct compare {
        bool operator() (const ListNode* l1, const ListNode* l2) {
            return l1->val > l2->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> min_heap;
        ListNode *head = nullptr, **pre = &head;
        for (auto l : lists) if (l) min_heap.emplace(l);
        while (!min_heap.empty()) {
            *pre = min_heap.top();
            min_heap.pop();
            pre = &(*pre)->next;
            if (*pre) min_heap.emplace(*pre);
        }
        return head;
    }
    //complexity is O(nlogk)
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}