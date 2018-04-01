#include "../libstruct.h"

using namespace std;

/*
 * NO.8
 * Implement atoi to convert a string to an integer. 
 */ 

class Solution {
public:
    int myAtoi(string str) {
        int res = 0, flag = 1, start = 0;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == ' ')
                start++;
            else
                break;
        }
        for (int i = start; i < str.length(); i++) {
            int temp = res;
            if (i == start && (str[i] == '-' || str[i] == '+'))
                flag = str[i] == '+' ? 1 : -1;
            else if (str[i] > '9' || str[i] < '0') 
                return res;
            else 
                temp = temp * 10 + (str[i] - '0') * flag;
            if (temp / 10 == res)
                res = temp;
            else
                return flag == 1 ? INT_MAX : INT_MIN;
        }
        return res;
    }
};

/*
 * Input: "    -004500a12"
 * Output: -4500
 */ 
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.myAtoi("    -004500a12") << endl;
    return 0;
}