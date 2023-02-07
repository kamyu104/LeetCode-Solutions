// Time:  O(m * n)
// Space: O(m + n)

// dp
class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if ((i == 0 && j == 0) || grid[i][j] == 0) {
                    continue;
                }
                if ((i - 1 < 0 || grid[i - 1][j] == 0) && (j - 1 < 0 || grid[i][j - 1] == 0)) {
                    grid[i][j] = 0;
                }
            }
        }
        for (int i = size(grid) - 1; i >= 0; --i) {
            for (int j = size(grid[0]) - 1; j >= 0; --j) {
                if ((i == size(grid) - 1 && j == size(grid[0]) - 1) || grid[i][j] == 0) {
                    continue;
                }
                if ((i + 1 >= size(grid) || grid[i + 1][j] == 0) && (j + 1 >= size(grid[0]) || grid[i][j + 1] == 0)) {
                    grid[i][j] = 0;
                }
            }
        }
        vector<int> cnt(size(grid) + size(grid[0]) - 1);
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                cnt[i + j] += grid[i][j];
            }
        }
        return any_of(next(cbegin(cnt)), prev(cend(cnt)), [](const auto& x) {
            return x <= 1;
        });
    }
};

// Time:  O(m * n)
// Space: O(m + n)
// iterative dfs
class Solution2 {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        const auto& iter_dfs = [&]() {
            vector<pair<int, int>> stk = {{0, 0}};
            while (!empty(stk)) {
                const auto [i, j] = stk.back(); stk.pop_back();
                if (!(i < size(grid) && j < size(grid[0]) && grid[i][j])) {
                    continue;
                }
                if (i == size(grid) - 1 && j == size(grid[0]) - 1) {
                    return true;
                }
                if (!(i == 0 && j == 0)) {
                    grid[i][j] = 0;
                }
                stk.emplace_back(i, j + 1);
                stk.emplace_back(i + 1, j);
            }
            return false;
        };

        return !iter_dfs() || !iter_dfs();
    }
};

// Time:  O(m * n)
// Space: O(m + n)
// dfs
class Solution3 {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        const function<bool(int, int)> dfs = [&](int i, int j) {
            if (!(i < size(grid) && j < size(grid[0]) && grid[i][j])) {
                return false;
            }
            if (i == size(grid) - 1 && j == size(grid[0]) - 1) {
                return true;
            }
            if (!(i == 0 && j == 0)) {
                grid[i][j] = 0;
            }
            return dfs(i + 1, j) || dfs(i, j + 1);
        };

        return !dfs(0, 0) || !dfs(0, 0);
    }
};

