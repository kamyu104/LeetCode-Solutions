// Time:  O(n)
// Space: O(n)

// flood fill, bfs, counting sort, greedy
/* 
n = 11
edges = [[0,1],[1,2],[2,3],[5,6],[6,7]]
max is 367 but ans is 366, which is wrong by greedy
*/
class Solution_WA {
public:
    long long maxScore(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        vector<bool> lookup(n);
        const auto& bfs = [&](int u) {
            lookup[u] = true;
            vector<int> result = {u};
            for (int i = 0; i < size(result); ++i){
                const auto& u = result[i];
                for (const auto& v : adj[u]) {
                    if (lookup[v]) {
                        continue;
                    }
                    lookup[v] = true;
                    result.emplace_back(v);
                }
            }
            return result;
        };

        const auto& f = [](int l, int r, bool is_cycle) {
            int64_t a = r, b = r;
            int64_t result = 0;
            for (int64_t c = r - 1; c >= l; --c) {
                result += a * c;
                tie(a, b) = pair(b, c);
            }
            if (is_cycle) {
                result += a * b;
            }
            return result;
        };

        vector<int> chains, cycles;
        for (int u = 0; u < n; ++u) {
            if (lookup[u]) {
                continue;
            }
            const auto& comp = bfs(u);
            if (all_of(cbegin(comp), cend(comp), [&](const auto& x) {
                return size(adj[x]) == 2;
            })) {
                cycles.emplace_back(size(comp));
            } else {
                chains.emplace_back(size(comp));
            }
        }
        int64_t result = 0;
        for (const auto& l : cycles) {
            result += f(n - l + 1, n, true);
            n -= l;
        }
        const int max_chain = empty(chains) ? 0 : ranges::max(chains);
        vector<int> cnt(max_chain + 1);
        for (const auto& l: chains) {
            ++cnt[l];
        }
        for (int l = size(cnt) - 1; l >= 0; --l) {
            for (int _ = 0; _ < cnt[l]; ++_) {
                result += f(n - l + 1, n, false);
                n -= l;
            }
        }
        return result;
    }
};
