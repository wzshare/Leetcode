#include "../libstruct.h"

using namespace std;

/*
 * NO.102
 * Given a binary tree, return the level order traversal of its 
 * nodes' values. (ie, from left to right, level by level).
 */

class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        buildVector(root, 0);
        return ret;
    }
private:
    vector<vector<int> > ret;

    void buildVector(TreeNode *root, int depth)
    {
        if(root == NULL) return;
        if(ret.size() == depth)
            ret.push_back(vector<int>());

        ret[depth].push_back(root->val);
        buildVector(root->left, depth + 1);
        buildVector(root->right, depth + 1);
    }
};

/* 
 * [3,9,20,null,null,15,7]
 * return
 *  [
 *    [3],
 *    [9,20],
 *    [15,7]
 *  ]
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
    vector<vector<int> > valList = solution.levelOrder(testTree());
    for (auto vec : valList)
    {
        for (auto val : vec)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}