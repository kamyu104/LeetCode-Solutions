// Time:  O(n * l^4)
// Space: O(l^2)

// dp
class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        const int l = size(cost[0]);
        vector<vector<int64_t>> dp(l, vector<int64_t>(l));
        for (int k = 0; k * 2 < n; ++k) {
            vector<vector<int64_t>> new_dp(l, vector<int64_t>(l, numeric_limits<int64_t>::max()));
            for (int i = 0; i < l; ++i) {
                for (int j = 0; j < l; ++j) {
                    if (j == i) {
                        continue;
                    }
                    for (int ni = 0; ni < l; ++ni) {
                        if (ni == i) {
                            continue;
                        }
                        for (int nj = 0; nj < l; ++nj) {
                            if (nj == j || ni == nj) {
                                continue;
                            }
                            new_dp[ni][nj] = min(new_dp[ni][nj], dp[i][j] + cost[k][ni] + cost[n - 1 - k][nj]);
                        }
                    }
                }
            }
            dp = move(new_dp);
        }
        int64_t result = numeric_limits<int64_t>::max();
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < l; ++j) {
                if (i != j) {
                    result = min(result, dp[i][j]);
                }
            }
        }
        return result;
    }
};
