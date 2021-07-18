// Time:  O(nlogk + mlogk), k is max(max(vals), n-1)
// Space: O(n + logk)

class Solution {
private:
    class Trie {
    public:
        Trie(int bit_length)
         : bit_length_(bit_length)
         , nodes_(1) {}

        void insert(int num, int v) {
            int idx = 0;
            for (int i = bit_length_; i >= 0; --i) {
                int curr = (num >> i) & 1;
                if (!nodes_[idx][curr]) {
                    if (!empty(pools_)) {
                        nodes_[idx][curr] = pools_.back(); pools_.pop_back();
                    } else {
                        nodes_.emplace_back();
                        nodes_[idx][curr] = size(nodes_) - 1;
                    }
                }
                int new_idx = nodes_[idx][curr];
                nodes_[new_idx][2] += v;
                if (!nodes_[new_idx][2]) {
                    nodes_[idx][curr] = 0;
                    pools_.emplace_back(new_idx);
                }
                idx = new_idx;
            }
        }

        int query(int num) {
            int result = 0, idx = 0;
            for (int i = bit_length_; i >= 0; --i) {
                int curr = (num >> i) & 1;
                if (nodes_[idx][1 ^ curr]) {
                    idx = nodes_[idx][1 ^ curr];
                    result |= 1 << i;
                } else {
                    idx = nodes_[idx][curr];
                }
            }
            return result;
        }

    private:
        const int bit_length_;
        vector<array<int, 3>> nodes_;
        vector<int> pools_;
    };

public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < size(parents); ++i) {
            adj[parents[i]].emplace_back(i);
        }
        int max_val = size(parents) - 1;
        unordered_map<int, vector<pair<int, int>>> qs;
        for (int i = 0; i < size(queries); ++i) {
            qs[queries[i][0]].emplace_back(i, queries[i][1]);
            max_val = max(max_val, queries[i][1]);
        }
        vector<int> result(size(queries));
        Trie trie(bit_length(max_val));
        iter_dfs(adj, qs, adj[-1][0], &trie, &result);
        return result;
    }

private:
    void iter_dfs(const unordered_map<int, vector<int>>& adj,
                  const unordered_map<int, vector<pair<int, int>>>& qs,
                  int node,
                  Trie *trie,
                  vector<int> *result) {

        vector<pair<int, int>> stk{{1, node}};
        while (!empty(stk)) {
            const auto [step, node] = stk.back(); stk.pop_back();
            if (step == 1) {
                trie->insert(node, 1);
                if (qs.count(node)) {
                    for (const auto& [i, val] : qs.at(node)) {
                        (*result)[i] = trie->query(val);
                    }
                }
                stk.emplace_back(2, node);
                if (adj.count(node)) {
                    for (const auto& child : adj.at(node)) {
                        stk.emplace_back(1, child);
                    }
                }
            } else if (step == 2) {
                trie->insert(node, -1);
            }
        }
    }

    int bit_length(int x) {
        return x != 0 ? 32 - __builtin_clz(x) : 1;
    }
};

// Time:  O(nlogk + mlogk), k is max(max(vals), n-1)
// Space: O(n + logk)
class Solution2 {
private:
    class Trie {
    public:
        Trie(int bit_length)
         : bit_length_(bit_length)
         , nodes_(1) {}

        void insert(int num, int v) {
            int idx = 0;
            for (int i = bit_length_; i >= 0; --i) {
                int curr = (num >> i) & 1;
                if (!nodes_[idx][curr]) {
                    if (!empty(pools_)) {
                        nodes_[idx][curr] = pools_.back(); pools_.pop_back();
                    } else {
                        nodes_.emplace_back();
                        nodes_[idx][curr] = size(nodes_) - 1;
                    }
                }
                int new_idx = nodes_[idx][curr];
                nodes_[new_idx][2] += v;
                if (!nodes_[new_idx][2]) {
                    nodes_[idx][curr] = 0;
                    pools_.emplace_back(new_idx);
                }
                idx = new_idx;
            }
        }

        int query(int num) {
            int result = 0, idx = 0;
            for (int i = bit_length_; i >= 0; --i) {
                int curr = (num >> i) & 1;
                if (nodes_[idx][1 ^ curr]) {
                    idx = nodes_[idx][1 ^ curr];
                    result |= 1 << i;
                } else {
                    idx = nodes_[idx][curr];
                }
            }
            return result;
        }

    private:
        const int bit_length_;
        vector<array<int, 3>> nodes_;
        vector<int> pools_;
    };

public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < size(parents); ++i) {
            adj[parents[i]].emplace_back(i);
        }
        int max_val = size(parents) - 1;
        unordered_map<int, vector<pair<int, int>>> qs;
        for (int i = 0; i < size(queries); ++i) {
            qs[queries[i][0]].emplace_back(i, queries[i][1]);
            max_val = max(max_val, queries[i][1]);
        }
        vector<int> result(size(queries));
        Trie trie(bit_length(max_val));
        dfs(adj, qs, adj[-1][0], &trie, &result);
        return result;
    }

private:
    void dfs(const unordered_map<int, vector<int>>& adj,
             const unordered_map<int, vector<pair<int, int>>>& qs,
             int node,
             Trie *trie,
             vector<int> *result) {

        trie->insert(node, 1);
        if (qs.count(node)) {
            for (const auto& [i, val] : qs.at(node)) {
                (*result)[i] = trie->query(val);
            }
        }
        if (adj.count(node)) {
            for (const auto& child : adj.at(node)) {
                dfs(adj, qs, child, trie, result);
            }
        }
        trie->insert(node, -1);
    }

    int bit_length(int x) {
        return x != 0 ? 32 - __builtin_clz(x) : 1;
    }
};
