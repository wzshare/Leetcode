#include "../libstruct.h"

using namespace std;

/*
 * NO.109
 * Given a singly linked list where elements are sorted in ascending order, convert 
 * it to a height balanced BST.
 * For this problem, a height-balanced binary tree is defined as a binary tree in 
 * which the depth of the two subtrees of every node never differ by more than 1.
 */ 

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return new TreeNode(head->val);
        ListNode *slow = head, *fast = head, *pre = NULL;
        while (fast != NULL && fast->next != NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}