#include <iostream>
#include "../libstruct.h"

using namespace std;

/*
 * No.111
 * Given a binary tree, find its minimum depth.
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int i = 0;
        while(!q.empty()) {
            i++;
            int k = q.size();
            for (int j = 0; j < k; j++) {
                TreeNode* temp = q.front();
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
                q.pop();
                if (!temp->left && !temp->right) return i;
            }
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}
