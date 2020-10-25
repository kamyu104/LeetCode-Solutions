// Time:  O(m * n * log(m * n) + m * n * α(m * n)) = O(m * n * log(m * n))
// Space: O(m * n)

class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        map<int, vector<pair<int, int>>> lookup;
        for (int i = 0; i < size(matrix); ++i) {
            for (int j = 0; j < size(matrix[0]); ++j) {
                lookup[matrix[i][j]].emplace_back(i, j);
            }
        }
        vector<int> rank(size(matrix) + size(matrix[0]));
        for (const auto& [x, pairs] : lookup) {
            vector<int> new_rank(rank);
            const auto& cb = [&new_rank](int x, int y, int z) {
                                 new_rank[x] = max(new_rank[y], new_rank[z]);
                             };
            UnionFind union_find(size(matrix) + size(matrix[0]), cb);
            for (const auto& [i, j] : pairs) {
                union_find.union_set(i, j + size(matrix));
            }
            for (const auto& [i, j] : pairs) {
                matrix[i][j] = rank[i] = rank[j + size(matrix)] = new_rank[union_find.find_set(i)] + 1;
            }
        }
        return matrix;
    }

private:
    class UnionFind {
    public:
        UnionFind(const int n, function<void(int, int, int)> cb)
         : set_(n)
         , rank_(n)
         , count_(n)
         , cb_(cb) {
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
                cb_(y_root, x_root, y_root);
            } else if (rank_[x_root] > rank_[y_root]) {
                set_[y_root] = x_root;
                cb_(x_root, x_root, y_root);
            } else {
                set_[y_root] = x_root;
                ++rank_[x_root];
                cb_(x_root, x_root, y_root);
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
        function<void(int, int, int)> cb_;
    };
};
