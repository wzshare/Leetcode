#include "../libstruct.h"

using namespace std;

/*
 * NO.191
 * Write a function that takes an unsigned integer and returns the 
 * number of '1' bits it has.
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int flag = 1, res = 0;
        while (flag) {
            if (flag & n) res++;
            flag <<= 1;
        }
        return res;
    }
    int hammingWeight1(uint32_t n) {
        int res = 0;
        while (n) {
            res++;
            n = n & (n - 1);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}