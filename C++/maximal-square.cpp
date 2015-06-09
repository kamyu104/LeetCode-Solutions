// Time:  O(n^2)
// Space: O(n)

// DP with rolling window.
class Solution {
public:
    int maximalSquare(vector<vector<char>>& A) {
        if (A.empty()) {
            return 0;
        }
        const int m = A.size(), n = A[0].size();
        vector<vector<int>> size(2, vector<int>(n, 0));
        int max_size = 0;

        for (int j = 0; j < n; ++j) {
            size[0][j] = A[0][j] - '0';
            max_size = max(max_size, size[0][j]);
        }
        for (int i = 1; i < m; ++i) {
            size[i % 2][0] = A[i][0] - '0';
            for (int j = 1; j < n; ++j) {
                if (A[i][j] == '1') {
                    size[i % 2][j] = min(size[i % 2][j - 1], 
                                         min(size[(i - 1) % 2][j], 
                                             size[(i - 1) % 2][j - 1])) + 1;
                    max_size = max(max_size, size[i % 2][j]);
                } else {
                    size[i % 2][j] = 0;
                }
            }
        }
        return max_size * max_size;
    }
};

// Time:  O(n^2)
// Space: O(n^2)
// DP.
class Solution2 {
public:
    int maximalSquare(vector<vector<char>>& A) {
        if (A.empty()) {
            return 0;
        }
        const int m = A.size(), n = A[0].size();
        vector<vector<int>> size(m, vector<int>(n, 0));
        int max_size = 0;

        for (int j = 0; j < n; ++j) {
            size[0][j] = A[0][j] - '0';
            max_size = max(max_size, size[0][j]);
        }
        for (int i = 1; i < m; ++i) {
            size[i][0] = A[i][0] - '0';
            for (int j = 1; j < n; ++j) {
                if (A[i][j] == '1') {
                    size[i][j] = min(size[i][j - 1], 
                                    min(size[i - 1][j], 
                                        size[i - 1][j - 1])) + 1;
                    max_size = max(max_size, size[i][j]);
                } else {
                    size[i][j] = 0;
                }
            }
        }
        return max_size * max_size;
    }
};

// Time:  O(n^2)
// Space: O(n^2)
// DP.
class Solution3 {
public:
    struct MaxHW {
        int h, w;
    };

    int maximalSquare(vector<vector<char>>& A) {
        if (A.empty()) {
            return 0;
        }

        // DP table stores (h, w) for each (i, j).
        vector<vector<MaxHW>> table(A.size(), vector<MaxHW>(A.front().size()));
        for (int i = A.size() - 1; i >= 0; --i) {
            for (int j = A[i].size() - 1; j >= 0; --j) {
                // Find the largest h such that (i, j) to (i + h - 1, j) are feasible.
                // Find the largest w such that (i, j) to (i, j + w - 1) are feasible.
                table[i][j] = A[i][j] == '1'
                                  ? MaxHW{i + 1 < A.size() ? table[i + 1][j].h + 1 : 1,
                                          j + 1 < A[i].size() ? table[i][j + 1].w + 1 : 1}
                                  : MaxHW{0, 0};
            }
        }

        // A table stores the length of largest square for each (i, j).
        vector<vector<int>> s(A.size(), vector<int>(A.front().size(), 0));
        int max_square_area = 0;
        for (int i = A.size() - 1; i >= 0; --i) {
            for (int j = A[i].size() - 1; j >= 0; --j) {
                int side = min(table[i][j].h, table[i][j].w);
                if (A[i][j]) {
                    // Get the length of largest square with bottom-left corner (i, j).
                    if (i + 1 < A.size() && j + 1 < A[i + 1].size()) {
                        side = min(s[i + 1][j + 1] + 1, side);
                    }
                    s[i][j] = side;
                    max_square_area = max(max_square_area, side * side);
                }
            }
        }
        return max_square_area;
    }
};
