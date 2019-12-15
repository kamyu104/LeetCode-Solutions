// Time:  O(m * n * k)
// Space: O(m * n)

// A* Search Algorithm without heap
class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        pair<int, int> b = {0, 0};
        pair<int, int> t = {grid.size() - 1, grid[0].size() - 1}; 
        return a_star(grid, b, t, k);
    }

private:
    int a_star(const vector<vector<int>>& grid,
               const pair<int, int>& b,
               const pair<int, int>& t,
               int k) {

        int f = g(b, t), dh = 2;
        vector<pair<pair<int, int>, int>> closer{{b, k}}, detour;
        unordered_map<int, int> lookup;
        while (!closer.empty() || !detour.empty()) {
            if (closer.empty()) {
                f += dh;
                swap(closer, detour);
            }
            const auto [b, k] = closer.back(); closer.pop_back();
            if (b == t) {
                return f;
            }
            if (lookup.count(b.first * grid[0].size() + b.second) &&
                lookup[b.first * grid[0].size() + b.second] >= k) {
                continue;
            }
            lookup[b.first * grid[0].size() + b.second] = k;
            for (const auto& [dx, dy] : directions) {
                pair<int, int> nb = {b.first + dx, b.second + dy};
                if (!(0 <= nb.first && nb.first < grid.size() &&
                      0 <= nb.second && nb.second < grid[0].size() &&
                      (grid[nb.first][nb.second] == 0 || k > 0) &&
                      (!lookup.count(nb.first * grid[0].size() + nb.second) ||
                       lookup[nb.first * grid[0].size() + nb.second] < k))) {
                    continue;
                }
                if (dot({dx, dy}, {t.first - b.first, t.second - b.second}) > 0) {
                    closer.emplace_back(nb, k - int(grid[nb.first][nb.second] != 0));
                } else {
                    detour.emplace_back(nb, k - int(grid[nb.first][nb.second] != 0));
                }
            }
        }
        return -1;
    }
    
    inline int g(const pair<int, int>& a,
                 const pair<int, int>& b) {
        return abs(a.first - b.first) + abs(a.second - b.second);
    }
    
    inline int dot(const pair<int, int>& a,
                   const pair<int, int>& b) {
        return a.first * b.first + a.second * b.second;
    }
    
    static const vector<pair<int, int>> directions;
};

const vector<pair<int, int>> Solution::directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
