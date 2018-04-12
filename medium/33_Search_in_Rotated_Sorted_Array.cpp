#include "../libstruct.h"

using namespace std;

/*
 * NO.33
 * Suppose an array sorted in ascending order is rotated at some pivot unknown 
 * to you beforehand.
 * You are given a target value to search. If found in the array return its index, 
 * otherwise return -1.
 * You may assume no duplicate exists in the array.
 */ 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) return -1;
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            int m = (i + j) / 2;
            if (target == nums[m]) return m;
            if (nums[i] <= nums[m]) {
                if (nums[i] <= target && target < nums[m]) j = m - 1;
                else i = m + 1;
            } else {
                if (nums[m] < target && target <= nums[j]) i = m + 1;
                else j = m - 1;
            }
        }
        return target == nums[i] ? i : -1;
    }
};

// in: [5, 1, 3], 5
// out: 0
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {5, 1, 3};
    int n = solution.search(nums, 5);
    cout << n << endl;
    return 0;
}