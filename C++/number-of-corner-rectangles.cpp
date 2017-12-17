// Time:  O(m^2 * n), m is the number of rows with 1s, n is the number of cols with 1s
// Space: O(m * n)

class Solution {
public:
    int countCornerRectangles(vector<vector<int>>& grid) {
        vector<vector<int>> rows;
        for (int i = 0; i < grid.size(); ++i) {
            vector<int> row;
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j]) {
                    row.emplace_back(j);
                }
            }
            if (!row.empty()) {
                rows.emplace_back(move(row));
            }
        }
        int result = 0;
        for (int i = 0; i < rows.size(); ++i) {
            unordered_set<int> lookup(rows[i].begin(), rows[i].end());
            for (int j = 0; j < i; ++j) {
                int count = 0;
                for (const auto& c : rows[j]) {
                    count += lookup.count(c);
                }
                result += count * (count - 1) / 2;
            }
        }
        return result;
    }
};
