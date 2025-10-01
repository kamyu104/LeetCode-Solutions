// Time:  O((r - l)^3 * logn)
// Space: O((r - l)^2)

// matrix fast exponentiation
class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        r -= l;
        vector<vector<int>> matrix(r + 1, vector<int>(r + 1));
        for (int i = 0; i <= r; ++i) {
            for (int j = 0; j <= r - 1 - i; ++j) {
                matrix[i][j] = 1;
            }
        }
        const auto& matrix_pow_t = matrixExpo(matrix, n - 1);
        const auto& result = matrixMult(vector<vector<int>>{vector<int>(r + 1, 1)}, matrix_pow_t);
        return (accumulate(cbegin(result[0]), cend(result[0]), 0, [](const auto& accu, const auto& x) {
            return (accu + x) % MOD;
        }) * 2) % MOD;
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
