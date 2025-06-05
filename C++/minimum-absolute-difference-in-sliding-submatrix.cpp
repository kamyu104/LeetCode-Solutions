// Time:  O(m * n * k^2)
// Space: O(k^2)

// two pointers, sliding window, bst
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        vector<vector<int>> result(size(grid) - k + 1, vector<int>(size(grid[0]) - k + 1, -1));
        multiset<int> bst;
        for (int di = 0; di < k; ++di) {
            for (int dj = 0; dj < k; ++dj) {
                bst.emplace(grid[0 + di][0 + dj]);
            }
        }
        for (int i = 0; i + (k - 1) < size(grid); ++i) {
            multiset<int> bst2(bst);
            for (int j = 0; j + (k - 1) < size(grid[0]); ++j) {
                int mn = numeric_limits<int>::max();
                int prev = numeric_limits<int>::min();
                for (const auto& x : bst2) {
                    if (prev != numeric_limits<int>::min() && x != prev) {
                        mn = min(mn, x - prev);
                    }
                    prev = x;
                }
                result[i][j] = mn != numeric_limits<int>::max() ? mn : 0;
                if (j + 1 == size(grid[0]) - (k - 1)) {
                    continue;
                }
                for (int di = 0; di < k; ++di) {
                    bst2.erase(bst2.find(grid[i + di][j]));
                    bst2.emplace(grid[i + di][j + k]);
                }
            }
            if (i + 1 == size(grid) - (k-1)) {
                continue;
            }
            for (int dj = 0; dj < k; ++dj) {
                bst.erase(bst.find(grid[i][0 + dj]));
                bst.emplace(grid[i + k][0 + dj]);
            }
        }
        return result;
    }
};

// Time:  O(m * n * k^2 * logk)
// Space: O(k^2)
// brute force, sort
class Solution2 {
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
