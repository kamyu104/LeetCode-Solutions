// Time:  O(m^2 * n^2)
// Space: O(m^2 * n^2)

// A* Search Algorithm without heap
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
    
    int minPushBox(vector<vector<char>>& grid) {
        pair<int, int> b, p, t;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 'B') {
                    b = {i, j};
                } else if (grid[i][j] == 'S') {
                    p = {i, j};
                } else if (grid[i][j] == 'T') {
                    t = {i, j};
                }
            }
        }
        return a_star(grid, b, p, t);
    }

private:
    int a_star(const vector<vector<char>>& grid,
               const pair<int, int>& b,
               const pair<int, int>& p,
               const pair<int, int>& t) {

        int f = g(b, t), dh = 2;
        vector<pair<pair<int, int>, pair<int, int>>> closer{{b, p}}, detour;
        unordered_set<pair<int, int>, PairHash<int>> lookup;
        while (!closer.empty() || !detour.empty()) {
            if (closer.empty()) {
                f += dh;
                swap(closer, detour);
            }
            const auto [b, p] = closer.back(); closer.pop_back();
            if (b == t) {
                return f;
            }
            if (lookup.count({b.first * grid[0].size() + b.second,
                              p.first * grid[0].size() + p.second})) {
                continue;
            }
            lookup.emplace(b.first * grid[0].size() + b.second,
                           p.first * grid[0].size() + p.second);
            for (const auto& [dx, dy] : directions) {
                pair<int, int> nb = {b.first + dx, b.second + dy}, np = {b.first - dx, b.second - dy};
                if (!(0 <= nb.first && nb.first < grid.size() &&
                      0 <= nb.second && nb.second < grid[0].size() &&
                      0 <= np.first && np.first < grid.size() &&
                      0 <= np.second && np.second < grid[0].size() &&
                      grid[nb.first][nb.second] != '#' && grid[np.first][np.second] != '#' &&
                      !lookup.count({nb.first * grid[0].size() + nb.second,
                                     b.first * grid[0].size() + b.second}) &&
                      can_reach(grid, b, p, np))) {
                    continue;
                }
                if (dot({dx, dy}, {t.first - b.first, t.second - b.second}) > 0) {
                    closer.emplace_back(nb, b);
                } else {
                    detour.emplace_back(nb, b);
                }
            }
        }
        return -1;
    }
    
    inline int g(const pair<int, int>& a,
                 const pair<int, int>& b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }
    
    int can_reach(const vector<vector<char>>& grid,
                  const pair<int, int>& b,
                  const pair<int, int>& p,
                  const pair<int, int>& t) {
        
        vector<pair<int, int>> closer{p}, detour;
        unordered_set<int> lookup = {b.first * grid[0].size() + b.second};
        while (!closer.empty() || !detour.empty()) {
            if (closer.empty()) {
                swap(closer, detour);
            }
            auto p = closer.back(); closer.pop_back();
            if (p == t) {
                return true;
            }
            if (lookup.count(p.first * grid[0].size() + p.second)) {
                continue;
            }
            lookup.emplace(p.first * grid[0].size() + p.second);
            for (const auto& [dx, dy] : directions) {
                pair<int, int> np = {p.first + dx, p.second + dy};
                if (!(0 <= np.first && np.first < grid.size() &&
                      0 <= np.second && np.second < grid[0].size() &&
                      grid[np.first][np.second] != '#' &&
                      !lookup.count(np.first * grid[0].size() + np.second))) {
                    continue;
                }
                if (dot({dx, dy}, {t.first - p.first, t.second - p.second}) > 0) {
                    closer.emplace_back(np);
                } else {
                    detour.emplace_back(np);
                }
            }
        }
        return false;
    }
    
    inline int dot(const pair<int, int>& a,
                   const pair<int, int>& b) {
        return a.first * b.first + a.second * b.second;
    }
    
    static const vector<pair<int, int>> directions;
};

const vector<pair<int, int>> Solution::directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
