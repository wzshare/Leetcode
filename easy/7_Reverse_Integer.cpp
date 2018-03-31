#include "../libstruct.h"

using namespace std;

/*
 * NO.7
 * Given a 32-bit signed integer, reverse digits of an integer.
 */

class Solution {
public:
    int reverse(int x) {
        int sign = x > 0 ? 1 : -1;
        x = abs(x);
         
        int ret = 0;
        while(x)
        {
            int digit = x % 10;
            ret = ret * 10 + digit;
            x /= 10;
        }
         
        return ret * sign;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.reverse(123) << endl;
    return 0;
}