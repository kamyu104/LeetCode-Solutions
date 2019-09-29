// Time:  O(n)
// Space: O(n)

class Solution {
private:
    template <typename A, typename B, typename C>
    struct TupleHash {
        size_t operator()(const tuple<A, B, C>& p) const {
            size_t seed = 0;
            A a; B b; C c;
            tie(a, b, c) = p;
            seed ^= std::hash<A>{}(a) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<B>{}(b) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<C>{}(c) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

public:
    int minimumMoves(vector<vector<int>>& grid) {
        int level = 0;
        vector<tuple<int, int, bool>> q = {{0, 0, false}};
        unordered_set<tuple<int, int, bool>, TupleHash<int, int, bool>> lookup;
        while (!q.empty()) {
            vector<tuple<int, int, bool>> next_q;
            for (const auto& [r, c, is_vertical] : q) {
                if (lookup.count(make_tuple(r, c, is_vertical))) {
                    continue;
                }
                if (make_tuple(r, c, is_vertical) == 
                    make_tuple(grid.size() - 1, grid.size() - 2, false)) {
                    return level;
                }
                lookup.emplace(r, c, is_vertical);
                if (!is_vertical) {
                    if (c + 2 != grid[0].size() && grid[r][c + 2] == 0) {
                        next_q.emplace_back(r, c + 1, is_vertical);
                    }
                    if (r + 1 != grid.size() &&
                        grid[r + 1][c] == 0 && grid[r + 1][c + 1] == 0) {
                        next_q.emplace_back(r + 1, c, is_vertical);
                        next_q.emplace_back(r, c, !is_vertical);
                    }
                } else {
                    if (r + 2 != grid.size() && grid[r + 2][c] == 0) {
                        next_q.emplace_back(r + 1, c, is_vertical);
                    }
                    if (c + 1 != grid[0].size() &&
                        grid[r][c + 1] == 0 && grid[r + 1][c + 1] == 0) {
                        next_q.emplace_back(r, c + 1, is_vertical);
                        next_q.emplace_back(r, c, !is_vertical);
                    }
                }
            }
            q = move(next_q);
            ++level;
        }
        return -1;
    }
};
