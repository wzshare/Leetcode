#include <iostream>

using namespace std;

/*
 * NO.116
 * Populate each next pointer to point to its next right node. 
 * If there is no next right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 */

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) {
            root->left->next = root->right;
            root->right->next = root->next ? root->next->left : NULL;
        }
        connect(root->left);
        connect(root->right);
    }
};

/*
 * [1,2,3]
 * return [1,#,2,3,#]
 */ 
TreeLinkNode* testTree()
{
    TreeLinkNode* root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    return root;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    solution.connect(testTree());
    return 0;
}