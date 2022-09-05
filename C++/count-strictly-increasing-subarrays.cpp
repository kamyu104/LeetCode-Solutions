// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        int64_t result = 1, l = 1;
        for (int i = 1; i < size(nums); ++i) {
            if (nums[i - 1] >= nums[i]) {
                l = 0;
            }
            result += ++l;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// two pointers
class Solution2 {
public:
    long long countSubarrays(vector<int>& nums) {
        int64_t result = 0, left = 0;
        for (int64_t right = 0; right < size(nums); ++right) {
            if (!(right - 1 >= 0 && nums[right - 1] < nums[right])) {
                left = right;
            }
            result += right - left + 1;
        }
        return result;
    }
};
