// Time:  O(4^n)
// Space: O(1)

// array
class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        const int total = 1 << n;
        vector<vector<int>> result(total, vector<int>(total));
        const auto& copy = [&](int l, int r1, int c1, int r2, int c2) {
            for (int i = 0; i < l; ++i) {
                for (int j = 0; j < l; ++j) {
                    result[r2 + i][c2 + j] = result[r1 + i][c1 + j] + l * l;
                }
            }
        };

        for (int i = 0, l = 1; i < n; ++i, l <<= 1) {
            int r = 0, c = total - l;
            for (const auto& [dr, dc] : vector<pair<int, int>>{{l, 0}, {0, -l}, {-l, 0}}) {
                const int nr = r + dr, nc = c + dc;
                copy(l, r, c, nr, nc);
                tie(r, c) = pair(nr, nc);
            }
        }
        return result;
    }
};

// Time:  O(4^n)
// Space: O(n)
// divide and conquer
class Solution2 {
public:
    vector<vector<int>> specialGrid(int n) {
        const int total = 1 << n;
        vector<vector<int>> result(total, vector<int>(total));
        int idx = 0;
        const function<void (int, int, int)> divide_and_conquer = [&](int l, int r, int c) {
            if (l == 1) {
                result[r][c] = idx++;
                return;
            }
            l >>= 1;
            for (const auto& [dr, dc] : vector<pair<int, int>>{{0, l}, {l, 0}, {0, -l}, {-l, 0}}) {
                r += dr;
                c += dc;
                divide_and_conquer(l, r, c);
            }
        };

        divide_and_conquer(total, 0, 0);
        return result;
    }
};
