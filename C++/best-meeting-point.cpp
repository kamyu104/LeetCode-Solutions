// Time:  O(m * n)
// Space: O(m + n)

class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        vector<int> x, y;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    x.emplace_back(i);
                    y.emplace_back(j);
                }
            }
        }
        nth_element(x.begin(), x.begin() + x.size() / 2, x.end());
        nth_element(y.begin(), y.begin() + y.size() / 2, y.end());
        const int mid_x = x[x.size() / 2];
        const int mid_y = y[y.size() / 2];
        int sum = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j]) {
                    sum += abs(mid_x - i) + abs(mid_y - j);
                }
            }
        }
        return sum;
    }
};
