// Time:  O(m * nlogn + m * n^2 / 64 + n^2 / 64 + n^2) = O(m * n^2 / 64)
// Space: O(n^2 / 64)

// sort, prefix sum, binary search, dp, bitmasks
class Solution {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        static const int N = 250;

        vector<bitset<N>> lookup(size(grid[0]));
        for (auto& x : lookup) {
            x.set();
        }
        for (int i = 0; i < size(grid); ++i) {
            vector<int> idxs(size(grid[0]));
            iota(begin(idxs), end(idxs), 0);
            sort(begin(idxs), end(idxs), [&](const auto& a, const auto& b){
                return grid[i][a] < grid[i][b];
            });
            vector<int> arr(size(grid[0]));
            for (int j = 0; j < size(grid[0]); ++j) {
                arr[j] = grid[i][idxs[j]];
            }
            vector<bitset<N>> prefix(size(grid[0]) + 1);
            for (int j = 0; j < size(grid[0]); ++j) {
                prefix[j + 1] = prefix[j];
                prefix[j + 1][idxs[j]] = 1;
            }
            for (int j = 0; j < size(grid[0]); ++j) {
                lookup[j] &= prefix[distance(begin(arr), upper_bound(begin(arr), end(arr), grid[i][j] + limit))]
                           ^ prefix[distance(begin(arr), lower_bound(begin(arr), end(arr), grid[i][j] - limit))];
            }
        }
        vector<int> dp(size(grid[0]));
        for (int j = 0; j < size(grid[0]); ++j) {
            int mx = 0;
            for (int k = lookup[j]._Find_first(); k < j; k = lookup[j]._Find_next(k)) {
                mx = max(mx, dp[k]);
            }
            dp[j] = mx + 1;
        }
        return ranges::max(dp);
    }
};

// Time:  O(m * n^2)
// Space: O(n)
// dp
class Solution2 {
public:
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        vector<int> dp(size(grid[0]), 1);
        for (int i = 0; i < size(grid[0]); ++i) {
            for (int j = 0; j < i; ++j) {
                if (dp[j] + 1 <= dp[i]) {
                    continue;
                }
                if (all_of(cbegin(grid), cend(grid), [&](const auto& row) {
                    return abs(row[i] - row[j]) <= limit;
                })) {
                    dp[i] = dp[j] + 1;
                }
            }
        }
        return ranges::max(dp);
    }
};
