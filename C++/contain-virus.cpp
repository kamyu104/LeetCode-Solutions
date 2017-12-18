// Time:  O((m * n)^(4/3)), days = O((m * n)^(1/3))
// Space: O(m * n)

class Solution {
public:    
    int containVirus(vector<vector<int>>& grid) {
        int result = 0;
        while (true) {
            P_SET lookup;
            vector<P_SET> regions, frontiers;
            vector<int> perimeters;
            for (int r = 0; r < grid.size(); ++r) {
                for (int c = 0; c < grid[r].size(); ++c) {
                    const auto& p = make_pair(r, c);
                    if (grid[r][c] == 1 && lookup.count(p) == 0) {
                        regions.emplace_back();
                        frontiers.emplace_back();
                        perimeters.emplace_back();
                        dfs(grid, p, &lookup, &regions, &frontiers, &perimeters);
                    }
                }
            }
            if (regions.empty()) {
                break;
            }
            
            int triage_idx = 0;
            for (int i = 0; i < frontiers.size(); ++i) {
                if (frontiers[i].size() > frontiers[triage_idx].size()) {
                    triage_idx = i;
                }
            }
            for (int i = 0; i < regions.size(); ++i) {
                if (i == triage_idx) {
                    result += perimeters[i];
                    for (const auto& p : regions[i]) {
                        grid[p.first][p.second] = -1;
                    }
                    continue;
                }
                for (const auto& p : regions[i]) {
                    for (const auto& d : directions) {
                        int nr = p.first + d.first;
                        int nc = p.second + d.second;
                        if (nr < 0 || nr >= grid.size() ||
                            nc < 0 || nc >= grid[nr].size()) {
                            continue;
                        }
                        if (grid[nr][nc] == 0) {
                            grid[nr][nc] = 1;
                        }
                    }
                }
            }
        }

        return result;
    }
    
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
    using P = pair<int, int>;
    using P_SET = unordered_set<P, PairHash<int>>;
    
    void dfs(const vector<vector<int>>& grid, 
             const P& p,
             P_SET *lookup,
             vector<P_SET> *regions,
             vector<P_SET> *frontiers, 
             vector<int> *perimeters) {
        
        if (lookup->count(p)) {
            return;
        }
        lookup->emplace(p);
        regions->back().emplace(p);
        for (const auto& d : directions) {
            int nr = p.first + d.first;
            int nc = p.second + d.second;
            if (nr < 0 || nr >= grid.size() ||
                nc < 0 || nc >= grid[nr].size()) {
                continue;
            }
            if (grid[nr][nc] == 1) {
                dfs(grid, make_pair(nr, nc), lookup, regions, frontiers, perimeters);
            } else if (grid[nr][nc] == 0) {
                frontiers->back().emplace(nr, nc);
                ++perimeters->back();
            }
        }
    }
    const vector<P> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
};
