// Time:  O(n)
// Space: O(k)

// two pointers, sliding window, mono deque
class Solution {
public:
    long long minMaxSubarraySum(vector<int>& nums, int k) {
        const auto& count = [&](const auto& check) {
            int64_t result = 0, total = 0;
            deque<pair<int, int>> dq;
            for (int right = 0; right < size(nums); ++right) {
                while (!empty(dq) && dq[0].first <= right - k) {
                    total -= nums[dq[0].first];
                    dq.pop_front();
                }
                if (!empty(dq) && dq[0].second == right - k) {
                    total -= nums[dq[0].first];
                    ++dq[0].second;
                }
                int left = right;
                for (int i; !empty(dq) && !check(nums[dq.back().first], nums[right]); ) {
                    tie(i, left) = dq.back(); dq.pop_back();
                    total -= static_cast<int64_t>(i - left + 1) * nums[i];
                }
                dq.emplace_back(right, left);
                total += static_cast<int64_t>(right - left + 1) * nums[right];
                result += total;
            }
            return result;
        };
    
        return count([](const auto& a, const auto& b) { return a < b; }) + 
               count([](const auto& a, const auto& b) { return a > b; });
    }
};
