// Time:  O(m * n)
// Space: O(1)

// dp solution
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (!matrix[i][j]) {
                    continue;
                }
                matrix[i][j] = numeric_limits<int>::max();
                if (i > 0 && matrix[i - 1][j] != numeric_limits<int>::max()) {
                    matrix[i][j] = min(matrix[i][j], matrix[i - 1][j] + 1);
                }
                if (j > 0 && matrix[i][j - 1] != numeric_limits<int>::max()) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][j - 1] + 1);
                }
            }
        }

        for (int i = matrix.size() - 1; i >= 0; --i) {
            for (int j = matrix[i].size() - 1; j >= 0; --j) {
                if (!matrix[i][j]) {
                    continue;
                }
                if (i < matrix.size() - 1 && matrix[i + 1][j] != numeric_limits<int>::max()) {
                    matrix[i][j] = min(matrix[i][j], matrix[i + 1][j] + 1);
                }
                if (j < matrix[i].size() - 1 && matrix[i][j + 1] != numeric_limits<int>::max()) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][j + 1] + 1);
                }
            }
        }

        return matrix;
    }
};

// Time:  O(m * n)
// Space: O(m * n)
// dp solution
class Solution2 {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        vector<vector<int> > dp(matrix.size(),
                                vector<int>(matrix[0].size(),
                                            numeric_limits<int>::max()));

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i > 0 && dp[i - 1][j] != numeric_limits<int>::max()) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    }
                    if (j > 0 && dp[i][j - 1] != numeric_limits<int>::max()) {
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
                    }
                }
            }
        }

        for (int i = matrix.size() - 1; i >= 0; --i) {
            for (int j = matrix[i].size() - 1; j >= 0; --j) {
                if (matrix[i][j] == 0) {
                    dp[i][j] = 0;
                } else {
                    if (i < matrix.size() - 1 && dp[i + 1][j] != numeric_limits<int>::max()) {
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                    }
                    if (j < matrix[i].size() - 1 && dp[i][j + 1] != numeric_limits<int>::max()) {
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                    }
                }
            }
        }

        return dp;
    }
};

// Time:  O(m * n)
// Space: O(m * n)
class Solution3 {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        queue<pair<int, int>> queue;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    queue.emplace(i, j);
                }
                else {
                    matrix[i][j] = numeric_limits<int>::max();
                }
            }
        }

        const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!queue.empty()) {
            auto cell = queue.front();
            queue.pop();
            for (const auto& dir : dirs) {
                auto i = cell.first + dir.first;
                auto j = cell.second + dir.second;
                if (!(0 <= i && i < matrix.size() && 0 <= j && j < matrix[0].size() && 
                      matrix[i][j] > matrix[cell.first][cell.second] + 1)) {
                        continue;
                }
                queue.emplace(i, j);
                matrix[i][j] = matrix[cell.first][cell.second] + 1;
            }
        }
        
        return matrix;
    }
};
