// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int minBuildTime(vector<int>& blocks, int split) {
        priority_queue<int, vector<int>, greater<int>> min_heap(blocks.cbegin(), blocks.cend());
        while (min_heap.size() != 1) {
            min_heap.pop();
            const auto y = min_heap.top(); min_heap.pop();
            min_heap.emplace(y + split);
        }
        return min_heap.top();
    }
};
