// Time:  O(1)
// Space: O(1)

// math
class Solution {
public:
    bool divisorGame(int n) {
        // 1. if we get an even, we can choose x = 1
        //    to make the opponent always get an odd
        // 2. if the opponent gets an odd, he can only choose x = 1 or other odds
        //    and we can still get an even
        // 3. at the end, the opponent can only choose x = 1 and we win
        // 4. in summary, we win if only if we get an even and 
        //    keeps even until the opponent loses
        return n % 2 == 0;
    }
};

// Time:  O(nlogn)
// Space: O(nlogn)
// dp, number theory
class Solution2 {
public:
    bool divisorGame(int n) {
        const auto& factors = [](int n) {
            vector<vector<int>> result(n + 1);
            for (int i = 1; i <= n; ++i) {
                for (int j = i; j <= n; j += i) {
                    result[j].emplace_back(i);
                }
            }
            return result;
        };

        const auto& FACTORS = factors(n);
        vector<bool> dp(n + 1);
        for (int i = 2; i <= n; ++i) {
            for (const auto& j : FACTORS[i]) {
                if (j != i && !dp[i - j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

// Time:  O(nlogn)
// Space: O(nlogn)
// memoization, number theory
class Solution3 {
public:
    bool divisorGame(int n) {
        const auto& factors = [](int n) {
            vector<vector<int>> result(n + 1);
            for (int i = 1; i <= n; ++i) {
                for (int j = i; j <= n; j += i) {
                    result[j].emplace_back(i);
                }
            }
            return result;
        };

        const auto& FACTORS = factors(n);
        vector<int> lookup(n + 1, -1);
        const function<int (int)> memoization = [&](int n) {
            if (lookup[n] == -1) {
                int result = 0;
                for (const auto& i : FACTORS[n]) {
                    if (i != n && !memoization(n - i)) {
                        result = 1;
                        break;
                    }
                }
                lookup[n] = result;
            }
            return lookup[n];
        };

        return memoization(n);
    }
};

// Time:  O(n^(3/2))
// Space: O(n)
// memoization
class Solution4 {
public:
    bool divisorGame(int n) {
        vector<int> lookup(n + 1, -1);
        const function<int (int)> memoization = [&](int n) {
            if (lookup[n] == -1) {
                int result = 0;
                for (auto i = 1; i * i <= n; ++i) {
                    if (n % i) {
                        continue;
                    }
                    if (i != n && !memoization(n - i)) {
                        result = 1;
                        break;
                    }
                    const int j = n / i;
                    if (j == i) {
                        continue;
                    }
                    if (j != n && !memoization(n - j)) {
                        result = 1;
                        break;
                    }
                }
                lookup[n] = result;
            }
            return lookup[n];
        };

        return memoization(n);
    }
};

// Time:  O(n^2)
// Space: O(n)
// memoization
class Solution5 {
public:
    bool divisorGame(int n) {
        vector<int> lookup(n + 1, -1);
        const function<int (int)> memoization = [&](int n) {
            if (lookup[n] == -1) {
                int result = 0;
                for (auto i = 1; i <= n; ++i) {
                    if (n % i) {
                        continue;
                    }
                    if (i != n && !memoization(n - i)) {
                        result = 1;
                        break;
                    }
                }
                lookup[n] = result;
            }
            return lookup[n];
        };

        return memoization(n);
    }
};
