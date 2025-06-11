// Time:  O(nlogn * logr), r = max(nums)
// Space: O(n + logr)

// number theory, suffix-gcd states, dp, binary search
class Solution {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        static const int INF = numeric_limits<int>::max();

        vector<int> lookup(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            while ((nums[i] & 1) == 0) {
                nums[i] >>= 1;
                ++lookup[i];
            }
        }
        const int max_e = ranges::max(lookup);
        vector<vector<int>> lookup2(max_e + 1);
        for (int i = 0; i < size(lookup); ++i) {
            lookup2[lookup[i]].emplace_back(i);
        }
        int64_t result = 0;
        unordered_map<int, unordered_map<int, vector<int>>> dp;
        for (int i = 0; i < size(nums); ++i) {
            unordered_map<int, unordered_map<int, vector<int>>> new_dp;
            new_dp[nums[i]][lookup[i]] = {i, i};
            for (const auto& [g, e_v] : dp) {  // |g * e| = O(logr)
                for (const auto& [e, v] : e_v) {
                    const int ng = gcd(g, nums[i]);
                    const int ne = min(e, lookup[i]);
                    if (!new_dp.count(ng) || !new_dp[ng].count(ne)) {
                        new_dp[ng][ne] = {INF, INF};
                    }
                    new_dp[ng][ne][0] = min(new_dp[ng][ne][0], v[0]);
                    const int left = distance(cbegin(lookup2[ne]), lower_bound(cbegin(lookup2[ne]), cend(lookup2[ne]), v[0]));  // Time: O(logn)
                    const int right = distance(cbegin(lookup2[ne]), upper_bound(cbegin(lookup2[ne]), cend(lookup2[ne]), i)) - 1;  // Time: O(logn)
                    new_dp[ng][ne][1] = min(new_dp[ng][ne][1], (right - left + 1 <= k) ? v[0] : lookup2[ne][right - k] + 1);
                }
            }
            dp = move(new_dp);
            for (const auto& [g, e_v] : dp) {  // |g * e| = O(logr)
                for (const auto& [e, v] : e_v) {
                    result = max(result, (static_cast<int64_t>(g) * (i - v[0] + 1)) << e);
                    result = max(result, (static_cast<int64_t>(g) * (i - v[1] + 1)) << (e + 1));
                }
            }
        }
        return result;
    }
};

// Time:  O(n^2 + n * logr), r = max(nums)
// Space: O(1)
// number theory, brute force
class Solution2 {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        static const int INF = numeric_limits<int>::max();

        const auto& lower_bit = [](int x) {
            return x & -x;
        };

        int64_t result = 0;
        for (int i = 0; i < size(nums); ++i) {
            for (int j = i, g = 0, mn = INF, cnt = 0; j < size(nums); ++j) {
                g = gcd(g, nums[j]);
                const auto& bit = lower_bit(nums[j]);
                if (bit < mn) {
                    mn = bit;
                    cnt = 0;
                }
                if (bit == mn) {
                    ++cnt;
                }
                result = max(result, static_cast<int64_t>(g) * (j - i + 1) * (cnt <= k ? 2 : 1));
                if (static_cast<int64_t>(g) * (size(nums) - i) * 2 <= result) {
                    break;
                }
            }
        }
        return result;
    }
};
