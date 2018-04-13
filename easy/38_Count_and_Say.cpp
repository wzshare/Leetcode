#include "../libstruct.h"

using namespace std;

/*
 * NO.38
 */

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string str = countAndSay(n - 1);
        int i = 0;
        string result = "";
        while (i < str.length()) {
            char c = str[i++];
            int count = 1;
            while (i < str.length() && str[i] == str[i - 1])
            {
                count ++;
                i ++;
            }
            result += ('0' + count);
            result += c;
        }
        return result;
    }
};

// in: 6
// out: 312211
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.countAndSay(6) << endl;
    return 0;
}