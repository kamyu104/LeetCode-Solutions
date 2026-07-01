// Time:  O(nlogn)
// Space: O(n)

// sort
class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        const auto& merged_intervals = [](auto& occupiedIntervals) {
            ranges::sort(occupiedIntervals, [](const auto& a, const auto& b) {
                return a[0] < b[0];
            });
            vector<vector<int>> result;
            for (const auto& x : occupiedIntervals) {
                if (empty(result) || result.back()[1] + 1 < x[0]) {
                    result.emplace_back(x);
                } else {
                    result.back()[1] = max(result.back()[1], x[1]);
                }
            }
            return result;
        };
    
        const auto& overlapped = [](const auto& a, const auto& b) {
            return max(a[0], b[0]) <= min(a[1], b[1]);
        };

        vector<vector<int>> result;
        for (const auto& x : merged_intervals(occupiedIntervals)) {
            if (!overlapped(x, vector<int>{freeStart, freeEnd})) {
                result.emplace_back(x);
                continue;
            }
            if (x[0] <= freeStart - 1) {
                result.push_back({x[0], freeStart - 1});
            }
            if (freeEnd + 1 <= x[1]) {
                result.push_back({freeEnd + 1, x[1]});
            }
        }
        return result;
    }
};
