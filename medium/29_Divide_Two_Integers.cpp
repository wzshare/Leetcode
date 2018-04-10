#include "../libstruct.h"

using namespace std;

/*
 * NO.29
 * Divide two integers without using multiplication, division and mod operator.
 * If it is overflow, return MAX_INT.
 */

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 1)
            return dividend;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int result = 0;
        int sign = (dividend > 0 ^ divisor > 0) ? -1 : 1;
        long end = abs((long)dividend);
        long sor = abs((long)divisor);
        
        while(end >= sor)
        {
            long temp = sor;
            int power = 1;
            while((temp << 1) < end)
            {
                temp <<= 1;
                power <<= 1;
            }
            result += power;
            end -= temp;
        }
        return result * sign;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    int n = solution.divide(24, 8);
    cout << n << endl;
    return 0;
}