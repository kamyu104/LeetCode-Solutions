// Time:  O(m * n)
// Space: O(n + min(m, n))

// dp
class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        static const int INF = numeric_limits<int>::max();

        const auto& l = min(size(mat), size(mat[0]));
        vector<int> min_r(l, INF), max_r(l, -1);
        vector<int> min_c(l, INF), max_c(l, -1);
        vector<int> dp(size(mat[0]));
        for (int r = 0; r < size(mat); ++r) {
            vector<int> new_dp(size(mat[0]));
            for (int c = 0; c < size(mat[0]); ++c) {
                if (!mat[r][c]) {
                    continue;
                }
                new_dp[c] = min({c - 1 >= 0 ? dp[c - 1] : 0, c - 1 >= 0 ? new_dp[c - 1] : 0, dp[c]}) + 1;
                min_r[new_dp[c] - 1] = min(min_r[new_dp[c] - 1], r);
                max_r[new_dp[c] - 1] = max(max_r[new_dp[c] - 1], r);
                min_c[new_dp[c] - 1] = min(min_c[new_dp[c] - 1], c);
                max_c[new_dp[c] - 1] = max(max_c[new_dp[c] - 1], c);
            }
            dp = move(new_dp);
        }
        for (int i = l - 1; i >= 0; --i) {
            if (max_r[i] - min_r[i] >= i + 1 || max_c[i] - min_c[i] >= i + 1) {
                return (i + 1) * (i + 1);
            }
        }
        return 0;
    }
};
