#include "../libstruct.h"

using namespace std;

/*
 * No.69
 * Implement int sqrt(int x)
 */

/*
 * Newton's Method
 * b = a * a, init: a = b, delta is a little number, e.x. 0.000001
 * while (a * a - b > delta) a = (a + b / a) / 2,
 * Prove: if a * a = (a + b / a ) / 2 * a = (a * a + b) / 2,
 * then, b = (a * a + b) / 2, b = a * a.
 */

class Solution {
public:
    int mySqrt(int x) {
        int sqr = x / 2 + 1;
        while (sqr > 0 && sqr > x / sqr)
            sqr = (sqr + x / sqr) / 2;
        return sqr;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.mySqrt(15) << endl;
    return 0;
}