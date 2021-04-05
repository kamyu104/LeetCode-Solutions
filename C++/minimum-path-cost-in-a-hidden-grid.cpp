// Time:  O(m * n * log(m * n))
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
public:
    int findShortestPath(GridMaster &master) {
        const pair<int, int> start = {MAX_M, MAX_N};
        pair<int, int> target = {0, 0};
        bool found = false;
        unordered_set<int> lookup;
        unordered_map<int, unordered_map<int, int>> adj;
        dfs(start, &target, &master, &found, &lookup, &adj);
        if (!found) {
            return -1;
        }
        return dijkstra(adj, start, target);
    }

private:
    int index(pair<int, int> p) {
        return (2 * MAX_N + 1) * p.first + p.second;
    }

    int dijkstra(const unordered_map<int, unordered_map<int, int>>& adj,
                 const pair<int, int>& start,
                 const pair<int, int>& target) {
        unordered_map<int, int> dist = {{index(start), 0}};
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        min_heap.emplace(0, index(start));
        while (!empty(min_heap)) {
            const auto [curr, u] = min_heap.top(); min_heap.pop();
            if (dist[u] < curr) {
                continue;
            }
            for (const auto& [v, w] : adj.at(u)) {
                if ((dist.count(v) && dist[v] - curr <= w)) {
                    continue;
                }
                dist[v] = curr + w;
                min_heap.emplace(curr + w, v);
            }
        }
        return dist.count(index(target)) ? dist[index(target)] : -1;
    }

    void dfs(const pair<int, int>& pos,
             pair<int, int> *target,
             GridMaster *master,
             bool *found,
             unordered_set<int> *lookup,
             unordered_map<int, unordered_map<int, int>> *adj) {
        static const unordered_map<char, char> rollback = {
            {'L', 'R'}, {'R', 'L'}, {'U', 'D'}, {'D', 'U'}
        };
        static const unordered_map<char, pair<int, int>> directions = {
            {'L', {0, -1}},
            {'R', {0, 1}},
            {'U', {-1, 0}},
            {'D', {1, 0}}
        };
        
        if (!(*found) && master->isTarget()) {
            *found = true;
            *target = pos;
        }
        lookup->emplace(index(pos));
        for (const auto& [d, dir] : directions) {
            if (!master->canMove(d)) {
                continue;
            }
            pair<int, int> nei = {pos.first + dir.first, pos.second + dir.second};
            if ((*adj)[index(pos)].count(index(nei))) {
                continue;
            }
            (*adj)[index(pos)][index(nei)] = master->move(d);
            if (!lookup->count(index(nei))) {
                dfs(nei, target, master, found, lookup, adj);
            }
            (*adj)[index(nei)][index(pos)] = master->move(rollback.at(d));
        }
    }

    static const int MAX_M = 100;
    static const int MAX_N = 100;
};
