#include "../libstruct.h"

using namespace std;

/*
 * No.89
 * The gray code is a binary numeral system where two successive values differ 
 * in only one bit.
 * Given a non-negative integer n representing the total number of bits in the 
 * code, print the sequence of gray code. A gray code sequence must begin with 0.
 * For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
 * 
 * 00 - 0
 * 01 - 1
 * 11 - 3
 * 10 - 2
 */
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1, 0);
        int index = 1;
        while(n--) {
            for (int i = result.size() - 1; i >= 0; i--) {
                result.push_back(result[i] | index);
            }
            index <<= 1;
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    vector<int> res = solution.grayCode(4);
    for (auto v : res) cout << v << " ";
    return 0;
}