// Time:  O(r * c)
// Space: O(1)

class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        int R = A.size();
        int C = A[0].size();
        int result = 0;
        for (int c = 0; c < C; ++c) {
            int col = 0;
            for (int r = 0; r < R; ++r) {
                col += A[r][c] ^ A[r][0];
            }
            result += max(col, R - col) * (1 << (C - 1 - c));
        }
        return result;
    }
};
