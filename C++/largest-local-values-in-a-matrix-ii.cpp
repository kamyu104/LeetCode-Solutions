// Time:  O(n * m * logn * logm)
// Space: O(n * m * logn * logm)

// 2d sparse table
class Solution {
public:
    int countLocalMaximums(vector<vector<int>>& matrix) {
        const int n = size(matrix);
        const int m = size(matrix[0]);
        SparseTable2D st(matrix, [](const auto& x, const auto& y) {
            return x < y ? y : x;
        });

        int result = 0;
        for (int r = 0; r < n; ++r) {
            const auto& row = matrix[r];
            for (int c = 0; c < m; ++c) {
                const auto& x = row[c];
                if (x == 0) {
                    continue;
                }
                const auto& r1 = max(r - x, 0);
                const auto& r2 = min(r + x, n - 1);
                const auto& c1 = max(c - x, 0);
                const auto& c2 = min(c + x, m - 1);
                const auto& tl = r - x >= 0 && c - x >= 0;
                const auto& tr = r - x >= 0 && c + x <= m - 1;
                const auto& bl = r + x <= n - 1 && c - x >= 0;
                const auto& br = r + x <= n - 1 && c + x <= m - 1;
                const auto& topX = tl || tr, botX = bl || br;
                if (max(st.query(r1, c1 + (tl || bl ? 1 : 0), r2, c2 - (tr || br ? 1 : 0)),
                        st.query(r1 + (tl || tr ? 1 : 0), c1, r2 - (bl || br ? 1 : 0), c2)) <= x) {
                    ++result;
                }
            }
        }
        return result;
    }

private:
    // Reference: https://cp-algorithms.com/data_structures/sparse-table.html
    class SparseTable2D {
    public:
        // Time: O(n * m * log(n) * log(m)) * O(fn), Space: O(n * m * log(n) * log(m))
        SparseTable2D(const vector<vector<int>>& matrix, function<int(int, int)> fn)
        : fn(fn) {
            const auto& n = size(matrix);
            const auto& m = size(matrix[0]);
            const auto& logn = __lg(n);
            const auto& logm = __lg(m);
            st.assign(logn + 1, vector<vector<vector<int>>>(logm + 1, vector<vector<int>>(n, vector<int>(m))));            
            for (int r = 0; r < n; ++r) {
                for (int c = 0; c < m; ++c) {
                    st[0][0][r][c] = matrix[r][c];
                }
            }
            for (int j = 1; j <= logm; ++j) {
                for (int r = 0; r < n; ++r) {
                    for (int c = 0; c + (1 << j) <= m; ++c) {
                        st[0][j][r][c] = fn(st[0][j - 1][r][c], st[0][j - 1][r][c + (1 << (j - 1))]);
                    }
                }
            }            
            for (int i = 1; i <= logn; ++i) {
                for (int j = 0; j <= logm; ++j) {
                    for (int r = 0; r + (1 << i) <= n; ++r) {
                        for (int c = 0; c + (1 << j) <= m; ++c) {
                            st[i][j][r][c] = fn(st[i - 1][j][r][c], st[i - 1][j][r + (1 << (i - 1))][c]);
                        }
                    }
                }
            }
        }
        
        int query(int r1, int c1, int r2, int c2) const {
            const int i = __lg(r2 - r1 + 1);
            const int j = __lg(c2 - c1 + 1);
            return fn(
                fn(st[i][j][r1][c1], st[i][j][r1][c2 - (1 << j) + 1]),
                fn(st[i][j][r2 - (1 << i) + 1][c1], st[i][j][r2 - (1 << i) + 1][c2 - (1 << j) + 1])
            );
        }

    private:
        vector<vector<vector<vector<int>>>> st;
        const function<int(int, int)> fn;
    };
};
