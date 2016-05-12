// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    bool search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] == nums[left]) {
                ++left;
            } else if ((nums[mid] > nums[left] && nums[left] <= target && target < nums[mid]) ||
                       (nums[mid] < nums[left] && !(nums[mid] < target && target <= nums[right]))) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};

class Solution2 {
public:
    bool search(vector<int> &nums, int target) {
        int left = 0, right = nums.size();

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return true;
            } else if (nums[mid] == nums[left]) {
                ++left;
            } else if ((nums[left] <= nums[mid] && nums[left] <= target && target < nums[mid]) ||
                       (nums[left] > nums[mid] && !(nums[mid] < target && target <= nums[right - 1]))) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};
