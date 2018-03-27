#include "../libstruct.h"

using namespace std;

/*
 * NO.108
 * Given an array where elements are sorted in ascending order, 
 * convert it to a height balanced BST.
 */ 
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if(start > end)
            return NULL;
        int mid = (start + end + 1) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = helper(nums, start, mid - 1);
        root->right = helper(nums, mid + 1, end);
        return root;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}