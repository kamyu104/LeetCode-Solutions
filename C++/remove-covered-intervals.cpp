// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](const auto& a, const auto& b) {
                 return a[0] != b[0] ? a < b : a[1] > b[1];
             });
        int result = 0, max_right = 0;
        for (const auto& interval : intervals) {
            result += int(interval[1] > max_right);
            max_right = max(max_right, interval[1]);
        }
        return result;
    }
};
