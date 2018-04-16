#include <iostream>

using namespace std;

/*
 * NO.70
 * You are climbing a stair case. It takes n steps to reach to the top.
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

/*
 * fibonacci sequence:
 * f(n) = f(n-1) + f(n-2)
 */
class Solution {
public:
    int climbStairs(int n) {
        int a = 1, b = 1;
        while (n-- > 1) {
            a = a + b;
            b = a - b;
        }
        return a;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.climbStairs(15) << endl;
    return 0;
}