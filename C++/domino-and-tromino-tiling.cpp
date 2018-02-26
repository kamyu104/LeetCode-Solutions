// Time:  O(logn)
// Space: O(logn)

class Solution {
public:
    int numTilings(int N) {
        vector<vector<int>> T{{1, 0, 0, 1},  // #(|) = #(|) + #(=)
                              {1, 0, 1, 0},  // #(「) = #(|) + #(L)
                              {1, 1, 0, 0},  // #(L) = #(|) + #(「)
                              {1, 1, 1, 0}}; // #(=) = #(|) + #(「) + #(L)
        return matrixExpo(T, N)[0][0];       // T^N * [1, 0, 0, 0]
    }

private:
    vector<vector<int>> matrixExpo(const vector<vector<int>>& A, int pow) {
        if (pow == 0) {
            vector<vector<int>> I(A.size(), vector<int>(A.size()));
            for (int i = 0; i < A.size(); ++i) {
                I[i][i] = 1;
            }
            return I;
        }
        if (pow == 1) {
            return A;
        }
        if (pow % 2 == 1) {
            return matrixMult(matrixExpo(A, pow - 1), A);
        }
        const auto& B = matrixExpo(A, pow / 2);
        return matrixMult(B, B);
    }

    vector<vector<int>> matrixMult(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        vector<vector<int>> result(A.size(), vector<int>(A.size()));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < B[0].size(); ++j) {
                int64_t entry = 0;
                for (int k = 0; k < B.size(); ++k) {
                    entry = (static_cast<int64_t>(A[i][k]) * B[k][j] % M + entry) % M;
                }
                result[i][j] = static_cast<int>(entry);
            }
        }
        return result;
    }
    const int M = 1e9 + 7;
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int numTilings(int N) {
        // Prove:
        // dp[n] = dp[n-1](|) + dp[n-2](=) + 2*(dp[n-3](「」) + ... + d[0](「 = ... = 」))
        //       = dp[n-1] + dp[n-2] + dp[n-3] + dp[n-3] + 2*(dp[n-4] + ... + d[0])
        //       = dp[n-1] + dp[n-3] + (dp[n-2] + dp[n-3] + 2*(dp[n-4] + ... + d[0])
        //       = dp[n-1] + dp[n-3] + dp[n-1]
        //       = 2*dp[n-1] + dp[n-3]
        const int M = 1e9 + 7;
        vector<int> dp(3);
        dp[0] = 1, dp[1] = 1, dp[2] = 2;
        for (int i = 3; i <= N; ++i) {
            dp[i % 3] = (2 * dp[(i - 1) % 3] % M + dp[(i - 3) % 3]) % M;
        }
        return dp[N % 3];
    }
};
