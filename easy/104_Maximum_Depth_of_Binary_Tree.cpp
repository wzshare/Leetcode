#include "../libstruct.h"

using namespace std;

/*
 * No.104
 * Given a binary tree, find its maximum depth.
 * The maximum depth is the number of nodes along the longest path from the root 
 * node down to the farthest leaf node.
 */

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}