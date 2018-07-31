#include "../libstruct.h"

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st, star;
        for (char c : s) {
            if (c == '(') {
                if (st.empty()) {
                    while (!star.empty()) star.pop();
                }
                st.push(c);
            }
            else if (c == '*') {
                star.push(c);
            }
            else if (st.empty()) {
                if (star.empty()) return false;
                else star.pop();
            } else {
                st.pop();
            }
        }
        return st.size() <= star.size();
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.checkValidString("(())(())(((()*()()()))()((()()(*()())))(((*)()") << endl;
    return 0;
}