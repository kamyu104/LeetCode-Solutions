// Time:  O(nlogn + klogk)
// Space: O(n + k)

// bfs, heap
class Solution {
public:
    long long kSum(vector<int>& nums, int k) {
        int64_t total = 0;
        vector<int> sorted_vals;
        for (const auto& x : nums) {
            if (x > 0) {
                total += x;
            }
            sorted_vals.emplace_back(abs(x));
        }
        sort(begin(sorted_vals), end(sorted_vals));
        priority_queue<pair<int64_t, int>> max_heap;
        max_heap.emplace(total, 0);
        int64_t result = 0;
        while (k--) {
            result = max_heap.top().first;
            const int i = -max_heap.top().second;
            max_heap.pop();
            if (i == size(sorted_vals)) {
                continue;
            }
            max_heap.emplace(result - sorted_vals[i], -(i + 1));
            if (i - 1 >= 0) {
                max_heap.emplace(result + sorted_vals[i - 1] - sorted_vals[i], -(i + 1));
            }
        }
        return result;
    }
};
