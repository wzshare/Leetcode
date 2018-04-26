#include "../libstruct.h"

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        string result;
        stack<string> st;
        for(int i = 0; i < path.length(); i++) {
            string temp;
            while(i < path.length() && path[i] != '/') temp += path[i++];
            if (temp == "..") st.empty() ? void() : st.pop();
            else if (temp != "." && !temp.empty()) st.push(temp);
        }
        if (st.empty()) result = "/";
        while (!st.empty()) {
            result = "/" + st.top() + result;
            st.pop();
        }
        return result;
    }
};

// input: "/a/./b/../../c"
// out: "/c"
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.simplifyPath("/a/./b/../../c") << endl;
    return 0;
}