// Time:  O(logn)
// Space: O(1)

// matrix fast exponentiation
class Solution {
public:
    int countGoodStrings(long long n) {
        vector<vector<int>> T = {{1, 1},
                                 {1, 0}};
        return matrixMult({{2, 0}}, matrixExpo(T, n))[0][1];  // [a1, a0] * T^n
    }

private:
    vector<vector<int>> matrixExpo(const vector<vector<int>>& A, int64_t pow) {
        vector<vector<int>> result(size(A), vector<int>(size(A)));
        vector<vector<int>> A_exp(A);
        for (int i = 0; i < size(A); ++i) {
            result[i][i] = 1;
        }
        while (pow) {
            if ((pow & 1) == 1) {
                result = matrixMult(result, A_exp);
            }
            A_exp = matrixMult(A_exp, A_exp);
            pow >>= 1;
        }
        return result;
    }

    vector<vector<int>> matrixMult(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        vector<vector<int>> result(size(A), vector<int>(size(B[0])));
        for (int i = 0; i < size(A); ++i) {
            for (int j = 0; j < size(B[0]); ++j) {
                int64_t entry = 0;
                for (int k = 0; k < size(B); ++k) {
                    entry = (static_cast<int64_t>(A[i][k]) * B[k][j] % MOD + entry) % MOD;
                }
                result[i][j] = static_cast<int>(entry);
            }
        }
        return result;
    }

    static const int MOD = 1e9 + 7;
};
