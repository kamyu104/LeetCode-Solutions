// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int tribonacci(int n) {
        vector<vector<int>> T = {{1, 1, 0},
                                 {1, 0, 1},
                                 {1, 0, 0}};
        return matrixMult({{1, 0, 0}}, matrixExpo(T, n))[0][1];  // [a1, a0, a(-1)] * T^n
    }

private:
    vector<vector<int>> matrixExpo(const vector<vector<int>>& A, int pow) {
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
                    entry = (static_cast<int64_t>(A[i][k]) * B[k][j] + entry);
                }
                result[i][j] = static_cast<int>(entry);
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int tribonacci(int n) {
        vector<int> dp = {0, 1, 1, 0};
        for (int i = 3; i <= n; ++i) {
            dp[i % 4] = dp[(i - 1) % 4] + dp[(i - 2) % 4] + dp[(i - 3) % 4];
        }
        return dp[n % 4];
    }
};
