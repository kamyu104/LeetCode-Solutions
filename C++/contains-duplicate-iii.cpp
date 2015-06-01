// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        deque<int64_t> window_deq;
        multiset<int64_t> window;
        for (int i = 0; i < nums.size(); ++i) {
            // Only keep at most k elements.
            if (window.size() > k) {
                int num = window_deq.front();
                window_deq.pop_front();
                window.erase(window.find(num));
            }
            // Every search costs time: O(logn).
            const auto it = window.lower_bound(nums[i] - t);
            if (it == window.cend() || (*it - nums[i]) > t) {
                // Not found.
                window_deq.emplace_back(nums[i]);
                window.emplace(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
