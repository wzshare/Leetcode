#include "../libstruct.h"

using namespace std;

/*
 * NO.91
 * A message containing letters from A-Z is being encoded to numbers using the following mapping:
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * Given a non-empty string containing only digits, determine the total number of ways to decode it.
 */

class Solution {
public:
    int numDecodings(string s) {
        vector<int> res(s.size() + 1, 1);
        if (s.empty()) return 0;
        res[1] = s[0] == '0' ? 0 : 1;
        for (int i = 1; i < s.size(); i++) {
            res[i+1] = s[i] == '0' ? 0 : res[i];
            res[i+1] += (s[i-1] == '1' || (s[i-1] == '2' && s[i] < '7')) ? res[i-1] : 0;
        }
        return res[s.size()];
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.numDecodings("226") << endl;//3
    return 0;
}