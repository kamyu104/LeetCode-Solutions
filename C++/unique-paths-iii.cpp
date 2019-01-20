// Time:  O(m * n * 2^(m * n))
// Space: O(m * n * 2^(m * n))

class Solution {
private:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
    using Lookup = unordered_map<pair<int, int>, int, PairHash<int>>;

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int todo = 0;
        pair<int, int> src, dst;
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (grid[r][c] % 2 == 0) {
                    todo |= index(grid, r, c);
                }
                if (grid[r][c] == 1) {
                    src = make_pair(r, c);
                } else if (grid[r][c] == 2) {
                    dst = make_pair(r, c);
                }
            }
        }
        Lookup lookup;
        return dp(grid, src, dst, todo, &lookup);
    }
    
private:
    int dp(const vector<vector<int>>& grid,
           const pair<int, int>& src,
           const pair<int, int>& dst,
           int todo,
           Lookup *lookup) {
        if (src == dst) {
            return (todo == 0);
        }
        const auto& key = make_pair(index(grid, src.first, src.second), todo);
        if (lookup->count(key)) {
            return (*lookup)[key];
        }

        static const vector<pair<int, int>> directions = 
            {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int result = 0;
        for (const auto& d : directions) {
            int r = src.first + d.first, c = src.second + d.second;
            if (0 <= r && r < grid.size() &&
                0 <= c && c < grid[0].size() &&
                grid[r][c] % 2 == 0 && 
                todo & index(grid, r, c)) {

                result += dp(grid, make_pair(r, c), dst,
                             todo ^ index(grid, r, c), lookup);
            }
        }

        (*lookup)[key] = result;
        return (*lookup)[key];
    }
    
    int index(const vector<vector<int>>& grid, int r, int c) {
        return 1 << (r * grid[0].size() + c);
    }
};
