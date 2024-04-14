// Time:  O(n * 2^n * (log(mx) + log(k * mn))) = O(n * 2^n * logk), mn = min(coins), mx = max(coins)
// Space: O(2^n)

// binary search, principle of inclusion and exclusion, number theory
class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        const auto& binary_search = [](auto left, auto right, const auto& check) {
            while (left <= right) {
                const auto mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        vector<vector<int64_t>> lookup(size(coins) + 1);
        for (int mask = 1; mask < 1 << size(coins); ++mask) {
            int64_t l = 1;
            for (int i = 0; i < size(coins); ++i) {
                if (!(mask & (1 << i))) {
                    continue;
                }
                l = lcm(l, coins[i]);
            }
            lookup[__builtin_popcount(mask)].emplace_back(l);
        }
        const int64_t mn = ranges::min(coins);
        return binary_search(mn, k * mn, [&](auto target) {
            int64_t count = 0;
            for (int i = 1; i <= size(coins); ++i) {
                for (const auto& l : lookup[i]) {
                    count += ((i + 1) & 1 ? -1 : +1) * target / l;
                }
            }
            return count >= k;
        });
    }
};
