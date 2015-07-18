// Time:  O(n)
// Space: O(k)

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        const int n = nums.size();
        deque<int> q;
        vector<int> max_numbers;

        for (int i = 0; i < k; ++i) {
            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            q.emplace_back(i);
        }

        for (int i = k; i < n; ++i) {
            max_numbers.emplace_back(nums[q.front()]);

            while (!q.empty() && nums[i] >= nums[q.back()]) {
                q.pop_back();
            }
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            q.emplace_back(i);
        }

        if (!q.empty()) {
            max_numbers.emplace_back(nums[q.front()]);
        }

        return max_numbers;
    }
};
