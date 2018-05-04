#include "../libstruct.h"

using namespace std;

/*
 * NO.90
 * Given a collection of integers that might contain duplicates, nums, 
 * return all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * Input: [1,2,2]
 * Output:
 * [
 *   [2],
 *   [1],
 *   [1,2,2],
 *   [2,2],
 *   [1,2],
 *   []
 * ]
 */

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> > result(1, vector<int>());
        vector<vector<int> > temp;
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int> > pre = temp;
            temp.clear();
            if (i == 0 || nums[i] != nums[i - 1]) pre = result;
            for (auto t : pre) {
                t.push_back(nums[i]);
                result.push_back(t);
                temp.push_back(t);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> nums = {1, 2, 2};
    solution.subsetsWithDup(nums);
    return 0;
}