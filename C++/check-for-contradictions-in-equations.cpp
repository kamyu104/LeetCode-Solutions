// Time:  O(e + q)
// Space: O(n)

// union find
class Solution {
public:
    bool checkContradictions(vector<vector<string>>& equations, vector<double>& values) {
        static const double EPS = 1e-5;
        UnionFind uf;
        for (int i = 0; i < size(equations); ++i) {
            if (!uf.union_set(equations[i][0], equations[i][1], values[i]) &&
                abs(uf.query_set(equations[i][0], equations[i][1]) - values[i]) > EPS) {
                return true;
            }
        }
        return false;
    }

private:
    class UnionFind {
    public:
        UnionFind() {
        }
                
        pair<string, double> find_set(const string& x) {
            if (!set_.count(x)) {
                set_[x] = pair(x, 1.0);
            }
            const auto& [xp, xr] = set_[x];
            if (x != xp) {
                const auto& [pp, pr] = find_set(xp);  // Path compression.
                set_[x] = pair(pp, xr * pr);
            }
            return set_[x];
        }

        bool union_set(const string& x, const string& y, double r) {
            const auto& [xp, xr] = find_set(x);
            const auto& [yp, yr] = find_set(y);
            if (xp == yp) {
                return false;
            }
            if (rank_[xp] < rank_[yp]) {  // Union by rank.
                set_[xp] = pair(yp, r * yr / xr);
            } else if (rank_[xp] > rank_[yp]) {
                set_[yp] = pair(xp, 1.0 / r * xr / yr);
            } else {
                set_[yp] = pair(xp, 1.0 / r * xr / yr);
                ++rank_[xp];
            }
            return true;
        }

        double query_set(const string& x, const string& y) {
            if (!set_.count(x) || !set_.count(y)) {
                return -1.0;
            }
            const auto& [xp, xr] = find_set(x);
            const auto& [yp, yr] = find_set(y);
            return (xp == yp) ? xr / yr : -1.0;
        }

    private:
        unordered_map<string, pair<string, double>> set_;
        unordered_map<string, int> rank_;
    };
};

// Time:  O(e + q)
// Space: O(n)
// dfs
class Solution2 {
public:
    bool checkContradictions(vector<vector<string>>& equations, vector<double>& values) {
        unordered_map<string, vector<pair<string, double>>> adj;
        for (int i = 0; i < size(equations); ++i) {
            adj[equations[i][0]].emplace_back(equations[i][1], 1.0 / values[i]);
            adj[equations[i][1]].emplace_back(equations[i][0], values[i]);
        }
        unordered_map<string, double> lookup;
        const auto& iter_dfs = [&](const auto& u) {
            vector<string> stk = {u};
            lookup[u] = 1.0;
            while (!empty(stk)) {
                auto u = stk.back(); stk.pop_back();
                for (const auto& [v, k] : adj[u]) {
                    if (lookup.count(v)) {
                        if (!isclose(lookup[v], lookup[u] * k)) {
                            return true;
                        }
                        continue;
                    }
                    lookup[v] = lookup[u] * k;
                    stk.emplace_back(v);
                }
            }
            return false;
        };
        for (const auto& [u, _] : adj) {
            if (lookup.count(u)) {
                continue;
            }
            if (iter_dfs(u)) {
                return true;
            }
        }
        return false;
    }

private:
    bool isclose(double a, double b, double rel_tol = 1e-09, double abs_tol = 0.0) {
        return abs(a - b) <= max(rel_tol * max(abs(a), abs(b)), abs_tol);
    }
};
