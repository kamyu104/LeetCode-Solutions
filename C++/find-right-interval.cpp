// Time:  O(nlogn)
// Space: O(n)

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
    vector<int> findRightInterval(vector<Interval>& intervals) {
        map<int, int> lookup;
        vector<int> result;
        for (int i = 0; i < intervals.size(); ++i) {
            lookup[intervals[i].start] = i;
        }
        for (const auto& interval : intervals) {
            const auto it = lookup.lower_bound(interval.end);
            if (it == lookup.end()) {
                result.emplace_back(-1);
            } else {
                result.emplace_back(it->second);
            }
        }
        return result;
    }
};
