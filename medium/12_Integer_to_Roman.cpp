#include "../libstruct.h"

using namespace std;

/*
 * NO.11
 * Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

class Solution {
public:
    string intToRoman(int num) {
        string R[4][10] = {{"", "M", "MM", "MMM"},
                           {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                           {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                           {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}};
        return R[0][num / 1000] + R[1][(num % 1000) / 100] + R[2][(num % 100) / 10] + R[3][num % 10];
    }
};

/*
 * input: 2018
 * output: MMXVIII
 */ 
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.intToRoman(2018) << endl;
    return 0;
}