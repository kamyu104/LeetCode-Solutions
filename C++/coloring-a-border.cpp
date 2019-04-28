// Time:  O(m * n)
// Space: O(m + n)

class Solution {
public:
    template <typename T>
    struct PairHash {
        size_t operator()(const pair<T, T>& p) const {
            size_t seed = 0;
            seed ^= std::hash<T>{}(p.first)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<T>{}(p.second) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
        static const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                       {-1, 0}, {1, 0}};
        vector<pair<int, int>> borders;
        unordered_set<pair<int, int>, PairHash<int>> lookup{make_pair(r0, c0)};
	    queue<pair<int, int>> q({make_pair(r0, c0)});
        while (!q.empty()) {
            int r, c;
            tie(r, c) = q.front();  q.pop();
            bool is_border = false;

            for (const auto& dir : directions) {
                const auto nr = r + dir.first, nc = c + dir.second;
                if (!((0 <= nr && nr < grid.size()) &&
                      (0 <= nc && nc < grid[0].size()) &&
                      grid[nr][nc] == grid[r][c])) {
                    is_border = true;
                    continue;
                }
                if (lookup.count(make_pair(nr, nc))) {
                    continue;
                }
                lookup.emplace(nr, nc);
                q.emplace(nr, nc);
            }

            if (is_border) {
                borders.emplace_back(r, c);
            }
        }

        for (const auto& border : borders) {
            grid[border.first][border.second] = color;
        }
        return grid;
    }
};
