#include "../libstruct.h"

using namespace std;

/*
 * NO.106
 * Given inorder and postorder traversal of a tree, construct the binary tree.
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildtree(postorder, 0, postorder.size(), inorder, 0, inorder.size());
    }
    
    TreeNode* buildtree(vector<int>& postorder, int i, int j, vector<int>& inorder, int ii, int jj)
    {
        if(i >= j || ii >= jj)
            return NULL;
        int mid = postorder[j - 1];
        auto f = find(inorder.begin() + ii, inorder.begin() + jj, mid);
        int dis = f - inorder.begin() - ii;

        TreeNode* root = new TreeNode(mid);
        root -> left = buildtree(postorder, i, i + dis, inorder, ii, ii + dis);
        root -> right = buildtree(postorder, i + dis, j - 1, inorder, ii + dis + 1, jj);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};
    solution.buildTree(inorder, postorder);
    return 0;
}