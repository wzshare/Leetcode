#include <iostream>

using namespace std;

/*
 * No.367
 * Given a positive integer num, write a function which returns 
 * True if num is a perfect square else False.
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        long int a = num;
        while (a > 0) {
            if (a * a == num)
                return true;
            else if (a * a > num)
                a = (a + num / a) / 2;
            else
                return false;
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.isPerfectSquare(15) << endl;
    return 0;
}