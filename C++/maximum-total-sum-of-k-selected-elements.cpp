// Time:  O(nlogk)
// Space: O(k)

// heap, greedy
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for (const auto& x : nums) {
            min_heap.emplace(x);
            if (size(min_heap) == k + 1) {
                min_heap.pop();
            }
        }
        int64_t result = 0;
        while (!empty(min_heap)) {
            const auto x = min_heap.top(); min_heap.pop();
            result += x * static_cast<int64_t>(max(mul - static_cast<int>(size(min_heap)), 1));
        }
        return result;
    }
};

// Time:  O(nlogk)
// Space: O(k)
// sort, greedy
class Solution2 {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        partial_sort(begin(nums), begin(nums) + k, end(nums), greater<int>());
        int64_t result = 0;
        for (int i = 0; i < k; ++i) {
            result += nums[i] * static_cast<int64_t>(max(mul - i, 1));
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// sort, greedy
class Solution3 {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(begin(nums), end(nums), greater<int>());
        int64_t result = 0;
        for (int i = 0; i < k; ++i) {
            result += nums[i] * static_cast<int64_t>(max(mul - i, 1));
        }
        return result;
    }
};
