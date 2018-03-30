#include "../libstruct.h"
#include <cmath>

using namespace std;

/*
 * NO.222
 * Given a complete binary tree, count the number of nodes. 
 */

// Time = O(lgn * lgn)
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lheight = 0, rheight = 0;
        TreeNode *l = root, *r = root;
        while (l) {lheight++; l = l->left;}
        while (r) {rheight++; r = r->right;}
        if (lheight == rheight) return pow(2, lheight) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

/* 
 * [3,9,20,15,7]
 * return
 * 5
 */
TreeNode* testTree()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(15);
    root->left->right = new TreeNode(7);
    return root;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.countNodes(testTree()) << endl;
    return 0;
}