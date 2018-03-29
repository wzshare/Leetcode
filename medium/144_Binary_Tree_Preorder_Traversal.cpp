#include "../libstruct.h"

using namespace std;

class Solution {
public:
    //Recursive
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> vec;
        helper(root, vec);
        return vec;
    }
private:
    void helper(TreeNode* root, vector<int>& vec) {
        if (!root) return;
        vec.push_back(root->val);
        helper(root->left, vec);
        helper(root->right, vec);
    }
public:
    //Iterative
    vector<int> preorderTraversal2(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> st;
        while (root || !st.empty()) {
            if (root) {
                st.push(root);
                vec.push_back(root->val);
                root = root->left;
            }
            else {
                root = st.top();
                root = root->right;
                st.pop();
            }
        }
        return vec;
    }
};

/*
 * input: [1,2,3,#,4]
 * output: [1,2,4,3]
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
    vector<int> vec = solution.preorderTraversal(testTree());
    for (auto v : vec)
        cout << v << " ";
    cout << endl;
    vec = solution.preorderTraversal2(testTree());
    for (auto v : vec)
        cout << v << " ";
    cout << endl;
    return 0;
}
