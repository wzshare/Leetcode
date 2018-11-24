#include "../libstruct.h"

using namespace std;

/*
 * NO.260
 * Given an array of numbers nums, in which exactly two elements appear only once 
 * and all the other elements appear exactly twice. Find the two elements that appear only once.
 * Example:
 * Input:  [1,2,1,3,2,5]
 * Output: [3,5]
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        int one = 1;
        for (auto num : nums) {
            temp ^= num;
        }
        while ((temp & one) == 0) {
            one <<= 1;
        }
        vector<int> first , second;
        int f = 0, s = 0;
        for (auto num : nums) {
            if (num & one) {
                first.push_back(num);
            } else {
                second.push_back(num);
            }
        }
        for (auto num : first) {
            f ^= num;
        }
        for (auto num : second) {
            s ^= num;
        }
        return {f, s};
    }
};
