// Time:  O(m * n * alpha(m + n)) = O(m + n)
// Space: O(m * n)

// bfs, union find
class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        const int m = size(grid), n = size(grid[0]);
        vector<UnionFind> uf1(m, UnionFind(n + 1));
        vector<UnionFind> uf2(n, UnionFind(m + 1));
        int d = 1, i = 0, j = 0;
        vector<pair<int, int>> q = {{i, j}};
        uf1[i].union_set(j, j + 1);
        uf2[j].union_set(i, i + 1);
        while (!empty(q)) {
            vector<pair<int, int>> new_q;
            for (const auto& [i, j] : q) {
                if (i == m - 1 && j == n - 1) {
                    return d;
                }
                while (uf1[i].right_set(j) <= min(j + grid[i][j], n - 1)) {
                    const int k = uf1[i].right_set(j);
                    new_q.emplace_back(i, k);
                    uf2[k].union_set(i, i + 1);
                    uf1[i].union_set(k, k + 1);
                }
                while (uf2[j].right_set(i) <= min(i+grid[i][j], m - 1)) {
                    const int k = uf2[j].right_set(i);
                    new_q.emplace_back(k, j);
                    uf1[k].union_set(j, j + 1);
                    uf2[j].union_set(k, k + 1);
                }
            }
            q = move(new_q);
            ++d;
        }
        return -1;
    }

private:
class UnionFind {
    public:
        UnionFind(int n)
         : set_(n)
         , rank_(n)
         , right_(n) {  // added
            iota(begin(set_), end(set_), 0);
            iota(begin(right_), end(right_), 0);  // added
        }

        int find_set(int x) {
           if (set_[x] != x) {
               set_[x] = find_set(set_[x]);  // Path compression.
           }
           return set_[x];
        }

        bool union_set(int x, int y) {
            x = find_set(x), y = find_set(y);
            if (x == y) {
                return false;
            }
            if (rank_[x] > rank_[y]) {
                swap(x, y);
            }
            set_[x] = y;  // Union by rank.
            if (rank_[x] == rank_[y]) {
                ++rank_[y];
            }
            right_[y] = max(right_[x], right_[y]);  // added
            return true;
        }

        int right_set(int x) {  // added
            return right_[find_set(x)];
        }

    private:
        vector<int> set_;
        vector<int> rank_;
        vector<int> right_;  // added
    };
};

// Time:  O(m * n * alpha(m + n)) = O(m + n)
// Space: O(m * n)
// bfs, bst
class Solution2 {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        const int m = size(grid), n = size(grid[0]);
        vector<set<int>> bst1(m);
        vector<set<int>> bst2(n);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                bst1[i].emplace(j);
                bst2[j].emplace(i);
            }
        }
        int d = 1, i = 0, j = 0;
        vector<pair<int, int>> q = {{i, j}};
        while (!empty(q)) {
            vector<pair<int, int>> new_q;
            for (const auto& [i, j] : q) {
                if (i == m - 1 && j == n - 1) {
                    return d;
                }
                for (auto it = bst1[i].lower_bound(j + 1);
                     it != end(bst1[i]) && *it <= j + grid[i][j];
                     it = bst1[i].erase(it)) {
                    new_q.emplace_back(i, *it);
                    bst2[*it].erase(i);
                }
                for (auto it = bst2[j].lower_bound(i + 1);
                     it != end(bst2[j]) && *it <= i + grid[i][j];
                     it = bst2[j].erase(it)) {
                    new_q.emplace_back(*it, j);
                    bst1[*it].erase(j);
                }
            }
            q = move(new_q);
            ++d;
        }
        return -1;
    }
};
