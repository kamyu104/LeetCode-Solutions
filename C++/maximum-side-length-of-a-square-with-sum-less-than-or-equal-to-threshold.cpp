// Time:  O(m * n * log(min(m, n)))
// Space: O(m * n)

class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        vector<vector<int>> dp(mat.size() + 1, vector<int>(mat[0].size() + 1));
        for (int i = 1; i < mat.size() + 1; ++i) {
            for (int j  = 1; j < mat[0].size() + 1; ++j) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }
        
        int left = 0, right = min(mat.size(), mat[0].size());
        while (left <= right) {
            const auto mid = left + (right - left) / 2;
            if (!check(dp, mid, threshold)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private:
    bool check(const vector<vector<int>>& dp, int mid, int threshold) {
        for (int i = mid; i < dp.size(); ++i) {
            for (int j = mid; j < dp[0].size(); ++j) {
                if (dp[i][j] - dp[i-mid][j] - dp[i][j-mid] + dp[i-mid][j-mid] <= threshold) {
                    return true;
                }
            }
        }
        return false;
    }
};
