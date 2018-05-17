#include "../libstruct.h"

using namespace std;

/*
 * NO.242
 * Given two strings s and t , write a function to determine if t is an anagram of s.
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> path(26, 0);
        if (s.length() != t.length()) return false;
        for (auto c : s) path[c - '0'] += 1;
        for (auto c : t) {
            if (--path[c - '0'] < 0)
                return false;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}