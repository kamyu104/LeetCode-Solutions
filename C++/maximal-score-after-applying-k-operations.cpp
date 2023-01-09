// Time:  O(n + klogn)
// Space: O(n)

// heap
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        const auto& ceil_divide = [](const auto& a, const auto& b) {
            return (a + b - 1) / b;
        };

        int64_t result = 0;
        priority_queue<int> max_heap(cbegin(nums), cend(nums));
        while (k--) {
            const auto x = max_heap.top(); max_heap.pop();
            result += x;
            max_heap.emplace(ceil_divide(x, 3));
        }
        return result;
    }
};
