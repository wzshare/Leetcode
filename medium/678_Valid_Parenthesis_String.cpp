#include "../libstruct.h"

using namespace std;

/*
 * NO.678
 * Given a string containing only three types of characters: '(', ')' and '*', write a function to 
 * check whether this string is valid. We define the validity of a string by these rules:
 * 
 * 1. Any left parenthesis '(' must have a corresponding right parenthesis ')'.
 * 2. Any right parenthesis ')' must have a corresponding left parenthesis '('.
 * 3. Left parenthesis '(' must go before the corresponding right parenthesis ')'.
 * 4. '*' could be treated as a single right parenthesis ')' or a single left parenthesis 
 *    '(' or an empty string.
 * 5. An empty string is also valid.
 */

class Solution {
public:
    bool checkValidString(string s) {
        int a = 0, b = 0;
        for (char c : s) {
            if (c == '(') {
                a++;
                b++;
            } else if (c == ')') {
                a--;
                b--;
            } else {
                a--;
                b++;
            }
            a = max(0, a);
            if (b < 0) return false;
        }
        return a == 0; 
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}