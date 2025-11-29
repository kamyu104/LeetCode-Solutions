// Time:  O(logn * 11 * 11 * 2 * 2 * 10)
// Space: O(logn * 11 * 11 * 2 * 2)

// memoization by list
class Solution {
public:
    long long totalWaviness(long long num1, long long num2) {
        const auto& count = [&](long long x) {
            auto encode = [&](int i, int prev, int prev2, bool zero, bool tight) {
                long long key = i;
                key = key * (10 + 1) + (prev + 1);
                key = key * (10 + 1) + (prev2 + 1);
                key = key * 2 + (zero ? 1 : 0);
                key = key * 2 + (tight ? 1 : 0);
                return key;
            };

            const auto& s = to_string(x);
            vector<pair<long long, long long>> lookup(size(s) * (10 + 1) * (10 + 1) * 2 * 2, {-1, -1});
            const auto dp = [&](this auto&& dp, int i, int prev, int prev2, bool zero, bool tight) -> pair<long long, long long> {
                if (i == size(s)) {
                    return {1, 0};
                }
                long long key = encode(i, prev, prev2, zero, tight);
                if (lookup[key].first == -1) {
                    long long cnt = 0, w = 0;
                    const auto& mx = tight ? s[i] - '0' : 9;
                    for (int d = 0; d <= mx; ++d) {
                        const auto& new_tight = tight && (d == s[i] - '0');
                        const auto& new_zero = zero && (d == 0);
                        const auto& new_prev2 = prev;
                        const auto& new_prev = !new_zero ? d : -1;
                        const auto& [new_cnt, nw] = dp(i + 1, new_prev, new_prev2, new_zero, new_tight);
                        cnt += new_cnt;
                        if (!zero && prev2 != -1 && ((prev2 < prev && prev > d) || (prev2 > prev && prev < d))) {
                            w += new_cnt;
                        }
                        w += nw;
                    }
                    lookup[key] = {cnt, w};
                }
                return lookup[key];
            };

            return dp(0, -1, -1, true, true).second;
        };

        return count(num2) - count(num1 - 1);
    }
};

// Time:  O(logn * 11 * 11 * 2 * 2 * 10)
// Space: O(11 * 11 * 2 * 2)
// dp by list
class Solution2 {
public:
    long long totalWaviness(long long num1, long long num2) {
        const auto& count = [&](long long x) {
            auto encode = [&](int prev, int prev2, int zero, int tight) {
                long long key = prev + 1;
                key = key * (10 + 1) + (prev2 + 1);
                key = key * 2 + zero;
                key = key * 2 + tight;
                return key;
            };

            const auto& s = to_string(x);
            const int state_size = (10 + 1) * (10 + 1) * 2 * 2;
            vector<pair<long long, long long>> dp(state_size, {-1, -1});
            vector<pair<long long, long long>> new_dp(state_size, {-1, -1});
            for (int prev = -1; prev <= 9; ++prev) {
                for (int prev2 = -1; prev2 <= 9; ++prev2) {
                    for (int zero = 0; zero <= 1; ++zero) {
                        for (int tight = 0; tight <= 1; ++tight) {
                            const auto& key = encode(prev, prev2, zero, tight);
                            dp[key] = {1, 0};
                        }
                    }
                }
            }
            for (int i = size(s) - 1; i >= 0; --i) {
                fill(begin(new_dp), end(new_dp), make_pair(-1LL, -1LL));
                for (int prev = -1; prev <= 9; ++prev) {
                    for (int prev2 = -1; prev2 <= 9; ++prev2) {
                        for (int zero = 0; zero <= 1; ++zero) {
                            for (int tight = 0; tight <= 1; ++tight) {
                                long long cnt = 0, w = 0;
                                const auto& mx = tight ? s[i] - '0' : 9;
                                for (int d = 0; d <= mx; ++d) {
                                    const auto& new_tight = tight && (d == s[i] - '0');
                                    const auto& new_zero = zero && (d == 0);
                                    const auto& new_prev2 = prev;
                                    const auto& new_prev = !new_zero ? d : -1;
                                    const auto& key = encode(new_prev, new_prev2, new_zero, new_tight);
                                    if (dp[key].first != -1) {
                                        const auto& [new_cnt, nw] = dp[key];
                                        cnt += new_cnt;
                                        if (!zero && prev2 != -1 && ((prev2 < prev && prev > d) || (prev2 > prev && prev < d))) {
                                            w += new_cnt;
                                        }
                                        w += nw;
                                    }
                                }
                                const auto& key = encode(prev, prev2, zero, tight);
                                new_dp[key] = {cnt, w};
                            }
                        }
                    }
                }
                swap(dp, new_dp);
            }

            return dp[encode(-1, -1, true, true)].second;
        };

        return count(num2) - count(num1 - 1);
    }
};

// Time:  O(logn * 11 * 11 * 2 * 2 * 10)
// Space: O(logn * 11 * 11 * 2 * 2)
// memoization by dict
class Solution3 {
private:
    struct TupleHash {
        template <typename... T>
        std::size_t operator()(const std::tuple<T...>& t) const {
            return apply([](const auto&... args) {
                std::size_t seed = 0;
                ((seed ^= std::hash<std::decay_t<decltype(args)>>{}(args) +
                        0x9e3779b9 + (seed << 6) + (seed >> 2)), ...);
                return seed;
            }, t);
        }
    };

public:
    long long totalWaviness(long long num1, long long num2) {
        auto count = [&](long long x) {
            const auto& s = to_string(x);
            using State = tuple<int, int, int, bool, bool>;
            unordered_map<State, pair<long long, long long>, TupleHash> lookup;
            const auto dp = [&](this auto&& dp, int i, int prev, int prev2, bool zero, bool tight) -> pair<long long, long long> {
                if (i == size(s)) {
                    return {1, 0};
                }
                State key = {i, prev, prev2, zero, tight};
                if (!lookup.count(key)) {
                    long long cnt = 0, w = 0;
                    const auto& mx = tight ? (s[i] - '0') : 9;
                    for (int d = 0; d <= mx; ++d) {
                        const auto& new_tight = tight && (d == mx);
                        const auto& new_zero = zero && (d == 0);
                        const auto& new_prev2 = prev;
                        const auto& new_prev = !new_zero ? d : -1;
                        const auto& [new_cnt, nw] = dp(i + 1, new_prev, new_prev2, new_zero, new_tight);
                        cnt += new_cnt;
                        if (!zero && prev2 != -1 && ((prev2 < prev && prev > d) || (prev2 > prev && prev < d))) {
                            w += new_cnt;
                        }
                        w += nw;
                    }
                    lookup[key] = {cnt, w};
                }
                return lookup[key];
            };

            return dp(0, -1, -1, true, true).second;
        };

        return count(num2) - count(num1 - 1);
    }
};

// Time:  O(logn * 11 * 11 * 2 * 2 * 10)
// Space: O(11 * 11 * 2 * 2)
// dp by dict
class Solution4 {
private:
    struct TupleHash {
        template <typename... T>
        std::size_t operator()(const std::tuple<T...>& t) const {
            return apply([](const auto&... args) {
                std::size_t seed = 0;
                ((seed ^= std::hash<std::decay_t<decltype(args)>>{}(args) +
                        0x9e3779b9 + (seed << 6) + (seed >> 2)), ...);
                return seed;
            }, t);
        }
    };

public:
    long long totalWaviness(long long num1, long long num2) {
        const auto& count = [&](long long x) {
            const auto& s = to_string(x);
            using State = tuple<int, int, int, int>;
            unordered_map<State, pair<long long, long long>, TupleHash> dp, new_dp;
            for (int prev = -1; prev <= 9; ++prev) {
                for (int prev2 = -1; prev2 <= 9; ++prev2) {
                    for (int zero = 0; zero <= 1; ++zero) {
                        for (int tight = 0; tight <= 1; ++tight) {
                            dp[{prev, prev2, zero, tight}] = {1, 0};
                        }
                    }
                }
            }
            for (int i = size(s) - 1; i >= 0; --i) {
                new_dp.clear();
                for (int prev = -1; prev <= 9; ++prev) {
                    for (int prev2 = -1; prev2 <= 9; ++prev2) {
                        for (int zero = 0; zero <= 1; ++zero) {
                            for (int tight = 0; tight <= 1; ++tight) {
                                long long cnt = 0, w = 0;
                                const auto& mx = tight ? s[i] - '0' : 9;
                                for (int d = 0; d <= mx; ++d) {
                                    const auto& new_tight = tight && (d == s[i] - '0');
                                    const auto& new_zero = zero && (d == 0);
                                    const auto& new_prev2 = prev;
                                    const auto& new_prev = !new_zero ? d : -1;
                                    State key = {new_prev, new_prev2, new_zero, new_tight};
                                    if (dp.count(key)) {
                                        const auto& [new_cnt, nw] = dp[key];
                                        cnt += new_cnt;
                                        if (!zero && prev2 != -1 && ((prev2 < prev && prev > d) || (prev2 > prev && prev < d))) {
                                            w += new_cnt;
                                        }
                                        w += nw;
                                    }
                                }
                                new_dp[{prev, prev2, zero, tight}] = {cnt, w};
                            }
                        }
                    }
                }
                swap(dp, new_dp);
            }

            return dp[{-1, -1, true, true}].second;
        };

        return count(num2) - count(num1 - 1);
    }
};
