#include "../libstruct.h"

using namespace std;

/*
 * Given an input string, reverse the string word by word.
 *
 * Example:  
 *
 * Input: "the sky is blue",
 * Output: "blue is sky the".
 */

class Solution {
public:
    void reverseWords(string &s) {
        istringstream is(s);
        string tmp;
        is >> s;
        while(is >> tmp) s = tmp + " " + s;
        if(s[0] == ' ') s = "";
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    string res = " ";
    solution.reverseWords(res);
    return 0;
}