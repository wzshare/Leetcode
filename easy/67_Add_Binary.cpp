#include "../libstruct.h"

using namespace std;

/*
 * No.67
 * Given two binary strings, return their sum (also a binary string).
 * For example,
 * a = "11", b = "1", Return "100".
 */

class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int c = 0;
        while (i >= 0 || j >= 0 || c == 1)
        {
            c += i >= 0 ? a[i--] - '0' : 0;
            c += j >= 0 ? b[j--] = '0' : 0;
            s = char(c % 2 + '0') + s;
            c /= 2;
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.addBinary("11", "1") << endl;
    return 0;
}

