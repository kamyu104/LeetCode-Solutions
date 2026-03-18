// Time:  O(dlogd + g + d^2 + g * d) = O(g * d + d^2), d = logr, g = len(good)
// Space: O(g + d)

// bfs, dp, principle of inclusion and exclusion
class Solution {
public:
    long long countFancy(long long l, long long r) {
        const auto& count = [&](int64_t x) {
            const auto& total = [](int64_t n) { // Time: O(logn)
                int result = 0;
                for (; n; n /= 10) {
                    result += n % 10;
                }
                return result;
            };

            const auto& length = [](int64_t n) { // Time: O(logn)
                int result = 0;
                for (; n; n /= 10) {
                    ++result;
                }
                return result;
            };

            const auto& check = [](int n) { // Time: O(logn)
                bool asc = true, desc = true;
                for (; n >= 10; n /= 10) {
                    if (!((n / 10) % 10 < n % 10)) {
                        asc = false;
                    }
                    if (!((n / 10) % 10 > n % 10)) {
                        desc = false;
                    }
                }
                return asc || desc;
            };

            const auto& bfs = [](int64_t x) {  // Time: O(g), g = len(result)
                vector<int64_t> result;
                for (int i = 1; i <= min(static_cast<int64_t>(9), x); ++i) {
                    result.emplace_back(i);
                }
                for (const auto& diff : {1, -1}) {
                    vector<int64_t> q;
                    for (int i = 1; i <= min(static_cast<int64_t>(9), x); ++i) {
                        q.emplace_back(i);
                    }
                    while (!empty(q)) {
                        vector<int64_t> new_q;
                        for (const auto& u : q) {
                            const auto& curr = u % 10;
                            for (int d = curr + diff; 0 <= d && d <= 9; d += diff) {
                                const auto& v = u * 10 + d;
                                if (v <= x) {
                                    new_q.emplace_back(v);
                                    result.emplace_back(v);
                                }
                            }
                        }
                        q = move(new_q);
                    }
                }
                return result;
            };

            vector<bool> lookup(length(x) * 9 + 1);
            const auto& dp = [&](int64_t x) {  // Time: O(d^2), d = logr
                const auto& l = length(x);
                const auto& mx = l * 9;
                vector<vector<int64_t>> dp(2, vector<int64_t>(mx + 1));  // dp[tight][sum]
                dp[1][0] = 1;
                int64_t base = pow(10LL, l - 1);
                for (int i = 0; i < l; ++i) {
                    vector<vector<int64_t>> new_dp(2, vector<int64_t>(mx + 1));
                    const auto& v = (x / base) % 10;
                    base /= 10;
                    for (int t = 0; t < 2; ++t) {
                        for (int s = 0; s <= mx; ++s) {
                            if (dp[t][s] == 0) {
                                continue;
                            }
                            const auto& bound = (t == 1) ? v : 9;
                            for (int d = 0; d <= bound; ++d) {
                                new_dp[t == 1 && d == v][s + d] += dp[t][s];
                            }
                        }
                    }
                    dp = move(new_dp);
                };

                int64_t result = 0;
                for (int i = 0; i <= mx; ++i) {
                    if (lookup[i]) {
                        result += dp[0][i] + dp[1][i];
                    }
                }
                return result;
            };
    
            for (int i = 0; i < size(lookup); ++i) {
                lookup[i] = check(i);
            }
            const auto& good = bfs(x);
            int64_t cnt = 0;
            for (const auto& x : good) {
                if (lookup[total(x)]) {
                    ++cnt;
                }
            }
            return size(good) + dp(x) - cnt;
        };

        return count(r) - count(l - 1);
    }
};
