// Time:  O(n^2)
// Space: O(1)

// array
class Solution {
public:
    int findChampion(vector<vector<int>>& grid) {
        for (int u = 0; u < size(grid); ++u) {
            if (accumulate(cbegin(grid[u]), cend(grid[u]), 0) == size(grid[u]) - 1) {
                return u;
            }
        }
        return -1;
    }
};
