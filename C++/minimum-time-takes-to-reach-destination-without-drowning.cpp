// Time:  O(m * n)
// Space: O(m * n)

// bfs
class Solution {
public:
    int minimumSeconds(vector<vector<string>>& land) {
        static const vector<pair<int, int>> DIRECTIONS {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        vector<vector<int>> lookup(size(land), vector<int>(size(land[0])));
        vector<tuple<int, int, int>> q;
        int i0 = -1, j0 = -1;
        for (int i = 0; i < size(land); ++i) {
            for (int j = 0; j < size(land[0]); ++j) {
                if (land[i][j] == "*") {
                    q.emplace_back(i, j, -1);
                    lookup[i][j] = -1;
                } else if (land[i][j] == "S") {
                    i0 = i, j0 = j;
                }
            }
        }
        q.emplace_back(i0, j0, 0);
        while (!empty(q)) {
            vector<tuple<int, int, int>> new_q;
            for (const auto& [i, j, d] : q) {
                if (land[i][j] == "D") {
                    return d;
                }
                for (const auto& [di, dj] : DIRECTIONS) {
                    const int ni = i + di, nj = j + dj;
                    if (!(0 <= ni && ni < size(land) && 0 <= nj && nj < size(land[0]) && land[ni][nj] != "X" && lookup[ni][nj] != -1)) {
                        continue;
                    }
                    if (d != -1) {
                        if (lookup[ni][nj] == 0) {
                            lookup[ni][nj] = d + 1;
                            new_q.emplace_back(ni, nj, d + 1);
                        }
                    } else if (land[ni][nj] != "D") {
                        lookup[ni][nj] = -1;
                        new_q.emplace_back(ni, nj, -1);
                    }
                }
            }
            q = move(new_q);
        }
        return -1;
    }
};
