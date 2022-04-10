// Time:  O(nlogn)
// Space: O(1)

// sort, prefix sum, greedy, two pointers
class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        const auto it = partition(begin(flowers), end(flowers), [&target](int x) { return x < target; });
        sort(begin(flowers), it);
        const long long n = distance(begin(flowers), it);
        long long prefix = 0, suffix = accumulate(begin(flowers), it, 0ll);
        long long result = 0, left = 0;
        for (long long right = 0; right <= n; ++right) {
            const auto total = newFlowers - (static_cast<long long>(n - right) * target - suffix);
            if (right < n) {
                suffix -= flowers[right];
            }
            if (total < 0) {
                continue;
            }
            while (left + 1 <= right && (left == 0 || (total + prefix) / left > flowers[left])) {
                prefix += flowers[left++];
            }
            const auto mn = min(left ? (total + prefix) / left : 0ll, static_cast<long long>(target) - 1);
            result = max(result, mn * partial + (static_cast<long long>(size(flowers)) - right) * full);
        }
        return result;
    }
};
