// Time:  O(nlogr)
// Space: O(n)

// prefix sum, dp, mono deque, wqs binary search, alien trick
class Solution {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        static const auto& NEG_INF = numeric_limits<int64_t>::min();

        const auto& binary_search = [](auto left, auto right, const auto& check) {
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

        vector<int64_t> prefix(size(nums) + 1);
        const auto& best_single = [&]() {
            auto result = NEG_INF;
            deque<int> dq;
            for (int i = 1; i <= size(nums); ++i) {
                const auto& j = i - l;
                if (j >= 0) {
                    while (!empty(dq) && prefix[dq.back()] >= prefix[j]) {
                        dq.pop_back();
                    }
                    dq.emplace_back(j);
                }
                while (!empty(dq) && dq.front() < i - r) {
                    dq.pop_front();
                }
                if (!empty(dq)) {
                    result = max(result, prefix[i] - prefix[dq.front()]);
                }
            }
            return result;
        };

        auto f = [&](int64_t x) -> pair<int64_t, int> {
            const auto& better = [](auto v1, auto c1, auto v2, auto c2)  {
                return v1 > v2 || (v1 == v2 && c1 < c2);
            };

            vector<pair<int64_t, int>> dp(size(nums) + 1, make_pair(0LL, 0));
            deque<int> dq;
            for (int i = 1; i <= size(nums); ++i) {
                const auto& j = i - l;
                if (j >= 0) {
                    while (!empty(dq) && better(dp[j].first - prefix[j], dp[j].second, dp[dq.back()].first - prefix[dq.back()], dp[dq.back()].second)) {
                        dq.pop_back();
                    }
                    dq.emplace_back(j);
                }
                while (!empty(dq) && dq.front() < i - r) {
                    dq.pop_front();
                }
                dp[i] = dp[i - 1];
                if (!empty(dq)) {
                    pair<int64_t, int> new_dp = {
                        ((dp[dq.front()].first - prefix[dq.front()]) + prefix[i]) - x,
                        dp[dq.front()].second + 1
                    };
                    if (better(new_dp.first, new_dp.second, dp[i].first, dp[i].second)) {
                        dp[i] = move(new_dp);
                    }
                }
            }
            return dp.back();
        };

        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        const auto& single = best_single();
        auto [dp, cnt] = f(0);
        if (cnt == 0) {
            return single;
        }
        if (cnt <= m) {
            return dp;
        }
        const auto& mx = single;
        assert(f(mx).second <= m);
        const auto& x = binary_search(static_cast<int64_t>(1), mx, [&](const auto& x) {
            return f(x).second <= m;
        });
        return f(x).first + static_cast<int64_t>(m) * x;
    }
};

// Time:  O(n * m)
// Space: O(n)
// prefix sum, dp, mono deque
class Solution2 {
public:
    long long maximumSum(vector<int>& nums, int m, int l, int r) {
        static const auto& NEG_INF = numeric_limits<int64_t>::min();

        vector<int64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int64_t result = NEG_INF;
        vector<int64_t> dp(size(nums) + 1);
        for (int t = 0; t < m; ++t) {
            vector<int64_t> new_dp(size(nums) + 1, NEG_INF);
            deque<int> dq;
            for (int i = 1; i <= size(nums); ++i) {
                new_dp[i] = new_dp[i - 1];
                const auto& j = i - l;
                if (j >= 0 && dp[j] != NEG_INF) {
                    while (!empty(dq) &&  dp[dq.back()] - prefix[dq.back()] <= dp[j] - prefix[j]) {
                        dq.pop_back();
                    }
                    dq.emplace_back(j);
                }
                while (!empty(dq) && dq.front() < i - r) {
                    dq.pop_front();
                }
                if (!empty(dq)) {
                    new_dp[i] = max(new_dp[i], (dp[dq.front()] - prefix[dq.front()]) + prefix[i]);
                }
            }
            dp = move(new_dp);
            result = max(result, dp.back());
        }
        return result;
    }
};
