// Time:  O(nlogn)
// Space: O(n)

// heap, prefix sum
class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        priority_queue<int> max_heap;
        for (int i = 0; i < size(nums) / 3; ++i) {
            max_heap.emplace(nums[i]);
        }
        vector<int64_t> prefix(size(nums) / 3 + 1, accumulate(cbegin(nums), cbegin(nums) + size(nums) / 3, 0ll));
        for (int i = 0; i < size(nums) / 3; ++i) {
            max_heap.emplace(nums[i + size(nums) / 3]);
            const int x = max_heap.top(); max_heap.pop();
            prefix[i + 1] = prefix[i] - x + nums[i + size(nums) / 3];
        }

        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (int i = size(nums) - 1; i >= size(nums) / 3 * 2; --i) {
            min_heap.emplace(nums[i]);
        }
        int64_t suffix = accumulate(cbegin(nums) + size(nums) / 3 * 2, cend(nums), 0ll);
        int64_t result = prefix[size(nums) / 3] - suffix;
        for (int i = size(nums) / 3 - 1; i >= 0; --i) {
            min_heap.emplace(nums[i + size(nums) / 3]);
            const int x = min_heap.top(); min_heap.pop();
            suffix += -x + nums[i + size(nums) / 3];
            result = min(result, prefix[i] - suffix);
        }
        return result;
    }
};
