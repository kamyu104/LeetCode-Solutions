// Time:  O(n * alpha(n)) = O(n)
// Space: O(n)

// bfs, union find
class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<bool> lookup(n);
        for (const auto& i : banned) {
            lookup[i] = true;
        }
        int d = 0;
        vector<int> result(n, -1);
        result[p] = d++;
        UnionFind uf(n + 2);
        uf.union_set(p, p + 2);
        vector<int> q = {p};
        while (!empty(q)) {
            vector<int> new_q;
            for (const auto& p : q) {
                const int left = 2 * max(p - (k - 1), 0) + (k - 1) - p;
                const int right = 2 * min(p + (k - 1), n - 1) - (k - 1) - p;
                for (int p = uf.right_set(left); p <= right; p = uf.right_set(p)) {
                    if (!lookup[p]) {
                        result[p] = d;
                        new_q.emplace_back(p);
                    }
                    uf.union_set(p, p + 2);
                }
            }
            q = move(new_q);
            ++d;
        }
        return result;
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

// Time:  O(nlogn)
// Space: O(n)
// bfs, bst
class Solution2 {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        vector<bool> lookup(n);
        for (const auto& i : banned) {
            lookup[i] = true;
        }
        int d = 0;
        vector<int> result(n, -1);
        result[p] = d++;
        vector<set<int>> bst(2);
        for (int i = 0; i < n; ++i) {
            bst[i % 2].emplace(i);
        }
        bst[p % 2].erase(p);
        vector<int> q = {p};
        while (!empty(q)) {
            vector<int> new_q;
            for (const auto& p : q) {
                const int left = 2 * max(p - (k - 1), 0) + (k - 1) - p;
                const int right = 2 * min(p + (k - 1), n - 1) - (k - 1) - p;
                for (auto it = bst[left % 2].lower_bound(left);
                     it != end(bst[left % 2]) && *it <= right;
                     it = bst[left % 2].erase(it)) {
                    if (!lookup[*it]) {
                        result[*it] = d;
                        new_q.emplace_back(*it);
                    }
                }
            }
            q = move(new_q);
            ++d;
        }
        return result;
    }
};
