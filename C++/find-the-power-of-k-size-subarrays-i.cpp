// Time:  O(n)
// Space: O(1)

// two pointers, sliding window
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> result(size(nums) - k + 1, -1);
        for (int right = 0, left = 0; right < size(nums); ++right) {
            if (nums[right] - nums[left] != right - left) {
                left = right;
            }
            if (right - left + 1 == k) {
                result[left++] = nums[right];
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
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> result;
        for (int i = 0; i + k - 1 < size(nums); ++i) {
            int j = i;
            for (; j < i + k - 1; ++j) {
                if (nums[j] + 1 != nums[j + 1]) {
                    break;
                }
            }
            result.emplace_back(j == i + k - 1 ? nums[i + k - 1] : -1);
        }
        return result;
    }
};
