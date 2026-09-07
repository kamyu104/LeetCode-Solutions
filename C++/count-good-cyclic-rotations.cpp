// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    int countGoodRotations(vector<int>& nums) {
        int result = 0;
        const auto& total = accumulate(cbegin(nums), cend(nums), 0LL);
        auto curr = accumulate(cbegin(nums), cbegin(nums) + size(nums) / 2, 0LL);
        for (int i = 0; i < size(nums); ++i) {
            if (curr > total - curr) {
                ++result;
            }
            curr += nums[(i + size(nums) / 2) % size(nums)] - nums[i];
        }
        return result;
    }
};
