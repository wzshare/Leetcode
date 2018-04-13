#include "../libstruct.h"

using namespace std;

/*
 * NO.36
 * Determine if a Sudoku is valid.
 * A valid Sudoku board (partially filled) is not necessarily solvable. 
 * Only the filled cells need to be validated.
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> cols(9, 0);
        vector<int> rows(9, 0);
        vector<int> grid(9, 0);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int idx = 1 << (board[i][j] - '0');
                    if (rows[i] & idx || cols[j] & idx || grid[i / 3 * 3 + j / 3] & idx)
                        return false;
                    rows[i] |= idx;
                    cols[j] |= idx;
                    grid[i / 3 * 3 + j / 3] |= idx;
                }
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}