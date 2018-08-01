#include "../libstruct.h"

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int a = 0, b = 0;
        for (char c : s) {
            if (c == '(') {
                a++;
                b++;
            } else if (c == ')') {
                a--;
                b--;
            } else {
                a--;
                b++;
            }
            a = max(0, a);
            if (b < 0) return false;
        }
        return a == 0; 
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}