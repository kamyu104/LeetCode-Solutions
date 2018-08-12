// Time:  O(max(m, n)^2)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        int r = r0, c = c0;
        vector<vector<int>> result = {{r, c}};
        int x = 0, y = 1, i = 0, n = 0;
        while (result.size() < R * C) {
            r += x, c += y, ++i;
            if (0 <= r && r < R && 0 <= c && c < C) {
                result.push_back({r, c});
            }
            if (i == n / 2 + 1) {
                swap(x, y), y *= -1, ++n, i = 0;
            }
        }
        return result;
    }
};
