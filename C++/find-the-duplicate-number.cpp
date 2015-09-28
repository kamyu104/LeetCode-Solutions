// Time:  O(n)
// Space: O(1)

// Two pointers method, same as Linked List Cycle II.
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[nums[0]];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        fast = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};;

// Time:  O(nlogn)
// Space: O(1)
// Binary search method.
class Solution2 {
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
class Solution3 {
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
