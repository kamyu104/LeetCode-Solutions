// Time:  O(n + 26^3 * logt)
// Space: O(26^2)

// matrix fast exponentiation
class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        vector<vector<int>> matrix(26, vector<int>(26));
        for (int i = 0; i < size(nums); ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                matrix[i][(i + j) % 26] = 1;
            }
        }
        const auto& matrix_pow_t = matrixExpo(matrix, t);
        const auto& result = matrixMult(vector<vector<int>>{{cnt}}, matrix_pow_t);
        return accumulate(cbegin(result[0]), cend(result[0]), 0, [](const auto& accu, const auto& x) {
            return (accu + x) % MOD;
        });
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
