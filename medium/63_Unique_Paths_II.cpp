#include "../libstruct.h"

using namespace std;

/* 
 * NO.63
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        for (int i = 0; i < obstacleGrid.size(); i++) {
            for (int j = 0; j < obstacleGrid[0].size(); j++) {
                int left = j ? obstacleGrid[i][j - 1] : 0;
                int up = i ? obstacleGrid[i - 1][j] : 0;
                if (i | j)
                    obstacleGrid[i][j] = obstacleGrid[i][j] ? 0 : left + up;
                else
                    obstacleGrid[i][j] = !obstacleGrid[i][j];
            }
        }
        return obstacleGrid.back().back();
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}