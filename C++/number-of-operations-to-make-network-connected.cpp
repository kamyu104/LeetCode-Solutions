// Time:  O(|E| + |V|)
// Space: O(|V|)

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        UnionFind union_find(n);
        for (const auto& c : connections) {
            union_find.union_set(c[0], c[1]);
        }
        return union_find.size() - 1;
    }

private:
    class UnionFind {
    public:
        UnionFind(const int n) : set_(n), size_(n) {
            iota(set_.begin(), set_.end(), 0);
        }

        int find_set(const int x) {
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
        }

        bool union_set(const int x, const int y) {
            int x_root = find_set(x), y_root = find_set(y);
            if (x_root == y_root) {
                return false;
            }
            set_[min(x_root, y_root)] = max(x_root, y_root);
            --size_;
            return true;
        }

        int size() const {
            return size_;
        }

    private:
        vector<int> set_;
        int size_;
    };
};

// Time:  O(|E| + |V|)
// Space: O(|V|)
class Solution2 {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        unordered_map<int, vector<int>> G;
        for (const auto& c : connections) {
            G[c[0]].emplace_back(c[1]);
            G[c[1]].emplace_back(c[0]);
        }
        int result = 0;
        unordered_set<int> lookup;
        for (int i = 0; i < n; ++i) {
            result += dfs(G, i, &lookup);
        }
        return result - 1;
    }

private:
    int dfs(const unordered_map<int, vector<int>>& G,
            int i, unordered_set<int> *lookup) {
        if (lookup->count(i)) {
            return 0;
        }
        lookup->emplace(i);
        if (G.count(i)) {
            for (const auto& j : G.at(i)) {
                dfs(G, j, lookup);
            }
        }
        return 1;
    }
};
