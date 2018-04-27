#include "../libstruct.h"

using namespace std;

/*
 * NO.73
 * Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r0 = 1, c0 = 1;
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0) {
                    if (i == 0) r0 = 0;
                    if (j == 0) c0 = 0;
                    matrix[0][j] = matrix[i][0] = 0;
                }
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (!matrix[0][j] || !matrix[i][0])
                    matrix[i][j] = 0;
        if (r0 == 0) for (int j = 0; j < n; j++) matrix[0][j] = 0;
        if (c0 == 0) for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}