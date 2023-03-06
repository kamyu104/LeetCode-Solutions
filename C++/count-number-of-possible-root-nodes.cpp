// Time:  O(n) 
// Space: O(h)

// iterative dfs
class Solution {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        unordered_map<int, vector<int>> adj;
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        unordered_set<pair<int, int>, PairHash<int>> lookup;
        for (const auto& g : guesses) {
            lookup.emplace(pair(g[0], g[1]));
        }
        const auto& iter_dfs = [&]() {
            int result = 0;
            vector<pair<int, int>> stk = {{0, -1}};
            while (!empty(stk)) {
                const auto [u, p] = stk.back(); stk.pop_back();
                result += lookup.count(pair(p, u));
                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    stk.emplace_back(v, u);
                }
            }
            return result;
        };
        const auto& iter_dfs2 = [&](int curr) {
            int result = 0;
            vector<tuple<int, int, int>> stk = {{0, -1, curr}};
            while (!empty(stk)) {
                auto [u, p, curr] = stk.back(); stk.pop_back();
                if (lookup.count(pair(p, u))) {
                    --curr;
                }
                if (lookup.count(pair(u, p))) {
                    ++curr;
                }
                result += static_cast<int>(curr >= k);
                for (const auto& v : adj[u]) {
                    if (v == p) {
                        continue;
                    }
                    stk.emplace_back(v, u, curr);
                }
            }
            return result;
        };
    
        int curr = iter_dfs();
        return iter_dfs2(curr);
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
};

// Time:  O(n) 
// Space: O(h)
// dfs
class Solution2 {
public:
    int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
        unordered_map<int, vector<int>> adj;
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        unordered_set<pair<int, int>, PairHash<int>> lookup;
        for (const auto& g : guesses) {
            lookup.emplace(pair(g[0], g[1]));
        }
        const function<int(int, int)> dfs = [&](int u, int p) {
            int cnt = lookup.count(pair(p, u));
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                cnt += dfs(v, u);
            }
            return cnt;
        };
        const function<int(int, int, int)> dfs2 = [&](int u, int p, int curr) {
            if (lookup.count(pair(p, u))) {
                --curr;
            }
            if (lookup.count(pair(u, p))) {
                ++curr;
            }
            int cnt = static_cast<int>(curr >= k);
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                cnt += dfs2(v, u, curr);
            }
            return cnt;
        };
    
        int curr = dfs(0, -1);
        return dfs2(0, -1, curr);
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
};
