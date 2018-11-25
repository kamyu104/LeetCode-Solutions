// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        static const int MAX_ROW = 10000;
        UnionFind union_find(2 * MAX_ROW);
        for (const auto& stone : stones) {
            union_find.union_set(stone[0], stone[1] + MAX_ROW);
        }
        unordered_set<int> components;
        for (const auto& stone : stones) {
            components.emplace(union_find.find_set(stone[0]));
        }
        return stones.size() - components.size();
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

        void union_set(const int x, const int y) {
            int x_root = find_set(x), y_root = find_set(y);
            if (x_root != y_root) {
                set_[min(x_root, y_root)] = max(x_root, y_root);
            }
        }

    private:
        vector<int> set_;
    };
};
