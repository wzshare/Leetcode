#include "../libstruct.h"

using namespace std;

/* 
 * NO.75
 * Given an array with n objects colored red, white or blue, 
 * sort them in-place so that objects of the same color are adjacent, 
 * with the colors in the order red, white and blue.
 * Here, we will use the integers 0, 1, and 2 to represent the color red, 
 * white, and blue respectively.
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, h = nums.size() - 1, m = 0;
        while (m <= h)
            if (nums[m] == 0) swap(nums[m++], nums[l++]);
            else if (nums[m] == 1) m++;
            else swap(nums[m], nums[h--]);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}