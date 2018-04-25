#include "../libstruct.h"

using namespace std;

/* 
 * NO.64
 * Given a m x n grid filled with non-negative numbers, find a path from top left 
 * to bottom right which minimizes the sum of all numbers along its path.
 * Note: You can only move either down or right at any point in time.
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                int up = i ? grid[i - 1][j] : 0;
                int left = j ? grid[i][j - 1] : 0;
                if (i && j) grid[i][j] += min(left, up);
                else  grid[i][j] += (left + up);
            }
        }
        return grid.back().back();
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int> > grid;
    vector<int> g1 = {0,2,2,6,4,1,6,2,9,9,5,8,4,4};
    vector<int> g2 = {0,3,6,4,5,5,9,7,8,3,9,9,5,4};
    vector<int> g3 = {6,9,0,7,2,2,5,6,3,1,0,4,2,5};
    grid.push_back(g1);
    grid.push_back(g2);
    grid.push_back(g3);
    Solution solution;
    cout << solution.minPathSum(grid) << endl; //46
    return 0;
}