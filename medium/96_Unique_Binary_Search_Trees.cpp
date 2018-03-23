#include "../libstruct.h"

using namespace std;

/*
 * Given n, how many structurally unique BST's (binary 
 * search trees) that store values 1...n?
 * 
 * G(n) = Sum( G(i-1) * G(n-i) ), i = 1..n
 * This is 'Catalan Number'.
 */

class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= i; j ++) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.numTrees(3) << endl;
    return 0;
}