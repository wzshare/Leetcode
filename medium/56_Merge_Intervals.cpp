#include "../libstruct.h"

using namespace std;

/* 
 * NO.56
 * Given a collection of intervals, merge all overlapping intervals.
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {return a.start < b.start;});
        vector<Interval> result{intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (result.back().end < intervals[i].start) result.push_back(intervals[i]);
            else result.back().end = max(result.back().end, intervals[i].end);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}