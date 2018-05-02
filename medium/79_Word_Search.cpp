#include "../libstruct.h"

using namespace std;

/* 
 * NO.79
 * Given a 2D board and a word, find if the word exists in the grid.
 * The word can be constructed from letters of sequentially adjacent cell, where 
 * "adjacent" cells are those horizontally or vertically neighboring. The same 
 * letter cell may not be used more than once.
 */

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (helper(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool helper(vector<vector<char> >& board, string word, int row, int col, int index) {
        if (board[row][col] != word[index]) return false;
        if (index == word.size() - 1) return true;
        char temp = board[row][col];
        board[row][col] = '#';
        bool res = false;
        if (row > 0) res = helper(board, word, row - 1, col, index + 1);
        if (!res && row < m - 1) res = helper(board, word, row + 1, col, index + 1);
        if (!res && col > 0) res = helper(board, word, row, col - 1, index + 1);
        if (!res && col < n - 1) res = helper(board, word, row, col + 1, index + 1);
        board[row][col] = temp;
        return res;
    }
private:
    int m, n;
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}