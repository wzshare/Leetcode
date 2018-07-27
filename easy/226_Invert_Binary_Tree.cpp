#include "../libstruct.h"

using namespace std;

class Solution {
public:
    // recursive
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    // iterative
    TreeNode* invertTree1(TreeNode* root) {
        queue<TreeNode *> q;
        if (root) q.push(root);
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
            swap(node->left, node->right);
        }
        return root;
    }
};