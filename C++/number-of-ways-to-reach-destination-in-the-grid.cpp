// Time:  O(logn)
// Space: O(1)

// dp, matrix exponentiation
class Solution {
public:
    int numberOfWays(int n, int m, int k, vector<int>& source, vector<int>& dest) {
        static const int MOD = 1e9 + 7;
    
        vector<int> dp(4);  // dp[0] = both_same, dp[1] = row_same, dp[2] = col_same, dp[3] = no_same
        if (source == dest) {
            dp[0] = 1;
        } else if (source[0] == dest[0]) {
            dp[1] = 1;
        } else if (source[1] == dest[1]) {
            dp[2] = 1;
        } else {
            dp[3] = 1;
        }
        vector<vector<int>> T = {{0, m - 1, n - 1,                 0},
                                 {1, m - 2,     0,             n - 1},
                                 {1,   0,   n - 2,             m - 1},
                                 {0,   1,       1, (n - 2) + (m - 2)}};
        dp = matrixMult({dp}, matrixExpo(T, k))[0];
        return dp[0];
    }

private:
    vector<vector<int>> matrixExpo(const vector<vector<int>>& A, int64_t pow) {
        vector<vector<int>> result(A.size(), vector<int>(A.size()));
        vector<vector<int>> A_exp(A);
        for (int i = 0; i < A.size(); ++i) {
            result[i][i] = 1;
        }
        while (pow) {
            if (pow % 2 == 1) {
                result = matrixMult(result, A_exp);
            }
            A_exp = matrixMult(A_exp, A_exp);
            pow /= 2;
        }
        return result;
    }

    vector<vector<int>> matrixMult(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        vector<vector<int>> result(A.size(), vector<int>(B[0].size()));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B[0].size(); ++j) {
                int64_t entry = 0;
                for (int k = 0; k < B.size(); ++k) {
                    entry = (static_cast<int64_t>(A[i][k]) * B[k][j] % MOD + entry) % MOD;
                }
                result[i][j] = static_cast<int>(entry);
            }
        }
        return result;
    }

    static const int MOD = 1e9 + 7;
};

// Time:  O(n)
// Space: O(1)
// dp
class Solution2 {
public:
    int numberOfWays(int n, int m, int k, vector<int>& source, vector<int>& dest) {
        static const int MOD = 1e9 + 7;
    
        int both_same = 0, row_same = 0, col_same = 0, no_same = 0;
        if (source == dest) {
            both_same = 1;
        } else if (source[0] == dest[0]) {
            row_same = 1;
        } else if (source[1] == dest[1]) {
            col_same = 1;
        } else {
            no_same = 1;
        }
        for (int _ = 0; _ < k; ++_) {
            tie(both_same, row_same, col_same, no_same) = tuple(
                (row_same + col_same) % MOD,
                (both_same * static_cast<int64_t>(m - 1) + row_same * static_cast<int64_t>(m - 2) + no_same) % MOD,
                (both_same * static_cast<int64_t>(n - 1) + col_same * static_cast<int64_t>(n - 2) + no_same) % MOD,
                (row_same * static_cast<int64_t>(n - 1) + col_same * static_cast<int64_t>(m - 1) + no_same * static_cast<int64_t>((n - 2) + (m - 2))) % MOD
            );
        }
        return both_same;
    }
};
