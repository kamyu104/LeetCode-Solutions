// Time:  O(n^2 + len(diffs) * n * k) = O(n^3 * k) at most
// Space: O(len(diffs) + n * k) = O(n^2) at most

// sort, dp, prefix sum, two pointers
class Solution {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        static const int MOD = 1e9 + 7;
        
        sort(begin(nums), end(nums));
        unordered_set<int> diffs;
        for (int i = 0; i < size(nums); ++i) {
            for (int j = i + 1; j < size(nums); ++j) {
                diffs.emplace(nums[j] - nums[i]);
            }
        }
        vector<int> sorted_diffs(cbegin(diffs), cend(diffs));
        sort(rbegin(sorted_diffs), rend(sorted_diffs));
        int result = 0;
        int64_t prev = 0;
        for (const auto& mn : sorted_diffs) {
            vector<vector<int64_t>> dp(size(nums) + 1, vector<int64_t>(k + 1));
            dp[0][0] = 1;
            for (int i = 0, j = 0; i < size(nums); ++i) {
                for (; j < size(nums) && nums[i] - nums[j] >= mn; ++j);
                for (int l = 1; l <= k; ++l) {
                    dp[i + 1][l] = (dp[i + 1][l] + dp[(j - 1) + 1][l - 1]) % MOD;  // dp[i+1][l]: count of subsequences of length l ending at i having min diff >= mn
                }
                for (int l = 0; l <= k; ++l) {
                    dp[i + 1][l] = (dp[i + 1][l] + dp[i][l]) % MOD;  // dp[i+1][l]: accumulated count of subsequences of length l ending at [0, i] having min diff >= mn
                }
            }
            const int64_t cnt = ((dp.back()[k] - prev) + MOD) % MOD;
            result = (result + (mn * cnt % MOD)) % MOD;
            prev = dp.back()[k];
        }
        return result;
    }
};

// Time:  O(n^3 * len(diffs)) = O(n^5) at most
// Space: O(n^2 * len(diffs)) = O(n^4) at most
// sort, dp
class Solution2 {
public:
    int sumOfPowers(vector<int>& nums, int k) {
        static const int MOD = 1e9 + 7;
        
        sort(begin(nums), end(nums));
        vector<vector<unordered_map<int, int64_t>>> dp(size(nums), vector<unordered_map<int, int64_t>>(size(nums) + 1));
        for (int i = 0; i < size(nums); ++i) {
            for (int j = max(k - (static_cast<int>(size(nums)) - i + 1), 0); j < i; ++j) {
                const int diff = nums[i] - nums[j];
                ++dp[i][2][diff];
                for (int l = max(k - (static_cast<int>(size(nums)) - i + 1), 0); l <= i; ++l) {
                    for (const auto& [mn, cnt] : dp[j][l]) {
                        dp[i][l + 1][min(diff, mn)] = (dp[i][l + 1][min(diff, mn)] + cnt) % MOD;
                    }
                }
            }
        }
        int result = 0;
        for (int i = k - 1; i < size(dp); ++i) {
            for (const auto& [mn, cnt] : dp[i][k]) {
                result = (result + (mn * cnt % MOD)) % MOD;
            }
        }
        return result;
    }
};
