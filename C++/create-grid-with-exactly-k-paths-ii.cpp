// Time:  O((logk)^2)
// Space: O(1)

// constructive algorithms
class Solution {
public:
    vector<string> createGrid(int k) {
        const auto& l = bit_width(static_cast<uint32_t>(k));
        const auto& m = 2 * l, &n = l + 3;
        vector<string> result(m, string(n, '#'));
        for (int i = 0; i < l; ++i) {
            const auto& r = 2 * i;
            result[r][i] = result[r][i + 1] = result[r + 1][i] = result[r + 1][i + 1] = '.';
            if (!(k & (1 << i))) {
                continue;
            }
            for (int c = i + 2; c < n; ++c) {
                result[r][c] = '.';
            }
        }
        for (int r = 0; r < m; ++r) {
            result[r][n - 1] = '.';
        }
        return result;
    }
};
