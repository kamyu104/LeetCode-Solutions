// Time:  precompute: O(t + 26)
//        runtime:    O(n)
// Space: O(t + 26)

// precompute, dp
const int MOD = 1e9 + 7;
const int MAX_T = 1e5;
vector<int> init() {
    vector<int> DP(MAX_T + 26);
    for (int i = 0; i < 26; ++i) {
        DP[i] = 1;
    }
    for (int i = 26; i < size(DP); ++i) {
        DP[i] = (DP[i - 26] + DP[(i - 26) + 1]) % MOD;
    }
    return DP;
}

const auto& DP = init();
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int result = 0;
        for (const auto& x : s) {
            result = (result + DP[(x - 'a') + t]) % MOD;
        }
        return result;
    }
};

// Time:  O(n + t + 26)
// Space: O(26)
// dp
class Solution2 {
public:
    int lengthAfterTransformations(string s, int t) {
        static const int MOD = 1e9 + 7;

        vector<int> dp(26, 1);
        const auto mx = ranges::max(s);
        for (int i = 26; i <= (mx - 'a') + t; ++i) {
            dp[i % 26] = (dp[(i - 26) % 26] + dp[((i - 26) + 1) % 26]) % MOD;
        }
        int result = 0;
        for (const auto& x : s) {
            result = (result + dp[((x - 'a') + t) % 26]) % MOD;
        }
        return result;
    }
};

// Time:  O(n + 26^3 * logt)
// Space: O(26^2)
// matrix fast exponentiation
class Solution3 {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        vector<int> nums(26, 1);
        nums.back() = 2;
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

// Time:  O(n + t * 26)
// Space: O(26)
// dp
class Solution4 {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26);
        for (const auto& x : s) {
            ++cnt[x - 'a'];
        }
        for (int _ = 0; _ < t; ++_) {
            vector<int> new_cnt(26);
            for (int i = 0; i < 26; ++i) {
                new_cnt[(i + 1) % 26] = (new_cnt[(i + 1) % 26] + cnt[i]) % MOD;
                if (i == 25) {
                    new_cnt[(i + 2) % 26] = (new_cnt[(i + 2) % 26] + cnt[i]) % MOD;
                }
            }
            cnt = move(new_cnt);
        }
        return accumulate(cbegin(cnt), cend(cnt), 0, [](const auto& accu, const auto& x) {
            return (accu + x) % MOD;
        });
    }
};
