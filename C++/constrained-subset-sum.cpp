// Time:  O(n)
// Space: O(k)

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int result = numeric_limits<int>::min();
        deque<pair<int, int>> dq;
        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && i - dq.front().first == k + 1) {
                dq.pop_front();
            }
            const auto& curr = nums[i] + (!dq.empty() ? dq.front().second : 0);
            while (!dq.empty() && dq.back().second <= curr) {
                dq.pop_back();
            }
            if (curr > 0) {
                dq.emplace_back(i, curr);
            }
            result = max(result, curr);
        }
        return result;
    }
};
