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
        while (root) {
            TreeLinkNode *temp = new TreeLinkNode(0);
            TreeLinkNode *current = temp;
            while(root) {
                if (root->left) {
                    current->next = root->left;
                    current = current->next;
                }
                if (root->right) {
                    current->next = root->right;
                    current = current->next;
                }
                root = root->next;
            }
            root = temp->next;
        }
    }
};

/*
 * {1,2,3,4,#,#,5}
 * return [1,#,2,3,#]
 */ 
TreeLinkNode* testTree()
{
    TreeLinkNode* root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->right->right = new TreeLinkNode(5);
    return root;
}

int main(int argc, char const *argv[])
{
    Solution solution;
    TreeLinkNode *root = testTree();
    solution.connect(root);
    cout << "root: " << root->val << endl;
    return 0;
}