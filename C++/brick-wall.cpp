// Time:  O(n), n is the total number of the bricks
// Space: O(m), m is the total number different widths

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> widths;
        auto result = wall.size();
        for (const auto& row : wall) {
            for (auto i = 0, width = 0; i < row.size() - 1; ++i) {
                result = min(result, wall.size() - (++widths[width += row[i]]));
            }
        }
        return result;
    }
};
