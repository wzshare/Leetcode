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

    //DP solution
    //dp[0] = ""
    //dp[i]='('+ dp[k]+')'+dp[i-1-k],k=0..i-i
    vector<string> generateParenthesis1(int n) {
        vector< vector<string> > dp(n+1, vector<string>());
        dp[0].push_back("");
        for(int i=1; i<=n; ++i){
            for(int k=0; k<i; ++k){
                for(string s1: dp[k]){
                    for(string s2: dp[i-1-k])
                        dp[i].push_back("("+s1+")"+s2);
                }
            }
        }
        return dp[n];
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
    vec = solution.generateParenthesis1(3);
    for (auto v : vec) cout << v << " ";
    cout << endl;
    return 0;
}