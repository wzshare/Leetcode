#include "../libstruct.h"

using namespace std;

/*
 * NO.5
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows. 
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */ 

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows <= 1) return s;
        string res;
        vector<string> vec(numRows);
        int row = 0, step = 1;
        for (int i = 0; i < s.length(); i++) {
            vec[row] += s[i];
            if (row == 0)
                step = 1;
            else if (row == numRows - 1)
                step = -1;
            row += step;
        }
        for (int i = 0; i < numRows; i++) {
            res += vec[i];
        }
        return res;
    }
};

/*
 * Input: ("PAYPALISHIRING", 3)
 * Output: "PAHNAPLSIIGYIR"
 */ 
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.convert("PAYPALISHIRING", 3) << endl;
    return 0;
}