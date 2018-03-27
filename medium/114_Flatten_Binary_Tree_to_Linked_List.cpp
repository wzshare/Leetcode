#include "../libstruct.h"

using namespace std;

/*
 * NO.114
 * Given a binary tree, flatten it to a linked list in-place.
 */

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root)
            return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* temp = root->right;
        root->right = root->left;
        root->left = NULL;
        while(root->right)
            root = root->right;
        root->right = temp;
    }
};

/* 
 * input:
 * [1,null,2,3]
 * output:
 * [1,null,2,null,3]
 */
TreeNode* testTree()
{
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    solution.flatten(testTree());
    return 0;
}