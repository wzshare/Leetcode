#include "../libstruct.h"

using namespace std;

/*
 * NO.34
 * Given an array of integers sorted in ascending order, find the starting 
 * and ending position of a given target value.
 * Your algorithm's runtime complexity must be in the order of O(log n).
 * If the target is not found in the array, return [-1, -1].
 */

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i = -1, j = -1, l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (target < nums[m]) r = m - 1;
            else if (target > nums[m]) l = m + 1;
            else {
                i = j = m;
                while (l < i) {
                    int m1 = (l + i) / 2;
                    if (nums[m1] == target) i = m1;
                    else l = m1 + 1;
                }
                while (j < r) {
                    int m2 = (j + r + 1) / 2;
                    if (nums[m2] == target) j = m2;
                    else r = m2 - 1;
                }
                break;
            }
        }
        vector<int> vec = {i, j};
        return vec;
    }
};

// in: [5, 7, 7, 8, 8, 10] , 8
// out: [3, 4]
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> n = solution.searchRange(nums, 8);
    cout << n[0] << " " << n[1] << endl;
    return 0;
}