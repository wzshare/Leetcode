#include "../libstruct.h"

using namespace std;

/* 
 * NO.77
 * Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
 */

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> t(k, 0);
        int i = 0;
        while (i >= 0) {
            t[i]++;
            if (t[i] > n) i--;
            else if (i == k - 1) result.push_back(t);
            else t[++i] = t[i - 1];
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}