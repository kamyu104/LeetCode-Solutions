// Time:  O(m * n * k^2 * logk)
// Space: O(k^2)

// brute force, sort
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector<vector<int>> result(size(grid) - k + 1, vector<int>(size(grid[0]) - k + 1, -1));
        for (int i = 0; i + (k - 1) < size(grid); ++i) {
            for (int j = 0; j + (k - 1) < size(grid[0]); ++j) {
                vector<int> vals;
                for (int di = 0; di < k; ++di) {
                    for (int dj = 0; dj < k; ++dj) {
                        vals.emplace_back(grid[i + di][j + dj]);
                    }
                }
                sort(begin(vals), end(vals));
                vals.erase(unique(begin(vals), end(vals)), end(vals));
                if (size(vals) == 1) {
                    result[i][j] = 0;
                    continue;
                }
                int mn = numeric_limits<int>::max();
                int prev = numeric_limits<int>::min();
                for (const auto& x : vals) {
                    if (prev != numeric_limits<int>::min()) {
                        mn = min(mn, x - prev);
                    }
                    prev = x;
                }
                result[i][j] = mn;
            }
        }
        return result;
    }
};
