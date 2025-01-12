// Time:  O(n)
// Space: O(n)

// mono deque, two pointers, sliding window
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int64_t result = 0, cnt = 0;
        deque<int> dq;
        for (int left = size(nums) - 1, right = size(nums) - 1; left >= 0; --left) {
            while (!empty(dq) && nums[dq.back()] < nums[left]) {
                const int64_t l = dq.back(); dq.pop_back();
                const int64_t r = !empty(dq) ? dq.back() - 1 : right;
                cnt += (r - l + 1) * (nums[left] - nums[l]);
            }
            dq.emplace_back(left);
            for (; cnt > k; --right) {
                cnt -= nums[dq[0]] - nums[right];
                if (dq[0] == right) {
                    dq.pop_front();
                }
            }
            result += right - left + 1;
        }
        return result;
    }
};
