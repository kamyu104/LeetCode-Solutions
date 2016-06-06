// Time:  O(n)
// Space: O(k)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> max_numbers;

        for (int i = 0; i < nums.size(); ++i) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.emplace_back(i);
            if (i >= k && !dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            if (i >= k - 1) {
                max_numbers.emplace_back(nums[dq.front()]);
            }
        }

        return max_numbers;
    }
};
