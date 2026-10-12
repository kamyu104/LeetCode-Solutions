// Time:  O(n)
// Space: O(1)

// two pointers
class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int result = 0;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            if (nums[left] % k != nums[right] % k) {
                left = right;
            }
            if (nums[left] * ((right - left + 1LL) - 1) % k == 0) {
                result = max(result, right - left + 1);
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(1)
// brute force
class Solution2 {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        int result = 0;
        for (int i = 0; i < size(nums); ++i) {
            for (int j = i; j < size(nums); ++j) {
                if (nums[j] % k != nums[i] % k) {
                    break;
                }
                if (nums[i] * ((j - i + 1LL) - 1) % k == 0) {
                    result = max(result, j - i + 1);
                }
            }
        }
        return result;
    }
};
