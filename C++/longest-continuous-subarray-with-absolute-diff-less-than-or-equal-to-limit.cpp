// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_dq, min_dq;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (!max_dq.empty() && nums[max_dq.back()] <= nums[right]) {
                max_dq.pop_back();
            }
            max_dq.emplace_back(right);
            while (!min_dq.empty() && nums[min_dq.back()] >= nums[right]) {
                min_dq.pop_back();
            }
            min_dq.emplace_back(right);
            if (nums[max_dq[0]] - nums[min_dq[0]] > limit) {
                if (max_dq[0] == left) {
                    max_dq.pop_front();
                }
                if (min_dq[0] == left) {
                    min_dq.pop_front();
                }
                ++left;  // advance left by one to not count in result
            }
        }
        return nums.size() - left;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> max_dq, min_dq;
        int result = 0, left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (!max_dq.empty() && nums[max_dq.back()] <= nums[right]) {
                max_dq.pop_back();
            }
            max_dq.emplace_back(right);
            while (!min_dq.empty() && nums[min_dq.back()] >= nums[right]) {
                min_dq.pop_back();
            }
            min_dq.emplace_back(right);
            while (nums[max_dq[0]] - nums[min_dq[0]] > limit) {  // both always exist "right" element
                if (max_dq[0] == left) {
                    max_dq.pop_front();
                }
                if (min_dq[0] == left) {
                    min_dq.pop_front();
                }
                ++left;
            }
            result = max(result, right - left + 1);
        }
        return result;
    }
};
