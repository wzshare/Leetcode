#include "../libstruct.h"
#include <vector>

using namespace std;
/*
 * NO.94
 * Given a binary tree, return the inorder traversal of its nodes' values.
 */

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        traversal(root, result);
        return result;
    }
private:
    void traversal(TreeNode* root, vector<int> &vec)
    {
        if (root->left) traversal(root->left, vec);
        if (root) vec.push_back(root->val);
        if (root->right) traversal(root->right, vec);
    }
};

/* 
 * input:
 * [1,null,2,3]
 * output:
 * [1,3,2]
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
    for (auto val : solution.inorderTraversal(testTree()))
    {
        cout << val << endl;
    }
    return 0;
}