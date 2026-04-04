// Time:  O(m * n)
// Space: O(k * n)

// sliding window, difference array, greedy
class Solution {
public:
    long long minOperations(vector<vector<int>>& grid, int k) {
        int64_t c = 0, target = 0, mn = numeric_limits<int64_t>::min();
        bool found = false;
        vector<vector<int64_t>> lookup(k, vector<int64_t>(size(grid[0])));
        vector<int64_t> cnt(size(grid[0]));
        for (int i = 0; i < size(grid); ++i) {
            int64_t total = 0;
            for (int j = 0; j < size(grid[0]); ++j) {
                total += cnt[j];
                const auto& diff = -(grid[i][j] + total);  // grid[i][j]+total+diff = target
                if (i + k - 1 < size(grid) && j + k - 1 < size(grid[0])) {
                    lookup[i % k][j] = diff;
                    cnt[j] += diff;
                    total += diff;
                    c += diff;
                    if (i % k == 0 && j % k == 0) {  // target+diff >= 0, target >= -diff
                        mn = max(mn, -diff);
                    } else if (diff < 0) {  // diff >= 0
                        return -1;
                    }
                } else {
                    if ((i / k + 1) * k <= size(grid) && (j / k + 1) * k <= size(grid[0])) {
                        if (diff) {
                            return -1;
                        }
                    } else {
                        if (!found) {
                            found = true;
                            target = -diff;
                        } else if (target != -diff) {
                            return -1;
                        }
                    }
                }
                if (j - k + 1 >= 0) {
                    total -= cnt[j - k + 1];
                }
            }
            if (i - k + 1 >= 0) {
                for (int j = 0; j < size(grid[0]); ++j) {
                    cnt[j] -= lookup[(i - k + 1) % k][j];
                    lookup[(i - k + 1) % k][j] = 0;
                }
            }
        }
        if (!found) {
            target = mn;
        } else if (target < mn) {
            return -1;
        }
        return c + target * ((size(grid) / k) * (size(grid[0]) / k));
    }
};
