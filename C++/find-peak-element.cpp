// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        
        while (left < right) {
            const auto mid = left + (right - left) / 2;
            if ((mid == 0 || nums[mid - 1] < nums[mid]) &&
               (mid + 1 == nums.size() || nums[mid] > nums[mid + 1])) {
                return mid;
            } else if (!(mid == 0 || nums[mid - 1] < nums[mid])) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
       
        return left;
    }
};
