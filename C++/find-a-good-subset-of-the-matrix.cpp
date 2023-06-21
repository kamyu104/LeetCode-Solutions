// Time:  O(m * 2^n)
// Space: O(2^n)

// bitmasks, constructive algorithms, greedy
class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        unordered_map<int, int> lookup;
        for (int i = 0; i < size(grid); ++i) {
            int mask = 0;
            for (int j = 0; j < size(grid[0]); ++j) {
                mask |= grid[i][j] << j;
            }
            if (!mask) {
                return {i};
            }
            for (const auto& [mask2, j] : lookup) {
                if ((mask2 & mask) == 0) {
                    return {j, i};
                }
            }
            lookup[mask] = i;
        }
        return {};
    }
};
