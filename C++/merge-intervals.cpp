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
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return intervals;
        }

        sort(intervals.begin(), intervals.end(),
        [](const Interval& a, const Interval& b) {
             return a.start < b.start;               
        });

        vector<Interval> result{intervals[0]};
        for (int i = 1; i < intervals.size(); ++i) {
            Interval& prev = result.back();
            if (intervals[i].start <= prev.end) { 
                prev.end = max(prev.end, intervals[i].end);
            } else {
                result.emplace_back(intervals[i]);
            }
        }

        return result;
    }
};
