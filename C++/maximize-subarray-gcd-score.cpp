// Time:  O(nlogn * (logr)^2)
// Space: O(n + (logr)^2)

// suffix-gcd states, dp, binary search
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
            for (const auto& [g, e_v] : dp) {  // |g| = O(logr)
                for (const auto& [e, v] : e_v) {  // |e| = O(logr)
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
            for (const auto& [g, e_v] : dp) {  // |g| = O(logr)
                for (const auto& [e, v] : e_v) {  // |e| = O(logr)
                    result = max(result, (static_cast<int64_t>(g) * (i - v[0] + 1)) << e);
                    result = max(result, (static_cast<int64_t>(g) * (i - v[1] + 1)) << (e + 1));
                }
            }
        }
        return result;
    }
};

// Time:  O(n^2 + n * logr)
// Space: O(1)
// brute force
class Solution2 {
public:
    long long maxGCDScore(vector<int>& nums, int k) {
        int64_t result = 0;
        for (int i = 0; i < size(nums); ++i) {
            for (int j = i, g = 0, mn = numeric_limits<int>::max(), cnt = 0; j < size(nums); ++j) {
                g = gcd(g, nums[j]);
                const auto last_bit = nums[j] & -nums[j];
                if (last_bit < mn) {
                    mn = last_bit;
                    cnt = 0;
                }
                if (last_bit == mn) {
                    ++cnt;
                }
                result = max(result, static_cast<int64_t>(g) * (j - i + 1) * (cnt <= k ? 2 : 1));
                if (g * (size(nums) - i) * 2 <= result) {
                    break;
                }
            }
        }
        return result;
    }
};
