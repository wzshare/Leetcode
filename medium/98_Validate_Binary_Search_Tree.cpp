#include "../libstruct.h"

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isvalidbst(root, NULL, NULL);
    }
private:
    bool isvalidbst(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (!root) return true;
        if ((min && min->val >= root->val) || (max && max->val <= root->val)) 
            return false;
        return isvalidbst(root->left, min, root) && isvalidbst(root->right, root, max);
    }
};


/*
 * [10,5,15,null,null,6,20]
 * return 0
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