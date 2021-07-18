// Time:  O(m * n)
// Space: O(n)

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        vector<int64_t> dp(cbegin(points[0]), cend(points[0]));
        for (int i = 1; i < size(points); ++i) {
            vector<int64_t> prefix(size(points[i]));
            prefix[0] = dp[0];
            for (int j = 1; j < size(points[i]); ++j) {
                prefix[j] = max(prefix[j - 1], dp[j] + j);
            }
            vector<int64_t> suffix(size(points[i]));
            suffix.back() = dp.back() - (size(points[i]) - 1);
            for (int j = size(points[i]) - 2; j >= 0; --j) {
                suffix[j] = max(suffix[j + 1], dp[j] - j);
            }
            vector<int64_t> new_dp(size(points[i]));
            for (int j = 0; j < size(points[i]); ++j) {
                new_dp[j] = max(prefix[j] - j, suffix[j] + j) + points[i][j];
            }
            dp = move(new_dp);
        }
        return *max_element(cbegin(dp), cend(dp));
    }
};
