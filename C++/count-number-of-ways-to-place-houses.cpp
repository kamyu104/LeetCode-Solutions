// Time:  O(logn)
// Space: O(1)

// matrix exponentiation
class Solution {
public:
    int countHousePlacements(int n) {
        vector<vector<int>> T = {{1, 1},
                                 {1, 0}};
        int64_t result = matrixMult({{1, 0}}, matrixExpo(T, n + 1))[0][0]; // [a1, a0] * T^N
        return result * result % MOD;
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
// dp
class Solution2 {
public:
    int countHousePlacements(int n) {
        static const int MOD = 1e9 + 7;
        int64_t prev = 0, curr = 1;
        for (int _ = 0; _ < n + 1; ++_) {
            tie(prev, curr) = pair(curr, (prev + curr) % MOD);
        }
        return curr * curr % MOD;
    }
};
