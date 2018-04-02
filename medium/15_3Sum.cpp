#include "../libstruct.h"

using namespace std;

/*
 * NO.15
 * Given an array S of n integers, are there elements a, b, c in S such 
 * that a + b + c = 0? Find all unique triplets in the array which gives 
 * the sum of zero.
 * Note: The solution set must not contain duplicate triplets.
 */

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > result;
        int a, b, c;
        sort(nums.begin(), nums.end());
        if (!nums.size() || nums[nums.size()-1] < 0)
            return result;
        for (int i = 0; i < nums.size() && nums[i] <= 0;)
        {
            a = -nums[i];
            b = i + 1;
            c = nums.size() - 1;
            while (b < c)
            {
                int sum = nums[b] + nums[c];
                if(sum < a) b++;
                else if(sum > a) c--;
                else{
                    vector<int> temp = {-a, nums[b], nums[c]};
                    result.push_back(temp);
                    
                    while(b < c && nums[b] == temp[1]) b++;
                    while(b < c && nums[c] == temp[2]) c--;
                }
            }
            while(i < nums.size() && nums[i] == -a) i++;
        }
        return result;
    }
};

/*
 * input: S = [-1, 0, 1, 2, -1, -4],
 * output:
 * [
 *  [-1, 0, 1],
 *  [-1, -1, 2]
 * ]
 */ 
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> vec = {-1, 0, 1, 2, -1, -4};
    solution.threeSum(vec);
    return 0;
}