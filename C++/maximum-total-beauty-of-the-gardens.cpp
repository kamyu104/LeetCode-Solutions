// Time:  O(nlogn)
// Space: O(n)

// sort, prefix sum, greedy, two pointers
class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        sort(begin(flowers), end(flowers));
        const long long n = distance(cbegin(flowers), lower_bound(cbegin(flowers), cend(flowers), target));
        vector<long long> prefix(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + flowers[i];
        }
        vector<long long> suffix(n + 1);
        for (int i = n - 1; i >= 0; --i) {
            suffix[i] = suffix[i + 1] + flowers[i];
        }
        long long result = 0, left = 0;
        for (long long right = 0; right <= n; ++right) {
            const auto total = newFlowers - (static_cast<long long>(n - right) * target -suffix[right]);
            if (total < 0) {
                continue;
            }
            while (left + 1 <= right && (left == 0 || (total + prefix[left]) / left > flowers[left])) {
                ++left;
            }
            const auto mn = min(left ? (total + prefix[left]) / left : 0ll, static_cast<long long>(target) - 1);
            result = max(result, mn * partial + (static_cast<long long>(size(flowers)) - right) * full);
        }
        return result;
    }
};
