// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        vector<int> prefix(n + 1);
        partial_sum(cbegin(stoneValue), cend(stoneValue), begin(prefix) + 1);

        vector<vector<int>> mid(n, vector<int>(n));
        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i <= n - l; ++i) {
                int p = (l == 1) ? i + 1 : mid[i][i + l - 2];
                while (prefix[p] - prefix[i] < prefix[i + l] - prefix[p]) {
                    ++p;  // Time: O(n^2) in total
                }
                mid[i][i + l - 1] = p;
            }
        }
        
        vector<vector<int>> rmq(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            rmq[i][i] = stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n));
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i <= n - l; ++i) {
                const auto& p = mid[i][i + l - 1];
                int max_score = 0;
                if (prefix[p] - prefix[i] == prefix[i + l] - prefix[p]) {
                    max_score = max(rmq[i][p - 1], rmq[i + l - 1][p]);
                } else {
                    if (i <= p - 2) {
                        max_score = max(max_score, rmq[i][p - 2]);
                    }
                    if (p <= i + l - 1) {
                        max_score = max(max_score, rmq[i + l - 1][p]);
                    }
                }
                dp[i][i + l - 1] = max_score;
                rmq[i][i + l - 1] = max(rmq[i][i + l - 2], (prefix[i + l] - prefix[i]) + max_score);
                rmq[i + l - 1][i] = max(rmq[i + l - 1][i + 1], (prefix[i + l] - prefix[i]) + max_score);
            }
        }
        return dp[0][n - 1];
    }
};
