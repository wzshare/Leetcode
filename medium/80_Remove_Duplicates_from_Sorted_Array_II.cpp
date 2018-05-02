#include "../libstruct.h"

using namespace std;

/*
 * NO.80
 * Given a sorted array nums, remove the duplicates in-place such 
 * that duplicates appeared at most twice and return the new length.
 * Do not allocate extra space for another array, you must do this 
 * by modifying the input array in-place with O(1) extra memory.
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int a = 0, b = 0;
        while (b < nums.size()) {
            if (a < 2 || nums[b] > nums[a - 2])
                nums[a++] = nums[b];
            b++;
        }
        return a;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> vec = {1, 1, 2, 2, 2, 3, 3, 3, 3};
    int n = solution.removeDuplicates(vec);
    for (int i = 0; i < n; i++) cout << vec[i] << " ";
    cout << endl;
    return 0;
}