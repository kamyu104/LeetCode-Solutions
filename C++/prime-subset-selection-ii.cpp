// Time:  O(n + (n / logn) * s)
// Space: O(n + (n / logn) * s)

// number theory, knapsack dp, greedy, backtracing
vector<int> linear_sieve_of_eratosthenes(int n) {  // Time: O(n), Space: O(n)
    vector<int> spf(n + 1, -1);
    vector<int> primes;
    for (int i = 2; i <= n; ++i) {
        if (spf[i] == -1) {
            spf[i] = i;
            primes.emplace_back(i);
        }
        for (const auto& p : primes) {
            if (i * p > n || p > spf[i]) {
                break;
            }
            spf[i * p] = p;
        }
    }
    return primes;
}

class Solution {
public:
    vector<int> maxPrimeSubset(int n, int s) {
        static const auto& INF = numeric_limits<int>::max();

        const auto& primes = linear_sieve_of_eratosthenes(n);
        vector<vector<int>> dp(size(primes) + 1, vector<int>(s + 1, INF));
        dp.back()[0] = 0;
        for (int i = size(primes) - 1; i >= 0; --i) {
            for (int j = 0; j < size(dp[i]); ++j) {
                dp[i][j] = min(dp[i + 1][j], (j - primes[i] >= 0 && dp[i + 1][j - primes[i]] != INF) ? dp[i + 1][j - primes[i]] + 1 : INF);
            }
        }
        int target = -1;
        for (int j = size(dp[0]) - 1; j >= 0; --j) {
            if (dp[0][j] != INF) {
                target = j;
                break;
            }
        }
        vector<int> result;
        for (int i = 0; i < size(primes); ++i) {
            if (target - primes[i] < 0) {
                break;
            }
            if (dp[i + 1][target - primes[i]] != dp[i][target] - 1) {
                continue;
            }
            result.emplace_back(primes[i]);
            target -= primes[i];
        }
        return result;
    }
};

// Time:  O(n + (n / logn) * s * l), l = max number of primes whose sum is at most s (when s = 1000, l = 24)
// Space: O(n + s * l)
// number theory, knapsack dp
class Solution2 {
public:
    vector<int> maxPrimeSubset(int n, int s) {
        static const auto& INF = numeric_limits<int>::max();

        const auto& primes = linear_sieve_of_eratosthenes(n);
        vector<pair<int, vector<int>>> dp(s + 1, {INF, {}});
        dp[0] = {0, {}};
        for (const auto& p : primes | views::reverse) {
            for (int i = size(dp) - 1; i >= p; --i) {
                if (dp[i - p].first == INF) {
                    continue;
                }
                vector<int> arr;
                arr.reserve(size(dp[i - p].second) + 1);
                arr.emplace_back(p);
                arr.insert(end(arr), cbegin(dp[i - p].second), cend(dp[i - p].second));
                dp[i] = min(dp[i], pair(dp[i - p].first + 1, move(arr)));
            }
        }
        for (int i = size(dp) - 1; i >= 0; --i) {
            if (dp[i].first != INF) {
                return dp[i].second;
            }
        }
        return {};
    }
};
