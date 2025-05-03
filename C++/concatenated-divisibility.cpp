// Time:  O(nlogr + k * n * 2^n)
// Space: O(logr + k * 2^n)

// dp, backtracing
class Solution {
public:
    vector<int> concatenatedDivisibility(vector<int>& nums, int k) {
        const auto& length = [](int x) {
            int l = 0;
            for (; x > 0; x /= 10) {
                ++l;
            }
            return max(l, 1);
        };

        vector<int> lookup(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            lookup[i] = length(nums[i]);
        }
        const int mx = ranges::max(lookup);
        vector<int> pow10(mx + 1);
        pow10[0] = 1 % k;
        for (int i = 0; i + 1 < size(pow10); ++i) {
            pow10[i + 1] = (pow10[i] * 10) % k;
        }
        vector<vector<bool>> dp(1 << size(nums), vector<bool>(k));
        dp.back()[0] = true;
        for (int mask = (size(dp) - 1) - 1; mask >= 0; --mask) {
            for (int r = 0; r < k; ++r) {
                for (int i = 0; i < size(nums); ++i) {
                    if (mask & (1 << i)) {
                        continue;
                    }
                    if (dp[mask | (1 << i)][(r * pow10[lookup[i]] + nums[i]) % k]) {
                        dp[mask][r] = true;
                        break;
                    }
                }
            }
        }
        vector<int> result;
        if (!dp[0][0]) {
            return result;
        }
        vector<pair<int,int>> order;
        for (int i = 0; i < size(nums); ++i) {
            order.emplace_back(nums[i], i);
        }
        sort(begin(order), end(order));
        for (int _ = 0, mask = 0, r = 0; _ < size(nums); ++_) {
            for (const auto& [_, i] : order) {
                if (mask & (1 << i)) {
                    continue;
                }
                if (dp[mask | (1 << i)][(r * pow10[lookup[i]] + nums[i]) % k]) {
                    result.emplace_back(nums[i]);
                    mask |= (1 << i);
                    r = (r * pow10[lookup[i]] + nums[i]) % k;
                    break;
                }
            }
        }
        return result;
    }
};
