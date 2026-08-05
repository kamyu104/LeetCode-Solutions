// Time:  O(n * rlogr * (f / 64)) = O(n * rlogr), r = max(demand), f = fuel[0]
// Space: O(r * (f / 64)) = O(r)

// binary search, dp, bitmasks
class Solution {
public:
    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
        const auto& binary_search = [](int left, int right, const auto& check) {
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

        const auto& low = [](int x) -> uint64_t {
            return x >= 63 ? ~uint64_t{0} : x >= 0 ? ((uint64_t{1} << (x + 1)) - 1) : 0;
        };

        const auto& high = [&](int x) -> uint64_t {
            return ~uint64_t{0} ^ low(x - 1);
        };

        const auto& find_max_served = [&]() -> int {
            uint64_t mask = 1;
            for (int i = 0, total = 0; i < size(demand); ++i) {
                mask = ((mask << demand[i]) & low(fuel[0])) | (mask & high(total + demand[i] - fuel[1]));
                if (!mask) {
                    return i;
                }
                total += demand[i];
            }
            return size(demand);
        };

        const auto& l = find_max_served();
        if (!l) {
            return -1;
        }
    
        const auto& mx = ranges::max(demand);
        const auto& check = [&](int w) {
            // dp[last][gap] = bit used0 is set if the state (last, gap, used0) is reachable.
            // - last: dispenser serving the previous car
            // - gap: remaining busy time of the other dispenser
            // - used0: total fuel consumed by dispenser 0
            vector<vector<uint64_t>> dp(2, vector<uint64_t>(mx + 1));
            dp[0][0] = 1;
            for (int i = 0, total = 0; i < l; ++i) {
                vector<vector<uint64_t>> new_dp(2, vector<uint64_t>(mx + 1));
                const auto& update = [&](int last, int gap, uint64_t mask) {
                    if (last == 0) {
                        mask = (mask << demand[i]) & low(fuel[0]);
                    } else {
                        mask &= high(total + demand[i] - fuel[1]);
                    }
                    new_dp[last][gap] |= mask;
                };

                for (int last = 0; last < size(dp); ++last) {
                    for (int gap = 0; gap < size(dp[0]); ++gap) {
                        if (!dp[last][gap]) {
                            continue;
                        }
                        if ((i - 1 >= 0 ? demand[i - 1] : 0) <= w) {
                            update(last, max(gap - (i - 1 >= 0 ? demand[i - 1] : 0), 0), dp[last][gap]);
                        }
                        if (gap <= w) {
                            update(last ^ 1, max((i - 1 >= 0 ? demand[i - 1] : 0) - gap, 0), dp[last][gap]);
                        }
                    }
                }
                dp = move(new_dp);
                total += demand[i];
            }
            return ranges::any_of(dp, [](const auto& row) {
                return ranges::any_of(row, [](uint64_t mask) {
                    return mask != 0;
                });
            });
        };

        return binary_search(0, mx, check);
    }
};

// Time:  O(n * rlogr * f),  r = max(demand), f = fuel[0]
// Space: O(r * f)
// binary search, dp
class Solution2 {
public:
    int minMaxWaitingTime(vector<int>& demand, vector<int>& fuel) {
        const auto& binary_search = [](int left, int right, const auto& check) {
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

        const auto& find_max_served = [&]() -> int {
            // dp[used0] = whether the current prefix can be served with state (used0).
            vector<bool> dp(fuel[0] + 1);
            dp[0] = true;
            for (int i = 0, total = 0; i < size(demand); ++i) {
                vector<bool> new_dp(fuel[0] + 1);
                for (int used0 = 0; used0 <= fuel[0]; ++used0) {
                    if (!dp[used0]) {
                        continue;
                    }
                    if (used0 + demand[i] <= fuel[0]) {
                        new_dp[used0 + demand[i]] = true;
                    }
                    if (total - used0 + demand[i] <= fuel[1]) {
                        new_dp[used0] = true;
                    }
                }
                if (!ranges::any_of(new_dp, [](bool ok) { return ok; })) {
                    return i;
                }
                dp = move(new_dp);
                total += demand[i];
            }
            return size(demand);
        };

        const auto& l = find_max_served();
        if (!l) {
            return -1;
        }

        const auto& mx = ranges::max(demand);
        const auto& check = [&](int w) {
            // dp[last][gap][used0] = whether the current prefix can be served with state (last, gap, used).
            // - last: which dispenser serving the previous car
            // - gap: remaining busy time of the other dispenser
            // - used0: total fuel consumed by dispenser 0
            vector<vector<vector<bool>>> dp(2, vector<vector<bool>>(mx + 1, vector<bool>(fuel[0] + 1)));
            dp[0][0][0] = true;
            for (int i = 0, total = 0; i < l; ++i) {
                vector<vector<vector<bool>>> new_dp(2, vector<vector<bool>>(mx + 1, vector<bool>(fuel[0] + 1)));
                const auto& update = [&](int last, int gap, int used0) {
                    if (last == 0) {
                        if (used0 + demand[i] <= fuel[0]) {
                            new_dp[last][gap][used0 + demand[i]] = true;
                        }
                    } else {
                        if (total - used0 + demand[i] <= fuel[1]) {
                            new_dp[last][gap][used0] = true;
                        }
                    }
                };
    
                for (int last = 0; last < size(dp); ++last) {
                    for (int gap = 0; gap < size(dp[0]); ++gap) {
                        for (int used0 = 0; used0 < size(dp[0][0]); ++used0) {
                            if (!dp[last][gap][used0]) {
                                continue;
                            }
                            if ((i - 1 >= 0 ? demand[i - 1] : 0) <= w) {
                                update(last, max(gap - (i - 1 >= 0 ? demand[i - 1] : 0), 0), used0);
                            }
                            if (gap <= w) {
                                update(last ^ 1, max((i - 1 >= 0 ? demand[i - 1] : 0) - gap, 0), used0);
                            }
                        }
                    }
                }
                dp = move(new_dp);
                total += demand[i];
            }
            return ranges::any_of(dp, [](const auto& matrix) {
                return ranges::any_of(matrix, [](const auto& row) {
                    return ranges::any_of(row, [](bool x) {
                        return x;
                    });
                });
            });
        };

        return binary_search(0, mx, check);
    }
};
