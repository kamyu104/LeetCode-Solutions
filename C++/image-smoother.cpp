// Time:  O(m * n)
// Space: O(1)

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        const auto m = M.size(), n = M[0].size();
        vector<vector<int>> result(M);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                result[i][j] = getGray(M, i, j);
            }
        }
        return result;
    }

private:
    int getGray(const vector<vector<int>>& M, int i, int j) {
        const auto& m = M.size(), n = M[0].size();
        static const vector<pair<int, int>> directions = { {-1, -1}, {0, -1}, {1, -1},
                                                           {-1,  0}, {0,  0}, {1,  0},
                                                           {-1,  1}, {0,  1}, {1,  1} };
        double total = 0.0;
        int count = 0;
        for (const auto& direction : directions) {
            const auto& ii = i + direction.first;
            const auto& jj = j + direction.second;
            if (0 <= ii && ii < m && 0 <= jj && jj < n) {
                total += M[ii][jj];
                ++count;
            }
        }
        return static_cast<int>(total / count);
    }
};
