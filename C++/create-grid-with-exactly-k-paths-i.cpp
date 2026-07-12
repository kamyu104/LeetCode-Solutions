// Time:  O(m * n)
// Space: O(1)

// constructive algorithms
class Solution {
public:
    vector<string> createGrid(int m, int n, int k) {
        static const vector<vector<vector<string>>> PATTERNS = {
            {},
            {{"."}},
            {{"..", ".."}},
            {{"..", "..", ".."}, {"...", "..."}},
            {{"..", "..", "..", ".."}, {"....", "...."}, {"..#", "...", "#.."}},
        };

        for (const auto& p : PATTERNS[k]) {
            if (!(size(p) <= m && size(p[0]) <= n)) {
                continue;
            }
            vector<string> result(m, string(n, '#'));
            for (int i = 0; i < size(p); ++i) {
                for (int j = 0; j < size(p[0]); ++j) {
                    result[i][j] = p[i][j];
                }
            }
            for (int i = size(p); i < m; ++i) {
                result[i][size(p[0]) - 1] = '.';
            }
            for (int j = size(p[0]); j < n; ++j) {
                result[m - 1][j] = '.';
            }
            return result;
        }
        return {};
    }
};
