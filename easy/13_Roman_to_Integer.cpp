#include "../libstruct.h"
#include <unordered_map>

using namespace std;

/*
 * NO.13
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 */

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> R = {{'I', 1},
                                    {'V', 5},
                                    {'X', 10},
                                    {'L', 50},
                                    {'C', 100},
                                    {'D', 500},
                                    {'M', 1000}};
        int sum = 0, i = 0;
		for(; i < s.size() - 1; i ++)
        {
            if (R[s[i]] < R[s[i+1]]) sum -= R[s[i]];
            else sum += R[s[i]];
        }
        sum += R[s[i]];
        return sum;
    }

};

/*
 * input: MMXVIII
 * output: 2018
 */ 
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.romanToInt("MMXVIII") << endl;
    return 0;
}