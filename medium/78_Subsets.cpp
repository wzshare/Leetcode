#include "../libstruct.h"

using namespace std;

/* 
 * NO.78
 * Given a set of distinct integers, nums, return all possible subsets (the power set).
 * Note: The solution set must not contain duplicate subsets.
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > result(1, vector<int>());
        for (int i = 0; i < nums.size(); i++) {
            int n = result.size();
            for (int j = 0; j < n; j++) {
                vector<int> t = result[j];
                t.push_back(nums[i]);
                result.push_back(t);
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}