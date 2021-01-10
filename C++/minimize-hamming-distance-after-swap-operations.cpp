// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        vector<unordered_set<int>> adj(size(source));
        for (const auto& swap : allowedSwaps) {
            adj[swap[0]].emplace(swap[1]);
            adj[swap[1]].emplace(swap[0]);
        }
        vector<bool> lookup(size(source));
        int result = 0;
        for (int i = 0; i < size(source); ++i) {
            if (lookup[i]) {
                continue;
            }
            vector<int> idxs;
            iter_flood_fill(adj, i, &lookup, &idxs);
            unordered_map<int, int> source_cnt, target_cnt;
            for (const auto& i : idxs) {
                ++source_cnt[source[i]];
                ++target_cnt[target[i]];
            }
            for (const auto& [v , cnt] : source_cnt) {
                result += max(cnt - target_cnt[v], 0);
            }
        }
        return result;
    }

private:
    void iter_flood_fill(const vector<unordered_set<int>>& adj,
                         int node,
                         vector<bool> *lookup, vector<int> *idxs) {
        vector<int> stk = {node};
        while (!empty(stk)) {
            auto node = stk.back(); stk.pop_back();
            if ((*lookup)[node]) {
                continue;
            }
            (*lookup)[node] = true;
            idxs->emplace_back(node);
            for (const auto& child : adj[node]) {
                stk.emplace_back(child);
            }
        }
    }
};


// Time:  O(n * α(n)) ~= O(n)
// Space: O(n)
class Solution2 {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        UnionFind uf(size(source));
        for (const auto& swap : allowedSwaps) {
            uf.union_set(swap[0], swap[1]);
        }
        unordered_map<int, unordered_set<int>> groups;
        for (int i = 0; i < size(source); ++i) {
            groups[uf.find_set(i)].emplace(i);
        }
        int result = 0;
        for (const auto& [_, idxs] : groups) {
            unordered_map<int, int> source_cnt, target_cnt;
            for (const auto& i : idxs) {
                ++source_cnt[source[i]];
                ++target_cnt[target[i]];
            }
            for (const auto& [v , cnt] : source_cnt) {
                result += max(cnt - target_cnt[v], 0);
            }
        }
        return result;
    }

private:
    class UnionFind {
    public:
        UnionFind(const int n)
         : set_(n)
         , rank_(n)
         , count_(n) {
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
            if (rank_[x_root] < rank_[y_root]) {  // Union by rank.
                set_[x_root] = y_root;
            } else if (rank_[x_root] > rank_[y_root]) {
                set_[y_root] = x_root;
            } else {
                set_[y_root] = x_root;
                ++rank_[x_root];
            }
            --count_;
            return true;
        }

        int size() const {
            return count_;
        }

    private:
        vector<int> set_;
        vector<int> rank_;
        int count_;
    };
};
