#include "../libstruct.h"

using namespace std;

/*
 * NO.236
 * Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || q == root) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right)
            return root;
        else
            return left ? left : right;
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
    TreeNode *root = testTree();
    TreeNode *p = root->left->left, *q = root->right;
    TreeNode *ancestor = solution.lowestCommonAncestor(root, p, q);
    cout << ancestor->val << endl;
    return 0;
}