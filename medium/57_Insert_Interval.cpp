#include "../libstruct.h"

using namespace std;

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        if (intervals.empty()) {
            result.push_back(newInterval);
            return result;
        }
        result.push_back(intervals[0]);
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}