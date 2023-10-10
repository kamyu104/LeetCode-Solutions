// Time:  O(nlogr), r is sum(values)
// Space: O(n)

// iterative dfs, trie, greedy
class Solution {
private:
    class Trie {
    public:
        Trie(int bit_length)
         : bit_length_(bit_length)
         , nodes_(1) {}

        void insert(int64_t num) {
            int idx = 0;
            for (int i = bit_length_ - 1; i >= 0; --i) {
                int64_t curr = (num >> i) & 1;
                if (!nodes_[idx][curr]) {
                    nodes_.emplace_back();
                    nodes_[idx][curr] = size(nodes_) - 1;
                }
                idx = nodes_[idx][curr];
            }
        }

        int64_t query(int64_t num) {
            if (size(nodes_) == 1) {
                return -1;
            }
            int64_t result = 0, idx = 0;
            for (int i = bit_length_ - 1; i >= 0; --i) {
                int64_t curr = (num >> i) & 1;
                if (nodes_[idx][1 ^ curr]) {
                    idx = nodes_[idx][1 ^ curr];
                    result |= 1ll << i;
                } else {
                    idx = nodes_[idx][curr];
                }
            }
            return result;
        }

    private:
        const int bit_length_;
        vector<array<int, 2>> nodes_;
    };

public:
    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) {
        vector<vector<int>> adj(size(values));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        
        const auto& iter_dfs = [&]() {
            vector<int64_t> lookup(size(values));
            vector<tuple<int, int, int>> stk = {{1, 0, -1}};
            while (!empty(stk)) {
                const auto [step, u, p] = stk.back(); stk.pop_back();
                if (step == 1) {
                    stk.emplace_back(2, u, p);
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        stk.emplace_back(1, v, u);
                    }
                } else if (step == 2) {
                    lookup[u] = values[u];
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        lookup[u] += lookup[v];
                    }
                }
            }
            return lookup;
        };
        const auto& lookup = iter_dfs();
        Trie trie(bit_length(lookup[0]));
        const auto& iter_dfs2 = [&]() {
            using RET = int64_t;
            RET result{0};
            vector<tuple<int, int, int, shared_ptr<RET>, RET *>> stk = {{1, 0, -1, nullptr, &result}};
            while (!empty(stk)) {
                const auto [step, u, p, new_ret, ret] = stk.back(); stk.pop_back();
                if (step == 1) {
                    *ret = max(*ret, trie.query(lookup[u]));
                    stk.emplace_back(3, u, p, new_ret, ret);
                    for (const auto& v : adj[u]) {
                        if (v == p) {
                            continue;
                        }
                        const auto& new_ret = make_shared<RET>(0);
                        stk.emplace_back(2, v, u, new_ret, ret);
                        stk.emplace_back(1, v, u, nullptr, new_ret.get());
                    }
                } else if (step == 2) {
                    *ret = max(*ret, *new_ret);
                } else if (step == 3) {
                    trie.insert(lookup[u]);
                }
            }
            return result;
        };
        return iter_dfs2();
    }

private:
    int bit_length(int64_t x) {
        return x != 0 ? 64 - __builtin_clzll(x) : 1;
    }
};

// Time:  O(nlogr), r is sum(values)
// Space: O(n)
// dfs, trie, greedy
class Solution2 {
private:
    class Trie {
    public:
        Trie(int bit_length)
         : bit_length_(bit_length)
         , nodes_(1) {}

        void insert(int64_t num) {
            int idx = 0;
            for (int i = bit_length_ - 1; i >= 0; --i) {
                int64_t curr = (num >> i) & 1;
                if (!nodes_[idx][curr]) {
                    nodes_.emplace_back();
                    nodes_[idx][curr] = size(nodes_) - 1;
                }
                idx = nodes_[idx][curr];
            }
        }

        int64_t query(int64_t num) {
            if (size(nodes_) == 1) {
                return -1;
            }
            int64_t result = 0, idx = 0;
            for (int i = bit_length_ - 1; i >= 0; --i) {
                int64_t curr = (num >> i) & 1;
                if (nodes_[idx][1 ^ curr]) {
                    idx = nodes_[idx][1 ^ curr];
                    result |= 1ll << i;
                } else {
                    idx = nodes_[idx][curr];
                }
            }
            return result;
        }

    private:
        const int bit_length_;
        vector<array<int, 2>> nodes_;
    };

public:
    long long maxXor(int n, vector<vector<int>>& edges, vector<int>& values) {
        vector<vector<int>> adj(size(values));
        for (const auto& e : edges) {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        vector<int64_t> lookup(size(values));
        const function<int64_t(int, int)> dfs = [&](int u, int p) {
            lookup[u] = values[u];
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                lookup[u] += dfs(v, u);
            }
            return lookup[u];
        };
        dfs(0, -1);
        Trie trie(bit_length(lookup[0]));
        const function<int64_t(int, int)> dfs2 = [&](int u, int p) {
            int64_t result = max(trie.query(lookup[u]), static_cast<int64_t>(0));
            for (const auto& v : adj[u]) {
                if (v == p) {
                    continue;
                }
                result = max(result, dfs2(v, u));
            }
            trie.insert(lookup[u]);
            return result;
        };
        return dfs2(0, -1);
    }

private:
    int bit_length(int64_t x) {
        return x != 0 ? 64 - __builtin_clzll(x) : 1;
    }
};
