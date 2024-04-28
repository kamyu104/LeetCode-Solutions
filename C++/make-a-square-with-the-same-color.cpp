// Time:  O((n - w + 1)^2 * w^2)
// Space: O(1)

// array
class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& grid) {
        static const int N = 3, W = 2;

        for (int i = 0; i < N - W + 1; ++i) {
            for (int j = 0; j < N - W + 1; ++j) {
                vector<int> cnt(2);
                for (int h = 0; h < W; ++h) {
                    for (int w = 0; w < W; ++w) {
                        ++cnt[grid[i + h][j + w] == 'W' ? 0 : 1];
                    }
                }
                if (ranges::max(cnt) >= W * W - 1) {
                    return true;
                }
            }
        }
        return false;
    }
};
