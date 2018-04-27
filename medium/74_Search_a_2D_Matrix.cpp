#include "../libstruct.h"

using namespace std;

/* 
 * 
 * Write an efficient algorithm that searches for a value in an m x n matrix. 
 * This matrix has the following properties:
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the previous row.
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (!matrix.size() || !matrix[0].size()) return false;
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, h = m * n - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (target == matrix[mid / n][mid % n]) return true;
            else if (target > matrix[mid / n][mid % n]) l = mid + 1;
            else h = mid - 1;
        }
        return false;
    }   
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}