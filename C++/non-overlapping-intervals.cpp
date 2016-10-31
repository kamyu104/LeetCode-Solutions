// Time:  O(nlogn)
// Space: O(1)

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const Interval& a, const Interval& b) { return a.start < b.start; });

        int result = 0, prev = 0;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start < intervals[prev].end) {
                if (intervals[i].end < intervals[prev].end) {
                    prev = i;
                }
                ++result;
            } else {
                prev = i;
            }
        }
        return result;
    }
};
