// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> T = {{0, 1, 1, 0, 1},
                                 {1, 0, 1, 0, 0},
                                 {0, 1, 0, 1, 0},
                                 {0, 0, 1, 0, 0},
                                 {0, 0, 1, 1, 0}};

        const auto& result = matrixExpo(T, n - 1);
        return accumulate(result.cbegin(), result.cend(), 0,
                          [&](int total, const vector<int>& row) {
                              return (total + 
                                      accumulate(row.cbegin(), row.cend(), 0,
                                                 [&](int sum, int val) {
                                                     return (sum + val) % MOD;
                                                 })) % MOD;
                          });
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
    int countVowelPermutation(int n) {
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int x = 1; x < n; ++x) {
            tie(a, e, i, o, u) = make_tuple(((e + i) % MOD + u) % MOD,
                                            (a + i) % MOD,
                                            (e + o) % MOD,
                                            i,
                                            (i + o) % MOD);
        }
        return (((a + e) % MOD + (i + o) % MOD) % MOD + u) % MOD;
    }
    
private:
    const int MOD = 1e9 + 7;
};
