// Time:  O(n + qlogq)
// Space: O(q)

// sort, heap, greedy
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(begin(queries), end(queries), greater<vector<int>>());
        priority_queue<int, vector<int>> max_heap;   
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i = 0; i < size(nums); ++i) {
            while (!empty(queries) && queries.back()[0] <= i) {
                max_heap.emplace(queries.back()[1]);
                queries.pop_back();
            }
            while (!empty(min_heap) && min_heap.top() < i) {
                min_heap.pop();
            }
            while (size(min_heap) < nums[i]) {
                if (empty(max_heap) || max_heap.top() < i) {
                    return -1;
                }
                min_heap.emplace(max_heap.top());
                max_heap.pop();
            }
        }
        return size(max_heap);
    }
};
