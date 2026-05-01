// Time:  O(n)
// Space: O(n)

// prefix sum
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<bool> right(size(nums));
        int mx = 0;
        for (int i = size(nums) - 1; i >= 0; --i) {
            right[i] = nums[i] > mx;
            mx = max(mx, nums[i]);
        }
        vector<int> result;
        bool left = false;
        mx = 0;
        for (int i = 0; i < size(nums); ++i) {
            left = nums[i] > mx;
            mx = max(mx, nums[i]);
            if (left || right[i]) {
                result.emplace_back(nums[i]);
            }
        }
        return result;
    }
};
