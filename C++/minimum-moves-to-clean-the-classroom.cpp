// Time:  O(m * n * 2^l)
// Space: O(m * n * 2^l)

// bfs, bitmasks
class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        static const vector<pair<int, int>> DIRECTIONS = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        const int m = size(classroom), n = size(classroom[0]);
        unordered_map<int, int> lookup;
        int r = -1, c = -1;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    r = i;
                    c = j;
                } else if (classroom[i][j] == 'L') {
                    lookup[i * n + j] = size(lookup);
                }
            }
        }
        
        vector<vector<vector<int>>> lookup2(m, vector<vector<int>>(n, vector<int>(1 << size(lookup), -1)));
        lookup2[r][c][0] = energy;
        vector<tuple<int, int, int, int>> q = {{r, c, 0, energy}};
        for (int result = 0; !empty(q); ++result) {
            vector<tuple<int, int, int, int>> new_q;
            for (const auto& [i, j, mask, e] : q) {
                if (lookup2[i][j][mask] != e) {
                    continue;
                }
                if (mask == (1 << size(lookup)) - 1) {
                    return result;
                }
                for (const auto& [di, dj] : DIRECTIONS) {
                    const int ni = i + di, nj = j + dj;
                    int ne = e - 1;
                    if (!(0 <= ni && ni < m && 0 <= nj && nj < n && classroom[ni][nj] != 'X' && ne >= 0)) {
                        continue;
                    }
                    int new_mask = mask;
                    if (classroom[ni][nj] == 'R') {
                        ne = energy;
                    } else if (classroom[ni][nj] == 'L') {
                        new_mask |= 1 << lookup[ni * n + nj];
                    }
                    if (ne <= lookup2[ni][nj][new_mask]) {
                        continue;
                    }
                    lookup2[ni][nj][new_mask] = ne;
                    new_q.emplace_back(ni, nj, new_mask, ne);
                }
            }
            q = move(new_q);
        }
        return -1;
    }
};
