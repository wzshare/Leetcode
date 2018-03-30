#include "../libstruct.h"

using namespace std;

/*
 * NO.230
 * Given a binary search tree, write a function kthSmallest to 
 * find the kth smallest element in it.
 */

// inorder
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> vec;
        helper(root, vec);
        return vec[k-1];
    }
    void helper(TreeNode* root, vector<int>& vec) {
        if (!root) return;
        helper(root->left, vec);
        vec.push_back(root->val);
        helper(root->right, vec);
    }
};

/* 
 * [10,6,15,5,8] k=4
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
    cout << solution.kthSmallest(testTree(), 4) << endl;
    return 0;
}