// Time:  O(m * n)
// Space: O(m * n)

class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        unordered_set<string> islands;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                string island;
                if (dfs(i, j, &grid, &island)) {
                    islands.emplace(island);
                }
            }
        }
        return islands.size();
    }

private:
    bool dfs(const int i, const int j,
             vector<vector<int>> *grid, string *island) {
        
        static const unordered_map<char, pair<int, int>>
            directions = { {'l', {-1,  0} }, {'r', { 1,  0} },
                           {'u', { 0,  1} }, {'d', { 0, -1} }};

        if (i < 0 || i >= grid->size() ||
            j < 0 || j >= (*grid)[0].size() ||
            (*grid)[i][j] <= 0) {
            return false;
        }
        (*grid)[i][j] *= -1;
        for (const auto& kvp : directions) {
            island->push_back(kvp.first);
            dfs(i + kvp.second.first, j +kvp.second.second, grid, island);
        }
        return true;
    }
};
