// Time:  O(r * c)
// Space: O(r * c)

class Solution {
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        static const vector<pair<int, int>> directions{{-1,  0}, { 1,  0},
                                                       { 0,  1}, { 0, -1}};
        const int R = grid.size();
        const int C = grid[0].size();
        const auto index = [&C](int r, int c) { return r * C + c; };

        vector<vector<int>> hit_grid(grid);
        for (const auto& hit : hits) {
            hit_grid[hit[0]][hit[1]] = 0;
        }

        UnionFind union_find(R * C);
        for (int r = 0; r < hit_grid.size(); ++r) {
            for (int c = 0; c < hit_grid[r].size(); ++c) {
                if (!hit_grid[r][c]) {
                    continue;
                }
                if (r == 0) {
                    union_find.union_set(index(r, c), R * C);
                }
                if (r && hit_grid[r - 1][c]) {
                    union_find.union_set(index(r, c), index(r - 1, c));
                }
                if (c && hit_grid[r][c - 1]) {
                    union_find.union_set(index(r, c), index(r, c - 1));
                }
            }
        }

        vector<int> result;
        for (int i = hits.size() - 1; i >= 0; --i) {
            const auto r = hits[i][0], c = hits[i][1];
            const auto prev_roof = union_find.top();
            if (grid[r][c] == 0) {
                result.emplace_back(0);
                continue;
            }
            for (const auto& d : directions) {
                const auto nr = r + d.first, nc = c + d.second;
                if (0 <= nr && nr < R &&
                    0 <= nc && nc < C &&
                    hit_grid[nr][nc]) {
                    union_find.union_set(index(r, c), index(nr, nc));
                }
            }
            if (r == 0) {
                union_find.union_set(index(r, c), R * C);
            }
            hit_grid[r][c] = 1;
            result.emplace_back(max(0, union_find.top() - prev_roof - 1));
        }
        reverse(result.begin(), result.end());
        return result;
    }

private:
    class UnionFind {
        public:
            UnionFind(const int n) : set_(n + 1), size_(n + 1, 1) {
                iota(set_.begin(), set_.end(), 0);
                size_.back() = 0;
            }

            int find_set(const int x) {
               if (set_[x] != x) {
                   set_[x] = find_set(set_[x]);  // Path compression.
               }
               return set_[x];
            }

            bool union_set(const int x, const int y) {
                int x_root = find_set(x), y_root = find_set(y);
                if (x_root == y_root) {
                    return false;
                }
                set_[min(x_root, y_root)] = max(x_root, y_root);
                size_[max(x_root, y_root)] += size_[min(x_root, y_root)];
                return true;
            }

            int top() {
                return size_[find_set(size_.size() - 1)];
            }

        private:
            vector<int> set_;
            vector<int> size_;
    };
};
