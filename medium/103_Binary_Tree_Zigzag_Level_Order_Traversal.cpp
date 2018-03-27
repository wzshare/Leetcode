#include "../libstruct.h"

using namespace std;

/*
 * Given a binary tree, return the zigzag level order traversal of its nodes' 
 * values. (ie, from left to right, then right to left for the next level and 
 * alternate between).
 */

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > levelorder;
        if(root == NULL) return levelorder;
        stack<TreeNode*> s1, s2, *s;
        s1.push(root);
        int sum = 1;
        int flag = 1;
        while(!s1.empty() || !s2.empty())
        {
            vector<int> level, level2;
            s = s1.empty() ? &s2 : &s1;
            while(sum--)
            {
                TreeNode* temp = s->top();
                s->pop();
                level.push_back(temp->val);
                if(flag == 1)
                {
                    if(temp->left) s2.push(temp->left);
                    if(temp->right) s2.push(temp->right);
                }
                else
                {
                    if(temp->right) s1.push(temp->right);
                    if(temp->left) s1.push(temp->left);
                }
            }
            flag *= -1;
            sum = s1.size() + s2.size();
            levelorder.push_back(level);
        }
        return levelorder;
    }
};

/* 
 * [3,9,20,null,null,15,7]
 * return
 *  [
 *    [3],
 *    [20,9],
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

int main(int argc, char const *argcv[])
{
    Solution solution;
    vector<vector<int> > valList = solution.zigzagLevelOrder(testTree());
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