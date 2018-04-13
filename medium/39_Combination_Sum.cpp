#include "../libstruct.h"

using namespace std;

/*
 * NO.39
 * Given a set of candidate numbers (C) (without duplicates) and a target number (T), 
 * find all unique combinations in C where the candidate numbers sums to T.
 * The same repeated number may be chosen from C unlimited number of times.
 * Note:
 * All numbers (including target) will be positive integers.
 * The solution set must not contain duplicate combinations.
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> com;
        helper(candidates, target, res, com, 0);
        return res;
    }
    void helper(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        }
        for (int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
            combination.push_back(candidates[i]);
            helper(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};

// in: [2, 3, 6, 7] and 7, 
// out: [2, 2, 3], [7]
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> candidates = {2, 3, 6, 7};
    solution.combinationSum(candidates, 7);
    return 0;
}