#include "../libstruct.h"

using namespace std;

/*
 * NO.53
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', 
 * return the length of last word in the string.
 * If the last word does not exist, return 0. 
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0, n = s.length() - 1;
        while (n >= 0 && s[n] == ' ') n--;
        while (n >= 0 && s[n] != ' ') {
            count++;
            n--;
        }
        return count;
    }
};

//Input: "Hello World"
//Output: 5
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.lengthOfLastWord("hello world") << endl;
    return 0;
}