#include "../libstruct.h"

using namespace std;

/*
 * NO.40
 * Given a collection of candidate numbers (candidates) and a target number (target), 
 * find all unique combinations in candidates where the candidate numbers sums to target.
 * Each number in candidates may only be used once in the combination.
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> comb;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, result, comb, 0);
        return result;
    }
    
    void helper(vector<int>& candidates, int target, vector<vector<int> >& result, vector<int>combination, int start) {
        if (target == 0) {
            result.push_back(combination);
        }
        for (int i = start; i < candidates.size() && candidates[i] <= target; i++) {
            if (i && candidates[i] == candidates[i-1] && i > start) continue;
            combination.push_back(candidates[i]);
            helper(candidates, target - candidates[i], result, combination, i + 1);
            combination.pop_back();
        }
    }
};

// in: [10,1,2,7,6,1,5] and 8, 
// out: [1,1,6],[1,2,5],[1,7],[2,6]
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> candidates = {10,1,2,7,6,1,5};
    solution.combinationSum2(candidates, 8);
    return 0;
}