#include "../libstruct.h"

using namespace std;

/*
 * NO.3
 * Given a string, find the length of the longest substring without repeating 
 * characters.
 */ 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		vector<int> charIndex(256, -1);
		int longest = 0, m = 0;

		for (int i = 0; i < s.length(); i++) {
			m = max(charIndex[s[i]] + 1, m);
			charIndex[s[i]] = i;
			longest = max(longest, i - m + 1);
		}

		return longest;
	}
};

/*
 * Given "pwwkew", the answer is "wke", with the length of 3.
 */ 
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}