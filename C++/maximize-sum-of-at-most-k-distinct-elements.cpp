// Time:  O(nlogk)
// Space: O(k)

// heap, sort
class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> max_heap;
        for (const auto& x : unordered_set<int>(cbegin(nums), cend(nums))) {
            max_heap.emplace(x);
            if (size(max_heap) == k + 1) {
                max_heap.pop();
            }
        }
        vector<int> result;
        while (!empty(max_heap)) {
            result.emplace_back(max_heap.top());
            max_heap.pop();
        }
        ranges::reverse(result);
        return result;
    }
};
