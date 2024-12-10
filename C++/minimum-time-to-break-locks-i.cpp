// Time:  O(n * 2^n)
// Space: O(2^n)

// bitmasks, dp
class Solution {
public:
    int findMinimumTime(vector<int>& strength, int K) {
        const auto& ceil_divide = [](int a, int b) {
            return (a + b - 1) / b;
        };

        vector<int> dp(1 << size(strength), numeric_limits<int>::max());
        dp[0] = 0;
        for (int mask = 1; mask < size(dp); ++mask) {
            const int x = 1 + (__builtin_popcount(mask) - 1) * K;
            for (int i = 0; i < size(strength); ++i) {
                if (!(mask & (1 << i))) {
                    continue;
                }
                dp[mask] = min(dp[mask], dp[mask ^ (1 << i)] + ceil_divide(strength[i], x));
            }
        }
        return dp.back();
    }
};
