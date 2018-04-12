#include "../libstruct.h"

using namespace std;

/*
 * NO.35
 * Given a sorted array and a target value, return the index if the target is found. 
 * If not, return the index where it would be if it were inserted in order.
 * You may assume no duplicates in the array.
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        if (r < 0) return 0;
        while (l < r) {
            int m = (l + r) / 2;
            if (nums[m] == target) return m;
            if (nums[m] < target) l = m + 1;
            else r = m - 1;
        }
        return target <= nums[l] ? l : l + 1;
    }
};

// in: [1,3,5,6], 5
// out: 2
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 3, 5, 6};
    int n = solution.searchInsert(nums, 5);
    cout << n << endl;
    return 0;
}