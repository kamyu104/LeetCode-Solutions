// Time:  O(n * m)
// Space: O(n * m)

// z-function
class Solution {
public:
    int countCells(vector<vector<char>>& grid, const string& pattern) {
        // Template: https://cp-algorithms.com/string/z-function.html
        const auto& z_function = [](const string& s) {  // Time: O(n), Space: O(n)
            vector<int> z(size(s));
            for (int i = 1, l = 0, r = 0; i < size(z); ++i) {
                if (i <= r) {
                    z[i] = min(r - i + 1, z[i - l]);
                }
                while (i + z[i] < size(z) && s[z[i]] == s[i + z[i]]) {
                    ++z[i];
                }
                if (i + z[i] - 1 > r) {
                    l = i, r = i + z[i] - 1;
                }
            }
            return z;
        };
    
        const auto& check = [&](bool is_horizontal) {
            int n = size(grid), m = size(grid[0]);
            if (!is_horizontal) {
                swap(n, m);
            }
            const int p = size(pattern);
            string s = pattern;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < m; ++j) {
                    s.push_back(is_horizontal ? grid[i][j] : grid[j][i]);
                }
            }
            vector<vector<bool>> lookup(n, vector<bool>(m));
            vector<int> z = z_function(s);
            for (int i = p, curr = 0 - p; i < size(s); ++i) {
                if (z[i] < p) {
                    continue;
                }
                curr = max(curr, i - p);
                for (; curr <= (i - p) + p - 1; ++curr) {
                    lookup[curr / m][curr % m] = true;
                }
            }
            return lookup;
        };
    
        const auto& lookup1 = check(true);
        const auto& lookup2 = check(false);
        int result = 0;
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (lookup1[i][j] && lookup2[j][i]) {
                    ++result;
                }
            }
        }
        return result;
    }
};
