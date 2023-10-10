// Time:  O(nlogr), r = max(nums)
// Space: O(logr)

// bit manipulation, greedy, freq table
class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        static const int MOD = 1e9 + 7;

        const auto& bit_length = [](int x) {
            return x != 0 ? 8 * sizeof(x) - __builtin_clz(x) : 1;
        };

        const int l = bit_length(*max_element(cbegin(nums), cend(nums)));
        vector<int> cnt(l);
        for (int i = 0; i < l; ++i) {
            for (const auto& x : nums) {
                if (x & (1 << i)) {
                    ++cnt[i];
                }
            }
        }
        int result = 0;
        for (int j = 1; j <= k; ++j) {
            int curr = 0;
            for (int i = 0; i < l; ++i) {
                if (cnt[i] >= j) {
                    curr += 1 << i;
                }
            }
            result = (result + static_cast<int64_t>(curr) * curr) % MOD;
        }
        return result;
    }
};
