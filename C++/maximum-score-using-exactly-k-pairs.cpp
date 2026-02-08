// Time:  O(n * m * k)
// Space: O(min(n, m) * k)

// dp
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        static const auto& NEG_INF = numeric_limits<int64_t>::min();
        
        if (size(nums1) < size(nums2)) {
            swap(nums1, nums2);
        }
        vector<vector<int64_t>> dp(size(nums2) + 1, vector<int64_t>(k + 1, NEG_INF));
        for (int j = 0; j < size(dp); ++j) {
            dp[j][0] = 0;
        }
        vector<vector<int64_t>> new_dp(size(nums2) + 1, vector<int64_t>(k + 1, NEG_INF));
        for (int i = 0; i < size(nums1); ++i) {
            for (int j = 0; j < size(new_dp); ++j) {
                new_dp[j][0] = 0;
            }            
            for (int j = 0; j < size(nums2); ++j) {
                const auto& score = static_cast<int64_t>(nums1[i]) * nums2[j];
                const auto& mx = min({i + 1, j + 1, k});
                for (int c = 0; c < mx; ++c) {
                    new_dp[j + 1][c + 1] = max({
                        new_dp[j][c + 1],
                        dp[j + 1][c + 1],
                        dp[j][c] + score
                    });
                }
            }
            swap(dp, new_dp);
        }
        return dp.back().back();
    }
};

// Time:  O(n * m * k)
// Space: O(n * m)
class Solution2 {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        static const auto& NEG_INF = numeric_limits<int64_t>::min();

        vector<vector<int64_t>> dp(size(nums1), vector<int64_t>(size(nums2), NEG_INF));
        vector<vector<int64_t>> new_dp(size(nums1), vector<int64_t>(size(nums2), NEG_INF));
        for (int c = 0; c < k; ++c) {
            for (int i = c; i < size(nums1); ++i) {
                for (int j = c; j < size(nums2); ++j) {
                    new_dp[i][j] = max({
                        j - 1 >= c ? new_dp[i][j - 1] : NEG_INF,
                        i - 1 >= c ? new_dp[i - 1][j] : NEG_INF,
                        (c ? dp[i - 1][j - 1] : 0) + static_cast<int64_t>(nums1[i]) * nums2[j]
                    });
                }
            }
            swap(dp, new_dp);
        }
        return dp.back().back();
    }
};
