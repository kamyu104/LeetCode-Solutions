// Time:  O(nlog*n) ~= O(n), n is the length of the positions
// Space: O(n)

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> cand1, cand2;
        unordered_map<int, int> parent;
        for (const auto& edge : edges) {
            if (!parent.count(edge[1])) {
                parent[edge[1]] = edge[0];
            } else {
                cand1 = {parent[edge[1]], edge[1]};
                cand2 = edge;
            }
        }

        UnionFind union_find(edges.size() + 1);
        for (const auto& edge : edges) {
            if (edge == cand2) {
                continue;
            }
            if (!union_find.union_set(edge[0], edge[1])) {
                return cand2.empty() ? edge : cand1;
            }
        }
        return cand2;
    }

private:
    class UnionFind {
        public:
            UnionFind(const int n) : set_(n) {
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
                return true;
            }

        private:
            vector<int> set_;
    };
};
