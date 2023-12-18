// Time:  O(n^2)
// Space: O(1)

// bit manipulation
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const int n = size(grid);
        int a_xor_b = 0;
        for (int i = 0; i < n * n; ++i) {
            const int r = i / n, c = i % n;
            a_xor_b ^= grid[r][c] ^ (i + 1);
        }
        const int base = a_xor_b & -a_xor_b;
        vector<int> result(2);
        for (int i = 0; i < n * n; ++i) {
            const int r = i / n, c = i % n;
            result[((i + 1) & base) != 0 ? 1 : 0] ^= i + 1;
            result[(grid[r][c] & base) != 0 ? 1 : 0] ^= grid[r][c];
        }
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == result[1]) {
                    swap(result[0], result[1]);
                    return result;
                }
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n^2)
// freq table
class Solution2 {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        const int n = size(grid);
        vector<int> cnt(n * n);
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                ++cnt[grid[r][c] - 1];
            }
        }
        vector<int> result(2);
        for (int i = 0; i < n * n; ++i) {
            if (cnt[i] == 2) {
                result[0] = i + 1;
            } else if (cnt[i] == 0) {
                result[1] = i + 1;
            }
        }
        return result;
    }
};
