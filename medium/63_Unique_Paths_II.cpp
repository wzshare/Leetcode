#include "../libstruct.h"

using namespace std;

/* NO.62
 * A robot is located at the top-left corner of a m x n grid 

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