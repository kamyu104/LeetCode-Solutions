// Time:  O(o * l + k * eloge + n * c * l), e is the number of edges reachable from a given node u, o = len(original), l = max(len(x) for x in original), k = len(lookups), c = len({len(x) for x in original})
// Space: O(o * l + k * v + c + l), v is the number of nodes reachable from a given node u

// hash table, dijkstra's algorithm, dp, memoization
class Solution {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        static const auto INF = numeric_limits<int64_t>::max();

        unordered_map<int, unordered_map<string, int>> lookups;
        for (const auto& x : original) {
            const int l = size(x);
            auto& lookup = lookups[l];
            if (!lookup.count(x)) {
                lookup[x] = size(lookup);
            }
        }
        for (const auto& x : changed) {
            const int l = size(x);
            auto& lookup = lookups[l];
            if (!lookup.count(x)) {
                lookup[x] = size(lookup);
            }
        }
        unordered_map<int, vector<vector<int64_t>>> dists;
        for (const auto& [l, lookup] : lookups) {
            auto& dist = dists[l];
            dist.assign(size(lookup), vector<int64_t>(size(lookup), INF));
            for (int u = 0; u < size(dist); ++u) {
                dist[u][u] = 0;
            }
        }
        for (int i = 0; i < size(original); ++i) {
            const int l = size(original[i]);
            auto& lookup = lookups[l];
            auto& dist = dists[l];
            const int u = lookup[original[i]];
            const int v = lookup[changed[i]];
            dist[u][v] = min(dist[u][v], static_cast<int64_t>(cost[i]));
        }
        const auto& dijkstra = [&](const auto& dist, int start) {
            vector<int64_t> best(size(dist), INF);
            best[start] = 0;
            priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> min_heap;
            min_heap.emplace(0, start);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr > best[u]) {
                    continue;
                }
                for (int v = 0; v < size(dist[u]); ++v) {
                    const auto& w = dist[u][v];
                    if (best[v] - curr <= w) {
                        continue;
                    }
                    best[v] = curr + w;
                    min_heap.emplace(best[v], v);
                }
            }
            return best;
        };
        
        unordered_map<int, unordered_map<int, vector<int64_t>>> memo;
        const auto& memoization = [&](int l, const auto& dist, int u, int v) {   
            if (!memo[l].count(u)) {
                memo[l][u] = dijkstra(dist, u);
            }
            return memo[l][u][v];
        };

        unordered_set<int> candidates;
        int l = 0;
        for (const auto& x : original) {
            candidates.emplace(size(x));
            l = max(l, static_cast<int>(size(x)));
        }
        vector<int64_t> dp(l + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(source); ++i) {
            if (dp[i % size(dp)] == INF) {
                continue;
            }
            if (source[i] == target[i]) {
                dp[(i + 1) % size(dp)] = min(dp[(i + 1) % size(dp)], dp[i % size(dp)]);
            }
            for (const auto& l : candidates) {
                if (i + l > size(source)) {
                    continue;
                }
                auto& lookup = lookups[l];
                auto& dist = dists[l];
                const auto& u = source.substr(i, l);
                const auto& v = target.substr(i, l);
                if (lookup.count(u) && lookup.count(v) && memoization(l, dist, lookup[u], lookup[v]) != INF) {
                    dp[(i + l) % size(dp)] = min(dp[(i + l) % size(dp)], dp[i % size(dp)] + memoization(l, dist, lookup[u], lookup[v]));
                }
            }
            dp[i % size(dp)] = INF;
        }
        return dp[size(source) % size(dp)] != INF ? dp[size(source) % size(dp)] : -1;
    }
};

// Time:  O(o * l + k^3 + n * c * l), o = len(original), l = max(len(x) for x in original), k = len(lookup), c = len({len(x) for x in original})
// Space: O(o * l + k^2 + c + l)
// hash table, Floyd-Warshall algorithm, dp
class Solution2 {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        static const auto INF = numeric_limits<int64_t>::max();
        
        const auto& floydWarshall = [](auto& dist) {
            for (int k = 0; k < size(dist); ++k) {
                for (int i = 0; i < size(dist); ++i) {
                    if (dist[i][k] == INF) {
                        continue;
                    }
                    for (int j = 0; j < size(dist[0]); ++j) {
                        if (dist[k][j] == INF) {
                            continue;
                        }
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        };

        unordered_map<int, unordered_map<string, int>> lookups;
        for (const auto& x : original) {
            const int l = size(x);
            auto& lookup = lookups[l];
            if (!lookup.count(x)) {
                lookup[x] = size(lookup);
            }
        }
        for (const auto& x : changed) {
            const int l = size(x);
            auto& lookup = lookups[l];
            if (!lookup.count(x)) {
                lookup[x] = size(lookup);
            }
        }
        unordered_map<int, vector<vector<int64_t>>> dists;
        for (const auto& [l, lookup] : lookups) {
            auto& dist = dists[l];
            dist.assign(size(lookup), vector<int64_t>(size(lookup), INF));
            for (int u = 0; u < size(dist); ++u) {
                dist[u][u] = 0;
            }
        }
        for (int i = 0; i < size(original); ++i) {
            const int l = size(original[i]);
            auto& lookup = lookups[l];
            auto& dist = dists[l];
            const int u = lookup[original[i]];
            const int v = lookup[changed[i]];
            dist[u][v] = min(dist[u][v], static_cast<int64_t>(cost[i]));
        }
        for (auto& [_, dist] : dists) {
            floydWarshall(dist);
        }
        unordered_set<int> candidates;
        int l = 0;
        for (const auto& x : original) {
            candidates.emplace(size(x));
            l = max(l, static_cast<int>(size(x)));
        }
        vector<int64_t> dp(l + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(source); ++i) {
            if (dp[i % size(dp)] == INF) {
                continue;
            }
            if (source[i] == target[i]) {
                dp[(i + 1) % size(dp)] = min(dp[(i + 1) % size(dp)], dp[i % size(dp)]);
            }
            for (const auto& l : candidates) {
                if (i + l > size(source)) {
                    continue;
                }
                auto& lookup = lookups[l];
                auto& dist = dists[l];
                const auto& u = source.substr(i, l);
                const auto& v = target.substr(i, l);
                if (lookup.count(u) && lookup.count(v) && dist[lookup[u]][lookup[v]] != INF) {
                    dp[(i + l) % size(dp)] = min(dp[(i + l) % size(dp)], dp[i % size(dp)] + dist[lookup[u]][lookup[v]]);
                }
            }
            dp[i % size(dp)] = INF;
        }
        return dp[size(source) % size(dp)] != INF ? dp[size(source) % size(dp)] : -1;
    }
};

// Time:  O(o * l + k * eloge + n * c * l), e is the number of edges reachable from a given node u, o = len(original), l = max(len(x) for x in original), k = len(lookups), c = len({len(x) for x in original})
// Space: O(t + k * v + c + l), v is the number of nodes reachable from a given node u
// hash table, dijkstra's algorithm, dp, memoization
class Solution3 {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        static const auto INF = numeric_limits<int64_t>::max();

        unordered_map<string, int> lookup;
        for (const auto& x : original) {
            if (lookup.count(x)) {
                continue;
            }
            lookup[x] = size(lookup);
        }
        for (const auto& x : changed) {
            if (lookup.count(x)) {
                continue;
            }
            lookup[x] = size(lookup);
        }
        unordered_map<int, unordered_map<int, int64_t>> dist;
        for (int i = 0; i < size(original); ++i) {
            const int u = lookup[original[i]];
            const int v = lookup[changed[i]];
            if (!dist[u].count(v)) {
                dist[u][v] = INF;
            }
            dist[u][v] = min(dist[u][v], static_cast<int64_t>(cost[i]));
        }
        const auto& dijkstra = [&](int start) {
            unordered_map<int, int64_t> best = {{start, 0}};
            priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> min_heap;
            min_heap.emplace(0, start);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr > best[u]) {
                    continue;
                }
                for (auto [v, w] : dist[u]) {
                    if (best.count(v) && best[v] - curr <= w) {
                        continue;
                    }
                    best[v] = curr + w;
                    min_heap.emplace(best[v], v);
                }
            }
            return best;
        };
        
        unordered_map<int, unordered_map<int, int64_t>> memo;
        const auto& memoization = [&](int u, int v) {            
            if (!memo.count(u)) {
                memo[u] = dijkstra(u);
            }
            return memo[u].count(v) ? memo[u][v] : INF;
        };
        
        unordered_set<int> candidates;
        int l = 0;
        for (const auto& x : original) {
            candidates.emplace(size(x));
            l = max(l, static_cast<int>(size(x)));
        }
        vector<int64_t> dp(l + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(source); ++i) {
            if (dp[i % size(dp)] == INF) {
                continue;
            }
            if (source[i] == target[i]) {
                dp[(i + 1) % size(dp)] = min(dp[(i + 1) % size(dp)], dp[i % size(dp)]);
            }
            for (const auto& l : candidates) {
                if (i + l > size(source)) {
                    continue;
                }
                const auto& u = source.substr(i, l);
                const auto& v = target.substr(i, l);
                if (lookup.count(u) && lookup.count(v) && memoization(lookup[u], lookup[v]) != INF) {
                    dp[(i + l) % size(dp)] = min(dp[(i + l) % size(dp)], dp[i % size(dp)] + memoization(lookup[u], lookup[v]));
                }
            }
            dp[i % size(dp)] = INF;
        }
        return dp[size(source) % size(dp)] != INF ? dp[size(source) % size(dp)] : -1;
    }
};

// Time:  O(o * l + k^3 + n * c * l), o = len(original), l = max(len(x) for x in original), k = len(lookup), c = len({len(x) for x in original})
// Space: O(o * l + k^2 + c + l)
// hash table, Floyd-Warshall algorithm, dp
class Solution4 {
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        static const auto INF = numeric_limits<int64_t>::max();
        
        const auto& floydWarshall = [](auto& dist) {
            for (const auto& [k, _] : dist) {
                for (const auto& [i, _] : dist) {
                    if (dist[i][k] == INF) {
                        continue;
                    }
                    for (const auto& [j, _] : dist) {
                        if (dist[k][j] == INF) {
                            continue;
                        }
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        };

        unordered_map<string, int> lookup;
        unordered_map<int, vector<int>> buckets;
        for (const auto& x : original) {
            if (lookup.count(x)) {
                continue;
            }
            lookup[x] = size(lookup);
            buckets[size(x)].emplace_back(lookup[x]);
        }
        for (const auto& x : changed) {
            if (lookup.count(x)) {
                continue;
            }
            lookup[x] = size(lookup);
            buckets[size(x)].emplace_back(lookup[x]);
        }
        unordered_map<int, unordered_map<int, unordered_map<int, int64_t>>> dists;
        for (const auto& [l, lookup] : buckets) {
            auto& dist = dists[l];
            for (const auto& u : lookup) {
                for (const auto& v : lookup) {
                    dist[u][v] = u == v ? 0 : INF;
                }
            }
        }
        for (int i = 0; i < size(original); ++i) {
            const int l = size(original[i]);
            auto& dist = dists[l];
            const int u = lookup[original[i]];
            const int v = lookup[changed[i]];
            dist[u][v] = min(dist[u][v], static_cast<int64_t>(cost[i]));
        }
        for (auto& [_, dist] : dists) {
            floydWarshall(dist);
        }
        unordered_set<int> candidates;
        int l = 0;
        for (const auto& x : original) {
            candidates.emplace(size(x));
            l = max(l, static_cast<int>(size(x)));
        }
        vector<int64_t> dp(l + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(source); ++i) {
            if (dp[i % size(dp)] == INF) {
                continue;
            }
            if (source[i] == target[i]) {
                dp[(i + 1) % size(dp)] = min(dp[(i + 1) % size(dp)], dp[i % size(dp)]);
            }
            for (const auto& l : candidates) {
                if (i + l > size(source)) {
                    continue;
                }
                auto& dist = dists[l];
                const auto& u = source.substr(i, l);
                const auto& v = target.substr(i, l);
                if (lookup.count(u) && lookup.count(v) && dist[lookup[u]][lookup[v]] != INF) {
                    dp[(i + l) % size(dp)] = min(dp[(i + l) % size(dp)], dp[i % size(dp)] + dist[lookup[u]][lookup[v]]);
                }
            }
            dp[i % size(dp)] = INF;
        }
        return dp[size(source) % size(dp)] != INF ? dp[size(source) % size(dp)] : -1;
    }
};

// Time:  O(o * l + k * eloge + n * l), e is the number of edges reachable from a given node u, o = len(original), l = max(len(x) for x in original), k = trie.k
// Space: O(t + k * v + l), v is the number of nodes reachable from a given node u
// trie, dijkstra's algorithm, dp, memoization
class Solution5 {
private:
    class Trie {
    public:
        Trie() {
             new_node();
         }

        pair<bool, int> add(const string& s) {
            int curr = 0;
            for (const auto& c : s) {
                const int x = c - 'a';
                if (nodes_[curr][x] == -1) {
                    nodes_[curr][x] = new_node();
                }
                curr = nodes_[curr][x];
            }
            if (idxs_[curr] == -1) {
                idxs_[curr] = k++;
                return {true, idxs_[curr]};
            }
            return {false, idxs_[curr]};
        }

        int query(const string& s) {
            int curr = 0;
            for (const auto& c : s) {
                curr = nodes_[curr][c - 'a'];
            }
            return idxs_[curr];
        }

        int next(int curr, int c) {
            return nodes_[curr][c - 'a'];
        }

        int id(int curr) {
            return idxs_[curr];
        }

    public:
        int k = 0;

    private:
        int new_node() {
            nodes_.emplace_back(26, -1);
            idxs_.emplace_back(-1);
            return size(nodes_) - 1;
        }

        vector<vector<int>> nodes_;
        vector<int> idxs_;
    };

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        static const auto INF = numeric_limits<int64_t>::max();

        Trie trie;
        for (const auto& x : original) {
            trie.add(x);
        }
        for (const auto& x : changed) {
            trie.add(x);
        }
        unordered_map<int, unordered_map<int, int64_t>> dist;
        for (int i = 0; i < size(original); ++i) {
            const int u = trie.query(original[i]);
            const int v = trie.query(changed[i]);
            if (!dist[u].count(v)) {
                dist[u][v] = INF;
            }
            dist[u][v] = min(dist[u][v], static_cast<int64_t>(cost[i]));
        }
        const auto& dijkstra = [&](int start) {
            unordered_map<int, int64_t> best = {{start, 0}};
            priority_queue<pair<int64_t, int>, vector<pair<int64_t, int>>, greater<pair<int64_t, int>>> min_heap;
            min_heap.emplace(0, start);
            while (!empty(min_heap)) {
                const auto [curr, u] = min_heap.top(); min_heap.pop();
                if (curr > best[u]) {
                    continue;
                }
                for (auto [v, w] : dist[u]) {
                    if (best.count(v) && best[v] - curr <= w) {
                        continue;
                    }
                    best[v] = curr + w;
                    min_heap.emplace(best[v], v);
                }
            }
            return best;
        };
        
        unordered_map<int, unordered_map<int, int64_t>> memo;
        const auto& memoization = [&](int u, int v) {            
            if (!memo.count(u)) {
                memo[u] = dijkstra(u);
            }
            return memo[u].count(v) ? memo[u][v] : INF;
        };
        
        int l = 0;
        for (const auto& x : original) {
            l = max(l, static_cast<int>(size(x)));
        }
        vector<int64_t> dp(l + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(source); ++i) {
            if (dp[i % size(dp)] == INF) {
                continue;
            }
            if (source[i] == target[i]) {
                dp[(i + 1) % size(dp)] = min(dp[(i + 1) % size(dp)], dp[i % size(dp)]);
                
            }
            int u = 0, v = 0;
            for (int j = i; j < size(source); ++j) {
                u = trie.next(u, source[j]);
                v = trie.next(v, target[j]);
                if (u == -1 || v == -1) {
                    break;
                }
                if (trie.id(u) != -1 && trie.id(v) != -1 && memoization(trie.id(u), trie.id(v)) != INF) {
                    dp[(j + 1) % size(dp)] = min(dp[(j + 1) % size(dp)], dp[i % size(dp)] + memoization(trie.id(u), trie.id(v)));
                }
            }
            dp[i % size(dp)] = INF;
        }
        return dp[size(source) % size(dp)] != INF ? dp[size(source) % size(dp)] : -1;
    }
};

// Time:  O(o * l + k^3 + n * l), o = len(original), l = max(len(x) for x in original), k = trie.k
// Space: O(t + k^2 + l)
// trie, Floyd-Warshall algorithm, dp
class Solution6 {
private:
    class Trie {
    public:
        Trie() {
             new_node();
         }

        pair<bool, int> add(const string& s) {
            int curr = 0;
            for (const auto& c : s) {
                const int x = c - 'a';
                if (nodes_[curr][x] == -1) {
                    nodes_[curr][x] = new_node();
                }
                curr = nodes_[curr][x];
            }
            if (idxs_[curr] == -1) {
                idxs_[curr] = k++;
                return {true, idxs_[curr]};
            }
            return {false, idxs_[curr]};
        }

        int query(const string& s) {
            int curr = 0;
            for (const auto& c : s) {
                curr = nodes_[curr][c - 'a'];
            }
            return idxs_[curr];
        }

        int next(int curr, int c) {
            return nodes_[curr][c - 'a'];
        }

        int id(int curr) {
            return idxs_[curr];
        }

    public:
        int k = 0;

    private:
        int new_node() {
            nodes_.emplace_back(26, -1);
            idxs_.emplace_back(-1);
            return size(nodes_) - 1;
        }

        vector<vector<int>> nodes_;
        vector<int> idxs_;
    };

public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        static const auto INF = numeric_limits<int64_t>::max();
        
        const auto& floydWarshall = [](auto& dist) {
            for (const auto& [k, _] : dist) {
                for (const auto& [i, _] : dist) {
                    if (dist[i][k] == INF) {
                        continue;
                    }
                    for (const auto& [j, _] : dist) {
                        if (dist[k][j] == INF) {
                            continue;
                        }
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        };

        Trie trie;
        unordered_map<int, vector<int>> buckets;
        for (const auto& x : original) {
            const auto& [not_duplicated, i] = trie.add(x);
            if (not_duplicated) {
                buckets[size(x)].emplace_back(i);
            }
        }
        for (const auto& x : changed) {
            const auto& [not_duplicated, i] = trie.add(x);
            if (not_duplicated) {
                buckets[size(x)].emplace_back(i);
            }
        }
        unordered_map<int, unordered_map<int, unordered_map<int, int64_t>>> dists;
        for (const auto& [l, lookup] : buckets) {
            auto& dist = dists[l];
            for (const auto& u : lookup) {
                for (const auto& v : lookup) {
                    dist[u][v] = u == v ? 0 : INF;
                }
            }
        }
        for (int i = 0; i < size(original); ++i) {
            const int l = size(original[i]);
            auto& dist = dists[l];
            const int u = trie.query(original[i]);
            const int v = trie.query(changed[i]);
            dist[u][v] = min(dist[u][v], static_cast<int64_t>(cost[i]));
        }
        for (auto& [_, dist] : dists) {
            floydWarshall(dist);
        }
        int l = 0;
        for (const auto& x : original) {
            l = max(l, static_cast<int>(size(x)));
        }
        vector<int64_t> dp(l + 1, INF);
        dp[0] = 0;
        for (int i = 0; i < size(source); ++i) {
            if (dp[i % size(dp)] == INF) {
                continue;
            }
            if (source[i] == target[i]) {
                dp[(i + 1) % size(dp)] = min(dp[(i + 1) % size(dp)], dp[i % size(dp)]);
                
            }
            int u = 0, v = 0;
            for (int j = i; j < size(source); ++j) {
                u = trie.next(u, source[j]);
                v = trie.next(v, target[j]);
                if (u == -1 || v == -1) {
                    break;
                }
                auto& dist = dists[j - i + 1];
                if (trie.id(u) != -1 && trie.id(v) != -1 && dist[trie.id(u)][trie.id(v)] != INF) {
                    dp[(j + 1) % size(dp)] = min(dp[(j + 1) % size(dp)], dp[i % size(dp)] + dist[trie.id(u)][trie.id(v)]);
                }
            }
            dp[i % size(dp)] = INF;
        }
        return dp[size(source) % size(dp)] != INF ? dp[size(source) % size(dp)] : -1;
    }
};
