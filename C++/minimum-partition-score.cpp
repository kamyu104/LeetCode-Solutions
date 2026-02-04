// Time:  O(n * log(n * r)) = O(nlogn + nlogr), r = max(nums)
// Space: O(n)

// prefix sum, dp, convex hull trick, wqs binary search, alien trick
class Solution {
public:
    long long minPartitionScore(vector<int>& nums, int k) {
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

        const auto& check = [](const auto& l1, const auto& l2, const auto& l3) {
            return (get<1>(l2) - get<1>(l1)) * (get<0>(l2) - get<0>(l3)) < (get<1>(l3) - get<1>(l2)) * (get<0>(l1) - get<0>(l2));
        };

        vector<int64_t> prefix(size(nums) + 1);
        const auto& max_lambda = [&]() {
            int64_t mx = 0;
            const auto& total = prefix.back() * (prefix.back() + 1) / 2;
            for (int i = 1; i < size(nums); ++i) {
                const auto& c1 = prefix[i], &c2 = prefix.back() - prefix[i];
                mx = max(mx, total - (c1 * (c1 + 1) / 2 + c2 * (c2 + 1) / 2));
            }
            return mx;
        };

        const auto& f = [&](auto l) {
            int64_t dp = 0;
            int cnt = 0;
            deque<tuple<int64_t, int64_t, int>> hull = {{0, 0, 0}};
            for (int i = 0; i < size(nums); ++i) {
                const auto& x = prefix[i + 1];
                while (size(hull) >= 2 && get<0>(hull[0]) * x + get<1>(hull[0]) >= get<0>(hull[1]) * x + get<1>(hull[1])) {
                    hull.pop_front();
                }
                dp = (get<0>(hull[0]) * x + get<1>(hull[0])) + (x * x + x) / 2 + l;
                cnt = get<2>(hull[0]) + 1;
                const auto& line = tuple(-x, dp + (x * x - x) / 2, cnt);
                while (size(hull) >= 2 && !check(hull[hull.size() - 2], hull[hull.size() - 1], line)) {
                    hull.pop_back();
                }
                hull.emplace_back(line);
            }
            return pair(dp, cnt);
        };

        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        const auto& mx = max_lambda();
        assert(f(mx + 1).second == 1);
        const auto& l = binary_search(static_cast<int64_t>(0), mx, [&](const auto& l) {
            return f(l).second <= k;
        });
        return f(l).first - k * l;
    }
};

// Time:  O(n * k)
// Space: O(n)
// prefix sum, dp, convex hull trick
class Solution2 {
public:
    long long minPartitionScore(vector<int>& nums, int k) {
        static const int64_t INF = numeric_limits<int64_t>::max();

        const auto& check = [](const auto& l1, const auto& l2, const auto& l3) {
            return (get<1>(l2) - get<1>(l1)) * (get<0>(l2) - get<0>(l3)) < (get<1>(l3) - get<1>(l2)) * (get<0>(l1) - get<0>(l2));
        };

        vector<int64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        vector<int64_t> dp(size(nums) + 1, INF);
        dp[0] = 0;
        for (int j = 0; j < k; ++j) {
            vector<int64_t> new_dp(size(nums) + 1, INF);
            deque<pair<int64_t, int64_t>> hull;
            for (int i = j; i < static_cast<int>(size(nums)); ++i) {
                if (dp[i] != INF) {
                    const auto& x = prefix[i];
                    const auto& line = pair(-x, dp[i] + (x * x - x) / 2);
                    while (size(hull) >= 2 && !check(hull[size(hull) - 2], hull[size(hull) - 1], line)) {
                        hull.pop_back();
                    }
                    hull.emplace_back(line);
                }
                const auto& x = prefix[i + 1];
                while (size(hull) >= 2 && get<0>(hull[0]) * x + get<1>(hull[0]) >= get<0>(hull[1]) * x + get<1>(hull[1])) {
                    hull.pop_front();
                }
                new_dp[i + 1] = get<0>(hull[0]) * x + get<1>(hull[0]) + (x * x + x) / 2;     
            }
            dp = move(new_dp);
        }
        return dp.back();
    }
};
