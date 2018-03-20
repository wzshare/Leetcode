#include "../libstruct.h"

using namespace std;

/*
 * NO.110
 * Given a binary tree, determine if it is height-balanced.
 * For this problem, a height-balanced binary tree is defined 
 * as a binary tree in which the depth of the two subtrees of 
 * every node never differ by more than 1.
*/

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        balance = true;
        depth(root);
        return balance;
    }
private:
    bool balance;

    int depth(TreeNode* root)
    {
        if(root == NULL) return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        if(left - right > 1 || right - left > 1)
            balance = false;
        return left > right ? left + 1 : right + 1;
    }
};

// [3,9,20,null,null,15,7]
// return ture
TreeNode* testTree()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->left = new TreeNode(7);
    return root;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.isBalanced(testTree()) << endl;
    return 0;
}