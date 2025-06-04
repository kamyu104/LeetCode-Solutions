// Time:  O(n * 2^n)
// Space: O(1)

// bitmasks
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        __int128 total = 1;
        for (const auto& x : nums) {
            total *= x;
            if (total > static_cast<__int128>(target) * target) {
                return false;
            }
        }
        if (total != static_cast<__int128>(target) * target) {
            return false;
        }
        for (int mask = 1; mask < (1 << size(nums)) - 1; ++mask) {
            __int128 curr = 1;
            for (int i = 0; i < size(nums); ++i) {
                if (!(mask & (1 << i))) {
                    continue;
                }
                curr *= nums[i];
                if (curr > target) {
                    break;
                }
            }
            if (curr == target) {
                return true;
            }
        }
        return false;
    }
};
