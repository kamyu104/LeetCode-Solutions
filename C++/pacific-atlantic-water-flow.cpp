// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }

        vector<pair<int, int>> res;
        const auto m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> visited(m, vector<int>(n));

        for (int i = 0; i < m; ++i) {
            pacificAtlanticHelper(matrix, i, 0, numeric_limits<int>::min(), PACIFIC, &visited, &res);
            pacificAtlanticHelper(matrix, i, n - 1, numeric_limits<int>::min(), ATLANTIC, &visited, &res);
        }
        for (int j = 0; j < n; ++j) {
            pacificAtlanticHelper(matrix, 0, j, numeric_limits<int>::min(), PACIFIC, &visited, &res);
            pacificAtlanticHelper(matrix, m - 1, j, numeric_limits<int>::min(), ATLANTIC, &visited, &res);
        }

        return res;
    }

private:
    void pacificAtlanticHelper(const vector<vector<int>>& matrix, int x, int y, int prev_height, int prev_val,
                               vector<vector<int>> *visited, vector<pair<int, int>> *res) {

        if (x < 0 || x >= matrix.size() ||
            y < 0 || y >= matrix[0].size() ||
            matrix[x][y] < prev_height || ((*visited)[x][y] | prev_val) == (*visited)[x][y]) {
            return;
        }

        (*visited)[x][y] |= prev_val;
        if ((*visited)[x][y] == (PACIFIC | ATLANTIC)) {
            res->emplace_back(x, y);
        }

        for (const auto& dir : directions) {
            pacificAtlanticHelper(matrix, x + dir.first, y + dir.second, matrix[x][y], (*visited)[x][y], visited, res);
        }
    }
    
    enum ocean { PACIFIC = 1, ATLANTIC = 2 };
    const vector<pair<int, int>> directions{ {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
};
