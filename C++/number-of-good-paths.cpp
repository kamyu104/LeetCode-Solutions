// Time:  O(nlogn)
// Space: O(n)

// tree, sort, union find
class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        sort(begin(edges), end(edges), [&](const auto& x, const auto& y) {
            return max(vals[x[0]], vals[x[1]]) < max(vals[y[0]], vals[y[1]]);
        });
        int result = size(vals);
        UnionFind uf(vals);
        for (const auto& e : edges) {
            result += uf.union_set(e[0], e[1], max(vals[e[0]], vals[e[1]]));
        }
        return result;
    }

private:
    class UnionFind {
    public:
        UnionFind(const vector<int>& nums)
         : set_(size(nums))
         , rank_(size(nums))
         , cnt_(size(nums)) {  // added
            iota(set_.begin(), set_.end(), 0);
             for (int i = 0; i < size(nums); ++i) {
                 ++cnt_[i][nums[i]];  // added
             }
        }

        int find_set(int x) {
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
        }

        int union_set(int x, int y, int v) {  // modified
            x = find_set(x), y = find_set(y);
            if (x == y) {
                return 0;  // modified
            }
            if (rank_[x] > rank_[y]) {
                swap(x, y);
            }
            set_[x] = y;  // Union by rank.
            if (rank_[x] == rank_[y]) {
                ++rank_[y];
            }
            const int cx = cnt_[x][v], cy = cnt_[y][v];  // added
            cnt_[y] = {{v, cx + cy}};  // added
            return cx * cy;  // modified
        }

    private:
        vector<int> set_;
        vector<int> rank_;
        vector<unordered_map<int, int>> cnt_;  // added
    };
};
