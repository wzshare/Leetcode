#include "../libstruct.h"

using namespace std;

/*
 * NO.237
 * Write a function to delete a node (except the tail) 
 * in a singly linked list, given only access to that node.
 */

class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}