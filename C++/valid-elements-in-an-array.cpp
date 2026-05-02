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

// Time:  O(n)
// Space: O(n)
// prefix sum
class Solution2 {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<bool> left(size(nums));
        int mx = 0;
        for (int i = 0; i < size(nums); ++i) {
            left[i] = nums[i] > mx;
            mx = max(mx, nums[i]);
        }
        vector<bool> right(size(nums));
        mx = 0;
        for (int i = size(nums) - 1; i >= 0; --i) {
            right[i] = nums[i] > mx;
            mx = max(mx, nums[i]);
        }
        vector<int> result;
        for (int i = 0; i < size(nums); ++i) {
            if (left[i] || right[i]) {
                result.emplace_back(nums[i]);
            }
        }
        return result;
    }
};
