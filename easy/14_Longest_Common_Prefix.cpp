#include "../libstruct.h"

using namespace std;

/*
 * NO.14
 * Write a function to find the longest common prefix string amongst an array of strings.
 */ 

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string com = "";
        if(strs.empty())
            return com;
        for(int i = 0; i < strs[0].size(); ++ i)
        {
            char c = strs[0][i];
            for(int j = 0; j < strs.size(); j ++)
            {
                if(strs[j][i] != c)
                    return com;
            }
            com += c;
        }
        return com;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}