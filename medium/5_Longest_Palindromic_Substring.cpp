#include "../libstruct.h"

using namespace std;

/*
 * NO.5
 * Given a string s, find the longest palindromic substring in s. You may assume that 
 * the maximum length of s is 1000.
 */ 
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        for (int start = 0; start < len && len - start > max_len / 2;) 
        {
            left = right = start;
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) 
            {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) 
            {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }
};

/*
 * Input: "babad"
 * Output: "bab"
 */ 
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.longestPalindrome("babad") << endl;
    return 0;
}