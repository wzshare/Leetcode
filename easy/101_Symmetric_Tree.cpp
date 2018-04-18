#include <iostream>
#include "../libstruct.h"

using namespace std;

/*
 * No.101
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 */

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return helper(root->left, root->right);
    }
    
    bool helper(TreeNode* left, TreeNode*right) {
        if (left == right) return true;
        if (left && !right || !left && right || left->val != right->val)
            return false;
        return helper(left->left, right->right) && helper(left->right, right->left);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}
