// Time:  O(nlogn)
// Space: O(n)

// sort, line sweep
class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;
        for (const auto& x : intervals) {
            events.emplace_back(x[0], +1);
            events.emplace_back(x[1] + 1, -1);
        }
        ranges::sort(events);
        int result = 0;
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

// Time:  O(n^2)
// Space: O(n)
// brute force
class Solution2 {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {
        const auto& check = [&](int i, int j) {
            return max(intervals[i][0], intervals[j][0]) <= min(intervals[i][1], intervals[j][1]);
        };

        int result = 0;
        for (int i = 0; i < size(intervals); ++i) {
            for (int j = i + 1; j < size(intervals); ++j) {
                if (check(i, j)) {
                    ++result;
                }
            }
        }
        return result;
    }
};
