#include <iostream>

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
        if(a == "")
            return b;
        if(b == "")
            return a;
        int astr = a.size();
        int bstr = b.size();
        int carry = 0;//记录进位
		int aint = 0, bint =0; //记录a、b的下标
        string result = astr > bstr ? a : b;
        int re = astr > bstr ? astr : bstr;
        do
        {           
            if(astr > 0)
                aint = a[astr - 1] - '0';
            else
                aint = 0;
            if(bstr > 0)
                bint = b[bstr - 1] - '0';
            else
                bint = 0;
			int sum = aint + bint + carry;
			if(re == 0)
                result.insert(0, "1"); //首位进位采用在起始插入
            else
                result[re - 1] = sum % 2 + '0';
            if(sum > 1)
                carry = 1;
            else
                carry = 0;
            astr --;
            bstr --;
            re --;
        }while(carry != 0 || astr > 0 || bstr > 0);//所有位计算完且没有进位才结束
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.addBinary("11", "1") << endl;
    return 0;
}

