// Time:  O(m * n * sqrt(m + n))
// Space: O(m * n)

// template from https://github.com/kth-competitive-programming/kactl/blob/main/content/graph/hopcroftKarp.h
bool dfs(int a, int L, vector<vector<int>>& g, vector<int>& btoa, vector<int>& A, vector<int>& B) {
    if (A[a] != L) return 0;
    A[a] = -1;
    for (int b : g[a]) if (B[b] == L + 1) {
        B[b] = 0;
        if (btoa[b] == -1 || dfs(btoa[b], L + 1, g, btoa, A, B))
            return btoa[b] = a, 1;
    }
    return 0;
}

int hopcroftKarp(vector<vector<int>>& g, vector<int>& btoa) {
    int res = 0;
    vector<int> A(g.size()), B(btoa.size()), cur, next;
    for (;;) {
        fill(begin(A), end(A), 0);
        fill(begin(B), end(B), 0);
        /// Find the starting nodes for BFS (i.e. layer 0).
        cur.clear();
        for (int a : btoa) if(a != -1) A[a] = -1;
        for (int a = 0; a < size(g); ++a) if(A[a] == 0) cur.push_back(a);
        /// Find all layers using bfs.
        for (int lay = 1;; lay++) {
            bool islast = 0;
            next.clear();
            for (int a : cur) for (int b : g[a]) {
                if (btoa[b] == -1) {
                    B[b] = lay;
                    islast = 1;
                }
                else if (btoa[b] != a && !B[b]) {
                    B[b] = lay;
                    next.push_back(btoa[b]);
                }
            }
            if (islast) break;
            if (next.empty()) return res;
            for (int a : next) A[a] = lay;
            cur.swap(next);
        }
        /// Use DFS to scan for augmenting paths.
        for (int a = 0; a < size(g); ++a)
            res += dfs(a, 0, g, btoa, A, B);
    }
}

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        vector<vector<int>> adj;
        vector<unordered_map<int, int>> ids(2);
        vector<vector<bool>> lookup(size(grid), vector<bool>(size(grid[0])));
        for (int i = 0; i < size(grid); ++i) {
            for (int j = 0; j < size(grid[0]); ++j) {
                if (!grid[i][j]) {
                    continue;
                }
                iter_dfs(grid, i, j, &lookup, &ids, &adj);
            }
        }
        vector<int> b(size(ids[1]), -1);
        return hopcroftKarp(adj, b);
    }

private:
    void iter_dfs(const vector<vector<int>>& grid, int i, int j,
                  vector<vector<bool>> *lookup,
                  vector<unordered_map<int, int>> *ids,
                  vector<vector<int>> *adj) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        if ((*lookup)[i][j]) {
            return;
        }
        auto get_id = [&grid, &ids](int i, int j, int color) {
            const int x = size(grid[0]) * i + j;
            if (!(*ids)[color].count(x)) {
                (*ids)[color][x] = size((*ids)[color]);
            }
            return (*ids)[color][x];
        };

        (*lookup)[i][j] = true;
        vector<tuple<int, int, int>> stk = {{i, j, (i + j) % 2}};
        while (!empty(stk)) {
            const auto [i, j, color] = stk.back(); stk.pop_back();
            for (const auto& [di, dj] : directions) {
                const int ni = i + di, nj = j + dj;
                if (!(0 <= ni && ni < size(grid) &&
                      0 <= nj && nj < size(grid[0]) &&
                      grid[ni][nj])) {
                    continue;
                }
                if (!color) {
                    const int x = get_id(i, j, color);
                    const int y = get_id(ni, nj, color ^ 1);
                    adj->resize(size((*ids)[0]));
                    (*adj)[x].emplace_back(y);
                }
                if ((*lookup)[ni][nj]) {
                    continue;
                }
                (*lookup)[ni][nj] = true;
                stk.emplace_back(ni, nj, color ^ 1);
            }
        }
    }
};
