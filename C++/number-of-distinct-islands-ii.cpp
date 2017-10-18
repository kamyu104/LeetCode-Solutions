// Time:  ((m * n) * log(m * n))
// Space: (m * n)

class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        unordered_set<vector<pair<int, int>>, VectorHash> islands;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    vector<pair<int, int>> island;
                    if (dfs(i, j, &grid, &island)) {
                        islands.emplace(normalize(island));
                    }
                }
            }
        }
        return islands.size();
    }

private:
    struct VectorHash {
        size_t operator()(const std::vector<pair<int, int>>& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= std::hash<int>{}(i.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
                seed ^= std::hash<int>{}(i.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };

    bool dfs(const int i, const int j,
             vector<vector<int>> *grid, vector<pair<int, int>> *island) {
        
        static const vector<pair<int, int>> directions{{1, 0}, {-1, 0},
                                                       {0, 1}, {0, -1}};

        if (i < 0 || i >= grid->size() ||
            j < 0 || j >= (*grid)[0].size() ||
            (*grid)[i][j] <= 0) {
            return false;
        }
        (*grid)[i][j] *= -1;
        island->emplace_back(i, j);
        for (const auto& direction : directions) {
            dfs(i + direction.first, j + direction.second, grid, island);
        }
        return true;
    }
    
    vector<pair<int,int>> normalize(const vector<pair<int, int>>& island) {
        vector<vector<pair<int,int>>> shapes(8);
        for (const auto& p : island) {
            int x, y;
            tie(x, y) = p;
            vector<pair<int, int>> rotations_and_reflections{{ x,  y}, { x, -y}, {-x,  y}, {-x, -y},
                                                             { y,  x}, { y, -x}, {-y,  x}, {-y, -x}};
            for (int i = 0; i < rotations_and_reflections.size(); ++i) {
                shapes[i].emplace_back(rotations_and_reflections[i]);
            }
        }
        for (auto& shape : shapes) {
            sort(shape.begin(), shape.end());  // Time: O(ilogi), i is the size of the island, the max would be (m * n)
        }
        for (auto& shape : shapes) {
            const auto origin = shape.front();
            for (auto& p : shape) {
                p = {p.first  - origin.first,
                     p.second - origin.second};
            }
        }
        sort(shapes.begin(), shapes.end());
        return shapes.front();
    }
    
};
