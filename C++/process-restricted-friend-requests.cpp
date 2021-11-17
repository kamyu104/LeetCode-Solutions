// Time:  O(n * (alpha(n) + r)) = O(n * r)
// Space: O(n)

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> result;
        UnionFind uf(n);
        for (const auto& request : requests) {
            int pu = uf.find_set(request[0]), pv = uf.find_set(request[1]);
            bool ok = true;
            for (const auto& restriction : restrictions) {
                int px = uf.find_set(restriction[0]), py = uf.find_set(restriction[1]);
                if ((px == pu && py == pv) || (px == pv && py == pu)) {
                    ok = false;
                    break;
                }
            }
            result.emplace_back(ok);
            if (ok) {
                uf.union_set(request[0], request[1]);
            }
        }
        return result;
    }

private:
    class UnionFind {
    public:
        UnionFind(const int n)
         : set_(n)
         , rank_(n)  {
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
            return true;
        }

    private:
        vector<int> set_;
        vector<int> rank_;
    };
};
