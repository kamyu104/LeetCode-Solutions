// Time:  O(n + logk)
// Space: O(n)

// dp, math, kmp
class Solution {
public:
    int numberOfWays(string s, string t, long long k) {
        const int n = size(s);
        vector<int> dp(2);
        dp[1] = (((pow(n - 1, k, MOD) - pow(-1, k, MOD)) * pow(n, MOD - 2, MOD)) % MOD + MOD) % MOD;
        dp[0] = (dp[1] + pow(-1, k, MOD)) % MOD;
        int result = 0;
        for (const auto& i : KMP(s + s.substr(0, size(s) - 1), t)) {
            result = (result + dp[static_cast<int>(i != 0)]) % MOD;
        }
        return result;
    }

private:
    int64_t pow(int64_t a, int64_t b, int64_t m) {
        a %= m;
        int64_t result = 1;
        while (b) {
            if (b & 1) {
                result = (result * a) % m;
            }
            a = (a * a) % m;
            b >>= 1;
        }
        return result;
    }

    vector<int> KMP(const string& text, const string& pattern) {
        vector<int> result;
        const vector<int> prefix = getPrefix(pattern);
        int j = -1;
        for (int i = 0; i < text.length(); ++i) {
            while (j > -1 && pattern[j + 1] != text[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == text[i]) {
                ++j;
            }
            if (j == pattern.length() - 1) {
                result.emplace_back(i - j);
                j = prefix[j];
            }
        }
        return result;
    }

    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }

    const int MOD = 1e9 + 7;
};

// Time:  O(n + logk)
// Space: O(n)
// dp, matrix exponentiation, kmp
class Solution2 {
public:
    int numberOfWays(string s, string t, long long k) {
        const int n = size(s);
        vector<vector<int>> T = {{    0,           1},
                                 {n - 1, (n - 1) - 1}};
        const auto dp = matrixMult({{1, 0}}, matrixExpo(T, k))[0];  // [dp[0], dp[1]] * T^k
        int result = 0;
        for (const auto& i : KMP(s + s.substr(0, size(s) - 1), t)) {
            result = (result + dp[static_cast<int>(i != 0)]) % MOD;
        }
        return result;
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

    vector<int> KMP(const string& text, const string& pattern) {
        vector<int> result;
        const vector<int> prefix = getPrefix(pattern);
        int j = -1;
        for (int i = 0; i < text.length(); ++i) {
            while (j > -1 && pattern[j + 1] != text[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == text[i]) {
                ++j;
            }
            if (j == pattern.length() - 1) {
                result.emplace_back(i - j);
                j = prefix[j];
            }
        }
        return result;
    }

    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(pattern.length(), -1);
        int j = -1;
        for (int i = 1; i < pattern.length(); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }

    const int MOD = 1e9 + 7;
};

// Time:  O(n + logk)
// Space: O(n)
// dp, matrix exponentiation, z-function
class Solution3 {
public:
    int numberOfWays(string s, string t, long long k) {
        const int n = size(s);
        vector<vector<int>> T = {{    0,           1},
                                 {n - 1, (n - 1) - 1}};
        const auto dp = matrixMult({{1, 0}}, matrixExpo(T, k))[0];  // [dp[0], dp[1]] * T^k
        const auto& z = z_function(t + s + s.substr(0, size(s) - 1));
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (z[i + size(t)] >= size(t)) {
                result = (result + dp[static_cast<int>(i != 0)]) % MOD;
            }
        }
        return result;
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

    // Template: https://cp-algorithms.com/string/z-function.html
    vector<int> z_function(const string& s) {  // Time: O(n), Space: O(n)
        vector<int> z(size(s));
        for (int i = 1, l = 0, r = 0; i < size(z); ++i) {
            if (i <= r) {
                z[i] = min(r - i + 1, z[i - l]);
            }
            while (i + z[i] < size(z) && s[z[i]] == s[i + z[i]]) {
                ++z[i];
            }
            if (i + z[i] - 1 > r) {
                l = i, r = i + z[i] - 1;
            }
        }
        return z;
    }

    const int MOD = 1e9 + 7;
};
