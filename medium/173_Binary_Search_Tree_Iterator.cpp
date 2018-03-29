#include "../libstruct.h"

using namespace std;

/*
 * NO.173
 * Implement an iterator over a binary search tree (BST). Your iterator will 
 * be initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, 
 * where h is the height of the tree.
 */

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        pushLeft(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !st.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *temp = st.top();
        st.pop();
        pushLeft(temp->right);
        return temp->val;
    }
private:
    stack<TreeNode*> st;
    void pushLeft(TreeNode *root) {
        for (; root; root = root->left)
            st.push(root);
    }
};

TreeNode* testTree()
{
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    return root;
}

int main(int argc, char const *argv[])
{
    BSTIterator i = BSTIterator(testTree());
    while (i.hasNext()) cout << i.next();
    return 0;
}