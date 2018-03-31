#include "../libstruct.h"
#include <unordered_map>

using namespace std;

/*
 * NO.1
 * Given an array of integers, return indices of the two numbers 
 * such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, 
 * and you may not use the same element twice.
 */ 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashSum;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(hashSum.count(target - nums[i]))
            {
                result.push_back(hashSum[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            else
                hashSum.insert(make_pair(nums[i], i));
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> vec = {2, 7, 11, 15};
    vector<int> res = solution.twoSum(vec, 9);
    cout << res[0] << " " << res[1] << endl;
    return 0;
}