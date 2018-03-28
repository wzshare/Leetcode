#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        if (root->left) {
            if (root->right) {
                root->left->next = root->right;
            }
            else {
                root->left->next = nextNode(root->next);
            }
        }
        if (root->right) {
            root->right->next = nextNode(root->next);
        }
        connect(root->left);
        connect(root->right);
    }
    TreeLinkNode* nextNode(TreeLinkNode* root) {
        if (!root) return NULL;
        if (root->left) return root->left;
        if (root->right) return root->right;
        return nextNode(root->next);
    }
};

/*
 * {2,1,3,0,7,9,1,2,#,1,0,#,#,8,8,#,#,#,#,7}
 * return [1,#,2,3,#]
 */ 
TreeLinkNode* testTree()
{
    TreeLinkNode* root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    return root;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    solution.connect(testTree());
    return 0;
}