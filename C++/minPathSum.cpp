// Time Complexity: O(mn)
// Space Complexity: O(mn)

class Solution {
    public:
        unordered_map<int, unordered_map<int, int> > hash;
        int minPathSumeImpl(vector<vector<int> > &grid, int i, int j) {
            if(hash.find(i) != hash.end() && hash[i].find(j) != hash[j].end()) 
                return hash[i][j];
            if(i == 0 && j == 0)
                return grid[i][j];
            if(i < 0 || j < 0)
                return INT_MAX;
            return hash[i][j] = grid[i][j] + min(minPathSumeImpl(grid, i-1, j), minPathSumeImpl(grid, i, j-1));
        }

        int minPathSum(vector<vector<int> > &grid) {
            return minPathSumeImpl(grid, grid.size()-1, grid[0].size()-1);
        }
};
