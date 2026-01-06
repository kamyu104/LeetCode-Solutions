// Time:  O(n * m)
// Space: O(m)

// dp, two pointers
class Solution {
public:
    int numberOfRoutes(vector<string>& grid, int d) {
        static const int MOD = 1e9 + 7;

        const auto& update = [](const auto& dp, int d, const auto& arr) {
            vector<int> new_dp(size(arr));
            int curr = accumulate(cbegin(dp), cbegin(dp) + min(d, static_cast<int>(size(dp))), 0, [](const auto& accu, const auto& x) {
                return (accu + x) % MOD;
            });
            for (int i = 0; i < size(arr); ++i) {
                if (i - d - 1 >= 0) {
                    curr = ((curr - dp[i - d - 1]) % MOD + MOD) % MOD;
                }
                if (i + d < size(dp)) {
                    curr = (curr + dp[i + d]) % MOD;
                }
                new_dp[i] = arr[i] == '.' ? curr : 0;
            }
            return new_dp;
        };
    
        vector<int> dp(size(grid[0]), 1);
        for (int i = size(grid) - 1; i >= 0; --i) {
            dp = update(dp, i != size(grid) - 1 ? d - 1 : 0, grid[i]);
            dp = update(dp, d, grid[i]);
        }
        return accumulate(cbegin(dp), cend(dp), 0, [](const auto& accu, const auto& x) {
            return (accu + x) % MOD;
        });
    }
};
