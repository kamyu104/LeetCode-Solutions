// Time:  O(m * n)
// Space: O(m * n)

/**
 * class GridMaster {
 *   public:
 *     bool canMove(char direction);
 *     void move(char direction);
 *     boolean isTarget();
 * };
 */

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

public:
    int findShortestPath(GridMaster &master) {
        static const int MAX_M = 500;
        static const int MAX_N = 500;
        const pair<int, int> start = {MAX_M, MAX_N};
        pair<int, int> target = {0, 0};
        bool found = false;
        vector<vector<bool>> lookup(2 * MAX_M + 1, vector<bool>(2 * MAX_N + 1));
        vector<vector<bool>> grid(2 * MAX_M + 1, vector<bool>(2 * MAX_N + 1));
        dfs(start, &target, &master, &found, &lookup, &grid);
        if (!found) {
            return -1;
        }
        return bi_bfs(grid, start, target);
    }

private:
    int bi_bfs(const vector<vector<bool>>& grid,
               const pair<int, int>& start,
               const pair<int, int>& target) {
        unordered_set<pair<int, int>, PairHash<int>> left = {start}, right = {target};
        vector<vector<bool>> lookup(size(grid), vector<bool>(size(grid[0])));
        int steps = 0;
        while (!empty(left)) {
            for (const auto& pos : left) {
                lookup[pos.first][pos.second] = true;
            }
            unordered_set<pair<int, int>, PairHash<int>> new_left;
            for (const auto& pos : left) {
                if (right.count(pos)) {
                    return steps;
                }
                for (const auto& [_, dir] : directions) {
                    pair<int, int> nei = {pos.first + dir.first, pos.second + dir.second};
                    if (!grid[nei.first][nei.second] || lookup[nei.first][nei.second]) {
                        continue;
                    }
                    new_left.emplace(nei);
                }
            }
            left = move(new_left);
            ++steps;
            if (size(left) > size(right)) {
                swap(left, right);
            }
        }
        return -1;
    }

    void dfs(const pair<int, int>& pos,
             pair<int, int> *target,
             GridMaster *master,
             bool *found,
             vector<vector<bool>> *lookup,
             vector<vector<bool>> *grid) {
        static const unordered_map<char, char> rollback = {
            {'L', 'R'}, {'R', 'L'}, {'U', 'D'}, {'D', 'U'}
        };
        
        if (!(*found) && master->isTarget()) {
            *found = true;
            *target = pos;
        }
        (*lookup)[pos.first][pos.second] = true;
        for (const auto& [d, dir] : directions) {
            if (!master->canMove(d)) {
                continue;
            }
            pair<int, int> nei = {pos.first + dir.first, pos.second + dir.second};
            (*grid)[nei.first][nei.second] = true;
            if ((*lookup)[nei.first][nei.second]) {
                continue;
            }
            master->move(d);
            dfs(nei, target, master, found, lookup, grid);
            master->move(rollback.at(d));
        }
    }
    
    const unordered_map<char, pair<int, int>> directions = {
            {'L', {0, -1}},
            {'R', {0, 1}},
            {'U', {-1, 0}},
            {'D', {1, 0}}
        };
};

// Time:  O(m * n)
// Space: O(m * n)
class Solution2 {
public:
    int findShortestPath(GridMaster &master) {
        static const int MAX_M = 500;
        static const int MAX_N = 500;
        const pair<int, int> start = {MAX_M, MAX_N};
        pair<int, int> target = {0, 0};
        bool found = false;
        vector<vector<bool>> lookup(2 * MAX_M + 1, vector<bool>(2 * MAX_N + 1));
        vector<vector<bool>> grid(2 * MAX_M + 1, vector<bool>(2 * MAX_N + 1));
        dfs(start, &target, &master, &found, &lookup, &grid);
        if (!found) {
            return -1;
        }
        return bfs(grid, start, target);
    }

private:
    int bfs(const vector<vector<bool>>& grid,
            const pair<int, int>& start,
            const pair<int, int>& target) {
        vector<pair<int, int>> q = {start};
        vector<vector<bool>> lookup(size(grid), vector<bool>(size(grid[0])));
        lookup[start.first][start.second] = true;
        int steps = 0;
        while (!empty(q)) {
            vector<pair<int, int>> new_q;
            for (const auto& pos : q) {
                if (pos == target) {
                    return steps;
                }
                for (const auto& [_, dir] : directions) {
                    pair<int, int> nei = {pos.first + dir.first, pos.second + dir.second};
                    if (!grid[nei.first][nei.second] || lookup[nei.first][nei.second]) {
                        continue;
                    }
                    lookup[nei.first][nei.second] = true;
                    new_q.emplace_back(nei);
                }
            }
            q = move(new_q);
            ++steps;
        }
        return -1;
    }

    void dfs(const pair<int, int>& pos,
             pair<int, int> *target,
             GridMaster *master,
             bool *found,
             vector<vector<bool>> *lookup,
             vector<vector<bool>> *grid) {
        static const unordered_map<char, char> rollback = {
            {'L', 'R'}, {'R', 'L'}, {'U', 'D'}, {'D', 'U'}
        };
        
        if (!(*found) && master->isTarget()) {
            *found = true;
            *target = pos;
        }
        (*lookup)[pos.first][pos.second] = true;
        for (const auto& [d, dir] : directions) {
            if (!master->canMove(d)) {
                continue;
            }
            pair<int, int> nei = {pos.first + dir.first, pos.second + dir.second};
            (*grid)[nei.first][nei.second] = true;
            if ((*lookup)[nei.first][nei.second]) {
                continue;
            }
            master->move(d);
            dfs(nei, target, master, found, lookup, grid);
            master->move(rollback.at(d));
        }
    }
    
    const unordered_map<char, pair<int, int>> directions = {
            {'L', {0, -1}},
            {'R', {0, 1}},
            {'U', {-1, 0}},
            {'D', {1, 0}}
        };
};
