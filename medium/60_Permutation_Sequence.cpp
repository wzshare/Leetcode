#include "../libstruct.h"

using namespace std;

/* NO.60
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * Given n and k, return the kth permutation sequence.
 * Note:
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        string result = "";
        int a[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
        vector<char> s = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
        k--;
        while (n-- > 0) {
            int i = k / a[n];
            k %= a[n];
            result += s[i];
            s.erase(s.begin() + i);
        }
        return result;
    }
};

//Input: n = 4, k = 9
//Output: "2314"
int main(int argc, char const *argv[])
{
    Solution solution;
    cout << solution.getPermutation(4, 9) << endl;
    return 0;
}