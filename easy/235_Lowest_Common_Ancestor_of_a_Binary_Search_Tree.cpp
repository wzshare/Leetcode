#include "../libstruct.h"

using namespace std;

/*
 * NO.230
 * Given a binary search tree (BST), find the lowest common ancestor (LCA) 
 * of two given nodes in the BST.
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if(p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
        
    }
};

/* 
 * [10,6,15,5,8] p = 5, q = 15
 * return
 * 10
 */
TreeNode* testTree()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(6);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(8);
    return root;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeNode *p = new TreeNode(5), *q = new TreeNode(15);
    TreeNode *ancestor = solution.lowestCommonAncestor(testTree(), p, q);
    cout << ancestor->val << endl;
    return 0;
}