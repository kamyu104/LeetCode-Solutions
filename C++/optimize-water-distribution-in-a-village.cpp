// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        vector<tuple<int, int, int>> nodes;
        for (int i = 0; i < wells.size(); ++i) {
            nodes.emplace_back(wells[i], 0, i + 1);
        }
        for (int i = 0; i < pipes.size(); ++i) {
            nodes.emplace_back(pipes[i][2], pipes[i][0], pipes[i][1]);
        }
        sort(nodes.begin(), nodes.end());
        int result = 0;
        UnionFind union_find(n + 1);
        for (const auto& [c, x, y] : nodes) {
            if (!union_find.union_set(x, y)) {
                continue;
            }
            result += c;
            if (union_find.count() == 1) {
                break;
            }
        }
        return result;
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
