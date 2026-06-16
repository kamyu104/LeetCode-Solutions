// Time:  O(n^2 * logk)
// Space: O(n)

// prefix sum, heap, dp
class Solution {
public:
    long long maxSum(vector<int>& nums, int k) {
        const auto& update = [&](auto& heap, int64_t total, int x) {
            if (k == 0) {
                return total;
            }
            heap.emplace(x);
            total += x;
            if (size(heap) == k + 1) {
                total -= heap.top(); heap.pop();
            }
            return total;
        };

        const auto& cnt = accumulate(cbegin(nums), cend(nums), 0, [](const auto& accu, const auto& x) {
            return accu + (x < 0 ? 1 : 0);
        });
        if (cnt == size(nums)) {
            return ranges::max(nums);
        }
        if (cnt <= k) {  // optional to boost up performance
            return accumulate(cbegin(nums), cend(nums), 0LL, [](const auto& accu, const auto& x) {
                return accu + (x >= 0 ? x : 0);
            });
        }
        vector<int64_t> prefix(size(nums) + 1);
        for (int i = 0; i < size(nums); ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int64_t result = 0;
        vector<int64_t> dp(size(nums));
        for (int i = 0; i < size(nums); ++i) {
            priority_queue<int, vector<int>, greater<int>> max_heap;
            int64_t total1 = 0;
            for (int j = i; j < size(nums); ++j) {
                if (nums[j] < 0) {
                    total1 = update(max_heap, total1, -nums[j]);
                }
                dp[j] = -total1;
            }
            priority_queue<int, vector<int>, greater<int>> min_heap;
            int64_t total2 = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[j] >= 0) {
                    total2 = update(min_heap, total2, nums[j]);
                }
            }
            for (int j = size(nums) - 1; j >= i; --j) {
                result = max(result, (prefix[j + 1] - prefix[i]) - dp[j] + total2);
                if (nums[j] >= 0) {
                    total2 = update(min_heap, total2, nums[j]);
                    result = max(result, total2);
                }
            }
        }
        return result;
    }
};
