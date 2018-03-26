#include "../libstruct.h"

using namespace std;

/*
 * NO.105
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildtree(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode* buildtree(vector<int>& preorder, int i, int j, vector<int>& inorder, int ii, int jj)
    {
        if(i >= j || ii >= jj)
            return NULL;
        int mid = preorder[i];
        auto f = find(inorder.begin() + ii, inorder.begin() + jj, mid);
        int dis = f - inorder.begin() - ii;

        TreeNode* root = new TreeNode(mid);
        root -> left = buildtree(preorder, i + 1, i + 1 + dis, inorder, ii, ii + dis);
        root -> right = buildtree(preorder, i + 1 + dis, j, inorder, ii + dis + 1, jj);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    solution.buildTree(preorder, inorder);
    return 0;
}