#include "../libstruct.h"

using namespace std;

/*
 * NO.18
 * Given an array S of n integers, are there elements a, b, c, and d in S such 
 * that a + b + c + d = target? 
 * Find all unique quadruplets in the array which gives the sum of target.
 */ 

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int> > result;
        if (nums.size() < 4) return result;
        sort(nums.begin(), nums.end());
        for (int a = 0; a < nums.size() - 3; a++) {
            if (a > 0 && nums[a] == nums[a-1]) continue;
            for (int b = a + 1; b < nums.size() - 2; b++) {
                if (b > a + 1 && nums[b] == nums[b-1]) continue;
                int t = target - nums[a] - nums[b];
                int c = b + 1, d = nums.size() - 1;
                while (c < d) {
                    while (nums[c] + nums[d] < t && c < d) c++;
                    while (nums[c] + nums[d] > t && c < d) d--;
                    if (nums[c] + nums[d] == t && c < d) {
                        vector<int> temp = {nums[a], nums[b], nums[c], nums[d]};
                        result.push_back(temp);
                        while(nums[c] == nums[++c]);
                        while(nums[d] == nums[--d]);
                    }
                }
            }
        }
        return result;
    }
};

/*
 * input: S = [1, 0, -1, 0, -2, 2], target = 0,
 * output:
 * [
 *  [-1,  0, 0, 1],
 *  [-2, -1, 1, 2],
 *  [-2,  0, 0, 2]
 * ]
 */ 
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> vec = {1, 0, -1, 0, -2, 2};
    solution.fourSum(vec, 0);
    return 0;
}