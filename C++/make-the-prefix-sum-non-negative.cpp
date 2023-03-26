// Time:  O(nlogn)
// Space: O(n)

// prefix sum, greedy, heap
class Solution {
public:
    int makePrefSumNonNegative(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int result = 0;
        int64_t prefix = 0;
        for (const auto& x: nums) {
            min_heap.emplace(x);
            prefix += x;
            if (prefix < 0) {
                prefix -= min_heap.top(); min_heap.pop();
                ++result;
            }
        }
        return result;
    }
};
