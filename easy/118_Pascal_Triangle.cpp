#include <iostream>
#include "../libstruct.h"

using namespace std;

/*
 * No.118
 * Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 */
 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > result;
        int n = 1;
        while (numRows >= n) {
            vector<int> temp(1, 1);
            while (temp.size() < n) {
                vector<int> pre = result[result.size() - 1];
                int m = temp.size();
                if (m == n - 1) temp.push_back(1);
                else temp.push_back(pre[m - 1] + pre[m]);
            }
            result.push_back(temp);
            n++;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}
