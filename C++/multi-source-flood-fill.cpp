// Time:  O(n * m)
// Space: O(n * m)

// bfs, flood fill
class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        static const vector<pair<int, int>>& DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        vector<vector<int>> result(n, vector<int>(m));
        vector<vector<int>> lookup(n, vector<int>(m, -1));
        vector<pair<int, int>> q;
        for (const auto& x : sources) {
            const auto& r = x[0], &c = x[1], &color = x[2];
            lookup[r][c] = 0;
            result[r][c] = color;
            q.emplace_back(r, c);
        }
        while (!empty(q)) {
            vector<pair<int, int>> new_q;
            for (const auto& [r, c] : q) {
                for (const auto& [dr, dc] : DIRECTIONS) {
                    const auto& nr = r + dr, &nc = c + dc;
                    if (!(0 <= nr && nr < n && 0 <= nc && nc < m)) {
                        continue;
                    }
                    if (lookup[nr][nc] == -1) {
                        lookup[nr][nc] = lookup[r][c] + 1;
                        result[nr][nc] = result[r][c];
                        new_q.emplace_back(nr, nc);
                    } else if (lookup[nr][nc] == lookup[r][c] + 1) {
                        result[nr][nc] = max(result[nr][nc], result[r][c]);
                    }
                }
            }
            q = move(new_q);
        }
        return result;
    }
};
