#include "../libstruct.h"

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        bool left = true, right = true;
        if (root->left) left = root->val > maxLeft(root->left);
        if (root->right) right = root->val < minRight(root->right);
        return left && right && isValidBST(root->left) && isValidBST(root->right);
    }
private:    
    int maxLeft(TreeNode* root) {
        if (root->right) maxLeft(root->right);
        return root->val;
    }
    
    int minRight(TreeNode* root) {
        if (root->left) minRight(root->left);
        return root->val;
    }
};

/*
 * [10,5,15,null,null,6,20]
 */ 
TreeNode* testTree()
{
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(20);
    return root;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.isValidBST(testTree()) << endl;
    return 0;
}