// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    vector<int> reverseSubarrays(vector<int>& nums, int k) {
        const auto& reverse = [&](int left, int right) {
            for (; left < right; ++left, --right) {
                swap(nums[left], nums[right]);
            }
        };

        for (int i = 0, l = size(nums) / k; i < size(nums); i += l) {
            reverse(i, i + l - 1);
        }
        return nums;
    }
};
