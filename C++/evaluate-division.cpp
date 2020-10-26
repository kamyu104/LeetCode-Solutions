// Time:  O((e + q) * α(n)) ~= O(e + q), using either one of "path compression" and "union by rank" results in amortized O(logn)
//                                     , using  both results in α(n) ~= O(1)
// Space: O(n)

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        UnionFind union_find;
        for (int i = 0; i < equations.size(); ++i) {
            union_find.union_set(equations[i][0], equations[i][1], values[i]);
        }
        
        vector<double> result;
        for (const auto& q : queries) {
            result.emplace_back(union_find.query_set(q[0], q[1]));
        }
        return result;
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
    
    class UnionFindPathCompressionOnly {
    public:
        UnionFindPathCompressionOnly() {
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
            set_[xp] = pair(yp, r * yr / xr); 
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
    };
};

// Time:  O(e + q * n), at most O(n^3 + q)
// Space: O(n^2)
// bfs solution
class Solution2 {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adj;
        for (int i = 0; i < equations.size(); ++i) {
            const auto& a = equations[i][0], &b = equations[i][1];
            adj[a][b] = values[i];
            adj[b][a] = 1.0 / values[i];
        }
        vector<double> result;
        unordered_map<string, unordered_map<string, double>> lookup;
        for (const auto& q : queries) {
            const auto& a = q[0], &b = q[1];
            result.emplace_back(bfs(adj, a, b, &lookup));
        }
        return result;
    }

private:
    double bfs(const unordered_map<string, unordered_map<string, double>>& adj,
            const string& a, const string& b,
            unordered_map<string, unordered_map<string, double>> *lookup) {
        if (!adj.count(a) || !adj.count(b)) {
            return -1.0;
        }
        if (lookup->count(a) && (*lookup)[a].count(b)) {
            return (*lookup)[a][b];
        }
        unordered_set<string> visited = {a};
        queue<pair<string, double>> q({{a, 1.0}});
        while (!q.empty()) {
            const auto [u, val] = q.front(); q.pop();
            if (u == b) {
                (*lookup)[a][b] = val;
                return val;
            }
            if (!adj.count(u)) {
                continue;
            }
            for (const auto& [v, k] : adj.at(u)) {
                if (visited.count(v)) {
                    continue;
                }
                visited.emplace(v);
                q.emplace(v, val * k);
            }
        }
        (*lookup)[a][b] = -1.0;
        return -1.0;
    }   
};

// Time:  O(n^3 + q)
// Space: O(n^2)
// variant of floyd–warshall algorithm solution
class Solution3 {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> adj;
        for (int i = 0; i < equations.size(); ++i) {
            const auto& a = equations[i][0], &b = equations[i][1];
            adj[a][a] = adj[b][b] = 1.0;
            adj[a][b] = values[i];
            adj[b][a] = 1.0 / values[i];
        }
        for (const auto& [k, _] : adj) {
            for (const auto& [i, _] : adj[k]) {
                for (const auto& [j, _] : adj[k]) {
                    adj[i][j] = adj[i][k] * adj[k][j];
                }
            }
        }
        vector<double> result;
        for (const auto& q : queries) {
            const auto& a = q[0], &b = q[1];
            result.emplace_back(adj.count(a) && adj[a].count(b) ? adj[a][b] : -1.0);
        }
        return result;
    }
};

// Time:  O(e + q * n), at most O(n^3 + q)
// Space: O(e)
class Solution4 {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations,
        vector<double>& values, vector<pair<string, string>> query) {

        unordered_map<string, unordered_map<string, double>> lookup;
        for (int i = 0; i < values.size(); ++i) {
            lookup[equations[i].first].emplace(equations[i].second, values[i]);
            if (values[i] != 0) {
                lookup[equations[i].second].emplace(equations[i].first, 1 / values[i]);
            }
        }

        vector<double> result;
        for (const auto& i : query) {
            unordered_set<string> visited;
            const auto tmp = check(i.first, i.second, lookup, &visited);
            if (tmp.first) {
                result.emplace_back(tmp.second);
            } else {
                result.emplace_back(-1);
            }
        }
        return result;
    }

private:
    pair<bool, double> check(string up, string down, 
            unordered_map<string, unordered_map<string, double>> &lookup,
            unordered_set<string> *visited) {
        if (lookup[up].find(down) != lookup[up].end()) {
            return {true, lookup[up][down]};
        }
        for (const auto& q : lookup[up]) {
            if (!visited->count(q.first)) {
                visited->emplace(q.first);
                const auto tmp = check(q.first, down, lookup, visited);
                if (tmp.first) {
                    return {true, q.second * tmp.second};
                }
            }
        }
        return {false, 0};
    }
};
