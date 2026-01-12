// Time:  O(nlogr)
// Space: O(n)

// bitmasks, greedy, quick select
class Solution {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int result = 0;
        for (int i = bit_width(static_cast<uint32_t>(ranges::max(nums) + k)) - 1; i >= 0; --i) {
            const auto& target = result | (1 << i);
            vector<int> costs;
            costs.reserve(size(nums));
            for (const auto& x : nums) {
                const auto& l = bit_width(static_cast<uint32_t>(target & ~x));
                const auto& mask = (1ll << l) - 1;
                costs.emplace_back((target & mask) - (x & mask));
            }
            ranges::nth_element(costs, begin(costs) + (m - 1));
            if (accumulate(cbegin(costs), cbegin(costs) + m, 0ll) <= k) {
                result |= 1 << i;
            }
        }
        return result;
    }
};

// Time:  O(nlogn * logr)
// Space: O(n)
// bitmasks, greedy, sort
class Solution2 {
public:
    int maximumAND(vector<int>& nums, int k, int m) {
        int result = 0;
        for (int i = bit_width(static_cast<uint32_t>(ranges::max(nums) + k)) - 1; i >= 0; --i) {
            const auto& target = result | (1 << i);
            vector<int> costs;
            costs.reserve(size(nums));
            for (const auto& x : nums) {
                const auto& l = bit_width(static_cast<uint32_t>(target & ~x));
                const auto& mask = (1ll << l) - 1;
                costs.emplace_back((target & mask) - (x & mask));
            }
            ranges::sort(costs);
            if (accumulate(cbegin(costs), cbegin(costs) + m, 0ll) <= k) {
                result |= 1 << i;
            }
        }
        return result;
    }
};
