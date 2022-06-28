// Time:  O((m * n) * (m + n) / 32)
// Space: O(n * (m + n) / 32)

// dp with bitsets
class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        if ((size(grid) + size(grid[0]) - 1) % 2 == 1) {
            return false;
        }
        vector<bitset<100>> dp(size(grid[0]) + 1);
        for (int i = 0; i < size(grid); ++i) {
            dp[0][0] = !i;
            for (int j = 0; j < size(grid[0]); ++j) {
                dp[j + 1] = (grid[i][j] == '(') ? (dp[j] | dp[j + 1]) << 1: (dp[j] | dp[j + 1]) >> 1;
            }
        }
        return dp.back()[0];
    }
};

// Time:  O(m * n)
// Space: O(n)
// dp, optimized from solution1 (wrong answer)
class Solution_WA {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        const int MAX_M = 100;
        const int MAX_N = 100;;
        if ((size(grid) + size(grid[0]) - 1) % 2 == 1) {
            return false;
        }
        vector<pair<int, int>> dp(size(grid[0]) + 1, {MAX_M + MAX_N, -(MAX_M + MAX_N)});
        for (int i = 0; i < size(grid); ++i) {
            dp[0] = !i ? pair(0, 0) : pair(MAX_M + MAX_N, -(MAX_M + MAX_N));
            for (int j = 0; j < size(grid[0]); ++j) {
                const int d = (grid[i][j] == '(') ? 1 : -1;
                dp[j + 1] = {min(dp[j + 1].first, dp[j].first) + d, max(dp[j + 1].second, dp[j].second) + d};
                // bitset pattern is like xxx1010101xxxx (in fact, it is not always true in this problem where some paths are invalid)
                if (dp[j + 1].second < 0) {
                    dp[j + 1] = {MAX_M + MAX_N, -(MAX_M + MAX_N)};
                } else {
                    dp[j + 1].first = max(dp[j + 1].first, dp[j + 1].second % 2);
                }
            }
        }
        return dp.back().first == 0;
    }
};
