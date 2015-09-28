// Time:  O(nlogn)
// Space: O(1)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left = 1, right = nums.size();

        while (left <= right) {
            const int mid = left + (right - left) / 2;
            // Get count of num <= mid.
            int count = 0;
            for (const auto& num : nums) {
                if (num <= mid) {
                    ++count;
                }
            }
            if (count > mid) {
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int findDuplicate(vector<int>& nums) {
        int duplicate = 0;
        // Mark the value as visited by negative.
        for (auto& num : nums) {
            if (nums[abs(num) - 1] > 0) {
                nums[abs(num) - 1] *= -1;
            } else {
                duplicate = abs(num);
                break;
            }
        }
        // Rollback the value.
        for (auto& num : nums) {
            if (nums[abs(num) - 1] < 0) {
                nums[abs(num) - 1] *= -1;
            } else {
                break;
            }
        }
        return duplicate;
    }
};
