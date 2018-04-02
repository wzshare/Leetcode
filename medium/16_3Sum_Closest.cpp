#include "../libstruct.h"

using namespace std;

/*
 * NO.15
 * Given an array S of n integers, find three integers in S such that the sum is closest 
 * to a given number, target. Return the sum of the three integers. You may assume that 
 * each input would have exactly one solution.
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int a, b, c, sum, result;
        int n = nums.size();
        result = nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < n; i++)
        {
            a = i;
            b = i + 1;
            c = n - 1;
            while(b < c)
            {
                sum = nums[a] + nums[b] + nums[c];
                if(sum == target)
                    return target;
                if(abs(target - sum) < abs(target - result))
                    result = sum;
                sum > target ? c-- : b++;
            }
        }
        return result;
    }
};

/*
 * input: S = {-1 2 1 -4}, target = 1,
 * output: 2
 */ 
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> vec = {-1, 2, 1, -4};
    cout << solution.threeSumClosest(vec, 2) << endl;;
    return 0;
}