// Time:  O(nlogn)
// Space: O(1)

// sort, line sweep
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / b;
        };

        ranges::sort(intervals, [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });
        int64_t result = 0;
        int left = 0, right = -1;
        for (const auto& x : intervals) {
            if (x[0] <= right + 1) {
                right = max(right, x[1]);
                continue;
            }
            result += right - left + 1;
            left = x[0];
            right = x[1];
        }
        result += right - left + 1;
        result *= ceil_divide(brightness, 3);
        return result;
    }
};
