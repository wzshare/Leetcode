#include "../libstruct.h"

using namespace std;

/*
 * NO.27
 * Given an array and a value, remove all instances of that value in-place and 
 * return the new length.
 * Do not allocate extra space for another array, you must do this by modifying 
 * the input array in-place with O(1) extra memory.
 * The order of elements can be changed. It doesn't matter what you leave beyond 
 * the new length.
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int a = 0, b = a;
        while (b < nums.size()) {
            while (b < nums.size() && nums[b] == val) b++;
            if (b < nums.size()) nums[a++] = nums[b++];
        }
        return a;
    }
};

/*
 * input: [3,1,2,3]
 * output: [1,2]
 */
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> vec = {3, 1, 2, 3};
    int n = solution.removeElement(vec, 3);
    for (int i = 0; i < n; i++) cout << vec[i] << " ";
    cout << endl;
    return 0;
}