#include "../libstruct.h"

using namespace std;

/*
 * NO.224
 * Implement a basic calculator to evaluate a simple expression string.
 * 
 * The expression string may contain open ( and closing parentheses ), 
 * the plus + or minus sign -, non-negative integers and empty spaces .
 */

class Solution {
public:
    int calculate(string s) {
        vector<string> postorder;
        stack<char> ss;
        stack<int> cal;
        s = '(' + s + ')';
        string temp = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                temp += s[i];
            }
            else if (temp != "") {
                postorder.push_back(temp);
                temp = "";
            }
            
            if (s[i] == '(') {
                ss.push(s[i]);
            }
            else if (s[i] == ')') {
                while(ss.top() != '(') {
                    string t(1, ss.top());
                    ss.pop();
                    postorder.push_back(t);
                }
                ss.pop();
            }
            else if (s[i] == '+' || s[i] == '-') {
                while(ss.top() != '(') {
                    string t(1, ss.top());
                    ss.pop();
                    postorder.push_back(t);
                }
                ss.push(s[i]);
            }
        }
        
        for (int i = 0; i < postorder.size(); i++) {
            if (postorder[i] == "+") {
                int a = cal.top();
                cal.pop();
                cal.top() += a;
            }
            else if (postorder[i] == "-") {
                int a = cal.top();
                cal.pop();
                cal.top() -= a;
            }
            else {
                cal.push(stoi(postorder[i]));
            }
        }
        return cal.top();
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}