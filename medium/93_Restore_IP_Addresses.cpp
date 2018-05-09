#include "../libstruct.h"

using namespace std;

/*
 * NO.90
 * Given a string containing only digits, restore it by returning all possible 
 * valid IP address combinations.
 * 
 * Example:
 * Input: "25525511135"
 * Output: ["255.255.11.135", "255.255.111.35"]
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        helper(res, "", s, 4);
        return res;
    }
    
    void helper(vector<string>& res, string cur, string s, int count) {
        if (s.size() > 3 * count) return;
        if (count == 0) {
            if (s == "") res.push_back(cur.substr(1));
            return;
        }
        if (s.size() >= 3 && s[0] != '0') {
            if (stoi(s.substr(0, 3)) <= 255)
                helper(res, cur + "." + s.substr(0, 3), s.substr(3), count - 1);
        }
        if (s.size() >= 2 && s[0] != '0')
            helper(res, cur + "." + s.substr(0, 2), s.substr(2), count - 1);
        if (s.size() >= 1)
            helper(res, cur + "." + s.substr(0, 1), s.substr(1), count - 1);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}