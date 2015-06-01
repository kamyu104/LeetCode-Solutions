// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        deque<int64_t> window;
        multiset<int64_t> bst;
        for (int i = 0; i < nums.size(); ++i) {
            // Only keep at most k elements.
            if (bst.size() > k) {
                int num = window.front();
                window.pop_front();
                bst.erase(bst.find(num));
            }
            // Every search costs time: O(logn).
            const auto it = bst.lower_bound(nums[i] - t);
            if (it == bst.cend() || (*it - nums[i]) > t) {
                // Not found.
                window.emplace_back(nums[i]);
                bst.emplace(nums[i]);
            } else {
                return true;
            }
        }
        return false;
    }
};
