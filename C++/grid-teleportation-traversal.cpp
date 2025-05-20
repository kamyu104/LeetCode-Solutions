// Time:  O(m * n)
// Space: O(m * n)

// 0-1 bfs
class Solution {
public:
    int minMoves(vector<string>& matrix) {
        static const vector<pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1},
                                                          {1, 0}, {-1, 0}};
        const int m = size(matrix), n = size(matrix[0]);
        vector<vector<pair<int, int>>> lookup(26);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '.' || matrix[i][j] == '#') {
                    continue;
                }
                lookup[matrix[i][j] - 'A'].emplace_back(i, j);
            }
        }
        vector<vector<bool>> lookup2(m, vector<bool>(n));
        deque<tuple<int, int, int>> dq = {{0, 0, 0}};
        while (!empty(dq)) {
            const auto [step, i, j] = dq.front(); dq.pop_front();
            if (lookup2[i][j]) {
                continue;
            }
            lookup2[i][j] = true;
            if (i == m - 1 && j == n - 1) {
                return step;
            }
            for (const auto& [di, dj] : DIRECTIONS) {
                const int ni = i + di, nj = j + dj;
                if (!(0 <= ni && ni < m && 0 <= nj && nj < n && matrix[ni][nj] != '#' && !lookup2[ni][nj])) {
                    continue;
                }
                dq.emplace_back(step + 1, ni, nj);
            }
            if (matrix[i][j] == '.') {
                continue;
            }
            for (const auto& [ni, nj] : lookup[matrix[i][j] - 'A']) {
                if (lookup2[ni][nj]) {
                    continue;
                }
                dq.emplace_front(step, ni, nj);
            }
            lookup[matrix[i][j] - 'A'].clear();
        }
        return -1;
    }
};
