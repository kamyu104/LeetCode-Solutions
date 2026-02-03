// Time:  O(logr * nlogn)
// Space: O(n)

// bitmasks, lis, binary search
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        const auto& lis = [&](int base) {
            vector<int> result;
            for (const auto& x : nums) {
                if (!(x & base)) {
                    continue;
                }
                if (empty(result) || result.back() < x) {
                    result.emplace_back(x);
                } else {
                    *lower_bound(begin(result), end(result), x) = x;
                }
            }
            return static_cast<int>(size(result));
        };

        const auto& mx = ranges::max(nums);
        const auto& w = bit_width(static_cast<uint32_t>(ranges::max(nums)));
        int result = 0;
        for (int l = 0; l < w; ++l) {
            result = max(result, lis(1 << l));
        }
        return result;
    }
};
