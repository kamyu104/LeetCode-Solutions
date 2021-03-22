// Time:  O(logm)
// Space: O(1)

class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum -= n;
        const auto& check = [&n, &index, &maxSum](int x) {
            int64_t y = max(x - index, 0);
            auto total = (x + y) * (x - y + 1) / 2;
            y = max(x - (n - 1 - index), 0);
            total += (x + y) * (x - y + 1) / 2;
            return total - x <= maxSum;
        };
        int left = 0, right = maxSum;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (!check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return 1 + right;
    }
};
