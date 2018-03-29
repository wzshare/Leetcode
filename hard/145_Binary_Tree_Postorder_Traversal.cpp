#include "../libstruct.h"

using namespace std;

/*
 * NO.145
 * Given a binary tree, return the postorder traversal of its nodes' values.
 */

class Solution {
public:
    //Recursive
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        helper(root, vec);
        return vec;
    }
private:
    void helper(TreeNode* root, vector<int>& vec) {
        if (!root) return;
        helper(root->left, vec);
        helper(root->right, vec);
        vec.push_back(root->val);
    }
public:
    //Iterative
    vector<int> postorderTraversal2(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> st1, st2;
        if (root) st1.push(root);
        while (!st1.empty()) {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if (root->left) st1.push(root->left);
            if (root->right) st1.push(root->right);
        }
        while (!st2.empty()) {
            vec.push_back(st2.top()->val);
            st2.pop();
        }
        return vec;
    }
};

/*
 * input: [1,2,3,#,4]
 * output: [4,2,3,1]
 */
TreeNode* testTree()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    return root;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> vec = solution.postorderTraversal(testTree());
    for (auto v : vec)
        cout << v << " ";
    cout << endl;
    vec = solution.postorderTraversal2(testTree());
    for (auto v : vec)
        cout << v << " ";
    cout << endl;
    return 0;
}