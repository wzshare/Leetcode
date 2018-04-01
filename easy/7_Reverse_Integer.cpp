#include "../libstruct.h"

using namespace std;

/*
 * NO.7
 * Given a 32-bit signed integer, reverse digits of an integer.
 */

class Solution {
public:
    int reverse(int x) {    
        int ret = 0;
        while(x)
        {
            int temp = ret * 10 + x % 10;
            if (temp / 10 != ret)
                return 0;
            ret = temp;
            x /= 10;
        }
         
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.reverse(123) << endl;
    return 0;
}