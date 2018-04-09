#include "../libstruct.h"

using namespace std;

/*
 * NO.26
 * Given a sorted array, remove the duplicates in-place such that each 
 * element appear only once and return the new length.
 * Do not allocate extra space for another array, you must do this by 
 * modifying the input array in-place with O(1) extra memory.
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int a = 0, b = a;
        while (b < nums.size()) {
            while (b < nums.size() && nums[a] == nums[b]) b++;
            if (++a < nums.size()) nums[a] = nums[b];
        }
        return a;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> vec = {1, 1, 2};
    int n = solution.removeDuplicates(vec);
    for (int i = 0; i < n; i++) cout << vec[i] << " ";
    cout << endl;
    return 0;
}