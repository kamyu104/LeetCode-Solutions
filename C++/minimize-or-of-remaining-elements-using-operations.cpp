// Time:  O(nlogr)
// Space: O(1)

// bitmasks, greedy
class Solution {
public:
    int minOrAfterOperations(vector<int>& nums, int k) {
        const auto& bit_length = [](int x) {
            return (x ? std::__lg(x) : -1) + 1;
        };

        int result = 0;
        const int l = bit_length(ranges::max(nums));
        const int mask = (1 << l) - 1;
        for (int i = l - 1; i >= 0; --i) {
            result <<= 1;
            int curr = mask, cnt = 0;
            for (const auto& x : nums) {
                curr &= x >> i;
                if (curr & ~result) {
                    ++cnt;
                } else {
                    curr = mask;
                }
            }
            if (cnt > k) {
                ++result;
            }
        }
        return result;
    }
};
