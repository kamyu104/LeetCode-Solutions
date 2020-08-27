// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        vector<int> prefix(n + 1);
        partial_sum(cbegin(stoneValue), cend(stoneValue), begin(prefix) + 1);
        
        vector<int> mid(n);
        iota(begin(mid), end(mid), 0);

        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = stoneValue[i];
        }

        int max_score = 0;
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i <= n - l; ++i) {
                const int j = i + l - 1;
                while (prefix[mid[i]] - prefix[i] < prefix[j + 1] - prefix[mid[i]]) {
                    ++mid[i];  // Time: O(n^2) in total
                }
                const int p = mid[i];
                max_score = 0;
                if (prefix[p] - prefix[i] == prefix[j + 1] - prefix[p]) {
                    max_score = max(dp[i][p - 1], dp[j][p]);
                } else {
                    if (i <= p - 2) {
                        max_score = max(max_score, dp[i][p - 2]);
                    }
                    if (p <= j) {
                        max_score = max(max_score, dp[j][p]);
                    }
                }
                dp[i][j] = max(dp[i][j - 1], (prefix[j + 1] - prefix[i]) + max_score);
                dp[j][i] = max(dp[j][i + 1], (prefix[j + 1] - prefix[i]) + max_score);
            }
        }
        return max_score;
    }
};


// Time:  O(n^2)
// Space: O(n^2)
class Solution2 {
public:
    int stoneGameV(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        vector<int> prefix(n + 1);
        partial_sum(cbegin(stoneValue), cend(stoneValue), begin(prefix) + 1);

        vector<vector<int>> mid(n, vector<int>(n));
        for (int l = 1; l <= n; ++l) {
            for (int i = 0; i <= n - l; ++i) {
                const int j = i + l - 1;
                int p = (l == 1) ? i : mid[i][j - 1];
                while (prefix[p] - prefix[i] < prefix[j + 1] - prefix[p]) {
                    ++p;  // Time: O(n^2) in total
                }
                mid[i][j] = p;
            }
        }
        
        vector<vector<int>> rmq(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            rmq[i][i] = stoneValue[i];
        }

        vector<vector<int>> dp(n, vector<int>(n));
        for (int l = 2; l <= n; ++l) {
            for (int i = 0; i <= n - l; ++i) {
                const int j = i + l - 1;
                const int p = mid[i][j];
                int max_score = 0;
                if (prefix[p] - prefix[i] == prefix[j + 1] - prefix[p]) {
                    max_score = max(rmq[i][p - 1], rmq[j][p]);
                } else {
                    if (i <= p - 2) {
                        max_score = max(max_score, rmq[i][p - 2]);
                    }
                    if (p <= j) {
                        max_score = max(max_score, rmq[j][p]);
                    }
                }
                dp[i][j] = max_score;
                rmq[i][j] = max(rmq[i][j - 1], (prefix[j + 1] - prefix[i]) + max_score);
                rmq[j][i] = max(rmq[j][i + 1], (prefix[j + 1] - prefix[i]) + max_score);
            }
        }
        return dp[0][n - 1];
    }
};
