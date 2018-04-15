#include "../libstruct.h"

using namespace std;

/*
 * NO.66
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 * The digits are stored such that the most significant digit is at the head of the list.
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i]++ < 9)
                return digits;
            else
                digits[i] = 0;
        }
        digits.insert(digits.begin(), 1); 
        return digits;
    }
};

//in: [9, 9, 9]
//out: [1, 0, 0, 0]
int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> vec = {9, 9, 9};
    vector<int> res =  solution.plusOne(vec);
    for (auto v : res) cout << v << " ";
    cout << endl;
    return 0;
}