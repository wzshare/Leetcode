#include "../libstruct.h"

using namespace std;

/*
 * NO.17
 * Given a digit string, return all possible letter combinations that the number could represent.
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 * {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}
 */

class Solution {
public:
/*
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty())
            return result;
        string buttons[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        result.push_back("");
        for(int i = 0; i < digits.size(); ++i)
        {
            vector<string> temp;
            string ch = buttons[digits[i] - '0'];
            for(int j = 0; j < ch.size(); ++j)
                for(int k = 0; k < result.size(); ++k)
                    temp.push_back(result[k] + ch[j]);
            result = temp;
        }
        return result;
    }
*/
    /* BackTracking */
    vector<string> letterCombinations(string digits){
        vector<string> result;
        
        if(digits.empty())
            return result;

        string buttons[] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> temp = letterCombinations(digits.substr(1));
        string ch = buttons[digits[0] - '0'];
        for(int i = 0; i < ch.size(); ++i)
        {
            if(temp.empty())
                result.push_back(string(1, ch[i]));
            else
                for(int j = 0; j < temp.size(); ++j)
                    result.push_back(ch[i] + temp[j]);
        }
        return result;
    }
};

/*
 * Input: "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 */
int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}