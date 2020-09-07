// Time:  O(m * n)
// Space: O(m * n)

// topological sort solution
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        static const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                       {-1, 0}, {1, 0}};
        
        if (matrix.empty()) {
            return 0;
        }

        vector<vector<int>> in_degree(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                for (const auto& [di, dj] : directions) {
                    int ni = i + di, nj = j + dj;
                    if (!(0 <= ni && ni < matrix.size() &&
                          0 <= nj && nj < matrix[0].size() &&
                          matrix[ni][nj] > matrix[i][j])) {
                        continue;
                    }
                    ++in_degree[i][j];
                }
            }
        }
        vector<pair<int, int>> q;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (!in_degree[i][j]) {
                    q.emplace_back(i, j);
                }
            }
        }
        int result = 0;
        while (!q.empty()) {
            vector<pair<int, int>> new_q;
            for (const auto& [i, j] : q) {
                for (const auto& [di, dj] : directions) {
                    int ni = i + di, nj = j + dj;
                    if (!(0 <= ni && ni < matrix.size() &&
                          0 <= nj && nj < matrix[0].size() &&
                          matrix[i][j] > matrix[ni][nj])) {
                        continue;
                    }
                    if (--in_degree[ni][nj] == 0) {
                        new_q.emplace_back(ni, nj);
                    }
                }
            }
            q = move(new_q);
            ++result;
        }
        return result;
    }
};

// Time:  O(m * n)
// Space: O(m * n)
// dfs + memorization solution
class Solution2 {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return 0;
        }

        int result = 0;
        vector<vector<int>> max_lengths(matrix.size(), vector<int>(matrix[0].size()));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                result = max(result, longestpath(matrix, i, j, &max_lengths));
            }
        }
        return result;
    }

private:
    int longestpath(const vector<vector<int>>& matrix, const int i, const int j,
                    vector<vector<int>> *max_lengths) {
        if ((*max_lengths)[i][j] > 0) {
            return (*max_lengths)[i][j];
        }
    
        int max_depth = 0;
        const vector<pair<int, int>> directions{{0, -1}, {0, 1},
                                                {-1, 0}, {1, 0}};
        for (const auto& d : directions) {
            const int x = i + d.first, y = j + d.second;
            if (x >= 0 && x < matrix.size() &&
                y >= 0 && y < matrix[0].size() &&
                matrix[x][y] < matrix[i][j]) {
                max_depth = max(max_depth,
                                longestpath(matrix, x, y, max_lengths));
            }
        }

        (*max_lengths)[i][j] = max_depth + 1;
        return (*max_lengths)[i][j];
    }
};
