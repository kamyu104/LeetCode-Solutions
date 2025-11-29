// Time:  O((n + r) * logr), r = max(nums)
// Space: O(n + r)

// sos dp, principle of inclusion and exclusion
class Solution {
public:
    int countEffective(vector<int>& nums) {
        static const int MOD = 1e9 + 7;

        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        int total = 0;
        for (const auto& x : nums) {
            total |= x;
        }
        const auto& l = bit_length(total);
        vector<int> bits;
        for (int i = 0; i < l; ++i) {
            if (total & (1 << i)) {
                bits.emplace_back(i);
            }
        }
        vector<int> dp(1 << size(bits));
        for (const auto& x : nums) {
            int mask = 0;
            for (int i = 0; i < size(bits); ++i) {
                if (x & (1 << bits[i])) {
                    mask |= (1 << i);
                }
            }
            ++dp[mask];
        }
        for (int i = 0; i < size(bits); ++i) {
            for (int mask = 0; mask < size(dp); ++mask) {
                if (mask & (1 << i)) {
                    dp[mask] += dp[mask ^ (1 << i)];
                }
            }
        }
        vector<int> cnt(1 << size(bits));
        for (int mask = 1; mask < size(cnt); ++mask) {
            cnt[mask] = cnt[mask & (mask - 1)] + 1;
        }
        vector<int> pow2(size(nums) + 1);
        pow2[0] = 1;
        for (int i = 0; i < size(nums); ++i) {
            pow2[i + 1] = (pow2[i] * 2) % MOD;
        }
        int result = 0;
        const int full = (1 << size(bits)) - 1;
        for (int mask = 1; mask < size(cnt); ++mask) {
            result = (((result + (cnt[mask] & 1 ? 1 : -1) * pow2[dp[full ^ mask]]) % MOD) + MOD) % MOD;
        }
        return result;
    }
};
