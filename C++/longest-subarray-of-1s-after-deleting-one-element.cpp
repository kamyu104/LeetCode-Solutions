// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0, left = 0, right = 0;
        for (; right < nums.size(); ++right) {
            count += (nums[right] == 0);
            if (count >= 2) {
                count -= (nums[left++] == 0);
            }
        }
        return (right - left) - 1;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int longestSubarray(vector<int>& nums) {
        int result = 0, count = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            count += (nums[right] == 0);
            while (count >= 2) {
                count -= (nums[left++] == 0);
            }
            result = max(result, right - left + 1);
        }
        return result - 1;
    }
};
