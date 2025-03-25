// Time:  O(n^2 * m)
// Space: O(n * m)

// graph, flood fill, bfs
class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        vector<vector<int>> adj(size(properties));
        vector<unordered_set<int>> p_set(size(properties));
        for (int i = 0; i < size(properties); ++i) {
            p_set[i] = unordered_set<int>(cbegin(properties[i]), cend(properties[i]));
        }
        for (int i = 0; i < size(p_set); ++i) {
            for (int j = i + 1; j < size(p_set); ++j) {
                int cnt = 0;
                for (const auto& x : p_set[i]) {
                    cnt += p_set[j].count(x);
                }
                if (cnt >= k) {
                    adj[i].emplace_back(j);
                    adj[j].emplace_back(i);
                }
            }
        }
        vector<bool> lookup(size(properties));
        const auto& bfs = [&](int u) {
            vector<int> q = {u};
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (lookup[v]) {
                            continue;
                        }
                        lookup[v] = true;
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
        };
       
        int result = 0;
        for (int i = 0; i < size(properties); ++i) {
            if (lookup[i]) {
                continue;
            }
            bfs(i);
            ++result;
        }
        return result;
    }
};

// Time:  O(n^2 * m)
// Space: O(n * m)
// graph, union find
class Solution2 {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        vector<vector<int>> adj(size(properties));
        vector<unordered_set<int>> p_set(size(properties));
        for (int i = 0; i < size(properties); ++i) {
            p_set[i] = unordered_set<int>(cbegin(properties[i]), cend(properties[i]));
        }
        int result = size(properties);
        UnionFind uf(size(properties));
        for (int i = 0; i < size(p_set); ++i) {
            for (int j = i + 1; j < size(p_set); ++j) {
                int cnt = 0;
                for (const auto& x : p_set[i]) {
                    cnt += p_set[j].count(x);
                }
                if (cnt >= k) {
                    result -= uf.union_set(i, j);
                }
            }
        }
        return result;
    }

private:
    class UnionFind {
    public:
        UnionFind(int n)
            : set_(n)
            , rank_(n) {
            iota(set_.begin(), set_.end(), 0);
        }

        int find_set(int x) {
            if (set_[x] != x) {
                set_[x] = find_set(set_[x]);  // Path compression.
            }
            return set_[x];
        }

        bool union_set(int x, int y) {
            x = find_set(x), y = find_set(y);
            if (x == y) {
                return false;
            }
            if (rank_[x] > rank_[y]) {
                swap(x, y);
            }
            set_[x] = y;  // Union by rank.
            if (rank_[x] == rank_[y]) {
                ++rank_[y];
            }
            return true;
        }

    private:
        vector<int> set_;
        vector<int> rank_;
    };
};
