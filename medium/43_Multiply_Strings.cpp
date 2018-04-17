#include "../libstruct.h"

using namespace std;

/*
 * NO.43
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, 
 * also represented as a string.
 */

class Solution {
public:
    string multiply(string num1, string num2) {
        string sum(num1.length() + num2.length(), '0');
        for (int i = num2.length() - 1; i >= 0; i--) {
            int c = 0;
            for (int j = num1.length() - 1; j >= 0; j--) {
                int temp = (num2[i] - '0') * (num1[j] - '0') + c + (sum[i + j + 1] - '0');
                sum[i + j + 1] = (temp % 10) + '0';
                c = temp / 10;
            }
            sum[i] += c;
        }
        size_t startpos = sum.find_first_not_of("0");
        if (string::npos != startpos) {
            return sum.substr(startpos);
        }
        return "0";
    }
};

// in: num1 = "123", num2 = "456" 
// out: "56088"
int main(int argc, char const *argv[])
{
    Solution solution;
    string str = solution.multiply("123", "456");
    cout << str << endl;
    return 0;
}