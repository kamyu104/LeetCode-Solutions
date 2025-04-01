// Time:  O(nlogn)
// Space: O(n)

// heap, greedy
class Solution {
public:
    long long minEliminationTime(vector<int>& timeReq, int splitTime) {
        priority_queue<int64_t, vector<int64_t>, greater<int64_t>> min_heap(cbegin(timeReq), cend(timeReq));
        for (int i = 0; i < size(timeReq) - 1; ++i) {
            const auto a = min_heap.top(); min_heap.pop();
            const auto b = min_heap.top(); min_heap.pop();
            min_heap.emplace(max(a, b) + splitTime);
        }
        return min_heap.top();
    }
};
