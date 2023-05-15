// Time:  O(m * n)
// Space: O(m)

// dp
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<bool> dp(size(grid), true);
        int c = 0;
        for (; c < size(grid[0]) - 1; ++c) {
            vector<bool> new_dp(size(grid));
            for (int r = 0; r < size(grid); ++r) {
                if (!dp[r]) {
                    continue;
                }
                if (grid[r][c] < grid[r][c + 1]) {
                    new_dp[r] = true;
                }
                if (r - 1 >= 0 && grid[r][c] < grid[r - 1][c + 1]) {
                    new_dp[r - 1] = true;
                }
                if (r + 1 < size(grid) && grid[r][c] < grid[r + 1][c + 1]) {
                    new_dp[r + 1] = true;
                }
            }
            dp = move(new_dp);
            if (!accumulate(cbegin(dp), cend(dp), 0)) {
                break;
            }
        }
        return c;
    }
};

// Time:  O(m * n)
// Space: O(m)
// dp
class Solution2 {
public:
    int maxMoves(vector<vector<int>>& grid) {
        vector<int> dp(size(grid));
        for (int c = size(grid[0]) - 2; c >= 0; --c) {
            vector<int> new_dp(size(grid));
            for (int r = 0; r < size(grid); ++r) {
                if (grid[r][c] < grid[r][c + 1]) {
                    new_dp[r] = max(new_dp[r], dp[r] + 1);
                }
                if (r - 1 >= 0 && grid[r][c] < grid[r - 1][c + 1]) {
                    new_dp[r] = max(new_dp[r], dp[r - 1] + 1);
                }
                if (r + 1 < size(grid) && grid[r][c] < grid[r + 1][c + 1]) {
                    new_dp[r] = max(new_dp[r], dp[r + 1] + 1);
                }
            }
            dp = move(new_dp);
        }
        return *max_element(cbegin(dp), cend(dp));
    }
};

// Time:  O(m * n)
// Space: O(m)
// bfs
class Solution3 {
public:
    int maxMoves(vector<vector<int>>& grid) {
        unordered_set<int> q;
        for (int r = 0; r < size(grid); ++r) {
            q.emplace(r);
        }
        int c = 0;
        for (; c < size(grid[0]) - 1; ++c) {
            unordered_set<int> new_q;
            for (const auto& r : q) {
                if (grid[r][c] < grid[r][c + 1]) {
                    new_q.emplace(r);
                }
                if (r - 1 >= 0 && grid[r][c] < grid[r - 1][c + 1]) {
                    new_q.emplace(r - 1);
                }
                if (r + 1 < size(grid) && grid[r][c] < grid[r + 1][c + 1]) {
                    new_q.emplace(r + 1);
                }
            }
            q = move(new_q);
            if (empty(q)) {
                break;
            }
        }
        return c;
    }
};
