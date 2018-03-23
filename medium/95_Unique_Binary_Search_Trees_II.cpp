#include "../libstruct.h"

using namespace std;

/*
 * Given an integer n, generate all structurally unique 
 * BST's (binary search trees) that store values 1...n.
 */

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return vector<TreeNode*> ();
        return gTrees(1, n);
    }
private:
    vector<TreeNode*> gTrees(int start, int end) {
        vector<TreeNode*> res, lefts, rights;
        
        if (start > end) {
            res.push_back(NULL);
            return res;
        } 
        else if (start == end) {
            res.push_back(new TreeNode(start));
            return res;
        }
        
        for (int i = start; i <= end; i ++) {
            lefts = gTrees(start, i - 1);
            rights = gTrees(i + 1, end);
            for (auto left : lefts) {
                for (auto right : rights) {
                    TreeNode* root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
    Solution soluton;
    vector<TreeNode*> root = soluton.generateTrees(3);
    return 0;
}