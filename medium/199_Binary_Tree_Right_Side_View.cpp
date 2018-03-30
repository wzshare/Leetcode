#include "../libstruct.h"

using namespace std;

/*
 * NO.199
 * Given a binary tree, imagine yourself standing on the right side of it, 
 * return the values of the nodes you can see ordered from top to bottom.
 */

// BTS like NO.102
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vec;
        helper(root, 0, vec);
        return vec;
    }
    void helper(TreeNode* root, int depth, vector<int>& vec) {
        if (!root) return;
        if (depth == vec.size())
            vec.push_back(root->val);
        helper(root->right, depth + 1, vec);
        helper(root->left, depth + 1, vec);
    }
};

/* 
 * [3,9,20,null,null,15,7]
 * return
 * [3,20,7]
 */
TreeNode* testTree()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> vec = solution.rightSideView(testTree());
    for (auto i : vec)
        cout << i << " ";
    return 0;
}