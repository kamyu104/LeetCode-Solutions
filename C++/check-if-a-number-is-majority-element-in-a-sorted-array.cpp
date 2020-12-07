// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        if (nums.size() % 2) {
            if (nums[nums.size() / 2] != target) {
                return false;
            }
        } else {
            if (nums[nums.size() / 2 - 1] != nums[nums.size() / 2] ||
                nums[nums.size() / 2] != target) {
                return false;
            }
        }
        const auto& l = lower_bound(nums.cbegin(), nums.cend(), target);
        const auto& r = upper_bound(nums.cbegin(), nums.cend(), target);
        return (r - l) * 2 > nums.size();
    }
};
