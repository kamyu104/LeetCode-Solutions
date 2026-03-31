// Time:  O(m * n * r / 64), r = max(x for row in grid for x in row)
// Space: O(n * r / 64)

// dp, bitset
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        static const int MAX_LEN = 1024;
        
        vector<bitset<MAX_LEN>> dp(size(grid[0]));
        dp[0].set(0);
        for (int i = 0; i < size(grid); ++i) {
            vector<bitset<MAX_LEN>> new_dp(size(grid[0]));
            for (int j = 0; j < size(grid[0]); ++j) {
                for (int k = 0; k < MAX_LEN; ++k) {
                    if (dp[j][k] || (j - 1 >= 0 && new_dp[j - 1][k])) {
                        new_dp[j].set(k ^ grid[i][j]);
                    }
                }
            }
            dp = move(new_dp);
        }
        for (int i = 0; i < MAX_LEN; ++i) {
            if (dp.back()[i]) {
                return i;
            }
        }
        return -1;
    }
};

// Time:  O(m * n * r), r = max(x for row in grid for x in row)
// Space: O(n * r)
// dp
class Solution2 {
public:
    int minCost(vector<vector<int>>& grid) {
        uint32_t mx = 0;
        for (const auto& row : grid) {
            mx = max(mx, static_cast<uint32_t>(ranges::max(row)));
        }
        const auto& l = 1 << bit_width(mx);
        vector<vector<bool>> dp(size(grid[0]), vector<bool>(l));
        dp[0][0] = true;
        for (int i = 0; i < size(grid); ++i) {
            vector<vector<bool>> new_dp(size(grid[0]), vector<bool>(l));
            for (int j = 0; j < size(grid[0]); ++j) {
                for (int k = 0; k < l; ++k) {
                    new_dp[j][k ^ grid[i][j]] = dp[j][k] || (j - 1 >= 0 && new_dp[j - 1][k]);
                }
            }
            dp = move(new_dp);
        }
        for (int i = 0; i < l; ++i) {
            if (dp.back()[i]) {
                return i;
            }
        }
        return -1;
    }
};

// Time:  O(m * n * r), r = max(x for row in grid for x in row)
// Space: O(n * r)
// dp
class Solution_TLE {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<unordered_set<int>> dp(size(grid[0]));
        dp[0].emplace(0);
        for (int i = 0; i < size(grid); ++i) {
            vector<unordered_set<int>> new_dp(size(grid[0]));
            for (int j = 0; j < size(grid[0]); ++j) {
                for (const auto& k : dp[j]) {
                    new_dp[j].emplace(k ^ grid[i][j]);
                }
                if (j - 1 < 0) {
                    continue;
                }
                for (const auto& k : new_dp[j - 1]) {
                    new_dp[j].emplace(k ^ grid[i][j]);
                }
            }
            dp = move(new_dp);
        }
        return ranges::min(dp.back());
    }
};
