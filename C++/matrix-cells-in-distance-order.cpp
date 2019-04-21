// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> result{{r0, c0}};
        for (auto d = 1; d < R + C; ++d) {
            append(R, C, r0 - d, c0, &result);
            for (int x = -d + 1; x < d; ++x) {
                append(R, C, r0 + x, c0 + d - abs(x), &result);
                append(R, C, r0 + x, c0 + abs(x) - d, &result);
            }
            append(R, C, r0 + d, c0, &result);
         }
         return result;
    }
    
private:
    void append(int R, int C, int r, int c,
                vector<vector<int>> *result) {
        if (0 <= r && r < R && 0 <= c && c < C) {
            result->emplace_back(vector<int>{r, c});
        }
    }
};
