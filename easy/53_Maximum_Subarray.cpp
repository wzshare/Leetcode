#include "../libstruct.h"

using namespace std;

/*
 * NO.53
 * Find the contiguous subarray within an array (containing at 
 * least one number) which has the largest sum.
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0], sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            ans = max(sum, ans);
            sum = max(sum, 0);
        }
        return ans;
    }
};

//in: [-2,1,-3,4,-1,2,1,-5,4],
//out: sum = 6 ([4,-1,2,1])
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> vec = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << solution.maxSubArray(vec) << endl;
    return 0;
}