// Time:  O(m * n *  α(c)) = O(m * n)
// Space: O(m * n)

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        const int start = row * col, end = row * col + 1;
        UnionFind uf(row * col + 2);
        vector<vector<bool>> lookup(row, vector<bool>(col));
        for (int i = size(cells) - 1; i >= 0; --i) {
            const int r = cells[i][0] - 1, c = cells[i][1] - 1;
            for (const auto& [dr, dc] : directions) {
                const int nr = r + dr, nc = c + dc;
                if (!(0 <= nr && nr < row && 0 <= nc && nc < col && lookup[nr][nc])) {
                    continue;
                }
                uf.union_set(index(col, r, c), index(col, nr, nc));
            }
            if (r == 0) {
                uf.union_set(start, index(col, r, c));
            }
            if (r == row - 1) {
                uf.union_set(end, index(col, r, c));
            }
            if (uf.find_set(start) == uf.find_set(end)) {
                return i;
            }
            lookup[r][c] = true;
        }
        return -1;
    }

private:
    int index(int n, int i, int j) {
        return i * n + j;
    }

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
