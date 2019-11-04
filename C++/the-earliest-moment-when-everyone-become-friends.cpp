// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int earliestAcq(vector<vector<int>>& logs, int N) {
        sort(logs.begin(), logs.end());
        UnionFind union_find(N);
        for (const auto& log : logs) {
            union_find.union_set(log[1], log[2]);
            if (union_find.count() == 1) {
                return log[0];
            }
        }
        return -1;
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
        
        int count() const {
            return count_;
        }

    private:
        vector<int> set_;
        int count_;
    };
};
