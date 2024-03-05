// Time:  O(nlogn)
// Space: O(n)

// simulation, heap
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int result = 0;
        priority_queue<int64_t, vector<int64_t>, greater<int64_t>> min_heap(cbegin(nums), cend(nums));
        while (!empty(nums)) {
            if (min_heap.top() >= k) {
                break;
            }
            const auto mn1 = min_heap.top(); min_heap.pop();
            const auto mn2 = min_heap.top(); min_heap.pop();
            min_heap.emplace(2 * mn1 + mn2);
            ++result;
        }
        return result;
    }
};
