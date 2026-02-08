// Time:  O(n)
// Space: O(n)

// mono deque, two pointers
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int64_t result = 0;
        deque<int> max_dq, min_dq;
        for (int right = 0, left = 0; right < size(nums); ++right) {
            while (!empty(max_dq) && nums[max_dq.back()] <= nums[right]) {
                max_dq.pop_back();
            }
            max_dq.emplace_back(right);
            while (!empty(min_dq) && nums[min_dq.back()] >= nums[right]) {
                min_dq.pop_back();
            }
            min_dq.emplace_back(right);
            while (static_cast<int64_t>(right - left + 1) * (nums[max_dq[0]] - nums[min_dq[0]]) > k) {
                if (!empty(max_dq) && max_dq[0] == left) {
                    max_dq.pop_front();
                }
                if (!empty(min_dq) && min_dq[0] == left) {
                    min_dq.pop_front();
                }
                ++left;
            }
            result += right - left + 1;
        }
        return result;
    }
};
