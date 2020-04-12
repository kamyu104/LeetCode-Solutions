// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int numOfWays(int n) {
        static const vector<vector<int>> T = {{3, 2},
                                              {2, 2}};
        const auto result = matrixMult({{6, 6}}, matrixExpo(T, n - 1))[0];  // [a1, a0] * T^(n-1)
        return (result[0] + result[1]) % MOD;
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
                    entry = (static_cast<int64_t>(A[i][k]) * B[k][j] % MOD + entry) % MOD;
                }
                result[i][j] = static_cast<int>(entry);
            }
        }
        return result;
    }
    const int MOD = 1e9 + 7;
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int numOfWays(int n) {
        static const int MOD = 1e9 + 7;
        uint64_t count_121 = 6, count_123 = 6;
        for (int i = 1; i < n; ++i) {
            tie(count_121, count_123) = pair((3 * count_121 % MOD + 2 * count_123 % MOD) % MOD,
                                             (2 * count_123 % MOD + 2 * count_121 % MOD) %MOD);
        }
        return (count_121 + count_123) % MOD;
    }
};
