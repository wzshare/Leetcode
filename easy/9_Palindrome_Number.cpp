#include "../libstruct.h"

using namespace std;

/*
 * NO.9
 * Determine whether an integer is a palindrome. Do this without extra space.
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x > 0 && x % 10 == 0)) return false;
        int sum = 0;
        while (x > sum) {
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        return (x == sum) || (x == sum / 10);
    }
};

/*
 * input: 1234321
 * output: true
 * input: 10
 * output: false
 */ 
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.isPalindrome(1234321) << endl;
    cout << solution.isPalindrome(10) << endl;
    return 0;
}