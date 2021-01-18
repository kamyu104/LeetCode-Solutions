// Time:  O(n^3)
// Space: O(n^2)

class Solution {
private:
    enum Location {HOLE, MOUSE_START, CAT_START};
    enum Result {DRAW, MOUSE, CAT};

public:
    int catMouseGame(vector<vector<int>>& graph) {
        vector<vector<vector<int>>> degree(size(graph), vector<vector<int>>(size(graph), vector<int>(2)));
        unordered_set<int> ignore(cbegin(graph[HOLE]), cend(graph[HOLE]));
        for (int m = 0; m < size(graph); ++m) {
            for (int c = 0; c < size(graph); ++c) {
                degree[m][c][MOUSE - 1] = size(graph[m]);
                degree[m][c][CAT - 1] = size(graph[c]) - ignore.count(c);
            }
        }
        vector<vector<vector<int>>> color(size(graph), vector<vector<int>>(size(graph), vector<int>(2)));
        queue<tuple<int, int, int, int>> q;
        for (int i = 0; i < size(graph); ++i) {
            if (i == HOLE) {
                continue;
            }
            color[HOLE][i][CAT - 1] = MOUSE;
            q.emplace(HOLE, i, CAT, MOUSE);
            for (const auto& t : {MOUSE, CAT}) {
                color[i][i][t - 1] = CAT;
                q.emplace(i, i, t, CAT);
            }
        }
        while (!empty(q)) {
            const auto [i, j, t, c] = q.front(); q.pop();
            for (const auto& [ni, nj, nt] : parents(graph, i, j, t)) {
                if (color[ni][nj][nt - 1] != DRAW) {
                    continue;
                }
                if (nt == c) {
                    color[ni][nj][nt - 1] = c;
                    q.emplace(ni, nj, nt, c);
                    continue;
                }
                --degree[ni][nj][nt - 1];
                if (!degree[ni][nj][nt - 1]) {
                    color[ni][nj][nt - 1]= c;
                    q.emplace(ni, nj, nt, c);
                }
            }
        }
        return color[MOUSE_START][CAT_START][MOUSE - 1];
    }

private:
    vector<tuple<int, int, int>> parents(const vector<vector<int>>& graph,
                                         int m, int c, int t) {
        vector<tuple<int, int, int>> result;
        if (t == CAT) {
            for (const auto& nm : graph[m]) {
                result.emplace_back(nm, c, MOUSE ^ CAT ^ t);
            }
        } else {
            for (const auto& nc : graph[c]) {
                if (nc != HOLE) {
                    result.emplace_back(m, nc, MOUSE ^ CAT ^ t);
                }
            }
        }
        return result;
    }
};

// Time:  O(n^3)
// Space: O(n^2)
class Solution2 {
private:
    enum Location {HOLE, MOUSE_START, CAT_START};
    enum Result {DRAW, MOUSE, CAT};

public:
    int catMouseGame(vector<vector<int>>& graph) {
        vector<vector<vector<int>>> degree(size(graph), vector<vector<int>>(size(graph), vector<int>(2)));
        unordered_set<int> ignore(cbegin(graph[HOLE]), cend(graph[HOLE]));
        for (int m = 0; m < size(graph); ++m) {
            for (int c = 0; c < size(graph); ++c) {
                degree[m][c][MOUSE - 1] = size(graph[m]);
                degree[m][c][CAT - 1] = size(graph[c]) - ignore.count(c);
            }
        }
        vector<vector<vector<int>>> color(size(graph), vector<vector<int>>(size(graph), vector<int>(2)));
        queue<tuple<int, int, int>> q1;
        queue<tuple<int, int, int>> q2;
        for(int i = 0; i < size(graph); ++i) {
            if (i == HOLE) {
                continue;
            }
            color[HOLE][i][CAT - 1] = MOUSE;
            q1.emplace(HOLE, i, CAT);
            for (const auto& t : {MOUSE, CAT}) {
                color[i][i][t - 1] = CAT;
                q2.emplace(i, i, t);
            }
        }
        while (!empty(q1)) {
            const auto [i, j, t] = q1.front(); q1.pop();
            for (const auto& [ni, nj, nt] : parents(graph, i, j, t)) {
                if (color[ni][nj][nt - 1] != DRAW) {
                    continue;
                }
                if (t == CAT) {
                    color[ni][nj][nt - 1] = MOUSE;
                    q1.emplace(ni, nj, nt);
                    continue;
                }
                --degree[ni][nj][nt - 1];
                if (!degree[ni][nj][nt - 1]) {
                    color[ni][nj][nt - 1] = MOUSE;
                    q1.emplace(ni, nj, nt);
                }
            }
        }
        while (!empty(q2)) {
            const auto [i, j, t] = q2.front(); q2.pop();
            for (const auto& [ni, nj, nt] : parents(graph, i, j, t)) {
                if (color[ni][nj][nt - 1] != DRAW) {
                    continue;
                }
                if (t == MOUSE) {
                    color[ni][nj][nt - 1] = CAT;
                    q2.emplace(ni, nj, nt);
                    continue;
                }
                --degree[ni][nj][nt - 1];
                if (!degree[ni][nj][nt - 1]) {
                    color[ni][nj][nt - 1] = CAT;
                    q2.emplace(ni, nj, nt);
                }
            }
        }
        return color[MOUSE_START][CAT_START][MOUSE - 1];
    }

private:
    vector<tuple<int, int, int>> parents(const vector<vector<int>>& graph,
                                         int m, int c, int t) {
        vector<tuple<int, int, int>> result;
        if (t == CAT) {
            for (const auto& nm : graph[m]) {
                result.emplace_back(nm, c, MOUSE ^ CAT ^ t);
            }
        } else {
            for (const auto& nc : graph[c]) {
                if (nc != HOLE) {
                    result.emplace_back(m, nc, MOUSE ^ CAT ^ t);
                }
            }
        }
        return result;
    }
};
