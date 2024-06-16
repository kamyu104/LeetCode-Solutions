// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    int numberOfWays(int n) {
        static const int MOD = 1e9 + 7;

        // sequences: [1, 2, 2, 4, 4, 7, 7, 11, 11, 16, 16, 22, 22, ...]
        return (1 + ((n / 2) + 1ll) * (n / 2) / 2) % MOD;
    }
};

// Time:  O(1)
// Space: O(1)
// math
class Solution2 {
public:
    int numberOfWays(int n) {
        static const int MOD = 1e9 + 7;

        const auto& count_1_2_6 = [&](int n) {
            // sum((n-6*i)//2+1 for i in xrange((n//6)+1)
            // = sum(((n//2)+1)-3*i for i in xrange((n//6)+1)
            return ((n / 2 + 1) * ((n / 6) - 0 + 1) - 3 * ((n / 6) + 0) * ((n / 6) - 0 + 1) / 2) % MOD;
        };

        int result = 0;
        for (int i = 0; i <= min(n / 4, 2); ++i) {
            result = (result + count_1_2_6(n - 4 * i)) % MOD;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// math
class Solution3 {
public:
    int numberOfWays(int n) {
        static const int MOD = 1e9 + 7;

        const auto& count_1_2 = [](int n) {
            return n / 2 + 1;
        };

        const auto& count_1_2_6 = [&](int n) {
            int result = 0;
            for (int i = 0; i <= n / 6; ++i) {
                result = (result + count_1_2(n - 6 * i)) % MOD;
            }
            return result;
        };

        int result = 0;
        for (int i = 0; i <= min(n / 4, 2); ++i) {
            result = (result + count_1_2_6(n - 4 * i)) % MOD;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// dp
class Solution4 {
public:
    int numberOfWays(int n) {
        static const int MOD = 1e9 + 7;

        vector<int> dp(n + 1);
        dp[0] = 1;
        for (const auto& i : {1, 2, 6}) {
            for (int j = i; j <= n; ++j) {
                dp[j] = (dp[j] + dp[j - i]) % MOD;
            }
        }
        int result = 0;
        for (int i = 0; i <= min(n / 4, 2); ++i) {
            result = (result + dp[n - 4 * i]) % MOD;
        }
        return result;
    }
};
