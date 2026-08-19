// Time:  O(m^2)
// Space: O(m)

// sort, dp
class Solution {
public:
    int elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        static const int64_t INF = numeric_limits<int64_t>::max();

        unordered_map<int, int> lookup;
        for (const auto& x : requests) {
            lookup[x[1]] = max(lookup[x[1]], x[0]);
        }
        vector<pair<int, int>> pairs(cbegin(lookup), cend(lookup));
        ranges::sort(pairs);
        if (size(pairs) == 1) {
            return max<int64_t>(abs(pairs[0].first - start), pairs[0].second);
        }
        vector<vector<int64_t>> dp(2, vector<int64_t>(size(pairs), INF));
        dp[0][1] = max<int64_t>(abs(pairs[0].first - start), pairs[0].second);
        dp[1][0] = max<int64_t>(abs(pairs.back().first - start), pairs.back().second);
        int64_t result = INF;
        for (int l = size(pairs) - 1; l >= 1; --l) {
            vector<vector<int64_t>> new_dp(2, vector<int64_t>(size(pairs), INF));
            for (int i = 0; i < size(pairs) - l + 1; ++i) {
                const auto& j = i + l - 1;
                for (int s = 0; s < 2; ++s) {
                    if (dp[s][i] == INF) {
                        continue;
                    }
                    const auto& x = (s == 0) ? pairs[i - 1].first : pairs[j + 1].first;
                    if (l == 1) {
                        result = min(result, max<int64_t>(dp[s][i] + abs(x - pairs[i].first), pairs[i].second));
                        continue;
                    }
                    new_dp[0][i + 1] = min(new_dp[0][i + 1], max<int64_t>(dp[s][i] + abs(x - pairs[i].first), pairs[i].second));
                    new_dp[1][i] = min(new_dp[1][i], max<int64_t>(dp[s][i] + abs(x - pairs[j].first), pairs[j].second));
                }
            }
            dp = move(new_dp);
        }
        return result;
    }
};

// Time:  O(m^2 * logr)
// Space: O(m)
// sort, binary search, dp
class Solution2 {
public:
    int elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        static const int64_t INF = numeric_limits<int64_t>::max();

        const auto& binary_search = [](int64_t left, int64_t right, const auto& check) {
            while (left <= right) {
                const auto& mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        vector<pair<int, int>> pairs;
        const auto& check = [&](int64_t x) {
            vector<vector<int64_t>> dp(2, vector<int64_t>(size(pairs), INF));
            for (int i = 0; i < size(pairs); ++i) {
                if (pairs[i].second > x) {
                    continue;
                }
                dp[0][i] = dp[1][i] = 0;
            }
            for (int l = 1; l < size(pairs); ++l) {
                vector<vector<int64_t>> new_dp(2, vector<int64_t>(size(pairs), INF));
                for (int i = 0; i < size(pairs) - l + 1; ++i) {
                    const auto& j = i + l - 1;
                    if (i - 1 >= 0) {
                        if (dp[0][i] != INF) {
                            if (pairs[i - 1].second <= x - (dp[0][i] + (pairs[i].first - pairs[i - 1].first))) {
                                new_dp[0][i - 1] = min(new_dp[0][i - 1], dp[0][i] + (pairs[i].first - pairs[i - 1].first));
                            }
                        }
                        if (dp[1][i] != INF) {
                            if (pairs[i - 1].second <= x - (dp[1][i] + (pairs[j].first - pairs[i - 1].first))) {
                                new_dp[0][i - 1] = min(new_dp[0][i - 1], dp[1][i] + (pairs[j].first - pairs[i - 1].first));
                            }
                        }
                    }
                    if (j + 1 < size(pairs)) {
                        if (dp[1][i] != INF) {
                            if (pairs[j + 1].second <= x - (dp[1][i] + (pairs[j + 1].first - pairs[j].first))) {
                                new_dp[1][i] = min(new_dp[1][i], dp[1][i] + (pairs[j + 1].first - pairs[j].first));
                            }
                        }
                        if (dp[0][i] != INF) {
                            if (pairs[j + 1].second <= x - (dp[0][i] + (pairs[j + 1].first - pairs[i].first))) {
                                new_dp[1][i] = min(new_dp[1][i], dp[0][i] + (pairs[j + 1].first - pairs[i].first));
                            }
                        }
                    }
                }
                dp = move(new_dp);
            }
            return dp[0][0] <= x - abs(pairs[0].first - start) || dp[1][0] <= x - abs(pairs[size(pairs) - 1].first - start);
        };

        unordered_map<int, int> lookup;
        for (const auto& x : requests) {
            lookup[x[1]] = max(lookup[x[1]], x[0]);
        }
        pairs.assign(cbegin(lookup), cend(lookup));
        ranges::sort(pairs);
        const auto& mx = ranges::max(pairs, {}, &pair<int, int>::second).second;
        const auto& diff1 = max(start - pairs[0].first, 0);
        const auto& diff2 = max(pairs.back().first - start, 0);
        const auto& left = max(mx, min(2 * diff1 + diff2, diff1 + 2 * diff2));
        const auto& right = max(mx, min(abs(start - pairs[0].first), abs(start - pairs.back().first))) + (pairs[size(pairs) - 1].first - pairs[0].first);
        return binary_search(left, right, check);
    }
};

// Time:  O(m^2 * 2^m)
// Space: O(m * 2^m)
// sort, bitmasks, dp
class Solution3 {
public:
    int elevatorRequests(int n, int start, vector<vector<int>>& requests) {
        static const int64_t INF = numeric_limits<int64_t>::max();

        unordered_map<int, int> lookup;
        for (const auto& x : requests) {
            lookup[x[1]] = max(lookup[x[1]], x[0]);
        }
        vector<pair<int, int>> pairs(cbegin(lookup), cend(lookup));
        ranges::sort(pairs);
        vector<vector<int64_t>> dp(1 << size(pairs), vector<int64_t>(size(pairs), INF));
        for (int i = 0; i < size(pairs); ++i) {
            dp[1 << i][i] = max(abs(pairs[i].first - start), pairs[i].second);
        }
        for (int mask = 1; mask < 1 << size(pairs); ++mask) {
            for (int i = 0; i < size(pairs); ++i) {
                if (!(mask & (1 << i)) || dp[mask][i] == INF) {
                    continue;
                }
                for (int j = 0; j < size(pairs); ++j) {
                    if (mask & (1 << j)) {
                        continue;
                    }
                    dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], max<int64_t>(dp[mask][i] + abs(pairs[i].first - pairs[j].first), pairs[j].second));
                }
            }
        }
        return ranges::min(dp.back());
    }
};
