// Time:  O(nlogn)
// Space: O(n)

// greedy, heap
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        uint64_t result = 0, curr = 0;
        vector<pair<int, int>> nums;
        for (int i = 0; i < size(nums1); ++i) {
            nums.emplace_back(nums1[i], nums2[i]);
        }
        sort(begin(nums), end(nums), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (const auto& [a, b] : nums) {
            curr += a;
            min_heap.emplace(a);
            if (size(min_heap) > k) {
                curr -= min_heap.top(); min_heap.pop();
            }
            if (size(min_heap) == k) {
                result = max(result, curr * b);
            }
        }
        return result;
    }
};
