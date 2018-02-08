// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> positions(m * n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                positions[grid[i][j]] = {i, j};
            }
        }
        static const vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        UnionFind union_find(m * n);
        for (int elevation = 0; elevation < positions.size(); ++elevation) {
            int i, j;
            tie(i, j) = positions[elevation];
            for (const auto& dir : directions) {
                int x = i + dir.first;
                int y = j + dir.second;
                if (0 <= x && x < m &&
                    0 <= y && y < n &&
                    grid[x][y] <= elevation) {
                    union_find.union_set(i * n + j, x * n + y);
                    if (union_find.find_set(0) == union_find.find_set(m * n - 1)) {
                        return elevation;
                    }
                }
            }
        }
        return m * n - 1;
    }

private:
    class UnionFind {
    public:
        UnionFind(const int n) : set_(n) {
            iota(set_.begin(), set_.end(), 0);
        }
        
        int find_set(const int x) {
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
        }

        void union_set(const int x, const int y) {
            int x_root = find_set(x), y_root = find_set(y);
            if (x_root != y_root) {
                set_[min(x_root, y_root)] = max(x_root, y_root);
            }
        }

    private:
        vector<int> set_;
    };
};
