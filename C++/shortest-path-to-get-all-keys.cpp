// Time:  O(k*r*c + |E|log|V|) = O(k*r*c + (k*|V|)*log|V|)
//                             = O(k*r*c + (k*(k*2^k))*log(k*2^k))
//                             = O(k*r*c + (k*(k*2^k))*(logk + k*log2))
//                             = O(k*r*c + (k*(k*2^k))*k)
//                             = O(k*r*c + k^3*2^k)
// Space: O(|V|) = O(k*2^k)

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {   
        unordered_map<char, pair<int, int>> locations;
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[0].size(); ++c) {
                if (string(".#").find(grid[r][c]) == string::npos) {
                    locations[grid[r][c]] = make_pair(r, c);
                }
            }
        }
        unordered_map<char, unordered_map<char, int>> dists;
        for (const auto& kvp : locations) {
            dists[kvp.first] = bfs(grid, kvp.first, locations);
        }

        // Dijkstra's algorithm
        using T = tuple<int, char, int>;
        priority_queue<T, vector<T>, greater<T>> min_heap;
        min_heap.emplace(0, '@', 0);
        unordered_map<char, unordered_map<int, int>> best;
        best['@'][0] = 0;
        int count = 0;
        for (const auto& kvp : locations) {
            if (islower(kvp.first)) {
                ++count;
            }
        }
        uint32_t target_state = (1 << count) - 1;
        while (!min_heap.empty()) {
            int cur_d, state;
            char place;
            tie(cur_d, place, state) = min_heap.top(); min_heap.pop();
            if (best.count(place) &&
                best[place].count(state) &&
                best[place][state] < cur_d) {
                continue;
            }
            if (state == target_state) {
                return cur_d;
            }
            for (const auto& kvp : dists[place]) {
                int dest, d;
                tie(dest, d) = kvp;
                auto next_state = state;
                if (islower(dest)) {
                    next_state |= (1 << (dest - 'a'));
                } else if (isupper(dest)) {
                    if (!(state & (1 << (dest - 'A')))) {
                        continue;
                    }
                }
                if (!best.count(dest) ||
                    !best[dest].count(next_state) ||
                    cur_d + d < best[dest][next_state]) {
                    best[dest][next_state] = cur_d + d;
                    min_heap.emplace(cur_d + d, dest, next_state);
                }
            }
        }
        return -1;
    }

private:
    unordered_map<char, int> bfs(const vector<string>&grid,
                                 char source,
                                 const unordered_map<char, pair<int, int>>& locations) {
        static const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                       {-1, 0}, {1, 0}};
        int r, c;
        tie(r, c) = locations.at(source);
        vector<vector<bool>> lookup(grid.size(), vector<bool>(grid[0].size()));
        lookup[r][c] = true;
        queue<tuple<int, int, int>> q;
        q.emplace(r, c, 0);
        unordered_map<char, int> dist;
        while (!q.empty()) {
            int r, c, d;
            tie(r, c, d) = q.front(); q.pop();
            if (source != grid[r][c] && grid[r][c] != '.') {
                dist[grid[r][c]] = d;
                continue;
            }
            for (const auto& dir : directions) {
                int cr = r + dir.first, cc = c + dir.second;
                if (!((0 <= cr && cr < grid.size()) &&
                      (0 <= cc && cc < grid[0].size()))) {
                         continue;
                }
                if (grid[cr][cc] != '#' && !lookup[cr][cc]) {
                    lookup[cr][cc] = true;
                    q.emplace(cr, cc, d + 1);
                }
            }
        }
        return dist ;
    }
};
