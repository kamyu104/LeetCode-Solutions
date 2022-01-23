// Time:  O(n)
// Space: O(1)

// math
class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int64_t total = 0, mn = 0, mx = 0;
        for (const auto& x : differences) {
            total += x;
            mn = min(mn, total);
            mx = max(mx, total);
        }
        return max((upper - lower) - (mx - mn) + 1, static_cast<int64_t>(0));
    }
};
