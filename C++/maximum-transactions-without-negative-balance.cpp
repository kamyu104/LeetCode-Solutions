// Time:  O(nlogn)
// Space: O(n)

// greedy, heap
class Solution {
public:
    int maxTransactions(vector<int>& transactions) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        int64_t curr = 0;
        for (const auto& x : transactions) {
            min_heap.emplace(x);
            curr += x;
            if (curr < 0) {
                curr -= min_heap.top(); min_heap.pop();
            }
        }
        return size(min_heap);
    }
};
