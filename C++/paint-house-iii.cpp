// Time:  O(m * t * n^2)
// Space: O(t * n)

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        // dp[i][j][k]: i means the ith house, j means j neighbor groups, k means the kth color
        vector<vector<vector<int>>> dp(2,
            vector<vector<int>>(target,
                vector<int>(n, numeric_limits<int>::max())));
        for (int i = 0; i < m; ++i) {
            dp[i % 2] = vector<vector<int>>(target, vector<int>(n, numeric_limits<int>::max()));
            for (int j = 0; j < min(target, i + 1); ++j) {
                for (int k = 0; k < n; ++k) {
                    if (houses[i] && houses[i] - 1 != k) {
                        continue;
                    }
                    int same = 0;
                    if (i - 1 >= 0) {
                        same = dp[(i - 1) % 2][j][k];
                    } 
                    int diff = 0;
                    if (i - 1 >= 0) {
                        diff = numeric_limits<int>::max();
                        if (j - 1 >= 0) {
                            for (int nk = 0; nk < n; ++nk) {
                                if (nk == k) {
                                    continue;
                                }
                                diff = min(diff, dp[(i - 1) % 2][j - 1][nk]);
                            }
                        } 
                    }
                    dp[i % 2][j][k] = min(same, diff);
                    if (dp[i % 2][j][k] != numeric_limits<int>::max() && !houses[i]) {
                        dp[i % 2][j][k] += cost[i][k];
                    }
                }
            }
        }
        int result = *min_element(begin(dp[(m - 1) % 2].back()), end(dp[(m - 1) % 2].back()));
        return (result != numeric_limits<int>::max()) ? result : -1;
    }
};

// Time:  O(m * t * n^2)
// Space: O(t * n)
class Solution2 {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        const auto& hash = [&](int a, int b) {
            return a * (n + 1) + b;
        };
        const auto& unhash = [&](int a_b) {
            return pair(a_b / (n + 1), a_b % (n + 1));
        };
        unordered_map<int, int> dp = {{hash(0, 0), 0}};
        for (int i = 0; i < houses.size(); ++i) {
            unordered_map<int, int> new_dp;
            int left = houses[i], right = houses[i];
            if (!houses[i]) {
                left = 1, right = n;
            }
            for (int nk = left; nk <= right; ++nk) {
                for (const auto& [j_k, _] : dp) {
                    const auto& [j, k] = unhash(j_k);
                    int nj = j + int(k != nk);
                    if (nj > target) {
                        continue;
                    }
                    new_dp[hash(nj, nk)] = min(new_dp.count(hash(nj, nk)) ? new_dp[hash(nj, nk)]
                                               : numeric_limits<int>::max(), 
                                               dp[hash(j, k)] + ((nk != houses[i]) ? cost[i][nk - 1] : 0));
                }
            }
            dp = move(new_dp);
        }
        int result = numeric_limits<int>::max();
        for (const auto& [j_k, v] : dp) {
            if (unhash(j_k).first == target) {
                result = min(result, v);
            }
        }
        return (result != numeric_limits<int>::max()) ? result : -1;
    }
};
