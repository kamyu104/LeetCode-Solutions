// Time:  O(C(ceil(log2(n)), k))
// Space: O(1)

// bit manipulation, hakmem-175
class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        const auto& next_popcount = [](uint32_t n) {  // reference: https://massivealgorithms.blogspot.com/2014/06/hakmem-item-175.html
            const uint32_t lowest_bit = n & -n;
            const uint32_t left_bits = n + lowest_bit;
            const uint32_t changed_bits = n ^ left_bits;
            const uint32_t right_bits = (changed_bits / lowest_bit) >> 2;
            return left_bits | right_bits;
        };

        int result = 0;
        for (int i = (1 << k) - 1; i < size(nums); i = next_popcount(i)) {
            result += nums[i];
            if (i == 0) {
                break;
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// bit manipulation
class Solution2 {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            if (__builtin_popcount(i) == k) {
                result += nums[i];
            }
        }
        return result;
    }
};
