// Time:  O(m * n)
// Space: O(1)

// inplace rotation
class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = size(grid), n = size(grid[0]);
        const int count = min(m, n) / 2;
        for (int i = 0; i < count; ++i, m -= 2, n -= 2) {
            const int total = 2 * ((m - 1) + (n - 1));
            const int nk = k % total;
            const int num_cycles = gcd(total, nk);
            const int cycle_len = total / num_cycles;
            for (int offset = 0; offset < num_cycles; ++offset) {
                const auto& [r, c] = getIndex(m, n, offset);
                for (int j = 1; j < cycle_len; ++j) {
                    const auto& [nr, nc] = getIndex(m, n, (offset + j * nk) % total);
                    swap(grid[i + nr][i + nc], grid[i + r][i + c]);
                }
            }
        }
        return grid;
    }

private:
    pair<int, int> getIndex(int m, int n, int l) {
        if (l - (m - 1) < 0) {
            return {l, 0};
        }
        l -= (m - 1);
        if (l - (n - 1) < 0) {
            return {m - 1, l};
        }
        l -= (n - 1);
        if (l - (m - 1) < 0) {
            return {m - 1 - l, n - 1};
        }
        l -= (m - 1);
        return {0, n - 1 - l};
    }
};
