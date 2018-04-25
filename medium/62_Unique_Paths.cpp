#include "../libstruct.h"

using namespace std;

/* 
 * NO.62
 * A robot is located at the top-left corner of a m x n grid 
 * (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point 
 * in time. The robot is trying to reach the bottom-right corner 
 * of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 */

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> res(m, 1);
        for (int i = 1; i < n; i++) 
            for (int j = 1; j < m; j++) 
                res[j] = res[j] + res[j - 1];
        return res[m-1];
    }
};

// Input: m = 7, n = 3
// Output: 28
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.uniquePaths(7, 3) << endl;
    return 0;
}