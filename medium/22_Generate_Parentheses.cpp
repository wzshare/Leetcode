#include "../libstruct.h"

using namespace std;

/*
 * NO.22
 * Given n pairs of parentheses, write a function to generate all combinations 
 * of well-formed parentheses.
 */

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        if (0 == n) return vec;
        helper(vec, "", n, 0);
        return vec;
    }
    
    void helper(vector<string> &vec, string str, int l, int r) {
        if (l == 0 && r == 0) vec.push_back(str);
        if (l > 0) helper(vec, str + '(', l - 1, r + 1);
        if (r > 0) helper(vec, str + ')', l, r - 1);
    }
};
/*
given n = 3, a solution set is:

["((()))", "(()())", "(())()", "()(())", "()()()"]
*/
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<string> vec = solution.generateParenthesis(3);
    for (auto v : vec) cout << v << " ";
    cout << endl;
    return 0;
}