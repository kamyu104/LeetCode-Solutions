// Time:  O(n * 2^n)
// Space: O(2^n)

// bitmasks, dp
class Solution {
public:
    long long minimumTime(vector<int>& power) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / b;
        };

        unordered_map<int, int64_t> dp = {{0, 0}};
        for (int gain = 1; gain <= size(power); ++gain) {
            unordered_map<int, int64_t> new_dp;
            for (const auto& [mask, _] : dp) {
                for (int i = 0; i < size(power); ++i) {
                    if (mask & (1 << i)) {
                        continue;
                    }
                    const auto& x = dp[mask] + ceil_divide(power[i], gain);
                    if (!new_dp.count(mask | (1 << i)) || new_dp[mask | (1 << i)] > x) {
                        new_dp[mask | (1 << i)] = x;
                    }
                }
            }
            dp = move(new_dp);
        }
        return dp[(1 << size(power)) - 1];
    }
};
