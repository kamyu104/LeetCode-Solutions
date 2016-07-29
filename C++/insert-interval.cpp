// Time:  O(n)
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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        size_t i = 0;
        vector<Interval> result;
        // Insert intervals appeared before newInterval.
        while (i < intervals.size() && newInterval.start > intervals[i].end) {
            result.emplace_back(intervals[i++]);
        }

        // Merge intervals that overlap with newInterval.
        while (i < intervals.size() && newInterval.end >= intervals[i].start) {
            newInterval = {min(newInterval.start, intervals[i].start),
                max(newInterval.end, intervals[i].end)};
            ++i;
        }
        result.emplace_back(newInterval);

        // Insert intervals appearing after newInterval.
        result.insert(result.end(), intervals.cbegin() + i, intervals.cend());
        return result;
    }
};
