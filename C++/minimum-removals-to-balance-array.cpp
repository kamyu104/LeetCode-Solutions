// Time:  O(nlogn)
// Space: O(1)

// sort, two pointers
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int left = 0;
        for (int right = 0; right < size(nums); ++right) {
            if (static_cast<int64_t>(nums[left]) * k < nums[right]) {
                ++left;
            }
        }
        return left;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort, two pointers
class Solution2 {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int result = 0;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            while (static_cast<int64_t>(nums[left]) * k < nums[right]) {
                ++left;
            }
            result = max(result, right - left + 1);
        }
        return size(nums) - result;
    }
};
