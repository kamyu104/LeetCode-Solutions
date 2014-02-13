// Time Complexity: O(n^2)
// Space Complexity: O(1)

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
        vector<Interval> merge(vector<Interval> &intervals) {
            vector<Interval> ans;
            for(auto i : intervals) {
                ans = insert(ans, i);
            }
            return ans;
        }
    private:
        vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
            vector<Interval> ans;
            auto n = intervals.size();
            for(int i = 0; i < n; ++i) {
                if (newInterval.end < intervals[i].start) { // not overlapped
                    ans.push_back(newInterval);
                    for(; i < n; ++i)
                        ans.push_back(intervals[i]);
                    return ans;
                }
                else if (newInterval.start > intervals[i].end)  { // not overlapped
                    ans.push_back(intervals[i]);
                }
                else { // merge
                    newInterval.start = min(newInterval.start, intervals[i].start);
                    newInterval.end = max(newInterval.end, intervals[i].end);
                }
            }

            ans.push_back(newInterval);
            return ans;
        }
};
