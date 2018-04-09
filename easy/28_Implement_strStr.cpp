#include "../libstruct.h"

using namespace std;

/*
 * NO.28
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack, or -1 if 
 * needle is not part of haystack.
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        for (int i = 0;;i++)
            for (int j = 0;;j++) {
                if (j == needle.length()) return i;
                if (i + j >= haystack.length()) return -1;
                if (haystack[i + j] != needle[j]) break;
            }
    }
};

/*
 * input: "hello", "ll"
 * output: 2
 */
int main(int argc, char const *argv[])
{
    Solution solution;
    int n = solution.strStr("hello", "ll");
    cout << n << endl;
    return 0;
}