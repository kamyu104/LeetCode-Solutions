// Time:  O(m * n)
// Space: O(1)

// array
class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        const auto& length = [](int x) {
            int l = 1;
            if (x < 0) {
                x = -x;
                ++l;
            }
            for (; x  >= 10; x /= 10, ++l);
            return l;
        };

        vector<int> result(size(grid[0]), numeric_limits<int>::min());
        for (int j = 0; j < size(grid[0]); ++j) {
            for (int i = 0; i < size(grid); ++i) {
                result[j] = max(result[j], length(grid[i][j]));
            }
        }
        return result;
    }
};

// Time:  O(m * n)
// Space: O(logr)
// array
class Solution2 {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        vector<int> result(size(grid[0]), numeric_limits<int>::min());
        for (int j = 0; j < size(grid[0]); ++j) {
            for (int i = 0; i < size(grid); ++i) {
                result[j] = max(result[j], static_cast<int>(size(to_string(grid[i][j]))));
            }
        }
        return result;
    }
};
