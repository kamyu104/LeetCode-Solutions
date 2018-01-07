// Time:  O(m * logn), m is the number of schedule, n is the number of employees, m >= n
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
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> result;
        using P = pair<int, pair<int, int>>;
        priority_queue<P, vector<P>, greater<P>> min_heap;
        for (int i = 0; i < schedule.size(); ++i) {
            min_heap.emplace(schedule[i][0].start, make_pair(i, 0));
        }
        int last_end = -1;
        while (!min_heap.empty()) {
            int t;
            pair<int, int> p;
            tie(t, p) = min_heap.top(); min_heap.pop();
            if (0 <= last_end && last_end < t) {
                result.emplace_back(last_end, t);
            }
            last_end = max(last_end, schedule[p.first][p.second].end);
            if (p.second + 1 < schedule[p.first].size()) {
                min_heap.emplace(schedule[p.first][p.second + 1].start, make_pair(p.first, p.second + 1));
            }
        }
        return result;
    }
};
