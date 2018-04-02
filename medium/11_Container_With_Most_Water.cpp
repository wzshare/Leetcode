#include "../libstruct.h"

using namespace std;

/*
 * NO.11
 * Given n non-negative integers a1, a2, ..., an, where each represents a 
 * point at coordinate (i, ai). n vertical lines are drawn such that the 
 * two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which 
 * together with x-axis forms a container, such that the container contains 
 * the most water.
 * Note: You may not slant the container and n is at least 2.
 */

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, i = 0, j = height.size() - 1; 
        while(i < j) {
            int h = min(height[i], height[j]);
            area = max(area, h * (j - i));
            while(height[i] <= h && i < j) i++;
            while(height[j] <= h && i < j) j--;
        }
        return area;
    }
};

/*
 * input: {4, 5, 2, 1, 7, 2, 1}
 * output: true
 */
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> vec = {4, 5, 2, 1, 7, 2, 1};
    cout << solution.maxArea(vec) << endl;
    return 0;
}