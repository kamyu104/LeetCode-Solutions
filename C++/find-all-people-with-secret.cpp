// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(begin(meetings), end(meetings), [](const auto& a, const auto& b) { return a[2] < b[2]; });
        unordered_set<int> result = {0, firstPerson};
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < size(meetings); ++i) {
            int x = meetings[i][0], y = meetings[i][1];
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
            if (i + 1 != size(meetings) && meetings[i + 1][2] == meetings[i][2]) {
                continue;
            }
            vector<int> q;
            for (const auto& [k, _] : adj) {
                if (result.count(k)) {
                    q.emplace_back(k);
                }
            }
            while (!empty(q)) {
                vector<int> new_q;
                for (const auto& u : q) {
                    for (const auto& v : adj[u]) {
                        if (result.count(v)) {
                            continue;
                        }
                        result.emplace(v);
                        new_q.emplace_back(v);
                    }
                }
                q = move(new_q);
            }
            adj.clear();
        }
        return {cbegin(result), cend(result)};
    }
};

// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(begin(meetings), end(meetings), [](const auto& a, const auto& b) { return a[2] < b[2]; });
        unordered_set<int> result = {0, firstPerson};
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < size(meetings); ++i) {
            int x = meetings[i][0], y = meetings[i][1];
            adj[x].emplace_back(y);
            adj[y].emplace_back(x);
            if (i + 1 != size(meetings) && meetings[i + 1][2] == meetings[i][2]) {
                continue;
            }
            vector<int> stk;
            for (const auto& [k, _] : adj) {
                if (result.count(k)) {
                    stk.emplace_back(k);
                }
            }
            while (!empty(stk)) {
                int u = stk.back(); stk.pop_back();
                for (const auto& v : adj[u]) {
                    if (result.count(v)) {
                        continue;
                    }
                    result.emplace(v);
                    stk.emplace_back(v);
                }
            }
            adj.clear();
        }
        return {cbegin(result), cend(result)};
    }
};

// Time:  O(nlogn)
// Space: O(n)
class Solution3 {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        sort(begin(meetings), end(meetings), [](const auto& a, const auto& b) { return a[2] < b[2]; });
        UnionFind uf(n);
        uf.union_set(0, firstPerson);
        unordered_set<int> group;
        for (int i = 0; i < size(meetings); ++i) {
            int x = meetings[i][0], y = meetings[i][1];
            group.emplace(x);
            group.emplace(y);
            uf.union_set(x, y);
            if (i + 1 != size(meetings) && meetings[i + 1][2] == meetings[i][2]) {
                continue;
            }
            for (const auto& x: group) {
                if (uf.find_set(x) != uf.find_set(0)) {
                    uf.reset(x);
                }
            }
            group.clear();
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (uf.find_set(i) == uf.find_set(0)) {
                result.emplace_back(i);
            }
        }
        return result;
    }

private:
    class UnionFind {
    public:
        UnionFind(int n)
         : set_(n)
         , rank_(n)  {
            iota(set_.begin(), set_.end(), 0);
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
            return true;
        }

        void reset(int x) {
            set_[x] = x;
            rank_[x] = 0;
         }

    private:
        vector<int> set_;
        vector<int> rank_;
    };
};
