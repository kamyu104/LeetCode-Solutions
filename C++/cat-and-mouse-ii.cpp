// Time:  O((m * n)^2 * (m + n))
// Space: O((m * n)^2)

class Solution {
    private:
    template <typename A, typename B, typename C>
    struct TupleHash {
        size_t operator()(const tuple<A, B, C>& p) const {
            size_t seed = 0;
            A a; B b; C c;
            tie(a, b, c) = p;
            seed ^= std::hash<A>{}(a) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<B>{}(b) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            seed ^= std::hash<C>{}(c) + 0x9e3779b9 + (seed<<6) + (seed>>2);
            return seed;
        }
    };
    using Lookup = unordered_map<tuple<int, int, int>, int, TupleHash<int, int, int>>;

    enum Result {DRAW, MOUSE, CAT};

public:
    bool canMouseWin(vector<string>& grid, int catJump, int mouseJump) {
        static const vector<pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        const int R = size(grid), C = size(grid[0]);
        const int N = R * C;
        unordered_set<int> WALLS;
        int FOOD = -1, MOUSE_START = -1, CAT_START = -1;
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] == 'M') {
                    MOUSE_START = r * C + c;
                } else if (grid[r][c] == 'C') {
                    CAT_START = r * C + c;
                } else if (grid[r][c] == 'F') {
                    FOOD = r * C + c;
                } else if (grid[r][c] == '#') {
                    WALLS.emplace(r * C + c);
                }
            }
        }

        vector<vector<vector<int>>> graph(N, vector<vector<int>>(2));
        unordered_map<int, int> jump = {{MOUSE, mouseJump}, {CAT, catJump}};
        for (int r = 0; r < R; ++r) {
            for (int c = 0; c < C; ++c) {
                if (grid[r][c] == '#') {
                    continue;
                }
                int pos = r * C + c;
                for (const auto& t : {MOUSE, CAT}) {
                    for (const auto& [dr, dc] : directions) {
                        for (int d = 0; d <= jump[t]; ++d) {
                            int nr = r + dr * d, nc = c + dc * d;
                            if (!(0 <= nr && nr < R && 0 <= nc && nc < C && grid[nr][nc] != '#')) {
                                break;
                            }
                            graph[pos][t - 1].emplace_back(nr * C + nc);
                        }
                    }
                }
            }
        }
        Lookup degree;
        for (int m = 0; m < size(graph); ++m) {
            for (int c = 0; c < size(graph); ++c) {
                degree[make_tuple(m, c, MOUSE)] = size(graph[m][MOUSE - 1]);
                degree[make_tuple(m, c, CAT)] = size(graph[c][CAT - 1]);
            }
        }
        Lookup color;
        queue<tuple<int, int, int, int>> q;
        for(int i = 0; i < size(graph); ++i) {
            if (WALLS.count(i) || i == FOOD) {
                continue;
            }
            color[make_tuple(FOOD, i, CAT)] = MOUSE;
            q.emplace(FOOD, i, CAT, MOUSE);
            color[make_tuple(i, FOOD, MOUSE)] = CAT;
            q.emplace(i, FOOD, MOUSE, CAT);
            for (const auto& t : {MOUSE, CAT}) {
                color[make_tuple(i, i, t)] = CAT;
                q.emplace(i, i, t, CAT);
            }
        }
        while (!empty(q)) {
            const auto [i, j, t, c] = q.front(); q.pop();
            for (const auto& [ni, nj, nt] : parents(graph, i, j, t)) {
                if (color[make_tuple(ni, nj, nt)] != DRAW) {
                    continue;
                }
                if (nt == c) {
                    color[make_tuple(ni, nj, nt)] = c;
                    q.emplace(ni, nj, nt, c);
                    continue;
                }
                --degree[make_tuple(ni, nj, nt)];
                if (!degree[make_tuple(ni, nj, nt)]) {
                    color[make_tuple(ni, nj, nt)] = c;
                    q.emplace(ni, nj, nt, c);
                }
            }
        }
        return color[make_tuple(MOUSE_START, CAT_START, MOUSE)] == MOUSE;
    }

private:
    vector<tuple<int, int, int>> parents(const vector<vector<vector<int>>>& graph,
                                         int m, int c, int t) {
        vector<tuple<int, int, int>> result;
        if (t == CAT) {
            for (const auto& nm : graph[m][(MOUSE ^ CAT ^ t) - 1]) {
                result.emplace_back(nm, c, MOUSE ^ CAT ^ t);
            }
        } else {
            for (const auto& nc : graph[c][(MOUSE ^ CAT ^ t) - 1]) {
                result.emplace_back(m, nc, MOUSE ^ CAT ^ t);
            }
        }
        return result;
    }
};
