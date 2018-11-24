#include "../libstruct.h"

using namespace std;

/*
 * NO.137
 * Given a non-empty array of integers, every element appears three times except for one,
 * which appears exactly once. Find that single one.
 */

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        int one = 1;
        for (int i = 0; i < 64; i++) {
            int temp = 0;
            for (auto num : nums) {
                if (one & num) {
                    temp ++;
                }
            }
            if (temp % 3 == 1) {
                res = res | one;
            }
            one = one << 1;
        }
        return res;
    }
};
