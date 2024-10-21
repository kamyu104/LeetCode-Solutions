// Time:  O(n)
// Space: O(n)

// iterative dfs, manacher's algorithm
class Solution {
public:
    vector<bool> findAnswer(vector<int>& parent, string s) {
        const auto& manacher = [](const string& s) {
            const auto& preProcess = [](const string& s) {
                if (empty(s)) {
                    return string("^$");
                }
                string ret = "^";
                for (int i = 0; i < size(s); ++i) {
                    ret += "#" + s.substr(i, 1);
                }
                ret += "#$";
                return ret;
            };

            string T = preProcess(s);
            const int n = size(T);
            vector<int> P(n);
            int C = 0, R = 0;
            for (int i = 1; i < n - 1; ++i) {
                int i_mirror = 2 * C - i;
                P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
                while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                    ++P[i];
                }
                if (i + P[i] > R) {
                    C = i;
                    R = i + P[i];
                }
            }
            return P;
        };

        vector<vector<int>> adj(size(parent));
        for (int v = 1; v < size(parent); ++v) {
            adj[parent[v]].emplace_back(v);
        }
        
        const auto& iter_dfs = [&]() {
            int cnt = 0;
            string curr;
            vector<pair<int, int>> lookup(size(adj));
            vector<tuple<int, int, int>> stk = {{1, 0, -1}};
            while (!empty(stk)) {
                const auto [step, u, left] = stk.back(); stk.pop_back();
                if (step == 1) {
                    stk.emplace_back(2, u, cnt);
                    for (int i = size(adj[u]) - 1; i >= 0; --i) {
                        stk.emplace_back(1, adj[u][i], -1);
                    }
                } else if (step == 2) {
                    curr.push_back(s[u]);
                    lookup[u] = pair(left, cnt++);
                }
            }
            return pair(curr, lookup);
        };
    
        const auto& [curr, lookup] = iter_dfs();
        const auto& P = manacher(curr);
        vector<bool> result;
        for (const auto& [left, right] : lookup) {
            result.emplace_back(P[(2 * (left + 1) + 2 * (right + 1)) / 2] >= right - left + 1);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// dfs, manacher's algorithm
class Solution2 {
public:
    vector<bool> findAnswer(vector<int>& parent, string s) {
        const auto& manacher = [](const string& s) {
            const auto& preProcess = [](const string& s) {
                if (empty(s)) {
                    return string("^$");
                }
                string ret = "^";
                for (int i = 0; i < size(s); ++i) {
                    ret += "#" + s.substr(i, 1);
                }
                ret += "#$";
                return ret;
            };

            string T = preProcess(s);
            const int n = size(T);
            vector<int> P(n);
            int C = 0, R = 0;
            for (int i = 1; i < n - 1; ++i) {
                int i_mirror = 2 * C - i;
                P[i] = (R > i) ? min(R - i, P[i_mirror]) : 0;
                while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                    ++P[i];
                }
                if (i + P[i] > R) {
                    C = i;
                    R = i + P[i];
                }
            }
            return P;
        };

        vector<vector<int>> adj(size(parent));
        for (int v = 1; v < size(parent); ++v) {
            adj[parent[v]].emplace_back(v);
        }
        int cnt = 0;
        string curr;
        vector<pair<int, int>> lookup(size(adj));
        const function<void (int)> dfs = [&](int u) {
            const int left = cnt;
            for (const auto& v : adj[u]) {
                dfs(v);
            }
            curr.push_back(s[u]);
            lookup[u] = pair(left, cnt++);
        };
    
        dfs(0);
        const auto& P = manacher(curr);
        vector<bool> result;
        for (const auto& [left, right] : lookup) {
            result.emplace_back(P[(2 * (left + 1) + 2 * (right + 1)) / 2] >= right - left + 1);
        }
        return result;
    }
};
