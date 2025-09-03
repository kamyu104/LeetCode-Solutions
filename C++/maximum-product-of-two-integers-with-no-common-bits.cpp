// Time:  O(rlogr), r = max(nums)
// Space: O(r)

// dp, bitmasks
class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        const auto& l = bit_length(ranges::max(nums));
        vector<int> dp(1 << l);
        for (const auto& x : nums) {
            dp[x] = x;
        }
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < (1 << l); j += 1 << (i + 1)) {
                for (int k = j; k < j + (1 << i); ++k) {
                    if (dp[k] > dp[k + (1 << i)]) {
                        dp[k + (1 << i)] = dp[k];
                    }
                }
            }
        }
        int64_t result = 0;
        for (const auto& x : nums) {
            const auto& v = static_cast<int64_t>(x) * dp[((1 << l) - 1) ^ x];
            if (v > result) {
                result = v;
            }
        }
        return result;
    }
};

// Time:  O(rlogr), r = max(nums)
// Space: O(r)
// dp, bitmasks
class Solution2 {
public:
    long long maxProduct(vector<int>& nums) {
        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        const auto& l = bit_length(ranges::max(nums));
        vector<int> dp(1 << l);
        for (const auto& x : nums) {
            dp[x] = x;
        }
        for (int i = 0; i < l; ++i) {
            for (int mask = 0; mask < (1 << l); ++mask) {
                if (mask & (1 << i)) {
                    continue;
                }
                if (dp[mask] > dp[mask | (1 << i)]) {
                    dp[mask | (1 << i)] = dp[mask];
                }
            }
        }
        int64_t result = 0;
        for (const auto& x : nums) {
            const auto& v = static_cast<int64_t>(x) * dp[((1 << l) - 1) ^ x];
            if (v > result) {
                result = v;
            }
        }
        return result;
    }
};
