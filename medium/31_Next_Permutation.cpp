#include "../libstruct.h"

using namespace std;

/*
 * NO.31
 * Implement next permutation, which rearranges numbers into the l
 * exicographically next greater permutation of numbers.
 */ 

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = nums.size() - 1, l = k;
        while (k - 1 >= 0 && nums[k] <= nums[k-1]) k--;
        if (k-- > 0) {
            while (nums[l] <= nums[k]) l--;
            swap(nums[k], nums[l]);
        }
        reverse(nums.begin() + k + 1, nums.end());
    }
};

// [1, 3, 2] -> [2, 1, 3]
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 3, 2};
    solution.nextPermutation(nums);
    return 0;
}