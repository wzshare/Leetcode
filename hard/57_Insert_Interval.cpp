#include "../libstruct.h"

using namespace std;

/* 
 * NO.57
 * Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
 * You may assume that the intervals were initially sorted according to their start times.
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        int index = 0;
        while(index < intervals.size() && intervals[index].end < newInterval.start){
            result.push_back(intervals[index++]);
        }
        while(index < intervals.size() && intervals[index].start <= newInterval.end){
            newInterval.start = min(newInterval.start, intervals[index].start);
            newInterval.end = max(newInterval.end, intervals[index++].end);
        }
        result.push_back(newInterval);
        while(index < intervals.size()){
            result.push_back(intervals[index++]);
        }
        return result;
    }
};

int main(int argc, char const *argv[])
{
    Solution solution;
    return 0;
}