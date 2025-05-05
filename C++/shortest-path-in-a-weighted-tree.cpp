// Time:  O(nlogn)
// Space: O(n)

class BIT {
public:
    BIT(int n) : bit_(n + 1) {  // 0-indexed
    }
    
    void add(int i, int val) {
        ++i;
        for (; i < size(bit_); i += lower_bit(i)) {
            bit_[i] += val;
        }
    }

    int query(int i) const {
        ++i;
        int total = 0;
        for (; i > 0; i -= lower_bit(i)) {
            total += bit_[i];
        }
        return total;
    }

private:
    int lower_bit(int i) const {
        return i & -i;
    }
    
    vector<int> bit_;
};

// iterative dfs, fenwick tree
class Solution {
public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            const int u = e[0] - 1, v = e[1] - 1, w = e[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        
        const auto& iter_dfs = [&]() {
            vector<int> L(n), R(n), dist(n), lookup(n);
            int cnt = 0;
            vector<tuple<int, int, int, int>> stk = {{1, 0, -1, 0}};
            while (!empty(stk)) {
                const auto [step, u, p, d] = stk.back(); stk.pop_back();
                if (step == 1) {
                    L[u] = cnt++;
                    dist[u] = d;
                    stk.emplace_back(2, u, -1, -1);
                    for (const auto& [v, w] : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        lookup[v] = w;
                        stk.emplace_back(1, v, u, d + w);
                    }
                } else if (step == 2) {
                    R[u] = cnt;
                }
            }            
            return tuple(L, R, dist, lookup);
        };

        auto [L, R, dist, lookup] = iter_dfs();
        BIT bit(n);
        vector<int> result;
        for (const auto& q : queries) {
            if (q[0] == 1) {
                int u = q[1] - 1, v = q[2] - 1, w = q[3];
                if (L[u] > L[v]) {
                    swap(u, v);
                }
                const int diff = w - lookup[v];
                bit.add(L[v], diff);
                bit.add(R[v], -diff);
                lookup[v] = w;
            } else {
                const int x = q[1] - 1;
                result.emplace_back(dist[x] + bit.query(L[x]));
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// dfs, fenwick tree
class Solution2 {
public:
    vector<int> treeQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> adj(n);
        for (const auto& e : edges) {
            const int u = e[0] - 1, v = e[1] - 1, w = e[2];
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }
        vector<int> L(n), R(n), dist(n), lookup(n);
        int cnt = 0;
        const function<void (int, int, int)> dfs = [&](int u, int p, int d) {
            L[u] = cnt++;
            dist[u] = d;
            for (const auto& [v, w] : adj[u]) {
                if (v == p) {
                    continue;
                }
                lookup[v] = w;
                dfs(v, u, d + w);
            }
            R[u] = cnt;
        };

        dfs(0, -1, 0);
        BIT bit(n);
        vector<int> result;
        for (const auto& q : queries) {
            if (q[0] == 1) {
                int u = q[1] - 1, v = q[2] - 1, w = q[3];
                if (L[u] > L[v]) {
                    swap(u, v);
                }
                const int diff = w - lookup[v];
                bit.add(L[v], diff);
                bit.add(R[v], -diff);
                lookup[v] = w;
            } else {
                const int x = q[1] - 1;
                result.emplace_back(dist[x] + bit.query(L[x]));
            }
        }
        return result;
    }
};
