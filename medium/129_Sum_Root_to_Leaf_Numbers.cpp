#include "../libstruct.h"

using namespace std;

/*
 * No.129
 * Given a binary tree containing digits from 0-9 only, each root-to-leaf path 
 * could represent a number.
 * An example is the root-to-leaf path 1->2->3 which represents the number 123.
 * Find the total sum of all root-to-leaf numbers.
 */ 

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return helper(root, 0);
    }
    
    int helper(TreeNode* root, int sum) {
        if (!root) return 0;
        if (!root->left && !root->right) return sum + root->val;
        int current = (sum + root->val) * 10;
        return helper(root->left, current) + helper(root->right, current);
    }
};

/*
 * input: [1, 2, 3]
 * output: 25 
 */

TreeNode* testTree()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    return root;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.sumNumbers(testTree()) << endl;
    return 0;
}