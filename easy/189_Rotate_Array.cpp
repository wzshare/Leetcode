#include "../libstruct.h"

using namespace std;

/*
 * No.189
 * Given an array, rotate the array to the right by k steps, where k is non-negative.
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty())
            return ;
        k %= nums.size();
        while(k)
        {
            int n = nums[nums.size() - 1];
            nums.pop_back();
            nums.insert(nums.begin(), n);
            k --;
        }
    }
};