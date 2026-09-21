// Time:  O(nlogn)
// Space: O(n)

// sort, line sweep
class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;
        for (const auto& x : intervals) {
            events.emplace_back(x[0], +1);
            events.emplace_back(x[1] + 1, -1);
        }
        ranges::sort(events);
        int64_t result = 0;
        int cnt = 0;
        for (const auto& [_, c] : events) {
            if (c == +1) {
                result += cnt;
            }
            cnt += c;
        }
        return result;
    }
};
