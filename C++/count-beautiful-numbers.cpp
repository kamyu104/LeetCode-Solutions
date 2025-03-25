// Time:  O(logr * 2 * 10 * s)
// Space: O(s) ~= O(2026), s = len(states)

// dp
class Solution {
public:
    int beautifulNumbers(int l, int r) {
        const auto& count = [](int x) {
            const auto& s = to_string(x);
            vector<unordered_map<int, unordered_map<int, int>>> dp(2);
            dp[1][1][0] = 1;
            for (int i = 0; i < size(s); ++i) {
                vector<unordered_map<int, unordered_map<int, int>>> new_dp(2);
                const int c = s[i] - '0';
                for (int b = 0; b < 2; ++b) {
                    for (const auto& [mul, kvp] : dp[b]) {
                        for (const auto& [total, cnt] : kvp) {
                            for (int x = 0; x <= (!b ? 9 : c); ++x) {
                                new_dp[b && x == c][total == 0 && x == 0 ? mul : (mul * x)][total + x] += cnt;
                            }
                        }
                    }
                }
                swap(dp, new_dp);
            }
            int result = 0;
            for (int b = 0; b < 2; ++b) {
                for (const auto& [mul, kvp] : dp[b]) {
                    for (const auto& [total, cnt] : kvp) {
                        if (total && mul % total == 0) {
                            result += cnt;
                        }
                    }
                }
            }
            return result;
        };

        return count(r) - count(l - 1);
    }
};
