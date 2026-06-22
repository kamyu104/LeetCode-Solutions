// Time:  O(m * n)
// Space: O(1)

// array
class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result(m, string(n, '#'));
        for (int j = 0; j < n; ++j) {
            result[0][j] = '.';
        }
        for (int i = 0; i < m; ++i) {
            result[i][n - 1] = '.';
        }
        return result;
    }
};
