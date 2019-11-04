// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int minimumCost(int N, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(),
             [](const auto& a, const auto& b) {
                return a[2] < b[2]; 
             });
        UnionFind union_find(N);
        int result = 0;
        for (const auto& c : connections) {
            if (union_find.union_set(c[0] - 1, c[1] - 1)) {
                result += c[2];
            }
        }
        return union_find.size() == 1 ? result : -1;
    }
    
private:
    class UnionFind {
    public:
        UnionFind(const int n) : set_(n), count_(n) {
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
            --count_;
            return true;
        }

        int size() const {
            return count_;
        }

    private:
        vector<int> set_;
        int count_;
    };
};
